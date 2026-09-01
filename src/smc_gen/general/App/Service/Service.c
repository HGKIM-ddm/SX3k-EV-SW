#include "Service.h"
    
/***********************************************************************************************************************
 * Function Name: Mode_Check
 * Description  : Checks and executes the primary operation modes (Normal, Test, Sleep).
 * Called By    : App_SwLogic
 ***********************************************************************************************************************/
static void Mode_Check(void)
{
    if ((protection_function == OFF) && (voltage_protection_function == OFF) && (protection_Mode_step == 0U) && (lin_bus_inactive_flag == OFF) && (AAF_Maximum_Torque_Test_Mode == OFF) && (G_Timer1ms.ProtectionCheck == 550)) 
    {
        Operating_Mode();
    }
    else if (AAF_Maximum_Torque_Test_Mode == ON) 
    {
        Torque_TestMode();
    }
    else if (lin_bus_inactive_flag == ON)
    {
        Lin_Sleep();
    }
    else
    {
        // invalid
    }

}

/***********************************************************************************************************************
 * Function Name: Communication_Check
 * Description  : Handles all communication related checks (LIN Rx/Tx).
 * Called By    : App_SwLogic
 ***********************************************************************************************************************/
static void Communication_Check(void)
{
    Lin_RxCheck();
    Lin_TxCheck();
    Lin_NrstCheck();
}   

/***********************************************************************************************************************
 * Function Name: Safety_Check
 * Description  : Checks and executes safety (Fail-safe, Antipinch) and protection modes.
 * Called By    : App_SwLogic
 ***********************************************************************************************************************/
static void Safety_Check(void)
{
    // 1. Fail Safety Mode
    if ((protection_function == OFF) && (voltage_protection_function == OFF) && (protection_Mode_step == 0U) && (lin_bus_inactive_flag == OFF) && (AAF_Maximum_Torque_Test_Mode == OFF))
    {
        FailSafety_Mode();
    }

    // 2. Anti-Pinch Logic
    if ((antipinch_previous_action == OPEN) || (antipinch_previous_action == CLOSE))
    {
        Antipinch_Move();
    }

    // 3. LIN Bus Check 
    Lin_BusCheck();

    // 4. Protection Mode
    ProtectionMode_Check();

   if (((protection_function == ON) || (voltage_protection_function == ON) || (protection_Mode_step != 0U)) && (lin_bus_inactive_flag == OFF) && (AAF_Maximum_Torque_Test_Mode == OFF))
    {
        Protection_Mode();
    }
}

void AAF_SetType(void)
{
	//Macro
	AAFx_Type           = CONFIG_AAF_TYPE;
    AAFx_Index          = CONFIG_AAF_INDEX;
    AAF_location_type   = CONFIG_AAF_LOCATION;
    TotalNumOfAAF       = CONFIG_AAF_TOTAL;
    TotalNumOfAAFSensor = CONFIG_SENSOR_TOTAL;
	//init
	aaf_step = AAF_INITIALIZATION;
	aaf_init_step = WAIT_INITIALIZATION;
	AAF_Tx_Position = UNKOWN_POSITION;
	AAFx_Position_Status = Unknown_Status;
	AAFx_InitStatus = DURING_INITIALIZATION;
}

void App_HwCheck(void)
{
    Error_CheckAfterIGN();

    ADC_GetStatus();

    ADC_TrqCountSample();

    FaultCheck_Sample();
}

/***********************************************************************************************************************
 * Function Name: App_SwLogic
 * Description  : Monitors software-level states executing logic in the EXACT order of the original loop.
 * Called By    : AAF_App
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
void App_SwLogic(void)
{
    // [Sequence 1] Main Operation Mode Check
    Mode_Check();

    // [Sequence 2] Communication Check
    Communication_Check();

    // [Sequence 3] External Factors Check
    //CHK_external_factors();

    // [Sequence 4] Safety & Protection Logic (Fail-safe, Antipinch, LIN Bus, Protection)
    Safety_Check();

    // [Sequence 5] Step Initialization Check
    Step_InitAndCheck();
}
