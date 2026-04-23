#include "Drv8889.h"

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
static void Drv8889_SpiTransfer(uint16_t * const tx_buf, uint16_t * const rx_buf, uint16_t us_delay)
{
  
    Drv8889_ScsActive();

    (void)R_Config_CSIH0_Send_Receive(tx_buf, 1U, rx_buf, _CSIH_SELECT_CHIP_0);

    (void)Drv8889_WaitSpiComplete();

    Drv8889_ScsInactive();

    Drv8889_WaitUs(us_delay);
}


void Drv8889_Init(void)
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


void Drv8889_SpiInit(void)
{
    uint8_t i;

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


