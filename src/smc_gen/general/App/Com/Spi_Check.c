#include "Spi_Check.h"
#include "Service.h"

/* =========================================================================================
 * SPI Communication & Stall Check Functions
 * ========================================================================================= */
/*----------------------------------------------------------------------------*/
/* Static Functions Prototype                                                 */
/*----------------------------------------------------------------------------*/
static void SpiCheck_ExecuteVoltageChange(void);
static void SpiCheck_SendCommand(void);
static void SpiCheck_Delay(void);
static void SpiCheck_Delay2(void);
static void SpiCheck_HandleData(void);
static void SpiCheck_Init(void);
static void SpiCheck_CurrentLimitingSelect(void);

/***********************************************************************************************************************
 * Function Name: SpiCheck_ExecuteVoltageChange
 * Description  : Sends SPI commands to update current limits when voltage status changes (Step 0 Condition 1).
 * Called By    : SpiCheck_Init
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
static void SpiCheck_ExecuteVoltageChange(void)
{
    Drv8889_ScsActive(); // CS Low

    if (voltage_status_spi == NORMAL_VOLTAGE)
    {
        Drv8889_WriteCtrl1(TRQ_DAC_68_75, SLEW_RATE_10V);
    }
    else if (voltage_status_spi == LOW_VOLTAGE)
    {
        Drv8889_WriteCtrl1(TRQ_DAC_68_75, SLEW_RATE_10V);
    }   
    else if (voltage_status_spi == HIGH_VOLTAGE)
    {   
        Drv8889_WriteCtrl1(TRQ_DAC_68_75, SLEW_RATE_10V);
    }
    else
    {
        /* Invalid */
    }

    voltage_status_change_complete = WAIT;
    G_Timer1msFlag.VoltStatChangeDelayFlag = 1U;
    spi_action_step = 1U;
    voltage_status_change = OFF;
}

