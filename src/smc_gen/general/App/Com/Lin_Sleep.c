#include "Lin_Sleep.h"
#include "Service.h"

static uint8_t Sleep_Stall = OFF;

/***********************************************************************************************************************
 * Function Name: LinSleep_StopMotorAndReset
 * Description  : 모터 구동 정지 및 제어 변수 리셋 (Case 0, 4 공통)
 * Called By    : LinSleep_Reset, LinSleep_CheckCompletion
 ***********************************************************************************************************************/
static void LinSleep_StopMotorAndReset(void)
{
    Drv8889_Off2();
    motor_start = OFF;
    G_Timer1msFlag.StallTimeFlag = 0U;
    G_Timer1ms.StallTime = 0U;
    softstart_complete = OFF;

}

static uint8_t LinSleep_AbortOnFault(void)
{
    if ((AAFx_Motor_Fault   == 0U)       &&
        (AAFx_Circuit_Short == NO_ERROR) &&
        (AAFx_Circuit_Open  == NO_ERROR))
    {
        return 0U;
    }

    LinSleep_StopMotorAndReset();

    aaf_step      = AAF_INITIALIZATION;
    aaf_init_step = WAIT_INITIALIZATION;

    AAF_Tx_Position      = UNKOWN_POSITION;
    AAFx_Position_Status = Unknown_Status;
    AAFx_InitStatus      = DURING_INITIALIZATION;

    motor_stall_flag = MOTOR_NORMAL;

    lin_sleep_step = 8U;   
    return 1U;
}

