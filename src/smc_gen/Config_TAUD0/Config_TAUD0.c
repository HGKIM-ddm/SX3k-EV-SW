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
* File Name        : Config_TAUD0.c
* Component Version: 1.8.0
* Device(s)        : R7F701695
* Description      : This file implements device driver for Config_TAUD0.
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
#include "Config_TAUD0.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
extern volatile uint32_t g_cg_sync_read;
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_TAUD0_Create
* Description  : This function initializes the TAUD0 channel.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_TAUD0_Create(void)
{
    /* Disable channel counter operation */
    TAUD0.TT |= (_TAUD_CHANNEL2_COUNTER_STOP | _TAUD_CHANNEL0_COUNTER_STOP);
    /* Disable INTTAUD0I0 operation and clear request */
    INTC1.ICTAUD0I0.BIT.MKTAUD0I0 = _INT_PROCESSING_DISABLED;
    INTC1.ICTAUD0I0.BIT.RFTAUD0I0 = _INT_REQUEST_NOT_OCCUR;
    /* Disable INTTAUD0I2 operation and clear request */
    INTC1.ICTAUD0I2.BIT.MKTAUD0I2 = _INT_PROCESSING_DISABLED;
    INTC1.ICTAUD0I2.BIT.RFTAUD0I2 = _INT_REQUEST_NOT_OCCUR;
    TAUD0.TPS &= _TAUD_CK2_PRS_CLEAR;
    TAUD0.TPS |= _TAUD_CK2_PRE_PCLK_0;
    /* Set channel 0 setting */
    TAUD0.CMOR0 = _TAUD_SELECTION_CK2 | _TAUD_COUNT_CLOCK_PCLK | _TAUD_MASTER_CHANNEL | _TAUD_START_TRIGGER_SOFTWARE | 
                  _TAUD_OVERFLOW_AUTO_CLEAR | _TAUD_INTERVAL_TIMER_MODE | _TAUD_START_INT_GENERATED;
    /* Set compare match register */
    TAUD0.CMUR0 = _TAUD_INPUT_EDGE_UNUSED;
    TAUD0.CDR0 = _TAUD0_CHANNEL0_COMPARE_VALUE;
    /* Set output mode setting */
    TAUD0.TOE &= _TAUD_CHANNEL0_DISABLES_OUTPUT_MODE;
    /* Set channel 2 setting */
    TAUD0.CMOR2 = _TAUD_SELECTION_CK2 | _TAUD_COUNT_CLOCK_PCLK | _TAUD_SLAVE_CHANNEL | 
                  _TAUD_START_TRIGGER_MASTER_INT | _TAUD_OVERFLOW_AUTO_CLEAR | _TAUD_ONE_COUNT_MODE | 
                  _TAUD_START_TRIGGER_ENABLE;
    /* Set compare match register */
    TAUD0.CMUR2 = _TAUD_INPUT_EDGE_UNUSED;
    TAUD0.CDR2 = _TAUD0_CHANNEL2_COMPARE_VALUE;
    /* Set output mode setting */
    TAUD0.TOE |= _TAUD_CHANNEL2_ENABLES_OUTPUT_MODE;
    TAUD0.TOM |= _TAUD_CHANNEL2_SYNCHRONOUS_OUTPUT_MODE;
    TAUD0.TOC &= _TAUD_CHANNEL2_OPERATION_MODE1;
    TAUD0.TOL &= _TAUD_CHANNEL2_POSITIVE_LOGIC;
    TAUD0.TDE &= _TAUD_CHANNEL2_DISABLE_DEAD_TIME_OPERATE;
    TAUD0.TDM &= _TAUD_CHANNEL2_DETECTING_DUTY_CYCLE;
    TAUD0.TDL &= _TAUD_CHANNEL2_NORMAL_PHASE;
    TAUD0.TRE &= _TAUD_CHANNEL2_REAL_TIME_OUTPUT_DISABLES;
    /* Synchronization processing */
    g_cg_sync_read = TAUD0.TPS;
    __syncp();

    /* Set TAUD0O2 pin */
    PORT.PIBC9 &= _PORT_CLEAR_BIT1;
    PORT.PBDC9 &= _PORT_CLEAR_BIT1;
    PORT.PM9 |= _PORT_SET_BIT1;
    PORT.PMC9 &= _PORT_CLEAR_BIT1;
    PORT.PFC9 |= _PORT_SET_BIT1;
    PORT.PFCE9 &= _PORT_CLEAR_BIT1;
    PORT.PFCAE9 &= _PORT_CLEAR_BIT1;
    PORT.PMC9 |= _PORT_SET_BIT1;
    PORT.PM9 &= _PORT_CLEAR_BIT1;

    R_Config_TAUD0_Create_UserInit();
}

/***********************************************************************************************************************
* Function Name: R_Config_TAUD0_Start
* Description  : This function starts the TAUD0 channel counter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_TAUD0_Start(void)
{
    /* Enable channel counter operation */
    TAUD0.TS |= (_TAUD_CHANNEL2_COUNTER_START | _TAUD_CHANNEL0_COUNTER_START);
}

/***********************************************************************************************************************
* Function Name: R_Config_TAUD0_Stop
* Description  : This function stop the TAUD0 channel counter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_TAUD0_Stop(void)
{
    /* Disable channel counter operation */
    TAUD0.TT |= (_TAUD_CHANNEL2_COUNTER_STOP | _TAUD_CHANNEL0_COUNTER_STOP);
    /* Synchronization processing */
    g_cg_sync_read = TAUD0.TT;
    __syncp();
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
