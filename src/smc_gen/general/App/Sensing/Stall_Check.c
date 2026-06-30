#include "Stall_Check.h"

/***********************************************************************************************************************
 * Function Name: StallCheck_UpdateCounter
 * Description  : Compares current motor value against thresholds and updates the stall counter/flag.
 * Called By    : StallCheck_Close, StallCheck_Open
 * Arguments    : low_limit  - The lower threshold for stall detection
 * high_limit - The upper threshold for stall detection
 * Return Value : void
 ***********************************************************************************************************************/
static void StallCheck_UpdateCounter(unsigned int low_limit, unsigned int high_limit)
{
    // Check if the value is out of the normal range (Stall condition)
    if ((TRQ_COUNT <= low_limit) || (TRQ_COUNT >= high_limit))
    {
        if ((G_Timer1ms.StallTime >= STALL_CHK_WAIT_TIME) || (stall_test_mode == 1U))
        {
            stall_count++;
        }

        if (stall_count >= STALL_CNT_DEFAULT + cumulative_stall_count)
        {
            motor_stall_flag = MOTOR_STALL;
            stall_count = STALL_CNT_DEFAULT;
        }
    }
    // Value is within normal range
    else
    {
        motor_stall_flag = MOTOR_NORMAL;
        stall_count = STALL_CNT_DEFAULT;
    }
}

/* 초기화 중이면 둔감한 임계(스토퍼 박기용), 아니면 전압별 일반 임계 */
static unsigned int StallCheck_GetThreshold(unsigned int normal_value)
{
    unsigned int threshold;

    if ((aaf_step == AAF_INITIALIZATION) || 
        (lin_sleep_step >= 3U) || 
        (fail_safety_flag == ON) || 
        (LIMP_HOME_step > 0U) || 
        (antipinch_action_on == ON))
    {
        threshold = INIT_STALL_TH_VALUE;
    }
    else
    {
        threshold = normal_value;       /* 일반: 전압별 민감 임계 */
    }

    return threshold;
}

/***********************************************************************************************************************
 * Function Name: StallCheck_Close
 * Description  : Handles stall detection logic when the motor is in CLOSE direction.
 * Called By    : Stall_Check
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
static void StallCheck_Close(void)
{
    if (AAF_location_type == RH_TYPE)
    {
        // RH Type + CLOSE Direction -> Use CCW Thresholds
        StallCheck_UpdateCounter(StallCheck_GetThreshold(motor_ccw_stall_value), MOTOR_CCW_STALL_CHK_HIGH_VALUE);
    }
    else if (AAF_location_type == LH_TYPE)
    {
        // LH Type + CLOSE Direction -> Use CW Thresholds
        StallCheck_UpdateCounter(StallCheck_GetThreshold(motor_cw_stall_value), MOTOR_CW_STALL_CHK_HIGH_VALUE);
    }
    else
    {
        // Invalid
    }
}

/***********************************************************************************************************************
 * Function Name: StallCheck_Open
 * Description  : Handles stall detection logic when the motor is in OPEN direction.
 * Called By    : Stall_Check
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
static void StallCheck_Open(void)
{
    if (AAF_location_type == RH_TYPE)
    {
        // RH Type + OPEN Direction -> Use CW Thresholds
        StallCheck_UpdateCounter(StallCheck_GetThreshold(motor_cw_stall_value), MOTOR_CW_STALL_CHK_HIGH_VALUE);
    }
    else if (AAF_location_type == LH_TYPE)
    {
        // LH Type + OPEN Direction -> Use CCW Thresholds
        StallCheck_UpdateCounter(StallCheck_GetThreshold(motor_ccw_stall_value), MOTOR_CCW_STALL_CHK_HIGH_VALUE);
    }
    else
    {
        // Invalid
    }
}

/***********************************************************************************************************************
 * Function Name: Stall_Check
 * Description  : Main function for motor stall detection.
 * Called By    : SPI_chk
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
void Stall_Check(void)
{
    if (motor_start == ON)
    {
        if (dir_state == CLOSE)
        {
            StallCheck_Close();
        }
        else if (dir_state == OPEN)
        {
            StallCheck_Open();
        }
        else
        {
            // Invalid
        }
    }
}

