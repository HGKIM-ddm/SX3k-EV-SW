#include "Drv8889.h"

static uint8_t drv8889_ctrl1_override_active = OFF;

//Timer
static uint8_t Drv8889_WaitSpiComplete(void)
{
    G_Timer1msFlag.SpiErrorCheckFlag = 1U;
    
    while (1)
    {
        if ((spi_receive_flag == 1U) && (spi_send_flag == 1U))
        {
            spi_receive_flag = 0U;
            spi_send_flag = 0U;
            G_Timer1ms.SpiErrorCheck = 0U;
            G_Timer1msFlag.SpiErrorCheckFlag = 0U;
            return 1U; 
        }

        if (G_Timer1ms.SpiErrorCheck >= 100U)
        {
            G_Timer1ms.SpiErrorCheck = 0U;
            G_Timer1msFlag.SpiErrorCheckFlag = 0U;
            return 0U; 
        }
    }
}

static void Drv8889_Wait1ms(void)
{
    G_Timer1msFlag.SpiFlag = 1U;
    while (1)
    {
        if (G_Timer1ms.Spi >= 1U)
        {
            break;
        }
    }
}

static void Drv8889_WaitUs(uint16_t us_delay)
{
    G_Timer1usFlag.SpiFlag = 1U;
    while (1)
    {
        if (G_Timer1us.Spi >= us_delay)
        {
            G_Timer1usFlag.SpiFlag = 0U;
            G_Timer1us.Spi = 0U;
            break;
        }
    }
}

/* SPi Comunication (txbuf, rxbuf, us_delay) */
static void Drv8889_SpiTransfer(uint16_t * const tx_buf,
                                uint16_t * const rx_buf,
                                uint16_t us_delay)
{
    Drv8889_ScsActive();

    (void)R_Config_CSIH0_Send_Receive(tx_buf,
                                     1U,
                                     rx_buf,
                                     _CSIH_SELECT_CHIP_0);

    (void)Drv8889_WaitSpiComplete();

    Drv8889_ScsInactive();

    Drv8889_WaitUs(us_delay);
}

void Drv8889_GpioInit(void)
{
	PORT.P10 |= _PORT_Pn0_OUTPUT_HIGH;	// MCU_DRVOFF
	PORT.P10 |= _PORT_Pn2_OUTPUT_HIGH;	// MCU_DRV_SLEEP_MODE
	PORT.P9 |= _PORT_Pn1_OUTPUT_HIGH;	// VREF
	PORT.P10 &= ~_PORT_Pn4_OUTPUT_HIGH; // MCU_DIR
	PORT.P9 &= ~_PORT_Pn0_OUTPUT_HIGH;	// MCU_STEP
}

void Drv8889_Wakeup(void)
{
	PORT.P10 |= _PORT_Pn0_OUTPUT_HIGH; // MCU_DRVOFF
	PORT.P10 |= _PORT_Pn2_OUTPUT_HIGH; // MCU_DRV_SLEEP_MODE
	PORT.P9 |= _PORT_Pn1_OUTPUT_HIGH;  // VREF
}

void Drv8889_Sleep(void)
{
	PORT.P10 |= _PORT_Pn0_OUTPUT_HIGH;	// MCU_DRVOFF
	PORT.P10 &= ~_PORT_Pn2_OUTPUT_HIGH; // MCU_DRV_SLEEP_MODE
	PORT.P9 &= ~_PORT_Pn1_OUTPUT_HIGH;	// VREF
	PORT.P10 &= ~_PORT_Pn4_OUTPUT_HIGH; // MCU_DIR
	PORT.P9 &= ~_PORT_Pn0_OUTPUT_HIGH;	// MCU_STEP
}

void Drv8889_On(void)
{
	PORT.P10 &= ~_PORT_Pn0_OUTPUT_HIGH; // MCU_DRVOFF
}

void Drv8889_On2(void)
{
	PORT.P10 &= ~_PORT_Pn0_OUTPUT_HIGH; // MCU_DRVOFF
}

void Drv8889_Off(void)
{
	PORT.P10 |= _PORT_Pn0_OUTPUT_HIGH; // MCU_DRVOFF
	G_Timer1msFlag.StallTimeFlag = 0U;
	G_Timer1ms.StallTime = 0U;
}

