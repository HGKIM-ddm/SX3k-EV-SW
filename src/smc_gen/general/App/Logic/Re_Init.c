#include "Re_Init.h"
#include "Service.h"

static void Step_LoadData(void)
{
	step_position_close = close_memory_read;
	step_position_open = open_memory_read;
	step_position = now_step_memory_read;
	AAF_Tx_Position = position_memory_read;
	AAFx_Position_Status = position_status_memory_read;
	AAFx_InitStatus = AAFx_InitStatus_memory_read;
	limit_step_position = limit_memory_read;
	evrdy_on_flag = Initial_memory_read;
	DTC_Status |= DTC_memory_read;
	power_chk = power_chk_memory_read;
	First_Powerchk = First_Powerchk_memory_read;
}

static void Step_Check(void)
{
	unsigned int step_range  = step_position_close - step_position_open;
    unsigned int reinit_required;
	
	reinit_required = (        
        /* 1. 이동 범위(Range) 및 마진(Limit) 체크 */
        (step_range           <= STEP_POSITION_MINIMUM_RANGE)               ||
        (step_range           >  STEP_POSITION_MAXIMUM_RANGE)               || 
        (step_position        == REFERENCE_POSITION)                        ||
        // (step_position        <  step_position_open  + limit_step_position) || 
        // (step_position        >  step_position_close - limit_step_position) || 
        
		((step_position + limit_step_position) < step_position_open)        ||
        (step_position > (step_position_close + limit_step_position))       ||
        /* 2. 초기화 실패(Zero) 체크 */
        (step_position_close  == 0U)                                        || 
        (step_position_open   == 0U)                                        || 
        (limit_step_position  == 0U)                                        || 
        
        /* 3. 하드웨어 최대 한계치(Max Range) 이탈 체크 */
        (step_position        >  POSITION_MAXIMUM_RANGE)                    || 
        (step_position_open   >  POSITION_MAXIMUM_RANGE)                    || 
        (step_position_close  >  POSITION_MAXIMUM_RANGE)                    || 
        (limit_step_position  >  LIMITSTEP_MAXIMUM_RANGE)                   || 
        
        /* 4. 시스템 상태 및 통신 에러 플래그 체크 */
        (evrdy_on_flag        == OFF)                                       ||
        (AAF_Tx_Position      == UNKOWN_POSITION)                           || 
        (AAFx_InitStatus      == ABNORMAL_FINISHED_INITIALIZATION)          ||
        (AAFx_Position_Status == FlapMoving_Status)                         ||
        (AAFx_Position_Status == Unknown_Status)                            ||
        (power_chk            == Shutdown_Check)							
		// 5. 펌웨어 버전 불일치 체크
		// ((fw_version_memory_read & 0xFFU) != FW_VERSION) 
    ) ? 1U : 0U;

    if (reinit_required == 1U)
    {
        Re_Init();
    }
	else
	{
		if (AAFx_Position_Status == Open_Status)
		{
			aaf_step = AAF_WAITING;
			aaf_init_step = NORMAL_INITIALIZATION;
			// AAF_Tx_Position = OPEN;
			// AAFx_Position_Status = Open_Status;
			AAFx_InitStatus = NORMAL_FINISHED_INITIALIZATION;
			evrdy_on_flag = ON;
			aaf_action_complete_chk = FLAP_STOP;
			antipinch_previous_action = ANTIWAIT;
		}
		else if (AAFx_Position_Status == Close_Status)
		{
			aaf_step = AAF_WAITING;
			aaf_init_step = NORMAL_INITIALIZATION;
			// AAF_Tx_Position = CLOSE;
			// AAFx_Position_Status = Close_Status;
			AAFx_InitStatus = NORMAL_FINISHED_INITIALIZATION;
			evrdy_on_flag = ON;
			aaf_action_complete_chk = FLAP_STOP;
			antipinch_previous_action = ANTIWAIT;
		}
		else
		{
			//invaild
		}
	}
}

void Re_Init(void)
{
	G_Timer1ms.DiagAutoMode = 0U;
	G_Timer1msFlag.DiagAutoModeFlag = OFF;
	diag_mode_auto_action = OFF;
	aaf_action = 0U;
	trq_cnt = MOTOR_STALL_CHK_NORMAL_VALUE; // stall reset
	aaf_step = AAF_INITIALIZATION;					  // MCU is reset, AAF is initialized.
	aaf_init_step = START_INITIALIZATION;			  // MCU is reset, AAF is initialized.
	AAFx_Position_Status = Unknown_Status;
	AAF_Tx_Position = UNKOWN_POSITION;
	init_move_step = 0U;
	AAFx_ErrorStatus = No_ErrorStatus;
	step_position = REFERENCE_POSITION;
	step_position_open = 0U;
	step_position_close = 0U;
	lin_aaf_command = OPEN;
	Diag_Mode = 0U;
	Diag_Mode_chk = 0U;
	evrdy_on_flag = OFF;

	#ifdef ENABLE_TORQUE_LIN_COMMUNICATION
	TRQ_COUNT_Index = 0U;
    TRQ_COUNT_LogEnable = 1U; 
    TRQ_COUNT_TxReady = 0U;
	#endif
}

/***********************************************************************************************************************
 * Function Name: Step_InitAndCheck
 * Description  : Handles step position initialization and flash memory sync upon Ignition ON.
 * Called By    : App_SwLogic
 ***********************************************************************************************************************/
void Step_InitAndCheck(void)
{
    if ((IGN_Chk == 2U) && (LDCRdy == 0x01U))
    {
        Position_Temporary_read();
        IGN_Chk = 1U;
    }

    if ((step_check_flag == 0U) && (LDCRdy == 0x01U))
    {
        FDL_Read();
        Step_LoadData();
        IGN_Chk = 1U;

        G_Timer1msFlag.MotorStepCheckFlag = 1U;

        if (G_Timer1ms.MotorStepCheck >= 50U)
        {
            Step_Check();   

            G_Timer1msFlag.MotorStepCheckFlag = 0U;
            G_Timer1ms.MotorStepCheck = 50U;
            step_check_flag = 1U;
        }
	}	

	if ((step_check_flag == 1U) && (AAFx_InitStatus == NORMAL_FINISHED_INITIALIZATION))
	{
		power_chk = Shutdown_Check;
		FDL_Write();
		step_check_flag = 2U;
	}
}
