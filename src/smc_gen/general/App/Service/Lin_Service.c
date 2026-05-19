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
             ((AAFx_Index == 3U) && (GetIDbuffer == 0x6AU)))   // 0x2A PID: 0x6A
    {
        Lin_SlaveTransmit(Slave_TxData, 7U); 
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


