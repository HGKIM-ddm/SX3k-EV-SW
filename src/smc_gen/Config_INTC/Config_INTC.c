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
* Copyright (C) 2018, 2025 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name        : Config_INTC.c
* Component Version: 1.7.0
* Device(s)        : R7F701695
* Description      : This file implements device driver for Config_INTC.
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
#include "Config_INTC.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
extern volatile uint32_t g_cg_sync_read;
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_INTC_Create
* Description  : This function initializes the INTC module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_INTC_Create(void)
{
    /* Disable INTP5 operation and clear request */
    INTC2.ICP5.BIT.MKP5 = _INT_PROCESSING_DISABLED;
    INTC2.ICP5.BIT.RFP5 = _INT_REQUEST_NOT_OCCUR;
    /* Set INTP5 setting */
    INTC2.ICP5.BIT.TBP5 = _INT_TABLE_VECTOR;
    INTC2.ICP5.UINT16 &= _INT_PRIORITY_LOWEST;
    FCLA0.CTL5_INTPL = _INTC_EDGE_FALLING;
    /* Synchronization processing */
    g_cg_sync_read = FCLA0.CTL5_INTPL;
    __syncp();
    /* Set INTP5 pin */
    PORT.PIBC8 &= _PORT_CLEAR_BIT1;
    PORT.PBDC8 &= _PORT_CLEAR_BIT1;
    PORT.PM8 |= _PORT_SET_BIT1;
    PORT.PMC8 &= _PORT_CLEAR_BIT1;
    PORT.PFC8 &= _PORT_CLEAR_BIT1;
    PORT.PFCE8 |= _PORT_SET_BIT1;
    PORT.PFCAE8 &= _PORT_CLEAR_BIT1;
    PORT.PMC8 |= _PORT_SET_BIT1;

    R_Config_INTC_Create_UserInit();
}

/***********************************************************************************************************************
* Function Name: R_Config_INTC_INTP5_Start
* Description  : This function enables INTP5 interrupt.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_INTC_INTP5_Start(void)
{
    /* Clear INTP5 request and enable operation */
    INTC2.ICP5.BIT.RFP5 = _INT_REQUEST_NOT_OCCUR;
    INTC2.ICP5.BIT.MKP5 = _INT_PROCESSING_ENABLED;
}

/***********************************************************************************************************************
* Function Name: R_Config_INTC_INTP5_Stop
* Description  : This function disables INTP5 interrupt.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_INTC_INTP5_Stop(void)
{
    /* Disable INTP5 operation and clear request */
    INTC2.ICP5.BIT.MKP5 = _INT_PROCESSING_DISABLED;
    INTC2.ICP5.BIT.RFP5 = _INT_REQUEST_NOT_OCCUR;
    /* Synchronization processing */
    g_cg_sync_read = INTC2.ICP5.UINT16;
    __syncp();
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