void Drv8889_Off2(void)
{
	PORT.P10 |= _PORT_Pn0_OUTPUT_HIGH; // MCU_DRVOFF
	G_Timer1msFlag.StallTimeFlag = 0U;
	G_Timer1ms.StallTime = 0U;
}

void Drv8889_ScsActive(void)
{
	PORT.P8 &= ~_PORT_Pn0_OUTPUT_HIGH;
}

void Drv8889_ScsInactive(void)
{
	PORT.P8 |= _PORT_Pn0_OUTPUT_HIGH;
}

void Drv8889_StepHigh(void) { PORT.P9 |= _PORT_Pn0_OUTPUT_HIGH; }
void Drv8889_StepLow(void)  { PORT.P9 &= ~_PORT_Pn0_OUTPUT_HIGH; }

void Drv8889_DirCW(void)    { PORT.P10 |= _PORT_Pn4_OUTPUT_HIGH; }
void Drv8889_DirCCW(void)   { PORT.P10 &= ~_PORT_Pn4_OUTPUT_HIGH; }

void Drv8889_SetCtrl1Override(uint8_t active)
{
    drv8889_ctrl1_override_active = active;
}

uint8_t Drv8889_IsCtrl1OverrideActive(void)
{
    return drv8889_ctrl1_override_active;
}

/***********************************************************************************************************************
 * Function Name: Drv8889_WriteCtrl1
 * Description  : DRV8889 CTRL1 레지스터에 TRQ_DAC 및 SLEW_RATE 설정값을 SPI로 전송함.
 ***********************************************************************************************************************/
void Drv8889_WriteCtrl1(Drv_TrqDac_t trq, Drv_SlewRate_t slew)
{
    uint16_t ctrl1_frame;

    ctrl1_frame = ((uint16_t)DRV_CTRL1 << 8U) | (uint16_t)((uint8_t)trq | (uint8_t)slew);

    Drv8889_SpiTransfer(&ctrl1_frame, &rx_16bit_spi[3], 2U);
}

#ifdef ENABLE_TORQUE_LIN_COMMUNICATION
/***********************************************************************************************************************
 * Function Name: Drv8889_WriteRegisterRaw
 * Description  : DRV8889 레지스터 주소와 8bit data를 조합하여 16bit SPI frame으로 전송함.
 ***********************************************************************************************************************/
static void Drv8889_WriteRegisterRaw(uint8_t reg_addr,
                                     uint8_t data,
                                     uint8_t rx_index)
{
    uint16_t frame;

    frame = ((uint16_t)reg_addr << 8U) | (uint16_t)data;

    Drv8889_SpiTransfer(&frame,
                        &rx_16bit_spi[rx_index],
                        2U);
}

/***********************************************************************************************************************
 * Function Name: Drv8889_WriteCtrl1Raw
 * Description  : DRV8889 CTRL1 레지스터에 8bit raw data를 SPI로 전송함.
 ***********************************************************************************************************************/
void Drv8889_WriteCtrl1Raw(uint8_t data)
{
    Drv8889_WriteRegisterRaw((uint8_t)DRV_CTRL1,
                             data,
                             3U);
}

/***********************************************************************************************************************
 * Function Name: Drv8889_WriteCtrl2
 * Description  : DRV8889 CTRL2 레지스터에 8bit raw data를 SPI로 전송함.
 ***********************************************************************************************************************/
void Drv8889_WriteCtrl2(uint8_t data)
{
    Drv8889_WriteRegisterRaw((uint8_t)DRV_CTRL2, data, 4U);
}

/***********************************************************************************************************************
 * Function Name: Drv8889_WriteCtrl3
 * Description  : DRV8889 CTRL3 레지스터에 Microstep 설정값을 SPI로 전송함.
 *                LIN 통신에서는 CTRL3 전체 raw data가 아니라 Microstep 값만 수신함.
 *                DIR / STEP 제어 방식은 기존 핀 제어 방식으로 유지함.
 ***********************************************************************************************************************/
