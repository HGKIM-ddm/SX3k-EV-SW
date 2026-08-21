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
* Copyright (C) 2018, 2025 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name        : r_cg_taud.h
* Version          : 1.0.151
* Device(s)        : R7F701695
* Description      : General header file for TAUD peripheral.
***********************************************************************************************************************/

#ifndef TAUD_H
#define TAUD_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/
/*
    TAUDTTINm Input Signal Selection Register (SELB_TAUD0I)
*/
/* Selection of TAUDTTIN15 input signal (SELB_TAUD0I15)*/
#define _TAUD_INPUT_SIGNAL_CH15_TAUDI14                     (0x8000U) /* TAUD0I14 is selected */
/* Selection of TAUDTTIN14 input signal (SELB_TAUD0I14) */
#define _TAUD_INPUT_SIGNAL_CH14_TAUDI15                     (0x4000U) /* TAUD0I15 is selected */
/* Selection of TAUDTTIN13 input signal (SELB_TAUD0I13) */
#define _TAUD_INPUT_SIGNAL_CH13_TAUDI12                     (0x2000U) /* TAUD0I12 is selected */
/* Selection of TAUDTTIN12 input signal (SELB_TAUD0I12) */
#define _TAUD_INPUT_SIGNAL_CH12_TAUDI13                     (0x1000U) /* TAUD0I13 is selected */
/* Selection of TAUDTTIN11 input signal (SELB_TAUD0I11) */
#define _TAUD_INPUT_SIGNAL_CH11_TAUDI10                     (0x0800U) /* TAUD0I10 is selected */
/* Selection of TAUDTTIN10 input signal (SELB_TAUD0I10) */
#define _TAUD_INPUT_SIGNAL_CH10_TAUDI11                     (0x0400U) /* TAUD0I11 is selected */
/* Selection of TAUDTTIN9 input signal (SELB_TAUD0I9) */
#define _TAUD_INPUT_SIGNAL_CH9_TAUDI8                       (0x0200U) /* TAUD0I8 is selected */
/* Selection of TAUDTTIN8 input signal (SELB_TAUD0I8) */
#define _TAUD_INPUT_SIGNAL_CH8_TAUDI9                       (0x0100U) /* TAUD0I9 is selected */
/* Selection of TAUDTTIN7 input signal (SELB_TAUD0I7)*/
#define _TAUD_INPUT_SIGNAL_CH7_TAUDI6                       (0x0080U) /* TAUD0I6 is selected */
/* Selection of TAUDTTIN6 input signal (SELB_TAUD0I6) */
#define _TAUD_INPUT_SIGNAL_CH6_TAUDI7                       (0x0040U) /* TAUD0I7 is selected */
/* Selection of TAUDTTIN5 input signal (SELB_TAUD0I5) */
#define _TAUD_INPUT_SIGNAL_CH5_TAUDI4                       (0x0020U) /* TAUD0I4 is selected */
/* Selection of TAUDTTIN4 input signal (SELB_TAUD0I4) */
#define _TAUD_INPUT_SIGNAL_CH4_TAUDI5                       (0x0010U) /* TAUD0I5 is selected */
/* Selection of TAUDTTIN3 input signal (SELB_TAUD0I3) */
#define _TAUD_INPUT_SIGNAL_CH3_TAUDI2                       (0x0008U) /* TAUD0I2 is selected */
/* Selection of TAUDTTIN2 input signal (SELB_TAUD0I2) */
#define _TAUD_INPUT_SIGNAL_CH2_TAUDI3                       (0x0004U) /* TAUD0I3 is selected */
/* Selection of TAUDTTIN1 input signal (SELB_TAUD0I1) */
#define _TAUD_INPUT_SIGNAL_CH1_TAUDI0                       (0x0002U) /* TAUD0I0 is selected */
/* Selection of TAUDTTIN0 input signal (SELB_TAUD0I0) */
#define _TAUD_INPUT_SIGNAL_CH0_TAUDI1                       (0x0001U) /* TAUD0I1 is selected */

/*
    TAUDn Prescaler Clock Select Register (TAUDnTPS)
*/
/* Specifies the CK3 clock (TAUDnPRS3[3:0]) */
#define _TAUD_CK3_PRE_PCLK_0                                (0x0000U) /* CK3_PRE - PCLK/2^0 */
#define _TAUD_CK3_PRE_PCLK_1                                (0x1000U) /* CK3_PRE - PCLK/2^1 */
#define _TAUD_CK3_PRE_PCLK_2                                (0x2000U) /* CK3_PRE - PCLK/2^2 */
#define _TAUD_CK3_PRE_PCLK_3                                (0x3000U) /* CK3_PRE - PCLK/2^3 */
#define _TAUD_CK3_PRE_PCLK_4                                (0x4000U) /* CK3_PRE - PCLK/2^4 */
#define _TAUD_CK3_PRE_PCLK_5                                (0x5000U) /* CK3_PRE - PCLK/2^5 */
#define _TAUD_CK3_PRE_PCLK_6                                (0x6000U) /* CK3_PRE - PCLK/2^6 */
#define _TAUD_CK3_PRE_PCLK_7                                (0x7000U) /* CK3_PRE - PCLK/2^7 */
#define _TAUD_CK3_PRE_PCLK_8                                (0x8000U) /* CK3_PRE - PCLK/2^8 */
#define _TAUD_CK3_PRE_PCLK_9                                (0x9000U) /* CK3_PRE - PCLK/2^9 */
#define _TAUD_CK3_PRE_PCLK_10                               (0xA000U) /* CK3_PRE - PCLK/2^10 */
#define _TAUD_CK3_PRE_PCLK_11                               (0xB000U) /* CK3_PRE - PCLK/2^11 */
#define _TAUD_CK3_PRE_PCLK_12                               (0xC000U) /* CK3_PRE - PCLK/2^12 */
#define _TAUD_CK3_PRE_PCLK_13                               (0xD000U) /* CK3_PRE - PCLK/2^13 */
#define _TAUD_CK3_PRE_PCLK_14                               (0xE000U) /* CK3_PRE - PCLK/2^14 */
#define _TAUD_CK3_PRE_PCLK_15                               (0xF000U) /* CK3_PRE - PCLK/2^15 */
#define _TAUD_CK3_PRS_CLEAR                                 (0x0FFFU) /* CK3_PRE - clear */
/* Specifies the CK2 clock (TAUDnPRS2[3:0]) */
#define _TAUD_CK2_PRE_PCLK_0                                (0x0000U) /* CK2_PRE - PCLK/2^0 */
#define _TAUD_CK2_PRE_PCLK_1                                (0x0100U) /* CK2_PRE - PCLK/2^1 */
#define _TAUD_CK2_PRE_PCLK_2                                (0x0200U) /* CK2_PRE - PCLK/2^2 */
#define _TAUD_CK2_PRE_PCLK_3                                (0x0300U) /* CK2_PRE - PCLK/2^3 */
#define _TAUD_CK2_PRE_PCLK_4                                (0x0400U) /* CK2_PRE - PCLK/2^4 */
#define _TAUD_CK2_PRE_PCLK_5                                (0x0500U) /* CK2_PRE - PCLK/2^5 */
#define _TAUD_CK2_PRE_PCLK_6                                (0x0600U) /* CK2_PRE - PCLK/2^6 */
#define _TAUD_CK2_PRE_PCLK_7                                (0x0700U) /* CK2_PRE - PCLK/2^7 */
#define _TAUD_CK2_PRE_PCLK_8                                (0x0800U) /* CK2_PRE - PCLK/2^8 */
#define _TAUD_CK2_PRE_PCLK_9                                (0x0900U) /* CK2_PRE - PCLK/2^9 */
#define _TAUD_CK2_PRE_PCLK_10                               (0x0A00U) /* CK2_PRE - PCLK/2^10 */
#define _TAUD_CK2_PRE_PCLK_11                               (0x0B00U) /* CK2_PRE - PCLK/2^11 */
#define _TAUD_CK2_PRE_PCLK_12                               (0x0C00U) /* CK2_PRE - PCLK/2^12 */
#define _TAUD_CK2_PRE_PCLK_13                               (0x0D00U) /* CK2_PRE - PCLK/2^13 */
#define _TAUD_CK2_PRE_PCLK_14                               (0x0E00U) /* CK2_PRE - PCLK/2^14 */
#define _TAUD_CK2_PRE_PCLK_15                               (0x0F00U) /* CK2_PRE - PCLK/2^15 */
#define _TAUD_CK2_PRS_CLEAR                                 (0xF0FFU) /* CK2_PRE - clear */
/* Specifies the CK1 clock (TAUDnPRS1[3:0]) */
#define _TAUD_CK1_PRE_PCLK_0                                (0x0000U) /* CK1_PRE - PCLK/2^0 */
#define _TAUD_CK1_PRE_PCLK_1                                (0x0010U) /* CK1_PRE - PCLK/2^1 */
#define _TAUD_CK1_PRE_PCLK_2                                (0x0020U) /* CK1_PRE - PCLK/2^2 */
#define _TAUD_CK1_PRE_PCLK_3                                (0x0030U) /* CK1_PRE - PCLK/2^3 */
#define _TAUD_CK1_PRE_PCLK_4                                (0x0040U) /* CK1_PRE - PCLK/2^4 */
#define _TAUD_CK1_PRE_PCLK_5                                (0x0050U) /* CK1_PRE - PCLK/2^5 */
#define _TAUD_CK1_PRE_PCLK_6                                (0x0060U) /* CK1_PRE - PCLK/2^6 */
#define _TAUD_CK1_PRE_PCLK_7                                (0x0070U) /* CK1_PRE - PCLK/2^7 */
#define _TAUD_CK1_PRE_PCLK_8                                (0x0080U) /* CK1_PRE - PCLK/2^8 */
#define _TAUD_CK1_PRE_PCLK_9                                (0x0090U) /* CK1_PRE - PCLK/2^9 */
#define _TAUD_CK1_PRE_PCLK_10                               (0x00A0U) /* CK1_PRE - PCLK/2^10 */
#define _TAUD_CK1_PRE_PCLK_11                               (0x00B0U) /* CK1_PRE - PCLK/2^11 */
#define _TAUD_CK1_PRE_PCLK_12                               (0x00C0U) /* CK1_PRE - PCLK/2^12 */
#define _TAUD_CK1_PRE_PCLK_13                               (0x00D0U) /* CK1_PRE - PCLK/2^13 */
#define _TAUD_CK1_PRE_PCLK_14                               (0x00E0U) /* CK1_PRE - PCLK/2^14 */
#define _TAUD_CK1_PRE_PCLK_15                               (0x00F0U) /* CK1_PRE - PCLK/2^15 */
#define _TAUD_CK1_PRS_CLEAR                                 (0xFF0FU) /* CK1_PRE - clear */
/* Specifies the CK0 clock (TAUDnPRS0[3:0]) */
#define _TAUD_CK0_PRE_PCLK_0                                (0x0000U) /* CK0_PRE - PCLK/2^0 */
#define _TAUD_CK0_PRE_PCLK_1                                (0x0001U) /* CK0_PRE - PCLK/2^1 */
#define _TAUD_CK0_PRE_PCLK_2                                (0x0002U) /* CK0_PRE - PCLK/2^2 */
#define _TAUD_CK0_PRE_PCLK_3                                (0x0003U) /* CK0_PRE - PCLK/2^3 */
#define _TAUD_CK0_PRE_PCLK_4                                (0x0004U) /* CK0_PRE - PCLK/2^4 */
#define _TAUD_CK0_PRE_PCLK_5                                (0x0005U) /* CK0_PRE - PCLK/2^5 */
#define _TAUD_CK0_PRE_PCLK_6                                (0x0006U) /* CK0_PRE - PCLK/2^6 */
#define _TAUD_CK0_PRE_PCLK_7                                (0x0007U) /* CK0_PRE - PCLK/2^7 */
#define _TAUD_CK0_PRE_PCLK_8                                (0x0008U) /* CK0_PRE - PCLK/2^8 */
#define _TAUD_CK0_PRE_PCLK_9                                (0x0009U) /* CK0_PRE - PCLK/2^9 */
#define _TAUD_CK0_PRE_PCLK_10                               (0x000AU) /* CK0_PRE - PCLK/2^10 */
#define _TAUD_CK0_PRE_PCLK_11                               (0x000BU) /* CK0_PRE - PCLK/2^11 */
#define _TAUD_CK0_PRE_PCLK_12                               (0x000CU) /* CK0_PRE - PCLK/2^12 */
#define _TAUD_CK0_PRE_PCLK_13                               (0x000DU) /* CK0_PRE - PCLK/2^13 */
#define _TAUD_CK0_PRE_PCLK_14                               (0x000EU) /* CK0_PRE - PCLK/2^14 */
#define _TAUD_CK0_PRE_PCLK_15                               (0x000FU) /* CK0_PRE - PCLK/2^15 */
#define _TAUD_CK0_PRS_CLEAR                                 (0xFFF0U) /* CK0_PRE - clear */

