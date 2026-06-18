#include "Trqchange.h"
#include "Config.h"
#include "Drv8889.h"
#include "Config_TAUJ1.h"

#ifdef ENABLE_TORQUE_LIN_COMMUNICATION

#define TRQCHANGE_CTRL1_TRQ_MASK        0xF0U
#define TRQCHANGE_CTRL1_RESERVED_MASK   0x0CU

static uint8_t trqchange_ctrl1_data = (uint8_t)(TRQ_DAC_75 | SLEW_RATE_10V);
static uint8_t trqchange_ctrl3_data = CONFIG_MOTOR_MICROSTEP_DEFAULT;
static uint8_t trqchange_setting_pending = OFF;
static uint8_t trqchange_ctrl1_active = OFF;
static uint8_t trqchange_current_microstep = CONFIG_MOTOR_MICROSTEP_DEFAULT;

static uint8_t TrqChange_CheckCtrl1(uint8_t ctrl1_data);
static uint8_t TrqChange_CheckCtrl3(uint8_t ctrl3_data);

static void TrqChange_SetTimer(uint8_t microstep);
static uint8_t TrqChange_GetDivider(uint8_t microstep);
static unsigned int TrqChange_ConvertStepCount(unsigned int step_count,
                                               uint8_t previous_microstep,
                                               uint8_t requested_microstep);
static void TrqChange_ConvertPosition(uint8_t previous_microstep,
                                      uint8_t requested_microstep);
static void TrqChange_PrepareMotor(void);

/***********************************************************************************************************************
 * Function Name: TrqChange_CheckCtrl1
 * Description  : CTRL1 설정값의 허용 범위를 확인함.
 * Arguments    : ctrl1_data - CTRL1 설정값
 ***********************************************************************************************************************/
static uint8_t TrqChange_CheckCtrl1(uint8_t ctrl1_data)
{
    uint8_t trq_dac;
    uint8_t result;

    trq_dac = (uint8_t)(ctrl1_data & TRQCHANGE_CTRL1_TRQ_MASK);
    result = OFF;

    if (((ctrl1_data & TRQCHANGE_CTRL1_RESERVED_MASK) == 0U) &&
        (trq_dac <= (uint8_t)TRQ_DAC_75))
    {
        result = ON;
    }

    return result;
}

/***********************************************************************************************************************
 * Function Name: TrqChange_CheckCtrl3
 * Description  : CTRL3 Microstep 설정값의 허용 범위를 확인함.
 * Arguments    : ctrl3_data - CTRL3 설정값
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
 * Arguments    : microstep - Microstep 설정값
 * Return Value : void
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
 * Function Name: TrqChange_GetDivider
 * Description  : Microstep 설정값을 분주값으로 변환함.
 * Arguments    : microstep - Microstep 설정값
 * Return Value : Microstep 분주값
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

    case CONFIG_MICROSTEP_1_16:
        divider = 16U;
        break;

    case CONFIG_MICROSTEP_1_32:
        divider = 32U;
        break;

    case CONFIG_MICROSTEP_1_8:
    default:
        divider = 8U;
        break;
    }

    return divider;
}

/***********************************************************************************************************************
 * Function Name: TrqChange_ConvertStepCount
 * Description  : 기존 Microstep 기준 위치값을 변경된 Microstep 기준으로 환산함.
 * Arguments    : step_count         - 기존 위치값
 *                previous_microstep - 변경 전 Microstep
 *                requested_microstep - 변경 후 Microstep
 * Return Value : 환산된 위치값
 ***********************************************************************************************************************/
static unsigned int TrqChange_ConvertStepCount(unsigned int step_count,
                                               uint8_t previous_microstep,
                                               uint8_t requested_microstep)
{
    unsigned long converted_value;
    unsigned long previous_divider;
    unsigned long requested_divider;

    previous_divider =
        (unsigned long)TrqChange_GetDivider(previous_microstep);

    requested_divider =
        (unsigned long)TrqChange_GetDivider(requested_microstep);

    if (previous_divider == requested_divider)
    {
        converted_value = (unsigned long)step_count;
    }
    else
    {
        converted_value =
            (((unsigned long)step_count * requested_divider) +
             (previous_divider / 2UL)) /
            previous_divider;
    }

    return (unsigned int)converted_value;
}

