#include "Sleep.h"
#include "Service.h"

static uint8_t Sleep_Stall = OFF;

static uint8_t Sleep_AbortOnFault(void)
{
    if ((AAFx_Motor_Fault   == 0U)       &&
        (AAFx_Circuit_Short == NO_ERROR) &&
        (AAFx_Circuit_Open  == NO_ERROR))
    {
        return 0U;
    }

    Motor_Off();

    aaf_step      = AAF_INITIALIZATION;
    aaf_init_step = WAIT_INITIALIZATION;

    AAF_Tx_Position      = UNKOWN_POSITION;
    AAFx_Position_Status = Unknown_Status;
    AAFx_InitStatus      = DURING_INITIALIZATION;

    motor_stall_flag = MOTOR_NORMAL;

    sleep_step = 8U;   
    return 1U;
}

/***********************************************************************************************************************
 * Function Name: Sleep_Reset
 * Description  : Lin Sleep 모드 초기 진입 시 변수 초기화 수행 (Case 0)
 * Called By    : Sleep_Ready
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
static void Sleep_Reset(void)
{
    Motor_Off();

    G_Timer1msFlag.InitFailCheckFlag = 0U;
    G_Timer1ms.InitFailCheck = 0U;

    Sleep_Stall = OFF;

    sleep_step = 1U;
}

/***********************************************************************************************************************
 * Function Name: Sleep_Delay
 * Description  : 50ms 동안 대기 후 다음 단계로 이동 (Case 1)
 * Called By    : Sleep_Ready
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
static void Sleep_Delay(void)
{
    G_Timer1msFlag.LinSleepModeFlag = 1U;

    if (G_Timer1ms.LinSleepMode >= 50U)
    {
        G_Timer1msFlag.LinSleepModeFlag = 0U;
        G_Timer1ms.LinSleepMode = 0U;
        sleep_step = 2U;
    }
}

/***********************************************************************************************************************
 * Function Name: Sleep_ParsingCommand
 * Description  : LIN Sleep 진입 전 마지막 수신 명령을 해석하여 Sleep 전 최종 구동 방향을 결정함
 *                - AAF_LINOut == 0 : 정상 종료 조건, 마지막 마스터 명령을 수행한 후 Sleep 진입
 *                - AAF_LINOut == 1 : 비정상 종료/LIN 단선 조건, OPEN 방향으로 이동 후 Sleep 진입 (case 2)
 * Called By    : Sleep_Ready
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
static void Sleep_ParsingCommand(void)
{
    if (AAF_LINOut == 0x00U)
    {
        if (IGN_Chk == 0U)
        {
            sleep_step = 8U;
        }
        else if ((lin_aaf_command == OPEN) ||
                 (lin_aaf_command == OPEN_1ST) ||
                 (lin_aaf_command == OPEN_2ND) ||
                 (lin_aaf_command == CLOSE))
        {
            Motor_Wakeup();

            /* FS 중(선점 시 FailSafety_Abort 가 flag 를 먼저 지움) 또는 위치 미확정 : 최종 명령 대신 OPEN (사양 5.2.8) */
            if ((fail_safety_flag == ON) || (reinit_request_flag == ON))
            {
                aaf_action = OPEN;
            }
            else
            {
                aaf_action = lin_aaf_command;
            }

            sleep_step = 3U;
        }
        else
        {
            sleep_step = 8U;
        }
    }
    else if (AAF_LINOut == 0x01U)
    {
        Motor_Wakeup();

        aaf_action = OPEN;
        sleep_step = 3U;
    }
    else
    {
        sleep_step = 8U;
    }
}


