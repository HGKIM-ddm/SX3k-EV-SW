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
* File Name        : r_cg_stbc.h
* Version          : 1.0.151
* Device(s)        : R7F701695
* Description      : General header file for STBC peripheral.
***********************************************************************************************************************/

#ifndef STBC_H
#define STBC_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/
/*
    Wake up factor clear register (WUFC0)
*/
/* Clear the WUFy bits in the wake-up factor registers */
#define _STBC_WUFC0_CLEAR_S1_4864PIN                            (0xF00FFFE7UL) /* Wake-up event is cleared */
#define _STBC_WUFC0_CLEAR_S1_80PIN                              (0xF0FFFFE7UL) /* Wake-up event is cleared */
#define _STBC_WUFC0_CLEAR_S1_100PIN                             (0xF2FFFFE7UL) /* Wake-up event is cleared */
#define _STBC_WUFC0_CLEAR_S2S4_100PIN                           (0xF3FFFFE7UL) /* Wake-up event is cleared */
#define _STBC_WUFC0_CLEAR                                       (0xFFFFFFE7UL) /* Wake-up event is cleared */
/*
    Wake up factor clear register (WUFC1)
*/
/*  Clear the WUFy bits in the wake-up factor registers */
#define _STBC_WUFC1_CLEAR_S1                                    (0x00000F00UL) /* Wake-up event is cleared */
#define _STBC_WUFC1_CLEAR_S2S4_100PIN                           (0x00000F00UL) /* Wake-up event is cleared */
#define _STBC_WUFC1_CLEAR                                       (0x00000FFFUL) /* Wake-up event is cleared */
/*
    Wake up factor clear register (WUFC_ISO0)
*/
/*  Clear the WUFy bits in the wake-up factor registers */
#define _STBC_WUFC_ISO0_CLEAR_S1_48PIN                          (0x0000000EUL) /* Wake-up event is cleared */
#define _STBC_WUFC_ISO0_CLEAR_S1_6480PIN                        (0x0000003EUL) /* Wake-up event is cleared */
#define _STBC_WUFC_ISO0_CLEAR_S1_100PIN                         (0x000001FEUL) /* Wake-up event is cleared */
#define _STBC_WUFC_ISO0_CLEAR                                   (0x00000DFEUL) /* Wake-up event is cleared */
/*
    Wake up factor clear register (WUFC20)
*/
/*  Clear the WUFy bits in the wake-up factor registers */
#define _STBC_WUFC20_CLEAR_S1_48PIN                             (0x003C1CFFUL) /* Wake-up event is cleared */
#define _STBC_WUFC20_CLEAR_S1_64PIN                             (0x003C1DFFUL) /* Wake-up event is cleared */
#define _STBC_WUFC20_CLEAR_S1_80PIN                             (0x003C1FFFUL) /* Wake-up event is cleared */
#define _STBC_WUFC20_CLEAR_S1_100PIN                            (0x003C3FFFUL) /* Wake-up event is cleared */
#define _STBC_WUFC20_CLEAR_S2S4_100PIN                          (0x003C1FFFUL) /* Wake-up event is cleared */
#define _STBC_WUFC20_CLEAR_S2S4_144PIN                          (0x003CFFFFUL) /* Wake-up event is cleared */
#define _STBC_WUFC20_CLEAR                                      (0x003FFFFFUL) /* Wake-up event is cleared */
/*
    Wake up factor register (WUFMSK0)
*/
/* Indicates enable a wake-up event (WUFMSK00) */
#define _STBC_WUFMSK0_FACTOR_TNMI                               (0xFFFFFFFEUL) /* Wake-up event is enabled */
/* Indicates enable a wake-up event (WUFMSK01) */
#define _STBC_WUFMSK0_FACTOR_WDTA0NMI                           (0xFFFFFFFDUL) /* Wake-up event is enabled */
/* Indicates enable a wake-up event (WUFMSK02) */
#define _STBC_WUFMSK0_FACTOR_INTLVIL                            (0xFFFFFFFBUL) /* Wake-up event is enabled */
/* Indicates enable a wake-up event (WUFMSK05) */
#define _STBC_WUFMSK0_FACTOR_INTP0                              (0xFFFFFFDFUL) /* Wake-up event is enabled */
/* Indicates enable a wake-up event (WUFMSK06) */
#define _STBC_WUFMSK0_FACTOR_INTP1                              (0xFFFFFFBFUL) /* Wake-up event is enabled */
/* Indicates enable a wake-up event (WUFMSK07) */
#define _STBC_WUFMSK0_FACTOR_INTP2                              (0xFFFFFF7FUL) /* Wake-up event is enabled */
/* Indicates enable a wake-up event (WUFMSK08) */
#define _STBC_WUFMSK0_FACTOR_INTWDTA0                           (0xFFFFFEFFUL) /* Wake-up event is enabled */
/* Indicates enable a wake-up event (WUFMSK09) */
#define _STBC_WUFMSK0_FACTOR_INTP3                              (0xFFFFFDFFUL) /* Wake-up event is enabled */
/* Indicates enable a wake-up event (WUFMSK10) */
#define _STBC_WUFMSK0_FACTOR_INTP4                              (0xFFFFFBFFUL) /* Wake-up event is enabled */
/* Indicates enable a wake-up event (WUFMSK011) */
#define _STBC_WUFMSK0_FACTOR_INTP5                              (0xFFFFF7FFUL) /* Wake-up event is enabled */
/* Indicates enable a wake-up event (WUFMSK012) */
#define _STBC_WUFMSK0_FACTOR_INTP10                             (0xFFFFEFFFUL) /* Wake-up event is enabled */
/* Indicates enable a wake-up event (WUFMSK013) */
#define _STBC_WUFMSK0_FACTOR_INTP11                             (0xFFFFDFFFUL) /* Wake-up event is enabled */
/* Indicates enable a wake-up event (WUFMSK014) */
#define _STBC_WUFMSK0_FACTOR_WUTRG1                             (0xFFFFBFFFUL) /* Wake-up event is enabled */
/* Indicates enable a wake-up event (WUFMSK015) */
#define _STBC_WUFMSK0_FACTOR_INTTAUJ0I0                         (0xFFFF7FFFUL) /* Wake-up event is enabled */
/* Indicates enable a wake-up event (WUFMSK016) */
#define _STBC_WUFMSK0_FACTOR_INTTAUJ0I1                         (0xFFFEFFFFUL) /* Wake-up event is enabled */
/* Indicates enable a wake-up event (WUFMSK017) */
#define _STBC_WUFMSK0_FACTOR_INTTAUJ0I2                         (0xFFFDFFFFUL) /* Wake-up event is enabled */
/* Indicates enable a wake-up event (WUFMSK018) */
#define _STBC_WUFMSK0_FACTOR_INTTAUJ0I3                         (0xFFFBFFFFUL) /* Wake-up event is enabled */
/* Indicates enable a wake-up event (WUFMSK019) */
#define _STBC_WUFMSK0_FACTOR_WUTRG0                             (0xFFF7FFFFUL) /* Wake-up event is enabled */
/* Indicates enable a wake-up event (WUFMSK020) */
#define _STBC_WUFMSK0_FACTOR_INTP6                              (0xFFEFFFFFUL) /* Wake-up event is enabled */
/* Indicates enable a wake-up event (WUFMSK021) */
#define _STBC_WUFMSK0_FACTOR_INTP7                              (0xFFDFFFFFUL) /* Wake-up event is enabled */
/* Indicates enable a wake-up event (WUFMSK022) */
#define _STBC_WUFMSK0_FACTOR_INTP8                              (0xFFBFFFFFUL) /* Wake-up event is enabled */
/* Indicates enable a wake-up event (WUFMSK023) */
#define _STBC_WUFMSK0_FACTOR_INTP12                             (0xFF7FFFFFUL) /* Wake-up event is enabled */
/* Indicates enable a wake-up event (WUFMSK024) */
#define _STBC_WUFMSK0_FACTOR_INTP9                              (0xFEFFFFFFUL) /* Wake-up event is enabled */
/* Indicates enable a wake-up event (WUFMSK025) */
#define _STBC_WUFMSK0_FACTOR_INTP13                             (0xFDFFFFFFUL) /* Wake-up event is enabled */
/* Indicates enable a wake-up event (WUFMSK026) */
#define _STBC_WUFMSK0_FACTOR_INTP14                             (0xFBFFFFFFUL) /* Wake-up event is enabled */
/* Indicates enable a wake-up event (WUFMSK027) */
#define _STBC_WUFMSK0_FACTOR_INTP15                             (0xF7FFFFFFUL) /* Wake-up event is enabled */
/* Indicates enable a wake-up event (WUFMSK028) */
#define _STBC_WUFMSK0_FACTOR_INTRTCA01S                         (0xEFFFFFFFUL) /* Wake-up event is enabled */
/* Indicates enable a wake-up event (WUFMSK029) */
#define _STBC_WUFMSK0_FACTOR_INTRTCA0AL                         (0xDFFFFFFFUL) /* Wake-up event is enabled */
/* Indicates enable a wake-up event (WUFMSK030) */
#define _STBC_WUFMSK0_FACTOR_INTRTCA0R                          (0xBFFFFFFFUL) /* Wake-up event is enabled */
/* Indicates enable a wake-up event (WUFMSK031) */
#define _STBC_WUFMSK0_FACTOR_INTDCUTDI                          (0x7FFFFFFFUL) /* Wake-up event is enabled */
/*
    Wake up factor register (WUFMSK1)
*/
/* Indicates enable a wake-up event (WUFMSK10) */
#define _STBC_WUFMSK1_FACTOR_INTP16                             (0xFFFFFFFEUL) /* Wake-up event is enabled */
/* Indicates enable a wake-up event (WUFMSK11) */
#define _STBC_WUFMSK1_FACTOR_INTP17                             (0xFFFFFFFDUL) /* Wake-up event is enabled */
/* Indicates enable a wake-up event (WUFMSK12) */
#define _STBC_WUFMSK1_FACTOR_INTP18                             (0xFFFFFFFBUL) /* Wake-up event is enabled */
/* Indicates enable a wake-up event (WUFMSK13) */
#define _STBC_WUFMSK1_FACTOR_INTP19                             (0xFFFFFFF7UL) /* Wake-up event is enabled */
/* Indicates enable a wake-up event (WUFMSK14) */
#define _STBC_WUFMSK1_FACTOR_INTP20                             (0xFFFFFFEFUL) /* Wake-up event is enabled */
/* Indicates enable a wake-up event (WUFMSK15) */
#define _STBC_WUFMSK1_FACTOR_INTP21                             (0xFFFFFFDFUL) /* Wake-up event is enabled */
/* Indicates enable a wake-up event (WUFMSK16) */
#define _STBC_WUFMSK1_FACTOR_INTP22                             (0xFFFFFFBFUL) /* Wake-up event is enabled */
/* Indicates enable a wake-up event (WUFMSK17) */
#define _STBC_WUFMSK1_FACTOR_INTP23                             (0xFFFFFF7FUL) /* Wake-up event is enabled */
/* Indicates enable a wake-up event (WUFMSK18) */
#define _STBC_WUFMSK1_FACTOR_INTTAUJ2I0                         (0xFFFFFEFFUL) /* Wake-up event is enabled */
/* Indicates enable a wake-up event (WUFMSK19) */
#define _STBC_WUFMSK1_FACTOR_INTTAUJ2I1                         (0xFFFFFDFFUL) /* Wake-up event is enabled */
/* Indicates enable a wake-up event (WUFMSK110) */
#define _STBC_WUFMSK1_FACTOR_INTTAUJ2I2                         (0xFFFFFBFFUL) /* Wake-up event is enabled */
/* Indicates enable a wake-up event (WUFMSK111) */
#define _STBC_WUFMSK1_FACTOR_INTTAUJ2I3                         (0xFFFFF7FFUL) /* Wake-up event is enabled */
/*
    Wake up factor register (WUFMSK_ISO0)
*/
/* Indicates enable a wake-up event (WUFMSK01) */
#define _STBC_WUFMSK_ISO0_FACTOR_INTKR0                         (0xFFFFFFFDUL) /* Wake-up event is enabled */
/* Indicates enable a wake-up event (WUFMSK02) */
#define _STBC_WUFMSK_ISO0_FACTOR_INTRCANGRECC0                  (0xFFFFFFFBUL) /* Wake-up event is enabled */
/* Indicates enable a wake-up event (WUFMSK03) */
#define _STBC_WUFMSK_ISO0_FACTOR_INTRCAN0REC                    (0xFFFFFFF7UL) /* Wake-up event is enabled */
/* Indicates enable a wake-up event (WUFMSK04) */
#define _STBC_WUFMSK_ISO0_FACTOR_INTRCAN1REC                    (0xFFFFFFEFUL) /* Wake-up event is enabled */
/* Indicates enable a wake-up event (WUFMSK05) */
#define _STBC_WUFMSK_ISO0_FACTOR_INTRCAN2REC                    (0xFFFFFFDFUL) /* Wake-up event is enabled */
/* Indicates enable a wake-up event (WUFMSK06) */
#define _STBC_WUFMSK_ISO0_FACTOR_INTRCAN3REC                    (0xFFFFFFBFUL) /* Wake-up event is enabled */
/* Indicates enable a wake-up event (WUFMSK07) */
#define _STBC_WUFMSK_ISO0_FACTOR_INTRCAN4REC                    (0xFFFFFF7FUL) /* Wake-up event is enabled */
/* Indicates enable a wake-up event (WUFMSK08) */
#define _STBC_WUFMSK_ISO0_FACTOR_INTRCAN5REC                    (0xFFFFFEFFUL) /* Wake-up event is enabled */
/* Indicates enable a wake-up event (WUFMSK10) */
#define _STBC_WUFMSK_ISO0_FACTOR_INTRCAN6REC                    (0xFFFFFBFFUL) /* Wake-up event is enabled */
/* Indicates enable a wake-up event (WUFMSK11) */
#define _STBC_WUFMSK_ISO0_FACTOR_INTRCAN7REC                    (0xFFFFF7FFUL) /* Wake-up event is enabled */
/*
    Wake up factor register (WUFMSK20)
*/
/* Indicates enable a wake-up event (WUFMSK200) */
#define _STBC_WUFMSK20_FACTOR_INTADCA0I0                        (0xFFFFFFFEUL) /* Wake-up event is enabled */
/* Indicates enable a wake-up event (WUFMSK201) */
#define _STBC_WUFMSK20_FACTOR_INTADCA0I1                        (0xFFFFFFFDUL) /* Wake-up event is enabled */
/* Indicates enable a wake-up event (WUFMSK202) */
#define _STBC_WUFMSK20_FACTOR_INTADCA0I2                        (0xFFFFFFFBUL) /* Wake-up event is enabled */
/* Indicates enable a wake-up event (WUFMSK203) */
#define _STBC_WUFMSK20_FACTOR_INTRLIN30                         (0xFFFFFFF7UL) /* Wake-up event is enabled */
/* Indicates enable a wake-up event (WUFMSK204) */
#define _STBC_WUFMSK20_FACTOR_INTTAUJ0I0                        (0xFFFFFFEFUL) /* Wake-up event is enabled */
/* Indicates enable a wake-up event (WUFMSK205) */
#define _STBC_WUFMSK20_FACTOR_INTTAUJ0I1                        (0xFFFFFFDFUL) /* Wake-up event is enabled */
/* Indicates enable a wake-up event (WUFMSK206) */
#define _STBC_WUFMSK20_FACTOR_INTTAUJ0I2                        (0xFFFFFFBFUL) /* Wake-up event is enabled */
/* Indicates enable a wake-up event (WUFMSK207) */
#define _STBC_WUFMSK20_FACTOR_INTTAUJ0I3                        (0xFFFFFF7FUL) /* Wake-up event is enabled */
/* Indicates enable a wake-up event (WUFMSK208) */
#define _STBC_WUFMSK20_FACTOR_INTRLIN31                         (0xFFFFFEFFUL) /* Wake-up event is enabled */
/* Indicates enable a wake-up event (WUFMSK209) */
#define _STBC_WUFMSK20_FACTOR_INTRLIN32                         (0xFFFFFDFFUL) /* Wake-up event is enabled */
/* Indicates enable a wake-up event (WUFMSK2010) */
#define _STBC_WUFMSK20_FACTOR_INTRTCA01S                        (0xFFFFFBFFUL) /* Wake-up event is enabled */
/* Indicates enable a wake-up event (WUFMSK2011) */
#define _STBC_WUFMSK20_FACTOR_INTRTCA0AL                        (0xFFFFF7FFUL) /* Wake-up event is enabled */
/* Indicates enable a wake-up event (WUFMSK2012) */
#define _STBC_WUFMSK20_FACTOR_INTRTCA0R                         (0xFFFFEFFFUL) /* Wake-up event is enabled */
/* Indicates enable a wake-up event (WUFMSK2013) */
#define _STBC_WUFMSK20_FACTOR_INTRLIN33                         (0xFFFFDFFFUL) /* Wake-up event is enabled */
/* Indicates enable a wake-up event (WUFMSK2014) */
#define _STBC_WUFMSK20_FACTOR_INTRLIN34                         (0xFFFFBFFFUL) /* Wake-up event is enabled */
/* Indicates enable a wake-up event (WUFMSK2015) */
#define _STBC_WUFMSK20_FACTOR_INTRLIN35                         (0xFFFF7FFFUL) /* Wake-up event is enabled */
/* Indicates enable a wake-up event (WUFMSK2016) */
#define _STBC_WUFMSK20_FACTOR_INTRLIN36                         (0xFFFEFFFFUL) /* Wake-up event is enabled */
/* Indicates enable a wake-up event (WUFMSK2017) */
#define _STBC_WUFMSK20_FACTOR_INTRLIN37                         (0xFFFDFFFFUL) /* Wake-up event is enabled */
/* Indicates enable a wake-up event (WUFMSK2018) */
#define _STBC_WUFMSK20_FACTOR_INTTAUJ2I0                        (0xFFFBFFFFUL) /* Wake-up event is enabled */
/* Indicates enable a wake-up event (WUFMSK2019) */
#define _STBC_WUFMSK20_FACTOR_INTTAUJ2I1                        (0xFFF7FFFFUL) /* Wake-up event is enabled */
/* Indicates enable a wake-up event (WUFMSK2020) */
#define _STBC_WUFMSK20_FACTOR_INTTAUJ2I2                        (0xFFEFFFFFUL) /* Wake-up event is enabled */
/* Indicates enable a wake-up event (WUFMSK2021) */
#define _STBC_WUFMSK20_FACTOR_INTTAUJ2I3                        (0xFFDFFFFFUL) /* Wake-up event is enabled */

/*
    Power save control register (STBC0PSC)
*/
/* Power save control (STBC0DISTRG) */
#define _STBC_DEEP_STOP_MODE_DISABLE                            (0x00000000UL) /* Writing 0 has no effect */
#define _STBC_DEEP_STOP_MODE_ENTERED                            (0x00000002UL) /* DeepSTOP mode is entered */

/*
    Power stop trigger register (STBC0STPT)
*/
/* Power stop trigger (STBC0STPTRG) */
#define _STBC_STOP_MODE_DISABLE                                 (0x00000000UL) /* Writing 0 has no effect */
#define _STBC_STOP_MODE_ENTERED                                 (0x00000001UL) /* Stop mode is entered */

/*
    reset factor clear register (RESFC)
*/
/* Reset flag clear by DeepSTOP mode (RESFC10) */
#define _RESFC_RESET_FLAG_CLEAR                                 (0x00000400UL) /* Clear reset flag */

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
/* Start user code for function. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#endif
