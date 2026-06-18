#include "Lin_CHeck.h"
#include "Service.h"
#include "Trqchange.h"

#ifdef ENABLE_TORQUE_LIN_COMMUNICATION
#define LIN_TRQCHANGE_SETTING_KEY      0x5AU
#define LIN_TRQCHANGE_SETTING_FRAME_ID 0xF0U
#endif


#ifdef ENABLE_TORQUE_TEST
/***********************************************************************************************************************
 * Function Name: Lin_ParseTorqueTestMode
 * Description  : 토크 테스트 및 초기화 관련 플래그 파싱 및 즉각 Re_Init 검사 수행
 ***********************************************************************************************************************/
static void Lin_ParseTorqueTestMode(void)
{
    AAF_Init_Flag                = (unsigned int)((ID_chk_rxdata[1U] & 0x80U) >> 7U);
    AAF_Flap_Fixation_Test_Mode  = (unsigned int)((ID_chk_rxdata[2U] & 0x80U) >> 7U);
    AAF_Maximum_Torque_Test_Mode = (unsigned int)((ID_chk_rxdata[3U] & 0x80U) >> 7U);
    Re_Init_check                = (unsigned int)((ID_chk_rxdata[4U] & 0x80U) >> 7U);

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
    else if ((AAF_Maximum_Torque_Test_Mode_tog == ON) && (AAF_Maximum_Torque_Test_Mode == OFF))
    {
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
        Slave_SwData[3] = (uint8_t)(0x03u); // VECHILE
        Slave_SwData[4] = (uint8_t)(0x11u); // ENGINE, MODEL
        Slave_SwData[5] = (uint8_t)(0x03u);
        Slave_SwData[6] = (uint8_t)(0x63u);
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

//0609  우상민 RAW_SPEED == 0XFF -> 0km/h 처리, 0x64 -> 100km/h . 0x91 -> 145km/h, 0xFF -> Error 
static unsigned int Lin_GetValidVehicleSpeed(unsigned int raw_speed)
{
    unsigned int valid_speed;

    if (raw_speed == AAF_VEHICLE_SPEED_ERROR_VALUE)
    {
        valid_speed = 0U;
    }
    else
    {
        valid_speed = raw_speed;
    }

    return valid_speed;
}

//0609 우상민 타이머 리셋
static void Lin_ResetHighSpeedExitTimer(void)
{
    G_Timer1ms.HighSpeedExitCheck = 0U;
    G_Timer1msFlag.HighSpeedExitCheckFlag = OFF;
}

//0609 우상민 고속 주행 모드에서만 호출,  차속 < 135km/h -> HighSpeedExitCheckFlag ON -> 10초 후 AAF_DRIVE_MODE_NORMAL로 복귀
//차속이 다시 135km/h 이상 -> 타이머 리셋
static void Lin_CheckHighSpeedRelease(unsigned int vehicle_speed)
{
    if (vehicle_speed < AAF_HIGH_SPEED_EXIT_KPH)
    {
        G_Timer1msFlag.HighSpeedExitCheckFlag = ON;

        if (G_Timer1ms.HighSpeedExitCheck >= AAF_HIGH_SPEED_EXIT_TIME_MS)
        {
            AAF_DriveMode = AAF_DRIVE_MODE_NORMAL;
            Lin_ResetHighSpeedExitTimer();
        }
    }
    else
    {
        Lin_ResetHighSpeedExitTimer();
    }
}

//차속 판단 = Lin_UpdateDriveMode()
//명령 변환 = Lin_ApplyHighSpeedCommandOverride()
//응답 위치 계산 = Lin_GetReportPosition()
// AAF_DriveMode 상태만 관리
static void Lin_UpdateDriveMode(unsigned int vehicle_speed)
{
#if (AAF_HIGH_SPEED_MODE_ENABLE == ON)

    if (AAF_DriveMode == AAF_DRIVE_MODE_NORMAL)
    {
        if (vehicle_speed >= AAF_HIGH_SPEED_ENTER_KPH)
        {
            AAF_DriveMode = AAF_DRIVE_MODE_HIGH_SPEED;
            Lin_ResetHighSpeedExitTimer();
        }
    }
    else
    {
        Lin_CheckHighSpeedRelease(vehicle_speed);
    }

#else

    AAF_DriveMode = AAF_DRIVE_MODE_NORMAL;
    Lin_ResetHighSpeedExitTimer();

#endif
}

//0609 우상민 LIN에서 받은 BYTE 6 차속을 처리하는 함수, id_chk_rxdata[6] 읽음, 0xFF이면 0으로 반환, CR_MCU_VEHSPDINT_KPG에 저장, 고속 주행모드 상태 업데이트
static void Lin_ParseVehicleSpeed(unsigned int raw_speed)
{
    CR_Mcu_VehSpdInt_Kph = Lin_GetValidVehicleSpeed(raw_speed);
    Lin_UpdateDriveMode(CR_Mcu_VehSpdInt_Kph);
}

//차속은 135 미만이지만 아직 10초 전이므로 HIGH_SPEED 상태, 그리고 정상복귀 대기중
static unsigned int Lin_IsHighSpeedExitWaiting(void)
{
    unsigned int waiting_status;

    waiting_status = OFF;

#if (AAF_HIGH_SPEED_MODE_ENABLE == ON)

    if ((AAF_DriveMode == AAF_DRIVE_MODE_HIGH_SPEED) &&
        (G_Timer1msFlag.HighSpeedExitCheckFlag == ON))
    {
        waiting_status = ON;
    }

#endif

    return waiting_status;
}

// 새 위치 명령을 바로 수행하지 않음
// 현재 위치 또는 현재 수행 중인 명령 유지
// 10초 후 NORMAL 복귀되면 그때 새 명령 수행
static unsigned int Lin_GetHighSpeedHoldCommand(void)
{
    unsigned int hold_command;

    // 동작 완료 상태 -> AAF_Tx_Position 유지, 동작 중 상태 -> 현재 LIN 명령 (lin_aaf_command) 유지
    hold_command = lin_aaf_command;

    if (aaf_action_complete_chk == FLAP_STOP) // 이 상태는 동작이 완료된 상태이므로, 실제 위치값인 AAF_Tx_Position을 유지
    {
        if (AAF_Tx_Position != UNKOWN_POSITION)
        {
            hold_command = AAF_Tx_Position;
        }
    }

    if (hold_command == UNKOWN_POSITION)
    {
        hold_command = OPEN_1ST;
    }

    return hold_command;
}

// 고속 주행모드일 경우, MCU 명령이 CLOSE 또는 1ST OPEN이면 실제 동작은 1ST OPEN 수행
static unsigned int Lin_ApplyHighSpeedCommandOverride(unsigned int requested_command)
{
    unsigned int effective_command;

    effective_command = requested_command;

#if (AAF_HIGH_SPEED_MODE_ENABLE == ON)

    if (AAF_DriveMode == AAF_DRIVE_MODE_HIGH_SPEED)
    {
        if (Lin_IsHighSpeedExitWaiting() == ON)
        {
            /*
             * 차속이 135km/h 미만으로 내려갔지만 10초가 지나지 않은 상태.
             * 아직 NORMAL 모드가 아니므로 새 위치 명령을 바로 수행하지 않고 현재 실제 상태를 유지한다.
             */
            effective_command = Lin_GetHighSpeedHoldCommand();
        }
        else
        {
            /*
             * 고속 주행모드 유지 상태.
             * CLOSE 또는 OPEN_1ST 요청만 OPEN_1ST로 보정하고,
             * OPEN_2ND / FULL OPEN / DIAG / UNKNOWN은 요청대로 수행한다.
             */
            if ((requested_command == CLOSE) || (requested_command == OPEN_1ST))
            {
                effective_command = OPEN_1ST;
            }
            else
            {
                /* Requested command is used without override */
            }
        }
    }

#endif

    return effective_command;
}

//0609 우상민 실제 동작 명령인 effective_command 기준으로 step_start_flag를 판단
static void Lin_RequestStepStart(unsigned int effective_command)
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

//0609 우상민 AAF_Tx_Position 자체를 바꾸면 안되고, 응답용 위치만 Lin_GetReportPosition에서 따로 계산
static unsigned int Lin_GetReportPosition(void)
{
    unsigned int report_position;

    report_position = AAF_Tx_Position;

#if (AAF_HIGH_SPEED_MODE_ENABLE == ON)

    if (AAF_DriveMode == AAF_DRIVE_MODE_HIGH_SPEED)
    {
        if ((lin_aaf_request_command == CLOSE) || (lin_aaf_request_command == OPEN_1ST))
        {
            report_position = lin_aaf_request_command;
        }
    }

#endif

    return report_position;
}

static void Lin_UpdateCommand(unsigned int target_select)
{
    unsigned int effective_command;

    lin_aaf_request_command = target_select;
    effective_command = Lin_ApplyHighSpeedCommandOverride(target_select);

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
static void Lin_ProcessTargetCommand(unsigned int target_select)
{
    Lin_RequestStepStart(Lin_ApplyHighSpeedCommandOverride(target_select));
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

    if (AAFx_InitStatus == NORMAL_FINISHED_INITIALIZATION) 
    {
        TRQ_COUNT_LogEnable = 0U; 

        if (SW_Chk == 0U) 
        {
            // 1. 현재 인덱스(trq_read_idx)를 기준으로 4개의 데이터를 무조건 상자에 담아둡니다. 
            for (uint8_t i = 3U; i <= 6U; i++) 
            {
                unsigned int temp_idx = trq_read_idx + (i - 3U);
                if (temp_idx < TRQ_COUNT_Index)
                {
                    Slave_TxData[i] = (uint8_t)(TRQ_COUNT_Buffer[temp_idx] & 0xFFU);
                }
                else
                {
                    Slave_TxData[i] = 0x00U; 
                }
            }

            // 2.  CANoe가 방금 데이터를 가져갔다는
            if (lin_tx_resp_flag == 1U)
            {
                trq_read_idx += 4U;      
                lin_tx_resp_flag = 0U;   

                if (trq_read_idx >= TRQ_COUNT_Index) 
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

#ifdef ENABLE_TORQUE_LIN_COMMUNICATION
/***********************************************************************************************************************
 * Function Name: Lin_CheckTrqSettingFrame
 * Description  : F0 설정 프레임을 확인하고 설정값을 전달함.
 ***********************************************************************************************************************/
static uint8_t Lin_CheckTrqSettingFrame(void)
{
    uint8_t result;

    result = OFF;

    if (ID_chk_rxdata[0U] == LIN_TRQCHANGE_SETTING_FRAME_ID)
    {
        result = ON;

        if (ID_chk_rxdata[3U] == LIN_TRQCHANGE_SETTING_KEY)
        {
            (void)TrqChange_Set(ID_chk_rxdata[1U],
                                ID_chk_rxdata[2U]);
        }
    }

    return result;
}
#endif

/***********************************************************************************************************************
 * Function Name: Lin_RxCheck
 * Description  : LIN 수신 프레임을 확인하고 해당 명령을 처리함.
 ***********************************************************************************************************************/
void Lin_RxCheck(void)
{
#ifdef ENABLE_TORQUE_LIN_COMMUNICATION
    uint8_t setting_frame;
#endif

    Lin_SwCheck();
    Lin_TranslateRxData();

    if (lin_rx_pass_flag == PASS)
    {
#ifdef ENABLE_TORQUE_LIN_COMMUNICATION
        setting_frame = Lin_CheckTrqSettingFrame();

        if (setting_frame == OFF)
#endif
        {
            Lin_ParseVehicleSpeed((unsigned int)ID_chk_rxdata[6U]);

            AAF_ProtectionMode_Rx =
                (unsigned int)((ID_chk_rxdata[7U] & 0x40U) >> 6U);

            LDCRdy =
                (unsigned int)((ID_chk_rxdata[7U] & 0x30U) >> 4U);

            AAF_LINOut =
                (unsigned int)((ID_chk_rxdata[7U] & 0x0CU) >> 2U);

            if (AAFx_InitStatus != DURING_INITIALIZATION)
            {
                AAF1_TargetPosition =
                    (unsigned int)(ID_chk_rxdata[4U] & 0x07U);

                AAF2_TargetPosition =
                    (unsigned int)((ID_chk_rxdata[4U] & 0x38U) >> 3U);

                AAF3_TargetPosition =
                    (unsigned int)(ID_chk_rxdata[5U] & 0x07U);

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
                else
                {
                    /* Invalid AAF index */
                }

#ifdef ENABLE_TORQUE_TEST
                Lin_ExecuteTorqueTestMode();
#endif
            }
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
    {
        unsigned long step_range;

        step_range = 0UL;

        if (step_position_close >= step_position_open)
        {
            step_range = (unsigned long)(step_position_close - step_position_open);
        }

        Slave_TxData[3U] = TrqChange_GetMicrostep();
        Slave_TxData[4U] = (uint8_t)(step_range & 0xFFUL);
        Slave_TxData[5U] = (uint8_t)((step_range >> 8U) & 0xFFUL);
        Slave_TxData[6U] = (uint8_t)((step_range >> 16U) & 0xFFUL);
    }
#endif

    // #ifdef ENABLE_TORQUE_LIN_COMMUNICATION
    // Lin_TxTrqCount();
    // #endif
   
    Lin_SwCheckResponse();

    lin_rx_pass_flag = WAITING;
}

void Lin_BusCheck(void)
{
    if ((G_Timer1ms.LinBusInactive >= LIN_BUS_CHK_TIME_4_SEC) && (lin_bus_inactive_flag == OFF))
    {
        lin_bus_inactive_flag = ON;
        lin_sleep_step = 0U;

        Drv8889_Off2();                           // drv of
        motor_start = OFF;                    // step stop

        aaf_action = FLAP_STOP;
        aaf_action_complete_chk = FLAP_STOP;
        softstart_complete = OFF;
        motor_step_value = STEP_TIME_1000RPM;

        G_Timer1msFlag.External10sCheckFlag = OFF; // 10s chk timer off
        G_Timer1ms.External10sCheck = 0U;

        G_Timer1ms.StallCheck = 0U;      // test
        G_Timer1msFlag.StallCheckFlag = 0U; // test

        G_Timer1msFlag.LinSleepModeFlag = 0U;
        G_Timer1ms.LinSleepMode = 0U;

        wake_up_motor_range_init_chk = 0U;

        aaf_step = AAF_WAITING;
    }
}


