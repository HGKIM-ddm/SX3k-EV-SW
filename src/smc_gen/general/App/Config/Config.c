#include "Config.h"

/* 2.1 Communication Buffers (LIN / SPI) */
uint8_t GetIDbuffer;
uint8_t Slave_RxData1[8]; /*reception data store array*/
uint8_t Slave_TxData[8] = {
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

uint16_t tx_16bit_spi[11] = {
	0x4000, // [0] (R) FAULT Status
	0x4200, // [1] (R) DIAG Status 1
	0x4400, // [2] (R) DIAG Status 2
	0x0690, // [3] ?  瑜섏젣?
	0x080F, // [4] (RW)CTRL 2
	0x0A05, // [5] (RW)CTRL 3
	0x0C3E, // [6] (RW)CTRL 4	3E (open load on) 0C36 0C3A
	0x0E10, // [7] (RW)CTRL 5
	0x1000, // [8] (RW)CTRL 6	stall threshold
	0x5200, // [9] (R) CTRL 7	stall count
	0x5400	// [10](R) CTRL 8
};

uint16_t tx_16bit_spi_current_limit[16] = {
	0x0601,
	0x0611,
	0x0621,
	0x0631,
	0x0641,
	0x0651,
	0x0661,
	0x0671,
	0x0681,
	0x0690,
	0x06A1,
	0x06B1,
	0x06C1,
	0x06D1,
	0x06E1,
	0x06F1
};

uint16_t tx_16bit_spi_slew_change[2] = {
    0x0690,
    0x0691
};

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
    0x0CBA};

/* 2.2 Motor Control Variables */
unsigned int motor_start = OFF;
unsigned int motor_wait_chk = 0;
unsigned long long step_position = 0;
unsigned int dir_state = 0;
unsigned int step_toggle_flag = 0;
unsigned int init_move_step = 0;
unsigned int motor_open_load = 0;
unsigned int motor_step_value = 0;
volatile unsigned int softstart_complete = 0;
unsigned int motor_stall_value = 255;
unsigned int motor_stall_flag = 0;
unsigned int motor_cw_stall_value = 0;
unsigned int motor_ccw_stall_value = 0;
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
unsigned int protection_Mode_step = 0;
unsigned int AAF_location_type = 0;
unsigned int AAF_OverCurrent = 0;
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
unsigned int AAF_Tx_Position = 0;
unsigned int AAF_Tx_Position_LIN = 0;
volatile unsigned int AAF_Maximum_Torque_Test_Mode = 0;
unsigned int torque_test_position = 0;

unsigned int ReqRespAAFID = 0;
unsigned int ReqAAF1DiagMode = 0;
unsigned int ReqAAF2DiagMode = 0;
unsigned int ReqAAF3DiagMode = 0;
unsigned int EngRunSta = 0;
unsigned int HevRdy = 0;
unsigned int Req_ChkSum_Rx = 0;
unsigned int Req_Alive_Rx = 0;
unsigned int AAFx_Mode = 0;

unsigned int AAFx_SNSR_SCG = 0;
unsigned int AAFx_SNSR_SCB = 0;
unsigned int AAFx_SNSR_OC = 0;
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
unsigned int AAF_LIN_ChkSum_CHK = 0;
unsigned int AAF_LIN_ChkSum_CHK_value = 0;
unsigned char spi_send_flag = 0;
unsigned char spi_receive_flag = 0;
unsigned char spi_error_flag = 0;
unsigned int spi_action_step = 0;
char ret = 0;
unsigned int lin_bus_inactive_flag = 0;
unsigned int lin_sleep_step = 0;

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
unsigned int stall_cnt = STALL_CNT_DEFAULT;
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

/* 3   Only SX3k*/
// unsigned int OBD1_Close_Check_memory_write = 0;
// unsigned int OBD1_Close_Check_memory_read = 0;
// unsigned int OBD1_Open_Check_memory_write = 0;
// unsigned int OBD1_Open_Check_memory_read = 0;
// unsigned int OBD2_Close_Check_memory_write = 0;
// unsigned int OBD2_Close_Check_memory_read = 0;
// unsigned int OBD2_Open_Check_memory_write = 0;
// unsigned int OBD2_Open_Check_memory_read = 0;
// unsigned int OBD3_Close_Check_memory_write = 0;
// unsigned int OBD3_Close_Check_memory_read = 0;
// unsigned int OBD3_Open_Check_memory_write = 0;
// unsigned int OBD3_Open_Check_memory_read = 0;
// uint16_t OBD1_adc = 0;
// uint16_t OBD2_adc = 0;
// uint16_t OBD3_adc = 0;
// uint16_t OBD4_adc = 0;
// uint16_t ADC_Stability = 0;
// unsigned int middle_step_position = 0U;
// unsigned int SNSR_Position_Ok = 0U;
// unsigned int SNSR2_Position_Ok = 0U;
// unsigned int SNSR3_Position_Ok = 0U;
// unsigned int step_check_ok = 0U;
// unsigned int step2_check_ok = 0U;
// unsigned int step3_check_ok = 0U;
// unsigned int OBD1_Open_Check = 0U;
// unsigned int OBD1_Close_Check = 0U;
// unsigned int OBD2_Open_Check = 0U;
// unsigned int OBD2_Close_Check = 0U;
// unsigned int SNSR1_Check = 0U;
// unsigned int SNSR2_Check = 0U;
// unsigned int OBD1_Open_tolerance = 0U;
// unsigned int OBD2_Open_tolerance = 0U;
// unsigned int OBD1_Close_tolerance = 0U;
// unsigned int OBD2_Close_tolerance = 0U;
// unsigned int OBD3_Open_Check = 0U;
// unsigned int OBD3_Close_Check = 0U;
// unsigned int SNSR3_Check = 0U;
// unsigned int OBD3_Open_tolerance = 0U;
// unsigned int OBD3_Close_tolerance = 0U;

// unsigned int OBD_Error_check_flag = 0U;
// unsigned int OBD_Error_flag = 0U;
// unsigned int OBD_Return_flag = 0U;
// unsigned int OBD_Short_Bat = 0U;
// unsigned int OBD_Short_Gnd = 0U;
// unsigned int OBD_Open_Circuit = 0U;
// unsigned int Recovery_Detected = 0U;
// unsigned char OBD_Error_move = 0U;
// unsigned int OBD1_adc_threshold_close = 0u;
// unsigned int OBD1_adc_threshold_open = 0u;
// unsigned int OBD2_adc_threshold_close = 0u;
// unsigned int OBD2_adc_threshold_open = 0u;
// unsigned int OBD3_adc_threshold_close = 0u;
// unsigned int OBD3_adc_threshold_open = 0u;
// unsigned char Obd_Position_Turn = 0U;




