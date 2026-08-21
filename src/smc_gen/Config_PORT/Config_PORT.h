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
* File Name        : Config_PORT.h
* Component Version: 1.8.0
* Device(s)        : R7F701695
* Description      : This file implements device driver for Config_PORT.
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_port.h"

#ifndef CFG_Config_PORT_H
#define CFG_Config_PORT_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
#define _PORT_PM0_DEFAULT_VALUE                   (0xFFF0U) /* PM0 default value */
#define _PORT_PM8_DEFAULT_VALUE                   (0xFFFCU) /* PM8 default value */
#define _PORT_PM9_DEFAULT_VALUE                   (0xFFFCU) /* PM9 default value */
#define _PORT_PM10_DEFAULT_VALUE                  (0xF800U) /* PM10 default value */
#define _PORT_PIS0_DEFAULT_VALUE                  (0xFFF0U) /* PIS0 default value */
#define _PORT_PIS8_DEFAULT_VALUE                  (0xFFFCU) /* PIS8 default value */
#define _PORT_PIS9_DEFAULT_VALUE                  (0xFFFCU) /* PIS9 default value */
#define _PORT_PIS10_DEFAULT_VALUE                 (0xF800U) /* PIS10 default value */

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
void R_Config_PORT_Create(void);
void R_Config_PORT_Create_UserInit(void);
/* Start user code for function. Do not edit comment generated here */
enum port_t
{
    Port0 = 0,
    Port8,
    Port9,
    Port10,
    Port11,
    APort0
};

enum alt_t
{
    Alt1,
    Alt2,
    Alt3,
    Alt4,
    Alt5,
    Alt6,
    Alt7
};

enum io_t
{
    Input,
    Output
};

/* Structure of registers for each port */
struct pregs_t
{
    volatile uint16_t * P_Reg;
    volatile uint16_t * PNOT_Reg;
    volatile uint16_t * PM_Reg;
    volatile uint16_t * PMC_Reg;
    volatile uint16_t * PFC_Reg;
    volatile uint16_t * PFCE_Reg;
    volatile uint16_t * PFCAE_Reg;
    volatile uint16_t * PIPC_Reg;
    volatile uint16_t * PIBC_Reg;
    volatile const uint16_t * PPR_Reg;
    volatile uint16_t * PD_Reg;
    volatile uint16_t * PU_Reg;
    volatile uint32_t * PODC_Reg;
    volatile uint32_t * PDSC_Reg;
    volatile uint32_t * PPROTS_Reg;
    volatile uint32_t * PPCMD_Reg;
};

static const struct pregs_t PortList[]=
{
  {(volatile uint16_t *)&PORT.P0,(volatile uint16_t *) &PORT.PNOT0,(volatile uint16_t *) &PORT.PM0,(volatile uint16_t *) &PORT.PMC0, (volatile uint16_t *)&PORT.PFC0, (volatile uint16_t *)&PORT.PFCE0, (volatile uint16_t *)&PORT.PFCAE0, (volatile uint16_t *)&PORT.PIPC0, (volatile uint16_t *)&PORT.PIBC0,(volatile uint16_t *) &PORT.PPR0, (volatile uint16_t *)&PORT.PD0, (volatile uint16_t *)&PORT.PU0,(volatile uint32_t *)&PORT.PODC0, (volatile uint32_t *)&PORT.PDSC0, (volatile uint32_t *)&PORT.PPROTS0, (volatile uint32_t *)&PORT.PPCMD0},
  {(volatile uint16_t *)&PORT.P8, (volatile uint16_t *)&PORT.PNOT8, (volatile uint16_t *)&PORT.PM8, (volatile uint16_t *)&PORT.PMC8, (volatile uint16_t *)&PORT.PFC8, (volatile uint16_t *)&PORT.PFCE8, 0, 0, (volatile uint16_t *)&PORT.PIBC8, (volatile uint16_t *)&PORT.PPR8, (volatile uint16_t *)&PORT.PD8, (volatile uint16_t *)&PORT.PU8, (volatile uint32_t *)&PORT.PODC8, 0, (volatile uint32_t *)&PORT.PPROTS8, (volatile uint32_t *)&PORT.PPCMD8},
  {(volatile uint16_t *)&PORT.P9, (volatile uint16_t *)&PORT.PNOT9, (volatile uint16_t *)&PORT.PM9, (volatile uint16_t *)&PORT.PMC9, (volatile uint16_t *)&PORT.PFC9, (volatile uint16_t *)&PORT.PFCE9, (volatile uint16_t *)&PORT.PFCAE9, 0, (volatile uint16_t *)&PORT.PIBC9, (volatile uint16_t *)&PORT.PPR9, (volatile uint16_t *)&PORT.PD9, (volatile uint16_t *)&PORT.PU9, (volatile uint32_t *)&PORT.PODC9, 0, (volatile uint32_t *)&PORT.PPROTS9, (volatile uint32_t *)&PORT.PPCMD9},
  {(volatile uint16_t *)&PORT.P10, (volatile uint16_t *)&PORT.PNOT10, (volatile uint16_t *)&PORT.PM10, (volatile uint16_t *)&PORT.PMC10, (volatile uint16_t *)&PORT.PFC10, (volatile uint16_t *)&PORT.PFCE10, (volatile uint16_t *)&PORT.PFCAE10, (volatile uint16_t *)&PORT.PIPC10, (volatile uint16_t *)&PORT.PIBC10, (volatile uint16_t *)&PORT.PPR10, (volatile uint16_t *)&PORT.PD10, (volatile uint16_t *)&PORT.PU10, (volatile uint32_t *)&PORT.PODC10, (volatile uint32_t *)&PORT.PDSC10, (volatile uint32_t *)&PORT.PPROTS10, (volatile uint32_t *)&PORT.PPCMD10},
  {(volatile uint16_t *)&PORT.AP0, (volatile uint16_t *)&PORT.APNOT0, (volatile uint16_t *)&PORT.APM0, 0, 0, 0, 0, 0, (volatile uint16_t *)&PORT.APIBC0, (volatile uint16_t *)&PORT.APPR0, 0, 0, 0, 0, 0, 0}
  };
void R_PORT_SetAltFunc(enum port_t Port, uint32_t Pin, enum alt_t Alt, enum io_t IO);
void R_PORT_ResetAltFunc(enum port_t Port, uint32_t Pin, enum io_t IO);
uint32_t R_PORT_GetLevel(enum port_t Port, uint32_t Pin);
/* End user code. Do not edit comment generated here */
#endif