/*
    TAUDn Channel Mode OS Register (TAUDnCMORm)
*/
/* Selects an operation clock (TAUDnCKS[1:0]) */
#define _TAUD_SELECTION_CK0                                 (0x0000U) /* CK0 */
#define _TAUD_SELECTION_CK1                                 (0x4000U) /* CK1 */
#define _TAUD_SELECTION_CK2                                 (0x8000U) /* CK2 */
#define _TAUD_SELECTION_CK3                                 (0xC000U) /* CK3 */
/* Selects a count clock for TAUDnCNTm counter (TAUDnCCS[1:0]) */
#define _TAUD_COUNT_CLOCK_PCLK                              (0x0000U) /* Operation clock specified by TAUDnCKS[1:0] */
#define _TAUD_COUNT_CLOCK_INPUT_EDGE                        (0x1000U) /* Valid edge of TAUDnTTINm input signal */
#define _TAUD_COUNT_CLOCK_INPUT_INT                         (0x3000U) /* INTTAUDnIm signal of master channel */
/* Specifies a master or slave channel during synchronous channel operation (TAUDnMAS) */
#define _TAUD_INDEPENDENT_CHANNEL                           (0x0000U) /* Independent channel */
#define _TAUD_SLAVE_CHANNEL                                 (0x0000U) /* Slave */
#define _TAUD_MASTER_CHANNEL                                (0x0800U) /* Master */
/* Selects an external start trigger (TAUDnSTS[2:0]) */
#define _TAUD_START_TRIGGER_SOFTWARE                        (0x0000U) /* Software trigger */
#define _TAUD_START_TRIGGER_VALID_EDGE                      (0x0100U) /* Valid edge of TAUDnTTINm input signal */
#define _TAUD_START_STOP_TRIGGER_VALID_EDGE                 (0x0200U) /* Valid edge used as a start/stop trigger */
#define _TAUD_START_TRIGGER_SIMULTANEOUS_REWRITE            (0x0300U) /* Trigger simultaneous rewrite */
#define _TAUD_START_TRIGGER_MASTER_INT                      (0x0400U) /* INTTAUDnIm of master channel */
#define _TAUD_START_TRIGGER_UPPER_INT                       (0x0500U) /* INTTAUDnIm of upper channel (m - 1) */
#define _TAUD_START_TRIGGER_DEAD_TIME_OUTPUT                (0x0600U) /* Dead time output signal */
#define _TAUD_START_TRIGGER_UP_DOWN_OUTPUT                  (0x0700U) /* Up/down output trigger signal */
/* Specifies the timing for updating capture register and overflow flag (TAUDnCOS[1:0]) */
#define _TAUD_OVERFLOW_AUTO_CLEAR                           (0x0000U) /* TAUDnOVF is set by TAUDnTTINm valid edge */
#define _TAUD_OVERFLOW_MANUAL_CLEAR                         (0x0040U) /* TAUDnOVF is set by TAUDnCLOV */
#define _TAUD_OVERFLOW_COUNT_STOP                           (0x0080U) /* Counter update, TAUDnOVF is not set */
#define _TAUD_OVERFLOW_COUNT_STOP_MANUAL_CLEAR              (0x00C0U) /* Counter update, TAUDnOVF is set by TAUDnCLOV */
/* Specifies an operating mode (TAUDnMD[4:1]) */
#define _TAUD_INTERVAL_TIMER_MODE                           (0x0000U) /* Interval timer mode */
#define _TAUD_JUDGE_MODE                                    (0x0002U) /* Judge mode */
#define _TAUD_CAPTURE_MODE                                  (0x0004U) /* Capture mode */
#define _TAUD_EVENT_COUNT_MODE                              (0x0006U) /* Event count mode */
#define _TAUD_ONE_COUNT_MODE                                (0x0008U) /* One-count mode */
#define _TAUD_CAPTURE_ONE_COUNT_MODE                        (0x000CU) /* Capture and one-count mode */
#define _TAUD_JUDGE_ONE_COUNT_MODE                          (0x000EU) /* Judge and one-count mode */
#define _TAUD_COUNT_UP_DOWN_MODE                            (0x0012U) /* Count-up/-down mode */
#define _TAUD_PULSE_ONECOUNT_MODE                           (0x0014U) /* Pulse one-count mode */
#define _TAUD_COUNT_CAPTURE_MODE                            (0x0016U) /* Count capture mode */
#define _TAUD_GATE_COUNT_MODE                               (0x0018U) /* Gate count mode */
#define _TAUD_CAPTURE_AND_GATE_COUNT_MODE                   (0x001AU) /* Capture and gate count mode */
/* Role of TAUDnMD0 Bit (TAUDnMD0) */
#define _TAUD_START_INT_NOT_GENERATED                       (0x0000U) /* INTTAUDnIm is not generated */
#define _TAUD_START_TRIGGER_DISABLE                         (0x0000U) /* Disables detection */
#define _TAUD_OUTPUT_IN_SIGNAL_WIDTH                        (0x0000U) /* INTTAUDnIm output in signal width */
#define _TAUD_START_INT_GENERATED                           (0x0001U) /* INTTAUDnIm is generated */
#define _TAUD_START_TRIGGER_ENABLE                          (0x0001U) /* Enables detection */
#define _TAUD_OUTPUT_OVER_SIGNAL_WIDTH                      (0x0001U) /* INTTAUDnIm output over signal width */

