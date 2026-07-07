#include "Lin_Sleep.h"
#include "Service.h"

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
    motor_step_value = STEP_TIME_1000RPM;
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
    
    // Case 0에만 있는 추가 초기화
    G_Timer1msFlag.InitFailCheckFlag = 0U;
    G_Timer1ms.InitFailCheck = 0U;

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
 * Description  : LIN 통신으로 수신된 Wakeup 명령을 해석하여 동작(Open/Close)을 결정함 (Case 2)
 * Called By    : LinSleep_Cycle1
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
/***********************************************************************************************************************
 * Function Name: LinSleep_ParsingCommand
 * Description  : LIN Sleep 진입 전 마지막 수신 명령을 해석하여 Sleep 전 최종 구동 방향을 결정함
 *                - AAF_LINOut == 0 : 정상 종료 조건, 마지막 마스터 명령을 수행한 후 Sleep 진입
 *                - AAF_LINOut == 1 : 비정상 종료/LIN 단선 조건, OPEN 방향으로 이동 후 Sleep 진입
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
            if ((AAF_Tx_Position == CLOSE) &&
                (AAFx_Position_Status == Close_Status) &&
                (aaf_action_complete_chk == FLAP_STOP))
            {
                lin_sleep_step = 8U;
            }
            else
            {
                Drv8889_Wakeup();

                aaf_action = CLOSE;
                lin_sleep_step = 3U;
            }
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
 * Function Name: LinSleep_StartMotor
 * Description  : 결정된 Action(OPEN/CLOSE)에 따라 모터 구동을 시작함 (Case 3)
 * Called By    : LinSleep_Cycle2
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
static void LinSleep_StartMotor(void)
{
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
    target_pos = step_position_open;

    if (aaf_action == OPEN_1ST)
    {
        target_pos = OPEN_1ST_POSITION;
    }
    else if (aaf_action == OPEN_2ND)
    {
        target_pos = OPEN_2ND_POSITION;
    }
    else
    {
        // OPEN 또는 CLOSE인 경우 별도 target_pos 변경 없음
    }

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

        // close stopper 후 800ms 대기 단계로 이동
        // 다음 단계에서 OPEN 방향으로 약 5도 복귀함
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

        // Sleep 전 CLOSE 도달 완료 상태이므로 정상 초기화 완료 상태로 보고
        AAFx_InitStatus = NORMAL_FINISHED_INITIALIZATION;

        Operate_SelectTxPostion();

        aaf_step = FINISHED_OPERATE;

        // 최종 Sleep 단계로 이동
        lin_sleep_step = 8U;
    }

    // 조건 4: 목표 위치 도달 전 스톨 발생
    // 목표 위치 도달 조건을 만족하지 못한 상태에서 스톨이 발생하면
    // 현재 위치를 신뢰할 수 없으므로 UNKNOWN / DURING_INITIALIZATION 상태로 저장함.
    else if (motor_stall_flag == MOTOR_STALL)
    {
        LinSleep_StopMotorAndReset();

        aaf_step = AAF_INITIALIZATION;
        aaf_init_step = WAIT_INITIALIZATION;

        AAF_Tx_Position = UNKOWN_POSITION;
        AAFx_Position_Status = Unknown_Status;
        AAFx_InitStatus = DURING_INITIALIZATION;

        motor_stall_flag = MOTOR_NORMAL;

        // 최종 Sleep 단계로 이동
        lin_sleep_step = 8U;
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

        /* OPEN 방향 약 5도 복귀 구동 시작 단계로 이동 */
        lin_sleep_step = 6U;
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

        /*
     * Soft Stop 1단계:
     * CLOSE stopper 후 OPEN 방향 약 5도 복귀 구간은 짧은 거리이므로
     * 기존 속도보다 느린 속도로 복귀한다.
     * 만약 motor_step_value = STEP_TIME_SLEEP_BACKOFF;를 넣었는데도 속도가 안 느려지면, Motor_SoftStart()나 Motor_Action() 쪽에서 motor_step_value를 다시 덮어쓰고 있을 가능성
     * 0527 우상민
     */
    //motor_step_value = STEP_TIME_SLEEP_BACKOFF;

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
//0526 우상민
static void LinSleep_Stall_Stop(void)
{
    /* OPEN 방향으로 약 5도 복귀 완료
     * CLOSE 위치에서 limit_step_position만큼 OPEN 방향으로 빠지면 완료로 판단
     */

    unsigned int sleep_backoff_step;

    sleep_backoff_step = step_position_close - (limit_step_position / SLEEP_BACKOFF_DIVIDER);    

    if (step_position <= (sleep_backoff_step))
    {
        LinSleep_StopMotorAndReset();
        
        /* 실제 위치는 stopper에서 약간 빠졌지만, Sleep 전 최종 상태는 CLOSE로 보고 */
        AAF_Tx_Position = CLOSE;
        AAFx_Position_Status = Close_Status;
        AAFx_InitStatus = NORMAL_FINISHED_INITIALIZATION;

        Operate_SelectTxPostion();

        aaf_step = FINISHED_OPERATE;

        /* 최종 Sleep 단계로 이동 */
        lin_sleep_step = 8U;
    }
    /* OPEN 복귀 중 다시 스톨이 발생하면 위치 신뢰 불가 처리 */
    else if (motor_stall_flag == MOTOR_STALL)
    {
        LinSleep_StopMotorAndReset();

        aaf_step = AAF_INITIALIZATION;
        aaf_init_step = WAIT_INITIALIZATION;

        AAF_Tx_Position = UNKOWN_POSITION;
        AAFx_Position_Status = Unknown_Status;
        AAFx_InitStatus = DURING_INITIALIZATION;

        motor_stall_flag = MOTOR_NORMAL;

        /* 최종 Sleep 단계로 이동 */
        lin_sleep_step = 8U;
    }
    else
    {
        /* 아직 약 5도 복귀 완료 전이면 계속 OPEN 방향 구동 유지 */
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

        aaf_step = AAF_WAITING;
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

    default:
        break;
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

    // 5. 내부 주변장치 클럭 정지
    McuSleep_InternalModuleStop();

    // 6. Deep Stop 모드 진입 (Wake-up 이벤트 발생 전까지 정지)
    McuSleep_DeepStop();
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
        motor_step_value = STEP_TIME_1000RPM;

        /* Sleep sequence 중 이동 중이었다면 일반 동작 대기로 복귀 */
        if (AAFx_Position_Status == FlapMoving_Status)
        {
            aaf_step = AAF_OPERATE;
        }
        else
        {
            aaf_step = AAF_WAITING;
        }
    }
}





