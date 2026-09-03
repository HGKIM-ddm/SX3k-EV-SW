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
* File Name        : Config_PORT.c
* Component Version: 1.7.1
* Device(s)        : R7F701695
* Description      : This file implements device driver for Config_PORT.
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
#include "Config_PORT.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
extern volatile uint32_t g_cg_sync_read;
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_PORT_Create
* Description  : This function initializes the PORT
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_PORT_Create(void)
{
    PORT.PIBC0 = _PORT_PIBC_INIT;
    PORT.PIBC8 = _PORT_PIBC_INIT;
    PORT.PIBC9 = _PORT_PIBC_INIT;
    PORT.PIBC10 = _PORT_PIBC_INIT;
    PORT.PBDC0 = _PORT_PBDC_INIT;
    PORT.PBDC8 = _PORT_PBDC_INIT;
    PORT.PBDC9 = _PORT_PBDC_INIT;
    PORT.PBDC10 = _PORT_PBDC_INIT;
    PORT.PM0 = _PORT_PM_INIT;
    PORT.PM8 = _PORT_PM_INIT;
    PORT.PM9 = _PORT_PM_INIT;
    PORT.PM10 = _PORT_PM_INIT;
    PORT.PMC0 = _PORT_PMC_INIT;
    PORT.PMC8 = _PORT_PMC_INIT;
    PORT.PMC9 = _PORT_PMC_INIT;
    PORT.PMC10 = _PORT_PMC_INIT;
    PORT.PIPC0 = _PORT_PIPC_INIT;
    PORT.PIPC10 = _PORT_PIPC_INIT;
    /* PORT0 setting */
    PORT.PPCMD0 = _WRITE_PROTECT_COMMAND;
    PORT.PDSC0 = _PORT_PDSCn1_SLOW_MODE_SELECT | _PORT_PDSCn2_SLOW_MODE_SELECT | _PORT_PDSCn3_SLOW_MODE_SELECT;
    PORT.PDSC0 = (uint32_t) ~(_PORT_PDSCn1_SLOW_MODE_SELECT | _PORT_PDSCn2_SLOW_MODE_SELECT | 
                 _PORT_PDSCn3_SLOW_MODE_SELECT);
    PORT.PDSC0 = _PORT_PDSCn1_SLOW_MODE_SELECT | _PORT_PDSCn2_SLOW_MODE_SELECT | _PORT_PDSCn3_SLOW_MODE_SELECT;
    PORT.PPCMD0 = _WRITE_PROTECT_COMMAND;
    PORT.PODC0 = _PORT_PODCn1_OPEN_DRAIN | _PORT_PODCn2_PUSH_PULL | _PORT_PODCn3_PUSH_PULL;
    PORT.PODC0 = (uint32_t) ~(_PORT_PODCn1_OPEN_DRAIN | _PORT_PODCn2_PUSH_PULL | _PORT_PODCn3_PUSH_PULL);
    PORT.PODC0 = _PORT_PODCn1_OPEN_DRAIN | _PORT_PODCn2_PUSH_PULL | _PORT_PODCn3_PUSH_PULL;
    PORT.PBDC0 = _PORT_PBDCn1_MODE_ENABLE | _PORT_PBDCn2_MODE_DISABLED | _PORT_PBDCn3_MODE_DISABLED;
    PORT.PU0 = _PORT_PUn0_PULLUP_OFF;
    PORT.PD0 = _PORT_PDn0_PULLDOWN_OFF;
    PORT.PIS0 = _PORT_PIS0_DEFAULT_VALUE | _PORT_PISn0_TYPE_SHMT4;
    PORT.P0 = _PORT_Pn1_OUTPUT_LOW | _PORT_Pn2_OUTPUT_HIGH | _PORT_Pn3_OUTPUT_LOW;
    PORT.PM0 = _PORT_PM0_DEFAULT_VALUE | _PORT_PMn0_MODE_INPUT | _PORT_PMn1_MODE_OUTPUT | _PORT_PMn2_MODE_OUTPUT | 
               _PORT_PMn3_MODE_OUTPUT;
    PORT.PIBC0 = _PORT_PIBCn0_INPUT_BUFFER_ENABLE;
    /* PORT8 setting */
    PORT.PPCMD8 = _WRITE_PROTECT_COMMAND;
    PORT.PODC8 = _PORT_PODCn0_PUSH_PULL;
    PORT.PODC8 = (uint32_t) ~(_PORT_PODCn0_PUSH_PULL);
    PORT.PODC8 = _PORT_PODCn0_PUSH_PULL;
    PORT.PBDC8 = _PORT_PBDCn0_MODE_DISABLED;
    PORT.P8 = _PORT_Pn0_OUTPUT_HIGH;
    PORT.PM8 = _PORT_PM8_DEFAULT_VALUE | _PORT_PMn0_MODE_OUTPUT | _PORT_PMn1_MODE_UNUSED;
    /* PORT9 setting */
    PORT.PPCMD9 = _WRITE_PROTECT_COMMAND;
    PORT.PODC9 = _PORT_PODCn1_PUSH_PULL;
    PORT.PODC9 = (uint32_t) ~(_PORT_PODCn1_PUSH_PULL);
    PORT.PODC9 = _PORT_PODCn1_PUSH_PULL;
    PORT.PBDC9 = _PORT_PBDCn1_MODE_DISABLED;
    PORT.P9 = _PORT_Pn1_OUTPUT_LOW;
    PORT.PM9 = _PORT_PM9_DEFAULT_VALUE | _PORT_PMn0_MODE_UNUSED | _PORT_PMn1_MODE_OUTPUT;
    /* PORT10 setting */
    PORT.PPCMD10 = _WRITE_PROTECT_COMMAND;
    PORT.PDSC10 = _PORT_PDSCn0_SLOW_MODE_SELECT | _PORT_PDSCn2_SLOW_MODE_SELECT | _PORT_PDSCn3_SLOW_MODE_SELECT | 
                  _PORT_PDSCn4_SLOW_MODE_SELECT;
    PORT.PDSC10 = (uint32_t) ~(_PORT_PDSCn0_SLOW_MODE_SELECT | _PORT_PDSCn2_SLOW_MODE_SELECT | 
                  _PORT_PDSCn3_SLOW_MODE_SELECT | _PORT_PDSCn4_SLOW_MODE_SELECT);
    PORT.PDSC10 = _PORT_PDSCn0_SLOW_MODE_SELECT | _PORT_PDSCn2_SLOW_MODE_SELECT | _PORT_PDSCn3_SLOW_MODE_SELECT | 
                  _PORT_PDSCn4_SLOW_MODE_SELECT;
    PORT.PPCMD10 = _WRITE_PROTECT_COMMAND;
    PORT.PODC10 = _PORT_PODCn0_PUSH_PULL | _PORT_PODCn2_PUSH_PULL | _PORT_PODCn3_PUSH_PULL | _PORT_PODCn4_PUSH_PULL;
    PORT.PODC10 = (uint32_t) ~(_PORT_PODCn0_PUSH_PULL | _PORT_PODCn2_PUSH_PULL | _PORT_PODCn3_PUSH_PULL | 
                  _PORT_PODCn4_PUSH_PULL);
    PORT.PODC10 = _PORT_PODCn0_PUSH_PULL | _PORT_PODCn2_PUSH_PULL | _PORT_PODCn3_PUSH_PULL | _PORT_PODCn4_PUSH_PULL;
    PORT.PBDC10 = _PORT_PBDCn0_MODE_DISABLED | _PORT_PBDCn2_MODE_DISABLED | _PORT_PBDCn3_MODE_DISABLED | 
                  _PORT_PBDCn4_MODE_DISABLED;
    PORT.PU10 = _PORT_PUn1_PULLUP_OFF | _PORT_PUn5_PULLUP_OFF | _PORT_PUn6_PULLUP_OFF | _PORT_PUn7_PULLUP_OFF | 
                _PORT_PUn8_PULLUP_OFF | _PORT_PUn9_PULLUP_OFF | _PORT_PUn10_PULLUP_OFF;
    PORT.PD10 = _PORT_PDn1_PULLDOWN_OFF | _PORT_PDn5_PULLDOWN_OFF | _PORT_PDn6_PULLDOWN_OFF | 
                _PORT_PDn7_PULLDOWN_OFF | _PORT_PDn8_PULLDOWN_OFF | _PORT_PDn9_PULLDOWN_OFF | _PORT_PDn10_PULLDOWN_OFF;
    PORT.PIS10 = _PORT_PIS10_DEFAULT_VALUE | _PORT_PISn1_TYPE_SHMT4 | _PORT_PISn5_TYPE_SHMT4 | 
                 _PORT_PISn6_TYPE_SHMT4 | _PORT_PISn7_TYPE_SHMT4 | _PORT_PISn8_TYPE_SHMT4 | _PORT_PISn9_TYPE_SHMT4 | 
                 _PORT_PISn10_TYPE_SHMT4;
    PORT.P10 = _PORT_Pn0_OUTPUT_LOW | _PORT_Pn2_OUTPUT_LOW | _PORT_Pn3_OUTPUT_LOW | _PORT_Pn4_OUTPUT_LOW;
    PORT.PM10 = _PORT_PM10_DEFAULT_VALUE | _PORT_PMn0_MODE_OUTPUT | _PORT_PMn1_MODE_UNUSED | _PORT_PMn2_MODE_OUTPUT | 
                _PORT_PMn3_MODE_OUTPUT | _PORT_PMn4_MODE_OUTPUT | _PORT_PMn5_MODE_INPUT | _PORT_PMn6_MODE_UNUSED | 
                _PORT_PMn7_MODE_UNUSED | _PORT_PMn8_MODE_UNUSED | _PORT_PMn9_MODE_UNUSED | _PORT_PMn10_MODE_UNUSED;
    PORT.PIBC10 = _PORT_PIBCn5_INPUT_BUFFER_ENABLE;
    /* Synchronization processing */
    g_cg_sync_read = PORT.PM0;
    __syncp();

    R_Config_PORT_Create_UserInit();
}


