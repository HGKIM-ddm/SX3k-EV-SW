#include "Trqchange.h"
#include "Config.h"
#include "Drv8889.h"
#include "Config_TAUJ1.h"

#ifdef ENABLE_TORQUE_LIN_COMMUNICATION

#define TRQCHANGE_CTRL1_TRQ_MASK        0xF0U
#define TRQCHANGE_CTRL1_RESERVED_MASK   0x0CU

#define TRQCHANGE_INIT_MICROSTEP CONFIG_MICROSTEP_1_8
#define TRQCHANGE_INIT_CTRL1_NORMAL \
    ((uint8_t)(TRQ_DAC_75 | SLEW_RATE_10V))
#define TRQCHANGE_INIT_CTRL1_LOW \
    ((uint8_t)(TRQ_DAC_75 | SLEW_RATE_35V))

static uint8_t trqchange_ctrl1_data = (uint8_t)(TRQ_DAC_75 | SLEW_RATE_10V);
static uint8_t trqchange_ctrl3_data = CONFIG_MOTOR_MICROSTEP_DEFAULT;
static uint8_t trqchange_setting_pending = OFF;
static uint8_t trqchange_ctrl1_active = OFF;
static uint8_t trqchange_current_ctrl1_data = (uint8_t)(TRQ_DAC_75 | SLEW_RATE_10V);
static uint8_t trqchange_current_microstep = CONFIG_MOTOR_MICROSTEP_DEFAULT;
static uint8_t trqchange_initialized_microstep = CONFIG_MOTOR_MICROSTEP_DEFAULT;
static uint8_t trqchange_position_valid = ON;
static uint8_t trqchange_reinit_active = OFF;

static uint8_t TrqChange_CheckCtrl1(uint8_t ctrl1_data);
static uint8_t TrqChange_CheckCtrl3(uint8_t ctrl3_data);

static void TrqChange_SetTimer(uint8_t microstep);
static void TrqChange_PrepareMotor(void);
static uint8_t TrqChange_GetDivider(uint8_t microstep);

static uint8_t TrqChange_GetInitCtrl1(void);
static unsigned int TrqChange_ConvertStepCount(
    unsigned int value,
    uint8_t from_microstep,
    uint8_t to_microstep);
static void TrqChange_ConvertPosition(
    uint8_t from_microstep,
    uint8_t to_microstep);

/***********************************************************************************************************************
 * Function Name: TrqChange_CheckCtrl1
 * Description  : CTRL1 설정값의 허용 범위를 확인함.
 ***********************************************************************************************************************/
static uint8_t TrqChange_CheckCtrl1(uint8_t ctrl1_data)
{
    uint8_t result;

    result = OFF;

    switch (ctrl1_data)
    {
    case (uint8_t)TRQ_DAC_100:
    case (uint8_t)TRQ_DAC_93_75:
    case (uint8_t)TRQ_DAC_87_5:
    case (uint8_t)TRQ_DAC_81_25:
    case (uint8_t)TRQ_DAC_75:
    case (uint8_t)TRQ_DAC_68_75:
    case (uint8_t)TRQ_DAC_62_5:
        result = ON;
        break;

    default:
        break;
    }

    return result;
}

/***********************************************************************************************************************
 * Function Name: TrqChange_CheckCtrl3
 * Description  : CTRL3 Microstep 설정값의 허용 범위를 확인함.
 ***********************************************************************************************************************/
static uint8_t TrqChange_CheckCtrl3(uint8_t ctrl3_data)
{
    uint8_t result;

    result = OFF;

    switch (ctrl3_data)
    {
    case CONFIG_MICROSTEP_FULL_71:
    case CONFIG_MICROSTEP_1_2:
    case CONFIG_MICROSTEP_1_4:
    case CONFIG_MICROSTEP_1_8:
    case CONFIG_MICROSTEP_1_16:
    case CONFIG_MICROSTEP_1_32:
        result = ON;
        break; 

    default:
        break;
    }

    return result;
}

/***********************************************************************************************************************
 * Function Name: TrqChange_SetTimer
 * Description  : Microstep 설정값에 따라 TAUJ1 STEP 출력 주기를 변경함.
 ***********************************************************************************************************************/