/*
    TAUDn Channel Mode User Register (TAUDnCMURm)
*/
/* Specifies a valid edge of TAUDnTTINm input signal (TAUDnTIS[1:0]) */
#define _TAUD_INPUT_EDGE_UNUSED                             (0x00U) /* Unused edge detection */
#define _TAUD_INPUT_EDGE_FALLING                            (0x00U) /* Falling edge */
#define _TAUD_INPUT_EDGE_RISING                             (0x01U) /* Rising edge */
#define _TAUD_INPUT_EDGE_BOTH_MEASURE_LOW                   (0x02U) /* Both edges (selects low width measurement) */
#define _TAUD_INPUT_EDGE_BOTH_MEASURE_HIGH                  (0x03U) /* Both edges (selects high width measurement) */

/*
    TAUDn Channel Start Trigger Register (TAUDnTS)
*/
/* Enables the counter operation of channel 15 (TAUDnTS15) */
#define _TAUD_CHANNEL15_COUNTER_START                       (0x8000U) /* Enables the counter operation */
/* Enables the counter operation of channel 14 (TAUDnTS14) */
#define _TAUD_CHANNEL14_COUNTER_START                       (0x4000U) /* Enables the counter operation */
/* Enables the counter operation of channel 13 (TAUDnTS13) */
#define _TAUD_CHANNEL13_COUNTER_START                       (0x2000U) /* Enables the counter operation */
/* Enables the counter operation of channel 12 (TAUDnTS12) */
#define _TAUD_CHANNEL12_COUNTER_START                       (0x1000U) /* Enables the counter operation */
/* Enables the counter operation of channel 11 (TAUDnTS11) */
#define _TAUD_CHANNEL11_COUNTER_START                       (0x0800U) /* Enables the counter operation */
/* Enables the counter operation of channel 10 (TAUDnTS10) */
#define _TAUD_CHANNEL10_COUNTER_START                       (0x0400U) /* Enables the counter operation */
/* Enables the counter operation of channel 9 (TAUDnTS9) */
#define _TAUD_CHANNEL9_COUNTER_START                        (0x0200U) /* Enables the counter operation */
/* Enables the counter operation of channel 8 (TAUDnTS8) */
#define _TAUD_CHANNEL8_COUNTER_START                        (0x0100U) /* Enables the counter operation */
/* Enables the counter operation of channel 7 (TAUDnTS7) */
#define _TAUD_CHANNEL7_COUNTER_START                        (0x0080U) /* Enables the counter operation */
/* Enables the counter operation of channel 6 (TAUDnTS6) */
#define _TAUD_CHANNEL6_COUNTER_START                        (0x0040U) /* Enables the counter operation */
/* Enables the counter operation of channel 5 (TAUDnTS5) */
#define _TAUD_CHANNEL5_COUNTER_START                        (0x0020U) /* Enables the counter operation */
/* Enables the counter operation of channel 4 (TAUDnTS4) */
#define _TAUD_CHANNEL4_COUNTER_START                        (0x0010U) /* Enables the counter operation */
/* Enables the counter operation of channel 3 (TAUDnTS3) */
#define _TAUD_CHANNEL3_COUNTER_START                        (0x0008U) /* Enables the counter operation */
/* Enables the counter operation of channel 2 (TAUDnTS2) */
#define _TAUD_CHANNEL2_COUNTER_START                        (0x0004U) /* Enables the counter operation */
/* Enables the counter operation of channel 1 (TAUDnTS1) */
#define _TAUD_CHANNEL1_COUNTER_START                        (0x0002U) /* Enables the counter operation */
/* Enables the counter operation of channel 0 (TAUDnTS0) */
#define _TAUD_CHANNEL0_COUNTER_START                        (0x0001U) /* Enables the counter operation */

/*
    TAUDn Channel Stop Trigger Register (TAUDnTT)
*/
/* Stops the counter operation of channel 15 (TAUDnTT15) */
#define _TAUD_CHANNEL15_COUNTER_STOP                        (0x8000U) /* Stops the counter operation */
/* Stops the counter operation of channel 14 (TAUDnTT14) */
#define _TAUD_CHANNEL14_COUNTER_STOP                        (0x4000U) /* Stops the counter operation */
/* Stops the counter operation of channel 13 (TAUDnTT13) */
#define _TAUD_CHANNEL13_COUNTER_STOP                        (0x2000U) /* Stops the counter operation */
/* Stops the counter operation of channel 12 (TAUDnTT12) */
#define _TAUD_CHANNEL12_COUNTER_STOP                        (0x1000U) /* Stops the counter operation */
/* Stops the counter operation of channel 11 (TAUDnTT11) */
#define _TAUD_CHANNEL11_COUNTER_STOP                        (0x0800U) /* Stops the counter operation */
/* Stops the counter operation of channel 10 (TAUDnTT10) */
#define _TAUD_CHANNEL10_COUNTER_STOP                        (0x0400U) /* Stops the counter operation  */
/* Stops the counter operation of channel 9 (TAUDnTT9) */
#define _TAUD_CHANNEL9_COUNTER_STOP                         (0x0200U) /* Stops the counter operation */
/* Stops the counter operation of channel 8 (TAUDnTT8) */
#define _TAUD_CHANNEL8_COUNTER_STOP                         (0x0100U) /* Stops the counter operation */
/* Stops the counter operation of channel 7 (TAUDnTT7) */
#define _TAUD_CHANNEL7_COUNTER_STOP                         (0x0080U) /* Stops the counter operation */
/* Stops the counter operation of channel 6 (TAUDnTT6) */
#define _TAUD_CHANNEL6_COUNTER_STOP                         (0x0040U) /* Stops the counter operation */
/* Stops the counter operation of channel 5 (TAUDnTT5) */
#define _TAUD_CHANNEL5_COUNTER_STOP                         (0x0020U) /* Stops the counter operation */
/* Stops the counter operation of channel 4 (TAUDnTT4) */
#define _TAUD_CHANNEL4_COUNTER_STOP                         (0x0010U) /* Stops the counter operation */
/* Stops the counter operation of channel 3 (TAUDnTT3) */
#define _TAUD_CHANNEL3_COUNTER_STOP                         (0x0008U) /* Stops the counter operation */
/* Stops the counter operation of channel 2 (TAUDnTT2) */
#define _TAUD_CHANNEL2_COUNTER_STOP                         (0x0004U) /* Stops the counter operation */
/* Stops the counter operation of channel 1 (TAUDnTT1) */
#define _TAUD_CHANNEL1_COUNTER_STOP                         (0x0002U) /* Stops the counter operation */
/* Stops the counter operation of channel 0 (TAUDnTT0) */
#define _TAUD_CHANNEL0_COUNTER_STOP                         (0x0001U) /* Stops the counter operation */

