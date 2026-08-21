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
* File Name        : Config_STBC.c
* Component Version: 1.3.3
* Device(s)        : R7F701695
* Description      : This file implements device driver for Config_STBC.
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
#include "Config_STBC.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_STBC_Prepare_Deep_Stop_Mode
* Description  : This function prepares STBC deep stop mode.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_STBC_Prepare_Deep_Stop_Mode(void)
{
    /* Stop all of the peripheral functions to which the clock supply is to be stopped */
    R_Config_STBC_Prepare_Deep_Stop_Mode_Set_Peripheral();
    /* Disable interrupts */
    DI();
    /* Clear all interrupt flags */
    R_Config_STBC_Prepare_Deep_Stop_Mode_Set_Interrupt();
    /* Clear wake-up factor */
    STBC_WUF0.WUFC0 = _STBC_WUFC0_CLEAR_S1_4864PIN;
    STBC_WUF1.WUFC1 = _STBC_WUFC1_CLEAR_S1;
    STBC_WUF20.WUFC20 = _STBC_WUFC20_CLEAR_S1_48PIN;
    /* Enable wake-up factor */
    STBC_WUF0.WUFMSK0 = _STBC_FACTOR_DEFAULT_VALUE & _STBC_WUFMSK0_FACTOR_INTP5;
    STBC_WUF1.WUFMSK1 = _STBC_FACTOR_DEFAULT_VALUE;
    STBC_WUF20.WUFMSK20 = _STBC_FACTOR_DEFAULT_VALUE;
    /* Set the masks for the clock domains */
    R_Config_STBC_Prepare_Deep_Stop_Mode_Set_Clock_Mask();
    /* Set the masks for the source clocks */
    R_Config_STBC_Prepare_Deep_Stop_Mode_Set_Clock_Source();
    /* Clear reset flag */
    RESCTL.RESFC |= _RESFC_RESET_FLAG_CLEAR;
}

/***********************************************************************************************************************
* Function Name: R_Config_STBC_Start_Deep_Stop_Mode
* Description  : This function starts Deep Stop Mode.
* Arguments    : None
* Return Value : status -
*                    MD_OK, MD_ERROR
***********************************************************************************************************************/
MD_STATUS R_Config_STBC_Start_Deep_Stop_Mode(void)
{
    MD_STATUS status = MD_ERROR;
    volatile uint32_t w_count = 0;

    do {
        WPROTR.PROTCMD0 = _WRITE_PROTECT_COMMAND;
        STBC0.PSC = _STBC_DEEP_STOP_MODE_ENTERED;
        STBC0.PSC = (uint32_t) ~_STBC_DEEP_STOP_MODE_ENTERED;
        STBC0.PSC = _STBC_DEEP_STOP_MODE_ENTERED;
        if ((WPROTR.PROTS0 & _WRITE_PROTECT_ERROR_OCCUR) == _WRITE_PROTECT_ERROR_NOT_OCCUR) {
            status = MD_OK;
            R_Config_STBC_Deep_Stop_Loop();
            break;
        } else {
            w_count++;
        }
    } while (w_count < _STBC_ERROR_MONITOR_WAITTIME); /* Change the waiting time according to the system */

    return status;
}

/***********************************************************************************************************************
* Function Name: R_Config_STBC_Deep_Stop_Loop
* Description  : This function Deep_Stop_Loop.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_STBC_Deep_Stop_Loop(void)
{
    /* Start user code for R_Config_STBC_Deep_Stop_Loop. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
