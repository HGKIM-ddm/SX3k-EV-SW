#ifdef ENABLE_QAC_TEST
    #pragma PRQA_MESSAGES_OFF 0292
#endif
/************************************************************************************************************
* File Name     : $Source: main.c $
* Mod. Revision : $Revision: 1.18 $
* Mod. Date     : $Date: 2019/04/26 09:54:04JST $
* Device(s)     : RV40 Flash based RH850 microcontroller
* Description   : Application sample for usage of Renesas Flash Control Library (FCL)
************************************************************************************************************/

/************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only  intended for use with
* Renesas products. No other uses are authorized. This software is owned by Renesas Electronics
* Corporation and is protected under all applicable laws, including copyright laws.
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING THIS SOFTWARE,
* WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.
* TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR
* ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR
* CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE
* BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the
* availability of this software. By using this software, you agree to the additional terms and conditions
* found by accessing the  following link:
* www.renesas.com/disclaimer
*
* Copyright (C) 2015-2019 Renesas Electronics Corporation. All rights reserved.
************************************************************************************************************/

#ifdef ENABLE_QAC_TEST
    #pragma PRQA_MESSAGES_ON 0292
#endif

/************************************************************************************************************
* MISRA Rule:   MISRA-C 2004 rule 3.1 (QAC message 0292)
* Reason:       To support automatic insertion of revision, module name etc. by the source
*               revision control system it is necessary to violate the rule, because the
*               system uses non basic characters as placeholders.
* Verification: The placeholders are used in commentaries only. Therefore rule violation cannot
*               influence code compilation.
************************************************************************************************************/


/************************************************************************************************************
Includes   <System Includes> , "Project Includes"
************************************************************************************************************/
#include "r_typedefs.h"
#include "fcl_cfg.h"
#include "r_fcl_types.h"
#include "r_fcl.h"
#include "target.h"
#include "fcl_descriptor.h"
#include "fcl_user.h"

/************************************************************************************************************
Macro definitions
************************************************************************************************************/
#define FLMD0_PROTECTION_OFF    (0x01u)
#define FLMD0_PROTECTION_ON     (0x00u)

/************************************************************************************************************
Typedef definitions
************************************************************************************************************/


/************************************************************************************************************
Exported global variables (to be accessed by other files)
************************************************************************************************************/

/* This array reserves the copy area in the device RAM */
#define FCL_RAM_EXECUTION_AREA_SIZE 0x8000

#if R_FCL_COMPILER == R_FCL_COMP_GHS
    #pragma ghs startdata
    #pragma ghs section bss = ".FCL_RESERVED"
    #define R_FCL_NOINIT
#elif R_FCL_COMPILER == R_FCL_COMP_IAR
    #pragma segment = "FCL_RESERVED"
    #pragma location = "FCL_RESERVED"
    #define R_FCL_NOINIT __no_init
#elif R_FCL_COMPILER == R_FCL_COMP_REC
    #pragma section r0_disp32 "FCL_RESERVED"
    #define R_FCL_NOINIT
#endif

R_FCL_NOINIT uint8_t FCL_Copy_area[FCL_RAM_EXECUTION_AREA_SIZE];

#if R_FCL_COMPILER == R_FCL_COMP_GHS
    #pragma ghs section bss = default
    #pragma ghs enddata
#elif R_FCL_COMPILER == R_FCL_COMP_IAR
    /* location only for one function, so no default required */
#elif R_FCL_COMPILER == R_FCL_COMP_REC
    #pragma section default
#endif


/************************************************************************************************************
Private global variables and functions
************************************************************************************************************/

void FCL_Ctrl (void);

/************************************************************************************************************
 * Function name: <Add function name>
 ***********************************************************************************************************/
/**
 * <Add function description>
 *
 * @param[in,out] <Add parameter>      <Add parameter description>
 * @return        <Add return value>
 */
/***********************************************************************************************************/
void main (void)
{
    r_fcl_status_t ret;
    #if R_FCL_COMMAND_EXECUTION_MODE == R_FCL_HANDLER_CALL_USER
        uint32_t   (* fpFct)(void);
    #endif

    /* initialize CPU and clocks */
    R_FCL_INIT_CPU_AND_FPERIPHERAL_CLK

    #if (defined R_FCL_DEVICE_SPECIFIC_INIT)
        R_FCL_DEVICE_SPECIFIC_INIT
    #endif

    ret = R_FCL_Init (&sampleApp_fclConfig_enu);
    if (R_FCL_OK == ret)
    {
        ret = R_FCL_CopySections ();
        /***************************************************************************************************
         * NOTICE: For CC-RH (Renesas compiler)
         *   If you modify sample codes, and then the ".pcconst32" section may be created,
         *   you should also copy the ".pcconst32" section by yourself.
         ***************************************************************************************************/
    }

    if (R_FCL_OK == ret)
    {
        #if R_FCL_COMMAND_EXECUTION_MODE == R_FCL_HANDLER_CALL_USER
            fpFct = ( uint32_t (*)() )R_FCL_CalcFctAddr ( (uint32_t)(&FCL_Ctrl) );
            fpFct ();
        #else
            FCL_Ctrl ();
        #endif
    }

    while (1)
    {
        /* do nothing */
    }
} /* main */
