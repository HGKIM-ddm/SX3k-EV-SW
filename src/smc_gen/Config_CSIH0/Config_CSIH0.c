/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products.
* No other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
* applicable laws, including copyright laws.
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED
* OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY
* LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE FOR ANY DIRECT,
* INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR
* ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability
* of this software. By using this software, you agree to the additional terms and conditions found by accessing the
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2018, 2024 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name        : Config_CSIH0.c
* Component Version: 1.4.2
* Device(s)        : R7F701695
* Description      : This file implements device driver for Config_CSIH0.
***********************************************************************************************************************/
/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_userdefine.h"
#include "Config_CSIH0.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
extern volatile uint32_t g_cg_sync_read;
volatile uint16_t  g_csih0_tx_num;                         /* csih0 transmit data number */
volatile uint16_t * gp_csih0_tx_address;                   /* csih0 transmit buffer address */
volatile uint16_t  g_csih0_rx_num;                         /* csih0 receive data number */
volatile uint16_t * gp_csih0_rx_address;                   /* csih0 receive buffer address */
volatile uint16_t  g_csih0_total_num;                      /* csih0 transmit/receive data total times */
/* Start user code for global. Do not edit comment generated here */
extern unsigned char spi_flag_test[20];
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_CSIH0_Create
* Description  : This function initializes the Config_CSIH0 module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_CSIH0_Create(void)
{
    uint32_t tmp_port;

    CSIH0.CTL0 = _CSIH_OPERATION_CLOCK_STOP;
    /* Disable INTCSIH0IC operation and clear request */
    INTC1.ICCSIH0IC.BIT.MKCSIH0IC = _INT_PROCESSING_DISABLED;
    INTC1.ICCSIH0IC.BIT.RFCSIH0IC = _INT_REQUEST_NOT_OCCUR;
    /* Disable INTCSIH0IRE operation and clear request */
    INTC1.ICCSIH0IRE.BIT.MKCSIH0IRE = _INT_PROCESSING_DISABLED;
    INTC1.ICCSIH0IRE.BIT.RFCSIH0IRE = _INT_REQUEST_NOT_OCCUR;
    /* Set CSIH0 interrupt(INTCSIH0IC) setting */
    INTC1.ICCSIH0IC.BIT.TBCSIH0IC = _INT_TABLE_VECTOR;
    INTC1.ICCSIH0IC.UINT16 &= _INT_PRIORITY_LOWEST;
    /* Set CSIH0 interrupt(INTCSIH0IRE) setting */
    INTC1.ICCSIH0IRE.BIT.TBCSIH0IRE = _INT_TABLE_VECTOR;
    INTC1.ICCSIH0IRE.UINT16 &= _INT_PRIORITY_LOWEST;
    /* Set CSIH0 control setting */
    CSIH0.CTL1 = _CSIH_CLOCK_INVERTING_HIGH | _CSIH_INTERRUPT_TIMING_NORMAL | _CSIH_DATA_CONSISTENCY_CHECK_DISABLE | 
                 _CSIH_NO_DELAY | _CSIH_CHIPSELECT0_ACTIVE_LOW | _CSIH_HANDSHAKE_DISABLE | 
                 _CSIH_CHIPSELECT_SIGNAL_HOLD_ACTIVE | _CSIH_SLAVE_SELECT_DISABLE;
    CSIH0.CTL2 = _CSIH0_MASTER_PCLK_DIV;
    CSIH0.BRS0 = _CSIH0_BAUD_RATE_0;
    CSIH0.BRS1 = _CSIH0_BAUD_RATE_1;
    CSIH0.BRS2 = _CSIH0_BAUD_RATE_2;
    CSIH0.BRS3 = _CSIH0_BAUD_RATE_3;
    /* Set CSIH0 configuration setting */
    CSIH0.CFG0 = _CSIH_USED_BAUDRATE_0 | _CSIH_PARITY_NO | _CSIH_DATA_LENGTH_16 | _CSIH_DATA_DIRECTION_MSB | 
                 _CSIH_PHASE_SELECTION_TYPE2 | _CSIH_IDLE_INSERTED_NOT_ALWAYS | _CSIH_IDLE_TIME_0 | 
                 _CSIH_HOLD_TIME_0 | _CSIH_INTER_DATA_DELAY_TIME_0 | _CSIH_SETUP_TIME_0;
    /* Synchronization processing */
    g_cg_sync_read = CSIH0.CTL1;
    __syncp();
    /* Set CSIH0SC pin */
    PORT.PIBC0 &= _PORT_CLEAR_BIT2;
    PORT.PBDC0 &= _PORT_CLEAR_BIT2;
    PORT.PM0 |= _PORT_SET_BIT2;
    PORT.PMC0 &= _PORT_CLEAR_BIT2;
    PORT.PIPC0 &= _PORT_CLEAR_BIT2;
    tmp_port = PORT.PDSC0;
    PORT.PPCMD0 = _WRITE_PROTECT_COMMAND;
    PORT.PDSC0 = (tmp_port & _PORT_CLEAR_BIT2);
    PORT.PDSC0 = (uint32_t) ~(tmp_port & _PORT_CLEAR_BIT2);
    PORT.PDSC0 = (tmp_port & _PORT_CLEAR_BIT2);
    PORT.PFC0 |= _PORT_SET_BIT2;
    PORT.PFCE0 |= _PORT_SET_BIT2;
    PORT.PFCAE0 &= _PORT_CLEAR_BIT2;
    PORT.PIPC0 |= _PORT_SET_BIT2;
    PORT.PMC0 |= _PORT_SET_BIT2;
    /* Set CSIH0SO pin */
    PORT.PIBC0 &= _PORT_CLEAR_BIT3;
    PORT.PBDC0 &= _PORT_CLEAR_BIT3;
    PORT.PM0 |= _PORT_SET_BIT3;
    PORT.PMC0 &= _PORT_CLEAR_BIT3;
    PORT.PIPC0 &= _PORT_CLEAR_BIT3;
    tmp_port = PORT.PDSC0;
    PORT.PPCMD0 = _WRITE_PROTECT_COMMAND;
    PORT.PDSC0 = (tmp_port & _PORT_CLEAR_BIT3);
    PORT.PDSC0 = (uint32_t) ~(tmp_port & _PORT_CLEAR_BIT3);
    PORT.PDSC0 = (tmp_port & _PORT_CLEAR_BIT3);
    PORT.PFC0 |= _PORT_SET_BIT3;
    PORT.PFCE0 |= _PORT_SET_BIT3;
    PORT.PFCAE0 &= _PORT_CLEAR_BIT3;
    PORT.PIPC0 |= _PORT_SET_BIT3;
    PORT.PMC0 |= _PORT_SET_BIT3;
    /* Set CSIH0SI pin */
    PORT.PIBC0 &= _PORT_CLEAR_BIT1;
    PORT.PBDC0 &= _PORT_CLEAR_BIT1;
    PORT.PM0 |= _PORT_SET_BIT1;
    PORT.PMC0 &= _PORT_CLEAR_BIT1;
    PORT.PFC0 |= _PORT_SET_BIT1;
    PORT.PFCE0 |= _PORT_SET_BIT1;
    PORT.PFCAE0 &= _PORT_CLEAR_BIT1;
    PORT.PMC0 |= _PORT_SET_BIT1;

    R_Config_CSIH0_Create_UserInit();
}