/*
    TAUDn Channel Output Enable Register (TAUDnTOE)
*/
/* Enables/disables the independent channel output function (TAUDnTOE15) */
#define _TAUD_CHANNEL15_DISABLES_OUTPUT_MODE                (0x7FFFU) /* Disables independent channel output function */
#define _TAUD_CHANNEL15_ENABLES_OUTPUT_MODE                 (0x8000U) /* Enables independent channel output function */
/* Enables/disables the independent channel output function (TAUDnTOE14) */
#define _TAUD_CHANNEL14_DISABLES_OUTPUT_MODE                (0xBFFFU) /* Disables independent channel output function */
#define _TAUD_CHANNEL14_ENABLES_OUTPUT_MODE                 (0x4000U) /* Enables independent channel output function */
/* Enables/disables the independent channel output function (TAUDnTOE13) */
#define _TAUD_CHANNEL13_DISABLES_OUTPUT_MODE                (0xDFFFU) /* Disables independent channel output function */
#define _TAUD_CHANNEL13_ENABLES_OUTPUT_MODE                 (0x2000U) /* Enables independent channel output function */
/* Enables/disables the independent channel output function (TAUDnTOE12) */
#define _TAUD_CHANNEL12_DISABLES_OUTPUT_MODE                (0xEFFFU) /* Disables independent channel output function */
#define _TAUD_CHANNEL12_ENABLES_OUTPUT_MODE                 (0x1000U) /* Enables independent channel output function */
/* Enables/disables the independent channel output function (TAUDnTOE11) */
#define _TAUD_CHANNEL11_DISABLES_OUTPUT_MODE                (0xF7FFU) /* Disables independent channel output function */
#define _TAUD_CHANNEL11_ENABLES_OUTPUT_MODE                 (0x0800U) /* Enables independent channel output function */
/* Enables/disables the independent channel output function (TAUDnTOE10) */
#define _TAUD_CHANNEL10_DISABLES_OUTPUT_MODE                (0xFBFFU) /* Disables independent channel output function */
#define _TAUD_CHANNEL10_ENABLES_OUTPUT_MODE                 (0x0400U) /* Enables independent channel output function */
/* Enables/disables the independent channel output function (TAUDnTOE9) */
#define _TAUD_CHANNEL9_DISABLES_OUTPUT_MODE                 (0xFDFFU) /* Disables independent channel output function */
#define _TAUD_CHANNEL9_ENABLES_OUTPUT_MODE                  (0x0200U) /* Enables independent channel output function */
/* Enables/disables the independent channel output function (TAUDnTOE8) */
#define _TAUD_CHANNEL8_DISABLES_OUTPUT_MODE                 (0xFEFFU) /* Disables independent channel output function */
#define _TAUD_CHANNEL8_ENABLES_OUTPUT_MODE                  (0x0100U) /* Enables independent channel output function */
/* Enables/disables the independent channel output function (TAUDnTOE7) */
#define _TAUD_CHANNEL7_DISABLES_OUTPUT_MODE                 (0xFF7FU) /* Disables independent channel output function */
#define _TAUD_CHANNEL7_ENABLES_OUTPUT_MODE                  (0x0080U) /* Enables independent channel output function */
/* Enables/disables the independent channel output function (TAUDnTOE6) */
#define _TAUD_CHANNEL6_DISABLES_OUTPUT_MODE                 (0xFFBFU) /* Disables independent channel output function */
#define _TAUD_CHANNEL6_ENABLES_OUTPUT_MODE                  (0x0040U) /* Enables independent channel output function */
/* Enables/disables the independent channel output function (TAUDnTOE5) */
#define _TAUD_CHANNEL5_DISABLES_OUTPUT_MODE                 (0xFFDFU) /* Disables independent channel output function */
#define _TAUD_CHANNEL5_ENABLES_OUTPUT_MODE                  (0x0020U) /* Enables independent channel output function */
/* Enables/disables the independent channel output function (TAUDnTOE4) */
#define _TAUD_CHANNEL4_DISABLES_OUTPUT_MODE                 (0xFFEFU) /* Disables independent channel output function */
#define _TAUD_CHANNEL4_ENABLES_OUTPUT_MODE                  (0x0010U) /* Enables independent channel output function */
/* Enables/disables the independent channel output function (TAUDnTOE3) */
#define _TAUD_CHANNEL3_DISABLES_OUTPUT_MODE                 (0xFFF7U) /* Disables independent channel output function */
#define _TAUD_CHANNEL3_ENABLES_OUTPUT_MODE                  (0x0008U) /* Enables independent channel output function */
/* Enables/disables the independent channel output function (TAUDnTOE2) */
#define _TAUD_CHANNEL2_DISABLES_OUTPUT_MODE                 (0xFFFBU) /* Disables independent channel output function */
#define _TAUD_CHANNEL2_ENABLES_OUTPUT_MODE                  (0x0004U) /* Enables independent channel output function */
/* Enables/disables the independent channel output function (TAUDnTOE1) */
#define _TAUD_CHANNEL1_DISABLES_OUTPUT_MODE                 (0xFFFDU) /* Disables independent channel output function */
#define _TAUD_CHANNEL1_ENABLES_OUTPUT_MODE                  (0x0002U) /* Enables independent channel output function */
/* Enables/disables the independent channel output function (TAUDnTOE0) */
#define _TAUD_CHANNEL0_DISABLES_OUTPUT_MODE                 (0xFFFEU) /* Disables independent channel output function */
#define _TAUD_CHANNEL0_ENABLES_OUTPUT_MODE                  (0x0001U) /* Enables independent channel output function */

/*
    TAUDn Channel Output Register (TAUDnTO)
*/
/* Specifies and reads a TAUDnTTOUT15 level (TAUDnTO15) */
#define _TAUD_CHANNEL15_LOW_LEVEL                           (0x7FFFU) /* Low level */
#define _TAUD_CHANNEL15_HIGH_LEVEL                          (0x8000U) /* High level */
/* Specifies and reads a TAUDnTTOUT14 level (TAUDnTO14) */
#define _TAUD_CHANNEL14_LOW_LEVEL                           (0xBFFFU) /* Low level */
#define _TAUD_CHANNEL14_HIGH_LEVEL                          (0x4000U) /* High level */
/* Specifies and reads a TAUDnTTOUT13 level (TAUDnTO13) */
#define _TAUD_CHANNEL13_LOW_LEVEL                           (0xDFFFU) /* Low level */
#define _TAUD_CHANNEL13_HIGH_LEVEL                          (0x2000U) /* High level */
/* Specifies and reads a TAUDnTTOUT12 level (TAUDnTO12) */
#define _TAUD_CHANNEL12_LOW_LEVEL                           (0xEFFFU) /* Low level */
#define _TAUD_CHANNEL12_HIGH_LEVEL                          (0x1000U) /* High level */
/* Specifies and reads a TAUDnTTOUT11 level (TAUDnTO11) */
#define _TAUD_CHANNEL11_LOW_LEVEL                           (0xF7FFU) /* Low level */
#define _TAUD_CHANNEL11_HIGH_LEVEL                          (0x0800U) /* High level */
/* Specifies and reads a TAUDnTTOUT10 level (TAUDnTO10) */
#define _TAUD_CHANNEL10_LOW_LEVEL                           (0xFBFFU) /* Low level */
#define _TAUD_CHANNEL10_HIGH_LEVEL                          (0x0400U) /* High level */
/* Specifies and reads a TAUDnTTOUT9 level (TAUDnTO9) */
#define _TAUD_CHANNEL9_LOW_LEVEL                            (0xFDFFU) /* Low level */
#define _TAUD_CHANNEL9_HIGH_LEVEL                           (0x0200U) /* High level */
/* Specifies and reads a TAUDnTTOUT8 level (TAUDnTO8) */
#define _TAUD_CHANNEL8_LOW_LEVEL                            (0xFEFFU) /* Low level */
#define _TAUD_CHANNEL8_HIGH_LEVEL                           (0x0100U) /* High level */
/* Specifies and reads a TAUDnTTOUT7 level (TAUDnTO7) */
#define _TAUD_CHANNEL7_LOW_LEVEL                            (0xFF7FU) /* Low level */
#define _TAUD_CHANNEL7_HIGH_LEVEL                           (0x0080U) /* High level */
/* Specifies and reads a TAUDnTTOUT6 level (TAUDnTO6) */
#define _TAUD_CHANNEL6_LOW_LEVEL                            (0xFFBFU) /* Low level */
#define _TAUD_CHANNEL6_HIGH_LEVEL                           (0x0040U) /* High level */
/* Specifies and reads a TAUDnTTOUT5 level (TAUDnTO5) */
#define _TAUD_CHANNEL5_LOW_LEVEL                            (0xFFDFU) /* Low level */
#define _TAUD_CHANNEL5_HIGH_LEVEL                           (0x0020U) /* High level */
/* Specifies and reads a TAUDnTTOUT4 level (TAUDnTO4) */
#define _TAUD_CHANNEL4_LOW_LEVEL                            (0xFFEFU) /* Low level */
#define _TAUD_CHANNEL4_HIGH_LEVEL                           (0x0010U) /* High level */
/* Specifies and reads a TAUDnTTOUT3 level (TAUDnTO3) */
#define _TAUD_CHANNEL3_LOW_LEVEL                            (0xFFF7U) /* Low level */
#define _TAUD_CHANNEL3_HIGH_LEVEL                           (0x0008U) /* High level */
/* Specifies and reads a TAUDnTTOUT2 level (TAUDnTO2) */
#define _TAUD_CHANNEL2_LOW_LEVEL                            (0xFFFBU) /* Low level */
#define _TAUD_CHANNEL2_HIGH_LEVEL                           (0x0004U) /* High level */
/* Specifies and reads a TAUDnTTOUT1 level (TAUDnTO1) */
#define _TAUD_CHANNEL1_LOW_LEVEL                            (0xFFFDU) /* Low level */
#define _TAUD_CHANNEL1_HIGH_LEVEL                           (0x0002U) /* High level */
/* Specifies and reads a TAUDnTTOUT0 level (TAUDnTO0) */
#define _TAUD_CHANNEL0_LOW_LEVEL                            (0xFFFEU) /* Low level */
#define _TAUD_CHANNEL0_HIGH_LEVEL                           (0x0001U) /* High level */