/***********************************************************************************************************************
 * Function Name: TrqChange_ConvertPosition
 * Description  : Microstep 변경 시 위치 관련 값을 변경된 Microstep 기준으로 환산함.
 * Arguments    : previous_microstep - 변경 전 Microstep
 *                requested_microstep - 변경 후 Microstep
 * Return Value : void
 ***********************************************************************************************************************/
static void TrqChange_ConvertPosition(uint8_t previous_microstep,
                                      uint8_t requested_microstep)
{
    if (previous_microstep != requested_microstep)
    {
        step_position =
            TrqChange_ConvertStepCount(step_position,
                                       previous_microstep,
                                       requested_microstep);

        step_position_open =
            TrqChange_ConvertStepCount(step_position_open,
                                       previous_microstep,
                                       requested_microstep);

        step_position_close =
            TrqChange_ConvertStepCount(step_position_close,
                                       previous_microstep,
                                       requested_microstep);

        limit_step_position =
            TrqChange_ConvertStepCount(limit_step_position,
                                       previous_microstep,
                                       requested_microstep);
    }
}

/***********************************************************************************************************************
 * Function Name: TrqChange_PrepareMotor
 * Description  : Microstep 변경 전 모터 제어 상태를 초기화함.
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
static void TrqChange_PrepareMotor(void)
{
    Drv8889_Off();

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
 * Function Name: TrqChange_Set
 * Description  : CTRL1과 CTRL3 설정값을 확인하고 적용 대기값으로 저장함.
 * Arguments    : ctrl1_data - CTRL1 설정값
 *                ctrl3_data - CTRL3 설정값
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
        trqchange_setting_pending = ON;
        result = ON;
    }

    return result;
}

/***********************************************************************************************************************
 * Function Name: TrqChange_Apply
 * Description  : 저장된 CTRL1과 CTRL3 설정값을 모터 정지 상태에서 적용함
 ***********************************************************************************************************************/
void TrqChange_Apply(void)
{
    uint8_t previous_microstep;
    uint8_t requested_microstep;

    previous_microstep = trqchange_current_microstep;
    requested_microstep = trqchange_ctrl3_data;

    if ((trqchange_setting_pending == ON) &&
        (motor_start == OFF))
    {
        if (previous_microstep != requested_microstep)
        {
            TrqChange_PrepareMotor();
        }

        Drv8889_WriteCtrl1Raw(trqchange_ctrl1_data);
        Drv8889_WriteCtrl3(trqchange_ctrl3_data);

        TrqChange_SetTimer(requested_microstep);
        TrqChange_ConvertPosition(previous_microstep, requested_microstep);

        trqchange_ctrl1_active = ON;
        trqchange_current_microstep = requested_microstep;
        trqchange_setting_pending = OFF;
    }
}

/***********************************************************************************************************************
 * Function Name: TrqChange_ClearPending
 * Description  : 적용 대기 중인 모터 설정 요청을 취소함.
 ***********************************************************************************************************************/
void TrqChange_ClearPending(void)
{
    trqchange_setting_pending = OFF;
}

/***********************************************************************************************************************
 * Function Name: TrqChange_ResetMicrostep
 * Description  : Resets the Microstep setting to the default value.
 ***********************************************************************************************************************/
void TrqChange_ResetMicrostep(void)
{
    trqchange_setting_pending = OFF;

    Drv8889_WriteCtrl3(CONFIG_MOTOR_MICROSTEP_DEFAULT);
    TrqChange_SetTimer(CONFIG_MOTOR_MICROSTEP_DEFAULT);

    trqchange_ctrl3_data = CONFIG_MOTOR_MICROSTEP_DEFAULT;
    trqchange_current_microstep = CONFIG_MOTOR_MICROSTEP_DEFAULT;
}

/***********************************************************************************************************************
 * Function Name: TrqChange_IsCtrl1Active
 * Description  : Returns the LIN CTRL1 setting state.
 ***********************************************************************************************************************/
uint8_t TrqChange_IsCtrl1Active(void)
{
    return trqchange_ctrl1_active;
}

/***********************************************************************************************************************
 * Function Name: TrqChange_GetMicrostep
 * Description  : 현재 적용된 Microstep 설정값을 반환함
 ***********************************************************************************************************************/
uint8_t TrqChange_GetMicrostep(void)
{
    return trqchange_current_microstep;
}

#endif
