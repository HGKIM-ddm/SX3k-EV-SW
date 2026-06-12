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
 * File Name        : r_cg_main.c
 * Version          : 1.0.151
 * Device(s)        : R7F701695
 * Description      : This file implements main function.
 ***********************************************************************************************************************/
/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_smc_entry.h"
/* Start user code for include. Do not edit comment generated here */
#include "target.h"
#include "Service.h"
#include "Lin_Interrupt.h"

#ifdef UDS
#include "cpu.h"
#include "..\..\uds\def_lin_uds.h"
#include "..\..\uds\lin_uds.h"
#include "..\..\uds\util.h"
#endif

/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
void AAF_SetType(void);

static void AAF_Init(void);
static void AAF_App(void);

/* End user code. Do not edit comment generated here */
void r_main_userinit(void);

/***********************************************************************************************************************
 * Function Name: main
 * Description  : This function implements main function.
 * Arguments    : None
 * Return Value : None
 ***********************************************************************************************************************/
int main(void)
{
	r_main_userinit();
	/* Start user code for main. Do not edit comment generated here */

	R_Config_TAUD0_3_Start();
	R_Config_TAUD0_13_Start();
	R_Config_ADCA0_ScanGroup1_OperationOn();
	R_Config_CSIH0_Start();
	Lin_SlaveInit();
	R_Config_WDT0_Create();
	R_Config_WDT0_Restart();

	AAF_Init();

	while (1)
	{

		#ifdef UDS
		uds_state_check();
		#endif

		AAF_App();
	}

	/* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
 * Function Name: r_main_userinit
 * Description  : This function adds user code before implementing main function.
 * Arguments    : None
 * Return Value : None
 ***********************************************************************************************************************/
void r_main_userinit(void)
{
	DI();
	/* Start user code for r_main_userinit. Do not edit comment generated here */
	#ifdef UDS
	SET_INTBP(0xE400u);  	// interrupt vector base relocation
	#endif	
	/* End user code. Do not edit comment generated here */
	R_Systeminit();
	EI();
}

/* Start user code for adding. Do not edit comment generated here */




/***********************************************************************************************************************
 * Function Name: AAF_Init
 * Description  : This function is main user init
 * Arguments    : None
 * Return Value : None
 ***********************************************************************************************************************/
static void AAF_Init(void) 
{
	/* Unlock protection & Release I/O hold state */
	protected_write(WPROTR.PROTCMD0, WPROTR.PROTS0, STBC_IOHOLD.IOHOLD, 0x00u); 

	/* flash memory setup and error check */
	FDL_Init();
	/* lin transceiver on */
	LinTrcv_On();

	Drv8889_GpioInit();

	AAF_SetType();

	Drv8889_SpiInit();

	TRQ_COUNT = (unsigned int)(rx_16bit_spi[9] & 0xFFU);

	G_Timer1msFlag.VoltCheckDelayFlag = 1; // POWER ON AFTER 500ms

	motor_cw_stall_value = MOTOR_CW_STALL_CHK_VALUE_NORMAL_VOLTAGE;
	motor_ccw_stall_value = MOTOR_CCW_STALL_CHK_VALUE_NORMAL_VOLTAGE;

	diag_mode_auto_dir = OPEN;
	G_Timer1msFlag.ProtectionCheckFlag = 1;

	voltage_status_change_complete = COMPLETE;
}

/***********************************************************************************************************************
 * Function Name: AAF_App
 * Description  : Application Main Loop Function.
 * Called By    : Main Loop (while(1))
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
static void AAF_App(void) 
{
    // 1. Motor Action & Timer
    App_MotorAction();

    // 2. Hardware Signal Monitoring (IGN, ADC)
    App_HwCheck();

    // 3. Software Logic Execution (Modes, Comms, Safety)
    App_SwLogic();
    
    // 4. Watchdog Refresh
    R_Config_WDT0_Restart(); 
}

#ifdef UDS
#pragma ghs startdata
#pragma ghs section rodata="R_APP_VER"
const uint32_t ECU_SIGN[4] = {
	0,0,0,0
};
const uint8_t ECU_VER[] = {
	"SX3K_EV V0.0.1 RH850 2026.6.11\n\r"		// 012 로 VERSION READ 자리변동 금지.
};
#pragma ghs enddata
#endif

/* End user code. Do not edit comment generated here */
