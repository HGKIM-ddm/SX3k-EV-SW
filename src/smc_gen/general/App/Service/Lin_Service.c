#include "Lin_Service.h"
#include "Service.h"

/***********************************************************************************************************************
 * Function Name: Lin_Wakeup
 * Description  : Wake up in sleep mode when LIN communication is detected and initialize the associated variables
 * Called By    : Lin_HandleReceivedHeader
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
static void Lin_Wakeup(void)
{
    if (lin_bus_inactive_flag == ON)
    {
        lin_bus_inactive_flag = OFF;
        lin_sleep_step = 0U;
        G_Timer1msFlag.LinSleepModeFlag = 0U;
        G_Timer1ms.LinSleepMode = 0U;

        Drv8889_Off2();
        motor_start = OFF;
        G_Timer1msFlag.StallTimeFlag = 0U;
        G_Timer1ms.StallTime = 0U;
        G_Timer1msFlag.InitFailCheckFlag = 0U;
        G_Timer1ms.InitFailCheck = 0U;

        if (AAFx_Position_Status == FlapMoving_Status)
        {
            aaf_step = AAF_OPERATE;
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
             ((AAFx_Index == 3U) && (GetIDbuffer == 0xAAU)))   // 0x2A PID: 0xAA
    {
        Lin_SlaveTransmit(Slave_TxData, 8U); // EV 사양 데이터 길이: 8바이트
    }
    /* Master Request Frame ID: 0x3C (PID: 0x3C) */
    else if (GetIDbuffer == 0x3CU)
    {
        Lin_SlaveReceive(8U); 
    }
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
        break;
    default:
        break;
    }
}

/***********************************************************************************************************************
 * Function Name: Lin_CalculateVerifyChecksum
 * Description  : Manage LIMP HOME counts by validating the checksum of received data
 * Called By    : Lin_ReceiveComplete_Interrupt
 * Arguments    : is_response_received - Response received flag (0: Not received, 2: Received)
 * Return Value : void
 ***********************************************************************************************************************/
void Lin_CalculateVerifyChecksum(uint8_t is_response_received)
{
    ReqRespAAFID = WAIT;
    
    /* * EV 사양은 LIN 2.2A Enhanced Checksum을 사용하며, 이는 Lin_Driver.c의 
     * RLN30.LDFC = 0x20U 설정에 의해 하드웨어 레벨에서 자동으로 검증됩니다. 
     * 따라서 소프트웨어에서 별도로 계산할 필요 없이 수신 성공 여부만 확인합니다.
     */
    if (is_response_received == 0x02U)
    {
        AAF_LIN_ChkSum_CHK = PASS; // 하드웨어 체크섬 검증 통과

        if (G_Timer1ms.IgnCheck >= 500U)
        {
            if (LIMP_HOME_Count >= 4U) LIMP_HOME_Count -= 4U; 
            else                       LIMP_HOME_Count = 0U;  
        }
    }
    else // Checksum Error 또는 통신 타임아웃
    {
        AAF_LIN_ChkSum_CHK = FAIL;

        if (G_Timer1ms.IgnCheck >= 500U)
        {
            /* EV 사양 기준 LIMP HOME 카운트 관리 (Max 160) */
            if (LIMP_HOME_Count <= 158U) LIMP_HOME_Count += 2U; 
            else                         LIMP_HOME_Count = 160U;
        } 
    }
}