/***********************************************************************************************************************
 * Function Name: Sleep_StartMotor
 * Description  : 결정된 Action(OPEN/CLOSE)에 따라 모터 구동을 시작함 (Case 3)
 * Called By    : Sleep_Start
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
static void Sleep_StartMotor(void)
{
    if (Sleep_AbortOnFault() == 1U) { return; }

    if ((aaf_action == OPEN) || (aaf_action == OPEN_1ST) || (aaf_action == OPEN_2ND))
    {
        Motor_Open2();
        Motor_On(); 

        motor_stall_flag = MOTOR_NORMAL;
        G_Timer1ms.StallTime = 0U;
        G_Timer1ms.TrqCheck = 0U;
        
        sleep_step = 4U;
    }
    else if (aaf_action == CLOSE)
    {
        Motor_Close2();
        Motor_On(); 

        motor_stall_flag = MOTOR_NORMAL;
        G_Timer1ms.StallTime = 0U;
        G_Timer1ms.TrqCheck = 0U;
        
        sleep_step = 4U;
    }
    else
    {
        sleep_step = 8U;
    }
}

/***********************************************************************************************************************
 * Function Name: Sleep_CheckCompletion
 * Description  : 모터 구동 중 목표 위치 도달 또는 스톨 발생 여부를 확인하고 정지함 (Case 4)
 * Called By    : Sleep_Start
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
static void Sleep_CheckCompletion(void)
{
    unsigned int target_pos;
    uint8_t range_valid;

    target_pos = Operate_GetTargetPosition(aaf_action);
    range_valid = ((step_position_close > step_position_open) &&
                   ((step_position_close - step_position_open) > STEP_POSITION_MINIMUM_RANGE)) ? 1U : 0U;

    if (Sleep_AbortOnFault() == 1U) { return; }

    if (((aaf_action == OPEN) ||
         (aaf_action == OPEN_1ST) ||
         (aaf_action == OPEN_2ND)) &&
        (((range_valid == 1U) && (step_position <= (target_pos + limit_step_position))) ||
         ((range_valid == 0U) && (motor_stall_flag == MOTOR_STALL))))
    {
        Motor_Off();
        motor_stall_flag = MOTOR_NORMAL;

        if ((reinit_request_flag == ON) || (range_valid == 0U))
        {
            /* 위치 미확정 : Initial value 유지 → Wake 시 위치초기화 (사양서 3.6) */
            AAF_Tx_Position      = UNKOWN_POSITION;
            AAFx_Position_Status = Unknown_Status;
            AAFx_InitStatus      = DURING_INITIALIZATION;
        }
        else
        {
            AAF_Tx_Position = aaf_action;
            AAFx_Position_Status = Open_Status;
            AAFx_InitStatus = NORMAL_FINISHED_INITIALIZATION;
            Operate_SelectTxPostion();
        }

        aaf_step = FINISHED_OPERATE;
        sleep_step = 8U;
    }

    else if ((aaf_action == CLOSE) &&
             (motor_stall_flag == MOTOR_STALL) &&
             (step_position >= (step_position_close - limit_step_position)) &&
             (AAFx_Type == EXTERNAL_TYPE))
    {
        Motor_Off();
        step_position = step_position_close;
        motor_stall_flag = MOTOR_NORMAL;
        Sleep_Stall    = OFF;
        sleep_step = 5U;
    }

    else if ((aaf_action == CLOSE) &&
             (step_position >= (step_position_close - limit_step_position)) &&
             (AAFx_Type == INTERNAL_TYPE))
    {
        Motor_Off();
        AAF_Tx_Position = CLOSE;
        AAFx_Position_Status = Close_Status;
        AAFx_InitStatus = NORMAL_FINISHED_INITIALIZATION;
        Operate_SelectTxPostion();
        aaf_step = FINISHED_OPERATE;
        sleep_step = 8U;
    }

    else if (motor_stall_flag == MOTOR_STALL)
    {
        Motor_Off();
        motor_stall_flag = MOTOR_NORMAL;
        aaf_step = AAF_INITIALIZATION;
        aaf_init_step = WAIT_INITIALIZATION;
        AAF_Tx_Position = UNKOWN_POSITION;
        AAFx_Position_Status = Unknown_Status;
        AAFx_InitStatus = DURING_INITIALIZATION;
        Sleep_Stall    = ON;
        sleep_step = 5U;
    }
    else
    {
        if ((protection_function == ON) || ((Open_fault_check == 1U) || (Short_fault_check == 1U)) || ((AAFx_InitStatus == DURING_INITIALIZATION) && (adc_avr <= ADC_UNDER_VOLTAGE_7V)))
        {
            Error_UnknownStatus();
            sleep_step = 8U;
        }
    }
}