/***********************************************************************************************************************
 * Function Name: LinSleep_Reset
 * Description  : Lin Sleep 모드 초기 진입 시 변수 초기화 수행 (Case 0)
 * Called By    : LinSleep_Cycle1
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
static void LinSleep_Reset(void)
{
    LinSleep_StopMotorAndReset();

    G_Timer1msFlag.InitFailCheckFlag = 0U;
    G_Timer1ms.InitFailCheck = 0U;

    Sleep_Stall = OFF;

    lin_sleep_step = 1U;
}

/***********************************************************************************************************************
 * Function Name: LinSleep_Delay
 * Description  : 50ms 동안 대기 후 다음 단계로 이동 (Case 1)
 * Called By    : LinSleep_Cycle1
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
static void LinSleep_Delay(void)
{
    G_Timer1msFlag.LinSleepModeFlag = 1U;

    if (G_Timer1ms.LinSleepMode >= 50U)
    {
        G_Timer1msFlag.LinSleepModeFlag = 0U;
        G_Timer1ms.LinSleepMode = 0U;
        lin_sleep_step = 2U;
    }
}

/***********************************************************************************************************************
 * Function Name: LinSleep_ParsingCommand
 * Description  : LIN Sleep 진입 전 마지막 수신 명령을 해석하여 Sleep 전 최종 구동 방향을 결정함
 *                - AAF_LINOut == 0 : 정상 종료 조건, 마지막 마스터 명령을 수행한 후 Sleep 진입
 *                - AAF_LINOut == 1 : 비정상 종료/LIN 단선 조건, OPEN 방향으로 이동 후 Sleep 진입 (case 2)
 * Called By    : LinSleep_Cycle1
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
static void LinSleep_ParsingCommand(void)
{
    if (AAF_LINOut == 0x00U)
    {
        if (IGN_Chk == 0U)
        {
            lin_sleep_step = 8U;
        }
        else if ((lin_aaf_command == OPEN) ||
                 (lin_aaf_command == OPEN_1ST) ||
                 (lin_aaf_command == OPEN_2ND))
        {
            Drv8889_Wakeup();

            aaf_action = lin_aaf_command;
            lin_sleep_step = 3U;
        }
        else if (lin_aaf_command == CLOSE)
        {
            Drv8889_Wakeup();
            
            if (fail_safety_step != 0U)
            {
                aaf_action = OPEN;
            } 
            else
            {
                aaf_action = CLOSE;
            }

            lin_sleep_step = 3U;
        }
        else
        {
            lin_sleep_step = 8U;
        }
    }
    else if (AAF_LINOut == 0x01U)
    {
        Drv8889_Wakeup();

        aaf_action = OPEN;
        lin_sleep_step = 3U;
    }
    else
    {
        lin_sleep_step = 8U;
    }
}


/***********************************************************************************************************************
 * Function Name: LinSleep_StartMotor
 * Description  : 결정된 Action(OPEN/CLOSE)에 따라 모터 구동을 시작함 (Case 3)
 * Called By    : LinSleep_Cycle2
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
static void LinSleep_StartMotor(void)
{
    if (LinSleep_AbortOnFault() == 1U) { return; }

    if ((aaf_action == OPEN) || (aaf_action == OPEN_1ST) || (aaf_action == OPEN_2ND))
    {
        Motor_Open2();
        Drv8889_On2(); 
        motor_start = ON;
        motor_stall_flag = MOTOR_NORMAL;
        G_Timer1ms.StallTime = 0U;
        TRQ_COUNT = MOTOR_STALL_CHK_NORMAL_VALUE;
        G_Timer1ms.Spi = 0U;
        
        lin_sleep_step = 4U;
    }
    else if (aaf_action == CLOSE)
    {
        Motor_Close2();
        Drv8889_On2(); 
        motor_start = ON;
        motor_stall_flag = MOTOR_NORMAL;
        G_Timer1ms.StallTime = 0U;
        TRQ_COUNT = MOTOR_STALL_CHK_NORMAL_VALUE;
        G_Timer1ms.Spi = 0U;
        
        lin_sleep_step = 4U;
    }
    else
    {
        lin_sleep_step = 8U;
    }
}

/***********************************************************************************************************************
 * Function Name: LinSleep_CheckCompletion
 * Description  : 모터 구동 중 목표 위치 도달 또는 스톨 발생 여부를 확인하고 정지함 (Case 4)
 * Called By    : LinSleep_Cycle2
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
static void LinSleep_CheckCompletion(void)
{
    unsigned int target_pos;

    // 기본 OPEN 목표 위치는 FULL OPEN 기준 위치
    if (aaf_action == OPEN)      { target_pos = step_position_open; }
    else if (aaf_action == OPEN_1ST) { target_pos = open_1st_step_position; }
    else if (aaf_action == OPEN_2ND) { target_pos = open_2nd_step_position; }
    else { target_pos = step_position_open; }

    if (LinSleep_AbortOnFault() == 1U) { return; }

    if (((aaf_action == OPEN) ||
         (aaf_action == OPEN_1ST) ||
         (aaf_action == OPEN_2ND)) &&
        (step_position <= (target_pos + limit_step_position)))
    {
        LinSleep_StopMotorAndReset();

        // 마스터에게 현재 위치 상태를 보고하기 위한 값 설정
        AAF_Tx_Position = aaf_action;
        AAFx_Position_Status = Open_Status;
        AAFx_InitStatus = NORMAL_FINISHED_INITIALIZATION;

        // LIN Response 위치값 선택/갱신
        Operate_SelectTxPostion();

        aaf_step = FINISHED_OPERATE;

        // 최종 Sleep 단계로 이동
        lin_sleep_step = 8U;
    }

    else if ((aaf_action == CLOSE) &&
             (motor_stall_flag == MOTOR_STALL) &&
             (step_position >= (step_position_close - limit_step_position)) &&
             (AAFx_Type == EXTERNAL_TYPE))
    {
        LinSleep_StopMotorAndReset();

        // close stopper에 도달했다고 판단했으므로 현재 위치를 close 기준 위치로 보정
        step_position = step_position_close;

        // stall 상태 초기화
        TRQ_COUNT = MOTOR_STALL_CHK_NORMAL_VALUE;
        motor_stall_flag = MOTOR_NORMAL;

        Sleep_Stall    = OFF;

        lin_sleep_step = 5U;
    }

    // 조건 3: INTERNAL TYPE CLOSE 목표 위치 도달
    // Internal Type은 stopper stall을 기다리지 않고 close 위치 근처 도달로 완료 처리함.
    else if ((aaf_action == CLOSE) &&
             (step_position >= (step_position_close - limit_step_position)) &&
             (AAFx_Type == INTERNAL_TYPE))
    {
        LinSleep_StopMotorAndReset();

        AAF_Tx_Position = CLOSE;
        AAFx_Position_Status = Close_Status;
        AAFx_InitStatus = NORMAL_FINISHED_INITIALIZATION;

        Operate_SelectTxPostion();

        aaf_step = FINISHED_OPERATE;

        // 최종 Sleep 단계로 이동
        lin_sleep_step = 8U;
    }

    // 조건 4: 목표 위치 도달 전 스톨 발생
    else if (motor_stall_flag == MOTOR_STALL)
    {
        LinSleep_StopMotorAndReset();

        motor_stall_flag = MOTOR_NORMAL;

        aaf_step = AAF_INITIALIZATION;
        aaf_init_step = WAIT_INITIALIZATION;

        AAF_Tx_Position = UNKOWN_POSITION;
        AAFx_Position_Status = Unknown_Status;
        AAFx_InitStatus = DURING_INITIALIZATION;

        Sleep_Stall    = ON;
        // 최종 Sleep 단계로 이동
        lin_sleep_step = 5U;
    }
    else
    {
        // 아직 목표 위치에 도달하지 않았고 스톨도 아니면 계속 구동 상태 유지
    }
}

/***********************************************************************************************************************
 * Function Name: LinSleep_Stall_Delay
 * Description  : External Type에서 CLOSE stopper 도달 후 OPEN 방향 복귀 전 800ms 대기
 *                기존 EV 코드에 별도 LinSleepStall 타이머가 없으므로 LinSleepMode 타이머를 재사용함.
 * Called By    : LinSleep_Cycle2
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
static void LinSleep_Stall_Delay(void)
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
            lin_sleep_step = 8U;
        }
        else
        {
            lin_sleep_step = 6U;
        }
    }
}

/***********************************************************************************************************************
 * Function Name: LinSleep_Stall_Open
 * Description  : CLOSE stopper 도달 후 OPEN 방향으로 약 5도 복귀하기 위해 모터 구동 시작
 *                - External Type에서 stopper 압착 상태를 풀기 위한 back-off 동작
 * Called By    : LinSleep_Cycle2
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
static void LinSleep_Stall_Open(void)
{
    /* OPEN 방향 설정 */
    Motor_Open2();

    /* 모터 드라이버 ON */
    Drv8889_On2();

    /* 모터 구동 시작 */
    motor_start = ON;

    /* 스톨 상태 및 타이머 초기화 */
    motor_stall_flag = MOTOR_NORMAL;
    G_Timer1ms.StallTime = 0U;
    TRQ_COUNT = MOTOR_STALL_CHK_NORMAL_VALUE;
    G_Timer1ms.Spi = 0U;

    /* OPEN 방향 복귀 완료 여부 확인 단계로 이동 */
    lin_sleep_step = 7U;
}

