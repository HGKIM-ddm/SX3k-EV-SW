#ifndef DRV8889_H
#define DRV8889_H

#include "Config.h"

/* ====================================================================
 * 레지스터 주소 (프레임 주소필드 값 = 실제주소 × 2)
 *   Write 프레임 = (addr << 8) | data
 * ==================================================================== */
#define DRV_FAULT       0x00U   /* 실제 0x00 (R)  Fault Status */
#define DRV_DIAG1       0x02U   /* 실제 0x01 (R)  Diag Status 1 */
#define DRV_DIAG2       0x04U   /* 실제 0x02 (R)  Diag Status 2 */
#define DRV_CTRL1       0x06U   /* 실제 0x03 (RW) */
#define DRV_CTRL2       0x08U   /* 실제 0x04 (RW) */
#define DRV_CTRL3       0x0AU   /* 실제 0x05 (RW) */
#define DRV_CTRL4       0x0CU   /* 실제 0x06 (RW) */
#define DRV_CTRL5       0x0EU   /* 실제 0x07 (RW) */
#define DRV_CTRL6       0x10U   /* 실제 0x08 (RW) */
#define DRV_CTRL7       0x12U   /* 실제 0x09 (R)  TRQ_COUNT */
#define DRV_CTRL8       0x14U   /* 실제 0x0A (R)  REV_ID */

#define MOTOR_STALL_BIT  0x0400U

/* ====================================================================
 * CTRL1 (0x03) : TRQ_DAC[7:4] | RSVD[3:2] | SLEW_RATE[1:0]
 *   현재값 0x40 = TRQ_DAC_75 | SLEW_RATE_10V
 * ==================================================================== */
/* TRQ_DAC[3:0] → bit7-4 (<<4). 토크(전류) 스케일 (Table 7-24) */
typedef enum {
    TRQ_DAC_100     = (0x0U << 4),   /* 100%   */
    TRQ_DAC_93_75   = (0x1U << 4),   /* 93.75% */
    TRQ_DAC_87_5    = (0x2U << 4),   /* 87.5%  */
    TRQ_DAC_81_25   = (0x3U << 4),   /* 81.25% */
    TRQ_DAC_75      = (0x4U << 4),   /* 75%    */
    TRQ_DAC_68_75   = (0x5U << 4),   /* 68.75% */
    TRQ_DAC_62_5    = (0x6U << 4),   /* 62.5%  */
    TRQ_DAC_56_25   = (0x7U << 4),   /* 56.25% */
    TRQ_DAC_50      = (0x8U << 4),   /* 50%    */
    TRQ_DAC_43_75   = (0x9U << 4),   /* 43.75% */
    TRQ_DAC_37_5    = (0xAU << 4),   /* 37.5%  */
    TRQ_DAC_31_25   = (0xBU << 4),   /* 31.25% */
    TRQ_DAC_25      = (0xCU << 4),   /* 25%    */
    TRQ_DAC_18_75   = (0xDU << 4),   /* 18.75% */
    TRQ_DAC_12_5    = (0xEU << 4),   /* 12.5%  */
    TRQ_DAC_6_25    = (0xFU << 4)    /* 6.25%  */
} Drv_TrqDac_t;
 
/* SLEW_RATE[1:0] → bit1-0 (<<0) (Table 7-24) */
typedef enum {
    SLEW_RATE_10V   = (0x0U << 0),   /* 10 V/us (현재) */
    SLEW_RATE_35V   = (0x1U << 0),   /* 35 V/us */
    SLEW_RATE_50V   = (0x2U << 0),   /* 50 V/us */
    SLEW_RATE_105V  = (0x3U << 0)    /* 105 V/us */
} Drv_SlewRate_t;
 
/* ====================================================================
 * CTRL2 (0x04) : DIS_OUT[7] | RSVD[6:5] | TOFF[4:3] | DECAY[2:0]
 *   현재값 0x0F = DIS_OUT_EN | TOFF_16US | DECAY_SMART_RIPPLE
 * ==================================================================== */
/* DIS_OUT → bit7 (Table 7-25) */
typedef enum {
    DIS_OUT_ENABLE  = (0x0U << 7),   /* 출력 enable (현재) */
    DIS_OUT_HIZ     = (0x1U << 7)    /* 출력 Hi-Z */
} Drv_DisOut_t;
 
/* TOFF[1:0] → bit4-3 (<<3) (Table 7-25) */
typedef enum {
    TOFF_7US        = (0x0U << 3),   /* 7 us  */
    TOFF_16US       = (0x1U << 3),   /* 16 us (현재) */
    TOFF_24US       = (0x2U << 3),   /* 24 us */
    TOFF_32US       = (0x3U << 3)    /* 32 us */
} Drv_Toff_t;
 
