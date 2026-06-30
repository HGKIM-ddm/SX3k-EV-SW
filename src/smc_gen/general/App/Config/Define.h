#ifndef DEFINE_H
#define DEFINE_H

/***********************************************************************************************************************
 * 0. Macro
***********************************************************************************************************************/


/* ====================================================================
 * Tuning
 * ==================================================================== */
//For TC TEST DEFAULT 180 3minute
#define MINUTE_3 180U 

//For Torque Test
// #define ENABLE_TORQUE_TEST

//For Bootloader
#define UDS

//For Torque Lin Communication
//#define ENABLE_TORQUE_LIN_COMMUNICATION

//Current CodeName
#define VEHICLE_CODENAME SX3K_EV_AAF1

 /* ==================================================================== */

//1ms timer macro
#define TIMER_1MS(NAME) \
    if (G_Timer1msFlag.NAME##Flag == 1) { \
        G_Timer1ms.NAME++; \
    }

// 1us timer macro
#define TIMER_1US(NAME) \
    if (G_Timer1usFlag.NAME##Flag == 1) { \
        G_Timer1us.NAME++; \
    }

/* ====================================================================
 * Code Name (EV only)
 * ==================================================================== */
// --- SX3K EV (3ea) ---
#define SX3K_EV_AAF1 1
#define SX3K_EV_AAF2 2
#define SX3K_EV_AAF3 3

// --------------------------------------------------------------------
// SX3K EV
// --------------------------------------------------------------------
#if (VEHICLE_CODENAME == SX3K_EV_AAF1)
#define CONFIG_AAF_ANGLE 110
#define CONFIG_AAF_TYPE EXTERNAL_TYPE
#define CONFIG_AAF_LOCATION RH_TYPE
#define CONFIG_AAF_INDEX AAF_1
#define CONFIG_AAF_TOTAL AAFx1
#define CONFIG_SENSOR_TOTAL SENSOR_NO
 
#else
// error
#endif

//Range
#if (CONFIG_AAF_ANGLE == 68)
    #define AAF_FULL_ANGLE              68U
    #define STEP_POSITION_MINIMUM_RANGE 9000U
    #define STEP_POSITION_MAXIMUM_RANGE 13000U                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
#elif (CONFIG_AAF_ANGLE == 72)
    #define AAF_FULL_ANGLE              72U
    #define STEP_POSITION_MINIMUM_RANGE 9000U
    #define STEP_POSITION_MAXIMUM_RANGE 13000U
#elif (CONFIG_AAF_ANGLE == 90)
    #define AAF_FULL_ANGLE              90U
    #define STEP_POSITION_MINIMUM_RANGE 12000U
    #define STEP_POSITION_MAXIMUM_RANGE 15500U
#elif (CONFIG_AAF_ANGLE == 110)
    #define AAF_FULL_ANGLE              110U
    #define STEP_POSITION_MINIMUM_RANGE 18000U 
    #define STEP_POSITION_MAXIMUM_RANGE 23000U    
#endif

/* ====================================================================
 * LIN Communication (EV)
 * ==================================================================== */
#define LIN_ID_AAFCTRL_RX     0x27U
#define LIN_ID_AAF1_RESP_TX   0x28U
#define LIN_ID_AAF2_RESP_TX   0x29U
#define LIN_ID_AAF3_RESP_TX   0x2AU
#define LIN_CONTROL_LEN       8U
#define LIN_RESPONSE_LEN      8U

#define OPEN_1ST_POSITION 1300U
#define OPEN_2ND_POSITION 900U
#define AAF_1ST_OPEN_ANGLE 60U //@@ 기존 83 에서 변경 예정 25% -> 75% 전체 110
#define AAF_2ST_OPEN_ANGLE 30U // @@ 기존 55에서 변경 예정 50% -> 50% 전체 110

/***********************************************************************************************************************
 * 1. System Defines
***********************************************************************************************************************/
#define R_WUF_RESET           (uint32_t)0x00
#define R_WUF_INTP4           (uint32_t)(1<<10)
#define R_WUF_INTP5           (uint32_t)(1<<11)
#define R_WUF_INTP6           (uint32_t)(1<<20)
#define R_WUF_INTP10           (uint32_t)(1<<12)
#define R_WUF_ERROR           (uint32_t)0xff

#ifndef protected_write
#define protected_write(preg,pstatus,reg,value)   do{\
                                                  (preg)=0xa5u;\
                                                  (reg)=(value);\
                                                  (reg)=~(value);\
                                                  (reg)=(value);\
                                                  }while((pstatus)==1u)
#endif
/***********************************************************************************************************************
 * 2. General Defines
***********************************************************************************************************************/
#define OFF 0U
#define ON 1U
#define FAIL 0U
#define PASS 1U
#ifndef TRUE
    #define TRUE  1
#endif

#ifndef FALSE
    #define FALSE 0
