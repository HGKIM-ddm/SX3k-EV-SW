#include "Lin_Interrupt.h"

/***********************************************************************************************************************
 * Function Name: Lin_ReceiveComplete_Interrupt
 * Description  : RLIN30 Received Interrupt Handler (Header/Response Processing)
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
#pragma ghs interrupt
void Lin_ReceiveComplete_Interrupt(void)
{
    uint8_t receive_header_flag;
    uint8_t receive_response_flag; // Typo Fixed: reponse -> response

    // 1. Get Status Flags
    receive_header_flag = (uint8_t)(RLN30.LST & 0x80U);  /* 1: Header transmission completed */
    receive_response_flag = (uint8_t)(RLN30.LST & 0x02U); /* 1: Frame/Wake-up reception completed */

    // 2. Handle Header Reception
    if (receive_header_flag != 0U)
    {
        Lin_HandleReceivedHeader();
    }

    // 3. Handle Response Reception
    if (receive_response_flag != 0U)
    {
        Lin_HandleReceivedResponse();
    }

    // 4. Calculate Checksum & Update Status (Always executed in original logic)
    ReqRespAAFID = WAIT;

    // 5. Reset Timer & Update Hardware Status
    G_Timer1ms.LinBusInactive = 0U; // Reset LIN timeout timer

	lin_status_error_detected = OFF;

    /* 6. Sleep 상태였다면 Sleep flag 해제 및 상태 복구 */
    Lin_WakeupFromSleep();
		
    RLN30.LTRC = 0x01U; // Set FTS bit (Ready for next frame)
}

/***********************************************************************************************************************
 * Function Name: r_Config_TAUB0_0_interrupt
 * Description  : This function is TAUB00 interrupt service routine
 * Arguments    : None
 * Return Value : None
 ***********************************************************************************************************************/
#pragma ghs interrupt
void Lin_Transmit_Interrupt(void)
{
	RLN30.LST &= 0xFEu;
}

/***********************************************************************************************************************
 * Function Name: r_Config_TAUB0_0_interrupt
 * Description  : This function is TAUB00 interrupt service routine
 * Arguments    : None
 * Return Value : None
 ***********************************************************************************************************************/
#pragma ghs interrupt
void Lin_Interrupt(void)
{
}

/***********************************************************************************************************************
 * Function Name: r_Config_TAUB0_0_interrupt
 * Description  : This function is TAUB00 interrupt service routine
 * Arguments    : None
 * Return Value : None
 ***********************************************************************************************************************/
#pragma ghs interrupt
void Lin_Status_Interrupt(void)
{
	NOP();
	error_status = RLN30.LEST; // check status

	if (error_status != 0U)
	{
		lin_status_error_detected = ON;
	}

	if (G_Timer1ms.IgnCheck >= 500U)
	{
		if (LIMP_HOME_Count <= 160U)
		{
			LIMP_HOME_Count += 2U;
		}
	}

#if 1 // LEST Clear
	while (1)
	{
		if ((RLN30.LTRC & 0x01U) == 1U)
		{
			RLN30.LEST = 0U;
			NOP();
			NOP();
			NOP();
			NOP();
			NOP();
			NOP();
			NOP();
			NOP();
			NOP();
			NOP();
			NOP();
			NOP();
			NOP();
			NOP();
			NOP();
			NOP();
			NOP();
			NOP();
			NOP();
			NOP();
			NOP();
			error_status = RLN30.LEST;
			break;
		}
	}
#endif
}

