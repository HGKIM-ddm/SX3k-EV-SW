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
    if ((motor_stall_value <= low_limit) || (motor_stall_value >= high_limit))
    {
        if ((G_Timer1ms.StallTime >= STALL_CHK_WAIT_TIME) || (stall_test_mode == 1U))
        {
            stall_cnt++;
        }

        if (stall_cnt >= STALL_CNT_DEFAULT + STALL_CNT_COMPARISON_VAL)
        {
            motor_stall_flag = MOTOR_STALL;
            stall_cnt = STALL_CNT_DEFAULT;
        }
    }
    // Value is within normal range
    else
    {
        motor_stall_flag = MOTOR_NORMAL;
        stall_cnt = STALL_CNT_DEFAULT;
        
        // [Legacy Comment Preserved]
        // stall_cnt--;
        // if (stall_cnt < STALL_CNT_DEFAULT)
        // {
        //     stall_cnt = STALL_CNT_DEFAULT;
        // }
    }
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
        StallCheck_UpdateCounter(motor_ccw_stall_value, MOTOR_CCW_STALL_CHK_HIGH_VALUE);
    }
    else if (AAF_location_type == LH_TYPE)
    {
        // LH Type + CLOSE Direction -> Use CW Thresholds
        StallCheck_UpdateCounter(motor_cw_stall_value, MOTOR_CW_STALL_CHK_HIGH_VALUE);
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
        StallCheck_UpdateCounter(motor_cw_stall_value, MOTOR_CW_STALL_CHK_HIGH_VALUE);
    }
    else if (AAF_location_type == LH_TYPE)
    {
        // LH Type + OPEN Direction -> Use CCW Thresholds
        StallCheck_UpdateCounter(motor_ccw_stall_value, MOTOR_CCW_STALL_CHK_HIGH_VALUE);
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

