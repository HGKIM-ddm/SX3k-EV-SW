#include "Config.h"

/*******************************************************************************
 * EV Only
 ******************************************************************************/
unsigned int LDCRdy = 0U;
unsigned int CR_Mcu_VehSpdInt_Kph = 0U;

unsigned int AAF_DriveMode = NORMAL_DRIVE_MODE; //현재 주행 모드 저장, 1이면 고속 주행 0이면 정상 주행
unsigned int lin_aaf_request_command = CLOSE; // MCU가 LIN으로 보낸 원본 위치 명령 저장
uint8_t  highspeed_command_hold_flag = 0U; // 고속 주행모드에서 명령 홀드 여부 저장 (0: 홀드 안함, 1: 홀드)

unsigned int cumulative_stall_count = 7; // 누적 스톨 카운트, 7 이상이면 스톨로 판단


 /*******************************************************************************
  * Drv8889 Register
  ******************************************************************************/

/* 2.1 Communication Buffers (LIN / SPI) */
uint8_t GetIDbuffer;
uint8_t Slave_RxData1[8]; /*reception data store array*/
uint8_t Slave_TxData[7] = {
    0,
}; /*Transmission data store array*/
uint8_t ID_chk_rxdata[11] = {
    0,
};
uint8_t w_buff[30] = {
	0,
};
uint32_t r_buff[8] = {
    0,
};

uint8_t Slave_SwData[8] = {
    0,
}; /* Transmission data store array  */

uint8_t Slave_RxSwData1[8] = {0,};

uint16_t tx_16bit_spi[11] = {0};

uint16_t rx_16bit_spi_id[11] = {
    0x4000,
    0x4200,
    0x4400,
    0x4600,
    0x4800,
    0x4A00,
    0x4C00,
    0x4E00,
    0x5000,
    0x5200,
    0x5400};

uint16_t rx_16bit_spi[11] = {
    0,
};

uint16_t fault_clear[1] = { 
    0x0CBC 
};

/*******************************************************************************
 * Drv8889 Register
 ******************************************************************************/
unsigned int TRQ_COUNT = 0U;

//for UI test
uint16_t TRQ_COUNT_Buffer[4000U] = {0U,};
unsigned int TRQ_COUNT_Index = 0U;
uint8_t TRQ_COUNT_LogEnable = 0U;
uint8_t TRQ_COUNT_TxReady = 0U;



/* 2.2 Motor Control Variables */
unsigned int motor_start = OFF;
unsigned int motor_wait_chk = 0;
unsigned long long step_position = 0;
unsigned int dir_state = 0;
unsigned int init_move_step = 0;
unsigned int AAF_OpenLoad = 0;
volatile unsigned int softstart_complete = 0;

unsigned int motor_stall_flag = 0;
unsigned int step_start_flag = 0;

/* 2.3 AAF Application Variables */
unsigned int aaf_step = 0;
unsigned int aaf_action = 0;
unsigned int aaf_init_step = 0;
unsigned int aaf_action_complete_chk = 0;
unsigned int flap_move = FLAP_STOP;
unsigned int step_position_open = 0;
unsigned int step_position_close = 0;
unsigned int limit_step_position = 0;
unsigned int open_1st_step_position = 0;
unsigned int open_2nd_step_position = 0;
unsigned int protection_function = 0;
unsigned int voltage_protection_function = 0;  //8.5, 16.5v 구간 open 시도
unsigned int protection_Mode_step = 0;
unsigned int AAF_location_type = 0;
unsigned int AAF_LINOut = 0;
unsigned int AAFx_Type = 0;
unsigned int AAFx_InitStatus = 0;
unsigned int AAFx_Index = 0;
unsigned int TotalNumOfAAF = 0;
unsigned int AAFx_Circuit_Open = 0;
unsigned int AAFx_Circuit_Short = 0;
unsigned int AAFx_Motor_Fault = 0;
unsigned int AAFx_Low_Volt = 0;
unsigned int AAFx_Over_Volt = 0;