/*
    TAUDn Channel Output Mode Register (TAUDnTOM)
*/
/* Specifies the channel output mode (TAUDnTOM15) */
#define _TAUD_CHANNEL15_INDEPENDENT_OUTPUT_MODE             (0x7FFFU) /* Independent channel output mode */
#define _TAUD_CHANNEL15_SYNCHRONOUS_OUTPUT_MODE             (0x8000U) /* Synchronous channel output mode */
/* Specifies the channel output mode (TAUDnTOM14) */
#define _TAUD_CHANNEL14_INDEPENDENT_OUTPUT_MODE             (0xBFFFU) /* Independent channel output mode */
#define _TAUD_CHANNEL14_SYNCHRONOUS_OUTPUT_MODE             (0x4000U) /* Synchronous channel output mode */
/* Specifies the channel output mode (TAUDnTOM13) */
#define _TAUD_CHANNEL13_INDEPENDENT_OUTPUT_MODE             (0xDFFFU) /* Independent channel output mode */
#define _TAUD_CHANNEL13_SYNCHRONOUS_OUTPUT_MODE             (0x2000U) /* Synchronous channel output mode */
/* Specifies the channel output mode (TAUDnTOM12) */
#define _TAUD_CHANNEL12_INDEPENDENT_OUTPUT_MODE             (0xEFFFU) /* Independent channel output mode */
#define _TAUD_CHANNEL12_SYNCHRONOUS_OUTPUT_MODE             (0x1000U) /* Synchronous channel output mode */
/* Specifies the channel output mode (TAUDnTOM11) */
#define _TAUD_CHANNEL11_INDEPENDENT_OUTPUT_MODE             (0xF7FFU) /* Independent channel output mode */
#define _TAUD_CHANNEL11_SYNCHRONOUS_OUTPUT_MODE             (0x0800U) /* Synchronous channel output mode */
/* Specifies the channel output mode (TAUDnTOM10) */
#define _TAUD_CHANNEL10_INDEPENDENT_OUTPUT_MODE             (0xFBFFU) /* Independent channel output mode */
#define _TAUD_CHANNEL10_SYNCHRONOUS_OUTPUT_MODE             (0x0400U) /* Synchronous channel output mode */
/* Specifies the channel output mode (TAUDnTOM9) */
#define _TAUD_CHANNEL9_INDEPENDENT_OUTPUT_MODE              (0xFDFFU) /* Independent channel output mode */
#define _TAUD_CHANNEL9_SYNCHRONOUS_OUTPUT_MODE              (0x0200U) /* Synchronous channel output mode */
/* Specifies the channel output mode (TAUDnTOM8) */
#define _TAUD_CHANNEL8_INDEPENDENT_OUTPUT_MODE              (0xFEFFU) /* Independent channel output mode */
#define _TAUD_CHANNEL8_SYNCHRONOUS_OUTPUT_MODE              (0x0100U) /* Synchronous channel output mode */
/* Specifies the channel output mode (TAUDnTOM7) */
#define _TAUD_CHANNEL7_INDEPENDENT_OUTPUT_MODE              (0xFF7FU) /* Independent channel output mode */
#define _TAUD_CHANNEL7_SYNCHRONOUS_OUTPUT_MODE              (0x0080U) /* Synchronous channel output mode */
/* Specifies the channel output mode (TAUDnTOM6) */
#define _TAUD_CHANNEL6_INDEPENDENT_OUTPUT_MODE              (0xFFBFU) /* Independent channel output mode */
#define _TAUD_CHANNEL6_SYNCHRONOUS_OUTPUT_MODE              (0x0040U) /* Synchronous channel output mode */
/* Specifies the channel output mode (TAUDnTOM5) */
#define _TAUD_CHANNEL5_INDEPENDENT_OUTPUT_MODE              (0xFFDFU) /* Independent channel output mode */
#define _TAUD_CHANNEL5_SYNCHRONOUS_OUTPUT_MODE              (0x0020U) /* Synchronous channel output mode */
/* Specifies the channel output mode (TAUDnTOM4) */
#define _TAUD_CHANNEL4_INDEPENDENT_OUTPUT_MODE              (0xFFEFU) /* Independent channel output mode */
#define _TAUD_CHANNEL4_SYNCHRONOUS_OUTPUT_MODE              (0x0010U) /* Synchronous channel output mode */
/* Specifies the channel output mode (TAUDnTOM3) */
#define _TAUD_CHANNEL3_INDEPENDENT_OUTPUT_MODE              (0xFFF7U) /* Independent channel output mode */
#define _TAUD_CHANNEL3_SYNCHRONOUS_OUTPUT_MODE              (0x0008U) /* Synchronous channel output mode */
/* Specifies the channel output mode (TAUDnTOM2) */
#define _TAUD_CHANNEL2_INDEPENDENT_OUTPUT_MODE              (0xFFFBU) /* Independent channel output mode */
#define _TAUD_CHANNEL2_SYNCHRONOUS_OUTPUT_MODE              (0x0004U) /* Synchronous channel output mode */
/* Specifies the channel output mode (TAUDnTOM1) */
#define _TAUD_CHANNEL1_INDEPENDENT_OUTPUT_MODE              (0xFFFDU) /* Independent channel output mode */
#define _TAUD_CHANNEL1_SYNCHRONOUS_OUTPUT_MODE              (0x0002U) /* Synchronous channel output mode */
/* Specifies the channel output mode (TAUDnTOM0) */
#define _TAUD_CHANNEL0_INDEPENDENT_OUTPUT_MODE              (0xFFFEU) /* Independent channel output mode */
#define _TAUD_CHANNEL0_SYNCHRONOUS_OUTPUT_MODE              (0x0001U) /* Synchronous channel output mode */

/*
    TAUDn Channel Output Configuration Register (TAUDnTOC)
*/
/* Specifies an output mode (TAUDnTOC15) */
#define _TAUD_CHANNEL15_OPERATION_MODE1                     (0x7FFFU) /* Operation mode 1 */
#define _TAUD_CHANNEL15_OPERATION_MODE2                     (0x8000U) /* Operation mode 2 */
/* Specifies an output mode (TAUDnTOC14) */
#define _TAUD_CHANNEL14_OPERATION_MODE1                     (0xBFFFU) /* Operation mode 1 */
#define _TAUD_CHANNEL14_OPERATION_MODE2                     (0x4000U) /* Operation mode 2 */
/* Specifies an output mode (TAUDnTOC13) */
#define _TAUD_CHANNEL13_OPERATION_MODE1                     (0xDFFFU) /* Operation mode 1 */
#define _TAUD_CHANNEL13_OPERATION_MODE2                     (0x2000U) /* Operation mode 2 */
/* Specifies an output mode (TAUDnTOC12) */
#define _TAUD_CHANNEL12_OPERATION_MODE1                     (0xEFFFU) /* Operation mode 1 */
#define _TAUD_CHANNEL12_OPERATION_MODE2                     (0x1000U) /* Operation mode 2 */
/* Specifies an output mode (TAUDnTOC11) */
#define _TAUD_CHANNEL11_OPERATION_MODE1                     (0xF7FFU) /* Operation mode 1 */
#define _TAUD_CHANNEL11_OPERATION_MODE2                     (0x0800U) /* Operation mode 2 */
/* Specifies an output mode (TAUDnTOC10) */
#define _TAUD_CHANNEL10_OPERATION_MODE1                     (0xFBFFU) /* Operation mode 1 */
#define _TAUD_CHANNEL10_OPERATION_MODE2                     (0x0400U) /* Operation mode 2 */
/* Specifies an output mode (TAUDnTOC9) */
#define _TAUD_CHANNEL9_OPERATION_MODE1                      (0xFDFFU) /* Operation mode 1 */
#define _TAUD_CHANNEL9_OPERATION_MODE2                      (0x0200U) /* Operation mode 2 */
/* Specifies an output mode (TAUDnTOC8) */
#define _TAUD_CHANNEL8_OPERATION_MODE1                      (0xFEFFU) /* Operation mode 1 */
#define _TAUD_CHANNEL8_OPERATION_MODE2                      (0x0100U) /* Operation mode 2 */
/* Specifies an output mode (TAUDnTOC7) */
#define _TAUD_CHANNEL7_OPERATION_MODE1                      (0xFF7FU) /* Operation mode 1 */
#define _TAUD_CHANNEL7_OPERATION_MODE2                      (0x0080U) /* Operation mode 2 */
/* Specifies an output mode (TAUDnTOC6) */
#define _TAUD_CHANNEL6_OPERATION_MODE1                      (0xFFBFU) /* Operation mode 1 */
#define _TAUD_CHANNEL6_OPERATION_MODE2                      (0x0040U) /* Operation mode 2 */
/* Specifies an output mode (TAUDnTOC5) */
#define _TAUD_CHANNEL5_OPERATION_MODE1                      (0xFFDFU) /* Operation mode 1 */
#define _TAUD_CHANNEL5_OPERATION_MODE2                      (0x0020U) /* Operation mode 2 */
/* Specifies an output mode (TAUDnTOC4) */
#define _TAUD_CHANNEL4_OPERATION_MODE1                      (0xFFEFU) /* Operation mode 1 */
#define _TAUD_CHANNEL4_OPERATION_MODE2                      (0x0010U) /* Operation mode 2 */
/* Specifies an output mode (TAUDnTOC3) */
#define _TAUD_CHANNEL3_OPERATION_MODE1                      (0xFFF7U) /* Operation mode 1 */
#define _TAUD_CHANNEL3_OPERATION_MODE2                      (0x0008U) /* Operation mode 2 */
/* Specifies an output mode (TAUDnTOC2) */
#define _TAUD_CHANNEL2_OPERATION_MODE1                      (0xFFFBU) /* Operation mode 1 */
#define _TAUD_CHANNEL2_OPERATION_MODE2                      (0x0004U) /* Operation mode 2 */
/* Specifies an output mode (TAUDnTOC1) */
#define _TAUD_CHANNEL1_OPERATION_MODE1                      (0xFFFDU) /* Operation mode 1 */
#define _TAUD_CHANNEL1_OPERATION_MODE2                      (0x0002U) /* Operation mode 2 */
/* Specifies an output mode (TAUDnTOC0) */
#define _TAUD_CHANNEL0_OPERATION_MODE1                      (0xFFFEU) /* Operation mode 1 */
#define _TAUD_CHANNEL0_OPERATION_MODE2                      (0x0001U) /* Operation mode 2 */

