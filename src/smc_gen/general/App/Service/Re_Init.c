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
	//only sx3k
	// OBD1_Close_Check = OBD1_Close_Check_memory_read;
	// OBD1_Open_Check = OBD1_Open_Check_memory_read;
	// OBD2_Close_Check = OBD2_Close_Check_memory_read;
	// OBD2_Open_Check = OBD2_Open_Check_memory_read;
	// OBD3_Close_Check = OBD3_Close_Check_memory_read;
	// OBD3_Open_Check = OBD3_Open_Check_memory_read;
	// OBD_Init();
}

/***********************************************************************************************************************
 * Function Name: Step_Check
 * Description  : Flash에서 읽은 초기화 위치 정보가 유효한지 확인하고, 이상 시 Re_Init을 수행함.
 ***********************************************************************************************************************/
static void Step_Check(void)
{
    unsigned int step_range;
    unsigned int minimum_range;
    unsigned int maximum_range;
    unsigned int reinit_required;

    step_range = step_position_close - step_position_open;

    minimum_range = STEP_POSITION_MINIMUM_RANGE;
    maximum_range = STEP_POSITION_MAXIMUM_RANGE;

    reinit_required = (
        /* 1. 이동 범위(Range) 및 마진(Limit) 체크 */
        (step_range           <= minimum_range)                             ||
        (step_range           >  maximum_range)                             ||
        (step_position        == REFERENCE_POSITION)                        ||
        (step_position        <  step_position_open  + limit_step_position) ||
        (step_position        >  step_position_close - limit_step_position) ||

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
            AAF_Tx_Position = OPEN;
            AAFx_InitStatus = NORMAL_FINISHED_INITIALIZATION;
            evrdy_on_flag = ON;
            aaf_action_complete_chk = FLAP_STOP;
            antipinch_previous_action = ANTIWAIT;
        }
        else if (AAFx_Position_Status == Close_Status)
        {
            aaf_step = AAF_WAITING;
            aaf_init_step = NORMAL_INITIALIZATION;
            AAF_Tx_Position = CLOSE;
            AAFx_InitStatus = NORMAL_FINISHED_INITIALIZATION;
            evrdy_on_flag = ON;
            aaf_action_complete_chk = FLAP_STOP;
            antipinch_previous_action = ANTIWAIT;
        }
        else
        {
            /* Invalid position status */
        }
    }
}


/***********************************************************************************************************************
 * Function Name: Re_Init
 * Description  : AAF 초기화가 필요한 경우 초기화 상태 및 관련 변수를 재설정함.
 ***********************************************************************************************************************/
void Re_Init(void)
{
    G_Timer1ms.DiagAutoMode = 0U;
    G_Timer1msFlag.DiagAutoModeFlag = OFF;
    diag_mode_auto_action = OFF;

    aaf_action = 0U;
    TRQ_COUNT = MOTOR_STALL_CHK_NORMAL_VALUE;

    aaf_step = AAF_INITIALIZATION;
    aaf_init_step = START_INITIALIZATION;
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
    wake_up_motor_range_init_chk = 0U;
    step_start_flag = OFF;
    aaf_action_complete_chk = FLAP_STOP;

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

    if ((step_check_flag == 1U) &&
        (AAFx_InitStatus == NORMAL_FINISHED_INITIALIZATION))
    {
        power_chk = Shutdown_Check;
        FDL_Write();
        step_check_flag = 2U;
    }
}