/***********************************************************************************************************************
* Function Name: R_Config_CSIH0_Start
* Description  : This function starts the Config_CSIH0 module operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_CSIH0_Start(void)
{
    /* Enable CSIH0 operation */
    CSIH0.CTL0 = _CSIH_OPERATION_CLOCK_PROVIDE | _CSIH_TRANSMISSION_PERMIT | _CSIH_RECEPTION_PERMIT | 
                 _CSIH_DIRECTACCESS;
    /* Clear CSIH0 interrupt request and enable operation */
    INTC1.ICCSIH0IC.BIT.RFCSIH0IC = _INT_REQUEST_NOT_OCCUR;
    INTC1.ICCSIH0IRE.BIT.RFCSIH0IRE = _INT_REQUEST_NOT_OCCUR;
    INTC1.ICCSIH0IC.BIT.MKCSIH0IC = _INT_PROCESSING_ENABLED;
    INTC1.ICCSIH0IRE.BIT.MKCSIH0IRE = _INT_PROCESSING_ENABLED;
}

/***********************************************************************************************************************
* Function Name: R_Config_CSIH0_Stop
* Description  : This function stops the CSIH0 module operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_CSIH0_Stop(void)
{
    /* Disable CSIH0 interrupt operation */
    INTC1.ICCSIH0IC.BIT.MKCSIH0IC = _INT_PROCESSING_DISABLED;
    INTC1.ICCSIH0IRE.BIT.MKCSIH0IRE = _INT_PROCESSING_DISABLED;
    /* Disable CSIH0 operation */
    CSIH0.CTL0 &= (uint8_t) ~_CSIH_RECEPTION_PERMIT;
    CSIH0.CTL0 &= (uint8_t) ~_CSIH_TRANSMISSION_PERMIT;
    CSIH0.CTL0 &= (uint8_t) ~_CSIH_OPERATION_CLOCK_PROVIDE;
    /* Synchronization processing */
    g_cg_sync_read = CSIH0.CTL0;
    __syncp();
    /* Clear CSIH0 interrupt operation */
    INTC1.ICCSIH0IC.BIT.RFCSIH0IC = _INT_REQUEST_NOT_OCCUR;
    INTC1.ICCSIH0IRE.BIT.RFCSIH0IRE = _INT_REQUEST_NOT_OCCUR;
    /* Synchronization processing */
    g_cg_sync_read = INTC1.ICCSIH0IC.UINT16;
    __syncp();
}

