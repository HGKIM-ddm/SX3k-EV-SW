#ifndef CONFIG_H
#define CONFIG_H

#include "r_cg_macrodriver.h"
#include "Define.h"
#include "r_smc_entry.h"

/*******************************************************************************
 * EV Only
 ******************************************************************************/
extern unsigned int LDCRdy;
extern unsigned int CR_Mcu_VehSpdInt_Kph;
extern unsigned int AAF_DriveMode;
extern unsigned int lin_aaf_request_command;
extern uint8_t  highspeed_command_hold_flag;
extern unsigned int cumulative_stall_count;
/*******************************************************************************
 * Drv8889 Register
 ******************************************************************************/
extern unsigned int TRQ_COUNT;
extern uint16_t TRQ_COUNT_Buffer[4000U];
extern unsigned int TRQ_COUNT_Index;
extern uint8_t TRQ_COUNT_LogEnable;
extern uint8_t TRQ_COUNT_TxReady;

/*******************************************************************************
 * Global Variable Extern Declarations
 ******************************************************************************/
/* 2.1 Communication Buffers (LIN / SPI) */
extern uint8_t GetIDbuffer;
extern uint8_t Slave_RxData1[8];
extern uint8_t Slave_TxData[7];
extern uint8_t ID_chk_rxdata[11];
extern uint8_t w_buff[30]; //Only SX3k [30]
extern uint32_t r_buff[8]; //Only SX3k [8]
extern uint8_t Slave_SwData[8];
extern uint8_t Slave_RxSwData1[8];

extern uint16_t tx_16bit_spi[11];
extern uint16_t rx_16bit_spi_id[11];
extern uint16_t rx_16bit_spi[11];
extern uint16_t fault_clear[1];

/* 2.2 Motor Control Variables */
extern unsigned int motor_start;
extern unsigned int motor_wait_chk;
extern unsigned long long step_position;
extern unsigned int dir_state;
extern unsigned int init_move_step;
extern unsigned int AAF_OpenLoad;
extern unsigned int motor_step_value;
extern volatile unsigned int softstart_complete;
extern unsigned int motor_stall_flag;
extern unsigned int step_start_flag;

/* 2.3 AAF Application Variables */
extern unsigned int aaf_step;
extern unsigned int aaf_action;
extern unsigned int aaf_init_step;
extern unsigned int aaf_action_complete_chk;
extern unsigned int flap_move;
extern unsigned int step_position_open;
extern unsigned int step_position_close;
extern unsigned int limit_step_position;
extern unsigned int open_1st_step_position;
extern unsigned int open_2nd_step_position;
extern unsigned int protection_function;
extern unsigned int protection_Mode_step;
extern unsigned int AAF_location_type;
extern unsigned int AAF_LINOut;
extern unsigned int AAFx_Type;
extern unsigned int AAFx_InitStatus;
extern unsigned int AAFx_Index;
extern unsigned int TotalNumOfAAF;
extern unsigned int AAFx_Circuit_Open;
extern unsigned int AAFx_Circuit_Short;
extern unsigned int AAFx_Motor_Fault;
extern unsigned int AAFx_Low_Volt;
extern unsigned int AAFx_Over_Volt;

extern unsigned int AAF1_TargetPosition;
extern unsigned int AAF2_TargetPosition;
extern unsigned int AAF3_TargetPosition;
extern unsigned int AAF1_TargetPosition_select;
extern unsigned int AAF2_TargetPosition_select;
extern unsigned int AAF3_TargetPosition_select;

extern unsigned int AAF_ProtectionMode_Rx;
extern volatile unsigned int AAF_ProtectionMode_Tx;
extern uint8_t AAF_Tx_Position;
extern unsigned int AAF_Tx_Position_LIN;
extern volatile unsigned int AAF_Maximum_Torque_Test_Mode;
extern unsigned int torque_test_position;

extern unsigned int ReqRespAAFID;
extern unsigned int ReqAAF1DiagMode;
extern unsigned int ReqAAF2DiagMode;
extern unsigned int ReqAAF3DiagMode;
extern unsigned int EngRunSta;
extern unsigned int HevRdy;
extern unsigned int Req_ChkSum_Rx;
extern unsigned int Req_Alive_Rx;
extern unsigned int AAFx_Mode;

extern unsigned int AAFx_Position_Status;
extern unsigned int AAFx_ErrorStatus;
extern unsigned int TotalNumOfAAFSensor;
extern unsigned int AAFx_SNSR1_Position;
extern unsigned int AAFx_SNSR2_Position;
extern unsigned int AAFx_SNSR3_Position;
extern unsigned int AAFx_SNSR4_Position;
extern unsigned int Req_ChkSum_Tx;
extern unsigned int Req_Alive_Tx;

