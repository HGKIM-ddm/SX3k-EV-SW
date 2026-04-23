#include "Lin_CHeck.h"
#include "Service.h"

#ifdef ENABLE_TORQUE_TEST
/***********************************************************************************************************************
 * Function Name: Lin_ParseTorqueTestMode
 * Description  : 토크 테스트 및 초기화 관련 플래그 파싱 및 즉각 Re_Init 검사 수행
 ***********************************************************************************************************************/
static void Lin_ParseTorqueTestMode(void)
{
    AAF_Init_Flag                = (unsigned int)((ID_chk_rxdata[1U] & 0x80U) >> 7U);
    AAF_Flap_Fixation_Test_Mode  = (unsigned int)((ID_chk_rxdata[2U] & 0x80U) >> 7U);
    AAF_Maximum_Torque_Test_Mode = (unsigned int)((ID_chk_rxdata[3U] & 0x80U) >> 7U);
    Re_Init_check                = (unsigned int)((ID_chk_rxdata[4U] & 0x80U) >> 7U);

    if (Re_Init_check == 0x01U)
    {
        Re_Init_check_flag = 1U;
    }
    else
    {
        Re_Init_check_flag = 0U;
    }

    if ((Re_Init_check_flag == 1U) && (aaf_step == AAF_WAITING) && (Re_Init_check_prev == 0U))
    {
        Re_Init();
    }
    Re_Init_check_prev = Re_Init_check;
}

/***********************************************************************************************************************
 * Function Name: Lin_ExecuteTorqueTestMode
 * Description  : 파싱된 플래그를 기반으로 토크, 고정 테스트 모드 토글 동작 및 초기화 수행
 ***********************************************************************************************************************/
static void Lin_ExecuteTorqueTestMode(void)
{
    if ((AAF_Init_Flag_tog == OFF) && (AAF_Init_Flag == ON))
    {
        if ((AAF1_TargetPosition == 0x7FU) || (AAF2_TargetPosition == 0x7FU) || (AAF3_TargetPosition == 0x7FU))
        {
            wake_up_motor_range_init_chk = 0U;
            evrdy_on_flag = OFF;
            Re_Init();
        }
        AAF_Init_Flag_tog = ON;
    }
    else if ((AAF_Init_Flag_tog == ON) && (AAF_Init_Flag == OFF))
    {
        AAF_Init_Flag_tog = OFF;
    }
    else
    {
        // Waiting
    }

    if ((AAF_Flap_Fixation_Test_Mode_tog == OFF) && (AAF_Flap_Fixation_Test_Mode == ON))
    {
        AAF_Flap_Fixation_Test_Mode_tog = ON;
    }
    else if ((AAF_Flap_Fixation_Test_Mode_tog == ON) && (AAF_Flap_Fixation_Test_Mode == OFF))
    {
        wake_up_motor_range_init_chk = 0U;
        evrdy_on_flag = OFF;
        Re_Init();
        AAF_Flap_Fixation_Test_Mode_tog = OFF;
    }
    else
    {
        // Waiting
    }

    if ((AAF_Maximum_Torque_Test_Mode_tog == OFF) && (AAF_Maximum_Torque_Test_Mode == ON))
    {
        AAF_Maximum_Torque_Test_Mode_tog = ON;
    }
    else if ((AAF_Maximum_Torque_Test_Mode_tog == ON) && (AAF_Maximum_Torque_Test_Mode == OFF))
    {
        wake_up_motor_range_init_chk = 0U;
        evrdy_on_flag = OFF;
        Re_Init();
        AAF_Maximum_Torque_Test_Mode_tog = OFF;
    }
    else
    {
        // Waiting
    }
}
#endif

static void Lin_DiagRx(void)
{
	if (Slave_RxSwData1[0U] == 0x26u)
	{
		if ((Slave_RxSwData1[1U] == 0x06U) && (Slave_RxSwData1[2U] == 0xB2U) && (Slave_RxSwData1[3U] == 0x01U) && (Slave_RxSwData1[4U] == 0x0Au) && (Slave_RxSwData1[5U] == 0x00U) && (Slave_RxSwData1[6U] == 0x0Bu) && (Slave_RxSwData1[7U] == 0x00U))
		{
			SW_Chk = 1U; // SW VER
		}
		else
		{
			SW_Chk = 3U;
		}
	}
	else if ((Slave_RxSwData1[0U] == 0x00U) && (Slave_RxSwData1[1U] == 0xFFu) && (Slave_RxSwData1[2U] == 0xFFu) && (Slave_RxSwData1[3U] == 0xFFu) && (Slave_RxSwData1[4U] == 0xFFu) && (Slave_RxSwData1[5U] == 0xFFu) && (Slave_RxSwData1[6U] == 0xFFu) && (Slave_RxSwData1[7U] == 0xFFu))
	{
		SW_Chk = 2U; // GO TO SLEEP
	}
	else
	{
		SW_Chk = 0U;
	}
}

