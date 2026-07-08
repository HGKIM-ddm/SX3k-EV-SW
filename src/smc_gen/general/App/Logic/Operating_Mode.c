#include "Operating_Mode.h"
#include "Service.h"
#include "HighSpeed_Mode.h"

static void Operate_Waiting(void);
static void Operate_SetupAction(void);
static void Operate_Action(unsigned int action);
static void Operate_SetupAutoAction(void);
static void Operate_Process(void);
static void Operate_NormalProcess(void);
static void Operate_NormalAction(unsigned int direction);
static void Operate_DiagProcess(void);
static void Operate_DiagAction(unsigned int direction, unsigned int is_auto);
static void Operate_CheckRange(void);
static void Operate_SelectAAFxMode(void);
static void Operate_HandleStall(void);
static void Operate_CheckCondition(void);
static void Operate_Init(void);
static void Operate_Finish(void);

/***********************************************************************************************************************
 * Function Name: Operate_Waiting
 * Description  : AAF_WAITING 상태에서 LIN 명령 수신 여부 또는 자동 모드 플래그를 확인하여 동작을 시작함
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
static void Operate_Waiting(void)
{
	if ((step_start_flag == ON) && (lin_bus_inactive_flag == OFF))
	{
		Operate_SetupAction();
	}
	else if ((diag_mode_auto_action == ON) && (lin_bus_inactive_flag == OFF))
	{
		Operate_SetupAutoAction();
	}
	else
	{
		// invalid
	}

}   

/***********************************************************************************************************************
 * Function Name: Operate_SetupAction
 * Description  : LIN 명령(lin_aaf_command)을 해석하여 적절한 Action 모드로 진입 준비를 수행함
 * Called By    : Operate_Waiting
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
static void Operate_SetupAction(void) {

	if ((lin_aaf_command == OPEN) || (lin_aaf_command == CLOSE) ||
        (lin_aaf_command == OPEN_1ST) || (lin_aaf_command == OPEN_2ND))
    {
        Operate_Action(HighSpeed_1stOpenOverride(lin_aaf_command));
	}
	else if ((lin_aaf_command == DIAG_MODE_OPEN) && (AAF_Tx_Position != DIAG_MODE_OPEN)) // lin init command chk
	{
		Operate_Action(DIAG_MODE_OPEN);
	}
	else if ((lin_aaf_command == DIAG_MODE_CLOSE) && (AAF_Tx_Position != DIAG_MODE_CLOSE)) // lin init command chk
	{
		Operate_Action(DIAG_MODE_CLOSE);
	}
	else if (lin_aaf_command == DIAG_MODE_AUTO) // lin init command chk
	{
		Drv8889_Wakeup();

		if (diag_mode_auto_action == ON)
		{
			if (diag_mode_auto_dir == OPEN)
			{
				diag_mode_auto_dir = CLOSE;
			}
			else if (diag_mode_auto_dir == CLOSE)
			{
				diag_mode_auto_dir = OPEN;
			}
			else
			{
				//invalid
			}
		}
		else
		{
			diag_mode_auto_action = ON;
			diag_mode_auto_dir = OPEN;
		}

		G_Timer1msFlag.DiagAutoModeFlag = ON;
		aaf_action = DIAG_MODE_AUTO;
		aaf_step = AAF_OPERATE;
	}
	else
	{
		//invalid
	}

	aaf_action_complete_chk = FLAP_START;

	step_start_flag = OFF;

}

/***********************************************************************************************************************
 * Function Name: Operate_Action
 * Description  : LIN 명령을 받아 모터 드라이버를 깨우고 해당 동작 모드로 설정함
 * Arguments    : action - 실행할 동작 (OPEN, CLOSE, OPEN_1ST 등)
 * Return Value : void
 ***********************************************************************************************************************/
static void Operate_Action(unsigned int action)
{
    Drv8889_Wakeup();
    G_Timer1ms.DiagAutoMode = 0U;
    G_Timer1msFlag.DiagAutoModeFlag = OFF;
    diag_mode_auto_action = OFF;
    
    aaf_action = action;
    aaf_step = AAF_OPERATE;
}

