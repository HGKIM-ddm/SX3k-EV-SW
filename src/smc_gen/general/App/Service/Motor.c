#include "Motor.h"
#include "Service.h"

static void Motor_Action(void);
static void Motor_ManageStartStatus(void);
static void Motor_SoftStart(void);
static void Motor_StagedSoftStart(void);
static void Motor_GenerateStepPulse(void);

static volatile uint8_t pwm_flag = OFF;

/***********************************************************************************************************************
 * Function Name: Motor_Action
 * Description  : Main function for motor control (State, Acceleration, Step Generation).
 * Called By    : Main Loop : AAF_App()
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
static void Motor_Action(void)
{
    // 1. Manage start/stop flags
    Motor_ManageStartStatus();

    // 2. Handle wait time and acceleration
    if (G_Timer1ms.MotorDelay >= MOTOR_WAIT_TIME)
    {
        Motor_SoftStart();
    }
    else 
    {
        motor_wait_chk = OFF;
    }

    // 3. Generate step pulses
    Motor_GenerateStepPulse();
}

/***********************************************************************************************************************
 * Function Name: Motor_ManageStartStatus
 * Description  : Manages flags and timers based on the motor start state (ON/OFF).
 * Called By    : Motor_Action
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
static void Motor_ManageStartStatus(void)
{
    if (motor_start == ON)
    {
        G_Timer1msFlag.MotorDelayFlag = 1U;
    }
    else if (motor_start == OFF)
    {
        G_Timer1msFlag.MotorDelayFlag = 0U;
        G_Timer1ms.MotorDelay = 0U;
        G_Timer1usFlag.MotorFlag = 0U;
        G_Timer1us.Motor = 0U;
        G_Timer1msFlag.MotorAccelerationFlag = 0U;
        G_Timer1ms.MotorAcceleration = 0U;
    }
    else
    {
        // Invalid
    }
}

/***********************************************************************************************************************
 * Function Name: Motor_SoftStart
 * Description  : Handles the currently active motor acceleration logic (1000RPM -> 1250RPM).
 * Called By    : Motor_Action
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
static void Motor_SoftStart(void)
{
    // Development START
    if ((AAF_Tx_Position != UNKOWN_POSITION) && (Diag_Mode == 0U)) 
    {
        AAFx_Position_Status = FlapMoving_Status;
    }
    else if (AAF_Tx_Position == UNKOWN_POSITION)
    {
        AAFx_Position_Status = Unknown_Status;
    }
    else
    {
        // Invalid
    }
    // Development END

    motor_wait_chk = ON;
    G_Timer1msFlag.StallTimeFlag = ON;
    G_Timer1msFlag.MotorAccelerationFlag = 1U;

    Motor_StagedSoftStart(); //not used

    // Active acceleration logic
    if (((motor_step_value <= STEP_TIME_1000RPM) && (motor_step_value > STEP_TIME_1250RPM)) && (G_Timer1ms.MotorAcceleration >= 10))
    {
        motor_step_value--;
        G_Timer1ms.MotorAcceleration = 0U;
    }
    else
    {
        motor_step_value = STEP_TIME_1250RPM;
        G_Timer1ms.MotorAcceleration = 0U;
        softstart_complete = ON;
    }

    G_Timer1ms.MotorDelay = MOTOR_WAIT_TIME;
}

/***********************************************************************************************************************
 * Function Name: Motor_StagedSoftStart
 * Description  : Handles the legacy detailed soft-start acceleration logic (Previously commented out).
 * Called By    : Motor_SoftStart (Currently commented out)
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
static void Motor_StagedSoftStart(void)
{
    // if (((motor_step_value <= STEP_TIME_1000RPM) && (motor_step_value > STEP_TIME_1250RPM)) && (G_Timer1ms.MotorAcceleration >= 4))
    // {
    //     motor_step_value--;
    //     G_Timer1ms.MotorAcceleration = 0;
    // }
    // else if (((motor_step_value <= STEP_TIME_1250RPM) && (motor_step_value > STEP_TIME_1500RPM)) && (G_Timer1ms.MotorAcceleration >= 6))
    // {
    //     motor_step_value--;
    //     G_Timer1ms.MotorAcceleration = 0;
    // }
    // else if (((motor_step_value <= STEP_TIME_1500RPM) && (motor_step_value > STEP_TIME_1575RPM)) && (G_Timer1ms.MotorAcceleration >= 8))
    // {
    //     motor_step_value--;
    //     G_Timer1ms.MotorAcceleration = 0;
    // }
    // else if (motor_step_value <= STEP_TIME_1575RPM)
    // {
    //     motor_step_value = STEP_TIME_1575RPM;
    //     softstart_complete = ON;
    // }
    // else
    // {
    //     // Invalid
    // }
}

/***********************************************************************************************************************
 * Function Name: Motor_GenerateStepPulse
 * Description  : Toggles the GPIO pin to generate motor steps and updates the position counter.
 * Called By    : Motor_Action
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
static void Motor_GenerateStepPulse(void)
{
    if ((motor_wait_chk == ON) && (voltage_status_change_complete == COMPLETE))
    {
        if (pwm_flag == OFF)
        {
            R_Config_TAUJ1_Start();
            pwm_flag = ON;
        }
    }
    else
    {
        if (pwm_flag == ON)
        {
            R_Config_TAUJ1_Stop();
            pwm_flag = OFF;
        }
    }
}

/***********************************************************************************************************************
 * Function Name: App_MotorAction
 * Description  : Handles protection timer and executes motor movement (Action Logic).
 * Called By    : AAF_App
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
void App_MotorAction(void)
{
    // 1. Protection Timer Clamp (Max 550ms)
    if (G_Timer1ms.ProtectionCheck >= 550U) 
    {
        G_Timer1msFlag.ProtectionCheckFlag = 0U;
        G_Timer1ms.ProtectionCheck = 550U;
    }

    // 2. Motor Execution (Start after 50ms)
    if (G_Timer1ms.ProtectionCheck >= 50U)
    {
        Motor_Action();
    }
}

void Motor_Open(void)
{
	if (AAF_location_type == RH_TYPE)
	{
		Drv8889_DirCCW(); // CCW
		dir_state = OPEN;
	}
	else if (AAF_location_type == LH_TYPE)
	{
		Drv8889_DirCW(); // CW
		dir_state = OPEN;
	}
	else
	{
        //invaild
	}
}

void Motor_Open2(void)
{
	if (AAF_location_type == RH_TYPE)
	{
		Drv8889_DirCCW(); // CCW
		dir_state = OPEN;
	}
	else if (AAF_location_type == LH_TYPE)
	{
		Drv8889_DirCW(); // CW
		dir_state = OPEN;
	}
	else
	{
        //invaild
	}
}


void Motor_Close(void)
{
	if (AAF_location_type == RH_TYPE)
	{
		Drv8889_DirCW(); // MCU_DIR
		dir_state = CLOSE;
	}
	else if (AAF_location_type == LH_TYPE)
	{
		Drv8889_DirCCW(); // MCU_DIR
		dir_state = CLOSE;
	}
	else
	{
		//invaild
	}
}

void Motor_Close2(void)
{
	if (AAF_location_type == RH_TYPE)
	{
		Drv8889_DirCW(); // MCU_DIR
		dir_state = CLOSE;
	}
	else if (AAF_location_type == LH_TYPE)
	{
		Drv8889_DirCCW(); // MCU_DIR
		dir_state = CLOSE;
	}
	else
	{
		//invaild
	}
}