/***********************************************************************************************************************
* Function Name: R_Config_CSIH0_Send_Receive
* Description  : This function sends and receives CSIH0 data.
* Arguments    : tx_buf -
*                    send buffer pointer
*                tx_num -
*                    buffer size
*                rx_buf -
*                    receive buffer pointer
*                chip_id -
*                    set chip select id
* Return Value : status -
*                    MD_OK or MD_ARGERROR
***********************************************************************************************************************/
MD_STATUS R_Config_CSIH0_Send_Receive(uint16_t* const tx_buf, uint16_t tx_num, uint16_t* const rx_buf, uint32_t chip_id)
{
    MD_STATUS status = MD_OK;
    uint32_t regValue = _CSIH0_SETTING_INIT;

    if ((tx_num < 1U) || (chip_id < _CSIH_SELECT_CHIP_0) || (chip_id > _CSIH_SELECT_CHIP_1))
    {
        status = MD_ARGERROR;
    }
    else
    {
        /* Set transmit setting */
        gp_csih0_tx_address = tx_buf;
        g_csih0_total_num = tx_num;
        g_csih0_tx_num = 0U;
        /* Set receive setting */
        gp_csih0_rx_address = rx_buf;
        /* Set select chip id */
        regValue &= (~chip_id);
        if (0U != gp_csih0_tx_address)
        {
            regValue |= (*gp_csih0_tx_address);
            gp_csih0_tx_address++;
        }
        else
        {
            regValue |= _CSIH_DUMMY_DATA;
        }
        /* Disable CSIH0 interrupt operation */
        INTC1.ICCSIH0IC.BIT.MKCSIH0IC = _INT_PROCESSING_DISABLED;
        /* Synchronization processing */
        g_cg_sync_read = INTC1.ICCSIH0IC.UINT16;
        __syncp();
        /* Set transmit data */
        CSIH0.TX0W = regValue;
        g_csih0_tx_num++;
        /* Enable CSIH0 interrupt operation */
        INTC1.ICCSIH0IC.BIT.MKCSIH0IC = _INT_PROCESSING_ENABLED;
        /* Synchronization processing */
        g_cg_sync_read = CSIH0.CTL1;
        __syncp();
    }

    return (status);
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