/***********************************************************************************************************************
 * Function Name: Operate_SetupAutoAction
 * Description  : 진단 자동(Auto) 모드 실행 중, 방향을 전환하여 연속 동작을 설정함
 * Called By    : Operate_Waiting
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
static void Operate_SetupAutoAction(void)
{
    if (diag_mode_auto_dir == OPEN)
    {
        diag_mode_auto_dir = CLOSE;
    }
    else if (diag_mode_auto_dir == CLOSE)
    {
        diag_mode_auto_dir = OPEN;
    }
    else
    {
        // Invalid 
    }

    aaf_action = DIAG_MODE_AUTO;
    aaf_step = AAF_OPERATE;

    aaf_action_complete_chk = FLAP_START;
    G_Timer1msFlag.DiagAutoModeFlag = ON;
    step_start_flag = OFF;
}

/***********************************************************************************************************************
 * Function Name: Operate_Process
 * Description  : AAF_OPERATE 상태에서 요청된 액션 타입(일반/진단)에 따라 적절한 처리 함수를 호출함
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
static void Operate_Process(void)
{
    Operating_flag = 1U;
    
    if ((aaf_action == OPEN) || (aaf_action == CLOSE) || 
        (aaf_action == OPEN_1ST) || (aaf_action == OPEN_2ND))
    {
        Operate_NormalProcess();
    }
    else
    {
        Operate_DiagProcess();
    }

    aaf_action_complete_chk = FLAP_MOVING;
}

/***********************************************************************************************************************
 * Function Name: Operate_NormalProcess
 * Description  : 현재 스텝 위치(step_position)와 목표 위치를 비교하여 모터를 구동할지, 완료 상태로 넘길지 결정함
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
static void Operate_NormalProcess(void)
{
    unsigned int target_pos;

    if (aaf_action == OPEN)
    {
        if (step_position >= (step_position_open + limit_step_position))
            Operate_NormalAction(OPEN);
        else
            aaf_step = TRAVEL_RANGE_COMPLETE_CHECK;
    }
    else if (aaf_action == CLOSE)
    {
        if (step_position <= (step_position_close - limit_step_position))
            Operate_NormalAction(CLOSE);
        else
            aaf_step = TRAVEL_RANGE_COMPLETE_CHECK;
    }
    else if (aaf_action == OPEN_1ST)
    {
        target_pos = step_position_open + (unsigned int)(((unsigned long)(step_position_close - step_position_open) * AAF_1ST_OPEN_ANGLE) / AAF_FULL_ANGLE);
        
        if (step_position > (target_pos + ERROR_RANGE)) {
            Operate_NormalAction(OPEN);
        } else if (step_position < (target_pos - ERROR_RANGE)) {
            Operate_NormalAction(CLOSE);
        } else {
            aaf_step = TRAVEL_RANGE_COMPLETE_CHECK;
        }
        Diag_Mode = 0U;
    }
    else if (aaf_action == OPEN_2ND)
    {
        target_pos = step_position_open + (unsigned int)(((unsigned long)(step_position_close - step_position_open) * AAF_2ST_OPEN_ANGLE) / AAF_FULL_ANGLE);
        
        if (step_position > (target_pos + ERROR_RANGE)) {
            Operate_NormalAction(OPEN);
        } else if (step_position < (target_pos - ERROR_RANGE)) {
            Operate_NormalAction(CLOSE);
        } else {
            aaf_step = TRAVEL_RANGE_COMPLETE_CHECK;
        }
        Diag_Mode = 0U;
    }
    else
    {
        //invalid
    }
}

/***********************************************************************************************************************
 * Function Name: Operate_NormalAction
 * Description  : 일반 동작(Normal Mode)을 위해 모터 방향 설정, 드라이버 On, 각종 감지 타이머를 활성화함
 * Arguments    : direction - 모터 이동 방향 (OPEN / CLOSE)
 * Return Value : void
 ***********************************************************************************************************************/
