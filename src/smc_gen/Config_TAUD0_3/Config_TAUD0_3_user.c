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
* File Name        : Config_TAUD0_3_user.c
* Component Version: 1.7.0
* Device(s)        : R7F701695
* Description      : This file implements device driver for Config_TAUD0_3.
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
#include "Config_TAUD0_3.h"
#include "Config.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_TAUD0_3_Create_UserInit
* Description  : This function adds user code after initializing the TAUD03 channel
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_TAUD0_3_Create_UserInit(void)
{
    /* Start user code for user init. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_Config_TAUD0_3_interrupt
* Description  : This function is TAUD03 interrupt service routine
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
#pragma ghs interrupt
void r_Config_TAUD0_3_interrupt(void)
{
    /* Start user code for r_Config_TAUD0_3_interrupt. Do not edit comment generated here */

    //Nomal Timer
    TIMER_1MS(InitMove);
    TIMER_1MS(AdcCheck);
    TIMER_1MS(External10sCheck);
    TIMER_1MS(Spi);
    TIMER_1MS(InitCheck);
    TIMER_1MS(StallCheck);
    TIMER_1MS(ProtectionMode);
    TIMER_1MS(StallTime);
    TIMER_1MS(MotorDelay);
    TIMER_1MS(VoltCheckDelay);
    TIMER_1MS(DiagAutoMode);
    TIMER_1MS(VoltStatChangeDelay);
    TIMER_1MS(MotorAcceleration);
    TIMER_1MS(InitFailCheck);
    TIMER_1MS(LinSleepMode);
    TIMER_1MS(AntipinchCheck);
    TIMER_1MS(SpiErrorCheck);
    TIMER_1MS(AdcErrorCheck);
    TIMER_1MS(FdlErrorCheck);
    TIMER_1MS(ProtectionCheck);
    TIMER_1MS(MotorMovingCheck);
    TIMER_1MS(MotorStepCheck);
    TIMER_1MS(WatchdogCheck);
    TIMER_1MS(ErrorCheck);
    // TIMER_1MS(ObdGndShort);
    // TIMER_1MS(ObdBatShort);
    // TIMER_1MS(ObdOpenCircuit);
    TIMER_1MS(MotorShortCheck);
    TIMER_1MS(MotorOpenCheck);
    TIMER_1MS(Adc1sCheck);
    TIMER_1MS(IgnCheck);
    // TIMER_1MS(ObdRecoveryCheck);
    TIMER_1MS(AdcRecoveryCheck);

    //Extra Timer

    G_Timer1ms.LinBusInactive++;

    if(G_Timer1msFlag.Timer3minuteFlag == 1)
    {
        G_Timer1ms.Timer3minute++;
        if(G_Timer1ms.Timer3minute >= 1000) 
        {
            G_Timer1ms.Timer3minuteSec++;
            G_Timer1ms.Timer3minute = 0;
        }
    }

    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
