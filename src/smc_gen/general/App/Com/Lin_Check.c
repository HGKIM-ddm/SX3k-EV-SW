#include "Lin_Check.h"
#include "Service.h"
#include "HighSpeed_Mode.h"

#ifdef ENABLE_TORQUE_TEST
/***********************************************************************************************************************
 * Function Name: Lin_ParseTorqueTestMode
 * Description  : 토크 테스트 및 초기화 관련 플래그 파싱 및 즉각 Re_Init 검사 수행
 ***********************************************************************************************************************/
static void Lin_ParseTorqueTestMode(void)
{
    AAF_Init_Flag = (unsigned int)((ID_chk_rxdata[1U] & 0x80U) >> 7U);
    AAF_Flap_Fixation_Test_Mode  = (unsigned int)((ID_chk_rxdata[2U] & 0x80U) >> 7U);
    if (((ID_chk_rxdata[4U] == 0x3BU) ||
        (ID_chk_rxdata[4U] == 0x38U)) &&
        (ID_chk_rxdata[5U] == 0x0FU))
    {
        /* Torque Test OPEN / CLOSE */
        AAF_Maximum_Torque_Test_Mode = ON;
    }
    else if ((ID_chk_rxdata[4U] == 0x3FU) &&
            (ID_chk_rxdata[5U] == 0x0FU))
    {
        /* Torque Test STOP → Torque Test 종료 */
        AAF_Maximum_Torque_Test_Mode = OFF;
    }
    Re_Init_check = (unsigned int)((ID_chk_rxdata[4U] & 0x80U) >> 7U);

    if (Re_Init_check == 0x01U)
    {
        Re_Init_check_flag = 1U;
    }
    else
    {
        Re_Init_check_flag = 0U;
    }

    if ((Re_Init_check_flag == 1U) && (aaf_step == AAF_WAITING) && (Re_Init_check_prev == 0U))
    {
        Re_Init();
    }
    Re_Init_check_prev = Re_Init_check;
}

/***********************************************************************************************************************
 * Function Name: Lin_ExecuteTorqueTestMode
 * Description  : 파싱된 플래그를 기반으로 토크, 고정 테스트 모드 토글 동작 및 초기화 수행
 ***********************************************************************************************************************/
static void Lin_ExecuteTorqueTestMode(void)
{
    if ((AAF_Init_Flag_tog == OFF) && (AAF_Init_Flag == ON))
    {
        if ((AAF1_TargetPosition == 0x7FU) || (AAF2_TargetPosition == 0x7FU) || (AAF3_TargetPosition == 0x7FU))
        {
            wake_up_motor_range_init_chk = 0U;
            evrdy_on_flag = OFF;
            Re_Init();
        }
        AAF_Init_Flag_tog = ON;
    }
    else if ((AAF_Init_Flag_tog == ON) && (AAF_Init_Flag == OFF))
    {
        AAF_Init_Flag_tog = OFF;
    }
    else
    {
        // Waiting
    }

    if ((AAF_Flap_Fixation_Test_Mode_tog == OFF) && (AAF_Flap_Fixation_Test_Mode == ON))
    {
        AAF_Flap_Fixation_Test_Mode_tog = ON;
    }
    else if ((AAF_Flap_Fixation_Test_Mode_tog == ON) && (AAF_Flap_Fixation_Test_Mode == OFF))
    {
        wake_up_motor_range_init_chk = 0U;
        evrdy_on_flag = OFF;
        Re_Init();
        AAF_Flap_Fixation_Test_Mode_tog = OFF;
    }
    else
    {
        // Waiting
    }

    if ((AAF_Maximum_Torque_Test_Mode_tog == OFF) && (AAF_Maximum_Torque_Test_Mode == ON))
    {
        AAF_Maximum_Torque_Test_Mode_tog = ON;
    }
    else if ((AAF_Maximum_Torque_Test_Mode_tog == ON) &&
            (AAF_Maximum_Torque_Test_Mode == OFF))
    {
        Motor_Off();
        motor_start = OFF;

        wake_up_motor_range_init_chk = 0U;
        evrdy_on_flag = OFF;

        Re_Init();

        AAF_Maximum_Torque_Test_Mode_tog = OFF;
    }
    else
    {
        // Waiting
    }
}
#endif

