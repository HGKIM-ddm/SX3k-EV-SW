#include "Stall_Check.h"

void StallCheck_ChangeStallTh(void)
{
    static uint8_t prev_th = 0xFFU;   /* 초기값: 강제 첫 write */
    uint8_t stall_th;

    if ((aaf_step == AAF_INITIALIZATION) ||
        (lin_sleep_step >= 3U) ||
        (fail_safety_flag == ON) ||
        (LIMP_HOME_step > 0U) ||
        (antipinch_action_on == ON))
    {
        stall_th = INIT_STALL_TH;
    }
    else
    {
        stall_th = STALL_TH_NORMAL_VOLTAGE;
    }

    if (stall_th != prev_th)          /* ← 값이 바뀔 때만 write */
    {
        Drv8889_WriteCtrl6(stall_th);
        prev_th = stall_th;
    }
}

void Stall_Check(void)   
{
    if ((motor_start == ON)
        && (AAF_Maximum_Torque_Test_Mode == OFF)
        && (G_Timer1ms.StallTime >= STALL_CHK_WAIT_TIME))
    {
        if (Drv8889_IsStallBitSet() != 0U)   // 드라이버에 stall bit 조회
        {
            stall_count++;
            if (stall_count >= cumulative_stall_count) {
                motor_stall_flag = MOTOR_STALL;
                stall_count = cumulative_stall_count;
            }
        }
        else {
            stall_count = 0U;
        }
    }
    else {
        stall_count = 0U;
    }
}

