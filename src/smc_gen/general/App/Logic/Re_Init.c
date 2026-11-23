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
	antipinch_action_on = OFF;
	antipinch_step = 0U;
	G_Timer1msFlag.AntipinchCheckFlag = 0U;
	G_Timer1ms.AntipinchCheck = 0U;
	reinit_request_flag = OFF;
	ldc_reinit_wait_flag = OFF;  /* 위치 초기화 시작 : 초기화 대기 요청 취소 (중복 Re_Init 방지) */

	#ifdef ENABLE_TORQUE_LIN_COMMUNICATION
	TRQ_OpenIndex  = 0U;
	TRQ_CloseIndex = 0U;
	TRQ_LogNewRun  = 1U;
	TRQ_LogEnable  = 1U;
	#endif
}

/***********************************************************************************************************************
 * Function Name: Re_InitRequest
 * Description  : 에러 / 보호 해제 후 위치 초기화 요청 (사양 3.6 / 5.2.6 : 위치 초기화는 LDCRdy = 1 수신 후)
 *                - LDCRdy 1 : 즉시 Re_Init
 *                - LDCRdy 0 : Initial value 송신 + 마스터 명령 무시 상태로 대기, LDCRdy 1 수신 시 Re_Init (Step_InitAndCheck)
 *                  대기 중 Sleep 최종 제어로 위치가 확정되면 요청 취소 (Sleep_Wakeup)
 * Called By    : Limp_Home, Antipinch_PrevOpen, Antipinch_PrevClose, Error_ClearVoltageProtection,
 *                Error_CheckShort, Error_CheckOpen, Protection_WaitOff
 ***********************************************************************************************************************/
void Re_InitRequest(void)
{
	if (LDCRdy == 0x01U)
	{
		Re_Init();
	}
	else
	{
		aaf_step             = AAF_INITIALIZATION;
		aaf_init_step        = WAIT_INITIALIZATION;
		AAF_Tx_Position      = UNKOWN_POSITION;
		AAFx_Position_Status = Unknown_Status;
		AAFx_InitStatus      = DURING_INITIALIZATION;
		ldc_reinit_wait_flag = ON;
	}
}

/***********************************************************************************************************************
 * Function Name: Step_InitAndCheck
 * Description  : Handles step position initialization and flash memory sync upon Ignition ON.
 * Called By    : App_SwLogic
 ***********************************************************************************************************************/
void Step_InitAndCheck(void)
{
    /* Sleep 시퀀스 진행 중(Wake 보류)에는 복원 금지 : Wake 판단 전 위치 미확정 정보 보존 */
    if ((IGN_Chk == 2U) && (LDCRdy == 0x01U) && (lin_bus_inactive_flag == OFF))
    {
        Position_Temporary_read();
        G_Timer1msFlag.IGNOffCheckFlag = 0U;
        G_Timer1ms.IGNOffCheck = 0U;
        IGN_Chk = 1U;
    }

    /* LDCRdy 1 -> 0 : 300ms 동안 마스터 명령 수행 후 명령 무시 + Initial value 송신 */
    if ((IGN_Chk == 1U) && (LDCRdy == 0x00U))
    {
        G_Timer1msFlag.IGNOffCheckFlag = 1U;

        if (G_Timer1ms.IGNOffCheck >= LDC_OFF_IGNORE_TIME)
        {
            G_Timer1msFlag.IGNOffCheckFlag = 0U;
            G_Timer1ms.IGNOffCheck = LDC_OFF_IGNORE_TIME;   /* 포화 : 재진입 방지 */

            /* Sleep 시퀀스 중(lin_bus_inactive_flag ON)에는 보류 : Sleep 최종 제어로 확정된 위치를
               Sleep_Wakeup 이 판단하기 전에 Initial value 로 덮어 위치 미확정 -> 불필요한 Re_Init 되는 것 방지.
               (MCU 전원 차단 시에는 Sleep_Execute 가 저장, 리셋 없는 Wake 시에는 Wake 후 다음 루프에서 저장) */
            if ((motor_start == OFF) &&
                (lin_bus_inactive_flag == OFF) &&
                (AAFx_Position_Status != FlapMoving_Status) &&
                (AAFx_InitStatus != DURING_INITIALIZATION))
            {
                Position_Temporary_write();
                IGN_Chk = 2U;
            }
        }
    }
    else if ((IGN_Chk == 1U) && (LDCRdy == 0x01U))
    {
        G_Timer1msFlag.IGNOffCheckFlag = 0U;
        G_Timer1ms.IGNOffCheck = 0U;                       /* Ready 유지 중 리셋 */
    }
    else
    {
        /* invalid */
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

            /* 이전 종료 상태(power_chk) 판정 완료 → 런타임 값은 '이번 사이클 미종료'로 전환.
               초기화 실패로 step_check_flag 가 2 가 되지 않아도 MCU_Sleep 이 정상 수행되도록 함 */
            power_chk = Shutdown_Check;

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

    /* 리셋 없는 Wake 후 위치 미확정 : LDCRdy = 1 수신 시 위치 초기화 (사양 3.6 / 5.2.6 / 5.3.12)
       Sleep 시퀀스 진행 중(Wake 보류)에는 수행 금지 : step_position 리셋으로 Sleep 구동 오동작 방지 */
    if ((ldc_reinit_wait_flag == ON) && (LDCRdy == 0x01U) && (lin_bus_inactive_flag == OFF))
    {
        ldc_reinit_wait_flag = OFF;
        Re_Init();
    }
}