#endif
#define WAITING 2U
#define UNKNOWN 0U
#define STOP 0U
#define INIT 3U
#define WAIT 0U
#define COMPLETE 1U
#define NO_ERROR 0U
#define ERROR 1U
#define Initial_Value 0U

/***********************************************************************************************************************
 * 3. Position & Movement Defines
***********************************************************************************************************************/
#define CLOSE 0U
#define OPEN_1ST 1U
#define OPEN_2ND 2U
#define OPEN 3U
#define DIAG_MODE_OPEN 4U
#define DIAG_MODE_CLOSE 5U
#define DIAG_MODE_AUTO 6U
#define UNKOWN_POSITION 7U

#define Unknown_Status 0U
#define Open_Status 1U
#define Close_Status 2U
#define FlapMoving_Status 3U

#define FLAP_START 0U
#define FLAP_MOVING 1U
#define FLAP_STOP 7U

#define START_INITIALIZATION 0U
#define CHECK_TRAVELRANGE 1U
#define TRAVEL_RANGE_ERROR 2U
#define NORMAL_INITIALIZATION 3U
#define WAIT_INITIALIZATION 4U

#define START_INITIALIZATION_CLOSE 3U
#define START_INITIALIZATION_OPEN 0U

#define DURING_INITIALIZATION 0U
#define NORMAL_FINISHED_INITIALIZATION 1U
#define ABNORMAL_FINISHED_INITIALIZATION 2U
#define INVALID_STATUS_OF_INITIALIZATION 3U

#define INITIALIZATION 1U
#define ANTIWAIT 2U

/***********************************************************************************************************************
 * 4. Step, RPM & Timing Defines
***********************************************************************************************************************/
// RPM = 60 / (t * 2 * (360 / step angle))
// t*10000 == 10us 5us
// PPS = RPM * (360 / step angle) / 60
// PPS = RPM * (360 / step angle) / 60 >> RPM = PPS * (ANGLE / 360) * 60
// #define STEP_TIME_1125RPM 28U // 450PPS
#define STEP_TIME_1250RPM 28U // 500PPS(4000) = 25, 450PPS(3600) = 27~28
#define STEP_TIME_1000RPM 28U

#define REFERENCE_POSITION 30000U // 30000
#define LIMIT_POSITION 1800U
#define TOLERANCE 100U
#define ERROR_RANGE 5U

// init action
#define INIT_ACTION_POSITION 1450U



// #define POSITION_MAXIMUM_RANGE 55000U
// #define LIMITSTEP_MAXIMUM_RANGE 1700U
#define POSITION_MAXIMUM_RANGE 70000U
#define LIMITSTEP_MAXIMUM_RANGE 3000U

#define MOTOR_WAIT_TIME 50U // 30default

#define LIN_BUS_CHK_TIME_4_SEC 4000U

/***********************************************************************************************************************
 * 5. ADC & Voltage Thresholds Defines
***********************************************************************************************************************/

// ADC chk MAX 4096
/*
 V    adc_data

0.8	652
0.9	732
1.0	813
1.1	895
1.2	975
1.3	1058
1.4	1139
1.5	1224
1.6	1304
1.7	1386
1.8	1467
1.9	1548
2.0	1627
2.1	1711
2.2	1793
2.3	1874
2.4	1955
2.5	2036
2.6	2119
2.7	2203
2.8	2283
2.9	2366
3.0	2447
3.1	2527
3.2	2610
3.3	2694
3.4	2777
3.5	2858
3.6	2939
3.7	3020
3.8	3101
3.9	3183
4.0	3267
4.1	3349
4.2	3431
4.3	3513
4.4	3593
4.5	3674
4.6	3758
4.7	3841
4.8	3923
4.9	4003

*/
// AAF V1.2 260123 ADC CHECK PCB VER
//ADC_UNDER_VOLTAGE
// #define ADC_UNDER_VOLTAGE_7V 1262U 
// #define ADC_UNDER_VOLTAGE_8_5V 1566U
// #define ADC_UNDER_VOLTAGE_9V 1667U

// //ADC_OVER_VOLTAGE
// #define ADC_VOLTAGE_15V 2887U
// #define ADC_OVER_VOLTAGE_16V 3070U
// #define ADC_OVER_VOLTAGE_16_5V 3170U
// #define ADC_OVER_VOLTAGE_18V 3480U

// //ADC_VOLTAGE
// #define ADC_VOLTAGE_10V 1850U	// slew change
// #define ADC_VOLTAGE_10_5V 1950U // slew change
// #define ADC_VOLTAGE_15V 2887U   // slew change
// #define ADC_VOLTAGE_14V 2681U

// HW 1.2 ADC 최신
#define ADC_UNDER_VOLTAGE_7V 618U	 
#define ADC_UNDER_VOLTAGE_8_5V 764U	 
#define ADC_UNDER_VOLTAGE_9V 814U
#define ADC_VOLTAGE_10V 914U   
#define ADC_VOLTAGE_10_5V 964U 
#define ADC_VOLTAGE_14V 1313U	
#define ADC_VOLTAGE_15V 1412U
#define ADC_OVER_VOLTAGE_16V 1512U	 
#define ADC_OVER_VOLTAGE_16_5V 1561U 
#define ADC_OVER_VOLTAGE_18V 1710U	 