/*
    TAUDn Channel Output Active Level Register (TAUDnTOL)
*/
/* Specifies the output logic of channel 15 output bit (TAUDnTOL15) */
#define _TAUD_CHANNEL15_POSITIVE_LOGIC                      (0x7FFFU) /* Positive logic */
#define _TAUD_CHANNEL15_NEGATIVE_LOGIC                      (0x8000U) /* Negative logic */
/* Specifies the output logic of channel 14 output bit (TAUDnTOL14) */
#define _TAUD_CHANNEL14_POSITIVE_LOGIC                      (0xBFFFU) /* Positive logic */
#define _TAUD_CHANNEL14_NEGATIVE_LOGIC                      (0x4000U) /* Negative logic */
/* Specifies the output logic of channel 13 output bit (TAUDnTOL13) */
#define _TAUD_CHANNEL13_POSITIVE_LOGIC                      (0xDFFFU) /* Positive logic */
#define _TAUD_CHANNEL13_NEGATIVE_LOGIC                      (0x2000U) /* Negative logic */
/* Specifies the output logic of channel 12 output bit (TAUDnTOL12) */
#define _TAUD_CHANNEL12_POSITIVE_LOGIC                      (0xEFFFU) /* Positive logic */
#define _TAUD_CHANNEL12_NEGATIVE_LOGIC                      (0x1000U) /* Negative logic */
/* Specifies the output logic of channel 11 output bit (TAUDnTOL11) */
#define _TAUD_CHANNEL11_POSITIVE_LOGIC                      (0xF7FFU) /* Positive logic */
#define _TAUD_CHANNEL11_NEGATIVE_LOGIC                      (0x0800U) /* Negative logic */
/* Specifies the output logic of channel 10 output bit (TAUDnTOL10) */
#define _TAUD_CHANNEL10_POSITIVE_LOGIC                      (0xFBFFU) /* Positive logic */
#define _TAUD_CHANNEL10_NEGATIVE_LOGIC                      (0x0400U) /* Negative logic */
/* Specifies the output logic of channel 9 output bit (TAUDnTOL9) */
#define _TAUD_CHANNEL9_POSITIVE_LOGIC                       (0xFDFFU) /* Positive logic */
#define _TAUD_CHANNEL9_NEGATIVE_LOGIC                       (0x0200U) /* Negative logic */
/* Specifies the output logic of channel 8 output bit (TAUDnTOL8) */
#define _TAUD_CHANNEL8_POSITIVE_LOGIC                       (0xFEFFU) /* Positive logic */
#define _TAUD_CHANNEL8_NEGATIVE_LOGIC                       (0x0100U) /* Negative logic */
/* Specifies the output logic of channel 7 output bit (TAUDnTOL7) */
#define _TAUD_CHANNEL7_POSITIVE_LOGIC                       (0xFF7FU) /* Positive logic */
#define _TAUD_CHANNEL7_NEGATIVE_LOGIC                       (0x0080U) /* Negative logic */
/* Specifies the output logic of channel 6 output bit (TAUDnTOL6) */
#define _TAUD_CHANNEL6_POSITIVE_LOGIC                       (0xFFBFU) /* Positive logic */
#define _TAUD_CHANNEL6_NEGATIVE_LOGIC                       (0x0040U) /* Negative logic */
/* Specifies the output logic of channel 5 output bit (TAUDnTOL5) */
#define _TAUD_CHANNEL5_POSITIVE_LOGIC                       (0xFFDFU) /* Positive logic */
#define _TAUD_CHANNEL5_NEGATIVE_LOGIC                       (0x0020U) /* Negative logic */
/* Specifies the output logic of channel 4 output bit (TAUDnTOL4) */
#define _TAUD_CHANNEL4_POSITIVE_LOGIC                       (0xFFEFU) /* Positive logic */
#define _TAUD_CHANNEL4_NEGATIVE_LOGIC                       (0x0010U) /* Negative logic */
/* Specifies the output logic of channel 3 output bit (TAUDnTOL3) */
#define _TAUD_CHANNEL3_POSITIVE_LOGIC                       (0xFFF7U) /* Positive logic */
#define _TAUD_CHANNEL3_NEGATIVE_LOGIC                       (0x0008U) /* Negative logic */
/* Specifies the output logic of channel 2 output bit (TAUDnTOL2) */
#define _TAUD_CHANNEL2_POSITIVE_LOGIC                       (0xFFFBU) /* Positive logic */
#define _TAUD_CHANNEL2_NEGATIVE_LOGIC                       (0x0004U) /* Negative logic */
/* Specifies the output logic of channel 1 output bit (TAUDnTOL1) */
#define _TAUD_CHANNEL1_POSITIVE_LOGIC                       (0xFFFDU) /* Positive logic */
#define _TAUD_CHANNEL1_NEGATIVE_LOGIC                       (0x0002U) /* Negative logic */
/* Specifies the output logic of channel 0 output bit (TAUDnTOL0) */
#define _TAUD_CHANNEL0_POSITIVE_LOGIC                       (0xFFFEU) /* Positive logic */
#define _TAUD_CHANNEL0_NEGATIVE_LOGIC                       (0x0001U) /* Negative logic */

/*
    TAUDn Channel Dead Time Output Enable Register (TAUDnTDE)
*/
/* Enables/disables the dead time control operation of channel 15 (TAUDnTDE15) */
#define _TAUD_CHANNEL15_DISABLE_DEAD_TIME_OPERATE           (0x7FFFU) /* Disables dead time operation */
#define _TAUD_CHANNEL15_ENABLE_DEAD_TIME_OPERATE            (0x8000U) /* Enables dead time operation */
/* Enables/disables the dead time control operation of channel 14 (TAUDnTDE14) */
#define _TAUD_CHANNEL14_DISABLE_DEAD_TIME_OPERATE           (0xBFFFU) /* Disables dead time operation */
#define _TAUD_CHANNEL14_ENABLE_DEAD_TIME_OPERATE            (0x4000U) /* Enables dead time operation */
/* Enables/disables the dead time control operation of channel 13 (TAUDnTDE13) */
#define _TAUD_CHANNEL13_DISABLE_DEAD_TIME_OPERATE           (0xDFFFU) /* Disables dead time operation */
#define _TAUD_CHANNEL13_ENABLE_DEAD_TIME_OPERATE            (0x2000U) /* Enables dead time operation */
/* Enables/disables the dead time control operation of channel 12 (TAUDnTDE12) */
#define _TAUD_CHANNEL12_DISABLE_DEAD_TIME_OPERATE           (0xEFFFU) /* Disables dead time operation */
#define _TAUD_CHANNEL12_ENABLE_DEAD_TIME_OPERATE            (0x1000U) /* Enables dead time operation */
/* Enables/disables the dead time control operation of channel 11 (TAUDnTDE11) */
#define _TAUD_CHANNEL11_DISABLE_DEAD_TIME_OPERATE           (0xF7FFU) /* Disables dead time operation */
#define _TAUD_CHANNEL11_ENABLE_DEAD_TIME_OPERATE            (0x0800U) /* Enables dead time operation */
/* Enables/disables the dead time control operation of channel 10 (TAUDnTDE10) */
#define _TAUD_CHANNEL10_DISABLE_DEAD_TIME_OPERATE           (0xFBFFU) /* Disables dead time operation */
#define _TAUD_CHANNEL10_ENABLE_DEAD_TIME_OPERATE            (0x0400U) /* Enables dead time operation */
/* Enables/disables the dead time control operation of channel 9 (TAUDnTDE9) */
#define _TAUD_CHANNEL9_DISABLE_DEAD_TIME_OPERATE            (0xFDFFU) /* Disables dead time operation */
#define _TAUD_CHANNEL9_ENABLE_DEAD_TIME_OPERATE             (0x0200U) /* Enables dead time operation */
/* Enables/disables the dead time control operation of channel 8 (TAUDnTDE8) */
#define _TAUD_CHANNEL8_DISABLE_DEAD_TIME_OPERATE            (0xFEFFU) /* Disables dead time operation */
#define _TAUD_CHANNEL8_ENABLE_DEAD_TIME_OPERATE             (0x0100U) /* Enables dead time operation */
/* Enables/disables the dead time control operation of channel 7 (TAUDnTDE7) */
#define _TAUD_CHANNEL7_DISABLE_DEAD_TIME_OPERATE            (0xFF7FU) /* Disables dead time operation */
#define _TAUD_CHANNEL7_ENABLE_DEAD_TIME_OPERATE             (0x0080U) /* Enables dead time operation */
/* Enables/disables the dead time control operation of channel 6 (TAUDnTDE6) */
#define _TAUD_CHANNEL6_DISABLE_DEAD_TIME_OPERATE            (0xFFBFU) /* Disables dead time operation */
#define _TAUD_CHANNEL6_ENABLE_DEAD_TIME_OPERATE             (0x0040U) /* Enables dead time operation */
/* Enables/disables the dead time control operation of channel 5 (TAUDnTDE5) */
#define _TAUD_CHANNEL5_DISABLE_DEAD_TIME_OPERATE            (0xFFDFU) /* Disables dead time operation */
#define _TAUD_CHANNEL5_ENABLE_DEAD_TIME_OPERATE             (0x0020U) /* Enables dead time operation */
/* Enables/disables the dead time control operation of channel 4 (TAUDnTDE4) */
#define _TAUD_CHANNEL4_DISABLE_DEAD_TIME_OPERATE            (0xFFEFU) /* Disables dead time operation */
#define _TAUD_CHANNEL4_ENABLE_DEAD_TIME_OPERATE             (0x0010U) /* Enables dead time operation */
/* Enables/disables the dead time control operation of channel 3 (TAUDnTDE3) */
#define _TAUD_CHANNEL3_DISABLE_DEAD_TIME_OPERATE            (0xFFF7U) /* Disables dead time operation */
#define _TAUD_CHANNEL3_ENABLE_DEAD_TIME_OPERATE             (0x0008U) /* Enables dead time operation */
/* Enables/disables the dead time control operation of channel 2 (TAUDnTDE2) */
#define _TAUD_CHANNEL2_DISABLE_DEAD_TIME_OPERATE            (0xFFFBU) /* Disables dead time operation */
#define _TAUD_CHANNEL2_ENABLE_DEAD_TIME_OPERATE             (0x0004U) /* Enables dead time operation */
/* Enables/disables the dead time control operation of channel 1 (TAUDnTDE1) */
#define _TAUD_CHANNEL1_DISABLE_DEAD_TIME_OPERATE            (0xFFFDU) /* Disables dead time operation */
#define _TAUD_CHANNEL1_ENABLE_DEAD_TIME_OPERATE             (0x0002U) /* Enables dead time operation */
/* Enables/disables the dead time control operation of channel 0 (TAUDnTDE0) */
#define _TAUD_CHANNEL0_DISABLE_DEAD_TIME_OPERATE            (0xFFFEU) /* Disables dead time operation */
#define _TAUD_CHANNEL0_ENABLE_DEAD_TIME_OPERATE             (0x0001U) /* Enables dead time operation */

