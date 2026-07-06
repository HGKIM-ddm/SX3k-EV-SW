#include "FailSafety_Mode.h"
#include "Service.h"

/***********************************************************************************************************************
 * Fail-Safety_Mode
 ***********************************************************************************************************************/
/***********************************************************************************************************************
 * Function Name: FS_MotorOpenStart
 * Description  : 모터 OPEN 방향 구동을 시작하고 관련 변수를 초기화함.
 *                (원본 case 0, 5, 10의 공통 로직)
 * Called By    : Run_fs_cycle_1_open, Run_fs_cycle_2_open, Run_fs_final_open
 * Arguments    : next_step - 초기화 후 이동할 다음 Fail-Safety Step
 * Return Value : void
 ***********************************************************************************************************************/
static void FS_MotorOpenStart(unsigned int next_step)
{
    Motor_Open();                                             /* dir OPEN */
    Drv8889_On2();                                                 /* drv on */
    motor_start = ON;
    G_Timer1ms.Spi = 0U;
    aaf_action = OPEN;
    aaf_step = AAF_WAITING;
    motor_stall_flag = MOTOR_NORMAL;                          /* stall reset */
    G_Timer1msFlag.StallTimeFlag = 0U;                                        /* stall reset */
    G_Timer1ms.StallTime = 0U;                                   /* stall reset */
    TRQ_COUNT = MOTOR_STALL_CHK_NORMAL_VALUE;         /* stall reset */
    G_Timer1ms.InitCheck = 0U;                                    /* step start */
    G_Timer1msFlag.InitCheckFlag = 1U;
    fail_safety_step = next_step;
}
 
/***********************************************************************************************************************
 * Function Name: FS_CheckStallStop
 * Description  : 스톨(Stall) 또는 타임아웃 발생 시 모터를 정지하고 다음 단계로 이동함.
 *                (원본 case 1, 6, 11의 공통 로직)
 * Called By    : Run_fs_cycle_1_stall, Run_fs_cycle_2_stall, Run_fs_final_stall
 * Arguments    : next_step - 정지 후 이동할 다음 Fail-Safety Step
 * Return Value : void
 ***********************************************************************************************************************/
static void FS_CheckStallStop(unsigned int next_step)
{
    if ((motor_stall_flag == MOTOR_STALL) || (G_Timer1ms.InitCheck >= 8000U))
    {
        Drv8889_Off2();
        motor_start = OFF;
        G_Timer1msFlag.StallTimeFlag = 0U;
        G_Timer1ms.StallTime = 0U;                               /* stall reset */
        aaf_action = FLAP_STOP;
        G_Timer1msFlag.InitCheckFlag = 0U;
        G_Timer1ms.InitCheck = 0U;
        softstart_complete = OFF;
        motor_step_value = STEP_TIME_1000RPM;
        fail_safety_step = next_step;
    }
}
 
/***********************************************************************************************************************
 * Function Name: FS_Delay3minute
 * Description  : 3분 대기 타이머를 구동하고, 완료 시 다음 단계로 이동함.
 *                (원본 case 2, 7의 공통 로직)
 * Called By    : Run_fs_cycle_1_wait, Run_fs_cycle_2_wait
 * Arguments    : next_step - 3분 대기 완료 후 이동할 다음 Fail-Safety Step
 * Return Value : void
 ***********************************************************************************************************************/
static void FS_Delay3minute(unsigned int next_step)
{
    G_Timer1msFlag.Timer3minuteFlag = 1U;
    antipinch_step = 0U;
 
    if (G_Timer1ms.Timer3minuteSec >= MINUTE_3)
    {
        G_Timer1msFlag.Timer3minuteFlag = 0U;
        G_Timer1ms.Timer3minuteSec = 0U;
        G_Timer1ms.Timer3minute = 0U;
        fail_safety_step = next_step;
    }
}
 
/***********************************************************************************************************************
 * Function Name: FS_ReInit
 * Description  : Re_Init()을 호출하고 다음 단계로 이동함.
 *                (원본 case 3, 8의 공통 로직)
 * Called By    : Run_fs_cycle_1_reinit, Run_fs_cycle_2_reinit
 * Arguments    : next_step - Re_Init 호출 후 이동할 다음 Fail-Safety Step
 * Return Value : void
 ***********************************************************************************************************************/
static void FS_ReInit(unsigned int next_step)
{
    Re_Init();
    fail_safety_step = next_step;
}
 
/***********************************************************************************************************************
 * Function Name: FS_CheckInitComplete
 * Description  : 초기화 이동(Init Move) 시퀀스 완료를 확인하고 정상 상태로 복귀함.
 *                (원본 case 4, 9의 공통 로직)
 * Called By    : Run_fs_cycle_1_complete, Run_fs_cycle_2_complete
 * Return Value : void
 ***********************************************************************************************************************/