// #define ADC_VOLTAGE_9_5V 1769U
// #define ADC_VOLTAGE_11V 2069U
// #define ADC_VOLTAGE_11_5V 2171U
// #define ADC_VOLTAGE_12V 2273U
// #define ADC_VOLTAGE_13_5V 2587U
// #define ADC_VOLTAGE_13_7V 2627U
// #define ADC_VOLTAGE_13_8V 2641U
// #define ADC_VOLTAGE_14V 2681U
// #define ADC_VOLTAGE_14_4V 2761U
// #define ADC_VOLTAGE_14_5V 2781U
// #define ADC_VOLTAGE_14_6V 2801U
// #define ADC_VOLTAGE_14_7V 2821U
// #define ADC_VOLTAGE_14_8V 2847U
// #define ADC_VOLTAGE_15V 2887U

#define LOW_VOLTAGE 1U
#define NORMAL_VOLTAGE 2U
#define HIGH_VOLTAGE 3U

/***********************************************************************************************************************
 * 6. Stall Check & Motor Faults
***********************************************************************************************************************/

#define MOTOR_STALL_CHK_NORMAL_VALUE 160U
#define MOTOR_CW_STALL_CHK_HIGH_VALUE 255U  // 180
#define MOTOR_CCW_STALL_CHK_HIGH_VALUE 255U // 180

#define INIT_STALL_TH_VALUE 30U
#define STALL_TH_VALUE_LOW_VOLTAGE 15U  
#define STALL_TH_VALUE_NORMAL_VOLTAGE 15U  
#define STALL_TH_VALUE_HIGH_VOLTAGE 15U  


#define STALL_CNT_DEFAULT 30000U
#define STALL_CHK_WAIT_TIME 250U // 250

#define MOTOR_NORMAL 0U
#define MOTOR_STALL 1U
#define MOTOR_FAULT 0x100U

/***********************************************************************************************************************
 * 7. AAF Specifics
***********************************************************************************************************************/
#define AAF_ERROR_ANGLE 5U // V
#define SLEEP_BACKOFF_DIVIDER 2U

#define AAF_WAITING 0U
#define AAF_OPERATE 1U
#define TRAVEL_RANGE_COMPLETE_CHECK 2U
#define CHECK_AAF_CONDITION 3U
#define AAF_INITIALIZATION 4U
#define FINISHED_OPERATE 5U

#define AAF_1 1U
#define AAF_2 2U
#define AAF_3 3U
#define INTERNAL_TYPE 0U
#define EXTERNAL_TYPE 1U

#define AAFx1 1U
#define AAFx2 2U
#define AAFx3 3U

/***********************************************************************************************************************
 * 8. Faults & Error Codes
***********************************************************************************************************************/
#define AAF_CIRCUIT_OPEN 1U
#define AAF_CIRCUIT_SHORT 1U
#define UNDER_VOLTAGE 1U
#define OVER_VOLTAGE 1U
#define OVER_CURRENT 0x800U
#define HIGH_TEMPERATURE 0x200U

#define NOT_OPEN_BY_EXTERNAL_FACTORS 1U
#define NOT_CLOSE_BY_EXTERNAL_FACTORS 2U
#define OPEN_CIRCUIT 1U
#define SHORT_CIRCUIT_BATTERY 1U
#define SHORT_CIRCUIT_GROUND 1U
#define No_ErrorStatus 0U
#define Open_ErrorStatus 1U
#define Close_ErrorStatus 2U

// --- Sensors & Types ---
#define SENSOR_NO 0U
#define SENSOR_X1 1U
#define SENSOR_X2 2U
#define SENSOR_X3 3U
#define SENSOR_X4 4U

#define RH_TYPE 0U
#define LH_TYPE 1U

#define NORMAL_MODE 0U

#define Shutdown_Check 0U
#define Normal_Shutdown 1U

#define Memory_Range_Init 0U
#define Memory_Range_Break 15U

#define ADC_Detect_Time 3000U

/***********************************************************************************************************************
 * 9. High Speed Mode (EV)
***********************************************************************************************************************/
#define AAF_HIGH_SPEED_MODE_ENABLE        
#define NORMAL_DRIVE_MODE             0U // 정상 주행모드 상태값
#define HIGH_SPEED_DRIVE_MODE         1U // 고속 주행모드 상태값
#define ENTER_HIGH_SPEED          145U // 145km/h 이상이면 고속 주행모드 진입
#define EXIT_HIGH_SPEED           135U //135km/h 미만이면 정상 복귀 조건 시작
#define EXIT_HIGH_SPEED_TIME       10000U //135km/h 미만 상태가 10초 유지되어야 정상 복귀
#define ERROR_SPEED     0xFFU // 차속 0xFF는 Error ID라서 0으로 처리


#endif


