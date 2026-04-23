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
* File Name        : Config_CSIH0_user.c
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
extern volatile uint16_t  g_csih0_tx_num;                         /* csih0 transmit data number */
extern volatile uint16_t * gp_csih0_tx_address;                   /* csih0 transmit buffer address */
extern volatile uint16_t  g_csih0_rx_num;                         /* csih0 receive data number */
extern volatile uint16_t * gp_csih0_rx_address;                   /* csih0 receive buffer address */
extern volatile uint16_t  g_csih0_total_num;                      /* csih0 transmit/receive data total times */
static void r_Config_CSIH0_callback_receiveend(void);
static void r_Config_CSIH0_callback_sendend(void);
static void r_Config_CSIH0_callback_error(uint32_t err_type);
/* Start user code for global. Do not edit comment generated here */
extern unsigned char spi_send_flag;
extern unsigned char spi_receive_flag;
extern unsigned char spi_error_flag;
extern unsigned char spi_flag_test_user[20];
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_CSIH0_Create_UserInit
* Description  : This function adds user code after initializing CSIH module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_CSIH0_Create_UserInit(void)
{
/* Start user code for user init. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_Config_CSIH0_interrupt_send
* Description  : This function is CSIH0 send interrupt service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
#pragma ghs interrupt
void r_Config_CSIH0_interrupt_send(void)
{
    uint8_t err_type;
    uint16_t sio_dummy;
    uint16_t temp;
    err_type = (CSIH0.STR0 & (_CSIH_CONSISTENCY_ERROR_DETECTED | _CSIH_PARITY_ERROR_DETECTED | 
               _CSIH_OVERRUN_ERROR_DETECTED));
    CSIH0.STCR0 |= (_CSIH_CONSISTENCY_ERROR_CLEAR | _CSIH_PARITY_ERROR_CLEAR | _CSIH_OVERRUN_ERROR_CLEAR);
    if (0U != err_type)
    {
        r_Config_CSIH0_callback_error(err_type);
    }
    else
    {
        if (0U != gp_csih0_rx_address)
        {
            *gp_csih0_rx_address = CSIH0.RX0H;
            gp_csih0_rx_address++;
        }
        else
        {
            sio_dummy = CSIH0.RX0H;
            (void)sio_dummy;
        }
        temp = g_csih0_total_num;
        if (temp > g_csih0_tx_num)
        {
            if (0U != gp_csih0_tx_address)
            {
                CSIH0.TX0H = *gp_csih0_tx_address;
                gp_csih0_tx_address++;
            }
            else
            {
                CSIH0.TX0H = _CSIH_DUMMY_DATA;
            }
            g_csih0_tx_num++;
        }
        if (temp == g_csih0_tx_num)
        {
            r_Config_CSIH0_callback_sendend();
            r_Config_CSIH0_callback_receiveend();
        }
    }
}

/***********************************************************************************************************************
* Function Name: r_Config_CSIH0_interrupt_error
* Description  : This function is CSIH0 error interrupt service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
#pragma ghs interrupt
void r_Config_CSIH0_interrupt_error(void)
{
    uint32_t err_type;
    err_type = (CSIH0.STR0 & (_CSIH_CONSISTENCY_ERROR_DETECTED | _CSIH_PARITY_ERROR_DETECTED | 
               _CSIH_OVERRUN_ERROR_DETECTED));
    CSIH0.STCR0 |= (_CSIH_CONSISTENCY_ERROR_CLEAR | _CSIH_PARITY_ERROR_CLEAR | _CSIH_OVERRUN_ERROR_CLEAR);
    *gp_csih0_rx_address = CSIH0.RX0W;
    if (err_type != 0U)
    {
        r_Config_CSIH0_callback_error(err_type);
    }
}

/***********************************************************************************************************************
* Function Name: r_Config_CSIH0_callback_sendend
* Description  : This function is CSIH0 sendend callback service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void r_Config_CSIH0_callback_sendend(void)
{
/* Start user code for r_Config_CSIH0_callback_sendend. Do not edit comment generated here */
    spi_send_flag++;
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_Config_CSIH0_callback_receiveend
* Description  : This function is CSIH0 receiveend callback service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void r_Config_CSIH0_callback_receiveend(void)
{
/* Start user code for r_Config_CSIH0_callback_receiveend. Do not edit comment generated here */
    spi_receive_flag++;
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_Config_CSIH0_callback_error
* Description  : This function is CSIH0 error callback service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void r_Config_CSIH0_callback_error(uint32_t err_type)
{
/* Start user code for r_Config_CSIH0_callback_error. Do not edit comment generated here */
    spi_error_flag++;
    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