unsigned int AAF1_TargetPosition = 0;
unsigned int AAF2_TargetPosition = 0;
unsigned int AAF3_TargetPosition = 0;
unsigned int AAF1_TargetPosition_select = 0;
unsigned int AAF2_TargetPosition_select = 0;
unsigned int AAF3_TargetPosition_select = 0;

unsigned int AAF_ProtectionMode_Rx = 0;
volatile unsigned int AAF_ProtectionMode_Tx = 0;
uint8_t AAF_Tx_Position = 0;
unsigned int AAF_Tx_Position_LIN = 0;
volatile unsigned int AAF_Maximum_Torque_Test_Mode = 0;
unsigned int torque_test_position = 0;

unsigned int ReqRespAAFID = 0;
unsigned int ReqAAF1DiagMode = 0;
unsigned int ReqAAF2DiagMode = 0;
unsigned int ReqAAF3DiagMode = 0;
unsigned int Req_ChkSum_Rx = 0;
unsigned int Req_Alive_Rx = 0;
unsigned int AAFx_Mode = 0;

unsigned int AAFx_Position_Status = 0;
unsigned int AAFx_ErrorStatus = 0;
unsigned int TotalNumOfAAFSensor = 0;
unsigned int AAFx_SNSR1_Position = 0;
unsigned int AAFx_SNSR2_Position = 0;
unsigned int AAFx_SNSR3_Position = 0;
unsigned int AAFx_SNSR4_Position = 0;
unsigned int Req_ChkSum_Tx = 0;
unsigned int Req_Alive_Tx = 0;

/* 2.4 Communication Flags & Status */
volatile uint8_t error_status = 0;
unsigned int lin_aaf_command = 0;
unsigned int lin_rx_pass_flag = 0;
unsigned int lin_rx_chk_flag = 0;
volatile uint8_t lin_tx_resp_flag = 0;
volatile uint8_t g_lin_comm_ok_flag = 0U;
volatile uint8_t g_lin_error_flag = 0U;
unsigned int AAF_LIN_ChkSum_CHK_value = 0;
unsigned char spi_send_flag = 0;
unsigned char spi_receive_flag = 0;
unsigned char spi_error_flag = 0;
unsigned int spi_action_step = 0;
char ret = 0;
unsigned int lin_bus_inactive_flag = 0;
unsigned int lin_sleep_step = 0;
unsigned int lin_nrst_low_flag = 0;
unsigned int lin_nrst_debounce_count = 0;

/* 2.5 ADC & Power Variables */
uint16_t bat_adc = 0;
unsigned int adc_chk[10] = {0,};
unsigned int adc_sum = 0;
unsigned int adc_avr = 0;
unsigned int adc_chk_ok_flag = 0;
unsigned int adc_chk_ready = 0;
uint16_t scan_results[6] = {0,};

unsigned int voltage_status_spi = 0;
unsigned int voltage_status_change = 0;
unsigned int voltage_status_change_complete = 0;
unsigned int voltage_chk_delay_complete = 0;
unsigned int Under_Voltage_Deceted = 0U;
unsigned int Over_Voltage_Deceted = 0U;
unsigned int First_Powerchk = 0U;

/* 2.6 Fault & Diagnosis */
unsigned int fail_safety_flag = 0;
unsigned int fail_safety_1_cycle_flag = 0;
unsigned int fail_safety_step = 0;
unsigned int stall_count = STALL_CNT_DEFAULT;
unsigned int stall_test_mode = 0;
unsigned int evrdy_on_flag = 0;
unsigned int diag_mode_auto_dir = 0;
unsigned int diag_mode_auto_action = 0;
unsigned int fdl_fail = 0;
volatile unsigned int wake_up_motor_range_init_chk = 0;
unsigned int LIMP_HOME_Count = 0;
unsigned int LIMP_HOME_step = 0;
uint8_t DTC_Status = 0;
unsigned int motor_fault_chk = 0U;
unsigned int power_chk = 0U;
unsigned int Diag_Mode = 0U;
unsigned int Diag_Mode_chk = 0U;
unsigned int Short_Detected = 0U;
unsigned int Open_Detected = 0U;
unsigned int Short_fault_check = 0U;
unsigned int Open_fault_check = 0U;
unsigned int motor_Short_chk_count = 0U;
unsigned int motor_Open_chk_count = 0U;