/***********************************************************************************************************************
 * Function Name: LinSleep_Stall_Stop
 * Description  : CLOSE stopper 후 OPEN 방향으로 약 5도 복귀 완료 여부를 확인하고 정지
 *                - limit_step_position이 약 5도에 해당하는 step 값으로 사용됨
 *                - 복귀 완료 후 실제 기구는 stopper에서 살짝 빠지지만, 상태는 CLOSE로 보고함
 * Called By    : LinSleep_Cycle2
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
static void LinSleep_Stall_Stop(void)
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
            LinSleep_StopMotorAndReset();

            motor_stall_flag = MOTOR_NORMAL;

            Sleep_Stall    = OFF;
            lin_sleep_step = 8U;
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
            LinSleep_StopMotorAndReset();

            AAF_Tx_Position      = CLOSE;
            AAFx_Position_Status = Close_Status;
            AAFx_InitStatus      = NORMAL_FINISHED_INITIALIZATION;

            Operate_SelectTxPostion();

            aaf_step       = FINISHED_OPERATE;
            lin_sleep_step = 8U;
        }
        else if (motor_stall_flag == MOTOR_STALL)
        {
            LinSleep_StopMotorAndReset();

            aaf_step      = AAF_INITIALIZATION;
            aaf_init_step = WAIT_INITIALIZATION;

            AAF_Tx_Position      = UNKOWN_POSITION;
            AAFx_Position_Status = Unknown_Status;
            AAFx_InitStatus      = DURING_INITIALIZATION;

            motor_stall_flag = MOTOR_NORMAL;

            lin_sleep_step = 8U;
        }
        else
        {
            /* 아직 백오프 완료 전 */
        }
    }
}

