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
* File Name        : Config_ADCA0.c
* Component Version: 1.9.0
* Device(s)        : R7F701695
* Description      : This file implements device driver for Config_ADCA0.
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
#include "Config_ADCA0.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
extern volatile uint32_t g_cg_sync_read;
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_ADCA0_Create
* Description  : This function initializes the ADC0 module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_ADCA0_Create(void)
{
    /* Disable ADC0 error interrupt (INTADCA0ERR) operation and clear request */
    INTC2.ICADCA0ERR.BIT.MKADCA0ERR = _INT_PROCESSING_DISABLED;
    INTC2.ICADCA0ERR.BIT.RFADCA0ERR = _INT_REQUEST_NOT_OCCUR;
    /* Disable ADC0 SG1 end interrupt (INTADCA0I0) operation and clear request */
    INTC1.ICADCA0I0.BIT.MKADCA0I0 = _INT_PROCESSING_DISABLED;
    INTC1.ICADCA0I0.BIT.RFADCA0I0 = _INT_REQUEST_NOT_OCCUR;
    /* Set ADC0 error interrupt (INTADCA0ERR) setting */
    INTC2.ICADCA0ERR.BIT.TBADCA0ERR = _INT_TABLE_VECTOR;
    INTC2.ICADCA0ERR.UINT16 &= _INT_PRIORITY_LOWEST;
    /* Set ADC0 SG1 end interrupt (INTADCA0I0) setting */
    INTC1.ICADCA0I0.BIT.TBADCA0I0 = _INT_TABLE_VECTOR;
    INTC1.ICADCA0I0.UINT16 &= _INT_PRIORITY_LOWEST;
    /* Set ADC0 virtual channel setting */
    ADCA0.VCR00.UINT32 = _ADC_MPX_DISABLE | _ADC_VIRTUAL_CHANNEL_END_INT_DISABLE | _ADC_LIMIT_TABLE_SELECT_0 | 
                         _ADC_PHYSICAL_CHANNEL_ANI05;
    /* Set ADC0 operation setting */
    ADCA0.ADCR.UINT32 = _ADC_SYNC_SUSPEND | _ADC_12_BIT_MODE | _ADC_RIGHT_ALIGNED;
    ADCA0.SMPCR.UINT32 = _ADC_SAMPLING_24_CYCLES;
    /* Set ADC0 error check setting */
    ADCA0.SFTCR.UINT32 = _ADC_READ_CLEAR_DISABLE | _ADC_LIMIT_ERROR_INT_ENABLE | _ADC_OVERWRITE_ERROR_INT_ENABLE;
    ADCA0.ULLMTBR0.UINT32 = _ADC0_UPPER_LIMIT_TABLE0 | _ADC0_LOWER_LIMIT_TABLE0;
    ADCA0.ULLMTBR1.UINT32 = _ADC0_UPPER_LIMIT_TABLE1 | _ADC0_LOWER_LIMIT_TABLE1;
    ADCA0.ULLMTBR2.UINT32 = _ADC0_UPPER_LIMIT_TABLE2 | _ADC0_LOWER_LIMIT_TABLE2;
    ADCA0.ULLMTBR3.UINT32 = _ADC0_UPPER_LIMIT_TABLE3 | _ADC0_LOWER_LIMIT_TABLE3;
    ADCA0.ULLMTBR4.UINT32 = _ADC0_UPPER_LIMIT_TABLE4 | _ADC0_LOWER_LIMIT_TABLE4;
    ADCA0.ULLMTBR5.UINT32 = _ADC0_UPPER_LIMIT_TABLE5 | _ADC0_LOWER_LIMIT_TABLE5;
    ADCA0.ULLMTBR6.UINT32 = _ADC0_UPPER_LIMIT_TABLE6 | _ADC0_LOWER_LIMIT_TABLE6;
    ADCA0.ULLMTBR7.UINT32 = _ADC0_UPPER_LIMIT_TABLE7 | _ADC0_LOWER_LIMIT_TABLE7;
    /* Set ADC0 self-diagnosis setting */
    ADCA0.DGCTL0.UINT32 = _ADC_SELF_DIAG_VOLTAGE_LEVEL_1;
    ADCA0.DGCTL1.UINT32 |= _ADC_SELF_DIAG_CH05_SEL_ANI05;
    /* Set ADC0 scan group setting */
    ADCA0.SGCR1.UINT32 = _ADC_SG_SCAN_MODE_CONTINUOUS | _ADC_SG_SCAN_END_INT_ENABLE | _ADC_SG_CHANNEL_REPEAT_TIME_4;
    ADCA0.SGVCSP1.UINT32 = _ADC0_SG1_START_POINTER;
    ADCA0.SGVCEP1.UINT32 = _ADC0_SG1_END_POINTER;
    ADCA0.SGMCYCR1.UINT32 = _ADC_SG_MULTICYCLE_NUMBER_1;
    /* Set ADC0 scan group trigger enable */
    ADCA0.SGCR1.UINT32 |= _ADC_SG_HW_TRIGGER_DISABLE;
    /* Synchronization processing */
    g_cg_sync_read = ADCA0.ADHALTR.UINT32;
    __syncp();
    /* Clear ADC0 error interrupt (INTADCA0ERR) request and enable operation */
    INTC2.ICADCA0ERR.BIT.RFADCA0ERR = _INT_REQUEST_NOT_OCCUR;
    INTC2.ICADCA0ERR.BIT.MKADCA0ERR = _INT_PROCESSING_ENABLED;

    R_Config_ADCA0_Create_UserInit();
}