/* Start user code for adding. Do not edit comment generated here */
void R_PORT_SetAltFunc(enum port_t Port, uint32_t Pin, enum alt_t Alt, enum io_t IO)
{   
    switch(Alt)
    {
        case Alt1:
            *PortList[Port].PFCAE_Reg &= ~(1<<Pin);
            *PortList[Port].PFCE_Reg &= ~(1<<Pin);
            *PortList[Port].PFC_Reg &= ~(1<<Pin);
        break;
        
        case Alt2:
            *PortList[Port].PFCAE_Reg &= ~(1<<Pin);
            *PortList[Port].PFCE_Reg &= ~(1<<Pin);
            *PortList[Port].PFC_Reg |= 1<<Pin;
        break;
        
        case Alt3:
            *PortList[Port].PFCAE_Reg &= ~(1<<Pin);
            *PortList[Port].PFCE_Reg |= 1<<Pin;
            *PortList[Port].PFC_Reg &= ~(1<<Pin);
        break;
        
        case Alt4:
            *PortList[Port].PFCAE_Reg &= ~(1<<Pin);
            *PortList[Port].PFCE_Reg |= 1<<Pin;
            *PortList[Port].PFC_Reg |= 1<<Pin;
        break;
        
        case Alt5:
            *PortList[Port].PFCAE_Reg |= 1<<Pin;
            *PortList[Port].PFCE_Reg &= ~(1<<Pin);
            *PortList[Port].PFC_Reg &= ~(1<<Pin);
        break;
        
        case Alt6:
            *PortList[Port].PFCAE_Reg |= 1<<Pin;
            *PortList[Port].PFCE_Reg &= ~(1<<Pin);
            *PortList[Port].PFC_Reg |= 1<<Pin;
        break;
        
        case Alt7:
            *PortList[Port].PFCAE_Reg |= 1<<Pin;
            *PortList[Port].PFCE_Reg |= 1<<Pin;
            *PortList[Port].PFC_Reg &= ~(1<<Pin);
        break;
        
        default:
        break;
    }
    
    switch(IO)
    {
        case Input:
            *PortList[Port].PM_Reg |= 1<<Pin;
        break;
        
        case Output:
            *PortList[Port].PM_Reg &= ~(1<<Pin);
        break;
        
        default:
        break;
        
    }
    
    *PortList[Port].PMC_Reg |= 1u<<Pin;
}

void R_PORT_ResetAltFunc(enum port_t Port, uint32_t Pin, enum io_t IO)
{   
    switch(IO)
    {
        case Input:
            *PortList[Port].PM_Reg |= 1<<Pin;
        break;
        
        case Output:
            *PortList[Port].PM_Reg &= ~(1<<Pin);
        break;
        
        default:
        break;
        
    }
    
    *PortList[Port].PMC_Reg &= ~(1<<Pin);
}

uint32_t R_PORT_GetLevel(enum port_t Port, uint32_t Pin)
{
    uint16_t PortLevel;
    
    PortLevel = *PortList[Port].PPR_Reg;
    PortLevel &= 1<<Pin;
    
    if(PortLevel == 0)
        {
            return 0;
        }
    else
        {
            return 1;
        }
}
/* End user code. Do not edit comment generated here */