/***********************************************************************************************************************
 * Function Name: LinSleep_Final
 * Description  : 최종 Sleep 진입 전 상태를 정리하고 MCU Sleep을 호출함 (Case 5)
 * Called By    : LinSleep_Cycle2
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
static void LinSleep_Final(void)
{
    if (lin_nrst_low_flag == ON) //undervoltage
    {
        lin_sleep_step = 9U;
        return;
    }

    if ((AAF_Tx_Position == UNKOWN_POSITION) ||
        (AAFx_Position_Status == Unknown_Status) ||
        (AAFx_InitStatus == DURING_INITIALIZATION))
    {
        aaf_init_step = WAIT_INITIALIZATION;
        AAF_Tx_Position = UNKOWN_POSITION;
        AAFx_Position_Status = Unknown_Status;
        AAFx_InitStatus = DURING_INITIALIZATION;
    }

    if (G_Timer1ms.LinBusInactive >= LIN_BUS_CHK_TIME_4_SEC)
    {
        if ((AAF_LINOut == 0x00U) &&
            (IGN_Chk == 1U) &&
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
        lin_bus_inactive_flag = OFF;
        lin_sleep_step = 0U;

        G_Timer1msFlag.LinSleepModeFlag = 0U;
        G_Timer1ms.LinSleepMode = 0U;

        aaf_action = FLAP_STOP;
        aaf_action_complete_chk = FLAP_STOP;

        if (aaf_step != AAF_INITIALIZATION) 
        {
            aaf_step = AAF_WAITING; 
        }
    }
}

static void LinSleep_UnderVoltageRecovery(void)
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
    PORT.P10 &= ~_PORT_Pn10_OUTPUT_HIGH; // TxD Low
    PORT.P10 &= ~_PORT_Pn3_OUTPUT_HIGH;  // EN Low

    /* 6. Interrupt Enable */
    EI();

    /* 7. NRST 복귀 확인 (Lin_NrstCheck가 이미 디바운스 완료해둔 값) */
    if (lin_nrst_low_flag == OFF)
    {
        lin_sleep_step = 8U;
    }
}

