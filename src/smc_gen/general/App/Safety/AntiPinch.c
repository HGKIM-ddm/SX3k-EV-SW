#include "AntiPinch.h"
#include "Service.h"
/* =========================================================================================
 * Anti-Pinch Movement Helper Functions
 * ========================================================================================= */

/***********************************************************************************************************************
 * Function Name: Antipinch_PrevOpen
 * Description  : 이전에 OPEN 동작 중 끼임이 발생했을 때의 복구 시퀀스 (Close -> Wait -> Open)
 * Called By    : Antipinch_Move
 ***********************************************************************************************************************/
static void Antipinch_PrevOpen(void)
{
    switch (antipinch_step)
    {
    case 0:
        Motor_Close();                
        Drv8889_On2();                       
        motor_start = ON;               
        G_Timer1msFlag.InitCheckFlag = 1U;     

        aaf_action = CLOSE;
        AAFx_ErrorStatus = Open_ErrorStatus; 
        G_Timer1ms.Spi = 0U;               
        motor_stall_flag = MOTOR_NORMAL; 
        antipinch_step = 1U;
        break;

    case 1:
        if ((motor_stall_flag == MOTOR_STALL) || (G_Timer1ms.InitCheck >= 4500U)) 
        {
            Drv8889_Off();
            motor_start = OFF;
            G_Timer1msFlag.StallTimeFlag = 0U;
            G_Timer1ms.StallTime = 0U; 
            softstart_complete = OFF;
            motor_step_value = STEP_TIME_1000RPM;
            aaf_action = FLAP_STOP;
            G_Timer1msFlag.InitCheckFlag = 0U;
            G_Timer1ms.InitCheck = 0U;
            
            if (step_position >= step_position_close)
            {
                step_position = step_position_close;
            }

            antipinch_step = 2U;
        }
        break;

    case 2:
        G_Timer1msFlag.AntipinchCheckFlag = 1U;

        if (G_Timer1ms.AntipinchCheck >= 3000U)
        {
            G_Timer1msFlag.AntipinchCheckFlag = 0U;
            G_Timer1ms.AntipinchCheck = 0U;

            antipinch_step = 3U;
        }
        break;

    case 3:
        Motor_Open();    
        Drv8889_On2();         
        motor_start = ON; 

        G_Timer1ms.StallTime = 0U;                                           
        TRQ_COUNT = MOTOR_STALL_CHK_NORMAL_VALUE; 
        motor_stall_flag = MOTOR_NORMAL;                  
        G_Timer1ms.Spi = 0U;
        aaf_action = OPEN;

        G_Timer1msFlag.InitCheckFlag = 1U; 

        antipinch_step = 4U;
        break;

    case 4:
        if ((aaf_action == OPEN) && (step_position <= step_position_open + limit_step_position))
        {
            Drv8889_Off();
            motor_start = OFF;
            
            // 진단 모드 여부에 따른 분기
            if (Diag_Mode != 0U)
            {
                if (lin_aaf_command == DIAG_MODE_OPEN)
                {
                    aaf_action = DIAG_MODE_OPEN;
                    aaf_step = AAF_WAITING;
                    AAFx_ErrorStatus = No_ErrorStatus;
                    AAFx_InitStatus = NORMAL_FINISHED_INITIALIZATION;
                    Operate_SelectTxPostion();
                }
                else if (lin_aaf_command == DIAG_MODE_AUTO)
                {
                    aaf_action = DIAG_MODE_AUTO;
                    aaf_step = AAF_WAITING;
                    AAFx_ErrorStatus = No_ErrorStatus;
                    AAFx_InitStatus = NORMAL_FINISHED_INITIALIZATION;
                    Operate_SelectTxPostion();
                }
                else
                {
                    // invalid
                }
            }
            else
            {
                AAF_Tx_Position = OPEN;
                AAFx_InitStatus = NORMAL_FINISHED_INITIALIZATION;
                AAFx_ErrorStatus = No_ErrorStatus;
                Operate_SelectTxPostion();
            }

            fail_safety_flag = OFF;
            antipinch_action_on = OFF;

            G_Timer1msFlag.StallTimeFlag = 0U;
            G_Timer1ms.StallTime = 0U;
            softstart_complete = OFF;
            motor_step_value = STEP_TIME_1000RPM;

            antipinch_previous_action = ANTIWAIT;
            antipinch_step = 0U;

            aaf_step = FINISHED_OPERATE;
        }
        else if ((motor_stall_flag == MOTOR_STALL) || (G_Timer1ms.InitCheck >= 4500U))
        {
            Drv8889_Off();
            motor_start = OFF;
            G_Timer1msFlag.StallTimeFlag = 0U;
            G_Timer1ms.StallTime = 0U;
            softstart_complete = OFF;
            motor_step_value = STEP_TIME_1000RPM;

            G_Timer1msFlag.InitCheckFlag = 0U;
            G_Timer1ms.InitCheck = 0U;

            antipinch_previous_action = INITIALIZATION;
            antipinch_action_on = OFF;

            if (Diag_Mode != 0U)
            {
                AAFx_InitStatus = ABNORMAL_FINISHED_INITIALIZATION;
                motor_fault_chk = 1U;
                Diag_Mode = 0U;
            }
            else
            {
                fail_safety_flag = ON;
                fail_safety_step = 2U;
            }
        }
        break;

    default:
        break;
    }
}

