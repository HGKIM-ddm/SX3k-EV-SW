#include "Error_Check.h"
#include "Service.h"

static void Error_StartVoltageProtection(void)
{
    if (voltage_protection_function == OFF)
    {
        voltage_protection_function = ON;
        protection_Mode_step = 0U;
        G_Timer1ms.ProtectionMode = 0U;
        G_Timer1msFlag.ProtectionModeFlag = 0U;
    }
}

static void Error_ClearVoltageProtection(void)
{
    voltage_protection_function = OFF;

    if (protection_Mode_step == 4U)
    {
        protection_Mode_step = 5U;
    }
    else if (protection_Mode_step == 0U)
    {
        Re_Init();
    }
    else
    {
        /* protection running */
    }
}

/***********************************************************************************************************************
 * Function Name: Error_CheckVoltage
 * Description  : 전압 상태(저전압/과전압)를 체크하고 임계값 이탈 시 모터를 정지하거나 보호 모드로 진입함
 * Arguments    : void
 * Return Value : 1 (즉시 정지 상황), 0 (정상 또는 대기 상황)
 ***********************************************************************************************************************/
static uint8_t Error_CheckVoltage(void)
{
    if (adc_chk_ok_flag != 10U) return 0U;
    if (adc_avr == 0U) return 0U;                           
 
    /* 1. 저전압 (Under Voltage) */
    if (adc_avr <= ADC_UNDER_VOLTAGE_7V)
    {
        Error_UnknownStatus();                           
        AAFx_Low_Volt = UNDER_VOLTAGE;
        return 1U;
    }
 
    if ((AAFx_Low_Volt == UNDER_VOLTAGE))
    {
        if (adc_avr >= ADC_UNDER_VOLTAGE_9V)
        {
            AAFx_Low_Volt = NO_ERROR;
            Under_Voltage_Deceted = 0U;
            G_Timer1ms.Adc1sCheck = 0U;
            G_Timer1msFlag.Adc1sCheckFlag = 0U;
            Error_ClearVoltageProtection();

        }
    }
    else if (adc_avr <= ADC_UNDER_VOLTAGE_8_5V)
    {
        if (Under_Voltage_Deceted == 0U)
        {
            Under_Voltage_Deceted = 1U;
            G_Timer1ms.Adc1sCheck = 0U;
            G_Timer1msFlag.Adc1sCheckFlag = 1U;
        }
        if ((Under_Voltage_Deceted == 1U) && (G_Timer1ms.Adc1sCheck >= ADC_Detect_Time)) 
        {
            AAFx_Low_Volt = UNDER_VOLTAGE;
            DTC_Status |= 0x20u;
            Error_UnknownStatus();
            Error_StartVoltageProtection();                      
            G_Timer1ms.Adc1sCheck = ADC_Detect_Time;       
            G_Timer1msFlag.Adc1sCheckFlag = 0U;
        }
    }
    else
    {
        if (Under_Voltage_Deceted == 1U)
        {
            Under_Voltage_Deceted = 0U;
            G_Timer1ms.Adc1sCheck = 0U;
            G_Timer1msFlag.Adc1sCheckFlag = 0U;
        }
    }
 
    /* 2. 과전압 (Over Voltage) */
    if (adc_avr >= ADC_OVER_VOLTAGE_18V)
    {
        Error_UnknownStatus();                           
        AAFx_Over_Volt = OVER_VOLTAGE;
        return 1U;
    }
 
    if ((AAFx_Over_Volt == OVER_VOLTAGE))
    {
        if (adc_avr <= ADC_OVER_VOLTAGE_16V)
        {
            AAFx_Over_Volt = NO_ERROR;
            Over_Voltage_Deceted = 0U;
            G_Timer1ms.Adc1sCheck = 0U;
            G_Timer1msFlag.Adc1sCheckFlag = 0U;
            Error_ClearVoltageProtection();
        }
    }
    else
    {
        if (adc_avr >= ADC_OVER_VOLTAGE_16_5V)
        {
            if (Over_Voltage_Deceted == 0U)
            {
                Over_Voltage_Deceted = 1U;
                G_Timer1ms.Adc1sCheck = 0U;
                G_Timer1msFlag.Adc1sCheckFlag = 1U;
            }
            if ((Over_Voltage_Deceted == 1U) && (G_Timer1ms.Adc1sCheck >= ADC_Detect_Time)) 
            {
                AAFx_Over_Volt = OVER_VOLTAGE;
                DTC_Status |= 0x40u;
                Error_UnknownStatus();
                Error_StartVoltageProtection();                      
                G_Timer1ms.Adc1sCheck = ADC_Detect_Time;   
                G_Timer1msFlag.Adc1sCheckFlag = 0U;
            }
            else
            {
                //invaild
            }
        }
        else
        {
            if (Over_Voltage_Deceted == 1U)
            {
                Over_Voltage_Deceted = 0U;
                G_Timer1ms.Adc1sCheck = 0U;
                G_Timer1msFlag.Adc1sCheckFlag = 0U;
            }
        }
    }
 
    return 0U;
}