/***********************************************************************************************************************
 * Function Name: Sleep_StallDelay
 * Description  : External Type에서 CLOSE stopper 도달 후 OPEN 방향 복귀 전 800ms 대기
 *                기존 EV 코드에 별도 LinSleepStall 타이머가 없으므로 LinSleepMode 타이머를 재사용함.
 * Called By    : Sleep_Start
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
static void Sleep_StallDelay(void)
{
    /* CLOSE stopper 도달 후 800ms 대기 타이머 시작 */
    G_Timer1msFlag.LinSleepModeFlag = 1U;

    /* 800ms 대기 완료 */
    if (G_Timer1ms.LinSleepMode >= 800U)
    {
        /* 대기 타이머 정지 및 초기화 */
        G_Timer1msFlag.LinSleepModeFlag = 0U;
        G_Timer1ms.LinSleepMode = 0U;

        if ((Sleep_Stall == ON) && (aaf_action == OPEN))
        {
            Sleep_Stall    = OFF;
            sleep_step = 8U;
        }
        else
        {
            sleep_step = 6U;
        }
    }
}

/***********************************************************************************************************************
 * Function Name: Sleep_StallOpen
 * Description  : CLOSE stopper 도달 후 OPEN 방향으로 약 5도 복귀하기 위해 모터 구동 시작
 *                - External Type에서 stopper 압착 상태를 풀기 위한 back-off 동작
 * Called By    : Sleep_Start
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
static void Sleep_StallOpen(void)
{
    /* OPEN 방향 설정 */
    Motor_Open2();

    /* 모터 드라이버 ON */
    Motor_On();

    /* 스톨 상태 및 타이머 초기화 */
    motor_stall_flag = MOTOR_NORMAL;
    G_Timer1ms.StallTime = 0U;
    G_Timer1ms.TrqCheck = 0U;

    /* OPEN 방향 복귀 완료 여부 확인 단계로 이동 */
    sleep_step = 7U;
}

/***********************************************************************************************************************
 * Function Name: Sleep_StallStop
 * Description  : CLOSE stopper 후 OPEN 방향으로 약 5도 복귀 완료 여부를 확인하고 정지
 *                - limit_step_position이 약 5도에 해당하는 step 값으로 사용됨
 *                - 복귀 완료 후 실제 기구는 stopper에서 살짝 빠지지만, 상태는 CLOSE로 보고함
 * Called By    : Sleep_Start
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
static void Sleep_StallStop(void)
{
    unsigned int sleep_backoff_step;

    /* 이상 stall 후 OPEN 파킹 경로 */
    if (Sleep_Stall == ON)
    {
        /* OPEN stopper 감지 시 정지.
         * 위치 조건은 스텝 펄스는 계속 흐르는데 stall 이 오지 않는 경우의 하한이다. */
        if ((motor_stall_flag == MOTOR_STALL) ||
            (step_position <= (step_position_open + limit_step_position)))
        {
            Motor_Off();

            motor_stall_flag = MOTOR_NORMAL;

            Sleep_Stall    = OFF;
            sleep_step = 8U;
        }
        else
        {
            /* OPEN 방향 계속 구동 */
        }
    }
    /* 정상 close stopper 후 백오프 완료 판정 */
    else
    {
        sleep_backoff_step = step_position_close - (limit_step_position / SLEEP_BACKOFF_DIVIDER);

        if (step_position <= sleep_backoff_step)
        {
            Motor_Off();

            AAF_Tx_Position      = CLOSE;
            AAFx_Position_Status = Close_Status;
            AAFx_InitStatus      = NORMAL_FINISHED_INITIALIZATION;

            Operate_SelectTxPostion();

            aaf_step       = FINISHED_OPERATE;
            sleep_step = 8U;
        }
        else if (motor_stall_flag == MOTOR_STALL)
        {
            Motor_Off();

            aaf_step      = AAF_INITIALIZATION;
            aaf_init_step = WAIT_INITIALIZATION;

            AAF_Tx_Position      = UNKOWN_POSITION;
            AAFx_Position_Status = Unknown_Status;
            AAFx_InitStatus      = DURING_INITIALIZATION;

            motor_stall_flag = MOTOR_NORMAL;

            sleep_step = 8U;
        }
        else
        {
            /* 아직 백오프 완료 전 */
        }
    }
}

