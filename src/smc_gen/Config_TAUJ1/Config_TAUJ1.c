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
* File Name        : Config_TAUJ1.c
* Component Version: 1.8.0
* Device(s)        : R7F701695
* Description      : This file implements device driver for Config_TAUJ1.
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
#include "Config_TAUJ1.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
extern volatile uint32_t g_cg_sync_read;
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_TAUJ1_Create
* Description  : This function initializes the TAUJ1 channel.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_TAUJ1_Create(void)
{
    /* Disable channel counter operation */
    TAUJ1.TT |= (_TAUJ_CHANNEL1_COUNTER_STOP | _TAUJ_CHANNEL0_COUNTER_STOP);
    /* Disable INTTAUJ1I0 operation and clear request */
    INTC2.ICTAUJ1I0.BIT.MKTAUJ1I0 = _INT_PROCESSING_DISABLED;
    INTC2.ICTAUJ1I0.BIT.RFTAUJ1I0 = _INT_REQUEST_NOT_OCCUR;
    /* Disable INTTAUJ1I1 operation and clear request */
    INTC2.ICTAUJ1I1.BIT.MKTAUJ1I1 = _INT_PROCESSING_DISABLED;
    INTC2.ICTAUJ1I1.BIT.RFTAUJ1I1 = _INT_REQUEST_NOT_OCCUR;
    /* Set INTTAUJ1I0 setting */
    INTC2.ICTAUJ1I0.BIT.TBTAUJ1I0 = _INT_TABLE_VECTOR;
    INTC2.ICTAUJ1I0.UINT16 &= _INT_PRIORITY_LEVEL7;
    TAUJ1.TPS &= _TAUJ_CK0_PRS_CLEAR;
    TAUJ1.TPS |= _TAUJ_CK0_PRE_PCLK_3;
    /* Set channel 0 setting */
    TAUJ1.CMOR0 = _TAUJ_SELECTION_CK0 | _TAUJ_COUNT_CLOCK_PCLK | _TAUJ_MASTER_CHANNEL | _TAUJ_START_TRIGGER_SOFTWARE | 
                  _TAUJ_OVERFLOW_AUTO_CLEAR | _TAUJ_INTERVAL_TIMER_MODE | _TAUJ_START_INT_GENERATED;
    /* Set compare match register */
    TAUJ1.CMUR0 = _TAUJ_INPUT_EDGE_UNUSED;
    TAUJ1.CDR0 = _TAUJ1_CHANNEL0_COMPARE_VALUE;
    /* Set output mode setting */
    TAUJ1.TOE &= _TAUJ_CHANNEL0_DISABLES_OUTPUT_MODE;
    /* Set channel 1 setting */
    TAUJ1.CMOR1 = _TAUJ_SELECTION_CK0 | _TAUJ_COUNT_CLOCK_PCLK | _TAUJ_SLAVE_CHANNEL | 
                  _TAUJ_START_TRIGGER_MASTER_INT | _TAUJ_OVERFLOW_AUTO_CLEAR | _TAUJ_ONE_COUNT_MODE | 
                  _TAUJ_START_TRIGGER_ENABLE;
    /* Set compare match register */
    TAUJ1.CMUR1 = _TAUJ_INPUT_EDGE_UNUSED;
    TAUJ1.CDR1 = _TAUJ1_CHANNEL1_COMPARE_VALUE;
    /* Set output mode setting */
    TAUJ1.TOE |= _TAUJ_CHANNEL1_ENABLES_OUTPUT_MODE;
    TAUJ1.TOM |= _TAUJ_CHANNEL1_SYNCHRONOUS_OPERATION;
    TAUJ1.TOC &= _TAUJ_CHANNEL1_OPERATION_MODE1;
    TAUJ1.TOL &= _TAUJ_CHANNEL1_POSITIVE_LOGIC;
    /* Synchronization processing */
    g_cg_sync_read = TAUJ1.TPS;
    __syncp();

    /* Set TAUJ1O1 pin */
    PORT.PIBC9 &= _PORT_CLEAR_BIT0;
    PORT.PBDC9 &= _PORT_CLEAR_BIT0;
    PORT.PM9 |= _PORT_SET_BIT0;
    PORT.PMC9 &= _PORT_CLEAR_BIT0;
    PORT.PFC9 &= _PORT_CLEAR_BIT0;
    PORT.PFCE9 &= _PORT_CLEAR_BIT0;
    PORT.PFCAE9 |= _PORT_SET_BIT0;
    PORT.PMC9 |= _PORT_SET_BIT0;
    PORT.PM9 &= _PORT_CLEAR_BIT0;

    R_Config_TAUJ1_Create_UserInit();
}

/***********************************************************************************************************************
* Function Name: R_Config_TAUJ1_Start
* Description  : This function starts the TAUJ1 channel counter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_TAUJ1_Start(void)
{
    /* Clear INTTAUJ1I0 request and enable operation */
    INTC2.ICTAUJ1I0.BIT.RFTAUJ1I0 = _INT_REQUEST_NOT_OCCUR;
    INTC2.ICTAUJ1I0.BIT.MKTAUJ1I0 = _INT_PROCESSING_ENABLED;
    /* Enable channel counter operation */
    TAUJ1.TS |= (_TAUJ_CHANNEL1_COUNTER_START | _TAUJ_CHANNEL0_COUNTER_START);
}

/***********************************************************************************************************************
* Function Name: R_Config_TAUJ1_Stop
* Description  : This function stop the TAUJ1 channel counter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_TAUJ1_Stop(void)
{
    /* Disable channel counter operation */
    TAUJ1.TT |= (_TAUJ_CHANNEL1_COUNTER_STOP | _TAUJ_CHANNEL0_COUNTER_STOP);
    /* Disable INTTAUJ1I0 operation and clear request */
    INTC2.ICTAUJ1I0.BIT.MKTAUJ1I0 = _INT_PROCESSING_DISABLED;
    INTC2.ICTAUJ1I0.BIT.RFTAUJ1I0 = _INT_REQUEST_NOT_OCCUR;
    /* Synchronization processing */
    g_cg_sync_read = TAUJ1.TT;
    __syncp();
}

/* Start user code for adding. Do not edit comment generated here */
/***********************************************************************************************************************
 * Function Name: R_Config_TAUJ1_SetCompareValue
 * Description  : TAUJ1 Channel0/1 compare 값을 변경함.
                Microstep 변경 시 STEP 출력 주기를 맞추기 위해 사용함.
 ***********************************************************************************************************************/
void R_Config_TAUJ1_SetCompareValue(uint32_t ch0_compare, uint32_t ch1_compare)
{
    /* Stop TAUJ1 channel 0/1 before changing compare values */
    TAUJ1.TT |= (_TAUJ_CHANNEL1_COUNTER_STOP | _TAUJ_CHANNEL0_COUNTER_STOP);

    g_cg_sync_read = TAUJ1.TT;
    __syncp();

    TAUJ1.CDR0 = ch0_compare;
    TAUJ1.CDR1 = ch1_compare;

    g_cg_sync_read = TAUJ1.CDR0;
    __syncp();
}
/* End user code. Do not edit comment generated here */