static void Operate_NormalAction(unsigned int direction)
{
	if (direction == OPEN) Motor_Open2();
    else Motor_Close2();

    Drv8889_On();
    motor_start = ON;
    G_Timer1msFlag.External10sCheckFlag = ON; 
    G_Timer1msFlag.StallCheckFlag = ON;
    G_Timer1ms.StallTime = 0U;
    TRQ_COUNT = MOTOR_STALL_CHK_NORMAL_VALUE;

    if (direction == OPEN) flap_move = OPEN;
    else flap_move = CLOSE;

    Diag_Mode = 0U;
    aaf_step = TRAVEL_RANGE_COMPLETE_CHECK;
}


/***********************************************************************************************************************
 * Function Name: Operate_DiagProcess
 * Description  : 진단 모드 요청에 따라 강제 열림/닫힘 또는 오토 사이클 동작을 수행함
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
static void Operate_DiagProcess(void)
{
    if (aaf_action == DIAG_MODE_OPEN)
    {
        Operate_DiagAction(OPEN, OFF);
    }
    else if (aaf_action == DIAG_MODE_CLOSE)
    {
        Operate_DiagAction(CLOSE, OFF);
    }
    else if ((aaf_action == DIAG_MODE_AUTO) && (diag_mode_auto_dir == OPEN))
    {
        Operate_DiagAction(OPEN, ON); //auto
    }
    else if ((aaf_action == DIAG_MODE_AUTO) && (diag_mode_auto_dir == CLOSE))
    {
        Operate_DiagAction(CLOSE, ON); //auto
    }
    else
    {
        // invalid 
    }
}

/***********************************************************************************************************************
 * Function Name: Operate_DiagAction
 * Description  : 진단 동작(Diagnostic Mode)을 위해 모터를 구동하고 진단 모드 플래그(Diag_Mode)를 설정함
 * Arguments    : direction - 모터 이동 방향
 * is_auto   - 자동 반복 모드 여부 (ON/OFF)
 * Return Value : void
 ***********************************************************************************************************************/
static void Operate_DiagAction(unsigned int direction, unsigned int is_auto)
{
    if (direction == OPEN) Motor_Open2();
    else Motor_Close2();

    Drv8889_On();
    motor_start = ON;
    G_Timer1msFlag.StallCheckFlag = ON;
    G_Timer1ms.StallTime = 0;
    TRQ_COUNT = MOTOR_STALL_CHK_NORMAL_VALUE;
    Diag_Mode = 1;

    if (direction == OPEN) flap_move = OPEN;
    else flap_move = CLOSE;

	// G_Timer1msFlag.InitCheckFlag = 1;
    
	if (is_auto == ON)
    {
        G_Timer1msFlag.DiagAutoModeFlag = 1U;
    }
	
    aaf_step = TRAVEL_RANGE_COMPLETE_CHECK;
}