static void Lin_SwCheck(void)
{
    if (Slave_RxSwData1[0U] == 0x26u)
    {
        if ((Slave_RxSwData1[1U] == 0x06U) && (Slave_RxSwData1[2U] == 0xB2U) && (Slave_RxSwData1[3U] == 0x01U) && (Slave_RxSwData1[4U] == 0x0Au) && (Slave_RxSwData1[5U] == 0x00U) && (Slave_RxSwData1[6U] == 0x0Bu) && (Slave_RxSwData1[7U] == 0x00U))
        {
            SW_Chk = 1U; // SW VER
        }
        else
        {
            SW_Chk = 3U;
        }
    }
    else
    {
        SW_Chk = 0U;
    }
}

static void Lin_SwCheckResponse(void)
{
    if (SW_Chk == 1U)
    {
        Slave_SwData[0] = (uint8_t)(0x26u);
        Slave_SwData[1] = (uint8_t)(0x05u);
        Slave_SwData[2] = (uint8_t)(0xF2u);
        Slave_SwData[3] = (uint8_t)(0x02u); // SX3K
        Slave_SwData[4] = (uint8_t)(0x31u); // EV, STD
        Slave_SwData[5] = (uint8_t)(FW_VERSION);
        Slave_SwData[6] = (uint8_t)(0x66u);
        Slave_SwData[7] = (uint8_t)(0xFFu);
    }
    else if (SW_Chk == 3U)
    {
        Slave_SwData[0] = (uint8_t)(0x26u);
        Slave_SwData[1] = (uint8_t)(0x03u);
        Slave_SwData[2] = (uint8_t)(0x7Fu);
        Slave_SwData[3] = (uint8_t)(0xB2u);
        Slave_SwData[4] = (uint8_t)(0x12u);
        Slave_SwData[5] = (uint8_t)(0xFFu);
        Slave_SwData[6] = (uint8_t)(0xFFu);
        Slave_SwData[7] = (uint8_t)(0xFFu);
    }
    else
    {
        // invalid
    }
}

//0609 우상민 실제 동작 명령인 effective_command 기준으로 step_start_flag를 판단
static void Lin_RequestStepStart(uint8_t effective_command)
{
    if (aaf_action_complete_chk == FLAP_STOP)
    {
        if ((effective_command != AAF_Tx_Position) &&
            (AAF_Tx_Position != UNKOWN_POSITION) &&
            (effective_command != UNKOWN_POSITION))
        {
            step_start_flag = ON;
        }
    }
    else if (aaf_action == DIAG_MODE_AUTO)
    {
        if (effective_command != aaf_action)
        {
            step_start_flag = ON;
        }
    }
    else
    {
        /* No request */
    }
}

static uint8_t Lin_GetReportPosition(void)
{
    static uint8_t report_position;

    report_position = AAF_Tx_Position;

    #ifdef AAF_HIGH_SPEED_MODE_ENABLE

        if (AAF_DriveMode == HIGH_SPEED_DRIVE_MODE)
        {
            if ((lin_aaf_request_command == CLOSE) || (lin_aaf_request_command == OPEN_1ST))
            {
                report_position = lin_aaf_request_command;
                highspeed_command_hold_flag = 1U;
            }
        }
        else if (highspeed_command_hold_flag == 1U)
        {
            /* NORMAL 복귀 후에도, 실제 위치가 마스터 명령과 일치할 때까지 계속 명령값 보고 */
            report_position = lin_aaf_request_command;

            /* 실제 위치가 명령값에 도달하면 그때 hold 해제 */
            if (AAF_Tx_Position == lin_aaf_request_command)
            {
                highspeed_command_hold_flag = 0U;
            }
        }
        else
        {
            /* hold 아님: 실제 위치 그대로 보고 (위에서 이미 설정됨) */
        }

    #endif

    return report_position;
}