/* 2.4 Communication Flags & Status */
extern volatile uint8_t error_status;
extern unsigned int lin_aaf_command;
extern unsigned int lin_rx_pass_flag;
extern unsigned int lin_rx_chk_flag;
extern volatile uint8_t lin_tx_resp_flag;
extern volatile uint8_t g_lin_comm_ok_flag;
extern volatile uint8_t g_lin_error_flag;
extern unsigned int AAF_LIN_ChkSum_CHK_value;
extern unsigned char spi_send_flag;
extern unsigned char spi_receive_flag;
extern unsigned char spi_error_flag;
extern unsigned int spi_action_step;
extern char ret;
extern unsigned int lin_bus_inactive_flag;
extern unsigned int lin_sleep_step;


/* 2.5 ADC & Power Variables */
extern uint16_t bat_adc;
extern unsigned int adc_chk[10];
extern unsigned int adc_sum;
extern unsigned int adc_avr;
extern unsigned int adc_chk_ok_flag;
extern unsigned int adc_chk_ready;
extern uint16_t scan_results[6]; //Only SX3k [6]

extern unsigned int voltage_status_spi;
extern unsigned int voltage_status_change;
extern unsigned int voltage_status_change_complete;
extern unsigned int voltage_chk_delay_complete;
extern unsigned int Under_Voltage_Deceted;
extern unsigned int Over_Voltage_Deceted;
extern unsigned int First_Powerchk;

/* 2.6 Fault & Diagnosis */
extern unsigned int fail_safety_flag;
extern unsigned int fail_safety_1_cycle_flag;
extern unsigned int fail_safety_step;
extern unsigned int stall_count;
extern unsigned int stall_test_mode;
extern unsigned int evrdy_on_flag;
extern unsigned int diag_mode_auto_dir;
extern unsigned int diag_mode_auto_action;
extern unsigned int fdl_fail;
extern volatile unsigned int wake_up_motor_range_init_chk;
extern unsigned int LIMP_HOME_Count;
extern unsigned int LIMP_HOME_step;
extern uint8_t DTC_Status;
extern unsigned int motor_fault_chk;
extern unsigned int power_chk;
extern unsigned int Diag_Mode;
extern unsigned int Diag_Mode_chk;
extern unsigned int Short_Detected;
extern unsigned int Open_Detected;
extern unsigned int Short_fault_check;
extern unsigned int Open_fault_check;
extern unsigned int motor_Short_chk_count;
extern unsigned int motor_Open_chk_count;

/* 2.7 Antipinch */
extern unsigned int antipinch_step;
extern unsigned int antipinch_previous_action;
extern unsigned int antipinch_action_on;

/* 2.8 Flash Memory Variables (Shadow RAM) */
extern unsigned int close_memory_write;
extern unsigned int close_memory_read;
extern unsigned int open_memory_write;
extern unsigned int open_memory_read;
extern unsigned int now_step_memory_write;
extern unsigned int now_step_memory_read;
extern unsigned int position_memory_write;
extern unsigned int position_memory_read;
extern unsigned int Initial_memory_write;
extern unsigned int Initial_memory_read;
extern unsigned int position_Initial_combined_read;
extern unsigned int limit_memory_write;
extern unsigned int limit_memory_read;
extern unsigned int position_status_memory_write;
extern unsigned int position_status_memory_read;
extern unsigned int AAFx_InitStatus_memory_write;
extern unsigned int AAFx_InitStatus_memory_read;
extern unsigned int position_Initstatus_combined_read;
extern unsigned int DTC_memory_write;
extern unsigned int DTC_memory_read;
extern unsigned int power_chk_memory_write;
extern unsigned int power_chk_memory_read;
extern unsigned int First_Powerchk_memory_write;
extern unsigned int First_Powerchk_memory_read;
extern unsigned int fw_version_memory_read;
extern unsigned int AAF_Tx_Position_Temporary;
extern unsigned int AAFx_Position_Status_Temporary;
extern unsigned int AAFx_InitStatus_Temporary;

/* 2.9 Timers (1us / 1ms Counters) */