/***********************************************************************************************************************
 * Function Name: Antipinch_PrevClose
 * Description  : 이전에 CLOSE 동작 중 끼임이 발생했을 때의 복구 시퀀스 (Open -> Wait -> Close)
 * Called By    : Antipinch_Move
 ***********************************************************************************************************************/
static void Antipinch_PrevClose(void)
{
    AAFx_InitStatus = DURING_INITIALIZATION; 

    switch (antipinch_step)
    {
    case 0:
        Motor_Open();   
        Drv8889_On2();       

        G_Timer1ms.StallTime = 0U; 

        motor_start = ON;                
        G_Timer1msFlag.InitCheckFlag = 1U;      
        motor_stall_flag = MOTOR_NORMAL; 
        G_Timer1ms.Spi = 0U;

        aaf_action = OPEN;
        AAFx_ErrorStatus = Close_ErrorStatus; 
        antipinch_step = 1U;
        break;

    case 1:
        if ((motor_stall_flag == MOTOR_STALL) || (G_Timer1ms.InitCheck >= 4500U))
        {
            Drv8889_Off();
            motor_start = OFF;
            G_Timer1msFlag.StallTimeFlag = 0U;
            G_Timer1ms.StallTime = 0U; 
            softstart_complete = OFF;
            motor_step_value = STEP_TIME_1000RPM;

            G_Timer1msFlag.InitCheckFlag = 0U;
            G_Timer1ms.InitCheck = 0U;
            
            if (step_position <= step_position_open)
            {
                step_position = step_position_open;
            }

            aaf_action = FLAP_STOP;
            antipinch_step = 2U;
        }
        break;

    case 2:
        G_Timer1msFlag.AntipinchCheckFlag = 1U;

        if (G_Timer1ms.AntipinchCheck >= 3000U)
        {
            G_Timer1msFlag.AntipinchCheckFlag = 0U;
            G_Timer1ms.AntipinchCheck = 0U;
            antipinch_step = 3U;

            G_Timer1msFlag.InitCheckFlag = 0U; 
            G_Timer1ms.InitCheck = 0U;      
        }
        break;

    case 3:
        Motor_Close();   
        Drv8889_On2();        
        motor_start = ON; 
        motor_stall_flag = MOTOR_NORMAL; 

        G_Timer1ms.StallTime = 0U;                                           
        TRQ_COUNT = MOTOR_STALL_CHK_NORMAL_VALUE; 
        G_Timer1ms.Spi = 0U;

        aaf_action = CLOSE;
        G_Timer1msFlag.InitCheckFlag = 1U; 
        antipinch_step = 4U;
        break;

    case 4:
        if ((aaf_action == CLOSE) && (step_position >= step_position_close - limit_step_position))
        {
            Drv8889_Off();
            motor_start = OFF;

            if (Diag_Mode != 0U)
            {
                if (lin_aaf_command == DIAG_MODE_CLOSE)
                {
                    aaf_action = DIAG_MODE_CLOSE;
                    aaf_step = AAF_WAITING;
                    AAFx_ErrorStatus = No_ErrorStatus;
                    AAFx_InitStatus = NORMAL_FINISHED_INITIALIZATION;
                    Operate_SelectTxPostion();
                }
                else if (lin_aaf_command == DIAG_MODE_AUTO)
                {
                    aaf_action = DIAG_MODE_AUTO;
                    aaf_step = AAF_WAITING;
                    AAFx_ErrorStatus = No_ErrorStatus;
                    AAFx_InitStatus = NORMAL_FINISHED_INITIALIZATION;
                    Operate_SelectTxPostion();
                }
                else
                {
                    // invalid
                }
            }
            else
            {
                AAF_Tx_Position = CLOSE;
                AAFx_InitStatus = NORMAL_FINISHED_INITIALIZATION;
                AAFx_ErrorStatus = No_ErrorStatus;
                Operate_SelectTxPostion();
            }

            fail_safety_flag = OFF;
            antipinch_action_on = OFF;

            G_Timer1msFlag.StallTimeFlag = 0U;
            G_Timer1ms.StallTime = 0U;
            softstart_complete = OFF;
            motor_step_value = STEP_TIME_1000RPM;

            antipinch_previous_action = ANTIWAIT;
            antipinch_step = 0U;

            aaf_step = FINISHED_OPERATE;
        }
        else if ((motor_stall_flag == MOTOR_STALL) || (G_Timer1ms.InitCheck >= 4500U))
        {
            Drv8889_Off();
            motor_start = OFF;
            G_Timer1msFlag.StallTimeFlag = 0U;
            G_Timer1ms.StallTime = 0U;
            softstart_complete = OFF;
            motor_step_value = STEP_TIME_1000RPM;

            G_Timer1msFlag.InitCheckFlag = 0U;
            G_Timer1ms.InitCheck = 0U;

            aaf_action = FLAP_STOP;
            antipinch_step = 5U;
        }
        break;

    case 5:
        Motor_Open();    
        Drv8889_On2();         
        motor_start = ON; 
        G_Timer1msFlag.InitCheckFlag = 1U; 
        aaf_action = OPEN;
        motor_stall_flag = MOTOR_NORMAL; 
        G_Timer1ms.Spi = 0U;

        G_Timer1ms.StallTime = 0U;                                           
        TRQ_COUNT = MOTOR_STALL_CHK_NORMAL_VALUE; 

        antipinch_step = 6U;
        break;

    case 6:
        if ((motor_stall_flag == MOTOR_STALL) || (G_Timer1ms.InitCheck >= 4500U))
        {
            Drv8889_Off();
            motor_start = OFF;
            G_Timer1msFlag.StallTimeFlag = 0U;
            G_Timer1ms.StallTime = 0U; 
            softstart_complete = OFF;
            motor_step_value = STEP_TIME_1000RPM;

            aaf_action = FLAP_STOP;
            G_Timer1msFlag.InitCheckFlag = 0U;
            G_Timer1ms.InitCheck = 0U;

            antipinch_step = 7U;

            // fail_safety_flag = ON;
            antipinch_action_on = OFF;

            antipinch_previous_action = INITIALIZATION;

            G_Timer1msFlag.External10sCheckFlag = OFF; 
            G_Timer1ms.External10sCheck = 0U;
            aaf_action = FLAP_STOP;
            aaf_action_complete_chk = FLAP_STOP;

            G_Timer1ms.StallCheck = 0U;      
            G_Timer1msFlag.StallCheckFlag = 0U; 

            TRQ_COUNT = MOTOR_STALL_CHK_NORMAL_VALUE; 

            if (Diag_Mode != 0U)
            {
                AAFx_InitStatus = ABNORMAL_FINISHED_INITIALIZATION;
                motor_fault_chk = 1U;
                Diag_Mode = 0U;
            }
            else
            {
                fail_safety_flag = ON;
                fail_safety_step = 2U;
            }
        }
        break;

    default:
        break;
    }
}

/* =========================================================================================
 * Main Anti-Pinch Function
 * ========================================================================================= */

/***********************************************************************************************************************
 * Function Name: Antipinch_Move
 * Description  : Anti-Pinch(끼임 방지) 동작 시퀀스 제어. 이전 동작 방향에 따라 반대 방향으로 회피 구동함.
 * Called By    : Main Loop (Operating_mode)
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
void Antipinch_Move(void)
{
    if (antipinch_action_on == ON)
    {
        AAFx_Position_Status = Unknown_Status;
        AAF_Tx_Position = UNKOWN_POSITION;
        AAFx_InitStatus = DURING_INITIALIZATION;
        
        if (antipinch_previous_action == OPEN)
        {
            Antipinch_PrevOpen();
        }
        else if (antipinch_previous_action == CLOSE)
        {
            Antipinch_PrevClose();
        }
        else
        {
            // invalid
        }
    }
}