static void Lin_DiagAction(void)
{
	if (SW_Chk == 1U)
	{
		Slave_SwData[0] = (uint8_t)(0x26u);
		Slave_SwData[1] = (uint8_t)(0x05u);
		Slave_SwData[2] = (uint8_t)(0xF2u);
		Slave_SwData[3] = (uint8_t)(0x03u); // VECHILE
		Slave_SwData[4] = (uint8_t)(0x11u); // ENGINE, MODEL
		Slave_SwData[5] = (uint8_t)(0x03u);
		Slave_SwData[6] = (uint8_t)(0x63u);
		Slave_SwData[7] = (uint8_t)(0xFFu);
	}
	else if (SW_Chk == 2U)
	{
		MCU_Sleep();
	}
	else if (SW_Chk == 3U)
	{
		Slave_SwData[0] = (uint8_t)(0x26u);
		Slave_SwData[1] = (uint8_t)(0x03u);
		Slave_SwData[2] = (uint8_t)(0x7Fu);
		Slave_SwData[3] = (uint8_t)(0xB2u);
		Slave_SwData[4] = (uint8_t)(0x12u);
		Slave_SwData[5] = (uint8_t)(0xFFu);
		Slave_SwData[6] = (uint8_t)(0xFFu);
		Slave_SwData[7] = (uint8_t)(0xFFu);
	}
	else
	{
		// invalid
	}
}

/***********************************************************************************************************************
 * Function Name: Lin_UpdateCommand
 * Description  : 파싱된 타겟 위치(target_select)에 따라 글로벌 제어 명령(lin_aaf_command)을 업데이트함
 * Arguments    : target_select - 결정된 목표 위치 또는 모드
 * Return Value : void
 ***********************************************************************************************************************/
static void Lin_UpdateCommand(unsigned int target_select)
{
    switch (target_select)
    {
    case CLOSE:
        lin_aaf_command = CLOSE;
        break;
    case OPEN_1ST:
        lin_aaf_command = OPEN_1ST;
        break;
    case OPEN_2ND:
        lin_aaf_command = OPEN_2ND;
        break;
    case OPEN:
        lin_aaf_command = OPEN;
        break;
    case DIAG_MODE_OPEN:
        lin_aaf_command = DIAG_MODE_OPEN;
        break;
    case DIAG_MODE_CLOSE:
        lin_aaf_command = DIAG_MODE_CLOSE;
        break;
    case DIAG_MODE_AUTO:
        lin_aaf_command = DIAG_MODE_AUTO;
        break;
    case UNKOWN_POSITION:
        lin_aaf_command = UNKOWN_POSITION;
        break;
    default:
        break;
    }
}