void Drv8889_WriteCtrl3(uint8_t data)
{
    uint8_t ctrl3_data;

    ctrl3_data =
        (uint8_t)(SPI_DIR_PIN | SPI_STEP_PIN | (data & 0x0FU));

    Drv8889_WriteRegisterRaw((uint8_t)DRV_CTRL3,
                             ctrl3_data,
                             5U);
}
/***********************************************************************************************************************
 * Function Name: Drv8889_WriteCtrl4
 * Description  : DRV8889 CTRL4 레지스터에 8bit raw data를 SPI로 전송함.
 ***********************************************************************************************************************/
void Drv8889_WriteCtrl4(uint8_t data)
{
    Drv8889_WriteRegisterRaw((uint8_t)DRV_CTRL4, data, 6U);
}

/***********************************************************************************************************************
 * Function Name: Drv8889_WriteCtrl5
 * Description  : DRV8889 CTRL5 레지스터에 8bit raw data를 SPI로 전송함.
 ***********************************************************************************************************************/
void Drv8889_WriteCtrl5(uint8_t data)
{
    Drv8889_WriteRegisterRaw((uint8_t)DRV_CTRL5, data, 7U);
}

/***********************************************************************************************************************
 * Function Name: Drv8889_WriteCtrl6
 * Description  : DRV8889 CTRL6 레지스터에 8bit raw data를 SPI로 전송함.
 ***********************************************************************************************************************/
void Drv8889_WriteCtrl6(uint8_t data)
{
    Drv8889_WriteRegisterRaw((uint8_t)DRV_CTRL6, data, 8U);
}
#endif

void Drv8889_SpiInit(void)
{
    uint8_t i;

    /* === tx_16bit_spi 배열 채우기 (DRV8889A-Q1 레지스터 설정) === */
    /* Read 전용: 주소만 (응답 데이터 읽기용) */
    tx_16bit_spi[0]  = ((uint16_t)DRV_FAULT << 8);   /* FAULT Status (R) */
    tx_16bit_spi[1]  = ((uint16_t)DRV_DIAG1 << 8);   /* DIAG Status 1 (R) */
    tx_16bit_spi[2]  = ((uint16_t)DRV_DIAG2 << 8);   /* DIAG Status 2 (R) */

    /* Write: CTRL1~6 (enum OR로 의미 명확) */
    tx_16bit_spi[3]  = ((uint16_t)DRV_CTRL1 << 8) | (TRQ_DAC_75 | SLEW_RATE_10V);
    tx_16bit_spi[4]  = ((uint16_t)DRV_CTRL2 << 8) | (DIS_OUT_ENABLE | TOFF_16US | DECAY_SMART_RIPPLE);
    tx_16bit_spi[5]  = ((uint16_t)DRV_CTRL3 << 8) | (SPI_DIR_PIN | SPI_STEP_PIN | MICROSTEP_1_8);
    tx_16bit_spi[6]  = ((uint16_t)DRV_CTRL4 << 8) | (LOCK_UNLOCK | EN_OL_ON | OCP_LATCH | OTSD_LATCH | TW_NO_REP);
    tx_16bit_spi[7]  = ((uint16_t)DRV_CTRL5 << 8) | (EN_STL_ON | STL_REP_OFF | EN_SR_BLANK_ON);
    tx_16bit_spi[8]  = ((uint16_t)DRV_CTRL6 << 8) | (STALL_TH);   /* STALL_TH = 0 */

   

    /* Read 전용 */
    tx_16bit_spi[9]  = ((uint16_t)DRV_CTRL7 << 8);   /* TRQ_COUNT (R) */
    tx_16bit_spi[10] = ((uint16_t)DRV_CTRL8 << 8);   /* REV_ID (R) */

    Drv8889_Wait1ms();

    for (i = 0U; i < 11U; i++)
    {
       Drv8889_SpiTransfer(&tx_16bit_spi[i], &rx_16bit_spi[i], 2U);
    }

    for (i = 0U; i < 11U; i++)
    {
       Drv8889_SpiTransfer(&rx_16bit_spi_id[i], &rx_16bit_spi[i], 2U);
    }
}

void Drv8889_FaultClear(void)
{
    Drv8889_SpiTransfer(&fault_clear[0], &rx_16bit_spi[9], 10U);
    
    Drv8889_SpiTransfer(&rx_16bit_spi_id[9], &rx_16bit_spi[9], 10U);
}


