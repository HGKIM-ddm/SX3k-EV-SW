#include "Protection_Mode.h"
#include "Service.h"

/***********************************************************************************************************************
 * Function Name: Protection_Reset
 * Description  : Protection Mode 진입 시 초기화 수행 (Case 0)
 * Called By    : Protection_Cycle1
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
static void Protection_Reset(void)
{
    Motor_Off();
    motor_start = OFF;
    G_Timer1msFlag.StallTimeFlag = 0U;
    G_Timer1ms.StallTime = 0U; // stall reset
    protection_Mode_step = 1U;
    G_Timer1msFlag.ProtectionModeFlag = 1U;
    aaf_action = FLAP_STOP;
    softstart_complete = OFF;
}

/***********************************************************************************************************************
 * Function Name: Protection_Delay
 * Description  : 100ms 대기 후 다음 단계로 이동 (Case 1)
 * Called By    : Protection_Cycle1
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
static void Protection_Delay(void)
{
    if (G_Timer1ms.ProtectionMode >= 100U)
    {
        G_Timer1msFlag.ProtectionModeFlag = 0U;
        G_Timer1ms.ProtectionMode = 0U;
        protection_Mode_step = 2U;
    }
}

/***********************************************************************************************************************
 * Function Name: Protection_StartMotor
 * Description  : 조건 확인 후 모터 Open 구동 시작 (Case 2)
 * Called By    : Protection_Cycle2
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
static void Protection_StartMotor(void)
{
    // if(((adc_avr >= ADC_UNDER_VOLTAGE_7V) && (adc_avr <= ADC_UNDER_VOLTAGE_9V)) || ((adc_avr >= ADC_OVER_VOLTAGE_16V) && (adc_avr <= ADC_OVER_VOLTAGE_18V)) || (AAF_ProtectionMode_Rx == ON))
    // if(((adc_avr >= ADC_OVER_VOLTAGE_16V) && (adc_avr <= ADC_OVER_VOLTAGE_18V)) || (AAF_ProtectionMode_Rx == ON) && (AAF_Tx_Position != OPEN))   
    if ((AAF_Tx_Position != OPEN))
	{
        Motor_Open2();                    // dir OPEN
       	Motor_On();                        // drv on
        motor_start = ON;                // step start
        G_Timer1msFlag.StallCheckFlag = ON;    // test
        motor_stall_flag = MOTOR_NORMAL; // stall reset
        G_Timer1ms.StallTime = 0U;          // stall reset
        protection_Mode_step = 3U;
        G_Timer1msFlag.InitCheckFlag = 1U; // test
    }
    else
    {
        G_Timer1msFlag.InitCheckFlag = 0U;
        protection_Mode_step = 4U;
    }
}

/***********************************************************************************************************************
 * Function Name: Protection_StallCheck
 * Description  : 목표 위치 도달 또는 스톨 발생 시 정지 (Case 3)
 * Called By    : Protection_Cycle2
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
static void Protection_StallCheck(void)
{
    // if ((motor_stall_flag == MOTOR_STALL) || (G_Timer1ms.InitCheck >= 4500U))
    if ((step_position <= (step_position_open + limit_step_position)) || (motor_stall_flag == MOTOR_STALL))
    {
        Motor_Off();
        motor_start = OFF;
        G_Timer1msFlag.StallTimeFlag = 0U;
        G_Timer1ms.StallTime = 0U; // stall reset
        G_Timer1msFlag.InitCheckFlag = 0U;
        G_Timer1ms.InitCheck = 0U;
        AAF_Tx_Position = UNKOWN_POSITION;
        AAFx_InitStatus = DURING_INITIALIZATION;
        AAFx_Position_Status = Unknown_Status;
        softstart_complete = OFF;
        protection_Mode_step = 4U;
    }
}

/***********************************************************************************************************************
 * Function Name: Protection_UpdateFinal
 * Description  : Protection Mode 최종 상태 업데이트 (Case 4)
 * Called By    : Protection_Cycle2
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
static void Protection_UpdateFinal(void)
{
    AAF_Tx_Position = UNKOWN_POSITION;
    AAFx_InitStatus = DURING_INITIALIZATION;
    AAFx_Position_Status = Unknown_Status;
    // FDL_Write();
    if ((protection_function == OFF) && (voltage_protection_function == OFF)) 
    {
        protection_Mode_step = 5U;
    }
}

static void Protection_WaitOff(void)
{
    Re_Init();
    protection_Mode_step = 0U;
}

static void Protection_Cycle1(void)
{
    switch (protection_Mode_step)
    {
    case 0:
        Protection_Reset();
        break;
    case 1:
        Protection_Delay();
        break;
    default:
        break;
    }
}

static void Protection_Cycle2(void)
{
    switch (protection_Mode_step)
    {
    case 2:
        Protection_StartMotor();
        break;
    case 3:
        Protection_StallCheck();
        break;
    case 4:
        Protection_UpdateFinal();
        break;
    case 5:
        Protection_WaitOff();
        break;    
    default:
        break;
    }
}

/***********************************************************************************************************************
 * Function Name: Protection_Mode
 * Description  : Protection Mode 동작 시퀀스 제어
 * Metric Info  : FUCYC = 3 (Pass), FUNDC = 2 (Pass)
 * Called By    : Main Loop
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
void Protection_Mode(void)
{
    if (stall_test_mode == 0U)
    {
        // Step 0 ~ 1: 준비 및 대기
        if (protection_Mode_step <= 1U)
        {
            Protection_Cycle1();
        }
        // Step 2 ~ 4: 동작 및 완료
        else
        {
            Protection_Cycle2();
        }
    }
}

/***********************************************************************************************************************
 * Function Name: Protection_CheckCondition
 * Description  : Protection Mode 진입/해제 조건 판단
 * Called By    : Main Loop (Protection_Mode 호출 전)
 ***********************************************************************************************************************/
void ProtectionMode_Check(void)
{
    /* Protection ON 요청 수신 시 모드 진입 */
    if ((AAF_ProtectionMode_Rx == ON) && (protection_function == OFF))
    {
        protection_function = ON;
        AAF_ProtectionMode_Tx = ON;
        protection_Mode_step = 0U;  /* 시퀀스 재시작 */
    }
    /* Protection OFF 요청 수신 시 모드 해제 */
    else if ((AAF_ProtectionMode_Rx == OFF) && (protection_function == ON))
    {
        protection_function = OFF;
        AAF_ProtectionMode_Tx = OFF;
    }
}


