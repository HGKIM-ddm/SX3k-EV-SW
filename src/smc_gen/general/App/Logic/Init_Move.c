#include "Init_Move.h"
#include "Service.h"

/***********************************************************************************************************************
 * Function Name: Init_StartMotor
 * Description  : Start the motor drive, initialize the relevant variables and move on to the next step
 * Called By    : Process_init_step_0_to_9
 * Arguments    : next_step - Next Case
 * dir       - Motor Drive Direction (OPEN / CLOSE)
 * is_case0  - first entry (Case 0) or not (TRUE: Perform additional initialization / FALSE: not)
 * Return Value : void
 ***********************************************************************************************************************/
static void Init_StartMotor(uint8_t next_step, uint8_t dir, uint8_t is_case0)
{
    if (dir == OPEN) Motor_Open2();
    else             Motor_Close2();

    Drv8889_On();
    motor_start = ON;
    
    // (Case 0, 6, 9)
    motor_stall_flag = MOTOR_NORMAL;
    G_Timer1ms.StallTime = 0U;
    G_Timer1ms.TrqCheck = 0U;
    AAF_Tx_Position = UNKOWN_POSITION;
    AAFx_Position_Status = Unknown_Status;
    antipinch_previous_action = INITIALIZATION;
    G_Timer1ms.InitCheck = 0U;
    G_Timer1msFlag.InitCheckFlag = 1U; 

    // (Case 0)
    if (is_case0 == TRUE)
    {
        G_Timer1msFlag.External10sCheckFlag = OFF;
        G_Timer1ms.External10sCheck = 0U;
        step_position = REFERENCE_POSITION;
    }

    init_move_step = next_step;
}


/***********************************************************************************************************************
 * Function Name: Init_StallCheck
 * Called By: Init_move (Case 4, 7, 10)
 * next_step: next case
 * retry_step: Steps to move in case of failure (timeout)
 * dir: OPEN, CLOSE DIRECTION
 ***********************************************************************************************************************/
static void Init_StallCheck(uint8_t next_step, uint8_t retry_step, uint8_t dir)
{
    if ((motor_stall_flag == MOTOR_STALL) || (G_Timer1ms.InitCheck >= 8000U))
    {
        Drv8889_Off();
        motor_start = OFF;
        
        if (dir == CLOSE) 
        {
            step_position_close = step_position;

        }
        else // dir == OPEN
        {
            step_position_open = step_position;

        }

        G_Timer1msFlag.StallTimeFlag = 0U;
        G_Timer1ms.StallTime = 0U;
        softstart_complete = OFF;
        G_Timer1msFlag.InitFailCheckFlag = 0U;
        G_Timer1ms.InitFailCheck = 0U;

        init_move_step = next_step;
    }
    else
    {
        //invaild
    }
}

/***********************************************************************************************************************
 * Function Name: Init_Delay
 * Description  : Wait 100 ms and move to the next step (Step 5, 8, 11 common)
 * Called By    : Process_init_step_0_to_9, Process_init_step_10_to_15
 * Arguments    : next_step - next case
 * Return Value : void
 ***********************************************************************************************************************/
static void Init_Delay(uint8_t next_step)
{
    G_Timer1msFlag.InitMoveFlag = 1U;

    if (G_Timer1ms.InitMove >= 100U)
    {
        G_Timer1msFlag.InitMoveFlag = 0U;
        G_Timer1ms.InitMove = 0U;
        init_move_step = next_step;

        G_Timer1msFlag.InitCheckFlag = 0U; 
        G_Timer1ms.InitCheck = 0U;      
    }
}