/***********************************************************************************************************************
 * Function Name: Sleep_Execute
 * Description  : 최종 Sleep 진입 전 상태를 정리하고 MCU Sleep을 호출함 (Case 5)
 * Called By    : Sleep_Start
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
static void Sleep_Execute(void)
{
    if (lin_nrst_low_flag == ON) //undervoltage
    {
        sleep_step = 9U;
        return;
    }

    if (G_Timer1ms.LinBusInactive >= LIN_BUS_CHK_TIME_4_SEC)
    {
        if ((AAF_Tx_Position == UNKOWN_POSITION) ||
            (AAFx_Position_Status == Unknown_Status) ||
            (AAFx_InitStatus == DURING_INITIALIZATION))
        {
            aaf_init_step = WAIT_INITIALIZATION;
            AAF_Tx_Position = UNKOWN_POSITION;
            AAFx_Position_Status = Unknown_Status;
            AAFx_InitStatus = DURING_INITIALIZATION;
        }

        if ((AAF_LINOut == 0x00U) &&
            ((IGN_Chk == 1U) || (IGN_Chk == 2U)) &&
            (motor_start == OFF) &&
            (AAF_Tx_Position != UNKOWN_POSITION) &&
            (AAFx_Position_Status != Unknown_Status) &&
            (AAFx_Position_Status != FlapMoving_Status) &&
            (AAFx_InitStatus == NORMAL_FINISHED_INITIALIZATION))
        {
            Position_Temporary_write();
            IGN_Chk = 2U;
        }

        MCU_Sleep();
    }
    else
    {
        /* MCU 전원 차단 전 LIN 재개 : 리셋 없이 복귀하므로 위치 미확정이면 초기화 재시작 */
        lin_bus_inactive_flag = OFF;
        sleep_step = 0U;

        G_Timer1msFlag.LinSleepModeFlag = 0U;
        G_Timer1ms.LinSleepMode = 0U;

        /* Sleep 방어 타이머 초기화 */
        G_Timer1msFlag.SleepGuardFlag = 0U;
        G_Timer1ms.SleepGuard = 0U;

        aaf_action = FLAP_STOP;
        aaf_action_complete_chk = FLAP_STOP;

        if (AAFx_InitStatus != NORMAL_FINISHED_INITIALIZATION)
        {
            aaf_step      = AAF_INITIALIZATION;
            aaf_init_step = START_INITIALIZATION;
        }
        else if (aaf_step != AAF_INITIALIZATION) 
        {
            aaf_step = AAF_WAITING; 
        }
        else
        {
            /* invalid */
        }
    }
}

static void Sleep_LowVoltageRecovery(void)
{
    /* 1. Interrupt Disable */
    DI();

    /* 2. LIN Mode를 Reset Mode로 전환 */
    RLN30.LCUC = 0x00U;

    /* 3. Transmission Stop */
    RLN30.LTRC = 0x04U;
    RLN30.LST  = 0x00U;
    RLN30.LEST = 0x00U;

    /* 4. TxD Port의 Property 변경 */
    R_PORT_ResetAltFunc(Port10, 10U, Output);
    R_PORT_ResetAltFunc(Port10, 9U, Input);

    /* 5. EN Port, TxD Port를 Low로 변경 */
    // PORT.P10 &= ~_PORT_Pn10_OUTPUT_HIGH; // TxD Low
    // PORT.P10 &= ~_PORT_Pn3_OUTPUT_HIGH;  // EN Low

    /* 6. Interrupt Enable */
    EI();

    /* 7. NRST 복귀 확인 (Lin_NrstCheck가 이미 디바운스 완료해둔 값) */
    if (lin_nrst_low_flag == OFF)
    {
        sleep_step = 8U;
    }
}

