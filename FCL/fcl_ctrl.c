#ifdef ENABLE_QAC_TEST
    #pragma PRQA_MESSAGES_OFF 0292
#endif
/************************************************************************************************************
* File Name     : $Source: fcl_ctrl.c $
* Mod. Revision : $Revision: 1.1 $
* Mod. Date     : $Date: 2019/04/26 09:04:53JST $
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
#define REINITIALIZE_BUFFER     for (i = 0; i < sizeof (writeBuffer_u08); i++)          \
                                {                                                       \
                                    writeBuffer_u08[i] = i;                             \
                                }                                                       \
                                for (i = 0; i < (sizeof (readBuffer_u32) >> 2); i++)    \
                                {                                                       \
                                    readBuffer_u32[i]  = 0xaa;                          \
                                }

/************************************************************************************************************
Typedef definitions
************************************************************************************************************/


/************************************************************************************************************
Exported global variables (to be accessed by other files)
************************************************************************************************************/

/************************************************************************************************************
Private global variables and functions
************************************************************************************************************/

#if R_FCL_COMMAND_EXECUTION_MODE == R_FCL_HANDLER_CALL_USER
    #if R_FCL_COMPILER == R_FCL_COMP_GHS
        #pragma ghs section text = ".R_FCL_CODE_USR"
    #elif R_FCL_COMPILER == R_FCL_COMP_IAR
        #pragma location = "R_FCL_CODE_USR"
    #elif R_FCL_COMPILER == R_FCL_COMP_REC
        #ifdef __PIC
            #pragma section pctext "R_FCL_CODE_USR"
        #else
            #pragma section text "R_FCL_CODE_USR"
        #endif
    #endif
#endif
void FCL_Ctrl (void)
{
    r_fcl_request_t     myRequest;
#if R_FCL_COMMAND_EXECUTION_MODE == R_FCL_HANDLER_CALL_USER
        r_fcl_request_t mySecRequest;
#endif
    uint8_t             writeBuffer_u08[512];
    uint32_t            readBuffer_u32[8];
    uint16_t            i;

    REINITIALIZE_BUFFER;

    FCLUser_Open ();

    /* prepare environment */
    myRequest.command_enu = R_FCL_CMD_PREPARE_ENV;
    R_FCL_Execute (&myRequest);
    #if R_FCL_COMMAND_EXECUTION_MODE == R_FCL_HANDLER_CALL_USER
        while (R_FCL_BUSY == myRequest.status_enu)
        {
            R_FCL_Handler ();
        }
    #endif

    /* get block count */
    myRequest.command_enu   = R_FCL_CMD_GET_BLOCK_CNT;
    myRequest.bufferAdd_u32 = (uint32_t)&readBuffer_u32[0];
    R_FCL_Execute (&myRequest);

    /* get block end address of block 2 */
    REINITIALIZE_BUFFER;
    myRequest.command_enu   = R_FCL_CMD_GET_BLOCK_END_ADDR;
    myRequest.bufferAdd_u32 = (uint32_t)&readBuffer_u32[0];
    myRequest.idx_u32       = 0x2;                   /* result: 0x5fff */
    R_FCL_Execute (&myRequest);

    /* erase block 2 and 3 */
    myRequest.command_enu = R_FCL_CMD_ERASE;
    myRequest.idx_u32     = 0x2;                   /* erased range = 0x4000 to 0x7fff */
    myRequest.cnt_u16     = 2;
    R_FCL_Execute (&myRequest);
    #if R_FCL_COMMAND_EXECUTION_MODE == R_FCL_HANDLER_CALL_USER
        while (R_FCL_BUSY == myRequest.status_enu)
        {
            R_FCL_Handler ();
        }
    #endif

    /* write 512 bytes to address 0x40000 (start of block 2) */
    REINITIALIZE_BUFFER;
    myRequest.command_enu = R_FCL_CMD_WRITE;
    myRequest.bufferAdd_u32 = (uint32_t)&writeBuffer_u08[0];
    myRequest.idx_u32       = 0x4000;
    myRequest.cnt_u16       = 2;                    /* written bytes = 256 * cnt_u16 */
    R_FCL_Execute (&myRequest);
    #if R_FCL_COMMAND_EXECUTION_MODE == R_FCL_HANDLER_CALL_USER
        while (R_FCL_BUSY == myRequest.status_enu)
        {
            R_FCL_Handler ();
        }
    #endif

    FCLUser_Close ();
} /* FCL_Ctrl */

