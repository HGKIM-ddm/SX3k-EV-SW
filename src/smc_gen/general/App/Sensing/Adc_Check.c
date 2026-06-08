#include "Adc_Check.h"

void ADC_GetStatus(void)
{
	G_Timer1msFlag.AdcCheckFlag = 1U;
#if 0
	if ((G_Timer1ms.AdcCheck >= 10U) && (voltage_chk_delay_complete == 1U))
	{
		G_Timer1msFlag.AdcErrorCheckFlag = 1;

		while (INTC1.ICADCA0I0.BIT.RFADCA0I0 == 0)
		{
			if (G_Timer1ms.AdcErrorCheck >= 100)
			{
				G_Timer1msFlag.AdcErrorCheckFlag = 0;
				G_Timer1ms.AdcErrorCheck = 0;
				adc_fail = 1;
				break;
			}
		}

		G_Timer1msFlag.AdcErrorCheckFlag = 0;
		G_Timer1ms.AdcErrorCheck = 0;

		/*
		while (!INTC1.ICADCA0I0.BIT.RFADCA0I0)
		{

		}
		*/

		INTC1.ICADCA0I0.BIT.RFADCA0I0 = 0;
		R_Config_ADCA0_ScanGroup1_GetResult(&bat_adc, 8);

		adc_sum = 0;

		for (int i = 8; i >= 0; i--)
		{
			adc_chk[i + 1] = adc_chk[i];
			adc_sum += adc_chk[i];
		}

		adc_chk[0] = bat_adc;

		adc_sum += adc_chk[0];

		adc_avr = adc_sum / 10U;

		adc_chk_ok_flag++;

		if (adc_chk_ok_flag >= 10U)
		{
			adc_chk_ok_flag = 10;
		}

		G_Timer1ms.AdcCheck = 0;
	}
#endif
	if (adc_chk_ready == 1U)
	{
		INTC1.ICADCA0I0.BIT.RFADCA0I0 = 0U;
		
		R_Config_ADCA0_ScanGroup1_GetResult(scan_results, 1U); //KR
		bat_adc = scan_results[0]; //KR

		adc_sum = 0U;

		for (uint8_t i = 9U; i > 0U; i--) 
        {
            adc_chk[i] = adc_chk[i - 1U]; 
            adc_sum += adc_chk[i];
        }

		adc_chk[0] = bat_adc;

		adc_sum += adc_chk[0];

		adc_avr = adc_sum / 10U;

		adc_chk_ok_flag++;

		if (adc_chk_ok_flag >= 10U)
		{
			adc_chk_ok_flag = 10U;
		}

		adc_chk_ready = 0U;
		G_Timer1ms.AdcCheck = 0U;
	}
	else if ((G_Timer1ms.AdcCheck >= 10U) && (voltage_chk_delay_complete == 1U) && (adc_chk_ready == 0U))
	{
		if (INTC1.ICADCA0I0.BIT.RFADCA0I0 == 1U)
		{
			adc_chk_ready = 1U;
			G_Timer1ms.AdcCheck = 0U;
		}
	}
	else if (G_Timer1ms.VoltCheckDelay >= 5U)
	{
		voltage_chk_delay_complete = 1U;
		G_Timer1ms.VoltCheckDelay = 0U;
		G_Timer1msFlag.VoltCheckDelayFlag = 0U;
		ADC_UpdateVoltStat();
	}
	else
	{
        //invaild
	}

	if ((G_Timer1ms.VoltStatChangeDelay >= 10U) && (motor_start == OFF))
	{
		voltage_status_change_complete = COMPLETE;
		G_Timer1ms.VoltStatChangeDelay = 0U;
		G_Timer1msFlag.VoltStatChangeDelayFlag = 0U;
	}
}

void ADC_UpdateVoltStat(void)
{
	if (voltage_status_spi == 0U) //	6 ohm
	{
		if ((bat_adc >= 500U) && (adc_avr < ADC_VOLTAGE_10V) && (motor_start == OFF))
		{
			voltage_status_spi = LOW_VOLTAGE;
		}
		else
		{
			voltage_status_spi = NORMAL_VOLTAGE;
		}

		voltage_status_change = ON;
	}
}