/***********************************************************************************************************************
 * Function Name: Init_MoveLimitPosition
 * Description  : Calculate the target position based on the entire learned stroke and start moving to that position
 * Called By    : Init_move (Case 13)
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
static void Init_MoveLimitPosition(void)
{
	if (step_position <= step_position_open + limit_step_position)
	{
		Motor_Close2();						 // dir CLOSE
		Drv8889_On();							 // drv on
		motor_start = ON;					 // step start
		//G_Timer1msFlag.External10sCheckFlag = ON; // 10s chk timer on

		motor_stall_flag = MOTOR_NORMAL; // stall reset
		// G_Timer1msFlag.StallTimeFlag = 0;			 stall reset
		G_Timer1ms.StallTime = 0U;							  // stall reset
		G_Timer1ms.TrqCheck = 0U;

		init_move_step = 14U;
	}
	else
	{
		// G_Timer1msFlag.External10sCheckFlag = ON; // 10s chk timer on

		init_move_step = 14U;
	}
}

/***********************************************************************************************************************
 * Function Name: Init_CheckLimitArrival
 * Description  : Monitor for target position reach or abnormal stall occurrence on the move
 * Called By    : Init_move (Case 14)
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
static void Init_CheckLimitArrival(void)
{
    // check stall
    uint8_t is_stall_error = ((motor_stall_flag == MOTOR_STALL) || 
                              ((step_position_close - step_position_open) <= STEP_POSITION_MINIMUM_RANGE)) && 
                             (stall_test_mode == 0U);

    // stall or obd
    if (is_stall_error)
    {
        Drv8889_Off();
        motor_start = OFF;
        softstart_complete = OFF;
        G_Timer1msFlag.InitFailCheckFlag = 0U;
        G_Timer1ms.InitFailCheck = 0U;
        
        if (fail_safety_step == 0U) { fail_safety_flag = ON; }
        if (fail_safety_step == 4U) { fail_safety_step = 5U; }
        else if (fail_safety_step == 9U) { fail_safety_step = 10U; }
    }
    else if (step_position >= step_position_open + limit_step_position)
    {
        Drv8889_Off();
        motor_start = OFF;
        G_Timer1msFlag.StallTimeFlag = 0U;
        G_Timer1ms.StallTime = 0U; 
        G_Timer1msFlag.External10sCheckFlag = OFF;
        G_Timer1ms.External10sCheck = 0U;
        softstart_complete = OFF;
        G_Timer1msFlag.InitFailCheckFlag = 0U;
        G_Timer1ms.InitFailCheck = 0U;

        init_move_step = 15U;
    }
    else
    {
        G_Timer1msFlag.InitFailCheckFlag = 1U;
        if (G_Timer1ms.InitFailCheck >= 5000U)
        {
            init_move_step = 0U;
            G_Timer1msFlag.InitFailCheckFlag = 0U;
            G_Timer1ms.InitFailCheck = 0U;
        }
    }
}

/***********************************************************************************************************************
 * Function Name: InitMove_Cycle1
 * Description  : case 0 ~ 9
 * Called By    : Init_move 
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
static void InitMove_Cycle1(void)
{
    switch (init_move_step)
    {
    case 0:
        Init_StartMotor(4U, OPEN, TRUE); // go case 4
        break;
    case 4:
        Init_StallCheck(5U, 0U, OPEN); // go case 5 return case 0
        break;
    case 5:
        Init_Delay(6U);
        break;
    case 6:
        Init_StartMotor(7U, CLOSE, FALSE);
        break;
    case 7:
        Init_StallCheck(8U, 6U, CLOSE);
        break;
    case 8:
        Init_Delay(9U);
        break;
    case 9:
        Init_StartMotor(10U, OPEN, FALSE);
        break;
    default:
        break;
    }
}

/***********************************************************************************************************************
 * Function Name: InitMove_Cycle2
 * Description  : case 10 ~ 15
 * Called By    : Init_move 
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
static void InitMove_Cycle2(void)
{
    switch (init_move_step)
    {
    case 10:
        Init_StallCheck(11U, 9U, OPEN);
        break;
    case 11:
        Init_Delay(12U);
        break;
    case 12:
        limit_step_position = (step_position_close - step_position_open) * AAF_ERROR_ANGLE / AAF_FULL_ANGLE;
		init_move_step = 13U;
        break;
    case 13:
        Init_MoveLimitPosition();
        break;
    case 14:
        Init_CheckLimitArrival();
        break;
    case 15:
        G_Timer1msFlag.InitMoveFlag = 1U;
        if (G_Timer1ms.InitMove >= 500U)
        {
			wake_up_motor_range_init_chk = COMPLETE;
			G_Timer1msFlag.InitMoveFlag = 0U;
			G_Timer1ms.InitMove = 0U;
			evrdy_on_flag = ON;
			motor_Short_chk_count = 0U;
			motor_Open_chk_count = 0U;
			init_move_step = 19U;
        }
        break;
    default:
        break;
    }
}

void Init_move(void)
{
    if (init_move_step < 10U)
    {
        InitMove_Cycle1();
    }
    else
    {
        InitMove_Cycle2();
    }
}


