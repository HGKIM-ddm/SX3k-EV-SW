#include "Lin_Service.h"
#include "Service.h"

#ifdef UDS
#include "cpu.h"
#include "..\..\uds\def_lin_uds.h"
#include "..\..\uds\lin_uds.h"
#include "..\..\uds\util.h"

void RLIN_Slave_uds_Transmit(uint8_t* databuf,uint8_t Data_length)
{
	uint8_t i;
	uint8_t *Databuf_adr ;
	RLN30.LDFC = 0x18;                    /*b5=0: checksum mode classic; b4=1:transmission*/
	Databuf_adr = (uint8_t *)&RLN30.LDBR1;    /* get the data buffer address*/
	for(i=0;i<Data_length;i++)             /* setting tansmission data to date buffer*/
	{
		*((uint8_t *)(Databuf_adr+i))=databuf[i];  
	}
	RLN30.LTRC = 0x02; /*setting RTS=1;Response transmission start*/   
}
#endif

/***********************************************************************************************************************
 * Function Name: Lin_Wakeup
 * Description  : Wake up in sleep mode when LIN communication is detected and initialize the associated variables
 * Called By    : Lin_HandleReceivedHeader
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
static void Lin_Wakeup(void)
{
    /* Sleep 상태에서 LIN 프레임이 다시 수신되면 Sleep 상태 해제 */
    if (lin_bus_inactive_flag == ON)
    {
        /* LIN Bus가 다시 살아났으므로 inactive 상태 해제 */
        lin_bus_inactive_flag = OFF;

        /* LIN inactive counter 초기화 */
        G_Timer1ms.LinBusInactive = 0U;

        /* Sleep 상태머신 초기화 */
        lin_sleep_step = 0U;

        /* Sleep delay timer 초기화 */
        G_Timer1msFlag.LinSleepModeFlag = 0U;
        G_Timer1ms.LinSleepMode = 0U;

        /* Sleep 중 모터가 동작하고 있었을 수 있으므로 모터 정지 */
        Drv8889_Off2();
        motor_start = OFF;

        /* Stall timer 초기화 */
        G_Timer1msFlag.StallTimeFlag = 0U;
        G_Timer1ms.StallTime = 0U;

        /* Init fail check timer 초기화 */
        G_Timer1msFlag.InitFailCheckFlag = 0U;
        G_Timer1ms.InitFailCheck = 0U;

        /* Soft start 및 모터 속도 관련 변수 초기화 */
        softstart_complete = OFF;
     
        /* Sleep 중 진행하던 동작은 중단 처리 */
        aaf_action = FLAP_STOP;
        aaf_action_complete_chk = FLAP_STOP;

        /* 
         * Sleep sequence 중 모터가 이동 중이었다면 실제 위치가 목표 위치가 아닐 수 있음.
         * 이 경우 위치 신뢰성이 떨어질 수 있으므로 초기화 대기 상태로 둔다.
         *
         * 단, 기존 정책이 "LIN Wake 시 이전 명령을 이어서 수행"이라면
         * 아래 블록은 AAF_OPERATE 복귀 방식으로 조정해야 한다.
         */
        if (AAFx_Position_Status == FlapMoving_Status)
        {
            aaf_step = AAF_INITIALIZATION;
            aaf_init_step = WAIT_INITIALIZATION;

            AAF_Tx_Position = UNKOWN_POSITION;
            AAFx_Position_Status = Unknown_Status;
            AAFx_InitStatus = DURING_INITIALIZATION;
        }
        else
        {
            /* 이동 중이 아니었다면 일반 명령 대기 상태로 복귀 */
           if (aaf_step != AAF_INITIALIZATION) 
            {
                aaf_step = AAF_WAITING; 
            }
        }
    }
}

/***********************************************************************************************************************
 * Function Name: Lin_HandleReceivedHeader
 * Description  : Check ID on LIN header reception and set send/receive mode (EV Specification)
 * Called By    : Lin_ReceiveComplete_Interrupt
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
void Lin_HandleReceivedHeader(void)
{
    RLN30.LST = 0x00U; // Clear Status
    GetIDbuffer = RLN30.LIDB; // Get ID

    /* EV Control Frame ID: 0x27 (PID: 0xE7) */
    if (GetIDbuffer == 0xE7U)
    {
        Lin_SlaveReceive(8U); // EV 사양 데이터 길이: 8바이트
    }
    /* EV Response Frame ID: 0x28 (AAF1), 0x29 (AAF2), 0x2A (AAF3) */
    else if (((AAFx_Index == 1U) && (GetIDbuffer == 0xA8U)) || // 0x28 PID: 0xA8
             ((AAFx_Index == 2U) && (GetIDbuffer == 0xE9U)) || // 0x29 PID: 0xE9
             ((AAFx_Index == 3U) && (GetIDbuffer == 0x6AU)))   // 0x2A PID: 0x6A
    {
        Lin_SlaveTransmit(Slave_TxData, 7U); 
    }
    /* Master Request Frame ID: 0x3C (PID: 0x3C) */
    else if (GetIDbuffer == 0x3CU)
    {
        Lin_SlaveReceive(8U); 
    }

    #ifdef UDS
    else if ((GetIDbuffer == 0x7DU) && (uds.state==EST_TX)) 
    { 
    RLIN_Slave_uds_Transmit((uint8_t *)&uds.tx_data[1], 8);
        uds.state=EST_RX;  
    }																												
    #endif
        
    /* Slave Response Frame ID: 0x3D (PID: 0x7D) */
    else if ((GetIDbuffer == 0x7DU) && ((SW_Chk == 1U) || (SW_Chk == 3U)))
    {
        Lin_SlaveTransmit(Slave_SwData, 8U); 
    }
    else
    {
        Lin_SlaveNoResponse();
    }

    Lin_Wakeup();
}

/***********************************************************************************************************************
 * Function Name: Lin_HandleReceivedResponse
 * Description  : LIN data reception completion flag processing and receiving buffer read
 * Called By    : Lin_ReceiveComplete_Interrupt
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
void Lin_HandleReceivedResponse(void)
{
    RLN30.LST &= 0xFDu; // Clear successful response reception flag

    switch (GetIDbuffer)
    {
    case 0xE7U: // EV Control Frame PID (0x27)
        Lin_GetReponseRxData(Slave_RxData1);
        lin_rx_chk_flag = ON;
        break;
    case 0x3CU: // Master Request Frame
        Lin_GetReponseRxData(Slave_RxSwData1);

        #ifdef UDS
        unsigned int i;
        if(Slave_RxSwData1[0]==NAD_PHY) {
            for (i = 0; i < 7; i++)	{	
                uds.packet_data[i]=Slave_RxSwData1[i+2];
                Slave_RxSwData1[i]=0;
            }	
            uds_frame_parser();					
        }
        #endif       

        break;
    default:
        break;
    }
}