/*
    TAUDn Channel Dead Time Output Mode Register (TAUDnTDM)
*/
/* Specifies the timing to add dead time during dead time output (TAUDnTDM15) */
#define _TAUD_CHANNEL15_DETECTING_DUTY_CYCLE                (0x7FFFU) /* The duty cycle of an upper even channel */
#define _TAUD_CHANNEL15_DETECTING_INPUT_EDGE                (0x8000U) /* The TIN input edge of a lower odd channel */
/* Specifies the timing to add dead time during dead time output (TAUDnTDM14) */
#define _TAUD_CHANNEL14_DETECTING_DUTY_CYCLE                (0xBFFFU) /* The duty cycle of an upper even channel */
#define _TAUD_CHANNEL14_DETECTING_INPUT_EDGE                (0x4000U) /* The TIN input edge of a lower odd channel */
/* Specifies the timing to add dead time during dead time output (TAUDnTDM13) */
#define _TAUD_CHANNEL13_DETECTING_DUTY_CYCLE                (0xDFFFU) /* The duty cycle of an upper even channel */
#define _TAUD_CHANNEL13_DETECTING_INPUT_EDGE                (0x2000U) /* The TIN input edge of a lower odd channel */
/* Specifies the timing to add dead time during dead time output (TAUDnTDM12) */
#define _TAUD_CHANNEL12_DETECTING_DUTY_CYCLE                (0xEFFFU) /* The duty cycle of an upper even channel */
#define _TAUD_CHANNEL12_DETECTING_INPUT_EDGE                (0x1000U) /* The TIN input edge of a lower odd channel */
/* Specifies the timing to add dead time during dead time output (TAUDnTDM11) */
#define _TAUD_CHANNEL11_DETECTING_DUTY_CYCLE                (0xF7FFU) /* The duty cycle of an upper even channel */
#define _TAUD_CHANNEL11_DETECTING_INPUT_EDGE                (0x0800U) /* The TIN input edge of a lower odd channel */
/* Specifies the timing to add dead time during dead time output (TAUDnTDM10) */
#define _TAUD_CHANNEL10_DETECTING_DUTY_CYCLE                (0xFBFFU) /* The duty cycle of an upper even channel */
#define _TAUD_CHANNEL10_DETECTING_INPUT_EDGE                (0x0400U) /* The TIN input edge of a lower odd channel */
/* Specifies the timing to add dead time during dead time output (TAUDnTDM9) */
#define _TAUD_CHANNEL9_DETECTING_DUTY_CYCLE                 (0xFDFFU) /* The duty cycle of an upper even channel */
#define _TAUD_CHANNEL9_DETECTING_INPUT_EDGE                 (0x0200U) /* The TIN input edge of a lower odd channel */
/* Specifies the timing to add dead time during dead time output (TAUDnTDM8) */
#define _TAUD_CHANNEL8_DETECTING_DUTY_CYCLE                 (0xFEFFU) /* The duty cycle of an upper even channel */
#define _TAUD_CHANNEL8_DETECTING_INPUT_EDGE                 (0x0100U) /* The TIN input edge of a lower odd channel */
/* Specifies the timing to add dead time during dead time output (TAUDnTDM7) */
#define _TAUD_CHANNEL7_DETECTING_DUTY_CYCLE                 (0xFF7FU) /* The duty cycle of an upper even channel */
#define _TAUD_CHANNEL7_DETECTING_INPUT_EDGE                 (0x0080U) /* The TIN input edge of a lower odd channel */
/* Specifies the timing to add dead time during dead time output (TAUDnTDM6) */
#define _TAUD_CHANNEL6_DETECTING_DUTY_CYCLE                 (0xFFBFU) /* The duty cycle of an upper even channel */
#define _TAUD_CHANNEL6_DETECTING_INPUT_EDGE                 (0x0040U) /* The TIN input edge of a lower odd channel */
/* Specifies the timing to add dead time during dead time output (TAUDnTDM5) */
#define _TAUD_CHANNEL5_DETECTING_DUTY_CYCLE                 (0xFFDFU) /* The duty cycle of an upper even channel */
#define _TAUD_CHANNEL5_DETECTING_INPUT_EDGE                 (0x0020U) /* The TIN input edge of a lower odd channel */
/* Specifies the timing to add dead time during dead time output (TAUDnTDM4) */
#define _TAUD_CHANNEL4_DETECTING_DUTY_CYCLE                 (0xFFEFU) /* The duty cycle of an upper even channel */
#define _TAUD_CHANNEL4_DETECTING_INPUT_EDGE                 (0x0010U) /* The TIN input edge of a lower odd channel */
/* Specifies the timing to add dead time during dead time output (TAUDnTDM3) */
#define _TAUD_CHANNEL3_DETECTING_DUTY_CYCLE                 (0xFFF7U) /* The duty cycle of an upper even channel */
#define _TAUD_CHANNEL3_DETECTING_INPUT_EDGE                 (0x0008U) /* The TIN input edge of a lower odd channel */
/* Specifies the timing to add dead time during dead time output (TAUDnTDM2) */
#define _TAUD_CHANNEL2_DETECTING_DUTY_CYCLE                 (0xFFFBU) /* The duty cycle of an upper even channel */
#define _TAUD_CHANNEL2_EDETECTING_INPUT_EDGE                (0x0004U) /* The TIN input edge of a lower odd channel */
/* Specifies the timing to add dead time during dead time output (TAUDnTDM1) */
#define _TAUD_CHANNEL1_DETECTING_DUTY_CYCLE                 (0xFFFDU) /* The duty cycle of an upper even channel */
#define _TAUD_CHANNEL1_DETECTING_INPUT_EDGE                 (0x0002U) /* The TIN input edge of a lower odd channel */
/* Specifies the timing to add dead time during dead time output (TAUDnTDM0) */
#define _TAUD_CHANNEL0_DETECTING_DUTY_CYCLE                 (0xFFFEU) /* The duty cycle of an upper even channel */
#define _TAUD_CHANNEL0_DETECTING_INPUT_EDGE                 (0x0001U) /* The TIN input edge of a lower odd channel */