static void Lin_UpdateCommand(uint8_t target_select)
{
    uint8_t effective_command;

    lin_aaf_request_command = target_select;
    effective_command = HighSpeed_1stOpenOverride(target_select);

    switch (effective_command)
    {
    case CLOSE:
        lin_aaf_command = CLOSE;
        break;

    case OPEN_1ST:
        lin_aaf_command = OPEN_1ST;
        break;

    case OPEN_2ND:
        lin_aaf_command = OPEN_2ND;
        break;

    case OPEN:
        lin_aaf_command = OPEN;
        break;

    case DIAG_MODE_OPEN:
        lin_aaf_command = DIAG_MODE_OPEN;
        break;

    case DIAG_MODE_CLOSE:
        lin_aaf_command = DIAG_MODE_CLOSE;
        break;

    case DIAG_MODE_AUTO:
        lin_aaf_command = DIAG_MODE_AUTO;
        break;

    case UNKOWN_POSITION:
        lin_aaf_command = UNKOWN_POSITION;
        break;

    default:
        break;
    }
}

//0609 우상민 step start 판단은 close 기준이 아닌 1st open 기준
static void Lin_ProcessTargetCommand(uint8_t target_select)
{
    Lin_RequestStepStart(HighSpeed_1stOpenOverride(target_select));
    Lin_UpdateCommand(target_select);
}

/***********************************************************************************************************************
 * Function Name: Lin_TranslateRxData
 * Description  : 수신된 LIN 데이터(Slave_RxData1)를 내부 검증용 버퍼(ID_chk_rxdata)로 복사함
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
static void Lin_TranslateRxData(void)
{
    if (lin_rx_chk_flag == ON)
    {
        for (uint8_t i = 0U; i < 8U; i++)
        {
            ID_chk_rxdata[i] = Slave_RxData1[i];
        }
        lin_rx_chk_flag = OFF;
        lin_rx_pass_flag = PASS;
    }
}

#ifdef ENABLE_TORQUE_LIN_COMMUNICATION
static void Lin_TxTrqCount(void)
{
    static unsigned int trq_read_idx = 0U;

    /* [B] 로깅 시작/종료는 Adc_Check.c 가 단독 소유한다.
     *     여기서는 로깅이 끝난(TxReady) 뒤에 읽어내기만 한다.
     *     AAFx_InitStatus 는 Re_Init() 에서 초기화되지 않으므로 판단 기준으로 쓸 수 없다. */
    if (TRQ_COUNT_TxReady == 1U)
    {
        if (SW_Chk == 0U)
        {
            for (uint8_t i = 3U; i <= 6U; i++)
            {
                unsigned int temp_idx = trq_read_idx + (i - 3U);

                /* 링버퍼이므로 TRQ_COUNT_Index 가 아니라 버퍼 크기로 판정한다 */
                if (temp_idx < TRQ_COUNT_BUF_SIZE)
                {
                    Slave_TxData[i] = (uint8_t)(TRQ_COUNT_Buffer[temp_idx] & 0xFFU);
                }
                else
                {
                    Slave_TxData[i] = 0x00U;
                }
            }

            if (lin_tx_resp_flag == 1U)
            {
                trq_read_idx += 4U;
                lin_tx_resp_flag = 0U;

                if (trq_read_idx >= TRQ_COUNT_BUF_SIZE)
                {
                    trq_read_idx = 0U;
                }
            }
        }
    }
    else
    {
        trq_read_idx = 0U;
    }
}
#endif