/* Global 1ms Timer Group */
typedef struct {
    unsigned int InitMove;
    unsigned int AdcCheck;
    unsigned int Spi;
    unsigned int InitCheck;
    unsigned int StallCheck;
    unsigned int ProtectionMode;
    unsigned int StallTime;
    unsigned int MotorDelay;
    unsigned int VoltCheckDelay;
    unsigned int DiagAutoMode;
    unsigned int VoltStatChangeDelay;
    unsigned int MotorAcceleration;
    unsigned int InitFailCheck;
    unsigned int LinSleepMode;
    unsigned int AntipinchCheck;
    unsigned int SpiErrorCheck;
    unsigned int AdcErrorCheck;
    unsigned int FdlErrorCheck;
    unsigned int ProtectionCheck;
    unsigned int MotorMovingCheck;
    unsigned int MotorStepCheck;
    unsigned int WatchdogCheck;
    unsigned int ErrorCheck;
    unsigned int MotorShortCheck;
    unsigned int MotorOpenCheck;
    unsigned int IgnCheck;
    unsigned int AdcRecoveryCheck;
    unsigned int LinBusInactive;
    unsigned int External10sCheck;
    unsigned int Adc1sCheck;
    unsigned int Timer3minute;
    unsigned int Timer3minuteSec;
    unsigned int IgnErrorCheck;
    unsigned int HighSpeedExitCheck;
} Global_Timer1msType;

typedef struct {
    unsigned int InitMoveFlag;
    unsigned int AdcCheckFlag;
    unsigned int FdlFlag;
    unsigned int SpiFlag;
    unsigned int InitCheckFlag;
    unsigned int StallCheckFlag;
    unsigned int ProtectionModeFlag;
    unsigned int StallTimeFlag;
    unsigned int MotorDelayFlag;
    unsigned int VoltCheckDelayFlag;
    unsigned int DiagAutoModeFlag;
    unsigned int VoltStatChangeDelayFlag;
    unsigned int MotorAccelerationFlag;
    unsigned int InitFailCheckFlag;
    unsigned int LinSleepModeFlag;
    unsigned int AntipinchCheckFlag;
    unsigned int SpiErrorCheckFlag;
    unsigned int AdcErrorCheckFlag;
    unsigned int FdlErrorCheckFlag;
    unsigned int ProtectionCheckFlag;
    unsigned int MotorMovingCheckFlag;
    unsigned int MotorStepCheckFlag;
    unsigned int WatchdogCheckFlag;
    unsigned int ErrorCheckFlag;
    unsigned int MotorShortCheckFlag;
    unsigned int MotorOpenCheckFlag;
    unsigned int IgnCheckFlag;
    unsigned int AdcRecoveryCheckFlag;
    unsigned int External10sCheckFlag;
    unsigned int Adc1sCheckFlag;
    unsigned int Timer3minuteFlag;
    unsigned int IgnErrorCheckFlag;
    unsigned int HighSpeedExitCheckFlag;
} Global_Timer1msFlagType;

extern Global_Timer1msType G_Timer1ms;
extern Global_Timer1msFlagType G_Timer1msFlag;

/* Global 1us Timer Group */
typedef struct {
    unsigned int Motor;
    unsigned int Spi;
} Global_Timer1usType;

typedef struct {
    unsigned int MotorFlag;
    unsigned int SpiFlag;
} Global_Timer1usFlagType;

extern Global_Timer1usType G_Timer1us;
extern Global_Timer1usFlagType G_Timer1usFlag;

extern unsigned int step_check_flag;
extern unsigned int IGN_Chk;
extern unsigned int IGN_Chk_On;
extern unsigned int SW_Chk;
extern unsigned int Operating_flag;
extern unsigned int LIN_Short_Ok;

extern unsigned int AAF_Init_Flag;
extern unsigned int AAF_Init_Flag_tog;
extern unsigned int Re_Init_check;
extern unsigned int Re_Init_check_flag;
extern unsigned int Re_Init_check_prev;
extern volatile unsigned int AAF_Flap_Fixation_Test_Mode;
extern volatile unsigned int AAF_Flap_Fixation_Test_Mode_tog;
extern volatile unsigned int AAF_Maximum_Torque_Test_Mode_tog;


/*******************************************************************************
 * MOTOR FAULT DATA
 ******************************************************************************/
extern unsigned int AAF_OverTemp;              /* Bit 10: OTSD (과열 셧다운) */
extern unsigned int AAF_GlobalFault;           /* Bit 15: FAULT (글로벌 에러) */
extern unsigned int AAF_UVLO;  /* B13 저전압 */  
extern unsigned int AAF_CPUV;  /* B12 차지펌프 저전압 */
extern unsigned int AAF_OverCurrent;  /* B11 OCP */
extern unsigned int AAF_HW_Stall;  /* B10 STL (HW스톨) */

#endif 