/***********************************************************************************************************************
* Function Name: R_Config_ADCA0_Halt
* Description  : This function halts ADC0.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_ADCA0_Halt(void)
{
    /* All scan groups are halted and initialized */
    ADCA0.ADHALTR.UINT32 = _ADC_HALT;
    /* Disable ADC0 SG1 end interrupt (INTADCA0I0) operation and clear request */
    INTC1.ICADCA0I0.BIT.MKADCA0I0 = _INT_PROCESSING_DISABLED;
    INTC1.ICADCA0I0.BIT.RFADCA0I0 = _INT_REQUEST_NOT_OCCUR;
    /* Synchronization processing */
    g_cg_sync_read = ADCA0.ADHALTR.UINT32;
    __syncp();
}

/***********************************************************************************************************************
* Function Name: R_Config_ADCA0_SelfDiagnostic_VoltageCircuitOn
* Description  : This function turns on the self-diagnostic voltage circuit or update the reference voltage.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_ADCA0_SelfDiagnostic_VoltageCircuitOn(void)
{
    /* The self-diagnostic voltage circuit is turned on, or the reference voltage is updated */
    ADCA0.ADCR.UINT32 |= _ADC_SELF_DIAG_VOLTAGE_CIRCUIT_ON;
}

/***********************************************************************************************************************
* Function Name: R_Config_ADCA0_SelfDiagnostic_VoltageCircuitOff
* Description  : This function turns off the self-diagnostic voltage circuit.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_ADCA0_SelfDiagnostic_VoltageCircuitOff(void)
{
    /* The self-diagnostic voltage circuit is turned off */
    ADCA0.ADCR.UINT32 &= _ADC_SELF_DIAG_VOLTAGE_CIRCUIT_OFF;
}

/***********************************************************************************************************************
* Function Name: R_Config_ADCA0_ScanGroup1_Start
* Description  : This function enables ADC0 scan group 1 end interrupt.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_ADCA0_ScanGroup1_Start(void)
{
    /* Clear ADC0 SG1 end interrupt (INTADCA0I0) request and enable operation */
    INTC1.ICADCA0I0.BIT.RFADCA0I0 = _INT_REQUEST_NOT_OCCUR;
    INTC1.ICADCA0I0.BIT.MKADCA0I0 = _INT_PROCESSING_ENABLED;
}

/***********************************************************************************************************************
* Function Name: R_Config_ADCA0_ScanGroup1_OperationOn
* Description  : This function starts ADC0 scan group 1 conversion.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_ADCA0_ScanGroup1_OperationOn(void)
{
    /* Enable ADC0 SG1 operation */
    ADCA0.SGSTCR1.UINT32 = _ADC_START;
}

/***********************************************************************************************************************
* Function Name: R_Config_ADCA0_ScanGroup1_OperationOff
* Description  : This function stops ADC0 scan group 1 conversion.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_ADCA0_ScanGroup1_OperationOff(void)
{
    /* Disable ADC0 SG1 operation */
    ADCA0.SGSTPCR1.UINT32 = _ADC_STOP;
}

/***********************************************************************************************************************
* Function Name: R_Config_ADCA0_ScanGroup1_GetResult
* Description  : This function gets A/D conversion result for ADC0 scan group 1.
* Arguments    : buffer -
*                    buffer pointer
*                buffer_size -
*                    the size of buffer
* Return Value : MD_STATUS -
*                    MD_OK or MD_ARGERROR
***********************************************************************************************************************/
MD_STATUS R_Config_ADCA0_ScanGroup1_GetResult(uint16_t * const buffer, uint8_t buffer_size)
{
    uint8_t start_pointer;
    uint8_t end_pointer;
    uint8_t count_num;
    uint8_t buffer_index;
    uint32_t * p_addr;
    uint32_t convert_data;

    start_pointer = (uint8_t)ADCA0.SGVCSP1.UINT32;
    end_pointer = (uint8_t)ADCA0.SGVCEP1.UINT32;
    count_num = (end_pointer - start_pointer) + 1U;
    if (buffer_size < count_num)
    {
        return MD_ARGERROR;
    }

    p_addr = (uint32_t*)(_ADC0_VCHANNEL_DATA_BASE + (2U * start_pointer));

    for (buffer_index = 0U; buffer_index < count_num; buffer_index = buffer_index + 2U)
    {
        convert_data = (uint32_t) * p_addr;
        buffer[buffer_index] = (uint16_t)(convert_data & 0x0000FFFFUL);
        if ((count_num - buffer_index) > 1U)
        {
            buffer[buffer_index + 1U] = (uint16_t)((convert_data & 0xFFFF0000UL) >> 16U);
        }
        p_addr++;
    }

    return MD_OK;
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