/***********************************************************************************************************************
 * Function Name: SpiCheck_SendCommand
 * Description  : Sends the standard SPI command (ID 9) for status monitoring (Step 0 Condition 2 & 3).
 * Called By    : SpiCheck_Init
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
static void SpiCheck_SendCommand(void)
{
    Drv8889_ScsActive(); // CS Low

    R_Config_CSIH0_Send_Receive(&rx_16bit_spi_id[9], 1U, &rx_16bit_spi[9], _CSIH_SELECT_CHIP_0);

    spi_action_step = 1U;
}

/***********************************************************************************************************************
 * Function Name: SpiCheck_Delay
 * Description  : Waits for SPI transmission/reception completion or timeout (Step 1).
 * Called By    : Spi_Check
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
static void SpiCheck_Delay(void)
{
    G_Timer1msFlag.SpiErrorCheckFlag = 1U;

    // Check for successful completion
    if ((spi_receive_flag >= 1U) && (spi_send_flag >= 1U))
    {
        spi_receive_flag = 0U;
        spi_send_flag = 0U;

        Drv8889_ScsInactive(); // CS High

        G_Timer1ms.SpiErrorCheck = 0U;
        G_Timer1msFlag.SpiErrorCheckFlag = 0U;

        spi_action_step = 2U;
    }

    // Check for timeout
    if (G_Timer1ms.SpiErrorCheck >= 100U)
    {
        spi_action_step = 2U;
        // DRV_Off();
        
        // spi_fail = 1; 
        
        G_Timer1ms.SpiErrorCheck = 0U;
        G_Timer1msFlag.SpiErrorCheckFlag = 0U;
    }
}

/***********************************************************************************************************************
 * Function Name: SpiCheck_Delay2
 * Description  : Provides a short delay (2us) between SPI transactions (Step 2).
 * Called By    : Spi_Check
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
static void SpiCheck_Delay2(void)
{
    G_Timer1usFlag.SpiFlag = 1U;

    if (G_Timer1us.Spi >= 2U)
    {
        G_Timer1usFlag.SpiFlag = 0U;
        G_Timer1us.Spi = 0U;

        spi_action_step = 3U;
    }
}

/***********************************************************************************************************************
 * Function Name: SpiCheck_HandleData
 * Description  : Processes received SPI data and performs stall checking (Step 3).
 * Called By    : Spi_Check
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
static void SpiCheck_HandleData(void)
{
    /* 1. 변수 파싱 */
    TRQ_COUNT = (unsigned int)(rx_16bit_spi[9] & 0xFFU);
    AAF_UVLO        = rx_16bit_spi[9] & 0x2000U;  /* B13 저전압 */
    AAF_CPUV        = rx_16bit_spi[9] & 0x1000U;  /* B12 차지펌프 저전압 */
    AAF_OverCurrent = rx_16bit_spi[9] & 0x0800U;  /* B11 OCP */
    AAF_HW_Stall    = rx_16bit_spi[9] & 0x0400U;  /* B10 STL (HW스톨) */
    AAF_OverTemp    = rx_16bit_spi[9] & 0x0200U;  /* B9  TF 과열 */
    AAF_OpenLoad    = rx_16bit_spi[9] & 0x0100U;  /* B8  OL */

    // if (AAF_Tx_Position == DIAG_MODE_AUTO) {
    //     if (TRQ_COUNT_Index < 4000U){
    //         TRQ_COUNT_Buffer[TRQ_COUNT_Index] = TRQ_COUNT;
    //         TRQ_COUNT_Index++;
    //     }
    // }

    #ifdef ENABLE_TORQUE_LIN_COMMUNICATION

    if (TRQ_COUNT_LogEnable == 1U)
    {
        // 모터 구동 중 2ms마다 여기가 호출됨
        if (TRQ_COUNT_Index < 4000U)
        {
            TRQ_COUNT_Buffer[TRQ_COUNT_Index] = TRQ_COUNT;
            TRQ_COUNT_Index++;
        }
        else
        {
            // 4000개가 넘어가면(약 8초) 강제 종료
            TRQ_COUNT_LogEnable = 0U;
            TRQ_COUNT_TxReady = 1U; 
        }
    }
    #endif

    G_Timer1ms.Spi = 0U;

    if (AAF_Maximum_Torque_Test_Mode == OFF)
    {
        StallCheck_ChangeStallTh();
        Stall_Check();
    }
    else
    {
        motor_stall_flag = MOTOR_NORMAL;
    }

    spi_action_step = 0U;
}
/***********************************************************************************************************************
 * Function Name: SpiCheck_Init
 * Description  : Checks conditions to start a new SPI transaction (Step 0 Logic).
 * Called By    : Spi_Check
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
static void SpiCheck_Init(void)
{
    // Condition 1: Voltage Status Change
    if ((voltage_status_change == ON) && (motor_start == OFF) && (G_Timer1ms.Spi >= 20U))
    {
        SpiCheck_ExecuteVoltageChange();
    }
    // Condition 2: Motor ON (Fast Polling)
    else if ((motor_start == ON) && (G_Timer1ms.Spi >= 2U) && (G_Timer1us.Motor <= (STEP_TIME_1250RPM / 2U)) && (spi_action_step == 0U))
    {
        SpiCheck_SendCommand();
    }
    // Condition 3: Idle (Slow Polling)
    else if ((G_Timer1ms.Spi >= 50U) && (G_Timer1us.Motor == 0U) && (spi_action_step == 0U))
    {

        SpiCheck_CurrentLimitingSelect(); 

        if (voltage_status_change == OFF)
        {
            SpiCheck_SendCommand();
        }
    }
    else
    {
        // invalid
    }
}

static void SpiCheck_CurrentLimitingSelect(void)
{
    if (Operating_flag == 0U)
    {
        if (voltage_status_spi == LOW_VOLTAGE)
        {
            if (adc_avr >= ADC_VOLTAGE_10V)
            {
                voltage_status_spi = NORMAL_VOLTAGE;
                voltage_status_change = ON;
            }
        }
        else if (voltage_status_spi == NORMAL_VOLTAGE)
        {
            if (adc_avr < ADC_VOLTAGE_10V)
            {
                voltage_status_spi = LOW_VOLTAGE;
                voltage_status_change = ON;
            }
            else if (adc_avr >= ADC_VOLTAGE_15V)
            {
                voltage_status_spi = HIGH_VOLTAGE;
                voltage_status_change = ON;
            }
        }
        else if (voltage_status_spi == HIGH_VOLTAGE)
        {
            if (adc_avr < ADC_VOLTAGE_15V)
            {
                voltage_status_spi = NORMAL_VOLTAGE;
                voltage_status_change = ON;
            }
        }
    }
}

/***********************************************************************************************************************
 * Function Name: Spi_Check
 * Description  : Main function for SPI communication control and stall checking.
 * Metric Info  : FUCYC = 2 (Pass), FUNDC = 2 (Pass)
 * Called By    : Main Loop
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
void Spi_Check(void)
{
    switch (spi_action_step)
    {
        
    case 0:
        SpiCheck_Init();
        break;

    case 1:
        SpiCheck_Delay();
        break;

    case 2:
        SpiCheck_Delay2();
        break;

    case 3:
        SpiCheck_HandleData();
        break;

    default:
        // Invalid
        break;
    }
}