/***********************************************************************************************************************
 * Function Name: Error_CheckMotorFault
 * Description  : 모터 드라이버의 Fault 상태 및 초기화 실패 여부를 확인하여 보호 모드(Sleep) 진입
 ***********************************************************************************************************************/
static void Error_CheckMotorFault(void)
{
    // 초기화가 비정상적으로 종료되었거나 모터 하드웨어 Fault가 감지된 경우
    if ((AAFx_InitStatus == ABNORMAL_FINISHED_INITIALIZATION) && (motor_fault_chk == 1))
    {
        Drv8889_Sleep();        // 모터 드라이버 보호를 위해 슬립 모드 진입
        AAFx_Motor_Fault = 1U;   // 모터 고장 상태 플래그 세팅
        DTC_Status |= 0x10u;     // 모터 관련 고장 코드(DTC) 기록
    }
}

/***********************************************************************************************************************
 * Function Name: Error_CheckShort
 * Description  : 모터 쇼트(과전류) 감지 시 재시도를 수행
 ***********************************************************************************************************************/
static void Error_CheckShort(void)
{
    if (AAFx_Circuit_Short == AAF_CIRCUIT_SHORT) return;
 
    if ((AAF_OverCurrent == OVER_CURRENT) && (Short_Detected == 0U))
    {
        G_Timer1ms.MotorShortCheck = 0U;
        G_Timer1msFlag.MotorShortCheckFlag = 1U;
        Short_Detected = 1U;
        Short_fault_check = 0U;
        motor_Short_chk_count++;
        Drv8889_Off2();
        motor_start = OFF;
        G_Timer1msFlag.StallTimeFlag = 0U;
        G_Timer1ms.StallTime = 0U;
        softstart_complete = OFF;
        motor_step_value = STEP_TIME_1000RPM;
        AAFx_InitStatus = DURING_INITIALIZATION;          
        AAF_Tx_Position = UNKOWN_POSITION;
        AAFx_Position_Status = Unknown_Status;
    }
    else if (Short_Detected == 1U)
    {
        if ((G_Timer1ms.MotorShortCheck >= 200U) && (Short_fault_check == 0U))
        {
            Drv8889_FaultClear();
            Short_fault_check = 1U;
        }
        AAF_OverCurrent = (unsigned int)(rx_16bit_spi[9] & 0x800U);
        if (G_Timer1ms.MotorShortCheck >= 1000U)
        {
            if ((AAF_OverCurrent == NO_ERROR) && (Short_fault_check == 1U))
            {
                Re_Init();
                G_Timer1ms.MotorShortCheck = 0U;
                G_Timer1msFlag.MotorShortCheckFlag = 0U;
                Short_Detected = 0U;
            }
            else if ((AAF_OverCurrent == OVER_CURRENT) && (motor_Short_chk_count < 10U))
            {
                Short_Detected = 0U;
            }
            else
            {
                // invalid
            }
        }
        if (motor_Short_chk_count >= 10U)
        {
            Drv8889_Off2();
            motor_start = OFF;
            AAFx_Circuit_Short = AAF_CIRCUIT_SHORT;
            Drv8889_Sleep();
            DTC_Status |= 0x04U;
            G_Timer1msFlag.MotorShortCheckFlag = 0U;
            Short_Detected = 0U;
            FDL_Write();
        }
    }
    else
    {
        // invalid
    }
}

/***********************************************************************************************************************
 * Function Name: Error_CheckOpen
 * Description  : 모터 단선(Open Load) 감지 시 재시도를 수행
 ***********************************************************************************************************************/
