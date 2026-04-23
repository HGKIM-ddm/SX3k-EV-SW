#include "Limp_Home.h"
#include "Service.h"

void Limp_Home(void)
{

	if ((LIMP_HOME_Count < 80U) && (AAF_LIN_ChkSum_CHK == PASS) && (LIMP_HOME_step == 2U))
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
				Drv8889_On2();						 // drv on
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
			Drv8889_Off2();
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
			
			//only sx3k
			AAFx_SNSR1_Position = Initial_Value;
			AAFx_SNSR2_Position = Initial_Value;
			AAFx_SNSR3_Position = Initial_Value;
			AAFx_SNSR4_Position = Initial_Value;
		}
		else if ((AAF_Tx_Position == OPEN) && (AAFx_Position_Status == Open_Status))
		{
			AAF_Tx_Position = UNKOWN_POSITION;
			AAFx_Position_Status = Unknown_Status;
			AAFx_InitStatus = DURING_INITIALIZATION;
			aaf_step = FINISHED_OPERATE;
			LIMP_HOME_step = 2U;

			//only sx3k
			AAFx_SNSR1_Position = Initial_Value;
			AAFx_SNSR2_Position = Initial_Value;
			AAFx_SNSR3_Position = Initial_Value;
			AAFx_SNSR4_Position = Initial_Value;
		}
		else
		{
            //invaild
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