static void FS_CheckInitComplete(void)
{
    if (init_move_step == 19U)
    {
        init_move_step = 0U;
        aaf_init_step = NORMAL_INITIALIZATION;
        fail_safety_step = 0U;
        fail_safety_flag = OFF;
        AAFx_ErrorStatus = No_ErrorStatus;
    }
}
 
/***********************************************************************************************************************
 * Function Name: FS_FinalErrorSet
 * Description  : 최종 에러 상태를 확정하고 관련 플래그를 설정함.
 *                (원본 case 12의 로직)
 * Called By    : FS_Cycle3
 * Return Value : void
 ***********************************************************************************************************************/
static void FS_FinalErrorSet(void)
{
    AAF_Tx_Position = UNKOWN_POSITION;
    AAFx_Position_Status = Unknown_Status;
    AAFx_InitStatus = ABNORMAL_FINISHED_INITIALIZATION;
    motor_fault_chk = 1U;
}
 
/* =========================================================================================
 * Fail Safety Cycle Execution Functions
 * ========================================================================================= */
 
/***********************************************************************************************************************
 * Function Name: FS_Cycle1
 * Description  : Fail-Safety 1차 사이클 (Step 0 ~ 4) 실행.
 *                Motor OPEN 구동 → 스톨 감지 → 3분 대기 → Re_Init → 완료 확인
 * Called By    : FailSafety_Mode
 * Return Value : void
 ***********************************************************************************************************************/
static void FS_Cycle1(void)
{
    switch (fail_safety_step)
    {
    case 0:                                   /* Motor OPEN 구동 시작 */
        FS_MotorOpenStart(1U);
        break;
    case 1:                                   /* 스톨/타임아웃 감지 → 모터 정지 */
        FS_CheckStallStop(2U);
        break;
    case 2:                                   /* 3분 대기 */
        FS_Delay3minute(3U);
        break;
    case 3:                                   /* Re_Init 호출 */
        FS_ReInit(4U);
        break;
    case 4:                                   /* 초기화 완료 확인 → 정상 복귀 */
        FS_CheckInitComplete();
        break;
    default:
        break;
    }
}
 
/***********************************************************************************************************************
 * Function Name: FS_Cycle2
 * Description  : Fail-Safety 2차 사이클 (Step 5 ~ 9) 실행.
 *                1차 사이클과 동일한 과정을 한 번 더 반복함.
 *                Motor OPEN 구동 → 스톨 감지 → 3분 대기 → Re_Init → 완료 확인
 * Called By    : FailSafety_Mode
 * Return Value : void
 ***********************************************************************************************************************/
static void FS_Cycle2(void)
{
    switch (fail_safety_step)
    {
    case 5:                                   /* Motor OPEN 구동 시작 */
        FS_MotorOpenStart(6U);
        break;
    case 6:                                   /* 스톨/타임아웃 감지 → 모터 정지 */
        FS_CheckStallStop(7U);
        break;
    case 7:                                   /* 3분 대기 */
        FS_Delay3minute(8U);
        break;
    case 8:                                   /* Re_Init 호출 */
        FS_ReInit(9U);
        break;
    case 9:                                   /* 초기화 완료 확인 → 정상 복귀 */
        FS_CheckInitComplete();
        break;
    default:
        break;
    }
}
 
/***********************************************************************************************************************
 * Function Name: FS_Cycle3
 * Description  : Fail-Safety 최종 사이클 (Step 10 ~ 12) 실행.
 *                마지막 Motor OPEN 시도 후 실패 시 에러 확정 (원본 case 10~12).
 * Called By    : FailSafety_Mode
 * Return Value : void
 ***********************************************************************************************************************/
static void FS_Cycle3(void)
{
    switch (fail_safety_step)
    {
    case 10:                                  /* Motor OPEN 구동 시작 (최후 시도) */
        FS_MotorOpenStart(11U);
        break;
    case 11:                                  /* 스톨/타임아웃 감지 → 모터 정지 */
        FS_CheckStallStop(12U);
        break;
    case 12:                                  /* 최종 에러 확정 */
        FS_FinalErrorSet();
        break;
    default:
        break;
    }
}
 
/* =========================================================================================
 * Main Fail Safety Mode Dispatcher
 * ========================================================================================= */
 
/***********************************************************************************************************************
 * Function Name: FailSafety_Mode
 * Description  : Fail-Safety 모드의 진입점. 현재 단계(step)에 따라 1차/2차/최종 사이클 함수를 호출함.
 * Called By    : Safety_Check
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
void FailSafety_Mode(void)
{
    if (fail_safety_flag == ON)
    {
        /* [Cycle 1] Steps 0 ~ 4 */
        if (fail_safety_step <= 4U)
        {
            FS_Cycle1();
        }
        /* [Cycle 2] Steps 5 ~ 9 */
        else if (fail_safety_step <= 9U)
        {
            FS_Cycle2();
        }
        /* [Final Cycle] Steps 10 ~ 12 */
        else
        {
            FS_Cycle3();
        }
    }
}