/***********************************************************************************************************************
 * Function Name: McuSleep_ExternalOff
 * Description  : MCU가 슬립 모드로 진입하기 전, 연결된 외부 하드웨어(모터 드라이버, 트랜시버 등)를 끔
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
static void McuSleep_ExternalOff(void)
{
    Drv8889_Sleep();        // 모터 드라이버 슬립 전환
    LinTrcv_Off();  // LIN 트랜시버 전원 차단
    Drv8889_ScsActive();   // SPI 통신 핀 활성화
}

/***********************************************************************************************************************
 * Function Name: McuSleep_PortConfig
 * Description  : 슬립 모드 중 누설 전류 방지 및 LIN Wake-up 대기를 위해 GPIO 포트 상태를 재설정함
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
static void McuSleep_PortConfig(void)
{
    // 포트 기능을 GPIO 입/출력으로 리셋
    R_PORT_ResetAltFunc(Port10, 10U, Output);
    R_PORT_ResetAltFunc(Port10, 9U, Input);

    // LIN TX 핀을 Low로 설정하여 슬립 상태 유지 (Leakage 방지)
    PORT.P10 &= ~_PORT_Pn10_OUTPUT_HIGH; // MCU_LIN_Tx_Low Sleep go
}

/***********************************************************************************************************************
 * Function Name: McuSleep_InternalModuleStop
 * Description  : 전력 소모를 줄이기 위해 MCU 내부 주변장치(ADC, 타이머, 통신 모듈)의 클럭을 정지함
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
static void McuSleep_InternalModuleStop(void)
{
    R_Config_INTC_Create();         // 인터럽트 컨트롤러 재설정 (Wake-up 준비)
    R_Config_INTC_INTP5_Start(); 

    R_Config_CSIH0_Stop();          // SPI 모듈 정지
    R_Config_ADCA0_Halt();          // ADC 모듈 정지
    R_Config_TAUD0_13_Stop();       // 타이머 정지
    R_Config_TAUD0_3_Stop();        // 타이머 정지

    G_Timer1msFlag.SpiFlag = 0U;          // 관련 플래그 초기화
    G_Timer1ms.Spi = 0U;
}

/***********************************************************************************************************************
 * Function Name: McuSleep_DeepStop
 * Description  : 클럭 생성기를 슬립 모드용으로 설정하고, 최종적으로 Deep Stop Mode로 진입함
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
static void McuSleep_DeepStop(void)
{
    R_CGC_Create_sleepmode();                   // 클럭 설정 변경

    R_Config_STBC_Prepare_Deep_Stop_Mode();     // 대기 모드 진입 준비 레지스터 설정
    R_Config_STBC_Start_Deep_Stop_Mode();       // [진입점] 여기서 MCU 동작 멈춤
}


/***********************************************************************************************************************
 * Function Name: LinSleep_Cycle1
 * Description  : LIN Sleep 전반부(준비) 단계 처리 (초기화 -> 대기 -> 명령 해석)
 * Called By    : Lin_Sleep (Step 0 ~ 2)
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
static void LinSleep_Cycle1(void)
{
    switch (lin_sleep_step)
    {
    case 0: 
        LinSleep_Reset();  
        break;
    case 1: 
        LinSleep_Delay();   
        break;
    case 2: 
        LinSleep_ParsingCommand(); 
        break;
    default: 
        break;
    }
}
/***********************************************************************************************************************
 * Function Name: LinSleep_Cycle2
 * Description  : LIN Sleep 후반부(동작) 단계 처리 (구동 시작 -> 완료 확인 -> Sleep)
 * Called By    : Lin_Sleep (Step 3 ~ 5)
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
static void LinSleep_Cycle2(void)
{
    switch (lin_sleep_step)
    {
    case 3:
        LinSleep_StartMotor();
        break;

    case 4:
        LinSleep_CheckCompletion();
        break;

    case 5:
        LinSleep_Stall_Delay();
        break;

    case 6:
        LinSleep_Stall_Open();
        break;

    case 7:
        LinSleep_Stall_Stop();
        break;

    case 8:
        LinSleep_Final();
        break;
    case 9:
        LinSleep_UnderVoltageRecovery();
        break;

    default:
        break;
    }
}
/***********************************************************************************************************************
 * Function Name: Lin_Sleep
 * Description  : LIN Sleep 모드 진입 및 Wakeup 동작 시퀀스 전체 제어
 * Called By    : Main Loop
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
void Lin_Sleep(void)
{
    // Step 0 ~ 2: 준비 및 명령 수신 단계
    if (lin_sleep_step <= 2U)
    {
        LinSleep_Cycle1();
    }
    // Step 3 ~ 5: 모터 구동 및 Sleep 단계
    else
    {
        LinSleep_Cycle2();
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
    
    // 1. 종료 상태 플래그 설정
    power_chk = Normal_Shutdown;
    First_Powerchk = 1U;

    // 2. 필요 시 플래시 메모리에 데이터 저장
    if (step_check_flag == 2U)
    {
        FDL_Write();
    }

    // 3. 외부 하드웨어 전원 차단
    McuSleep_ExternalOff();

    // 4. 슬립 대비 포트 설정 (누설 전류 방지)
    McuSleep_PortConfig();

    // // 5. 내부 주변장치 클럭 정지
    // McuSleep_InternalModuleStop();

    // // 6. Deep Stop 모드 진입 (Wake-up 이벤트 발생 전까지 정지)
    // McuSleep_DeepStop();
    
}



/***********************************************************************************************************************
 * Function Name: Lin_WakeupFromSleep
 * Description  : LIN Sleep 상태에서 LIN 프레임이 다시 수신되었을 때 Sleep 상태를 해제함
 *                - LIN Bus Inactive flag 해제
 *                - Sleep 상태머신 초기화
 *                - Sleep 관련 타이머 초기화
 *                - Sleep 중 모터가 구동 중이었다면 모터 정지
 * Called By    : Lin_ReceiveComplete_Interrupt
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
void Lin_WakeupFromSleep(void)
{
    if (lin_bus_inactive_flag == ON)
    {
        /* LIN 프레임이 다시 들어왔으므로 Sleep 상태 해제 */
        lin_bus_inactive_flag = OFF;

        /* LIN Sleep 상태머신 초기화 */
        lin_sleep_step = 0U;

        power_chk = Shutdown_Check;
        
        /* LIN Sleep 대기 타이머 초기화 */
        G_Timer1msFlag.LinSleepModeFlag = 0U;
        G_Timer1ms.LinSleepMode = 0U;

        /* Sleep 중 모터 구동 중일 수 있으므로 안전하게 정지 */
        Drv8889_Off2();
        motor_start = OFF;

        /* Stall 관련 타이머 초기화 */
        G_Timer1msFlag.StallTimeFlag = 0U;
        G_Timer1ms.StallTime = 0U;

        /* Init fail check 타이머 초기화 */
        G_Timer1msFlag.InitFailCheckFlag = 0U;
        G_Timer1ms.InitFailCheck = 0U;

        /* Soft start 및 모터 속도 초기화 */
        softstart_complete = OFF;

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