/***********************************************************************************************************************
 * Function Name: Lin_CheckAAF1RxData
 * Description  : AAF 1번 유닛에 대한 타겟 위치를 파싱하고 명령을 설정함 (EV 전용)
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
void Lin_CheckAAF1RxData(void){
    
    switch (AAF1_TargetPosition)
    {
        case 0x00U: AAF1_TargetPosition_select = CLOSE; break;
        case 0x01U: AAF1_TargetPosition_select = OPEN_1ST; break;
        case 0x02U: AAF1_TargetPosition_select = OPEN_2ND; break;
        case 0x03U: AAF1_TargetPosition_select = OPEN; break;
        case 0x04U: AAF1_TargetPosition_select = DIAG_MODE_OPEN; break;
        case 0x05U: AAF1_TargetPosition_select = DIAG_MODE_CLOSE; break;
        case 0x06U: AAF1_TargetPosition_select = DIAG_MODE_AUTO; break;
        case 0x07U: AAF1_TargetPosition_select = UNKOWN_POSITION; break;
        default: break;
    }

    Lin_ProcessTargetCommand(AAF1_TargetPosition_select);
}

/***********************************************************************************************************************
 * Function Name: Lin_CheckAAF2RxData
 * Description  : AAF 2번 유닛에 대한 타겟 위치를 파싱하고 명령을 설정함 (EV 전용)
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
void Lin_CheckAAF2RxData(void){
    
    switch (AAF2_TargetPosition)
    {
        case 0x00U: AAF2_TargetPosition_select = CLOSE; break;
        case 0x01U: AAF2_TargetPosition_select = OPEN_1ST; break;
        case 0x02U: AAF2_TargetPosition_select = OPEN_2ND; break;
        case 0x03U: AAF2_TargetPosition_select = OPEN; break;
        case 0x04U: AAF2_TargetPosition_select = DIAG_MODE_OPEN; break;
        case 0x05U: AAF2_TargetPosition_select = DIAG_MODE_CLOSE; break;
        case 0x06U: AAF2_TargetPosition_select = DIAG_MODE_AUTO; break;
        case 0x07U: AAF2_TargetPosition_select = UNKOWN_POSITION; break;
        default: break;
    }

    Lin_ProcessTargetCommand(AAF2_TargetPosition_select);
}

/***********************************************************************************************************************
 * Function Name: Lin_CheckAAF3RxData
 * Description  : AAF 3번 유닛에 대한 타겟 위치를 파싱하고 명령을 설정함 (EV 전용)
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
void Lin_CheckAAF3RxData(void){
    
    switch (AAF3_TargetPosition)
    {
        case 0x00U: AAF3_TargetPosition_select = CLOSE; break;
        case 0x01U: AAF3_TargetPosition_select = OPEN_1ST; break;
        case 0x02U: AAF3_TargetPosition_select = OPEN_2ND; break;
        case 0x03U: AAF3_TargetPosition_select = OPEN; break;
        case 0x04U: AAF3_TargetPosition_select = DIAG_MODE_OPEN; break;
        case 0x05U: AAF3_TargetPosition_select = DIAG_MODE_CLOSE; break;
        case 0x06U: AAF3_TargetPosition_select = DIAG_MODE_AUTO; break;
        case 0x07U: AAF3_TargetPosition_select = UNKOWN_POSITION; break;
        default: break;
    }

    Lin_ProcessTargetCommand(AAF3_TargetPosition_select);
}   


/***********************************************************************************************************************
 * Function Name: Lin_RxCheck
 * Description  : LIN 수신 데이터를 검증하고 보호 기능 상태(ON/OFF)에 따라 처리 루틴을 호출하는 메인 함수
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
void Lin_RxCheck(void)
{
    Lin_SwCheck();

    Lin_TranslateRxData();

    if (lin_rx_pass_flag == PASS)
    {
        if (AAFx_InitStatus != DURING_INITIALIZATION)
        {
            /* EV Control Frame Mapping (Byte 4 ~ 7) */
            AAF1_TargetPosition    = (unsigned int)(ID_chk_rxdata[4U] & 0x07U);
            AAF2_TargetPosition    = (unsigned int)((ID_chk_rxdata[4U] & 0x38U) >> 3U);
            AAF3_TargetPosition    = (unsigned int)(ID_chk_rxdata[5U] & 0x07U);
            CR_Mcu_VehSpdInt_Kph   = (unsigned int)(ID_chk_rxdata[6U]); 
            AAF_ProtectionMode_Rx  = (unsigned int)((ID_chk_rxdata[7U] & 0x40U) >> 6U);
            LDCRdy                 = (unsigned int)((ID_chk_rxdata[7U] & 0x30U) >> 4U);
            AAF_LINOut             = (unsigned int)((ID_chk_rxdata[7U] & 0x0CU) >> 2U);

            HighSpeed_CheckDriveMode(CR_Mcu_VehSpdInt_Kph);

            #ifdef ENABLE_TORQUE_TEST
            Lin_ParseTorqueTestMode(); 
            #endif

            if (AAFx_Index == AAF_1)
            {
                Lin_CheckAAF1RxData();
            }
            else if (AAFx_Index == AAF_2)
            {
                Lin_CheckAAF2RxData();
            }
            else if (AAFx_Index == AAF_3)
            {
                Lin_CheckAAF3RxData();
            }
            
            #ifdef ENABLE_TORQUE_TEST
            Lin_ExecuteTorqueTestMode(); 
            #endif
        }
        else 
        {
            LDCRdy     = (unsigned int)((ID_chk_rxdata[7U] & 0x30U) >> 4U);
            AAF_LINOut = (unsigned int)((ID_chk_rxdata[7U] & 0x0CU) >> 2U);
            AAF_ProtectionMode_Rx  = (ID_chk_rxdata[7U] & 0x40U) >> 6U;
        }
    }
    
}