/***********************************************************************************************************************
 * Function Name: Lin_TranslateRxData
 * Description  : 수신된 LIN 데이터(Slave_RxData1)를 내부 검증용 버퍼(ID_chk_rxdata)로 복사함
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
static void Lin_TranslateRxData(void)
{
    if (lin_rx_chk_flag == ON)
    {
        for (uint8_t i = 0U; i < 8U; i++)
        {
            ID_chk_rxdata[i] = Slave_RxData1[i];
        }
        lin_rx_chk_flag = OFF;
        lin_rx_pass_flag = PASS;
    }
}

/***********************************************************************************************************************
 * Function Name: Lin_CheckAAF1RxData
 * Description  : AAF 1번 유닛에 대한 진단 모드 및 타겟 위치를 파싱하고 명령을 설정함
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
static void Lin_CheckAAF1RxData(void){
	
	if (ReqAAF1DiagMode == 0x00u)
	{
		if (AAF1_TargetPosition == 0x00u)
		{
			AAF1_TargetPosition_select = OPEN;
		}
		else if (AAF1_TargetPosition == 0x64u)
		{
			AAF1_TargetPosition_select = CLOSE;
		}
		else if (AAF1_TargetPosition == 0x7Fu)
		{
			AAF1_TargetPosition_select = UNKOWN_POSITION;
		}
		else
		{
			//invalid
		}
	}
	else if (ReqAAF1DiagMode == 0x01u)
	{
		AAF1_TargetPosition_select = DIAG_MODE_AUTO;
	}
	else if (ReqAAF1DiagMode == 0x02u)
	{
		AAF1_TargetPosition_select = DIAG_MODE_OPEN;
	}
	else if (ReqAAF1DiagMode == 0x03u)
	{
		AAF1_TargetPosition_select = DIAG_MODE_CLOSE;
	}
	else
	{
		//invalid
	}

	if (aaf_action_complete_chk == FLAP_STOP)
	{
		if ((AAF1_TargetPosition_select != AAF_Tx_Position) && (AAF_Tx_Position != UNKOWN_POSITION) && (AAF1_TargetPosition_select != UNKOWN_POSITION))
		{
			step_start_flag = ON;
		}
	}
	else if (aaf_action == DIAG_MODE_AUTO)
	{
		if (AAF1_TargetPosition_select != aaf_action)
		{
			step_start_flag = ON;
		}
	}
	else
	{
		//invalid
	}

	Lin_UpdateCommand(AAF1_TargetPosition_select);

}

/***********************************************************************************************************************
 * Function Name: Lin_CheckAAF2RxData
 * Description  : AAF 2번 유닛에 대한 진단 모드 및 타겟 위치를 파싱하고 명령을 설정함
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
static void Lin_CheckAAF2RxData(void){
	if (ReqAAF2DiagMode == 0x00u)
	{
		if (AAF2_TargetPosition == 0x00u)
		{
			AAF2_TargetPosition_select = OPEN;
		}
		else if (AAF2_TargetPosition == 0x64u)
		{
			AAF2_TargetPosition_select = CLOSE;
		}
		else if (AAF2_TargetPosition == 0x7Fu)
		{
			AAF2_TargetPosition_select = UNKOWN_POSITION;
		}
		else
		{
			//invalid
		}
	}
	else if (ReqAAF2DiagMode == 0x01u)
	{
		AAF2_TargetPosition_select = DIAG_MODE_AUTO;
	}
	else if (ReqAAF2DiagMode == 0x02u)
	{
		AAF2_TargetPosition_select = DIAG_MODE_OPEN;
	}
	else
	{
		AAF2_TargetPosition_select = DIAG_MODE_CLOSE;
	}

	if (aaf_action_complete_chk == FLAP_STOP)
	{
		if ((AAF2_TargetPosition_select != AAF_Tx_Position) && (AAF_Tx_Position != UNKOWN_POSITION) && (AAF2_TargetPosition_select != UNKOWN_POSITION))
		{
			step_start_flag = ON;
		}
	}
	else if (aaf_action == DIAG_MODE_AUTO)
	{
		if (AAF2_TargetPosition_select != aaf_action)
		{
			step_start_flag = ON;
		}
	}
	else
	{
		//invalid
	}

	Lin_UpdateCommand(AAF2_TargetPosition_select);
}

/***********************************************************************************************************************
 * Function Name: Lin_CheckAAF3RxData
 * Description  : AAF 3번 유닛에 대한 진단 모드 및 타겟 위치를 파싱하고 명령을 설정함
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
static void Lin_CheckAAF3RxData(void){
	if (ReqAAF3DiagMode == 0x00u)
	{
		if (AAF3_TargetPosition == 0x00u)
		{
			AAF3_TargetPosition_select = OPEN;
		}
		else if (AAF3_TargetPosition == 0x64u)
		{
			AAF3_TargetPosition_select = CLOSE;
		}
		else if (AAF3_TargetPosition == 0x7Fu)
		{
			AAF3_TargetPosition_select = UNKOWN_POSITION;
		}
		else 
		{
			//invalid
		}
	}
	else if (ReqAAF3DiagMode == 0x01u)
	{
		AAF3_TargetPosition_select = DIAG_MODE_AUTO;
	}
	else if (ReqAAF3DiagMode == 0x02u)
	{
		AAF3_TargetPosition_select = DIAG_MODE_OPEN;
	}
	else
	{
		AAF3_TargetPosition_select = DIAG_MODE_CLOSE;
	}

	if (aaf_action_complete_chk == FLAP_STOP)
	{
		if ((AAF3_TargetPosition_select != AAF_Tx_Position) && (AAF_Tx_Position != UNKOWN_POSITION) && (AAF3_TargetPosition_select != UNKOWN_POSITION))
		{
			step_start_flag = ON;
		}
	}
	else if (aaf_action == DIAG_MODE_AUTO)
	{
		if (AAF3_TargetPosition_select != aaf_action)
		{
			step_start_flag = ON;
		}
	}
	else
	{
		//invalid
	}

	Lin_UpdateCommand(AAF3_TargetPosition_select);
}	

/***********************************************************************************************************************
 * Function Name: Protection_OffMode
 * Description  : 보호 기능이 꺼져 있을 때의 일반적인 데이터 파싱 및 AAF별 로직 분기를 수행함
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
static void Protection_OffMode(void){
	
	Lin_TranslateRxData();

	if (lin_rx_pass_flag == PASS)
	{
		if (AAFx_InitStatus != DURING_INITIALIZATION)
		{
			ReqAAF3DiagMode = (unsigned int)((ID_chk_rxdata[0U] & 0x30U) >> 4U);
			ReqAAF2DiagMode = (unsigned int)((ID_chk_rxdata[0U] & 0x0CU) >> 2U);
			ReqAAF1DiagMode = (unsigned int)(ID_chk_rxdata[0U] & 0x03U);
			AAF1_TargetPosition = (unsigned int)(ID_chk_rxdata[1U] & 0x7FU);
			AAF2_TargetPosition = (unsigned int)(ID_chk_rxdata[2U] & 0x7FU);
			AAF3_TargetPosition = (unsigned int)(ID_chk_rxdata[3U] & 0x7FU);
			EngRunSta = (unsigned int)((ID_chk_rxdata[4U] & 0x30U) >> 4U);
			HevRdy = (unsigned int)((ID_chk_rxdata[4U] & 0x0CU) >> 2U);
			AAF_LINOut = (unsigned int)(ID_chk_rxdata[4U] & 0x03U);

			#ifdef ENABLE_TORQUE_TEST
            Lin_ParseTorqueTestMode(); 
			#endif

			if (AAFx_Index == AAF_1)
			{
				Lin_CheckAAF1RxData();
			}
			else if (AAFx_Index == AAF_2)
			{
				Lin_CheckAAF2RxData();
			}
			else if (AAFx_Index == AAF_3)
			{
				Lin_CheckAAF3RxData();
			}
			else
			{
				//invalid
			}
			
			#ifdef ENABLE_TORQUE_TEST
            Lin_ExecuteTorqueTestMode(); 
			#endif
		}
		else 
		{
			ReqRespAAFID = (unsigned int)((ID_chk_rxdata[0U] & 0xC0U) >> 6U);
			EngRunSta = (unsigned int)((ID_chk_rxdata[4U] & 0x30U) >> 4U);
			HevRdy = (unsigned int)((ID_chk_rxdata[4U] & 0x0CU) >> 2U);
			AAF_LINOut = (unsigned int)(ID_chk_rxdata[4U] & 0x03U);
		}
	}
}

/***********************************************************************************************************************
 * Function Name: Protection_OnMode
 * Description  : 보호 기능이 켜져 있을 때 보호 모드 해제 요청 비트만 모니터링함
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
static void Protection_OnMode(void){
	Lin_TranslateRxData();

	if (lin_rx_pass_flag == PASS)
	{
		AAF_ProtectionMode_Rx = (unsigned int)((ID_chk_rxdata[7U] & 0x40U) >> 6U);
	}
}

/***********************************************************************************************************************
 * Function Name: Lin_RxCheck
 * Description  : LIN 수신 데이터를 검증하고 보호 기능 상태(ON/OFF)에 따라 처리 루틴을 호출하는 메인 함수
 * Arguments    : void
 * Return Value : void
 ***********************************************************************************************************************/