/*
    TAUDn Channel Dead Time Output Level Register (TAUDnTDL)
*/
/* Selects a phase in which dead time is added (TAUDnTDL15) */
#define _TAUD_CHANNEL15_NORMAL_PHASE                        (0x7FFFU) /* Normal phase */
#define _TAUD_CHANNEL15_REVERSE_PHASE                       (0x8000U) /* Reverse phase */
/* Selects a phase in which dead time is added (TAUDnTDL14) */
#define _TAUD_CHANNEL14_NORMAL_PHASE                        (0xBFFFU) /* Normal phase */
#define _TAUD_CHANNEL14_REVERSE_PHASE                       (0x4000U) /* Reverse phase */
/* Selects a phase in which dead time is added (TAUDnTDL13) */
#define _TAUD_CHANNEL13_NORMAL_PHASE                        (0xDFFFU) /* Normal phase */
#define _TAUD_CHANNEL13_REVERSE_PHASE                       (0x2000U) /* Reverse phase */
/* Selects a phase in which dead time is added (TAUDnTDL12) */
#define _TAUD_CHANNEL12_NORMAL_PHASE                        (0xEFFFU) /* Normal phase */
#define _TAUD_CHANNEL12_REVERSE_PHASE                       (0x1000U) /* Reverse phase */
/* Selects a phase in which dead time is added (TAUDnTDL11) */
#define _TAUD_CHANNEL11_NORMAL_PHASE                        (0xF7FFU) /* Normal phase */
#define _TAUD_CHANNEL11_REVERSE_PHASE                       (0x0800U) /* Reverse phase */
/* Selects a phase in which dead time is added (TAUDnTDL10) */
#define _TAUD_CHANNEL10_NORMAL_PHASE                        (0xFBFFU) /* Normal phase */
#define _TAUD_CHANNEL10_REVERSE_PHASE                       (0x0400U) /* Reverse phase */
/* Selects a phase in which dead time is added (TAUDnTDL9) */
#define _TAUD_CHANNEL9_NORMAL_PHASE                         (0xFDFFU) /* Normal phase */
#define _TAUD_CHANNEL9_REVERSE_PHASE                        (0x0200U) /* Reverse phase */
/* Selects a phase in which dead time is added (TAUDnTDL8) */
#define _TAUD_CHANNEL8_NORMAL_PHASE                         (0xFEFFU) /* Normal phase */
#define _TAUD_CHANNEL8_REVERSE_PHASE                        (0x0100U) /* Reverse phase */
/* Selects a phase in which dead time is added (TAUDnTDL7) */
#define _TAUD_CHANNEL7_NORMAL_PHASE                         (0xFF7FU) /* Normal phase */
#define _TAUD_CHANNEL7_REVERSE_PHASE                        (0x0080U) /* Reverse phase */
/* Selects a phase in which dead time is added (TAUDnTDL6) */
#define _TAUD_CHANNEL6_NORMAL_PHASE                         (0xFFBFU) /* Normal phase */
#define _TAUD_CHANNEL6_REVERSE_PHASE                        (0x0040U) /* Reverse phase */
/* Selects a phase in which dead time is added (TAUDnTDL5) */
#define _TAUD_CHANNEL5_NORMAL_PHASE                         (0xFFDFU) /* Normal phase */
#define _TAUD_CHANNEL5_REVERSE_PHASE                        (0x0020U) /* Reverse phase */
/* Selects a phase in which dead time is added (TAUDnTDL4) */
#define _TAUD_CHANNEL4_NORMAL_PHASE                         (0xFFEFU) /* Normal phase */
#define _TAUD_CHANNEL4_REVERSE_PHASE                        (0x0010U) /* Reverse phase */
/* Selects a phase in which dead time is added (TAUDnTDL3) */
#define _TAUD_CHANNEL3_NORMAL_PHASE                         (0xFFF7U) /* Normal phase */
#define _TAUD_CHANNEL3_REVERSE_PHASE                        (0x0008U) /* Reverse phase */
/* Selects a phase in which dead time is added (TAUDnTDL2) */
#define _TAUD_CHANNEL2_NORMAL_PHASE                         (0xFFFBU) /* Normal phase */
#define _TAUD_CHANNEL2_REVERSE_PHASE                        (0x0004U) /* Reverse phase */
/* Selects a phase in which dead time is added (TAUDnTDL1) */
#define _TAUD_CHANNEL1_NORMAL_PHASE                         (0xFFFDU) /* Normal phase */
#define _TAUD_CHANNEL1_REVERSE_PHASE                        (0x0002U) /* Reverse phase */
/* Selects a phase in which dead time is added (TAUDnTDL0) */
#define _TAUD_CHANNEL0_NORMAL_PHASE                         (0xFFFEU) /* Normal phase */
#define _TAUD_CHANNEL0_REVERSE_PHASE                        (0x0001U) /* Reverse phase */

/*
    TAUDn Channel Real-time Output Enable Register (TAUDnTRE)
*/
/* Enables or disables real-time output of channel 15 (TAUDnTRE15) */
#define _TAUD_CHANNEL15_REAL_TIME_OUTPUT_DISABLES           (0x7FFFU) /* Disables real-time output */
#define _TAUD_CHANNEL15_REAL_TIME_OUTPUT_ENABLES            (0x8000U) /* Enables real-time output */
/* Enables or disables real-time output of channel 14 (TAUDnTRE14) */
#define _TAUD_CHANNEL14_REAL_TIME_OUTPUT_DISABLES           (0xBFFFU) /* Disables real-time output */
#define _TAUD_CHANNEL14_REAL_TIME_OUTPUT_ENABLES            (0x4000U) /* Enables real-time output */
/* Enables or disables real-time output of channel 13 (TAUDnTRE13) */
#define _TAUD_CHANNEL13_REAL_TIME_OUTPUT_DISABLES           (0xDFFFU) /* Disables real-time output */
#define _TAUD_CHANNEL13_REAL_TIME_OUTPUT_ENABLES            (0x2000U) /* Enables real-time output */
/* Enables or disables real-time output of channel 12 (TAUDnTRE12) */
#define _TAUD_CHANNEL12_REAL_TIME_OUTPUT_DISABLES           (0xEFFFU) /* Disables real-time output */
#define _TAUD_CHANNEL12_REAL_TIME_OUTPUT_ENABLES            (0x1000U) /* Enables real-time output */
/* Enables or disables real-time output of channel 11 (TAUDnTRE11) */
#define _TAUD_CHANNEL11_REAL_TIME_OUTPUT_DISABLES           (0xF7FFU) /* Disables real-time output */
#define _TAUD_CHANNEL11_REAL_TIME_OUTPUT_ENABLES            (0x0800U) /* Enables real-time output */
/* Enables or disables real-time output of channel 10 (TAUDnTRE10) */
#define _TAUD_CHANNEL10_REAL_TIME_OUTPUT_DISABLES           (0xFBFFU) /* Disables real-time output */
#define _TAUD_CHANNEL10_REAL_TIME_OUTPUT_ENABLES            (0x0400U) /* Enables real-time output */
/* Enables or disables real-time output of channel 9 (TAUDnTRE9) */
#define _TAUD_CHANNEL9_REAL_TIME_OUTPUT_DISABLES            (0xFDFFU) /* Disables real-time output */
#define _TAUD_CHANNEL9_REAL_TIME_OUTPUT_ENABLES             (0x0200U) /* Enables real-time output */
/* Enables or disables real-time output of channel 8 (TAUDnTRE8) */
#define _TAUD_CHANNEL8_REAL_TIME_OUTPUT_DISABLES            (0xFEFFU) /* Disables real-time output */
#define _TAUD_CHANNEL8_REAL_TIME_OUTPUT_ENABLES             (0x0100U) /* Enables real-time output */
/* Enables or disables real-time output of channel 7 (TAUDnTRE7) */
#define _TAUD_CHANNEL7_REAL_TIME_OUTPUT_DISABLES            (0xFF7FU) /* Disables real-time output */
#define _TAUD_CHANNEL7_REAL_TIME_OUTPUT_ENABLES             (0x0080U) /* Enables real-time output */
/* Enables or disables real-time output of channel 6 (TAUDnTRE6) */
#define _TAUD_CHANNEL6_REAL_TIME_OUTPUT_DISABLES            (0xFFBFU) /* Disables real-time output */
#define _TAUD_CHANNEL6_REAL_TIME_OUTPUT_ENABLES             (0x0040U) /* Enables real-time output */
/* Enables or disables real-time output of channel 5 (TAUDnTRE5) */
#define _TAUD_CHANNEL5_REAL_TIME_OUTPUT_DISABLES            (0xFFDFU) /* Disables real-time output */
#define _TAUD_CHANNEL5_REAL_TIME_OUTPUT_ENABLES             (0x0020U) /* Enables real-time output */
/* Enables or disables real-time output of channel 4 (TAUDnTRE4) */
#define _TAUD_CHANNEL4_REAL_TIME_OUTPUT_DISABLES            (0xFFEFU) /* Disables real-time output */
#define _TAUD_CHANNEL4_REAL_TIME_OUTPUT_ENABLES             (0x0010U) /* Enables real-time output */
/* Enables or disables real-time output of channel 3 (TAUDnTRE3) */
#define _TAUD_CHANNEL3_REAL_TIME_OUTPUT_DISABLES            (0xFFF7U) /* Disables real-time output */
#define _TAUD_CHANNEL3_REAL_TIME_OUTPUT_ENABLES             (0x0008U) /* Enables real-time output */
/* Enables or disables real-time output of channel 2 (TAUDnTRE2) */
#define _TAUD_CHANNEL2_REAL_TIME_OUTPUT_DISABLES            (0xFFFBU) /* Disables real-time output */
#define _TAUD_CHANNEL2_REAL_TIME_OUTPUT_ENABLES             (0x0004U) /* Enables real-time output */
/* Enables or disables real-time output of channel 1 (TAUDnTRE1) */
#define _TAUD_CHANNEL1_REAL_TIME_OUTPUT_DISABLES            (0xFFFDU) /* Disables real-time output */
#define _TAUD_CHANNEL1_REAL_TIME_OUTPUT_ENABLES             (0x0002U) /* Enables real-time output */
/* Enables or disables real-time output of channel 0 (TAUDnTRE0) */
#define _TAUD_CHANNEL0_REAL_TIME_OUTPUT_DISABLES            (0xFFFEU) /* Disables real-time output */
#define _TAUD_CHANNEL0_REAL_TIME_OUTPUT_ENABLES             (0x0001U) /* Enables real-time output */

/*
    TAUDn Channel Status Clear Trigger Register (TAUDnCSCm)
*/
/* Clearing the overflow flag TAUDnCSRm.TAUDnOVF of channel m (TAUDnCLOV) */
#define _TAUD_OVERFLOW_FLAG_CLEAR                           (0x01U) /* Clears overflow flag */

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
#define _TAUD_OVERFLOW_OCCURS                               (0x01U) /* Overflow occurs */
#define _TAUD_OVERFLOW_VALUE                                (0x10000UL) /* Overflow value */

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
/* Start user code for function. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#endif