/***********************************************************************************************************************
 * Function Name: Sleep_ExternalOff
 * Description  : MCU가 슬립 모드로 진입하기 전, 연결된 외부 하드웨어(모터 드라이버, 트랜시버 등)를 끔
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
static void Sleep_ExternalOff(void)
{
    Motor_Sleep();        // 모터 드라이버 슬립 전환

   if (lin_nrst_low_flag == ON)
    {
        LinTrcv_On();       /* 저전압 : 트랜시버 유지 (INTP5 wake 및 복구 경로 확보) */
    }
    else
    {
        LinTrcv_Off();
    }

}

/***********************************************************************************************************************
 * Function Name: Sleep_PortConfig
 * Description  : 슬립 모드 중 누설 전류 방지 및 LIN Wake-up 대기를 위해 GPIO 포트 상태를 재설정함
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
static void Sleep_PortConfig(void)
{
    // 포트 기능을 GPIO 입/출력으로 리셋
    R_PORT_ResetAltFunc(Port10, 10U, Output);
    R_PORT_ResetAltFunc(Port10, 9U, Input);

    // LIN TX 핀을 Low로 설정하여 슬립 상태 유지 (Leakage 방지)
    PORT.P10 &= ~_PORT_Pn10_OUTPUT_HIGH; // MCU_LIN_Tx_Low Sleep go
}

/***********************************************************************************************************************
 * Function Name: MCU_ForceOff
 * Description  : Sleep 시퀀스가 SLEEP_GUARD_TIME 내에 끝나지 않을 때 가드 조건 무시하고 외부 전원 차단
 *                (리셋 시 AAF_Init 에서 트랜시버/LDO 재기동 → Sleep 동작 반복 가능성이 있어 차단 방식 사용)
 * Called By    : Sleep_Mode
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
static void MCU_ForceOff(void)
{
    if (G_Timer1ms.SleepGuard >= (SLEEP_GUARD_TIME + 2000U))
    {
        /* 전원 차단 시도 후 2초가 지나도 살아 있음 = LDO 미차단 : WDT 리셋으로 복귀 */
        DI();
        while (1)
        {
            /* WDT 갱신 안 함 */
        }
    }

    Motor_Off();

    power_chk = Normal_Shutdown;

    Sleep_ExternalOff();
    Sleep_PortConfig();
}

/***********************************************************************************************************************
 * Function Name: Sleep_Ready
 * Description  : LIN Sleep 전반부(준비) 단계 처리 (초기화 -> 대기 -> 명령 해석)
 * Called By    : Sleep_Mode (Step 0 ~ 2)
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
static void Sleep_Ready(void)
{
    switch (sleep_step)
    {
    case 0: 
        Sleep_Reset();  
        break;
    case 1: 
        Sleep_Delay();   
        break;
    case 2: 
        Sleep_ParsingCommand(); 
        break;
    default: 
        break;
    }
}
/***********************************************************************************************************************
 * Function Name: Sleep_Start
 * Description  : LIN Sleep 후반부(동작) 단계 처리 (구동 시작 -> 완료 확인 -> Sleep)
 * Called By    : Sleep_Mode (Step 3 ~ 5)
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
static void Sleep_Start(void)
{
    switch (sleep_step)
    {
    case 3:
        Sleep_StartMotor();
        break;

    case 4:
        Sleep_CheckCompletion();
        break;

    case 5:
        Sleep_StallDelay();
        break;

    case 6:
        Sleep_StallOpen();
        break;

    case 7:
        Sleep_StallStop();
        break;

    case 8:
        Sleep_Execute();
        break;
    case 9:
        Sleep_LowVoltageRecovery();
        break;

    default:
        break;
    }
}
/***********************************************************************************************************************
 * Function Name: Sleep_Mode
 * Description  : LIN Sleep 모드 진입 및 Wakeup 동작 시퀀스 전체 제어
 * Called By    : Main Loop
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
void Sleep_Mode(void)
{
    /* 방어 : Sleep 시퀀스 최대 시간 초과 (저전압 복구 대기 step 9 제외) */
    G_Timer1msFlag.SleepGuardFlag = 1U;

    if ((G_Timer1ms.SleepGuard >= SLEEP_GUARD_TIME) && (sleep_step != 9U) && (lin_nrst_low_flag == OFF))
    {
        MCU_ForceOff();
        return;
    }

    // Step 0 ~ 2: 준비 및 명령 수신 단계
    if (sleep_step <= 2U)
    {
        Sleep_Ready();
    }
    // Step 3 ~ 5: 모터 구동 및 Sleep 단계
    else
    {
        Sleep_Start();
    }
}

