#include "Limp_Home.h"
#include "Service.h"

/***********************************************************************************************************************
 * Function Name: LimpHome_UpdateCount
 * Description  : LIN 통신 상태에 따라 Limp Home 카운터를 증감시킴.
 *                - 정상 통신 시 4 감소, 에러 발생 시 2 증가.
 *                - 진단은 9V~16V 전압 범위 및 IGN ON 500ms 이후에만 수행됨.
 ***********************************************************************************************************************/
void LimpHome_UpdateCount(void)
{
    /* 진단 조건: 9V ~ 16V 사이의 전압 */
    if ((adc_avr >= ADC_UNDER_VOLTAGE_9V) && (adc_avr <= ADC_OVER_VOLTAGE_16V))
    {
        /* LIN 통신 에러 발생 시 카운트 증가 */
        if (g_lin_error_flag == 1U)
        {
            g_lin_error_flag = 0U; // 플래그 소모
            if (LIMP_HOME_Count <= 160U)
            {
                LIMP_HOME_Count += 2U;
            }
        }
        /* LIN 통신 정상 수신 시 카운트 감소 */
        else if (g_lin_comm_ok_flag == 1U)
        {
            g_lin_comm_ok_flag = 0U; // 플래그 소모
            if (LIMP_HOME_Count > 0U)
            {
                LIMP_HOME_Count = (LIMP_HOME_Count >= 4U) ? (LIMP_HOME_Count - 4U) : 0U;
            }
        }

		else
		{
			//invalid
		}
    }
}

void Limp_Home(void)
{

	if ((LIMP_HOME_Count < 80U) && (LIMP_HOME_step == 2U))
	{
		LIMP_HOME_Count = 0U;
		LIMP_HOME_step = 0U;
		Re_Init();
	}
	switch (LIMP_HOME_step)
	{
	case 0:
		if ((LIMP_HOME_Count >= 80U))
		{
			if ((AAF_Tx_Position != OPEN))
			{
				Motor_Open();					 // dir OPEN
				Motor_On();						 // drv on
				motor_start = ON;				 // step start
				G_Timer1msFlag.StallCheckFlag = ON;	 // test
				motor_stall_flag = MOTOR_NORMAL; // stall reset
				G_Timer1ms.StallTime = 0U;			 // stall reset
				LIMP_HOME_step = 1U;
				G_Timer1msFlag.InitCheckFlag = 1U; // test
			}
			else
			{
				LIMP_HOME_step = 1U;
			}
		}
		break;
	case 1:
		if ((step_position <= (step_position_open + limit_step_position)) || (motor_stall_flag == MOTOR_STALL)) //
		{
			Motor_Off();
			motor_start = OFF;
			G_Timer1msFlag.StallTimeFlag = 0U;
			G_Timer1ms.StallTime = 0U; // stall reset
			G_Timer1msFlag.InitCheckFlag = 0U;
			G_Timer1ms.InitCheck = 0U;
			AAF_Tx_Position = UNKOWN_POSITION;
			AAFx_Position_Status = Unknown_Status;
			AAFx_InitStatus = DURING_INITIALIZATION;
			aaf_step = FINISHED_OPERATE;
			LIMP_HOME_step = 2U;
			
		}
		else if ((AAF_Tx_Position == OPEN) && (AAFx_Position_Status == Open_Status))
		{
			AAF_Tx_Position = UNKOWN_POSITION;
			AAFx_Position_Status = Unknown_Status;
			AAFx_InitStatus = DURING_INITIALIZATION;
			aaf_step = FINISHED_OPERATE;
			LIMP_HOME_step = 2U;

		}
		else
		{
            //invalid
		}
		break;
	case 2:
		if (AAFx_Position_Status == Open_Status)
		{
			FDL_Write();
		}

		break;

	default:
		break;
	}
}
