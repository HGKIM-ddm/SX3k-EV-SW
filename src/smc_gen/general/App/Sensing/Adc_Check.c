#include "Adc_Check.h"

/***********************************************************************************************************************
 * Function Name: ADC_TrqCountReset
 * Description  : 토크카운트 이동평균 상태 초기화. 모터 정지 / 방향전환 시 호출.
 ***********************************************************************************************************************/
void ADC_TrqCountReset(void)
{
    uint8_t i;
 
    for (i = 0U; i < TRQ_BUF_SIZE; i++)
    {
        trq_buf[i] = 0U;
    }
 
    trq_buf_index     = 0U;
    trq_buf_count        	= 0U;
    trq_sum         = 0U;
    trq_cnt       = 0U;
    trq_cnt_avg   = 0U;
    trq_cnt_valid = 0U;
}

/***********************************************************************************************************************
 * Function Name: ADC_TrqCountSample
 * Description  : 2 ms 주기로 TRQ_CNT(ADCA0I0 / 가상채널01)를 읽어 이동평균을 갱신하고
 *                스톨 판정을 수행한다.
 * Called By    : App_HwCheck
 *
 *  ※ ADCA0 는 Continuous Scan 모드로 상시 변환 중이므로 DR 레지스터에는 항상 최신값이 있다.
 *    따라서 여기서는 스캔종료 인터럽트 플래그(RFADCA0I0)를 건드리지 않는다.
 *    플래그는 배터리 전압 경로(ADC_GetStatus)가 10 ms 핸드셰이크용으로 단독 사용한다.
 ***********************************************************************************************************************/
void ADC_TrqCountSample(void)
{
    G_Timer1msFlag.TrqCheckFlag = 1U;              /* 2 ms 샘플 타이머 구동 */
 
    if (motor_start != ON)
    {
        ADC_TrqCountReset();
        G_Timer1ms.TrqCheck = 0U;
        return;
    }
 
    if (G_Timer1ms.TrqCheck < TRQ_SAMPLE_PERIOD)
    {
        return;
    }
 
    G_Timer1ms.TrqCheck = 0U;
 
   	if (R_Config_ADCA0_ScanGroup1_GetResult(trq_scan, 2U) != MD_OK)
    {
        return;
    }
 
    trq_cnt = trq_scan[1];              /* VC01 = ADCA0I0 : 토크카운트 */
 
    #ifdef ENABLE_TORQUE_LIN_COMMUNICATION
    if (TRQ_COUNT_LogEnable == 1U)
    {
    uint8_t st;

    st  = (uint8_t)((motor_stall_flag == MOTOR_STALL)             ? 0x01U : 0x00U);
    st |= (uint8_t)((dir_state == OPEN)                           ? 0x02U : 0x00U);
    st |= (uint8_t)((trq_cnt_valid == 1U)                         ? 0x04U : 0x00U);
    st |= (uint8_t)((G_Timer1ms.StallTime >= STALL_CHK_WAIT_TIME) ? 0x08U : 0x00U);
    st |= (uint8_t)(((stall_count > 3U) ? 3U : stall_count) << 4U);
    st |= (uint8_t)((antipinch_action_on == ON)                   ? 0x40U : 0x00U);

    TRQ_COUNT_Buffer[TRQ_COUNT_Index] = (uint16_t)trq_cnt;   /* 생값, 마스킹 없음 */
    TRQ_STATE_Buffer[TRQ_COUNT_Index] = st;

    TRQ_COUNT_Index++;
    if (TRQ_COUNT_Index >= TRQ_COUNT_BUF_SIZE)
    {
        TRQ_COUNT_Index = 0U;                 /* 항상 순환 */
    }

    if (trq_log_post > 0U)                    /* 트리거 이후 : 후미 구간 */
    {
        trq_log_post++;
        if (trq_log_post >= TRQ_LOG_POST_CNT)
        {
            TRQ_COUNT_LogEnable = 0U;
            TRQ_COUNT_TxReady   = 1U;
        }
    }
    else if (motor_stall_flag == MOTOR_STALL) /* 스톨 확정 순간 트리거 */
    {
        trq_log_post = 1U;
    }
    else
    {
        /* 트리거 전 : 계속 덮어쓰기 */
    }
    }
    #endif

    /* 이동평균 갱신 */
    trq_sum        -= (uint32_t)trq_buf[trq_buf_index];
    trq_buf[trq_buf_index] = (uint16_t)trq_cnt;
    trq_sum        += (uint32_t)trq_buf[trq_buf_index];
 
    trq_buf_index++;
    if (trq_buf_index >= TRQ_BUF_SIZE)
    {
        trq_buf_index = 0U;
    }
 
    if (trq_buf_count < TRQ_BUF_SIZE)
    {
        trq_buf_count++;
    }
 
    if (trq_buf_count >= TRQ_BUF_SIZE)
    {
        trq_cnt_avg   = (unsigned int)(trq_sum / TRQ_BUF_SIZE);
        trq_cnt_valid = 1U;
    }
 
    /* 판정 : (2 ms 주기) */
    if (AAF_Maximum_Torque_Test_Mode == OFF)
    {
        StallCheck_ChangeStallTh();
        Stall_Check();
    }
    else
    {
        motor_stall_flag = MOTOR_NORMAL;
    }
}

void ADC_GetStatus(void)
{
	G_Timer1msFlag.AdcCheckFlag = 1U;

	if (adc_chk_ready == 1U)
	{
		INTC1.ICADCA0I0.BIT.RFADCA0I0 = 0U;
		
		R_Config_ADCA0_ScanGroup1_GetResult(scan_results, 2U);   /* VC00 + VC01 */
		bat_adc = scan_results[0];      /* VC00 = ADCA0I5 : 배터리 전압 */

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
	if (volt_stat == 0U) //	6 ohm
	{
		if ((bat_adc >= 500U) && (adc_avr < ADC_VOLTAGE_10V) && (motor_start == OFF))
		{
			volt_stat = LOW_VOLTAGE;
		}
		else if ((bat_adc >= 500U) && (adc_avr >= ADC_VOLTAGE_15V) && (motor_start == OFF))
        {
            volt_stat = HIGH_VOLTAGE;
        }
		else
		{
			volt_stat = NORMAL_VOLTAGE;
		}

		voltage_status_change = ON;
	}
}