/***********************************************************************************************************************
 * Function Name: Operate_CheckRange
 * Description  : 목표 위치 도달 여부를 확인하고, 도달 시 TX 포지션을 업데이트한 후 종료 상태로 전환함
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
static void Operate_CheckRange(void)
{   
    Operate_SelectAAFxMode();
    unsigned int target_pos;

    if ((aaf_action == OPEN) && (step_position <= (step_position_open + limit_step_position))) 
    {
        AAF_Tx_Position = OPEN;
        Operate_SelectTxPostion();
        aaf_step = FINISHED_OPERATE;
    }
    else if ((aaf_action == CLOSE) && (step_position >= (step_position_close - limit_step_position)))
    {
        AAF_Tx_Position = CLOSE;
        Operate_SelectTxPostion();
        aaf_step = FINISHED_OPERATE;
    }
    else if (aaf_action == OPEN_1ST)
    {
        target_pos = step_position_open + (unsigned int)(((unsigned long)(step_position_close - step_position_open) * AAF_1ST_OPEN_ANGLE) / AAF_FULL_ANGLE);
        
        if (((flap_move == OPEN) && (step_position <= target_pos)) || 
            ((flap_move == CLOSE) && (step_position >= target_pos)))
        {
            AAF_Tx_Position = OPEN_1ST;
            Operate_SelectTxPostion();
            aaf_step = FINISHED_OPERATE;
        }
        else
        {
            Operate_HandleStall();
        }
    }
    else if (aaf_action == OPEN_2ND)
    {
        target_pos = step_position_open + (unsigned int)(((unsigned long)(step_position_close - step_position_open) * AAF_2ST_OPEN_ANGLE) / AAF_FULL_ANGLE);
        
        if (((flap_move == OPEN) && (step_position <= target_pos)) || 
            ((flap_move == CLOSE) && (step_position >= target_pos)))
        {
            AAF_Tx_Position = OPEN_2ND;
            Operate_SelectTxPostion();
            aaf_step = FINISHED_OPERATE;
        }
        else
        {
            Operate_HandleStall();
        }
    }
    else if ((aaf_action == DIAG_MODE_OPEN) && (step_position <= (step_position_open + limit_step_position)))
    {
        AAF_Tx_Position = DIAG_MODE_OPEN;
        aaf_step = FINISHED_OPERATE;
    }
    else if ((aaf_action == DIAG_MODE_CLOSE) && (step_position >= (step_position_close - limit_step_position)))
    {
        AAF_Tx_Position = DIAG_MODE_CLOSE;
        aaf_step = FINISHED_OPERATE;
    }
    else if ((aaf_action == DIAG_MODE_AUTO) && (diag_mode_auto_dir == OPEN) && (step_position <= (step_position_open + limit_step_position)))
    {
        AAF_Tx_Position = DIAG_MODE_AUTO;
        aaf_step = FINISHED_OPERATE;
    }
    else if ((aaf_action == DIAG_MODE_AUTO) && (diag_mode_auto_dir == CLOSE) && (step_position >= (step_position_close - limit_step_position)))
    {
        AAF_Tx_Position = DIAG_MODE_AUTO;
        aaf_step = FINISHED_OPERATE;
    }
    else{
        Operate_HandleStall();
    }
}

static void Operate_SelectAAFxMode(void)
{
	const uint8_t ReqAAFDiagMode[] = {0U, ReqAAF1DiagMode, ReqAAF2DiagMode, ReqAAF3DiagMode};

	if (AAFx_Index < 1U || AAFx_Index > 3U)
	{
		return;
	}

	if (ReqAAFDiagMode[AAFx_Index] != 0U)
	{
		if (aaf_action == DIAG_MODE_AUTO)
		{
			AAFx_Mode = 1U;
		}
		else if (aaf_action == DIAG_MODE_OPEN)
		{
			AAFx_Mode = 2U;
		}
		else if (aaf_action == DIAG_MODE_CLOSE)
		{
			AAFx_Mode = 3U;
		}
	}
	else
	{
		AAFx_Mode = 0U;
	}
}

void Operate_SelectTxPostion(void)
{
	if (AAFx_Index == AAF_1)
	{
		AAF_Tx_Position = aaf_action;
	}
	else if (AAFx_Index == AAF_2)
	{
		AAF_Tx_Position = aaf_action;
	}
	else if (AAFx_Index == AAF_3)
	{
		AAF_Tx_Position = aaf_action;
	}
	else
	{
        //invaild
	}
}

/***********************************************************************************************************************
 * Function Name: Operate_HandleStall
 * Description  : 동작 중 스톨(모터 걸림) 발생 시 모터를 정지하고 상태를 업데이트함
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
static void Operate_HandleStall(void)
{
	// if(((motor_stall_flag == MOTOR_STALL) && (G_Timer1ms.StallCheck >= 100)) || (G_Timer1ms.InitCheck >= 4800))
	if ((motor_stall_flag == MOTOR_STALL) && (G_Timer1ms.StallCheck >= 100U))
	{
		Drv8889_Off2();
		motor_start = OFF;
		softstart_complete = OFF;
		motor_step_value = STEP_TIME_1000RPM;

		if (aaf_action == DIAG_MODE_OPEN)
		{
			AAF_Tx_Position = DIAG_MODE_OPEN;
			aaf_step = FINISHED_OPERATE;
		}
		else if (aaf_action == DIAG_MODE_CLOSE)
		{
			AAF_Tx_Position = DIAG_MODE_CLOSE;
			aaf_step = FINISHED_OPERATE;
		}
		else if (aaf_action == DIAG_MODE_AUTO)
		{
			AAF_Tx_Position = DIAG_MODE_AUTO;
			aaf_step = FINISHED_OPERATE;
		}
		else
		{
			//invalid
		}
		
		G_Timer1msFlag.External10sCheckFlag = OFF; // 10s chk timer on
		G_Timer1ms.External10sCheck = 0U;
		aaf_step = CHECK_AAF_CONDITION;
		G_Timer1msFlag.InitCheckFlag = 0U; // test
		G_Timer1ms.InitCheck = 0U;		// test

		aaf_action = FLAP_STOP;
	}
}

/***********************************************************************************************************************
 * Function Name: Operate_CheckCondition
 * Description  : 스톨 발생 후 정지 상태에서 끼임(Anti-Pinch) 감지를 위한 초기화 및 플래그 설정을 수행함
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
static void Operate_CheckCondition(void)
{
	if (flap_move == OPEN)
	{
		antipinch_previous_action = OPEN;
		antipinch_action_on = ON;

		motor_start = OFF;
		G_Timer1msFlag.StallTimeFlag = 0U;
		G_Timer1ms.StallTime = 0U; // stall reset

		flap_move = FLAP_STOP;
	}
	else if (flap_move == CLOSE)
	{
		antipinch_previous_action = CLOSE;
		antipinch_action_on = ON;

		motor_start = OFF;
		G_Timer1msFlag.StallTimeFlag = 0U;
		G_Timer1ms.StallTime = 0U; // stall reset

		flap_move = FLAP_STOP;
	}
	else
	{
		//invalid
	}

	G_Timer1ms.StallCheck = 0U;		 // test
	G_Timer1msFlag.StallCheckFlag = 0U; // test	
}

/***********************************************************************************************************************
 * Function Name: Operate_Init
 * Description  : 시스템 초기화 시퀀스(학습 모드)를 단계별로 처리함
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
static void Operate_Init(void)
{
switch (aaf_init_step)
	{
	case START_INITIALIZATION:
		AAFx_InitStatus = DURING_INITIALIZATION;

		if (fail_safety_flag == ON)
		{
			init_move_step = 0U;
		}

		aaf_init_step = CHECK_TRAVELRANGE;

		break;

	case CHECK_TRAVELRANGE:
		Init_move();

		if ((init_move_step == 19U) && (fail_safety_flag == OFF))
		{
			init_move_step = 0U;
			aaf_init_step = NORMAL_INITIALIZATION;
		}

		break;

	case TRAVEL_RANGE_ERROR:

		break;

	case NORMAL_INITIALIZATION:
		aaf_step = FINISHED_OPERATE;
		AAF_Tx_Position = OPEN;
		AAFx_Position_Status = Open_Status;
		AAFx_InitStatus = NORMAL_FINISHED_INITIALIZATION;

		break;

	default:
		break;
	}
}

/***********************************************************************************************************************
 * Function Name: Operate_Finish
 * Description  : 모든 동작이 완료된 후 드라이버를 끄고 변수들을 초기화하며 대기 상태(AAF_WAITING)로 전환함
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
static void Operate_Finish(void)
{
	Drv8889_Off2();							  // drv of
	motor_start = OFF;					  // step stop
	G_Timer1msFlag.External10sCheckFlag = OFF; // 10s chk timer off
	G_Timer1ms.External10sCheck = 0U;

	if ((AAF_Tx_Position == OPEN) && (Diag_Mode == 0U))
	{
			AAFx_Position_Status = Open_Status;
	}
	else if ((AAF_Tx_Position == CLOSE) && (Diag_Mode == 0U))
	{
		AAFx_Position_Status = Close_Status;
	}
	else if ((AAF_Tx_Position == DIAG_MODE_OPEN) || (AAF_Tx_Position == DIAG_MODE_CLOSE) || (AAF_Tx_Position == DIAG_MODE_AUTO))
	{
		AAFx_Position_Status = Unknown_Status;
		//only sx3k
		AAFx_SNSR1_Position = Initial_Value;
		AAFx_SNSR2_Position = Initial_Value;
		AAFx_SNSR3_Position = Initial_Value;
		AAFx_SNSR4_Position = Initial_Value;
	}
	else
	{
		//invalid
	}

	G_Timer1ms.StallCheck = 0U;		 // test
	G_Timer1msFlag.StallCheckFlag = 0U; // test
	softstart_complete = OFF;
	motor_step_value = STEP_TIME_1000RPM;
	G_Timer1msFlag.InitCheckFlag = 0U;						  // test
	G_Timer1ms.InitCheck = 0U;							  // test
	G_Timer1msFlag.StallTimeFlag = 0U;								  // stall reset
	G_Timer1ms.StallTime = 0U;							  // stall reset
	TRQ_COUNT = MOTOR_STALL_CHK_NORMAL_VALUE; // stall reset
    Operating_flag = 0U;

	if (aaf_action == DIAG_MODE_AUTO)
	{
		if (G_Timer1ms.DiagAutoMode >= 5000U)
		{
			G_Timer1ms.DiagAutoMode = 0U;
			G_Timer1msFlag.DiagAutoModeFlag = 0U;

			AAF_Tx_Position = DIAG_MODE_AUTO;

			aaf_action = FLAP_STOP;
			aaf_action_complete_chk = FLAP_STOP;
			aaf_step = AAF_WAITING;
		}
	}
	else
	{
		aaf_action = FLAP_STOP;
		aaf_action_complete_chk = FLAP_STOP;
		aaf_step = AAF_WAITING;
	}
}

/***********************************************************************************************************************
 * Function Name: Operating_Mode
 * Description  : AAF 시스템의 메인 상태 머신(State Machine). 현재 단계(aaf_step)에 따라 적절한 프로세스를 호출함
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
void Operating_Mode(void)
{
	switch (aaf_step)
	{
	case AAF_WAITING:
		
		Operate_Waiting();
		
		break;

	case AAF_OPERATE:

		Operate_Process();

		break;

	case TRAVEL_RANGE_COMPLETE_CHECK:

	    Operate_CheckRange();
		
		break;

	case CHECK_AAF_CONDITION:

		Operate_CheckCondition();

		break;

	case AAF_INITIALIZATION:

		// init action

		Operate_Init();

		break;

	case FINISHED_OPERATE:

		Operate_Finish();

		break;

	default:
		break;
	}
}

void Torque_TestMode(void)
{
	torque_test_position = AAF1_TargetPosition;
	
	// if ((AAFx_Index == AAF_1) && (ReqRespAAFID == AAF_1))
	// {
	// 	torque_test_position = AAF1_TargetPosition;
	// }
	// else if ((AAFx_Index == AAF_2) && (ReqRespAAFID == AAF_2))
	// {
	// 	torque_test_position = AAF2_TargetPosition;
	// }
	// else if ((AAFx_Index == AAF_3) && (ReqRespAAFID == AAF_3))
	// {
	// 	torque_test_position = AAF3_TargetPosition;
	// }
	// else
	// {
	// 	torque_test_position = WAITING;
	// }
	
    switch (torque_test_position)
    {
    case OPEN:        /* 0x03 - 스토퍼 무시하고 OPEN 방향 계속 밀기 */
        Motor_Open();
        Drv8889_On();
        motor_start = ON;
        break;
    case CLOSE:       /* 0x00 - 스토퍼 무시하고 CLOSE 방향 계속 밀기 */
        Motor_Close();
        Drv8889_On();
        motor_start = ON;
        break;
    case UNKOWN_POSITION:  /* 0x07 - STOP */
        Drv8889_Off2();
        motor_start = OFF;
        break;
    default:
        break;
    }
}