void Lin_RxCheck(void)
{
	Lin_DiagRx();

	ReqRespAAFID = (unsigned int)((Slave_RxData1[0U] & 0xC0U) >> 6U);
	if (AAF_LIN_ChkSum_CHK == PASS)
	{
		// ReqRespAAFID = (unsigned int)((Slave_RxData1[0] & 0xC0U) >> 6U);

		if (protection_function == OFF) //
		{
			Protection_OffMode();
		}
		else if (protection_function == ON)
		{
			Protection_OnMode();
		}
		else
		{
			//invalid
		}
	}
}

void Lin_TxCheck(void)
{
	switch (AAF_Tx_Position)
	{
	case CLOSE:
		AAF_Tx_Position_LIN = 0x64u;
		Diag_Mode_chk = 0U;
		break;
	case OPEN:
		AAF_Tx_Position_LIN = 0x00u;
		Diag_Mode_chk = 0U;
		break;
	case DIAG_MODE_OPEN:
		AAF_Tx_Position_LIN = 0x7Fu;
		Diag_Mode_chk = 1U;
		break;
	case DIAG_MODE_CLOSE:
		AAF_Tx_Position_LIN = 0x7Fu;
		Diag_Mode_chk = 1U;
		break;
	case DIAG_MODE_AUTO:
		AAF_Tx_Position_LIN = 0x7Fu;
		Diag_Mode_chk = 1U;
		break;
	case UNKOWN_POSITION:
		AAF_Tx_Position_LIN = 0x7Fu;
		break;
	default:
		break;
	}

	Slave_TxData[0U] = (uint8_t)((AAFx_Type << 7U) | AAF_Tx_Position_LIN);
	Slave_TxData[1U] = (uint8_t)((TotalNumOfAAF << 6U) | (AAFx_Index << 4U) | (AAFx_Mode << 2U) | AAFx_InitStatus);
	Slave_TxData[2U] = (uint8_t)((1U << 7U) | (AAFx_Over_Volt << 6U) | (AAFx_Low_Volt << 5U) | (AAFx_Motor_Fault << 4U) | (1U << 3U) | (AAFx_Circuit_Short << 2U) | (AAFx_Circuit_Open << 1U) | 1U);
	Slave_TxData[3U] = (uint8_t)((AAFx_SNSR_SCG << 7U) | (AAFx_SNSR_SCB << 6U) | (AAFx_SNSR_OC << 5U) | (AAFx_Position_Status << 2U) | AAFx_ErrorStatus);
	Slave_TxData[4U] = (uint8_t)((0x1Fu << 3U) | (TotalNumOfAAFSensor));
	Slave_TxData[5U] = (uint8_t)((AAFx_SNSR4_Position << 6U) | (AAFx_SNSR3_Position << 4U) | (AAFx_SNSR2_Position << 2U) | AAFx_SNSR1_Position);

	Req_ChkSum_Tx = (unsigned int)((16U - ((((Slave_TxData[0U] / 16U) + (Slave_TxData[1U] / 16U) + (Slave_TxData[2U] / 16U) + (Slave_TxData[3U] / 16U) + (Slave_TxData[4U] / 16U) + (Slave_TxData[5U] / 16U) + Req_Alive_Tx) + ((Slave_TxData[0U] % 16U) + (Slave_TxData[1U] % 16U) + (Slave_TxData[2U] % 16U) + (Slave_TxData[3U] % 16U) + (Slave_TxData[4U] % 16U) + (Slave_TxData[5U] % 16U))) & 0x0Fu) & 0x0Fu));

	Slave_TxData[6U] = (uint8_t)((Req_ChkSum_Tx << 4U) | Req_Alive_Tx);
	Lin_DiagAction();

	lin_rx_pass_flag = WAITING;
}



void Lin_BusCheck(void)
{
	if ((G_Timer1ms.LinBusInactive >= LIN_BUS_CHK_TIME_4_SEC) && (lin_bus_inactive_flag == OFF))
	{
		lin_bus_inactive_flag = ON;

		Drv8889_Off2();							  // drv of
		motor_start = OFF;					  // step stop
		G_Timer1msFlag.External10sCheckFlag = OFF; // 10s chk timer off
		G_Timer1ms.External10sCheck = 0U;
		aaf_action = FLAP_STOP;
		aaf_action_complete_chk = FLAP_STOP;
		softstart_complete = OFF;
		motor_step_value = STEP_TIME_1000RPM;

		G_Timer1ms.StallCheck = 0U;		 // test
		G_Timer1msFlag.StallCheckFlag = 0U; // test

		lin_sleep_step = 0U;

		wake_up_motor_range_init_chk = 0U;

		aaf_step = AAF_WAITING;
	}
}


