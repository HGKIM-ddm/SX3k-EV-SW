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
    
    #ifdef ENABLE_AAF_UI
    else if (AAF_Maximum_Torque_Test_Mode == ON) 
    {
        Torque_TestMode();
    }
    #endif

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

#ifdef EMC_STANDALONE
static void Emc_Standalone(void)
{
    /* LIN 수신값 고정 (마스터 없음) */
    LDCRdy                = 0x01U;   /* Driverable → 부팅 초기화 진행 */
    AAF_LINOut            = 0x01U;   /* Normal Operation */
    AAF_ProtectionMode_Rx = 0U;
    CR_Mcu_VehSpdInt_Kph  = 0U;
    G_Timer1ms.LinBusInactive = 0U;  /* Bus Inactive(4s) → Sleep 진입 방지 */
    LIMP_HOME_Count       = 0U;      /* LIN 노이즈 에러로 Limp Home 진입 방지 */

    /* 초기화 완료 후 DIAG AUTO 1회 기동 → 이후 FW가 OPEN/CLOSE 자동 반복 */
    if ((AAFx_InitStatus == NORMAL_FINISHED_INITIALIZATION) && (aaf_step == AAF_WAITING) &&
        (diag_mode_auto_action == OFF) && (motor_start == OFF))
    {
        lin_aaf_command = DIAG_MODE_AUTO;
        step_start_flag = ON;
    }
}
#endif

/***********************************************************************************************************************
 * Function Name: App_SwLogic
 * Description  : Monitors software-level states executing logic in the EXACT order of the original loop.
 * Called By    : AAF_App
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
void App_SwLogic(void)
{

    #ifdef EMC_STANDALONE
    Emc_Standalone();
    #endif
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