static void TrqChange_SetTimer(uint8_t microstep)
{
    switch (microstep)
    {
    case CONFIG_MICROSTEP_FULL_71:
        R_Config_TAUJ1_SetCompareValue(CONFIG_TAUJ1_MICROSTEP_FULL_71_CH0_COMPARE,
                                       CONFIG_TAUJ1_MICROSTEP_FULL_71_CH1_COMPARE);
        break;

    case CONFIG_MICROSTEP_1_2:
        R_Config_TAUJ1_SetCompareValue(CONFIG_TAUJ1_MICROSTEP_1_2_CH0_COMPARE,
                                       CONFIG_TAUJ1_MICROSTEP_1_2_CH1_COMPARE);
        break;

    case CONFIG_MICROSTEP_1_4:
        R_Config_TAUJ1_SetCompareValue(CONFIG_TAUJ1_MICROSTEP_1_4_CH0_COMPARE,
                                       CONFIG_TAUJ1_MICROSTEP_1_4_CH1_COMPARE);
        break;

    case CONFIG_MICROSTEP_1_8:
        R_Config_TAUJ1_SetCompareValue(CONFIG_TAUJ1_MICROSTEP_1_8_CH0_COMPARE,
                                       CONFIG_TAUJ1_MICROSTEP_1_8_CH1_COMPARE);
        break;

    case CONFIG_MICROSTEP_1_16:
        R_Config_TAUJ1_SetCompareValue(CONFIG_TAUJ1_MICROSTEP_1_16_CH0_COMPARE,
                                       CONFIG_TAUJ1_MICROSTEP_1_16_CH1_COMPARE);
        break;

    case CONFIG_MICROSTEP_1_32:
        R_Config_TAUJ1_SetCompareValue(CONFIG_TAUJ1_MICROSTEP_1_32_CH0_COMPARE,
                                       CONFIG_TAUJ1_MICROSTEP_1_32_CH1_COMPARE);
        break;

    default:
        break;
    }
}


/***********************************************************************************************************************
 * Function Name: TrqChange_PrepareMotor
 * Description  : Microstep 변경 전 모터 제어 상태를 초기화함.
 ***********************************************************************************************************************/
static void TrqChange_PrepareMotor(void)
{
    Drv8889_Off();

    motor_start = OFF;
    motor_wait_chk = OFF;
    step_start_flag = OFF;
    softstart_complete = OFF;
    motor_step_value = STEP_TIME_1000RPM;

    G_Timer1ms.MotorDelay = 0U;
    G_Timer1ms.StallTime = 0U;
    G_Timer1msFlag.StallTimeFlag = 0U;
    G_Timer1ms.StallCheck = 0U;
    G_Timer1msFlag.StallCheckFlag = 0U;

    motor_stall_flag = MOTOR_NORMAL;
}

/***********************************************************************************************************************
 * Function Name: TrqChange_GetDivider
 * Description  : Microstep 설정값에 따른 분주 비율을 반환함.
 ***********************************************************************************************************************/
static uint8_t TrqChange_GetDivider(uint8_t microstep)
{
    uint8_t divider;

    switch (microstep)
    {
    case CONFIG_MICROSTEP_FULL_71:
        divider = 1U;
        break;

    case CONFIG_MICROSTEP_1_2:
        divider = 2U;
        break;

    case CONFIG_MICROSTEP_1_4:
        divider = 4U;
        break;

    case CONFIG_MICROSTEP_1_8:
        divider = 8U;
        break;

    case CONFIG_MICROSTEP_1_16:
        divider = 16U;
        break;

    case CONFIG_MICROSTEP_1_32:
        divider = 32U;
        break;

    default:
        divider = 8U;
        break;
    }

    return divider;
}

static uint8_t TrqChange_GetInitCtrl1(void)
{
    if (voltage_status_spi == LOW_VOLTAGE)
    {
        return TRQCHANGE_INIT_CTRL1_LOW;
    }

    return TRQCHANGE_INIT_CTRL1_NORMAL;
}

static unsigned int TrqChange_ConvertStepCount(
    unsigned int value,
    uint8_t from_microstep,
    uint8_t to_microstep)
{
    unsigned long from_divider;
    unsigned long to_divider;

    from_divider =
        (unsigned long)TrqChange_GetDivider(from_microstep);
    to_divider =
        (unsigned long)TrqChange_GetDivider(to_microstep);

    return (unsigned int)
        ((((unsigned long)value * to_divider) +
          (from_divider / 2UL)) / from_divider);
}

static void TrqChange_ConvertPosition(
    uint8_t from_microstep,
    uint8_t to_microstep)
{
    step_position = TrqChange_ConvertStepCount(
        step_position, from_microstep, to_microstep);
    step_position_open = TrqChange_ConvertStepCount(
        step_position_open, from_microstep, to_microstep);
    step_position_close = TrqChange_ConvertStepCount(
        step_position_close, from_microstep, to_microstep);
    limit_step_position = TrqChange_ConvertStepCount(
        limit_step_position, from_microstep, to_microstep);
    open_1st_step_position = TrqChange_ConvertStepCount(
        open_1st_step_position, from_microstep, to_microstep);
    open_2nd_step_position = TrqChange_ConvertStepCount(
        open_2nd_step_position, from_microstep, to_microstep);
}