/***********************************************************************************************************************
 * Function Name: Lin_TxCheck
 * Description  : EV 전용 Response 프레임 규격에 맞춰 송신 데이터를 세팅
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
void Lin_TxCheck(void)
{
    switch (Lin_GetReportPosition())
    {
    case CLOSE:
        AAF_Tx_Position_LIN = 0x00U;
        Diag_Mode_chk = 0U;
        break;
    case OPEN_1ST:
        AAF_Tx_Position_LIN = 0x01U;
        Diag_Mode_chk = 0U;
        break;
    case OPEN_2ND:
        AAF_Tx_Position_LIN = 0x02U;
        Diag_Mode_chk = 0U;
        break;
    case OPEN:
        AAF_Tx_Position_LIN = 0x03U;
        Diag_Mode_chk = 0U;
        break;
    case DIAG_MODE_OPEN:
        AAF_Tx_Position_LIN = 0x04U;
        Diag_Mode_chk = 1U;
        break;
    case DIAG_MODE_CLOSE:
        AAF_Tx_Position_LIN = 0x05U;
        Diag_Mode_chk = 1U;
        break;
    case DIAG_MODE_AUTO:
        AAF_Tx_Position_LIN = 0x06U;
        Diag_Mode_chk = 1U;
        break;
    case UNKOWN_POSITION:
        AAF_Tx_Position_LIN = 0x07U;
        break;
    default:
        break;
    }

    /* EV AAF Response Frame Mapping (Byte 1 ~ Byte 7) */
    Slave_TxData[0U] = (uint8_t)((AAFx_Type << 7U) | (AAF_Tx_Position_LIN & 0x07U));
    Slave_TxData[1U] = (uint8_t)((TotalNumOfAAF << 6U) | (AAFx_Index << 4U) | (AAFx_InitStatus & 0x03U));
    Slave_TxData[2U] = (uint8_t)((AAF_ProtectionMode_Tx << 7U) | (AAFx_Over_Volt << 6U) | (AAFx_Low_Volt << 5U) | (AAFx_Motor_Fault << 4U) | (AAFx_Circuit_Short << 2U) | (AAFx_Circuit_Open << 1U));
    Slave_TxData[3U] = 0x00U;
    Slave_TxData[4U] = 0x00U;
    Slave_TxData[5U] = 0x00U;
    Slave_TxData[6U] = 0x00U;

    #ifdef ENABLE_TORQUE_LIN_COMMUNICATION
    Lin_TxTrqCount();
    #endif

    Lin_SwCheckResponse();

    lin_rx_pass_flag = WAITING;
}