/* 2.7 Antipinch */
unsigned int antipinch_step = 0;
unsigned int antipinch_previous_action = INITIALIZATION;
unsigned int antipinch_action_on = 0;
unsigned int antipinch_original_action = INITIALIZATION;

/* 2.8 Flash Memory Variables (Shadow RAM) */
unsigned int close_memory_write = 0; // close step
unsigned int close_memory_read = 0;
unsigned int open_memory_write = 0; // open step
unsigned int open_memory_read = 0;
unsigned int now_step_memory_write = 0; // now step
unsigned int now_step_memory_read = 0;
unsigned int position_memory_write = 0; // AAFx_Position
unsigned int position_memory_read = 0;
unsigned int Initial_memory_write = 0; // evrdy flag
unsigned int Initial_memory_read = 0;
unsigned int position_Initial_combined_read = 0; // AAFx_Position+evrdy flag
unsigned int limit_memory_write = 0; // limit step(5%)
unsigned int limit_memory_read = 0;
unsigned int position_status_memory_write = 0; // AAFx_Position_Status
unsigned int position_status_memory_read = 0;
unsigned int AAFx_InitStatus_memory_write = 0; // AAFx_InitStatus
unsigned int AAFx_InitStatus_memory_read = 0;
unsigned int position_Initstatus_combined_read = 0; // AAFx_Position_Status+AAFx_InitStatus
unsigned int DTC_memory_write = 0; // DTC
unsigned int DTC_memory_read = 0;
unsigned int power_chk_memory_write = 0; // power chk
unsigned int power_chk_memory_read = 0;
unsigned int First_Powerchk_memory_write = 0U;
unsigned int First_Powerchk_memory_read = 0U;
unsigned int fw_version_memory_read = 0U; // fw version
unsigned int AAF_Tx_Position_Temporary = UNKOWN_POSITION;
unsigned int AAFx_Position_Status_Temporary = Unknown_Status;
unsigned int AAFx_InitStatus_Temporary = DURING_INITIALIZATION;

/* 2.9 Timers (1us / 1ms Counters) */

/* 1us Timer Group */
Global_Timer1usType G_Timer1us = {0};
Global_Timer1usFlagType G_Timer1usFlag = {0};

/* 1ms Timer Group */
Global_Timer1msType G_Timer1ms = {0};
Global_Timer1msFlagType G_Timer1msFlag = {0};

unsigned int step_check_flag = 0;
unsigned int IGN_Chk = 0U;
unsigned int IGN_Chk_On = 0U;
unsigned int SW_Chk = 0U;
unsigned int Operating_flag = 0U;
unsigned int LIN_Short_Ok = 0U;

unsigned int AAF_Init_Flag = 0U;
unsigned int AAF_Init_Flag_tog = 0U;
unsigned int Re_Init_check = 0U;
unsigned int Re_Init_check_flag = 0U;
unsigned int Re_Init_check_prev = 0U;
volatile unsigned int AAF_Flap_Fixation_Test_Mode = 0U;
volatile unsigned int AAF_Flap_Fixation_Test_Mode_tog = 0U;
volatile unsigned int AAF_Maximum_Torque_Test_Mode_tog = 0U;



/*******************************************************************************
 * MOTOR FAULT DATA
 ******************************************************************************/
unsigned int AAF_OverTemp = 0;              /* Bit 10: OTSD (과열 셧다운) */
unsigned int AAF_GlobalFault = 0;           /* Bit 15: FAULT (글로벌 에러) */
unsigned int AAF_UVLO        = 0;  /* B13 저전압 */  
unsigned int AAF_CPUV        = 0;  /* B12 차지펌프 저전압 */
unsigned int AAF_OverCurrent = 0;  /* B11 OCP */
unsigned int AAF_HW_Stall    = 0;  /* B10 STL (HW스톨) */