/* DECAY[2:0] → bit2-0 (<<0) (Table 7-25) */
typedef enum {
    DECAY_SLOW_SLOW         = (0x0U << 0),  /* inc SLOW, dec SLOW */
    DECAY_SLOW_MIXED30      = (0x1U << 0),  /* inc SLOW, dec MIXED 30% */
    DECAY_SLOW_MIXED60      = (0x2U << 0),  /* inc SLOW, dec MIXED 60% */
    DECAY_SLOW_FAST         = (0x3U << 0),  /* inc SLOW, dec FAST */
    DECAY_MIXED30_MIXED30   = (0x4U << 0),  /* inc MIXED30, dec MIXED30 */
    DECAY_MIXED60_MIXED60   = (0x5U << 0),  /* inc MIXED60, dec MIXED60 */
    DECAY_SMART_DYNAMIC     = (0x6U << 0),  /* Smart tune Dynamic Decay */
    DECAY_SMART_RIPPLE      = (0x7U << 0)   /* Smart tune Ripple Control (현재) */
} Drv_Decay_t;
 
/* ====================================================================
 * CTRL3 (0x05) : DIR[7] | STEP[6] | SPI_DIR[5] | SPI_STEP[4] | MICROSTEP[3:0]
 *   현재값 0x05 = DIR_PIN | STEP_PIN | SPI_DIR_PIN | SPI_STEP_PIN | MICROSTEP_1_8
 * ==================================================================== */
/* DIR → bit7 (Table 7-26) (SPI_DIR=1일 때만 유효) */
typedef enum {
    DIR_PIN_LOW     = (0x0U << 7),   /* (현재, 단 SPI_DIR=0이라 핀이 우선) */
    DIR_PIN_HIGH    = (0x1U << 7)
} Drv_Dir_t;
 
/* STEP → bit6 (SPI_STEP=1일 때만 유효, self-clearing) */
typedef enum {
    STEP_NONE       = (0x0U << 6),   /* (현재) */
    STEP_ADVANCE    = (0x1U << 6)    /* indexer 1스텝 진행 */
} Drv_Step_t;
 
/* SPI_DIR → bit5 (방향 소스 선택) */
typedef enum {
    SPI_DIR_PIN     = (0x0U << 5),   /* DIR 핀 따름 (현재, P10_4) */
    SPI_DIR_REG     = (0x1U << 5)    /* SPI DIR 비트 따름 */
} Drv_SpiDir_t;
 
/* SPI_STEP → bit4 (스텝 소스 선택) */
typedef enum {
    SPI_STEP_PIN    = (0x0U << 4),   /* STEP 핀 따름 (현재, P9_0 PWM) */
    SPI_STEP_REG    = (0x1U << 4)    /* SPI STEP 비트 따름 */
} Drv_SpiStep_t;
 
/* MICROSTEP_MODE[3:0] → bit3-0 (<<0) (Table 7-26) */
typedef enum {
    MICROSTEP_FULL_100  = (0x0U << 0),  /* Full step (2상), 100% 전류 */
    MICROSTEP_FULL_71   = (0x1U << 0),  /* Full step (2상), 71% 전류 */
    MICROSTEP_NONCIRC   = (0x2U << 0),  /* Non-circular 1/2 step */
    MICROSTEP_1_2       = (0x3U << 0),  /* 1/2 step */
    MICROSTEP_1_4       = (0x4U << 0),  /* 1/4 step */
    MICROSTEP_1_8       = (0x5U << 0),  /* 1/8 step (현재) */
    MICROSTEP_1_16      = (0x6U << 0),  /* 1/16 step */
    MICROSTEP_1_32      = (0x7U << 0),  /* 1/32 step */
    MICROSTEP_1_64      = (0x8U << 0),  /* 1/64 step */
    MICROSTEP_1_128     = (0x9U << 0),  /* 1/128 step */
    MICROSTEP_1_256     = (0xAU << 0)   /* 1/256 step */
} Drv_Microstep_t;
 
/* ====================================================================
 * CTRL4 (0x06) : CLR_FLT[7] | LOCK[6:4] | EN_OL[3] | OCP_MODE[2] | OTSD_MODE[1] | TW_REP[0]
 *   현재값 0x3E = CLR_NONE | LOCK_UNLOCK | EN_OL_ON | OCP_RETRY | OTSD_RECOVER | TW_NO_REP
 * ==================================================================== */
