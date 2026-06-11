#include "HighSpeed_Mode.h"

/***********************************************************************************************************************
 * Function Name: HighSpeed_GetValidSpeed
 * Description  : LIN 통신으로 수신된 1Byte 차속 데이터의 유효성을 검사 (0xFF 필터링)
 * Arguments    : uint8_t speed (0 ~ 255)
 * Return Value : uint8_t valid_speed (에러 시 0, 정상 시 원본 값)
 ***********************************************************************************************************************/
static uint8_t HighSpeed_GetValidSpeed(uint8_t speed)
{
    // 0xFF 에러 처리
    if (speed == ERROR_SPEED)
    {
        return 0U;
    }
    
    return speed;
}

static void HighSpeed_TimerReset(void)
{
    G_Timer1ms.HighSpeedExitCheck = 0U;
    G_Timer1msFlag.HighSpeedExitCheckFlag = OFF;
}

static void HighSpeed_CheckRelease(uint8_t speed)
{
    if (speed < EXIT_HIGH_SPEED)
    {
        G_Timer1msFlag.HighSpeedExitCheckFlag = ON;

        if (G_Timer1ms.HighSpeedExitCheck >= EXIT_HIGH_SPEED_TIME)
        {
            AAF_DriveMode = NORMAL_DRIVE_MODE;
            HighSpeed_TimerReset();
        }
    }
    else
    {
        HighSpeed_TimerReset();
    }
}

void HighSpeed_CheckDriveMode(uint8_t speed)
{
    uint8_t valid_speed = HighSpeed_GetValidSpeed(speed);

    #ifdef AAF_HIGH_SPEED_MODE_ENABLE 

        if (AAF_DriveMode == NORMAL_DRIVE_MODE)
        {
            if (valid_speed >= ENTER_HIGH_SPEED)
            {
                AAF_DriveMode = HIGH_SPEED_DRIVE_MODE;
                HighSpeed_TimerReset();
            }
        }
        else
        {
            HighSpeed_CheckRelease(valid_speed);
        }

    #else

        AAF_DriveMode = NORMAL_DRIVE_MODE;
        HighSpeed_TimerReset();

    #endif

}

// 새 위치 명령을 바로 수행하지 않음
// 현재 위치 또는 현재 수행 중인 명령 유지
// 10초 후 NORMAL 복귀되면 그때 새 명령 수행
static uint8_t HighSpeed_HoldCommand(void)
{
    uint8_t hold_command;

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
uint8_t HighSpeed_1stOpenOverride(uint8_t requested_command)
{
    uint8_t effective_command = requested_command;

#ifdef AAF_HIGH_SPEED_MODE_ENABLE

    if (AAF_DriveMode == HIGH_SPEED_DRIVE_MODE)
    {
        if (G_Timer1msFlag.HighSpeedExitCheckFlag == ON)
        {
            // 10초 동안 명령 유지
            effective_command = HighSpeed_HoldCommand();
        } 
        else
        {
            if ((requested_command == CLOSE) || (requested_command == OPEN_1ST))
            {
                // 고속 주행 모드에서는 CLOSE 또는 1ST OPEN 명령이 1ST OPEN으로 오버라이드됨
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