/* =========================================================================================
 * MCU Sleep Mode Management Functions
 * ========================================================================================= */

/***********************************************************************************************************************
 * Function Name: MCU_Sleep
 * Description  : 시스템 종료 절차를 수행하고 MCU를 저전력 모드(Deep Stop)로 전환하는 메인 함수
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
void MCU_Sleep(void)
{
    if (power_chk == Normal_Shutdown)
    {
        return;
    }

    if (lin_nrst_low_flag == ON)
    {
        sleep_step = 9U;      /* 저전압 가드 한번 더*/
        return;
    }

    // 1. 종료 상태 플래그 설정
    power_chk = Normal_Shutdown;
    First_Powerchk = 1U;

    // 2. 필요 시 플래시 메모리에 데이터 저장
    //    - 2 : 이번 사이클 초기화 정상 완료 → 정상 값 저장
    //    - 1 : FDL 읽음 + 초기화 미완료(실패/FS) → 미확정 상태 저장 → 다음 IG ON 재초기화
    if ((step_check_flag == 2U) || (step_check_flag == 1U))
    {
        FDL_Write();
    }

    // 3. 외부 하드웨어 전원 차단
    Sleep_ExternalOff();

    // 4. 슬립 대비 포트 설정 (누설 전류 방지)
    Sleep_PortConfig();
}



/***********************************************************************************************************************
 * Function Name: Sleep_Wakeup
 * Description  : LIN Sleep 상태에서 LIN 프레임이 다시 수신되었을 때 Sleep 상태를 해제함
 *                - LIN Bus Inactive flag 해제
 *                - Sleep 상태머신 초기화
 *                - Sleep 관련 타이머 초기화
 *                - Sleep 중 모터가 구동 중이었다면 모터 정지
 * Called By    : Lin_ReceiveComplete_Interrupt
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
void Sleep_Wakeup(void)
{
    if (lin_bus_inactive_flag == ON)
    {
        /* LIN 프레임이 다시 들어왔으므로 Sleep 상태 해제 */
        lin_bus_inactive_flag = OFF;

        /* LIN Sleep 상태머신 초기화 */
        sleep_step = 0U;

        power_chk = Shutdown_Check;
        
        /* LIN Sleep 대기 타이머 초기화 */
        G_Timer1msFlag.LinSleepModeFlag = 0U;
        G_Timer1ms.LinSleepMode = 0U;

        /* Sleep 방어 타이머 초기화 */
        G_Timer1msFlag.SleepGuardFlag = 0U;
        G_Timer1ms.SleepGuard = 0U;

        /* Sleep 중 모터 구동 중일 수 있으므로 안전하게 정지 */
        Motor_Off();

        /* Init fail check 타이머 초기화 */
        G_Timer1msFlag.InitFailCheckFlag = 0U;
        G_Timer1ms.InitFailCheck = 0U;

        /* 수정된 부분: 초기화가 완전히 끝나지 않았다면 무조건 초기화 루프로 진입 */
        if (AAFx_InitStatus != NORMAL_FINISHED_INITIALIZATION)
        {
            aaf_step = AAF_INITIALIZATION;
            aaf_init_step = START_INITIALIZATION; // 0U
        }
        /* Sleep sequence 중 이동 중이었다면 일반 동작 대기로 복귀 */
        else if (AAFx_Position_Status == FlapMoving_Status)
        {
            aaf_step = AAF_OPERATE;
        }
        else
        {
            if (aaf_step != AAF_INITIALIZATION) 
            {
                aaf_step = AAF_WAITING; 
            }
        }
    }
}





