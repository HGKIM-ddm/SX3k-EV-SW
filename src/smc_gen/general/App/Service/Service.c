#include "Service.h"

static ActMode_t act_mode = ACT_MODE_NORMAL;

/***********************************************************************************************************************
 * Function Name: Service_SelectMode
 * Description  : 모드 요청 플래그로 이번 루프에 실행할 최상위 모드 1개를 결정
 * Called By    : App_SwLogic
 ***********************************************************************************************************************/
static ActMode_t Service_SelectMode(void)
{
    ActMode_t mode = ACT_MODE_NORMAL;

    if (lin_bus_inactive_flag == ON)
    {
        mode = ACT_MODE_SLEEP;
    }
    else if ((protection_function == ON) || (voltage_protection_function == ON) || (protection_Mode_step != 0U))
    {
        mode = ACT_MODE_PROTECTION;
    }
    else if ((LIMP_HOME_Count >= LIMP_HOME_ENTRY_COUNT) || (LIMP_HOME_step != 0U))
    {
        mode = ACT_MODE_LIMPHOME;
    }
    else
    {
        /* NORMAL */
    }

#ifdef ENABLE_AAF_UI
    if (AAF_Maximum_Torque_Test_Mode == ON)
    {
        mode = ACT_MODE_TORQUE_TEST;
    }
#endif

    return mode;
}

/***********************************************************************************************************************
 * Function Name: Service_NormalAbort
 * Description  : NORMAL 그룹이 상위 모드에 선점될 때 진행 중 시퀀스 정리
 * Called By    : Service_ChangeMode
 ***********************************************************************************************************************/
static void Service_NormalAbort(void)
{
    Operate_Abort();
    Antipinch_Abort();
    FailSafety_Abort();
}

/***********************************************************************************************************************
 * Function Name: Service_ChangeMode
 * Description  : 상위 모드 선점 시 모터 정지 + 하위 모드 Abort.
 *                하위로 내려갈 때는 상위 모드가 스스로 Re_Init 후 종료하므로 처리 없음
 * Called By    : App_SwLogic
 ***********************************************************************************************************************/
static void Service_ChangeMode(ActMode_t next)
{
    if (next > act_mode)
    {
        Motor_Off();
        G_Timer1msFlag.InitCheckFlag = 0U;
        G_Timer1ms.InitCheck = 0U;

        switch (act_mode)
        {
        case ACT_MODE_NORMAL:
            Service_NormalAbort();
            break;
        case ACT_MODE_LIMPHOME:
            LimpHome_Abort();
            break;
        case ACT_MODE_PROTECTION:
            Protection_Abort();
            break;
        default:
            break;
        }
    }

    act_mode = next;
}

/***********************************************************************************************************************
 * Function Name: Service_RunMode
 * Description  : 선택된 모드의 시퀀스만 실행
 * Called By    : App_SwLogic
 ***********************************************************************************************************************/
static void Service_RunMode(void)
{
    switch (act_mode)
    {
    case ACT_MODE_NORMAL:
        if (G_Timer1ms.ProtectionCheck == 550)
        {
            Operating_Mode();
        }
        FailSafety_Mode();
        if ((antipinch_previous_action == OPEN) || (antipinch_previous_action == CLOSE))
        {
            Antipinch_Move();
        }
        break;
    case ACT_MODE_LIMPHOME:
        Limp_Home();
        break;
    case ACT_MODE_PROTECTION:
        Protection_Mode();
        break;
    case ACT_MODE_SLEEP:
        Lin_Sleep();
        break;
#ifdef ENABLE_AAF_UI
    case ACT_MODE_TORQUE_TEST:
        Torque_TestMode();
        break;
#endif
    default:
        break;
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
 * Description  : 입력 갱신 → 모드 결정 → 선택 모드 실행
 * Called By    : AAF_App
 ***********************************************************************************************************************/
void App_SwLogic(void)
{
    Communication_Check();

    Lin_BusCheck();
    
    ProtectionMode_Check();

    Service_ChangeMode(Service_SelectMode());
    
    Service_RunMode();

    Step_InitAndCheck();
}