void Lin_BusCheck(void)
{
    if ((G_Timer1ms.LinBusInactive >= LIN_BUS_CHK_TIME_4_SEC) && (lin_bus_inactive_flag == OFF) && (antipinch_action_on == OFF))
    {
        lin_bus_inactive_flag = ON;
        lin_sleep_step = 0U;

        Motor_Off();                           // drv off
        motor_start = OFF;                        // step stop

        aaf_action = FLAP_STOP;
        aaf_action_complete_chk = FLAP_STOP;
        softstart_complete = OFF;
   
        G_Timer1msFlag.External10sCheckFlag = OFF; // 10s chk timer off
        G_Timer1ms.External10sCheck = 0U;

        G_Timer1ms.StallCheck = 0U;      // test
        G_Timer1msFlag.StallCheckFlag = 0U; // test

        G_Timer1msFlag.LinSleepModeFlag = 0U;
        G_Timer1ms.LinSleepMode = 0U;

        wake_up_motor_range_init_chk = 0U;

        /* 수정된 부분: 초기화가 안 끝났다면 WAITING으로 덮어쓰는 것을 방지 */
        if (AAFx_InitStatus != NORMAL_FINISHED_INITIALIZATION)
        {
            aaf_step = AAF_INITIALIZATION;
        }
        else if (aaf_step != AAF_INITIALIZATION)
        {
            aaf_step = AAF_WAITING;
        }
        else {
            /* invalid */
        }
    }
}

/***********************************************************************************************************************
 * Function Name: Lin_NrstCheck
 * Description  : LIN 트랜시버(TLE8457) NRST 핀을 매 루프마다 확인하여 디바운스 처리함.
 *                Sleep 진입 여부와 무관하게 항상 호출되어, lin_nrst_low_flag를 항상 최신 상태로 유지함.
 *                - NRST가 10ms 간격 3회 연속 Low로 확인되면 lin_nrst_low_flag = ON
 *                  (EN 명령이 무시되는 저전압 보호상태로 판단)
 *                - NRST가 10ms 간격 3회 연속 High로 확인되면 lin_nrst_low_flag = OFF (정상 복귀)
 * Called By    : Communication_Check (Service.c) - 매 루프 무조건 호출
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
void Lin_NrstCheck(void)
{
    unsigned int nrst_now;

    G_Timer1msFlag.NrstCheckFlag = 1U;

    if (G_Timer1ms.NrstCheck >= 10U)
    {
        G_Timer1ms.NrstCheck = 0U;
        nrst_now = PORT.PPR0 & (1U << 0);

        if (nrst_now == OFF) /* NRST Low */
        {
            if (lin_nrst_low_flag == OFF)
            {
                lin_nrst_debounce_count++;
                if (lin_nrst_debounce_count >= 3U)
                {
                    lin_nrst_debounce_count = 0U;
                    lin_nrst_low_flag = ON;
                }
            }
            else
            {
                lin_nrst_debounce_count = 0U;
            }
        }
        else /* NRST High */
        {
            if (lin_nrst_low_flag == ON)
            {
                lin_nrst_debounce_count++;
                if (lin_nrst_debounce_count >= 3U)
                {
                    lin_nrst_debounce_count = 0U;
                    lin_nrst_low_flag = OFF;
                }
            }
            else
            {
                lin_nrst_debounce_count = 0U;
            }
        }
    }
}