static void Error_CheckOpen(void)
{
    if (AAFx_Motor_Fault == 1) return;
 
    if ((AAF_OpenLoad == MOTOR_FAULT) && (Open_Detected == 0U))
    {
        G_Timer1ms.MotorOpenCheck = 0U;
        G_Timer1msFlag.MotorOpenCheckFlag = 1U;
        Open_Detected = 1U;
        Open_fault_check = 0U;
        motor_Open_chk_count++;
        Drv8889_Off2();
        motor_start = OFF;
        G_Timer1msFlag.StallTimeFlag = 0U;
        G_Timer1ms.StallTime = 0U;
        softstart_complete = OFF;
        motor_step_value = STEP_TIME_1000RPM;
        AAFx_InitStatus = DURING_INITIALIZATION;         
        AAF_Tx_Position = UNKOWN_POSITION;
        AAFx_Position_Status = Unknown_Status;
    }
    else if (Open_Detected == 1U)
    {
        if ((G_Timer1ms.MotorOpenCheck >= 200U) && (Open_fault_check == 0U))
        {
            Drv8889_FaultClear();
            Open_fault_check = 1U;
        }
 
        AAF_OpenLoad = (unsigned int)(rx_16bit_spi[9] & 0x100U);
 
        if (G_Timer1ms.MotorOpenCheck >= 1000U)
        {
            if ((AAF_OpenLoad == NO_ERROR) && (Open_fault_check == 1U))
            {
                Re_Init();
                G_Timer1ms.MotorOpenCheck = 0U;
                G_Timer1msFlag.MotorOpenCheckFlag = 0U;
                Open_Detected = 0U;
            }
            else if ((AAF_OpenLoad == MOTOR_FAULT) && (motor_Open_chk_count < 10U))
            {
                Open_Detected = 0U;
            }
            else
            {
                // invalid
            }
        }
        else
        {
            // invalid                                    
        }
 
        if (motor_Open_chk_count >= 10U)
        {
            Drv8889_Off2();
            motor_start = OFF;
            AAFx_Motor_Fault = 1U;
            Drv8889_Sleep();
            DTC_Status |= 0x10u;
            G_Timer1msFlag.MotorOpenCheckFlag = 0U;
            FDL_Write();
        }
    }
    else
    {
        // invalid
    }
}



/***********************************************************************************************************************
 * Function Name: Error_CheckAfterIGN
 * Description  : IGN/HEV 신호를 모니터링하고 에러 체크 루틴을 수행함 
 ***********************************************************************************************************************/
void Error_CheckAfterIGN(void)
{
    if (((LDCRdy == 0x01u) && (G_Timer1ms.IgnCheck <= 500U)) || (IGN_Chk_On == 1U)) 
    {
        G_Timer1msFlag.IgnCheckFlag = 1U;
        if (G_Timer1ms.IgnCheck >= 500U)
        {
            G_Timer1msFlag.IgnCheckFlag = 0U;
            G_Timer1ms.IgnCheck = 500U;
            IGN_Chk_On = 1U;
            Error_Check();
        }
    }
}

/***********************************************************************************************************************
 * Function Name: Error_Check
 * Description  : 외부 보호 요청, 전압, 드라이버 결함, 쇼트/오픈 상태를 순차적으로 체크함
 ***********************************************************************************************************************/
void Error_Check(void)
{
    static uint8_t error_step = 0U;

    if ((stall_test_mode == 0U))
    {
        switch (error_step)
        {
            case 0U:
                if (Error_CheckVoltage() == 1U) return;
                error_step++;
                break;
            case 1U:
                Error_CheckMotorFault();
                error_step++;
                break; 
            case 2U:
                Error_CheckShort();
                error_step++;
                break;

            case 3U:
                Error_CheckOpen();
                error_step++;
                break;

            case 4U:
                if (First_Powerchk == 1U)
                {
                    if (fdl_fail >= 10U)
                    {
                        AAFx_Circuit_Open = AAF_CIRCUIT_OPEN;
                    }
                    else
                    {
                        AAFx_Circuit_Open = NO_ERROR;
                    }
                }
                Limp_Home(); 
                error_step = 0U;
                break;

            default:
                error_step = 0U;
                break;
        }
        //Obd_DiagStatCheck();
    }
    else
    {
		//invaild
    }
}

void Error_UnknownStatus(void)
{
	Drv8889_Off();
	motor_start = OFF;
	G_Timer1msFlag.StallTimeFlag = 0U;
	G_Timer1ms.StallTime = 0U;
	softstart_complete = OFF;
	motor_step_value = STEP_TIME_1000RPM;
	AAF_Tx_Position = UNKOWN_POSITION;
	AAFx_Position_Status = Unknown_Status;
	AAFx_InitStatus = DURING_INITIALIZATION;
	AAFx_SNSR1_Position = Initial_Value;
	AAFx_SNSR2_Position = Initial_Value;
	AAFx_SNSR3_Position = Initial_Value;
	AAFx_SNSR4_Position = Initial_Value;
	aaf_step = FINISHED_OPERATE;
}