/* CLR_FLT → bit7 (자동 self-clear) */
typedef enum {
    CLR_FLT_NONE    = (0x0U << 7),   /* (현재) */
    CLR_FLT_CLEAR   = (0x1U << 7)    /* latched fault clear */
} Drv_ClrFlt_t;
 
/* LOCK[2:0] → bit6-4 (<<4) (Table 7-27) */
typedef enum {
    LOCK_UNLOCK     = (0x3U << 4),   /* 011b = unlock (현재) */
    LOCK_LOCK       = (0x6U << 4)    /* 110b = lock */
} Drv_Lock_t;
 
/* EN_OL → bit3 (open load 검출) */
typedef enum {
    EN_OL_OFF       = (0x0U << 3),
    EN_OL_ON        = (0x1U << 3)    /* (현재) open load 검출 enable */
} Drv_EnOl_t;
 
/* OCP_MODE → bit2 (과전류 대응) */
typedef enum {
    OCP_LATCH       = (0x0U << 2),   /* latched fault */
    OCP_RETRY       = (0x1U << 2)    /* (현재) 자동 재시도 */
} Drv_OcpMode_t;
 
/* OTSD_MODE → bit1 (과온 대응) */
typedef enum {
    OTSD_LATCH      = (0x0U << 1),   /* latched fault */
    OTSD_RECOVER    = (0x1U << 1)    /* (현재) 자동 복구 */
} Drv_OtsdMode_t;
 
/* TW_REP → bit0 (과온/저온 경고 보고) */
typedef enum {
    TW_NO_REP       = (0x0U << 0),   /* (현재) nFAULT 미보고 */
    TW_REP          = (0x1U << 0)    /* nFAULT 보고 */
} Drv_TwRep_t;
 
/* ====================================================================
 * CTRL5 (0x07) : RSVD[7:6] | STL_LRN[5] | EN_STL[4] | STL_REP[3] | RSVD[2:0]
 *   현재값 0x10 = STL_LRN_OFF | EN_STL_ON | STL_REP_OFF
 *   (DRV8889A-Q1: Table 7-29 기준)
 * ==================================================================== */
/* STL_LRN → bit5 (stall 학습, self-clear) */
typedef enum {
    STL_LRN_NONE    = (0x0U << 5),   /* (현재) */
    STL_LRN_START   = (0x1U << 5)    /* stall count 학습 시작 */
} Drv_StlLrn_t;
 
/* EN_STL → bit4 (stall 검출) */
typedef enum {
    EN_STL_OFF      = (0x0U << 4),   /* stall 검출 disable */
    EN_STL_ON       = (0x1U << 4)    /* (현재) stall 검출 enable */
} Drv_EnStl_t;
 
/* STL_REP → bit3 (stall nFAULT 보고) */
typedef enum {
    STL_REP_OFF     = (0x0U << 3),   /* (현재) nFAULT 미보고 → SW 판정 */
    STL_REP_ON      = (0x1U << 3)    /* nFAULT 보고 */
} Drv_StlRep_t;

/* CTRL5 EN_SR_BLANK → bit0 (DRV8889A-Q1 전용) */
typedef enum {
    EN_SR_BLANK_OFF = (0x0U << 0),
    EN_SR_BLANK_ON  = (0x1U << 0)
} Drv_EnSrBlank_t; 
/* ====================================================================
 * CTRL6 (0x08) : STALL_TH[7:0]
 *   현재값 0x00 = STALL_TH 0 (HW 자동 스톨 최소, SW에서 TRQ_COUNT로 직접 판정)

 * ==================================================================== */
#define STALL_TH 15U
/* 0 = 0 count, 0xFF = 255 counts (Table 7-30) */

void Drv8889_GpioInit(void);
void Drv8889_Wakeup(void);
void Drv8889_Sleep(void);

void Drv8889_On(void);
void Drv8889_On2(void);
void Drv8889_Off(void);
void Drv8889_Off2(void);

void Drv8889_ScsActive(void);
void Drv8889_ScsInactive(void);

void Drv8889_StepHigh(void); 
void Drv8889_StepLow(void); 

void Drv8889_DirCW(void);  
void Drv8889_DirCCW(void);  

void Drv8889_SpiInit(void);
void Drv8889_FaultClear(void);
void Drv8889_IsFault(void);
uint8_t Drv8889_IsStallBitSet(void);

void Drv8889_WriteCtrl1(Drv_TrqDac_t trq, Drv_SlewRate_t slew);
void Drv8889_WriteCtrl6(uint8_t stall_th);

void Drv8889_ReadDiag(uint8_t idx);

#endif


