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
* File Name        : Config_CSIH0.h
* Component Version: 1.4.2
* Device(s)        : R7F701695
* Description      : This file implements device driver for Config_CSIH0.
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_csih.h"

#ifndef CFG_Config_CSIH0_H
#define CFG_Config_CSIH0_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
#define _CSIH0_MASTER_PCLK_DIV                         (0xA000U) /* Selects the basic clock */
#define _CSIH0_SELECT_CHIP_SUM                         (0x00030000UL) /* CSIH select chip sum */
#define _CSIH0_SETTING_INIT                            (0x00FF0000UL) /* CSIH setting init value */
#define _CSIH0_BAUD_RATE_0                             (0x007DU) /* baudrate set */
#define _CSIH0_BAUD_RATE_1                             (0x007DU) /* baudrate set */
#define _CSIH0_BAUD_RATE_2                             (0x007DU) /* baudrate set */
#define _CSIH0_BAUD_RATE_3                             (0x007DU) /* baudrate set */

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
void R_Config_CSIH0_Create(void);
void R_Config_CSIH0_Start(void);
void R_Config_CSIH0_Stop(void);
MD_STATUS R_Config_CSIH0_Send_Receive(uint16_t* const tx_buf, uint16_t tx_num, uint16_t* const rx_buf, uint32_t chip_id);
void R_Config_CSIH0_Create_UserInit(void);
/* Start user code for function. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#endif