/***********************************************************************************************************************
 * Function Name: TrqChange_Set
 * Description  : CTRL1과 CTRL3 설정값을 확인하고 적용 대기값으로 저장함.
 ***********************************************************************************************************************/
uint8_t TrqChange_Set(uint8_t ctrl1_data, uint8_t ctrl3_data)
{
    uint8_t result;

    result = OFF;

    if ((TrqChange_CheckCtrl1(ctrl1_data) == ON) &&
        (TrqChange_CheckCtrl3(ctrl3_data) == ON))
    {
        trqchange_ctrl1_data = ctrl1_data;
        trqchange_ctrl3_data = ctrl3_data;

        if ((trqchange_ctrl1_active == OFF) ||
            (ctrl1_data != trqchange_current_ctrl1_data) ||
            (ctrl3_data != trqchange_current_microstep) ||
            (trqchange_position_valid == OFF) ||
            (ctrl3_data != trqchange_initialized_microstep))
        {
            trqchange_setting_pending = ON;
        }
        else
        {
            trqchange_setting_pending = OFF;
        }

        result = ON;
    }

    return result;
}

uint8_t TrqChange_HasPending(void)
{
    return trqchange_setting_pending;
}

uint8_t TrqChange_Apply(void)
{
    uint8_t init_ctrl1;

    if ((trqchange_setting_pending == OFF) ||
        (motor_start != OFF) ||
        (aaf_step != AAF_WAITING) ||
        (AAFx_InitStatus != NORMAL_FINISHED_INITIALIZATION) ||
        (spi_action_step != 0U) ||
        (spi_send_flag != 0U) ||
        (spi_receive_flag != 0U))
    {
        return OFF;
    }

    Drv8889_SetCtrl1Override(ON);

    if ((trqchange_position_valid == OFF) ||
        (trqchange_ctrl3_data != trqchange_initialized_microstep))
    {
        TrqChange_PrepareMotor();

        init_ctrl1 = TrqChange_GetInitCtrl1();

        Drv8889_WriteCtrl1Raw(init_ctrl1);
        Drv8889_WriteCtrl3(TRQCHANGE_INIT_MICROSTEP);
        TrqChange_SetTimer(TRQCHANGE_INIT_MICROSTEP);

        trqchange_current_ctrl1_data = init_ctrl1;
        trqchange_current_microstep = TRQCHANGE_INIT_MICROSTEP;
        motor_microstep_current = TRQCHANGE_INIT_MICROSTEP;
        trqchange_ctrl1_active = ON;
        trqchange_position_valid = OFF;
        trqchange_reinit_active = ON;
        trqchange_setting_pending = OFF;

        return ON;
    }

    if ((trqchange_ctrl1_active == OFF) ||
        (trqchange_ctrl1_data != trqchange_current_ctrl1_data))
    {
        Drv8889_WriteCtrl1Raw(trqchange_ctrl1_data);
        trqchange_current_ctrl1_data = trqchange_ctrl1_data;
        trqchange_ctrl1_active = ON;
    }

    trqchange_setting_pending = OFF;

    return OFF;
}

void TrqChange_ConfirmInitialization(void)
{
    if (trqchange_reinit_active == ON)
    {
        TrqChange_ConvertPosition(TRQCHANGE_INIT_MICROSTEP,
                                  trqchange_ctrl3_data);

        Drv8889_SetCtrl1Override(ON);
        Drv8889_WriteCtrl3(trqchange_ctrl3_data);
        TrqChange_SetTimer(trqchange_ctrl3_data);
        Drv8889_WriteCtrl1Raw(trqchange_ctrl1_data);

        trqchange_current_microstep = trqchange_ctrl3_data;
        motor_microstep_current = trqchange_ctrl3_data;
        trqchange_initialized_microstep = trqchange_ctrl3_data;
        trqchange_current_ctrl1_data = trqchange_ctrl1_data;
        trqchange_ctrl1_active = ON;
        trqchange_position_valid = ON;
        trqchange_reinit_active = OFF;
    }
}

/***********************************************************************************************************************
 * Function Name: TrqChange_ClearPending
 * Description  : 대기 중인 CTRL1/CTRL3 설정값을 취소함.

 ***********************************************************************************************************************/
void TrqChange_ClearPending(void)
{
    trqchange_setting_pending = OFF;
}

#endif
