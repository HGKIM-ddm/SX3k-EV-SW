/******************************************************************************/
/* DISCLAIMER                                                                 */
/* This software is supplied by Renesas Electronics Corporation and is only   */
/* intended for use with Renesas products. No other uses are authorized.This  */
/* software is owned by Renesas Electronics Corporation and is protected      */
/* under all applicable laws, including copyright laws.                       */
/* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES          */
/* REGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING  */
/* BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR */
/* PURPOSE AND NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY           */
/* DISCLAIMED.                                                                */
/* TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS     */
/* ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE       */
/* LIABLE FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL      */
/* DAMAGES FOR ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS    */
/* AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.           */
/* Renesas reserves the right, without notice, to make changes to this        */
/* software and to discontinue the availability of this software.             */
/* By using this software, you agree to the additional terms and conditions   */
/* found by accessing the following link:                                     */
/* http://www.renesas.com/disclaimer                                          */
/*                                                                            */
/* Device     : RH/RH850G3KH/R7F701695                                        */
/* File Name  : iodefine.h                                                    */
/* Abstract   : Definition of I/O Register                                    */
/* History    : V1.20  [Device File version]                                  */
/* Options    : -df=D:\CS+\CS+E7.00.00G\CS+E7.00.00G\CS+\CC\Device\RH850\Devi */
/*              cefile\DR7F701695.DVF -o=D:\SCRH850F1KM_IT\iodefine\r7f701695 */
/*              \iodefine.h -def=off -f                                       */
/* Date       : 2018/06/13                                                    */
/* Version    : V1.09.00.04  [df2iodef.exe version]                           */
/* This is a typical example.                                                 */
/*                                                                            */
/******************************************************************************/
#ifndef __R7F701695IODEFINE_HEADER__
#define __R7F701695IODEFINE_HEADER__

typedef struct
{
    unsigned char bit00:1;
    unsigned char bit01:1;
    unsigned char bit02:1;
    unsigned char bit03:1;
    unsigned char bit04:1;
    unsigned char bit05:1;
    unsigned char bit06:1;
    unsigned char bit07:1;
} __bitf_T;

#define  L 0
#define  H 1
#define LL 0
#define LH 1
#define HL 2
#define HH 3

struct __tag0
{                                                          /* Bit Access       */
    unsigned char  ATAUD0IENH0:1;                          /* ATAUD0IENH0      */
    unsigned char  ATAUD0IENH1:1;                          /* ATAUD0IENH1      */
    unsigned char  ATAUD0IENH2:1;                          /* ATAUD0IENH2      */
    unsigned char  ATAUD0IENH3:1;                          /* ATAUD0IENH3      */
    unsigned char  ATAUD0IENH4:1;                          /* ATAUD0IENH4      */
    unsigned char  ATAUD0IENH5:1;                          /* ATAUD0IENH5      */
    unsigned char  ATAUD0IENH6:1;                          /* ATAUD0IENH6      */
    unsigned char  ATAUD0IENH7:1;                          /* ATAUD0IENH7      */
};
struct __tag1
{                                                          /* Bit Access       */
    unsigned char  ATAUD0IENL0:1;                          /* ATAUD0IENL0      */
    unsigned char  ATAUD0IENL1:1;                          /* ATAUD0IENL1      */
    unsigned char  ATAUD0IENL2:1;                          /* ATAUD0IENL2      */
    unsigned char  ATAUD0IENL3:1;                          /* ATAUD0IENL3      */
    unsigned char  ATAUD0IENL4:1;                          /* ATAUD0IENL4      */
    unsigned char  ATAUD0IENL5:1;                          /* ATAUD0IENL5      */
    unsigned char  ATAUD0IENL6:1;                          /* ATAUD0IENL6      */
    unsigned char  ATAUD0IENL7:1;                          /* ATAUD0IENL7      */
};
struct __tag2
{                                                          /* Bit Access       */
    unsigned char  AENCA0IENL0:1;                          /* AENCA0IENL0      */
    unsigned char  AENCA0IENL1:1;                          /* AENCA0IENL1      */
    unsigned char  AENCA0IENL2:1;                          /* AENCA0IENL2      */
    unsigned char  AENCA0IENL3:1;                          /* AENCA0IENL3      */
    unsigned char  AENCA0IENL4:1;                          /* AENCA0IENL4      */
    unsigned char  :3;                                     /* Reserved Bits    */
};
struct __tag3
{                                                          /* Bit Access       */
    unsigned char  AADCTL0ENL0:1;                          /* AADCTL0ENL0      */
    unsigned char  AADCTL0ENL1:1;                          /* AADCTL0ENL1      */
    unsigned char  AADCTL0ENL2:1;                          /* AADCTL0ENL2      */
    unsigned char  :5;                                     /* Reserved Bits    */
};
struct __tag4
{                                                          /* Bit Access       */
    unsigned char  ASENTIENL0:1;                           /* ASENTIENL0       */
    unsigned char  ASENTIENL1:1;                           /* ASENTIENL1       */
    unsigned char  :6;                                     /* Reserved Bits    */
};
struct __tag5
{                                                          /* Bit Access       */
    unsigned char  :7;                                     /* Reserved Bits    */
    unsigned char  SVSDIS:1;                               /* SVSDIS           */
};
struct __tag6
{                                                          /* Bit Access       */
    unsigned char  SCE:1;                                  /* SCE              */
    unsigned char  :7;                                     /* Reserved Bits    */
};
struct __tag7
{                                                          /* Bit Access       */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  SLSB:1;                                 /* SLSB             */
    unsigned char  AMPM:1;                                 /* AMPM             */
    unsigned char  CEST:1;                                 /* CEST             */
    unsigned char  CE:1;                                   /* CE               */
};
struct __tag8
{                                                          /* Bit Access       */
    unsigned char  CT0:1;                                  /* CT0              */
    unsigned char  CT1:1;                                  /* CT1              */
    unsigned char  CT2:1;                                  /* CT2              */
    unsigned char  EN1S:1;                                 /* EN1S             */
    unsigned char  ENALM:1;                                /* ENALM            */
    unsigned char  EN1HZ:1;                                /* EN1HZ            */
    unsigned char  :2;                                     /* Reserved Bits    */
};
struct __tag9
{                                                          /* Bit Access       */
    unsigned char  WAIT:1;                                 /* WAIT             */
    unsigned char  WST:1;                                  /* WST              */
    unsigned char  RSUB:1;                                 /* RSUB             */
    unsigned char  RSST:1;                                 /* RSST             */
    unsigned char  WSST:1;                                 /* WSST             */
    unsigned char  WUST:1;                                 /* WUST             */
    unsigned char  :2;                                     /* Reserved Bits    */
};
struct __tag10
{                                                          /* Bit Access       */
    unsigned char  KRM0:1;                                 /* KRM0             */
    unsigned char  KRM1:1;                                 /* KRM1             */
    unsigned char  KRM2:1;                                 /* KRM2             */
    unsigned char  KRM3:1;                                 /* KRM3             */
    unsigned char  KRM4:1;                                 /* KRM4             */
    unsigned char  KRM5:1;                                 /* KRM5             */
    unsigned char  :2;                                     /* Reserved Bits    */
};
struct __tag11
{                                                          /* Bit Access       */
    unsigned char  P0TAUD0I0:1;                            /* P0TAUD0I0        */
    unsigned char  P1TAUD0I0:1;                            /* P1TAUD0I0        */
    unsigned char  P2TAUD0I0:1;                            /* P2TAUD0I0        */
    unsigned char  P3TAUD0I0:1;                            /* P3TAUD0I0        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBTAUD0I0:1;                            /* TBTAUD0I0        */
    unsigned char  MKTAUD0I0:1;                            /* MKTAUD0I0        */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFTAUD0I0:1;                            /* RFTAUD0I0        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTTAUD0I0:1;                            /* CTTAUD0I0        */
};
struct __tag12
{                                                          /* Bit Access       */
    unsigned char  P0TAUD0I2:1;                            /* P0TAUD0I2        */
    unsigned char  P1TAUD0I2:1;                            /* P1TAUD0I2        */
    unsigned char  P2TAUD0I2:1;                            /* P2TAUD0I2        */
    unsigned char  P3TAUD0I2:1;                            /* P3TAUD0I2        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBTAUD0I2:1;                            /* TBTAUD0I2        */
    unsigned char  MKTAUD0I2:1;                            /* MKTAUD0I2        */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFTAUD0I2:1;                            /* RFTAUD0I2        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTTAUD0I2:1;                            /* CTTAUD0I2        */
};
struct __tag13
{                                                          /* Bit Access       */
    unsigned char  P0TAUD0I4:1;                            /* P0TAUD0I4        */
    unsigned char  P1TAUD0I4:1;                            /* P1TAUD0I4        */
    unsigned char  P2TAUD0I4:1;                            /* P2TAUD0I4        */
    unsigned char  P3TAUD0I4:1;                            /* P3TAUD0I4        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBTAUD0I4:1;                            /* TBTAUD0I4        */
    unsigned char  MKTAUD0I4:1;                            /* MKTAUD0I4        */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFTAUD0I4:1;                            /* RFTAUD0I4        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTTAUD0I4:1;                            /* CTTAUD0I4        */
};
struct __tag14
{                                                          /* Bit Access       */
    unsigned char  P0TAUD0I6:1;                            /* P0TAUD0I6        */
    unsigned char  P1TAUD0I6:1;                            /* P1TAUD0I6        */
    unsigned char  P2TAUD0I6:1;                            /* P2TAUD0I6        */
    unsigned char  P3TAUD0I6:1;                            /* P3TAUD0I6        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBTAUD0I6:1;                            /* TBTAUD0I6        */
    unsigned char  MKTAUD0I6:1;                            /* MKTAUD0I6        */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFTAUD0I6:1;                            /* RFTAUD0I6        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTTAUD0I6:1;                            /* CTTAUD0I6        */
};
struct __tag15
{                                                          /* Bit Access       */
    unsigned char  P0TAUD0I8:1;                            /* P0TAUD0I8        */
    unsigned char  P1TAUD0I8:1;                            /* P1TAUD0I8        */
    unsigned char  P2TAUD0I8:1;                            /* P2TAUD0I8        */
    unsigned char  P3TAUD0I8:1;                            /* P3TAUD0I8        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBTAUD0I8:1;                            /* TBTAUD0I8        */
    unsigned char  MKTAUD0I8:1;                            /* MKTAUD0I8        */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFTAUD0I8:1;                            /* RFTAUD0I8        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTTAUD0I8:1;                            /* CTTAUD0I8        */
};
struct __tag16
{                                                          /* Bit Access       */
    unsigned char  P0TAUD0I10:1;                           /* P0TAUD0I10       */
    unsigned char  P1TAUD0I10:1;                           /* P1TAUD0I10       */
    unsigned char  P2TAUD0I10:1;                           /* P2TAUD0I10       */
    unsigned char  P3TAUD0I10:1;                           /* P3TAUD0I10       */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBTAUD0I10:1;                           /* TBTAUD0I10       */
    unsigned char  MKTAUD0I10:1;                           /* MKTAUD0I10       */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFTAUD0I10:1;                           /* RFTAUD0I10       */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTTAUD0I10:1;                           /* CTTAUD0I10       */
};
struct __tag17
{                                                          /* Bit Access       */
    unsigned char  P0TAUD0I12:1;                           /* P0TAUD0I12       */
    unsigned char  P1TAUD0I12:1;                           /* P1TAUD0I12       */
    unsigned char  P2TAUD0I12:1;                           /* P2TAUD0I12       */
    unsigned char  P3TAUD0I12:1;                           /* P3TAUD0I12       */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBTAUD0I12:1;                           /* TBTAUD0I12       */
    unsigned char  MKTAUD0I12:1;                           /* MKTAUD0I12       */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFTAUD0I12:1;                           /* RFTAUD0I12       */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTTAUD0I12:1;                           /* CTTAUD0I12       */
};
struct __tag18
{                                                          /* Bit Access       */
    unsigned char  P0TAUD0I14:1;                           /* P0TAUD0I14       */
    unsigned char  P1TAUD0I14:1;                           /* P1TAUD0I14       */
    unsigned char  P2TAUD0I14:1;                           /* P2TAUD0I14       */
    unsigned char  P3TAUD0I14:1;                           /* P3TAUD0I14       */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBTAUD0I14:1;                           /* TBTAUD0I14       */
    unsigned char  MKTAUD0I14:1;                           /* MKTAUD0I14       */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFTAUD0I14:1;                           /* RFTAUD0I14       */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTTAUD0I14:1;                           /* CTTAUD0I14       */
};
struct __tag19
{                                                          /* Bit Access       */
    unsigned char  P0TAPA0IPEK0:1;                         /* P0TAPA0IPEK0     */
    unsigned char  P1TAPA0IPEK0:1;                         /* P1TAPA0IPEK0     */
    unsigned char  P2TAPA0IPEK0:1;                         /* P2TAPA0IPEK0     */
    unsigned char  P3TAPA0IPEK0:1;                         /* P3TAPA0IPEK0     */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBTAPA0IPEK0:1;                         /* TBTAPA0IPEK0     */
    unsigned char  MKTAPA0IPEK0:1;                         /* MKTAPA0IPEK0     */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFTAPA0IPEK0:1;                         /* RFTAPA0IPEK0     */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTTAPA0IPEK0:1;                         /* CTTAPA0IPEK0     */
};
struct __tag20
{                                                          /* Bit Access       */
    unsigned char  P0TAPA0IVLY0:1;                         /* P0TAPA0IVLY0     */
    unsigned char  P1TAPA0IVLY0:1;                         /* P1TAPA0IVLY0     */
    unsigned char  P2TAPA0IVLY0:1;                         /* P2TAPA0IVLY0     */
    unsigned char  P3TAPA0IVLY0:1;                         /* P3TAPA0IVLY0     */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBTAPA0IVLY0:1;                         /* TBTAPA0IVLY0     */
    unsigned char  MKTAPA0IVLY0:1;                         /* MKTAPA0IVLY0     */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFTAPA0IVLY0:1;                         /* RFTAPA0IVLY0     */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTTAPA0IVLY0:1;                         /* CTTAPA0IVLY0     */
};
struct __tag21
{                                                          /* Bit Access       */
    unsigned char  P0ADCA0I0:1;                            /* P0ADCA0I0        */
    unsigned char  P1ADCA0I0:1;                            /* P1ADCA0I0        */
    unsigned char  P2ADCA0I0:1;                            /* P2ADCA0I0        */
    unsigned char  P3ADCA0I0:1;                            /* P3ADCA0I0        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBADCA0I0:1;                            /* TBADCA0I0        */
    unsigned char  MKADCA0I0:1;                            /* MKADCA0I0        */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFADCA0I0:1;                            /* RFADCA0I0        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTADCA0I0:1;                            /* CTADCA0I0        */
};
struct __tag22
{                                                          /* Bit Access       */
    unsigned char  P0ADCA0I1:1;                            /* P0ADCA0I1        */
    unsigned char  P1ADCA0I1:1;                            /* P1ADCA0I1        */
    unsigned char  P2ADCA0I1:1;                            /* P2ADCA0I1        */
    unsigned char  P3ADCA0I1:1;                            /* P3ADCA0I1        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBADCA0I1:1;                            /* TBADCA0I1        */
    unsigned char  MKADCA0I1:1;                            /* MKADCA0I1        */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFADCA0I1:1;                            /* RFADCA0I1        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTADCA0I1:1;                            /* CTADCA0I1        */
};
struct __tag23
{                                                          /* Bit Access       */
    unsigned char  P0ADCA0I2:1;                            /* P0ADCA0I2        */
    unsigned char  P1ADCA0I2:1;                            /* P1ADCA0I2        */
    unsigned char  P2ADCA0I2:1;                            /* P2ADCA0I2        */
    unsigned char  P3ADCA0I2:1;                            /* P3ADCA0I2        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBADCA0I2:1;                            /* TBADCA0I2        */
    unsigned char  MKADCA0I2:1;                            /* MKADCA0I2        */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFADCA0I2:1;                            /* RFADCA0I2        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTADCA0I2:1;                            /* CTADCA0I2        */
};
struct __tag24
{                                                          /* Bit Access       */
    unsigned char  P0DCUTDI:1;                             /* P0DCUTDI         */
    unsigned char  P1DCUTDI:1;                             /* P1DCUTDI         */
    unsigned char  P2DCUTDI:1;                             /* P2DCUTDI         */
    unsigned char  P3DCUTDI:1;                             /* P3DCUTDI         */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBDCUTDI:1;                             /* TBDCUTDI         */
    unsigned char  MKDCUTDI:1;                             /* MKDCUTDI         */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFDCUTDI:1;                             /* RFDCUTDI         */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTDCUTDI:1;                             /* CTDCUTDI         */
};
struct __tag25
{                                                          /* Bit Access       */
    unsigned char  P0RCANGERR0:1;                          /* P0RCANGERR0      */
    unsigned char  P1RCANGERR0:1;                          /* P1RCANGERR0      */
    unsigned char  P2RCANGERR0:1;                          /* P2RCANGERR0      */
    unsigned char  P3RCANGERR0:1;                          /* P3RCANGERR0      */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBRCANGERR0:1;                          /* TBRCANGERR0      */
    unsigned char  MKRCANGERR0:1;                          /* MKRCANGERR0      */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFRCANGERR0:1;                          /* RFRCANGERR0      */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTRCANGERR0:1;                          /* CTRCANGERR0      */
};
struct __tag26
{                                                          /* Bit Access       */
    unsigned char  P0RCANGRECC0:1;                         /* P0RCANGRECC0     */
    unsigned char  P1RCANGRECC0:1;                         /* P1RCANGRECC0     */
    unsigned char  P2RCANGRECC0:1;                         /* P2RCANGRECC0     */
    unsigned char  P3RCANGRECC0:1;                         /* P3RCANGRECC0     */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBRCANGRECC0:1;                         /* TBRCANGRECC0     */
    unsigned char  MKRCANGRECC0:1;                         /* MKRCANGRECC0     */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFRCANGRECC0:1;                         /* RFRCANGRECC0     */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTRCANGRECC0:1;                         /* CTRCANGRECC0     */
};
struct __tag27
{                                                          /* Bit Access       */
    unsigned char  P0RCAN0ERR:1;                           /* P0RCAN0ERR       */
    unsigned char  P1RCAN0ERR:1;                           /* P1RCAN0ERR       */
    unsigned char  P2RCAN0ERR:1;                           /* P2RCAN0ERR       */
    unsigned char  P3RCAN0ERR:1;                           /* P3RCAN0ERR       */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBRCAN0ERR:1;                           /* TBRCAN0ERR       */
    unsigned char  MKRCAN0ERR:1;                           /* MKRCAN0ERR       */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFRCAN0ERR:1;                           /* RFRCAN0ERR       */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTRCAN0ERR:1;                           /* CTRCAN0ERR       */
};
struct __tag28
{                                                          /* Bit Access       */
    unsigned char  P0RCAN0REC:1;                           /* P0RCAN0REC       */
    unsigned char  P1RCAN0REC:1;                           /* P1RCAN0REC       */
    unsigned char  P2RCAN0REC:1;                           /* P2RCAN0REC       */
    unsigned char  P3RCAN0REC:1;                           /* P3RCAN0REC       */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBRCAN0REC:1;                           /* TBRCAN0REC       */
    unsigned char  MKRCAN0REC:1;                           /* MKRCAN0REC       */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFRCAN0REC:1;                           /* RFRCAN0REC       */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTRCAN0REC:1;                           /* CTRCAN0REC       */
};
struct __tag29
{                                                          /* Bit Access       */
    unsigned char  P0RCAN0TRX:1;                           /* P0RCAN0TRX       */
    unsigned char  P1RCAN0TRX:1;                           /* P1RCAN0TRX       */
    unsigned char  P2RCAN0TRX:1;                           /* P2RCAN0TRX       */
    unsigned char  P3RCAN0TRX:1;                           /* P3RCAN0TRX       */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBRCAN0TRX:1;                           /* TBRCAN0TRX       */
    unsigned char  MKRCAN0TRX:1;                           /* MKRCAN0TRX       */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFRCAN0TRX:1;                           /* RFRCAN0TRX       */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTRCAN0TRX:1;                           /* CTRCAN0TRX       */
};
struct __tag30
{                                                          /* Bit Access       */
    unsigned char  P0CSIG0IC:1;                            /* P0CSIG0IC        */
    unsigned char  P1CSIG0IC:1;                            /* P1CSIG0IC        */
    unsigned char  P2CSIG0IC:1;                            /* P2CSIG0IC        */
    unsigned char  P3CSIG0IC:1;                            /* P3CSIG0IC        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBCSIG0IC:1;                            /* TBCSIG0IC        */
    unsigned char  MKCSIG0IC:1;                            /* MKCSIG0IC        */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFCSIG0IC:1;                            /* RFCSIG0IC        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTCSIG0IC:1;                            /* CTCSIG0IC        */
};
struct __tag31
{                                                          /* Bit Access       */
    unsigned char  P0CSIG0IR:1;                            /* P0CSIG0IR        */
    unsigned char  P1CSIG0IR:1;                            /* P1CSIG0IR        */
    unsigned char  P2CSIG0IR:1;                            /* P2CSIG0IR        */
    unsigned char  P3CSIG0IR:1;                            /* P3CSIG0IR        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBCSIG0IR:1;                            /* TBCSIG0IR        */
    unsigned char  MKCSIG0IR:1;                            /* MKCSIG0IR        */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFCSIG0IR:1;                            /* RFCSIG0IR        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTCSIG0IR:1;                            /* CTCSIG0IR        */
};
struct __tag32
{                                                          /* Bit Access       */
    unsigned char  P0CSIH0IC:1;                            /* P0CSIH0IC        */
    unsigned char  P1CSIH0IC:1;                            /* P1CSIH0IC        */
    unsigned char  P2CSIH0IC:1;                            /* P2CSIH0IC        */
    unsigned char  P3CSIH0IC:1;                            /* P3CSIH0IC        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBCSIH0IC:1;                            /* TBCSIH0IC        */
    unsigned char  MKCSIH0IC:1;                            /* MKCSIH0IC        */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFCSIH0IC:1;                            /* RFCSIH0IC        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTCSIH0IC:1;                            /* CTCSIH0IC        */
};
struct __tag33
{                                                          /* Bit Access       */
    unsigned char  P0CSIH0IR:1;                            /* P0CSIH0IR        */
    unsigned char  P1CSIH0IR:1;                            /* P1CSIH0IR        */
    unsigned char  P2CSIH0IR:1;                            /* P2CSIH0IR        */
    unsigned char  P3CSIH0IR:1;                            /* P3CSIH0IR        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBCSIH0IR:1;                            /* TBCSIH0IR        */
    unsigned char  MKCSIH0IR:1;                            /* MKCSIH0IR        */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFCSIH0IR:1;                            /* RFCSIH0IR        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTCSIH0IR:1;                            /* CTCSIH0IR        */
};
struct __tag34
{                                                          /* Bit Access       */
    unsigned char  P0CSIH0IRE:1;                           /* P0CSIH0IRE       */
    unsigned char  P1CSIH0IRE:1;                           /* P1CSIH0IRE       */
    unsigned char  P2CSIH0IRE:1;                           /* P2CSIH0IRE       */
    unsigned char  P3CSIH0IRE:1;                           /* P3CSIH0IRE       */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBCSIH0IRE:1;                           /* TBCSIH0IRE       */
    unsigned char  MKCSIH0IRE:1;                           /* MKCSIH0IRE       */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFCSIH0IRE:1;                           /* RFCSIH0IRE       */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTCSIH0IRE:1;                           /* CTCSIH0IRE       */
};
struct __tag35
{                                                          /* Bit Access       */
    unsigned char  :8;                                     /* Reserved Bits    */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  FNRF:1;                                 /* FNRF             */
    unsigned char  :3;                                     /* Reserved Bits    */
};
struct __tag36
{                                                          /* Bit Access       */
    unsigned char  :8;                                     /* Reserved Bits    */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  FIRF:1;                                 /* FIRF             */
    unsigned char  :3;                                     /* Reserved Bits    */
};
struct __tag37
{                                                          /* Bit Access       */
    unsigned char  :8;                                     /* Reserved Bits    */
    unsigned char  IMR0EIMK8:1;                            /* IMR0EIMK8        */
    unsigned char  IMR0EIMK9:1;                            /* IMR0EIMK9        */
    unsigned char  IMR0EIMK10:1;                           /* IMR0EIMK10       */
    unsigned char  IMR0EIMK11:1;                           /* IMR0EIMK11       */
    unsigned char  IMR0EIMK12:1;                           /* IMR0EIMK12       */
    unsigned char  IMR0EIMK13:1;                           /* IMR0EIMK13       */
    unsigned char  IMR0EIMK14:1;                           /* IMR0EIMK14       */
    unsigned char  IMR0EIMK15:1;                           /* IMR0EIMK15       */
    unsigned char  IMR0EIMK16:1;                           /* IMR0EIMK16       */
    unsigned char  IMR0EIMK17:1;                           /* IMR0EIMK17       */
    unsigned char  IMR0EIMK18:1;                           /* IMR0EIMK18       */
    unsigned char  IMR0EIMK19:1;                           /* IMR0EIMK19       */
    unsigned char  IMR0EIMK20:1;                           /* IMR0EIMK20       */
    unsigned char  IMR0EIMK21:1;                           /* IMR0EIMK21       */
    unsigned char  IMR0EIMK22:1;                           /* IMR0EIMK22       */
    unsigned char  IMR0EIMK23:1;                           /* IMR0EIMK23       */
    unsigned char  IMR0EIMK24:1;                           /* IMR0EIMK24       */
    unsigned char  IMR0EIMK25:1;                           /* IMR0EIMK25       */
    unsigned char  IMR0EIMK26:1;                           /* IMR0EIMK26       */
    unsigned char  IMR0EIMK27:1;                           /* IMR0EIMK27       */
    unsigned char  IMR0EIMK28:1;                           /* IMR0EIMK28       */
    unsigned char  IMR0EIMK29:1;                           /* IMR0EIMK29       */
    unsigned char  IMR0EIMK30:1;                           /* IMR0EIMK30       */
    unsigned char  IMR0EIMK31:1;                           /* IMR0EIMK31       */
};
struct __tag38
{                                                          /* Bit Access       */
    unsigned char  P0ADCA0I2_2:1;                          /* P0ADCA0I2_2      */
    unsigned char  P1ADCA0I2_2:1;                          /* P1ADCA0I2_2      */
    unsigned char  P2ADCA0I2_2:1;                          /* P2ADCA0I2_2      */
    unsigned char  P3ADCA0I2_2:1;                          /* P3ADCA0I2_2      */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBADCA0I2_2:1;                          /* TBADCA0I2_2      */
    unsigned char  MKADCA0I2_2:1;                          /* MKADCA0I2_2      */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFADCA0I2_2:1;                          /* RFADCA0I2_2      */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTADCA0I2_2:1;                          /* CTADCA0I2_2      */
};
struct __tag39
{                                                          /* Bit Access       */
    unsigned char  P0RLIN30:1;                             /* P0RLIN30         */
    unsigned char  P1RLIN30:1;                             /* P1RLIN30         */
    unsigned char  P2RLIN30:1;                             /* P2RLIN30         */
    unsigned char  P3RLIN30:1;                             /* P3RLIN30         */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBRLIN30:1;                             /* TBRLIN30         */
    unsigned char  MKRLIN30:1;                             /* MKRLIN30         */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFRLIN30:1;                             /* RFRLIN30         */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTRLIN30:1;                             /* CTRLIN30         */
};
struct __tag40
{                                                          /* Bit Access       */
    unsigned char  P0RLIN30UR0:1;                          /* P0RLIN30UR0      */
    unsigned char  P1RLIN30UR0:1;                          /* P1RLIN30UR0      */
    unsigned char  P2RLIN30UR0:1;                          /* P2RLIN30UR0      */
    unsigned char  P3RLIN30UR0:1;                          /* P3RLIN30UR0      */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBRLIN30UR0:1;                          /* TBRLIN30UR0      */
    unsigned char  MKRLIN30UR0:1;                          /* MKRLIN30UR0      */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFRLIN30UR0:1;                          /* RFRLIN30UR0      */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTRLIN30UR0:1;                          /* CTRLIN30UR0      */
};
struct __tag41
{                                                          /* Bit Access       */
    unsigned char  P0RLIN30UR1:1;                          /* P0RLIN30UR1      */
    unsigned char  P1RLIN30UR1:1;                          /* P1RLIN30UR1      */
    unsigned char  P2RLIN30UR1:1;                          /* P2RLIN30UR1      */
    unsigned char  P3RLIN30UR1:1;                          /* P3RLIN30UR1      */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBRLIN30UR1:1;                          /* TBRLIN30UR1      */
    unsigned char  MKRLIN30UR1:1;                          /* MKRLIN30UR1      */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFRLIN30UR1:1;                          /* RFRLIN30UR1      */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTRLIN30UR1:1;                          /* CTRLIN30UR1      */
};
struct __tag42
{                                                          /* Bit Access       */
    unsigned char  P0RLIN30UR2:1;                          /* P0RLIN30UR2      */
    unsigned char  P1RLIN30UR2:1;                          /* P1RLIN30UR2      */
    unsigned char  P2RLIN30UR2:1;                          /* P2RLIN30UR2      */
    unsigned char  P3RLIN30UR2:1;                          /* P3RLIN30UR2      */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBRLIN30UR2:1;                          /* TBRLIN30UR2      */
    unsigned char  MKRLIN30UR2:1;                          /* MKRLIN30UR2      */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFRLIN30UR2:1;                          /* RFRLIN30UR2      */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTRLIN30UR2:1;                          /* CTRLIN30UR2      */
};
struct __tag43
{                                                          /* Bit Access       */
    unsigned char  P0P0:1;                                 /* P0P0             */
    unsigned char  P1P0:1;                                 /* P1P0             */
    unsigned char  P2P0:1;                                 /* P2P0             */
    unsigned char  P3P0:1;                                 /* P3P0             */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBP0:1;                                 /* TBP0             */
    unsigned char  MKP0:1;                                 /* MKP0             */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFP0:1;                                 /* RFP0             */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTP0:1;                                 /* CTP0             */
};
struct __tag44
{                                                          /* Bit Access       */
    unsigned char  P0P1:1;                                 /* P0P1             */
    unsigned char  P1P1:1;                                 /* P1P1             */
    unsigned char  P2P1:1;                                 /* P2P1             */
    unsigned char  P3P1:1;                                 /* P3P1             */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBP1:1;                                 /* TBP1             */
    unsigned char  MKP1:1;                                 /* MKP1             */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFP1:1;                                 /* RFP1             */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTP1:1;                                 /* CTP1             */
};
struct __tag45
{                                                          /* Bit Access       */
    unsigned char  P0P2:1;                                 /* P0P2             */
    unsigned char  P1P2:1;                                 /* P1P2             */
    unsigned char  P2P2:1;                                 /* P2P2             */
    unsigned char  P3P2:1;                                 /* P3P2             */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBP2:1;                                 /* TBP2             */
    unsigned char  MKP2:1;                                 /* MKP2             */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFP2:1;                                 /* RFP2             */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTP2:1;                                 /* CTP2             */
};
struct __tag46
{                                                          /* Bit Access       */
    unsigned char  P0WDTA0:1;                              /* P0WDTA0          */
    unsigned char  P1WDTA0:1;                              /* P1WDTA0          */
    unsigned char  P2WDTA0:1;                              /* P2WDTA0          */
    unsigned char  P3WDTA0:1;                              /* P3WDTA0          */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBWDTA0:1;                              /* TBWDTA0          */
    unsigned char  MKWDTA0:1;                              /* MKWDTA0          */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFWDTA0:1;                              /* RFWDTA0          */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTWDTA0:1;                              /* CTWDTA0          */
};
struct __tag47
{                                                          /* Bit Access       */
    unsigned char  P0WDTA1:1;                              /* P0WDTA1          */
    unsigned char  P1WDTA1:1;                              /* P1WDTA1          */
    unsigned char  P2WDTA1:1;                              /* P2WDTA1          */
    unsigned char  P3WDTA1:1;                              /* P3WDTA1          */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBWDTA1:1;                              /* TBWDTA1          */
    unsigned char  MKWDTA1:1;                              /* MKWDTA1          */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFWDTA1:1;                              /* RFWDTA1          */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTWDTA1:1;                              /* CTWDTA1          */
};
struct __tag48
{                                                          /* Bit Access       */
    unsigned char  P0P3:1;                                 /* P0P3             */
    unsigned char  P1P3:1;                                 /* P1P3             */
    unsigned char  P2P3:1;                                 /* P2P3             */
    unsigned char  P3P3:1;                                 /* P3P3             */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBP3:1;                                 /* TBP3             */
    unsigned char  MKP3:1;                                 /* MKP3             */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFP3:1;                                 /* RFP3             */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTP3:1;                                 /* CTP3             */
};
struct __tag49
{                                                          /* Bit Access       */
    unsigned char  P0P4:1;                                 /* P0P4             */
    unsigned char  P1P4:1;                                 /* P1P4             */
    unsigned char  P2P4:1;                                 /* P2P4             */
    unsigned char  P3P4:1;                                 /* P3P4             */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBP4:1;                                 /* TBP4             */
    unsigned char  MKP4:1;                                 /* MKP4             */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFP4:1;                                 /* RFP4             */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTP4:1;                                 /* CTP4             */
};
struct __tag50
{                                                          /* Bit Access       */
    unsigned char  P0P5:1;                                 /* P0P5             */
    unsigned char  P1P5:1;                                 /* P1P5             */
    unsigned char  P2P5:1;                                 /* P2P5             */
    unsigned char  P3P5:1;                                 /* P3P5             */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBP5:1;                                 /* TBP5             */
    unsigned char  MKP5:1;                                 /* MKP5             */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFP5:1;                                 /* RFP5             */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTP5:1;                                 /* CTP5             */
};
struct __tag51
{                                                          /* Bit Access       */
    unsigned char  P0P10:1;                                /* P0P10            */
    unsigned char  P1P10:1;                                /* P1P10            */
    unsigned char  P2P10:1;                                /* P2P10            */
    unsigned char  P3P10:1;                                /* P3P10            */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBP10:1;                                /* TBP10            */
    unsigned char  MKP10:1;                                /* MKP10            */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFP10:1;                                /* RFP10            */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTP10:1;                                /* CTP10            */
};
struct __tag52
{                                                          /* Bit Access       */
    unsigned char  P0P11:1;                                /* P0P11            */
    unsigned char  P1P11:1;                                /* P1P11            */
    unsigned char  P2P11:1;                                /* P2P11            */
    unsigned char  P3P11:1;                                /* P3P11            */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBP11:1;                                /* TBP11            */
    unsigned char  MKP11:1;                                /* MKP11            */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFP11:1;                                /* RFP11            */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTP11:1;                                /* CTP11            */
};
struct __tag53
{                                                          /* Bit Access       */
    unsigned char  P0TAUD0I1:1;                            /* P0TAUD0I1        */
    unsigned char  P1TAUD0I1:1;                            /* P1TAUD0I1        */
    unsigned char  P2TAUD0I1:1;                            /* P2TAUD0I1        */
    unsigned char  P3TAUD0I1:1;                            /* P3TAUD0I1        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBTAUD0I1:1;                            /* TBTAUD0I1        */
    unsigned char  MKTAUD0I1:1;                            /* MKTAUD0I1        */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFTAUD0I1:1;                            /* RFTAUD0I1        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTTAUD0I1:1;                            /* CTTAUD0I1        */
};
struct __tag54
{                                                          /* Bit Access       */
    unsigned char  P0TAUD0I3:1;                            /* P0TAUD0I3        */
    unsigned char  P1TAUD0I3:1;                            /* P1TAUD0I3        */
    unsigned char  P2TAUD0I3:1;                            /* P2TAUD0I3        */
    unsigned char  P3TAUD0I3:1;                            /* P3TAUD0I3        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBTAUD0I3:1;                            /* TBTAUD0I3        */
    unsigned char  MKTAUD0I3:1;                            /* MKTAUD0I3        */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFTAUD0I3:1;                            /* RFTAUD0I3        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTTAUD0I3:1;                            /* CTTAUD0I3        */
};
struct __tag55
{                                                          /* Bit Access       */
    unsigned char  P0TAUD0I5:1;                            /* P0TAUD0I5        */
    unsigned char  P1TAUD0I5:1;                            /* P1TAUD0I5        */
    unsigned char  P2TAUD0I5:1;                            /* P2TAUD0I5        */
    unsigned char  P3TAUD0I5:1;                            /* P3TAUD0I5        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBTAUD0I5:1;                            /* TBTAUD0I5        */
    unsigned char  MKTAUD0I5:1;                            /* MKTAUD0I5        */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFTAUD0I5:1;                            /* RFTAUD0I5        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTTAUD0I5:1;                            /* CTTAUD0I5        */
};
struct __tag56
{                                                          /* Bit Access       */
    unsigned char  P0TAUD0I7:1;                            /* P0TAUD0I7        */
    unsigned char  P1TAUD0I7:1;                            /* P1TAUD0I7        */
    unsigned char  P2TAUD0I7:1;                            /* P2TAUD0I7        */
    unsigned char  P3TAUD0I7:1;                            /* P3TAUD0I7        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBTAUD0I7:1;                            /* TBTAUD0I7        */
    unsigned char  MKTAUD0I7:1;                            /* MKTAUD0I7        */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFTAUD0I7:1;                            /* RFTAUD0I7        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTTAUD0I7:1;                            /* CTTAUD0I7        */
};
struct __tag57
{                                                          /* Bit Access       */
    unsigned char  P0TAUD0I9:1;                            /* P0TAUD0I9        */
    unsigned char  P1TAUD0I9:1;                            /* P1TAUD0I9        */
    unsigned char  P2TAUD0I9:1;                            /* P2TAUD0I9        */
    unsigned char  P3TAUD0I9:1;                            /* P3TAUD0I9        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBTAUD0I9:1;                            /* TBTAUD0I9        */
    unsigned char  MKTAUD0I9:1;                            /* MKTAUD0I9        */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFTAUD0I9:1;                            /* RFTAUD0I9        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTTAUD0I9:1;                            /* CTTAUD0I9        */
};
struct __tag58
{                                                          /* Bit Access       */
    unsigned char  P0TAUD0I11:1;                           /* P0TAUD0I11       */
    unsigned char  P1TAUD0I11:1;                           /* P1TAUD0I11       */
    unsigned char  P2TAUD0I11:1;                           /* P2TAUD0I11       */
    unsigned char  P3TAUD0I11:1;                           /* P3TAUD0I11       */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBTAUD0I11:1;                           /* TBTAUD0I11       */
    unsigned char  MKTAUD0I11:1;                           /* MKTAUD0I11       */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFTAUD0I11:1;                           /* RFTAUD0I11       */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTTAUD0I11:1;                           /* CTTAUD0I11       */
};
struct __tag59
{                                                          /* Bit Access       */
    unsigned char  P0TAUD0I13:1;                           /* P0TAUD0I13       */
    unsigned char  P1TAUD0I13:1;                           /* P1TAUD0I13       */
    unsigned char  P2TAUD0I13:1;                           /* P2TAUD0I13       */
    unsigned char  P3TAUD0I13:1;                           /* P3TAUD0I13       */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBTAUD0I13:1;                           /* TBTAUD0I13       */
    unsigned char  MKTAUD0I13:1;                           /* MKTAUD0I13       */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFTAUD0I13:1;                           /* RFTAUD0I13       */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTTAUD0I13:1;                           /* CTTAUD0I13       */
};
struct __tag60
{                                                          /* Bit Access       */
    unsigned char  P0TAUD0I15:1;                           /* P0TAUD0I15       */
    unsigned char  P1TAUD0I15:1;                           /* P1TAUD0I15       */
    unsigned char  P2TAUD0I15:1;                           /* P2TAUD0I15       */
    unsigned char  P3TAUD0I15:1;                           /* P3TAUD0I15       */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBTAUD0I15:1;                           /* TBTAUD0I15       */
    unsigned char  MKTAUD0I15:1;                           /* MKTAUD0I15       */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFTAUD0I15:1;                           /* RFTAUD0I15       */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTTAUD0I15:1;                           /* CTTAUD0I15       */
};
struct __tag61
{                                                          /* Bit Access       */
    unsigned char  P0ADCA0ERR:1;                           /* P0ADCA0ERR       */
    unsigned char  P1ADCA0ERR:1;                           /* P1ADCA0ERR       */
    unsigned char  P2ADCA0ERR:1;                           /* P2ADCA0ERR       */
    unsigned char  P3ADCA0ERR:1;                           /* P3ADCA0ERR       */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBADCA0ERR:1;                           /* TBADCA0ERR       */
    unsigned char  MKADCA0ERR:1;                           /* MKADCA0ERR       */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFADCA0ERR:1;                           /* RFADCA0ERR       */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTADCA0ERR:1;                           /* CTADCA0ERR       */
};
struct __tag62
{                                                          /* Bit Access       */
    unsigned char  P0CSIG0IRE:1;                           /* P0CSIG0IRE       */
    unsigned char  P1CSIG0IRE:1;                           /* P1CSIG0IRE       */
    unsigned char  P2CSIG0IRE:1;                           /* P2CSIG0IRE       */
    unsigned char  P3CSIG0IRE:1;                           /* P3CSIG0IRE       */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBCSIG0IRE:1;                           /* TBCSIG0IRE       */
    unsigned char  MKCSIG0IRE:1;                           /* MKCSIG0IRE       */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFCSIG0IRE:1;                           /* RFCSIG0IRE       */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTCSIG0IRE:1;                           /* CTCSIG0IRE       */
};
struct __tag63
{                                                          /* Bit Access       */
    unsigned char  P0RLIN20:1;                             /* P0RLIN20         */
    unsigned char  P1RLIN20:1;                             /* P1RLIN20         */
    unsigned char  P2RLIN20:1;                             /* P2RLIN20         */
    unsigned char  P3RLIN20:1;                             /* P3RLIN20         */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBRLIN20:1;                             /* TBRLIN20         */
    unsigned char  MKRLIN20:1;                             /* MKRLIN20         */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFRLIN20:1;                             /* RFRLIN20         */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTRLIN20:1;                             /* CTRLIN20         */
};
struct __tag64
{                                                          /* Bit Access       */
    unsigned char  P0RLIN21:1;                             /* P0RLIN21         */
    unsigned char  P1RLIN21:1;                             /* P1RLIN21         */
    unsigned char  P2RLIN21:1;                             /* P2RLIN21         */
    unsigned char  P3RLIN21:1;                             /* P3RLIN21         */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBRLIN21:1;                             /* TBRLIN21         */
    unsigned char  MKRLIN21:1;                             /* MKRLIN21         */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFRLIN21:1;                             /* RFRLIN21         */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTRLIN21:1;                             /* CTRLIN21         */
};
struct __tag65
{                                                          /* Bit Access       */
    unsigned char  P0DMA0:1;                               /* P0DMA0           */
    unsigned char  P1DMA0:1;                               /* P1DMA0           */
    unsigned char  P2DMA0:1;                               /* P2DMA0           */
    unsigned char  P3DMA0:1;                               /* P3DMA0           */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBDMA0:1;                               /* TBDMA0           */
    unsigned char  MKDMA0:1;                               /* MKDMA0           */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFDMA0:1;                               /* RFDMA0           */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTDMA0:1;                               /* CTDMA0           */
};
struct __tag66
{                                                          /* Bit Access       */
    unsigned char  P0DMA1:1;                               /* P0DMA1           */
    unsigned char  P1DMA1:1;                               /* P1DMA1           */
    unsigned char  P2DMA1:1;                               /* P2DMA1           */
    unsigned char  P3DMA1:1;                               /* P3DMA1           */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBDMA1:1;                               /* TBDMA1           */
    unsigned char  MKDMA1:1;                               /* MKDMA1           */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFDMA1:1;                               /* RFDMA1           */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTDMA1:1;                               /* CTDMA1           */
};
struct __tag67
{                                                          /* Bit Access       */
    unsigned char  P0DMA2:1;                               /* P0DMA2           */
    unsigned char  P1DMA2:1;                               /* P1DMA2           */
    unsigned char  P2DMA2:1;                               /* P2DMA2           */
    unsigned char  P3DMA2:1;                               /* P3DMA2           */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBDMA2:1;                               /* TBDMA2           */
    unsigned char  MKDMA2:1;                               /* MKDMA2           */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFDMA2:1;                               /* RFDMA2           */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTDMA2:1;                               /* CTDMA2           */
};
struct __tag68
{                                                          /* Bit Access       */
    unsigned char  P0DMA3:1;                               /* P0DMA3           */
    unsigned char  P1DMA3:1;                               /* P1DMA3           */
    unsigned char  P2DMA3:1;                               /* P2DMA3           */
    unsigned char  P3DMA3:1;                               /* P3DMA3           */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBDMA3:1;                               /* TBDMA3           */
    unsigned char  MKDMA3:1;                               /* MKDMA3           */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFDMA3:1;                               /* RFDMA3           */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTDMA3:1;                               /* CTDMA3           */
};
struct __tag69
{                                                          /* Bit Access       */
    unsigned char  P0DMA4:1;                               /* P0DMA4           */
    unsigned char  P1DMA4:1;                               /* P1DMA4           */
    unsigned char  P2DMA4:1;                               /* P2DMA4           */
    unsigned char  P3DMA4:1;                               /* P3DMA4           */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBDMA4:1;                               /* TBDMA4           */
    unsigned char  MKDMA4:1;                               /* MKDMA4           */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFDMA4:1;                               /* RFDMA4           */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTDMA4:1;                               /* CTDMA4           */
};
struct __tag70
{                                                          /* Bit Access       */
    unsigned char  P0DMA5:1;                               /* P0DMA5           */
    unsigned char  P1DMA5:1;                               /* P1DMA5           */
    unsigned char  P2DMA5:1;                               /* P2DMA5           */
    unsigned char  P3DMA5:1;                               /* P3DMA5           */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBDMA5:1;                               /* TBDMA5           */
    unsigned char  MKDMA5:1;                               /* MKDMA5           */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFDMA5:1;                               /* RFDMA5           */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTDMA5:1;                               /* CTDMA5           */
};
struct __tag71
{                                                          /* Bit Access       */
    unsigned char  P0DMA6:1;                               /* P0DMA6           */
    unsigned char  P1DMA6:1;                               /* P1DMA6           */
    unsigned char  P2DMA6:1;                               /* P2DMA6           */
    unsigned char  P3DMA6:1;                               /* P3DMA6           */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBDMA6:1;                               /* TBDMA6           */
    unsigned char  MKDMA6:1;                               /* MKDMA6           */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFDMA6:1;                               /* RFDMA6           */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTDMA6:1;                               /* CTDMA6           */
};
struct __tag72
{                                                          /* Bit Access       */
    unsigned char  P0DMA7:1;                               /* P0DMA7           */
    unsigned char  P1DMA7:1;                               /* P1DMA7           */
    unsigned char  P2DMA7:1;                               /* P2DMA7           */
    unsigned char  P3DMA7:1;                               /* P3DMA7           */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBDMA7:1;                               /* TBDMA7           */
    unsigned char  MKDMA7:1;                               /* MKDMA7           */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFDMA7:1;                               /* RFDMA7           */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTDMA7:1;                               /* CTDMA7           */
};
struct __tag73
{                                                          /* Bit Access       */
    unsigned char  P0DMA8:1;                               /* P0DMA8           */
    unsigned char  P1DMA8:1;                               /* P1DMA8           */
    unsigned char  P2DMA8:1;                               /* P2DMA8           */
    unsigned char  P3DMA8:1;                               /* P3DMA8           */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBDMA8:1;                               /* TBDMA8           */
    unsigned char  MKDMA8:1;                               /* MKDMA8           */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFDMA8:1;                               /* RFDMA8           */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTDMA8:1;                               /* CTDMA8           */
};
struct __tag74
{                                                          /* Bit Access       */
    unsigned char  P0DMA9:1;                               /* P0DMA9           */
    unsigned char  P1DMA9:1;                               /* P1DMA9           */
    unsigned char  P2DMA9:1;                               /* P2DMA9           */
    unsigned char  P3DMA9:1;                               /* P3DMA9           */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBDMA9:1;                               /* TBDMA9           */
    unsigned char  MKDMA9:1;                               /* MKDMA9           */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFDMA9:1;                               /* RFDMA9           */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTDMA9:1;                               /* CTDMA9           */
};
struct __tag75
{                                                          /* Bit Access       */
    unsigned char  P0DMA10:1;                              /* P0DMA10          */
    unsigned char  P1DMA10:1;                              /* P1DMA10          */
    unsigned char  P2DMA10:1;                              /* P2DMA10          */
    unsigned char  P3DMA10:1;                              /* P3DMA10          */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBDMA10:1;                              /* TBDMA10          */
    unsigned char  MKDMA10:1;                              /* MKDMA10          */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFDMA10:1;                              /* RFDMA10          */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTDMA10:1;                              /* CTDMA10          */
};
struct __tag76
{                                                          /* Bit Access       */
    unsigned char  P0DMA11:1;                              /* P0DMA11          */
    unsigned char  P1DMA11:1;                              /* P1DMA11          */
    unsigned char  P2DMA11:1;                              /* P2DMA11          */
    unsigned char  P3DMA11:1;                              /* P3DMA11          */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBDMA11:1;                              /* TBDMA11          */
    unsigned char  MKDMA11:1;                              /* MKDMA11          */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFDMA11:1;                              /* RFDMA11          */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTDMA11:1;                              /* CTDMA11          */
};
struct __tag77
{                                                          /* Bit Access       */
    unsigned char  P0DMA12:1;                              /* P0DMA12          */
    unsigned char  P1DMA12:1;                              /* P1DMA12          */
    unsigned char  P2DMA12:1;                              /* P2DMA12          */
    unsigned char  P3DMA12:1;                              /* P3DMA12          */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBDMA12:1;                              /* TBDMA12          */
    unsigned char  MKDMA12:1;                              /* MKDMA12          */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFDMA12:1;                              /* RFDMA12          */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTDMA12:1;                              /* CTDMA12          */
};
struct __tag78
{                                                          /* Bit Access       */
    unsigned char  P0DMA13:1;                              /* P0DMA13          */
    unsigned char  P1DMA13:1;                              /* P1DMA13          */
    unsigned char  P2DMA13:1;                              /* P2DMA13          */
    unsigned char  P3DMA13:1;                              /* P3DMA13          */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBDMA13:1;                              /* TBDMA13          */
    unsigned char  MKDMA13:1;                              /* MKDMA13          */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFDMA13:1;                              /* RFDMA13          */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTDMA13:1;                              /* CTDMA13          */
};
struct __tag79
{                                                          /* Bit Access       */
    unsigned char  P0DMA14:1;                              /* P0DMA14          */
    unsigned char  P1DMA14:1;                              /* P1DMA14          */
    unsigned char  P2DMA14:1;                              /* P2DMA14          */
    unsigned char  P3DMA14:1;                              /* P3DMA14          */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBDMA14:1;                              /* TBDMA14          */
    unsigned char  MKDMA14:1;                              /* MKDMA14          */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFDMA14:1;                              /* RFDMA14          */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTDMA14:1;                              /* CTDMA14          */
};
struct __tag80
{                                                          /* Bit Access       */
    unsigned char  P0DMA15:1;                              /* P0DMA15          */
    unsigned char  P1DMA15:1;                              /* P1DMA15          */
    unsigned char  P2DMA15:1;                              /* P2DMA15          */
    unsigned char  P3DMA15:1;                              /* P3DMA15          */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBDMA15:1;                              /* TBDMA15          */
    unsigned char  MKDMA15:1;                              /* MKDMA15          */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFDMA15:1;                              /* RFDMA15          */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTDMA15:1;                              /* CTDMA15          */
};
struct __tag81
{                                                          /* Bit Access       */
    unsigned char  P0RIIC0TI:1;                            /* P0RIIC0TI        */
    unsigned char  P1RIIC0TI:1;                            /* P1RIIC0TI        */
    unsigned char  P2RIIC0TI:1;                            /* P2RIIC0TI        */
    unsigned char  P3RIIC0TI:1;                            /* P3RIIC0TI        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBRIIC0TI:1;                            /* TBRIIC0TI        */
    unsigned char  MKRIIC0TI:1;                            /* MKRIIC0TI        */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFRIIC0TI:1;                            /* RFRIIC0TI        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTRIIC0TI:1;                            /* CTRIIC0TI        */
};
struct __tag82
{                                                          /* Bit Access       */
    unsigned char  P0RIIC0EE:1;                            /* P0RIIC0EE        */
    unsigned char  P1RIIC0EE:1;                            /* P1RIIC0EE        */
    unsigned char  P2RIIC0EE:1;                            /* P2RIIC0EE        */
    unsigned char  P3RIIC0EE:1;                            /* P3RIIC0EE        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBRIIC0EE:1;                            /* TBRIIC0EE        */
    unsigned char  MKRIIC0EE:1;                            /* MKRIIC0EE        */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFRIIC0EE:1;                            /* RFRIIC0EE        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTRIIC0EE:1;                            /* CTRIIC0EE        */
};
struct __tag83
{                                                          /* Bit Access       */
    unsigned char  P0RIIC0RI:1;                            /* P0RIIC0RI        */
    unsigned char  P1RIIC0RI:1;                            /* P1RIIC0RI        */
    unsigned char  P2RIIC0RI:1;                            /* P2RIIC0RI        */
    unsigned char  P3RIIC0RI:1;                            /* P3RIIC0RI        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBRIIC0RI:1;                            /* TBRIIC0RI        */
    unsigned char  MKRIIC0RI:1;                            /* MKRIIC0RI        */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFRIIC0RI:1;                            /* RFRIIC0RI        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTRIIC0RI:1;                            /* CTRIIC0RI        */
};
struct __tag84
{                                                          /* Bit Access       */
    unsigned char  P0RIIC0TEI:1;                           /* P0RIIC0TEI       */
    unsigned char  P1RIIC0TEI:1;                           /* P1RIIC0TEI       */
    unsigned char  P2RIIC0TEI:1;                           /* P2RIIC0TEI       */
    unsigned char  P3RIIC0TEI:1;                           /* P3RIIC0TEI       */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBRIIC0TEI:1;                           /* TBRIIC0TEI       */
    unsigned char  MKRIIC0TEI:1;                           /* MKRIIC0TEI       */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFRIIC0TEI:1;                           /* RFRIIC0TEI       */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTRIIC0TEI:1;                           /* CTRIIC0TEI       */
};
struct __tag85
{                                                          /* Bit Access       */
    unsigned char  P0TAUJ0I0:1;                            /* P0TAUJ0I0        */
    unsigned char  P1TAUJ0I0:1;                            /* P1TAUJ0I0        */
    unsigned char  P2TAUJ0I0:1;                            /* P2TAUJ0I0        */
    unsigned char  P3TAUJ0I0:1;                            /* P3TAUJ0I0        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBTAUJ0I0:1;                            /* TBTAUJ0I0        */
    unsigned char  MKTAUJ0I0:1;                            /* MKTAUJ0I0        */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFTAUJ0I0:1;                            /* RFTAUJ0I0        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTTAUJ0I0:1;                            /* CTTAUJ0I0        */
};
struct __tag86
{                                                          /* Bit Access       */
    unsigned char  P0TAUJ0I1:1;                            /* P0TAUJ0I1        */
    unsigned char  P1TAUJ0I1:1;                            /* P1TAUJ0I1        */
    unsigned char  P2TAUJ0I1:1;                            /* P2TAUJ0I1        */
    unsigned char  P3TAUJ0I1:1;                            /* P3TAUJ0I1        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBTAUJ0I1:1;                            /* TBTAUJ0I1        */
    unsigned char  MKTAUJ0I1:1;                            /* MKTAUJ0I1        */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFTAUJ0I1:1;                            /* RFTAUJ0I1        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTTAUJ0I1:1;                            /* CTTAUJ0I1        */
};
struct __tag87
{                                                          /* Bit Access       */
    unsigned char  P0TAUJ0I2:1;                            /* P0TAUJ0I2        */
    unsigned char  P1TAUJ0I2:1;                            /* P1TAUJ0I2        */
    unsigned char  P2TAUJ0I2:1;                            /* P2TAUJ0I2        */
    unsigned char  P3TAUJ0I2:1;                            /* P3TAUJ0I2        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBTAUJ0I2:1;                            /* TBTAUJ0I2        */
    unsigned char  MKTAUJ0I2:1;                            /* MKTAUJ0I2        */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFTAUJ0I2:1;                            /* RFTAUJ0I2        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTTAUJ0I2:1;                            /* CTTAUJ0I2        */
};
struct __tag88
{                                                          /* Bit Access       */
    unsigned char  P0TAUJ0I3:1;                            /* P0TAUJ0I3        */
    unsigned char  P1TAUJ0I3:1;                            /* P1TAUJ0I3        */
    unsigned char  P2TAUJ0I3:1;                            /* P2TAUJ0I3        */
    unsigned char  P3TAUJ0I3:1;                            /* P3TAUJ0I3        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBTAUJ0I3:1;                            /* TBTAUJ0I3        */
    unsigned char  MKTAUJ0I3:1;                            /* MKTAUJ0I3        */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFTAUJ0I3:1;                            /* RFTAUJ0I3        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTTAUJ0I3:1;                            /* CTTAUJ0I3        */
};
struct __tag89
{                                                          /* Bit Access       */
    unsigned char  P0OSTM0:1;                              /* P0OSTM0          */
    unsigned char  P1OSTM0:1;                              /* P1OSTM0          */
    unsigned char  P2OSTM0:1;                              /* P2OSTM0          */
    unsigned char  P3OSTM0:1;                              /* P3OSTM0          */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBOSTM0:1;                              /* TBOSTM0          */
    unsigned char  MKOSTM0:1;                              /* MKOSTM0          */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFOSTM0:1;                              /* RFOSTM0          */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTOSTM0:1;                              /* CTOSTM0          */
};
struct __tag90
{                                                          /* Bit Access       */
    unsigned char  P0ENCA0IOV:1;                           /* P0ENCA0IOV       */
    unsigned char  P1ENCA0IOV:1;                           /* P1ENCA0IOV       */
    unsigned char  P2ENCA0IOV:1;                           /* P2ENCA0IOV       */
    unsigned char  P3ENCA0IOV:1;                           /* P3ENCA0IOV       */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBENCA0IOV:1;                           /* TBENCA0IOV       */
    unsigned char  MKENCA0IOV:1;                           /* MKENCA0IOV       */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFENCA0IOV:1;                           /* RFENCA0IOV       */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTENCA0IOV:1;                           /* CTENCA0IOV       */
};
struct __tag91
{                                                          /* Bit Access       */
    unsigned char  P0ENCA0IUD:1;                           /* P0ENCA0IUD       */
    unsigned char  P1ENCA0IUD:1;                           /* P1ENCA0IUD       */
    unsigned char  P2ENCA0IUD:1;                           /* P2ENCA0IUD       */
    unsigned char  P3ENCA0IUD:1;                           /* P3ENCA0IUD       */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBENCA0IUD:1;                           /* TBENCA0IUD       */
    unsigned char  MKENCA0IUD:1;                           /* MKENCA0IUD       */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFENCA0IUD:1;                           /* RFENCA0IUD       */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTENCA0IUD:1;                           /* CTENCA0IUD       */
};
struct __tag92
{                                                          /* Bit Access       */
    unsigned char  P0ENCA0I0:1;                            /* P0ENCA0I0        */
    unsigned char  P1ENCA0I0:1;                            /* P1ENCA0I0        */
    unsigned char  P2ENCA0I0:1;                            /* P2ENCA0I0        */
    unsigned char  P3ENCA0I0:1;                            /* P3ENCA0I0        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBENCA0I0:1;                            /* TBENCA0I0        */
    unsigned char  MKENCA0I0:1;                            /* MKENCA0I0        */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFENCA0I0:1;                            /* RFENCA0I0        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTENCA0I0:1;                            /* CTENCA0I0        */
};
struct __tag93
{                                                          /* Bit Access       */
    unsigned char  P0ENCA0I1:1;                            /* P0ENCA0I1        */
    unsigned char  P1ENCA0I1:1;                            /* P1ENCA0I1        */
    unsigned char  P2ENCA0I1:1;                            /* P2ENCA0I1        */
    unsigned char  P3ENCA0I1:1;                            /* P3ENCA0I1        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBENCA0I1:1;                            /* TBENCA0I1        */
    unsigned char  MKENCA0I1:1;                            /* MKENCA0I1        */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFENCA0I1:1;                            /* RFENCA0I1        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTENCA0I1:1;                            /* CTENCA0I1        */
};
struct __tag94
{                                                          /* Bit Access       */
    unsigned char  P0ENCA0IEC:1;                           /* P0ENCA0IEC       */
    unsigned char  P1ENCA0IEC:1;                           /* P1ENCA0IEC       */
    unsigned char  P2ENCA0IEC:1;                           /* P2ENCA0IEC       */
    unsigned char  P3ENCA0IEC:1;                           /* P3ENCA0IEC       */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBENCA0IEC:1;                           /* TBENCA0IEC       */
    unsigned char  MKENCA0IEC:1;                           /* MKENCA0IEC       */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFENCA0IEC:1;                           /* RFENCA0IEC       */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTENCA0IEC:1;                           /* CTENCA0IEC       */
};
struct __tag95
{                                                          /* Bit Access       */
    unsigned char  P0KR0:1;                                /* P0KR0            */
    unsigned char  P1KR0:1;                                /* P1KR0            */
    unsigned char  P2KR0:1;                                /* P2KR0            */
    unsigned char  P3KR0:1;                                /* P3KR0            */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBKR0:1;                                /* TBKR0            */
    unsigned char  MKKR0:1;                                /* MKKR0            */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFKR0:1;                                /* RFKR0            */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTKR0:1;                                /* CTKR0            */
};
struct __tag96
{                                                          /* Bit Access       */
    unsigned char  P0QFULL:1;                              /* P0QFULL          */
    unsigned char  P1QFULL:1;                              /* P1QFULL          */
    unsigned char  P2QFULL:1;                              /* P2QFULL          */
    unsigned char  P3QFULL:1;                              /* P3QFULL          */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBQFULL:1;                              /* TBQFULL          */
    unsigned char  MKQFULL:1;                              /* MKQFULL          */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFQFULL:1;                              /* RFQFULL          */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTQFULL:1;                              /* CTQFULL          */
};
struct __tag97
{                                                          /* Bit Access       */
    unsigned char  P0PWGAG00:1;                            /* P0PWGAG00        */
    unsigned char  P1PWGAG00:1;                            /* P1PWGAG00        */
    unsigned char  P2PWGAG00:1;                            /* P2PWGAG00        */
    unsigned char  P3PWGAG00:1;                            /* P3PWGAG00        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBPWGAG00:1;                            /* TBPWGAG00        */
    unsigned char  MKPWGAG00:1;                            /* MKPWGAG00        */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFPWGAG00:1;                            /* RFPWGAG00        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTPWGAG00:1;                            /* CTPWGAG00        */
};
struct __tag98
{                                                          /* Bit Access       */
    unsigned char  P0FLERR:1;                              /* P0FLERR          */
    unsigned char  P1FLERR:1;                              /* P1FLERR          */
    unsigned char  P2FLERR:1;                              /* P2FLERR          */
    unsigned char  P3FLERR:1;                              /* P3FLERR          */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBFLERR:1;                              /* TBFLERR          */
    unsigned char  MKFLERR:1;                              /* MKFLERR          */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFFLERR:1;                              /* RFFLERR          */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTFLERR:1;                              /* CTFLERR          */
};
struct __tag99
{                                                          /* Bit Access       */
    unsigned char  P0FLENDNM:1;                            /* P0FLENDNM        */
    unsigned char  P1FLENDNM:1;                            /* P1FLENDNM        */
    unsigned char  P2FLENDNM:1;                            /* P2FLENDNM        */
    unsigned char  P3FLENDNM:1;                            /* P3FLENDNM        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBFLENDNM:1;                            /* TBFLENDNM        */
    unsigned char  MKFLENDNM:1;                            /* MKFLENDNM        */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFFLENDNM:1;                            /* RFFLENDNM        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTFLENDNM:1;                            /* CTFLENDNM        */
};
struct __tag100
{                                                          /* Bit Access       */
    unsigned char  P0CWEND:1;                              /* P0CWEND          */
    unsigned char  P1CWEND:1;                              /* P1CWEND          */
    unsigned char  P2CWEND:1;                              /* P2CWEND          */
    unsigned char  P3CWEND:1;                              /* P3CWEND          */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBCWEND:1;                              /* TBCWEND          */
    unsigned char  MKCWEND:1;                              /* MKCWEND          */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFCWEND:1;                              /* RFCWEND          */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTCWEND:1;                              /* CTCWEND          */
};
struct __tag101
{                                                          /* Bit Access       */
    unsigned char  P0TAPA0IPEK0_2:1;                       /* P0TAPA0IPEK0_2   */
    unsigned char  P1TAPA0IPEK0_2:1;                       /* P1TAPA0IPEK0_2   */
    unsigned char  P2TAPA0IPEK0_2:1;                       /* P2TAPA0IPEK0_2   */
    unsigned char  P3TAPA0IPEK0_2:1;                       /* P3TAPA0IPEK0_2   */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBTAPA0IPEK0_2:1;                       /* TBTAPA0IPEK0_2   */
    unsigned char  MKTAPA0IPEK0_2:1;                       /* MKTAPA0IPEK0_2   */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFTAPA0IPEK0_2:1;                       /* RFTAPA0IPEK0_2   */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTTAPA0IPEK0_2:1;                       /* CTTAPA0IPEK0_2   */
};
struct __tag102
{                                                          /* Bit Access       */
    unsigned char  P0TAPA0IVLY0_2:1;                       /* P0TAPA0IVLY0_2   */
    unsigned char  P1TAPA0IVLY0_2:1;                       /* P1TAPA0IVLY0_2   */
    unsigned char  P2TAPA0IVLY0_2:1;                       /* P2TAPA0IVLY0_2   */
    unsigned char  P3TAPA0IVLY0_2:1;                       /* P3TAPA0IVLY0_2   */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBTAPA0IVLY0_2:1;                       /* TBTAPA0IVLY0_2   */
    unsigned char  MKTAPA0IVLY0_2:1;                       /* MKTAPA0IVLY0_2   */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFTAPA0IVLY0_2:1;                       /* RFTAPA0IVLY0_2   */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTTAPA0IVLY0_2:1;                       /* CTTAPA0IVLY0_2   */
};
struct __tag103
{                                                          /* Bit Access       */
    unsigned char  P0CSIG0IC_2:1;                          /* P0CSIG0IC_2      */
    unsigned char  P1CSIG0IC_2:1;                          /* P1CSIG0IC_2      */
    unsigned char  P2CSIG0IC_2:1;                          /* P2CSIG0IC_2      */
    unsigned char  P3CSIG0IC_2:1;                          /* P3CSIG0IC_2      */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBCSIG0IC_2:1;                          /* TBCSIG0IC_2      */
    unsigned char  MKCSIG0IC_2:1;                          /* MKCSIG0IC_2      */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFCSIG0IC_2:1;                          /* RFCSIG0IC_2      */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTCSIG0IC_2:1;                          /* CTCSIG0IC_2      */
};
struct __tag104
{                                                          /* Bit Access       */
    unsigned char  P0CSIG0IR_2:1;                          /* P0CSIG0IR_2      */
    unsigned char  P1CSIG0IR_2:1;                          /* P1CSIG0IR_2      */
    unsigned char  P2CSIG0IR_2:1;                          /* P2CSIG0IR_2      */
    unsigned char  P3CSIG0IR_2:1;                          /* P3CSIG0IR_2      */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBCSIG0IR_2:1;                          /* TBCSIG0IR_2      */
    unsigned char  MKCSIG0IR_2:1;                          /* MKCSIG0IR_2      */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFCSIG0IR_2:1;                          /* RFCSIG0IR_2      */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTCSIG0IR_2:1;                          /* CTCSIG0IR_2      */
};
struct __tag105
{                                                          /* Bit Access       */
    unsigned char  P0TAUD0I0_2:1;                          /* P0TAUD0I0_2      */
    unsigned char  P1TAUD0I0_2:1;                          /* P1TAUD0I0_2      */
    unsigned char  P2TAUD0I0_2:1;                          /* P2TAUD0I0_2      */
    unsigned char  P3TAUD0I0_2:1;                          /* P3TAUD0I0_2      */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBTAUD0I0_2:1;                          /* TBTAUD0I0_2      */
    unsigned char  MKTAUD0I0_2:1;                          /* MKTAUD0I0_2      */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFTAUD0I0_2:1;                          /* RFTAUD0I0_2      */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTTAUD0I0_2:1;                          /* CTTAUD0I0_2      */
};
struct __tag106
{                                                          /* Bit Access       */
    unsigned char  P0TAUD0I4_2:1;                          /* P0TAUD0I4_2      */
    unsigned char  P1TAUD0I4_2:1;                          /* P1TAUD0I4_2      */
    unsigned char  P2TAUD0I4_2:1;                          /* P2TAUD0I4_2      */
    unsigned char  P3TAUD0I4_2:1;                          /* P3TAUD0I4_2      */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBTAUD0I4_2:1;                          /* TBTAUD0I4_2      */
    unsigned char  MKTAUD0I4_2:1;                          /* MKTAUD0I4_2      */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFTAUD0I4_2:1;                          /* RFTAUD0I4_2      */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTTAUD0I4_2:1;                          /* CTTAUD0I4_2      */
};
struct __tag107
{                                                          /* Bit Access       */
    unsigned char  P0TAUD0I6_2:1;                          /* P0TAUD0I6_2      */
    unsigned char  P1TAUD0I6_2:1;                          /* P1TAUD0I6_2      */
    unsigned char  P2TAUD0I6_2:1;                          /* P2TAUD0I6_2      */
    unsigned char  P3TAUD0I6_2:1;                          /* P3TAUD0I6_2      */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBTAUD0I6_2:1;                          /* TBTAUD0I6_2      */
    unsigned char  MKTAUD0I6_2:1;                          /* MKTAUD0I6_2      */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFTAUD0I6_2:1;                          /* RFTAUD0I6_2      */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTTAUD0I6_2:1;                          /* CTTAUD0I6_2      */
};
struct __tag108
{                                                          /* Bit Access       */
    unsigned char  P0TAUD0I8_2:1;                          /* P0TAUD0I8_2      */
    unsigned char  P1TAUD0I8_2:1;                          /* P1TAUD0I8_2      */
    unsigned char  P2TAUD0I8_2:1;                          /* P2TAUD0I8_2      */
    unsigned char  P3TAUD0I8_2:1;                          /* P3TAUD0I8_2      */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBTAUD0I8_2:1;                          /* TBTAUD0I8_2      */
    unsigned char  MKTAUD0I8_2:1;                          /* MKTAUD0I8_2      */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFTAUD0I8_2:1;                          /* RFTAUD0I8_2      */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTTAUD0I8_2:1;                          /* CTTAUD0I8_2      */
};
struct __tag109
{                                                          /* Bit Access       */
    unsigned char  P0TAUD0I2_2:1;                          /* P0TAUD0I2_2      */
    unsigned char  P1TAUD0I2_2:1;                          /* P1TAUD0I2_2      */
    unsigned char  P2TAUD0I2_2:1;                          /* P2TAUD0I2_2      */
    unsigned char  P3TAUD0I2_2:1;                          /* P3TAUD0I2_2      */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBTAUD0I2_2:1;                          /* TBTAUD0I2_2      */
    unsigned char  MKTAUD0I2_2:1;                          /* MKTAUD0I2_2      */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFTAUD0I2_2:1;                          /* RFTAUD0I2_2      */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTTAUD0I2_2:1;                          /* CTTAUD0I2_2      */
};
struct __tag110
{                                                          /* Bit Access       */
    unsigned char  P0TAUD0I10_2:1;                         /* P0TAUD0I10_2     */
    unsigned char  P1TAUD0I10_2:1;                         /* P1TAUD0I10_2     */
    unsigned char  P2TAUD0I10_2:1;                         /* P2TAUD0I10_2     */
    unsigned char  P3TAUD0I10_2:1;                         /* P3TAUD0I10_2     */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBTAUD0I10_2:1;                         /* TBTAUD0I10_2     */
    unsigned char  MKTAUD0I10_2:1;                         /* MKTAUD0I10_2     */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFTAUD0I10_2:1;                         /* RFTAUD0I10_2     */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTTAUD0I10_2:1;                         /* CTTAUD0I10_2     */
};
struct __tag111
{                                                          /* Bit Access       */
    unsigned char  P0TAUD0I12_2:1;                         /* P0TAUD0I12_2     */
    unsigned char  P1TAUD0I12_2:1;                         /* P1TAUD0I12_2     */
    unsigned char  P2TAUD0I12_2:1;                         /* P2TAUD0I12_2     */
    unsigned char  P3TAUD0I12_2:1;                         /* P3TAUD0I12_2     */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBTAUD0I12_2:1;                         /* TBTAUD0I12_2     */
    unsigned char  MKTAUD0I12_2:1;                         /* MKTAUD0I12_2     */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFTAUD0I12_2:1;                         /* RFTAUD0I12_2     */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTTAUD0I12_2:1;                         /* CTTAUD0I12_2     */
};
struct __tag112
{                                                          /* Bit Access       */
    unsigned char  P0TAUD0I14_2:1;                         /* P0TAUD0I14_2     */
    unsigned char  P1TAUD0I14_2:1;                         /* P1TAUD0I14_2     */
    unsigned char  P2TAUD0I14_2:1;                         /* P2TAUD0I14_2     */
    unsigned char  P3TAUD0I14_2:1;                         /* P3TAUD0I14_2     */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBTAUD0I14_2:1;                         /* TBTAUD0I14_2     */
    unsigned char  MKTAUD0I14_2:1;                         /* MKTAUD0I14_2     */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFTAUD0I14_2:1;                         /* RFTAUD0I14_2     */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTTAUD0I14_2:1;                         /* CTTAUD0I14_2     */
};
struct __tag113
{                                                          /* Bit Access       */
    unsigned char  P0TAUJ1I0:1;                            /* P0TAUJ1I0        */
    unsigned char  P1TAUJ1I0:1;                            /* P1TAUJ1I0        */
    unsigned char  P2TAUJ1I0:1;                            /* P2TAUJ1I0        */
    unsigned char  P3TAUJ1I0:1;                            /* P3TAUJ1I0        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBTAUJ1I0:1;                            /* TBTAUJ1I0        */
    unsigned char  MKTAUJ1I0:1;                            /* MKTAUJ1I0        */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFTAUJ1I0:1;                            /* RFTAUJ1I0        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTTAUJ1I0:1;                            /* CTTAUJ1I0        */
};
struct __tag114
{                                                          /* Bit Access       */
    unsigned char  P0TAUJ1I1:1;                            /* P0TAUJ1I1        */
    unsigned char  P1TAUJ1I1:1;                            /* P1TAUJ1I1        */
    unsigned char  P2TAUJ1I1:1;                            /* P2TAUJ1I1        */
    unsigned char  P3TAUJ1I1:1;                            /* P3TAUJ1I1        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBTAUJ1I1:1;                            /* TBTAUJ1I1        */
    unsigned char  MKTAUJ1I1:1;                            /* MKTAUJ1I1        */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFTAUJ1I1:1;                            /* RFTAUJ1I1        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTTAUJ1I1:1;                            /* CTTAUJ1I1        */
};
struct __tag115
{                                                          /* Bit Access       */
    unsigned char  P0TAUJ1I2:1;                            /* P0TAUJ1I2        */
    unsigned char  P1TAUJ1I2:1;                            /* P1TAUJ1I2        */
    unsigned char  P2TAUJ1I2:1;                            /* P2TAUJ1I2        */
    unsigned char  P3TAUJ1I2:1;                            /* P3TAUJ1I2        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBTAUJ1I2:1;                            /* TBTAUJ1I2        */
    unsigned char  MKTAUJ1I2:1;                            /* MKTAUJ1I2        */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFTAUJ1I2:1;                            /* RFTAUJ1I2        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTTAUJ1I2:1;                            /* CTTAUJ1I2        */
};
struct __tag116
{                                                          /* Bit Access       */
    unsigned char  P0TAUJ1I3:1;                            /* P0TAUJ1I3        */
    unsigned char  P1TAUJ1I3:1;                            /* P1TAUJ1I3        */
    unsigned char  P2TAUJ1I3:1;                            /* P2TAUJ1I3        */
    unsigned char  P3TAUJ1I3:1;                            /* P3TAUJ1I3        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBTAUJ1I3:1;                            /* TBTAUJ1I3        */
    unsigned char  MKTAUJ1I3:1;                            /* MKTAUJ1I3        */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFTAUJ1I3:1;                            /* RFTAUJ1I3        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTTAUJ1I3:1;                            /* CTTAUJ1I3        */
};
struct __tag117
{                                                          /* Bit Access       */
    unsigned char  P0RTCA01S:1;                            /* P0RTCA01S        */
    unsigned char  P1RTCA01S:1;                            /* P1RTCA01S        */
    unsigned char  P2RTCA01S:1;                            /* P2RTCA01S        */
    unsigned char  P3RTCA01S:1;                            /* P3RTCA01S        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBRTCA01S:1;                            /* TBRTCA01S        */
    unsigned char  MKRTCA01S:1;                            /* MKRTCA01S        */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFRTCA01S:1;                            /* RFRTCA01S        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTRTCA01S:1;                            /* CTRTCA01S        */
};
struct __tag118
{                                                          /* Bit Access       */
    unsigned char  P0RTCA0AL:1;                            /* P0RTCA0AL        */
    unsigned char  P1RTCA0AL:1;                            /* P1RTCA0AL        */
    unsigned char  P2RTCA0AL:1;                            /* P2RTCA0AL        */
    unsigned char  P3RTCA0AL:1;                            /* P3RTCA0AL        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBRTCA0AL:1;                            /* TBRTCA0AL        */
    unsigned char  MKRTCA0AL:1;                            /* MKRTCA0AL        */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFRTCA0AL:1;                            /* RFRTCA0AL        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTRTCA0AL:1;                            /* CTRTCA0AL        */
};
struct __tag119
{                                                          /* Bit Access       */
    unsigned char  P0RTCA0R:1;                             /* P0RTCA0R         */
    unsigned char  P1RTCA0R:1;                             /* P1RTCA0R         */
    unsigned char  P2RTCA0R:1;                             /* P2RTCA0R         */
    unsigned char  P3RTCA0R:1;                             /* P3RTCA0R         */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBRTCA0R:1;                             /* TBRTCA0R         */
    unsigned char  MKRTCA0R:1;                             /* MKRTCA0R         */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFRTCA0R:1;                             /* RFRTCA0R         */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTRTCA0R:1;                             /* CTRTCA0R         */
};
struct __tag120
{                                                          /* Bit Access       */
    unsigned char  P0RIIC1TI:1;                            /* P0RIIC1TI        */
    unsigned char  P1RIIC1TI:1;                            /* P1RIIC1TI        */
    unsigned char  P2RIIC1TI:1;                            /* P2RIIC1TI        */
    unsigned char  P3RIIC1TI:1;                            /* P3RIIC1TI        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBRIIC1TI:1;                            /* TBRIIC1TI        */
    unsigned char  MKRIIC1TI:1;                            /* MKRIIC1TI        */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFRIIC1TI:1;                            /* RFRIIC1TI        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTRIIC1TI:1;                            /* CTRIIC1TI        */
};
struct __tag121
{                                                          /* Bit Access       */
    unsigned char  P0RIIC1EE:1;                            /* P0RIIC1EE        */
    unsigned char  P1RIIC1EE:1;                            /* P1RIIC1EE        */
    unsigned char  P2RIIC1EE:1;                            /* P2RIIC1EE        */
    unsigned char  P3RIIC1EE:1;                            /* P3RIIC1EE        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBRIIC1EE:1;                            /* TBRIIC1EE        */
    unsigned char  MKRIIC1EE:1;                            /* MKRIIC1EE        */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFRIIC1EE:1;                            /* RFRIIC1EE        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTRIIC1EE:1;                            /* CTRIIC1EE        */
};
struct __tag122
{                                                          /* Bit Access       */
    unsigned char  P0RIIC1RI:1;                            /* P0RIIC1RI        */
    unsigned char  P1RIIC1RI:1;                            /* P1RIIC1RI        */
    unsigned char  P2RIIC1RI:1;                            /* P2RIIC1RI        */
    unsigned char  P3RIIC1RI:1;                            /* P3RIIC1RI        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBRIIC1RI:1;                            /* TBRIIC1RI        */
    unsigned char  MKRIIC1RI:1;                            /* MKRIIC1RI        */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFRIIC1RI:1;                            /* RFRIIC1RI        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTRIIC1RI:1;                            /* CTRIIC1RI        */
};
struct __tag123
{                                                          /* Bit Access       */
    unsigned char  P0RIIC1TEI:1;                           /* P0RIIC1TEI       */
    unsigned char  P1RIIC1TEI:1;                           /* P1RIIC1TEI       */
    unsigned char  P2RIIC1TEI:1;                           /* P2RIIC1TEI       */
    unsigned char  P3RIIC1TEI:1;                           /* P3RIIC1TEI       */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBRIIC1TEI:1;                           /* TBRIIC1TEI       */
    unsigned char  MKRIIC1TEI:1;                           /* MKRIIC1TEI       */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFRIIC1TEI:1;                           /* RFRIIC1TEI       */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTRIIC1TEI:1;                           /* CTRIIC1TEI       */
};
struct __tag124
{                                                          /* Bit Access       */
    unsigned char  P0TAUJ2I0:1;                            /* P0TAUJ2I0        */
    unsigned char  P1TAUJ2I0:1;                            /* P1TAUJ2I0        */
    unsigned char  P2TAUJ2I0:1;                            /* P2TAUJ2I0        */
    unsigned char  P3TAUJ2I0:1;                            /* P3TAUJ2I0        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBTAUJ2I0:1;                            /* TBTAUJ2I0        */
    unsigned char  MKTAUJ2I0:1;                            /* MKTAUJ2I0        */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFTAUJ2I0:1;                            /* RFTAUJ2I0        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTTAUJ2I0:1;                            /* CTTAUJ2I0        */
};
struct __tag125
{                                                          /* Bit Access       */
    unsigned char  P0TAUJ2I1:1;                            /* P0TAUJ2I1        */
    unsigned char  P1TAUJ2I1:1;                            /* P1TAUJ2I1        */
    unsigned char  P2TAUJ2I1:1;                            /* P2TAUJ2I1        */
    unsigned char  P3TAUJ2I1:1;                            /* P3TAUJ2I1        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBTAUJ2I1:1;                            /* TBTAUJ2I1        */
    unsigned char  MKTAUJ2I1:1;                            /* MKTAUJ2I1        */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFTAUJ2I1:1;                            /* RFTAUJ2I1        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTTAUJ2I1:1;                            /* CTTAUJ2I1        */
};
struct __tag126
{                                                          /* Bit Access       */
    unsigned char  P0TAUJ2I2:1;                            /* P0TAUJ2I2        */
    unsigned char  P1TAUJ2I2:1;                            /* P1TAUJ2I2        */
    unsigned char  P2TAUJ2I2:1;                            /* P2TAUJ2I2        */
    unsigned char  P3TAUJ2I2:1;                            /* P3TAUJ2I2        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBTAUJ2I2:1;                            /* TBTAUJ2I2        */
    unsigned char  MKTAUJ2I2:1;                            /* MKTAUJ2I2        */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFTAUJ2I2:1;                            /* RFTAUJ2I2        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTTAUJ2I2:1;                            /* CTTAUJ2I2        */
};
struct __tag127
{                                                          /* Bit Access       */
    unsigned char  P0TAUJ2I3:1;                            /* P0TAUJ2I3        */
    unsigned char  P1TAUJ2I3:1;                            /* P1TAUJ2I3        */
    unsigned char  P2TAUJ2I3:1;                            /* P2TAUJ2I3        */
    unsigned char  P3TAUJ2I3:1;                            /* P3TAUJ2I3        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBTAUJ2I3:1;                            /* TBTAUJ2I3        */
    unsigned char  MKTAUJ2I3:1;                            /* MKTAUJ2I3        */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFTAUJ2I3:1;                            /* RFTAUJ2I3        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTTAUJ2I3:1;                            /* CTTAUJ2I3        */
};
struct __tag128
{                                                          /* Bit Access       */
    unsigned char  P0TAUJ3I0:1;                            /* P0TAUJ3I0        */
    unsigned char  P1TAUJ3I0:1;                            /* P1TAUJ3I0        */
    unsigned char  P2TAUJ3I0:1;                            /* P2TAUJ3I0        */
    unsigned char  P3TAUJ3I0:1;                            /* P3TAUJ3I0        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBTAUJ3I0:1;                            /* TBTAUJ3I0        */
    unsigned char  MKTAUJ3I0:1;                            /* MKTAUJ3I0        */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFTAUJ3I0:1;                            /* RFTAUJ3I0        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTTAUJ3I0:1;                            /* CTTAUJ3I0        */
};
struct __tag129
{                                                          /* Bit Access       */
    unsigned char  P0TAUJ3I1:1;                            /* P0TAUJ3I1        */
    unsigned char  P1TAUJ3I1:1;                            /* P1TAUJ3I1        */
    unsigned char  P2TAUJ3I1:1;                            /* P2TAUJ3I1        */
    unsigned char  P3TAUJ3I1:1;                            /* P3TAUJ3I1        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBTAUJ3I1:1;                            /* TBTAUJ3I1        */
    unsigned char  MKTAUJ3I1:1;                            /* MKTAUJ3I1        */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFTAUJ3I1:1;                            /* RFTAUJ3I1        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTTAUJ3I1:1;                            /* CTTAUJ3I1        */
};
struct __tag130
{                                                          /* Bit Access       */
    unsigned char  P0TAUJ3I2:1;                            /* P0TAUJ3I2        */
    unsigned char  P1TAUJ3I2:1;                            /* P1TAUJ3I2        */
    unsigned char  P2TAUJ3I2:1;                            /* P2TAUJ3I2        */
    unsigned char  P3TAUJ3I2:1;                            /* P3TAUJ3I2        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBTAUJ3I2:1;                            /* TBTAUJ3I2        */
    unsigned char  MKTAUJ3I2:1;                            /* MKTAUJ3I2        */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFTAUJ3I2:1;                            /* RFTAUJ3I2        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTTAUJ3I2:1;                            /* CTTAUJ3I2        */
};
struct __tag131
{                                                          /* Bit Access       */
    unsigned char  P0TAUJ3I3:1;                            /* P0TAUJ3I3        */
    unsigned char  P1TAUJ3I3:1;                            /* P1TAUJ3I3        */
    unsigned char  P2TAUJ3I3:1;                            /* P2TAUJ3I3        */
    unsigned char  P3TAUJ3I3:1;                            /* P3TAUJ3I3        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBTAUJ3I3:1;                            /* TBTAUJ3I3        */
    unsigned char  MKTAUJ3I3:1;                            /* MKTAUJ3I3        */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFTAUJ3I3:1;                            /* RFTAUJ3I3        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTTAUJ3I3:1;                            /* CTTAUJ3I3        */
};
struct __tag132
{                                                          /* Bit Access       */
    unsigned char  P0SENT0SI:1;                            /* P0SENT0SI        */
    unsigned char  P1SENT0SI:1;                            /* P1SENT0SI        */
    unsigned char  P2SENT0SI:1;                            /* P2SENT0SI        */
    unsigned char  P3SENT0SI:1;                            /* P3SENT0SI        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBSENT0SI:1;                            /* TBSENT0SI        */
    unsigned char  MKSENT0SI:1;                            /* MKSENT0SI        */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFSENT0SI:1;                            /* RFSENT0SI        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTSENT0SI:1;                            /* CTSENT0SI        */
};
struct __tag133
{                                                          /* Bit Access       */
    unsigned char  P0SENT0RI:1;                            /* P0SENT0RI        */
    unsigned char  P1SENT0RI:1;                            /* P1SENT0RI        */
    unsigned char  P2SENT0RI:1;                            /* P2SENT0RI        */
    unsigned char  P3SENT0RI:1;                            /* P3SENT0RI        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBSENT0RI:1;                            /* TBSENT0RI        */
    unsigned char  MKSENT0RI:1;                            /* MKSENT0RI        */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFSENT0RI:1;                            /* RFSENT0RI        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTSENT0RI:1;                            /* CTSENT0RI        */
};
struct __tag134
{                                                          /* Bit Access       */
    unsigned char  P0SENT1SI:1;                            /* P0SENT1SI        */
    unsigned char  P1SENT1SI:1;                            /* P1SENT1SI        */
    unsigned char  P2SENT1SI:1;                            /* P2SENT1SI        */
    unsigned char  P3SENT1SI:1;                            /* P3SENT1SI        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBSENT1SI:1;                            /* TBSENT1SI        */
    unsigned char  MKSENT1SI:1;                            /* MKSENT1SI        */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFSENT1SI:1;                            /* RFSENT1SI        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTSENT1SI:1;                            /* CTSENT1SI        */
};
struct __tag135
{                                                          /* Bit Access       */
    unsigned char  P0SENT1RI:1;                            /* P0SENT1RI        */
    unsigned char  P1SENT1RI:1;                            /* P1SENT1RI        */
    unsigned char  P2SENT1RI:1;                            /* P2SENT1RI        */
    unsigned char  P3SENT1RI:1;                            /* P3SENT1RI        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBSENT1RI:1;                            /* TBSENT1RI        */
    unsigned char  MKSENT1RI:1;                            /* MKSENT1RI        */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFSENT1RI:1;                            /* RFSENT1RI        */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTSENT1RI:1;                            /* CTSENT1RI        */
};
struct __tag136
{                                                          /* Bit Access       */
    unsigned char  P0DPE:1;                                /* P0DPE            */
    unsigned char  P1DPE:1;                                /* P1DPE            */
    unsigned char  P2DPE:1;                                /* P2DPE            */
    unsigned char  P3DPE:1;                                /* P3DPE            */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBDPE:1;                                /* TBDPE            */
    unsigned char  MKDPE:1;                                /* MKDPE            */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFDPE:1;                                /* RFDPE            */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTDPE:1;                                /* CTDPE            */
};
struct __tag137
{                                                          /* Bit Access       */
    unsigned char  P0APE:1;                                /* P0APE            */
    unsigned char  P1APE:1;                                /* P1APE            */
    unsigned char  P2APE:1;                                /* P2APE            */
    unsigned char  P3APE:1;                                /* P3APE            */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  TBAPE:1;                                /* TBAPE            */
    unsigned char  MKAPE:1;                                /* MKAPE            */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  RFAPE:1;                                /* RFAPE            */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  CTAPE:1;                                /* CTAPE            */
};
struct __tag138
{                                                          /* Bit Access       */
    unsigned char  IMR1EIMK32:1;                           /* IMR1EIMK32       */
    unsigned char  IMR1EIMK33:1;                           /* IMR1EIMK33       */
    unsigned char  IMR1EIMK34:1;                           /* IMR1EIMK34       */
    unsigned char  IMR1EIMK35:1;                           /* IMR1EIMK35       */
    unsigned char  IMR1EIMK36:1;                           /* IMR1EIMK36       */
    unsigned char  IMR1EIMK37:1;                           /* IMR1EIMK37       */
    unsigned char  IMR1EIMK38:1;                           /* IMR1EIMK38       */
    unsigned char  IMR1EIMK39:1;                           /* IMR1EIMK39       */
    unsigned char  IMR1EIMK40:1;                           /* IMR1EIMK40       */
    unsigned char  IMR1EIMK41:1;                           /* IMR1EIMK41       */
    unsigned char  :1;                                     /* Reserved Bits    */
    unsigned char  IMR1EIMK43:1;                           /* IMR1EIMK43       */
    unsigned char  IMR1EIMK44:1;                           /* IMR1EIMK44       */
    unsigned char  IMR1EIMK45:1;                           /* IMR1EIMK45       */
    unsigned char  IMR1EIMK46:1;                           /* IMR1EIMK46       */
    unsigned char  IMR1EIMK47:1;                           /* IMR1EIMK47       */
    unsigned char  IMR1EIMK48:1;                           /* IMR1EIMK48       */
    unsigned char  IMR1EIMK49:1;                           /* IMR1EIMK49       */
    unsigned char  IMR1EIMK50:1;                           /* IMR1EIMK50       */
    unsigned char  IMR1EIMK51:1;                           /* IMR1EIMK51       */
    unsigned char  IMR1EIMK52:1;                           /* IMR1EIMK52       */
    unsigned char  IMR1EIMK53:1;                           /* IMR1EIMK53       */
    unsigned char  IMR1EIMK54:1;                           /* IMR1EIMK54       */
    unsigned char  IMR1EIMK55:1;                           /* IMR1EIMK55       */
    unsigned char  IMR1EIMK56:1;                           /* IMR1EIMK56       */
    unsigned char  IMR1EIMK57:1;                           /* IMR1EIMK57       */
    unsigned char  IMR1EIMK58:1;                           /* IMR1EIMK58       */
    unsigned char  IMR1EIMK59:1;                           /* IMR1EIMK59       */
    unsigned char  IMR1EIMK60:1;                           /* IMR1EIMK60       */
    unsigned char  IMR1EIMK61:1;                           /* IMR1EIMK61       */
    unsigned char  IMR1EIMK62:1;                           /* IMR1EIMK62       */
    unsigned char  IMR1EIMK63:1;                           /* IMR1EIMK63       */
};
struct __tag139
{                                                          /* Bit Access       */
    unsigned char  IMR2EIMK64:1;                           /* IMR2EIMK64       */
    unsigned char  IMR2EIMK65:1;                           /* IMR2EIMK65       */
    unsigned char  IMR2EIMK66:1;                           /* IMR2EIMK66       */
    unsigned char  IMR2EIMK67:1;                           /* IMR2EIMK67       */
    unsigned char  IMR2EIMK68:1;                           /* IMR2EIMK68       */
    unsigned char  IMR2EIMK69:1;                           /* IMR2EIMK69       */
    unsigned char  IMR2EIMK70:1;                           /* IMR2EIMK70       */
    unsigned char  IMR2EIMK71:1;                           /* IMR2EIMK71       */
    unsigned char  IMR2EIMK72:1;                           /* IMR2EIMK72       */
    unsigned char  IMR2EIMK73:1;                           /* IMR2EIMK73       */
    unsigned char  IMR2EIMK74:1;                           /* IMR2EIMK74       */
    unsigned char  IMR2EIMK75:1;                           /* IMR2EIMK75       */
    unsigned char  IMR2EIMK76:1;                           /* IMR2EIMK76       */
    unsigned char  IMR2EIMK77:1;                           /* IMR2EIMK77       */
    unsigned char  IMR2EIMK78:1;                           /* IMR2EIMK78       */
    unsigned char  IMR2EIMK79:1;                           /* IMR2EIMK79       */
    unsigned char  IMR2EIMK80:1;                           /* IMR2EIMK80       */
    unsigned char  IMR2EIMK81:1;                           /* IMR2EIMK81       */
    unsigned char  IMR2EIMK82:1;                           /* IMR2EIMK82       */
    unsigned char  IMR2EIMK83:1;                           /* IMR2EIMK83       */
    unsigned char  IMR2EIMK84:1;                           /* IMR2EIMK84       */
    unsigned char  IMR2EIMK85:1;                           /* IMR2EIMK85       */
    unsigned char  IMR2EIMK86:1;                           /* IMR2EIMK86       */
    unsigned char  IMR2EIMK87:1;                           /* IMR2EIMK87       */
    unsigned char  IMR2EIMK88:1;                           /* IMR2EIMK88       */
    unsigned char  IMR2EIMK89:1;                           /* IMR2EIMK89       */
    unsigned char  IMR2EIMK90:1;                           /* IMR2EIMK90       */
    unsigned char  IMR2EIMK91:1;                           /* IMR2EIMK91       */
    unsigned char  IMR2EIMK92:1;                           /* IMR2EIMK92       */
    unsigned char  :3;                                     /* Reserved Bits    */
};
struct __tag140
{                                                          /* Bit Access       */
    unsigned char  :8;                                     /* Reserved Bits    */
    unsigned char  :6;                                     /* Reserved Bits    */
    unsigned char  IMR3EIMK110:1;                          /* IMR3EIMK110      */
    unsigned char  IMR3EIMK111:1;                          /* IMR3EIMK111      */
    unsigned char  IMR3EIMK112:1;                          /* IMR3EIMK112      */
    unsigned char  :3;                                     /* Reserved Bits    */
    unsigned char  IMR3EIMK116:1;                          /* IMR3EIMK116      */
    unsigned char  IMR3EIMK117:1;                          /* IMR3EIMK117      */
    unsigned char  IMR3EIMK118:1;                          /* IMR3EIMK118      */
    unsigned char  IMR3EIMK119:1;                          /* IMR3EIMK119      */
    unsigned char  :8;                                     /* Reserved Bits    */
};
struct __tag141
{                                                          /* Bit Access       */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  IMR4EIMK132:1;                          /* IMR4EIMK132      */
    unsigned char  IMR4EIMK133:1;                          /* IMR4EIMK133      */
    unsigned char  IMR4EIMK134:1;                          /* IMR4EIMK134      */
    unsigned char  IMR4EIMK135:1;                          /* IMR4EIMK135      */
    unsigned char  :8;                                     /* Reserved Bits    */
    unsigned char  :8;                                     /* Reserved Bits    */
    unsigned char  :6;                                     /* Reserved Bits    */
    unsigned char  IMR4EIMK158:1;                          /* IMR4EIMK158      */
    unsigned char  IMR4EIMK159:1;                          /* IMR4EIMK159      */
};
struct __tag142
{                                                          /* Bit Access       */
    unsigned char  IMR5EIMK160:1;                          /* IMR5EIMK160      */
    unsigned char  IMR5EIMK161:1;                          /* IMR5EIMK161      */
    unsigned char  :6;                                     /* Reserved Bits    */
    unsigned char  IMR5EIMK168:1;                          /* IMR5EIMK168      */
    unsigned char  IMR5EIMK169:1;                          /* IMR5EIMK169      */
    unsigned char  IMR5EIMK170:1;                          /* IMR5EIMK170      */
    unsigned char  IMR5EIMK171:1;                          /* IMR5EIMK171      */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  :8;                                     /* Reserved Bits    */
    unsigned char  :8;                                     /* Reserved Bits    */
};
struct __tag143
{                                                          /* Bit Access       */
    unsigned char  :8;                                     /* Reserved Bits    */
    unsigned char  :8;                                     /* Reserved Bits    */
    unsigned char  :1;                                     /* Reserved Bits    */
    unsigned char  IMR6EIMK209:1;                          /* IMR6EIMK209      */
    unsigned char  IMR6EIMK210:1;                          /* IMR6EIMK210      */
    unsigned char  IMR6EIMK211:1;                          /* IMR6EIMK211      */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  :8;                                     /* Reserved Bits    */
};
struct __tag144
{                                                          /* Bit Access       */
    unsigned char  :8;                                     /* Reserved Bits    */
    unsigned char  :8;                                     /* Reserved Bits    */
    unsigned char  IMR7EIMK240:1;                          /* IMR7EIMK240      */
    unsigned char  IMR7EIMK241:1;                          /* IMR7EIMK241      */
    unsigned char  IMR7EIMK242:1;                          /* IMR7EIMK242      */
    unsigned char  IMR7EIMK243:1;                          /* IMR7EIMK243      */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  :8;                                     /* Reserved Bits    */
};
struct __tag145
{                                                          /* Bit Access       */
    unsigned char  :8;                                     /* Reserved Bits    */
    unsigned char  :8;                                     /* Reserved Bits    */
    unsigned char  :5;                                     /* Reserved Bits    */
    unsigned char  IMR8EIMK277:1;                          /* IMR8EIMK277      */
    unsigned char  IMR8EIMK278:1;                          /* IMR8EIMK278      */
    unsigned char  IMR8EIMK279:1;                          /* IMR8EIMK279      */
    unsigned char  IMR8EIMK280:1;                          /* IMR8EIMK280      */
    unsigned char  IMR8EIMK281:1;                          /* IMR8EIMK281      */
    unsigned char  IMR8EIMK282:1;                          /* IMR8EIMK282      */
    unsigned char  IMR8EIMK283:1;                          /* IMR8EIMK283      */
    unsigned char  IMR8EIMK284:1;                          /* IMR8EIMK284      */
    unsigned char  :3;                                     /* Reserved Bits    */
};
struct __tag146
{                                                          /* Bit Access       */
    unsigned char  :8;                                     /* Reserved Bits    */
    unsigned char  :8;                                     /* Reserved Bits    */
    unsigned char  :8;                                     /* Reserved Bits    */
    unsigned char  :3;                                     /* Reserved Bits    */
    unsigned char  IMR10EIMK347:1;                         /* IMR10EIMK347     */
    unsigned char  IMR10EIMK348:1;                         /* IMR10EIMK348     */
    unsigned char  IMR10EIMK349:1;                         /* IMR10EIMK349     */
    unsigned char  IMR10EIMK350:1;                         /* IMR10EIMK350     */
    unsigned char  :1;                                     /* Reserved Bits    */
};
struct __tag147
{                                                          /* Bit Access       */
    unsigned char  :4;                                     /* Reserved Bits    */
    unsigned char  IMR11EIMK356:1;                         /* IMR11EIMK356     */
    unsigned char  IMR11EIMK357:1;                         /* IMR11EIMK357     */
    unsigned char  :2;                                     /* Reserved Bits    */
    unsigned char  :8;                                     /* Reserved Bits    */
    unsigned char  :8;                                     /* Reserved Bits    */
    unsigned char  :8;                                     /* Reserved Bits    */
};
union __tag148
{                                                          /* IOR              */
    unsigned long  UINT32;                                 /* 32-bit Access    */
    unsigned short UINT16[2];                              /* 16-bit Access    */
    unsigned char  UINT8[4];                               /* 8-bit Access     */
};
union __tag149
{                                                          /* IOR              */
    unsigned char  UINT8;                                  /* 8-bit Access     */
    struct __tag0 BIT;                                     /* Bit Access       */
};
union __tag150
{                                                          /* IOR              */
    unsigned char  UINT8;                                  /* 8-bit Access     */
    struct __tag1 BIT;                                     /* Bit Access       */
};
union __tag151
{                                                          /* IOR              */
    unsigned char  UINT8;                                  /* 8-bit Access     */
    struct __tag2 BIT;                                     /* Bit Access       */
};
union __tag152
{                                                          /* IOR              */
    unsigned char  UINT8;                                  /* 8-bit Access     */
    struct __tag3 BIT;                                     /* Bit Access       */
};
union __tag153
{                                                          /* IOR              */
    unsigned char  UINT8;                                  /* 8-bit Access     */
    struct __tag4 BIT;                                     /* Bit Access       */
};
union __tag154
{                                                          /* IOR              */
    unsigned long  UINT32;                                 /* 32-bit Access    */
    unsigned short UINT16[2];                              /* 16-bit Access    */
};
union __tag155
{                                                          /* IOR              */
    unsigned long  UINT32;                                 /* 32-bit Access    */
    unsigned char  UINT8[4];                               /* 8-bit Access     */
    struct 
    {
        union
        {                                                  /* IOR              */
            unsigned char  UINT8;                          /* 8-bit Access     */
        } ERDB;
        union
        {                                                  /* IOR              */
            unsigned char  UINT8;                          /* 8-bit Access     */
        } ECRD;
        union
        {                                                  /* IOR              */
            unsigned char  UINT8;                          /* 8-bit Access     */
        } HORD;
        union
        {                                                  /* IOR              */
            unsigned char  UINT8;                          /* 8-bit Access     */
        } SYND;
    } REGS8;
};
union __tag156
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct 
    {
        union
        {                                                  /* IOR              */
            unsigned char  UINT8;                          /*  8-bit Access    */
        } LBRP0;
        union
        {                                                  /* IOR              */
            unsigned char  UINT8;                          /*  8-bit Access    */
        } LBRP1;
    } REGS8;
};
union __tag157
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
};
union __tag158
{                                                          /* IOR              */
    unsigned char  UINT8;                                  /* 8-bit Access     */
    struct __tag5 BIT;                                     /* Bit Access       */
};
union __tag159
{                                                          /* IOR              */
    unsigned char  UINT8;                                  /* 8-bit Access     */
    struct __tag6 BIT;                                     /* Bit Access       */
};
union __tag160
{                                                          /* IOR              */
    unsigned char  UINT8;                                  /* 8-bit Access     */
    struct __tag7 BIT;                                     /* Bit Access       */
};
union __tag161
{                                                          /* IOR              */
    unsigned char  UINT8;                                  /* 8-bit Access     */
    struct __tag8 BIT;                                     /* Bit Access       */
};
union __tag162
{                                                          /* IOR              */
    unsigned char  UINT8;                                  /* 8-bit Access     */
    struct __tag9 BIT;                                     /* Bit Access       */
};
union __tag163
{                                                          /* IOR              */
    unsigned char  UINT8;                                  /* 8-bit Access     */
    struct __tag10 BIT;                                    /* Bit Access       */
};
union __tag164
{                                                          /* IOR              */
    unsigned long  UINT32;                                 /* 32-bit Access    */
    unsigned short UINT16[2];                              /* 16-bit Access    */
    unsigned char  UINT8[4];                               /* 8-bit Access     */
    struct 
    {
        union
        {                                                  /* IOR              */
            unsigned char  UINT8;                          /* 8-bit Access     */
        } DPSELR1;
        union
        {                                                  /* IOR              */
            unsigned char  UINT8;                          /* 8-bit Access     */
        } DPSELR2;
        union
        {                                                  /* IOR              */
            unsigned char  UINT8;                          /* 8-bit Access     */
        } DPSELR3;
        union
        {                                                  /* IOR              */
            unsigned char  UINT8;                          /* 8-bit Access     */
        } DPSELR4;
    } REGS8;
};
union __tag165
{                                                          /* IOR              */
    unsigned long  UINT32;                                 /* 32-bit Access    */
    unsigned short UINT16[2];                              /* 16-bit Access    */
    unsigned char  UINT8[4];                               /* 8-bit Access     */
    struct 
    {
        union
        {                                                  /* IOR              */
            unsigned char  UINT8;                          /* 8-bit Access     */
        } DPSELR5;
        union
        {                                                  /* IOR              */
            unsigned char  UINT8;                          /* 8-bit Access     */
        } DPSELR6;
        union
        {                                                  /* IOR              */
            unsigned char  UINT8;                          /* 8-bit Access     */
        } DPSELR7;
        unsigned char  dummy0[1];                          /* Reserved         */
    } REGS8;
};
union __tag166
{                                                          /* IOR              */
    unsigned long  UINT32;                                 /* 32-bit Access    */
    unsigned short UINT16[2];                              /* 16-bit Access    */
    unsigned char  UINT8[4];                               /* 8-bit Access     */
    struct 
    {
        union
        {                                                  /* IOR              */
            unsigned char  UINT8;                          /* 8-bit Access     */
        } DPDSR1;
        union
        {                                                  /* IOR              */
            unsigned char  UINT8;                          /* 8-bit Access     */
        } DPDSR2;
        union
        {                                                  /* IOR              */
            unsigned char  UINT8;                          /* 8-bit Access     */
        } DPDSR3;
        union
        {                                                  /* IOR              */
            unsigned char  UINT8;                          /* 8-bit Access     */
        } DPDSR4;
    } REGS8;
};
union __tag167
{                                                          /* IOR              */
    unsigned long  UINT32;                                 /* 32-bit Access    */
    unsigned short UINT16[2];                              /* 16-bit Access    */
    unsigned char  UINT8[4];                               /* 8-bit Access     */
    struct 
    {
        union
        {                                                  /* IOR              */
            unsigned char  UINT8;                          /* 8-bit Access     */
        } DPDSR5;
        union
        {                                                  /* IOR              */
            unsigned char  UINT8;                          /* 8-bit Access     */
        } DPDSR6;
        union
        {                                                  /* IOR              */
            unsigned char  UINT8;                          /* 8-bit Access     */
        } DPDSR7;
        unsigned char  dummy1[1];                          /* Reserved         */
    } REGS8;
};
union __tag168
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag11 BIT;                                    /* Bit Access       */
};
union __tag169
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag12 BIT;                                    /* Bit Access       */
};
union __tag170
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag13 BIT;                                    /* Bit Access       */
};
union __tag171
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag14 BIT;                                    /* Bit Access       */
};
union __tag172
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag15 BIT;                                    /* Bit Access       */
};
union __tag173
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag16 BIT;                                    /* Bit Access       */
};
union __tag174
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag17 BIT;                                    /* Bit Access       */
};
union __tag175
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag18 BIT;                                    /* Bit Access       */
};
union __tag176
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag19 BIT;                                    /* Bit Access       */
};
union __tag177
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag20 BIT;                                    /* Bit Access       */
};
union __tag178
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag21 BIT;                                    /* Bit Access       */
};
union __tag179
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag22 BIT;                                    /* Bit Access       */
};
union __tag180
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct 
    {
        union
        {                                                  /* IOR              */
            unsigned char  UINT8;                          /*  8-bit Access    */
        } ICCSIH0IJC_1L;
        union
        {                                                  /* IOR              */
            unsigned char  UINT8;                          /*  8-bit Access    */
        } ICCSIH0IJC_1H;
    } REGS8;
    struct __tag23 BIT;                                    /* Bit Access       */
};
union __tag181
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag24 BIT;                                    /* Bit Access       */
};
union __tag182
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag25 BIT;                                    /* Bit Access       */
};
union __tag183
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag26 BIT;                                    /* Bit Access       */
};
union __tag184
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag27 BIT;                                    /* Bit Access       */
};
union __tag185
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag28 BIT;                                    /* Bit Access       */
};
union __tag186
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag29 BIT;                                    /* Bit Access       */
};
union __tag187
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag30 BIT;                                    /* Bit Access       */
};
union __tag188
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag31 BIT;                                    /* Bit Access       */
};
union __tag189
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag32 BIT;                                    /* Bit Access       */
};
union __tag190
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag33 BIT;                                    /* Bit Access       */
};
union __tag191
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag34 BIT;                                    /* Bit Access       */
};
union __tag192
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag35 BIT;                                    /* Bit Access       */
};
union __tag193
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag36 BIT;                                    /* Bit Access       */
};
union __tag194
{                                                          /* IOR              */
    unsigned long  UINT32;                                 /* 32-bit Access    */
    unsigned short UINT16[2];                              /* 16-bit Access    */
    unsigned char  UINT8[4];                               /* 8-bit Access     */
    struct __tag37 BIT;                                    /* Bit Access       */
};
union __tag195
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct 
    {
        union
        {                                                  /* IOR              */
            unsigned char  UINT8;                          /*  8-bit Access    */
        } ICCSIH0IJCL;
        union
        {                                                  /* IOR              */
            unsigned char  UINT8;                          /*  8-bit Access    */
        } ICCSIH0IJCH;
    } REGS8;
    struct __tag38 BIT;                                    /* Bit Access       */
};
union __tag196
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag39 BIT;                                    /* Bit Access       */
};
union __tag197
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag40 BIT;                                    /* Bit Access       */
};
union __tag198
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag41 BIT;                                    /* Bit Access       */
};
union __tag199
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag42 BIT;                                    /* Bit Access       */
};
union __tag200
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag43 BIT;                                    /* Bit Access       */
};
union __tag201
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag44 BIT;                                    /* Bit Access       */
};
union __tag202
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag45 BIT;                                    /* Bit Access       */
};
union __tag203
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag46 BIT;                                    /* Bit Access       */
};
union __tag204
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag47 BIT;                                    /* Bit Access       */
};
union __tag205
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag48 BIT;                                    /* Bit Access       */
};
union __tag206
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag49 BIT;                                    /* Bit Access       */
};
union __tag207
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag50 BIT;                                    /* Bit Access       */
};
union __tag208
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag51 BIT;                                    /* Bit Access       */
};
union __tag209
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag52 BIT;                                    /* Bit Access       */
};
union __tag210
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag53 BIT;                                    /* Bit Access       */
};
union __tag211
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag54 BIT;                                    /* Bit Access       */
};
union __tag212
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag55 BIT;                                    /* Bit Access       */
};
union __tag213
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag56 BIT;                                    /* Bit Access       */
};
union __tag214
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag57 BIT;                                    /* Bit Access       */
};
union __tag215
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag58 BIT;                                    /* Bit Access       */
};
union __tag216
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag59 BIT;                                    /* Bit Access       */
};
union __tag217
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag60 BIT;                                    /* Bit Access       */
};
union __tag218
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag61 BIT;                                    /* Bit Access       */
};
union __tag219
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag62 BIT;                                    /* Bit Access       */
};
union __tag220
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag63 BIT;                                    /* Bit Access       */
};
union __tag221
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag64 BIT;                                    /* Bit Access       */
};
union __tag222
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag65 BIT;                                    /* Bit Access       */
};
union __tag223
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag66 BIT;                                    /* Bit Access       */
};
union __tag224
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag67 BIT;                                    /* Bit Access       */
};
union __tag225
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag68 BIT;                                    /* Bit Access       */
};
union __tag226
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag69 BIT;                                    /* Bit Access       */
};
union __tag227
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag70 BIT;                                    /* Bit Access       */
};
union __tag228
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag71 BIT;                                    /* Bit Access       */
};
union __tag229
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag72 BIT;                                    /* Bit Access       */
};
union __tag230
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag73 BIT;                                    /* Bit Access       */
};
union __tag231
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag74 BIT;                                    /* Bit Access       */
};
union __tag232
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag75 BIT;                                    /* Bit Access       */
};
union __tag233
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag76 BIT;                                    /* Bit Access       */
};
union __tag234
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag77 BIT;                                    /* Bit Access       */
};
union __tag235
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag78 BIT;                                    /* Bit Access       */
};
union __tag236
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag79 BIT;                                    /* Bit Access       */
};
union __tag237
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag80 BIT;                                    /* Bit Access       */
};
union __tag238
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag81 BIT;                                    /* Bit Access       */
};
union __tag239
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag82 BIT;                                    /* Bit Access       */
};
union __tag240
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag83 BIT;                                    /* Bit Access       */
};
union __tag241
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag84 BIT;                                    /* Bit Access       */
};
union __tag242
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag85 BIT;                                    /* Bit Access       */
};
union __tag243
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag86 BIT;                                    /* Bit Access       */
};
union __tag244
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag87 BIT;                                    /* Bit Access       */
};
union __tag245
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag88 BIT;                                    /* Bit Access       */
};
union __tag246
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag89 BIT;                                    /* Bit Access       */
};
union __tag247
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag90 BIT;                                    /* Bit Access       */
};
union __tag248
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag91 BIT;                                    /* Bit Access       */
};
union __tag249
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag92 BIT;                                    /* Bit Access       */
};
union __tag250
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag93 BIT;                                    /* Bit Access       */
};
union __tag251
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag94 BIT;                                    /* Bit Access       */
};
union __tag252
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag95 BIT;                                    /* Bit Access       */
};
union __tag253
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag96 BIT;                                    /* Bit Access       */
};
union __tag254
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag97 BIT;                                    /* Bit Access       */
};
union __tag255
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag98 BIT;                                    /* Bit Access       */
};
union __tag256
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag99 BIT;                                    /* Bit Access       */
};
union __tag257
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag100 BIT;                                   /* Bit Access       */
};
union __tag258
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag101 BIT;                                   /* Bit Access       */
};
union __tag259
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag102 BIT;                                   /* Bit Access       */
};
union __tag260
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag103 BIT;                                   /* Bit Access       */
};
union __tag261
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag104 BIT;                                   /* Bit Access       */
};
union __tag262
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag105 BIT;                                   /* Bit Access       */
};
union __tag263
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag106 BIT;                                   /* Bit Access       */
};
union __tag264
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag107 BIT;                                   /* Bit Access       */
};
union __tag265
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag108 BIT;                                   /* Bit Access       */
};
union __tag266
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag109 BIT;                                   /* Bit Access       */
};
union __tag267
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag110 BIT;                                   /* Bit Access       */
};
union __tag268
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag111 BIT;                                   /* Bit Access       */
};
union __tag269
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag112 BIT;                                   /* Bit Access       */
};
union __tag270
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag113 BIT;                                   /* Bit Access       */
};
union __tag271
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag114 BIT;                                   /* Bit Access       */
};
union __tag272
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag115 BIT;                                   /* Bit Access       */
};
union __tag273
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag116 BIT;                                   /* Bit Access       */
};
union __tag274
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag117 BIT;                                   /* Bit Access       */
};
union __tag275
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag118 BIT;                                   /* Bit Access       */
};
union __tag276
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag119 BIT;                                   /* Bit Access       */
};
union __tag277
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag120 BIT;                                   /* Bit Access       */
};
union __tag278
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag121 BIT;                                   /* Bit Access       */
};
union __tag279
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag122 BIT;                                   /* Bit Access       */
};
union __tag280
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag123 BIT;                                   /* Bit Access       */
};
union __tag281
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag124 BIT;                                   /* Bit Access       */
};
union __tag282
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag125 BIT;                                   /* Bit Access       */
};
union __tag283
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag126 BIT;                                   /* Bit Access       */
};
union __tag284
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag127 BIT;                                   /* Bit Access       */
};
union __tag285
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag128 BIT;                                   /* Bit Access       */
};
union __tag286
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag129 BIT;                                   /* Bit Access       */
};
union __tag287
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag130 BIT;                                   /* Bit Access       */
};
union __tag288
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag131 BIT;                                   /* Bit Access       */
};
union __tag289
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag132 BIT;                                   /* Bit Access       */
};
union __tag290
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag133 BIT;                                   /* Bit Access       */
};
union __tag291
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag134 BIT;                                   /* Bit Access       */
};
union __tag292
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag135 BIT;                                   /* Bit Access       */
};
union __tag293
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag136 BIT;                                   /* Bit Access       */
};
union __tag294
{                                                          /* IOR              */
    unsigned short UINT16;                                 /* 16-bit Access    */
    unsigned char  UINT8[2];                               /* 8-bit Access     */
    struct __tag137 BIT;                                   /* Bit Access       */
};
union __tag295
{                                                          /* IOR              */
    unsigned long  UINT32;                                 /* 32-bit Access    */
    unsigned short UINT16[2];                              /* 16-bit Access    */
    unsigned char  UINT8[4];                               /* 8-bit Access     */
    struct __tag138 BIT;                                   /* Bit Access       */
};
union __tag296
{                                                          /* IOR              */
    unsigned long  UINT32;                                 /* 32-bit Access    */
    unsigned short UINT16[2];                              /* 16-bit Access    */
    unsigned char  UINT8[4];                               /* 8-bit Access     */
    struct __tag139 BIT;                                   /* Bit Access       */
};
union __tag297
{                                                          /* IOR              */
    unsigned long  UINT32;                                 /* 32-bit Access    */
    unsigned short UINT16[2];                              /* 16-bit Access    */
    unsigned char  UINT8[4];                               /* 8-bit Access     */
    struct __tag140 BIT;                                   /* Bit Access       */
};
union __tag298
{                                                          /* IOR              */
    unsigned long  UINT32;                                 /* 32-bit Access    */
    unsigned short UINT16[2];                              /* 16-bit Access    */
    unsigned char  UINT8[4];                               /* 8-bit Access     */
    struct __tag141 BIT;                                   /* Bit Access       */
};
union __tag299
{                                                          /* IOR              */
    unsigned long  UINT32;                                 /* 32-bit Access    */
    unsigned short UINT16[2];                              /* 16-bit Access    */
    unsigned char  UINT8[4];                               /* 8-bit Access     */
    struct __tag142 BIT;                                   /* Bit Access       */
};
union __tag300
{                                                          /* IOR              */
    unsigned long  UINT32;                                 /* 32-bit Access    */
    unsigned short UINT16[2];                              /* 16-bit Access    */
    unsigned char  UINT8[4];                               /* 8-bit Access     */
    struct __tag143 BIT;                                   /* Bit Access       */
};
union __tag301
{                                                          /* IOR              */
    unsigned long  UINT32;                                 /* 32-bit Access    */
    unsigned short UINT16[2];                              /* 16-bit Access    */
    unsigned char  UINT8[4];                               /* 8-bit Access     */
    struct __tag144 BIT;                                   /* Bit Access       */
};
union __tag302
{                                                          /* IOR              */
    unsigned long  UINT32;                                 /* 32-bit Access    */
    unsigned short UINT16[2];                              /* 16-bit Access    */
    unsigned char  UINT8[4];                               /* 8-bit Access     */
    struct __tag145 BIT;                                   /* Bit Access       */
};
union __tag303
{                                                          /* IOR              */
    unsigned long  UINT32;                                 /* 32-bit Access    */
    unsigned short UINT16[2];                              /* 16-bit Access    */
    unsigned char  UINT8[4];                               /* 8-bit Access     */
    struct __tag146 BIT;                                   /* Bit Access       */
};
union __tag304
{                                                          /* IOR              */
    unsigned long  UINT32;                                 /* 32-bit Access    */
    unsigned short UINT16[2];                              /* 16-bit Access    */
    unsigned char  UINT8[4];                               /* 8-bit Access     */
    struct __tag147 BIT;                                   /* Bit Access       */
};

struct __tag305
{                                                          /* Module           */
    unsigned long  CNT;                                    /* CNT              */
    unsigned long  PCMD;                                   /* PCMD             */
    unsigned long  PS;                                     /* PS               */
};
struct __tag306
{                                                          /* Module           */
    unsigned long  ID0;                                    /* ID0              */
    unsigned long  ID1;                                    /* ID1              */
    unsigned long  ID2;                                    /* ID2              */
    unsigned long  ID3;                                    /* ID3              */
    union __tag148 IDST;                                   /* IDST             */
};
struct __tag307
{                                                          /* Module           */
    unsigned char  FPMON;                                  /* FPMON            */
    unsigned char  dummy0[15];                             /* Reserved         */
    unsigned char  FASTAT;                                 /* FASTAT           */
    unsigned char  dummy1[3];                              /* Reserved         */
    unsigned char  FAEINT;                                 /* FAEINT           */
    unsigned char  dummy2[11];                             /* Reserved         */
    unsigned short FAREASELC;                              /* FAREASELC        */
    unsigned char  dummy3[14];                             /* Reserved         */
    unsigned long  FSADDR;                                 /* FSADDR           */
    unsigned long  FEADDR;                                 /* FEADDR           */
    unsigned char  dummy4[72];                             /* Reserved         */
    union __tag148 FSTATR;                                 /* FSTATR           */
    unsigned short FENTRYR;                                /* FENTRYR          */
    unsigned char  dummy5[2];                              /* Reserved         */
    unsigned short FPROTR;                                 /* FPROTR           */
    unsigned char  dummy6[2];                              /* Reserved         */
    unsigned short FSUINITR;                               /* FSUINITR         */
    unsigned char  dummy7[2];                              /* Reserved         */
    unsigned char  FLKSTAT;                                /* FLKSTAT          */
    unsigned char  dummy8[7];                              /* Reserved         */
    unsigned char  FRTSTAT;                                /* FRTSTAT          */
    unsigned char  dummy9[7];                              /* Reserved         */
    unsigned short FCMDR;                                  /* FCMDR            */
    unsigned char  dummy10[30];                            /* Reserved         */
    unsigned short FPESTAT;                                /* FPESTAT          */
    unsigned char  dummy11[14];                            /* Reserved         */
    unsigned char  FBCCNT;                                 /* FBCCNT           */
    unsigned char  dummy12[3];                             /* Reserved         */
    unsigned char  FBCSTAT;                                /* FBCSTAT          */
    unsigned char  dummy13[3];                             /* Reserved         */
    unsigned long  FPSADDR;                                /* FPSADDR          */
    unsigned char  dummy14[4];                             /* Reserved         */
    unsigned short FCPSR;                                  /* FCPSR            */
    unsigned char  dummy15[2];                             /* Reserved         */
    unsigned short FPCKAR;                                 /* FPCKAR           */
    unsigned char  dummy16[26];                            /* Reserved         */
    unsigned short FECCEMON;                               /* FECCEMON         */
    unsigned char  dummy17[2];                             /* Reserved         */
    unsigned short FECCTMD;                                /* FECCTMD          */
    unsigned char  dummy18[2];                             /* Reserved         */
    unsigned short FDMYECC;                                /* FDMYECC          */
    unsigned char  dummy19[2395902];                       /* Reserved         */
    unsigned char  BFASELR;                                /* BFASELR          */
};
struct __tag308
{                                                          /* Module           */
    unsigned long  WDTNMIF;                                /* WDTNMIF          */
    unsigned char  dummy20[4];                             /* Reserved         */
    unsigned long  WDTNMIFC;                               /* WDTNMIFC         */
};
struct __tag309
{                                                          /* Module           */
    unsigned long  FEINTF;                                 /* FEINTF           */
    unsigned long  FEINTFMSK;                              /* FEINTFMSK        */
    unsigned long  FEINTFC;                                /* FEINTFC          */
};
struct __tag310
{                                                          /* Module           */
    unsigned short SELB_INTC1;                             /* SELB_INTC1       */
};
struct __tag311
{                                                          /* Module           */
    unsigned long  DTFSEL_TAUD0;                           /* DTFSEL_TAUD0     */
};
struct __tag312
{                                                          /* Module           */
    unsigned short P0;                                     /* P0               */
    unsigned char  dummy21[30];                            /* Reserved         */
    unsigned short P8;                                     /* P8               */
    unsigned char  dummy22[2];                             /* Reserved         */
    unsigned short P9;                                     /* P9               */
    unsigned char  dummy23[2];                             /* Reserved         */
    unsigned short P10;                                    /* P10              */
    unsigned char  dummy24[158];                           /* Reserved         */
    unsigned short AP0;                                    /* AP0              */
    unsigned char  dummy25[54];                            /* Reserved         */
    unsigned long  PSR0;                                   /* PSR0             */
    unsigned char  dummy26[28];                            /* Reserved         */
    unsigned long  PSR8;                                   /* PSR8             */
    unsigned long  PSR9;                                   /* PSR9             */
    unsigned long  PSR10;                                  /* PSR10            */
    unsigned char  dummy27[156];                           /* Reserved         */
    unsigned long  APSR0;                                  /* APSR0            */
    unsigned char  dummy28[52];                            /* Reserved         */
    unsigned short PPR0;                                   /* PPR0             */
    unsigned char  dummy29[30];                            /* Reserved         */
    unsigned short PPR8;                                   /* PPR8             */
    unsigned char  dummy30[2];                             /* Reserved         */
    unsigned short PPR9;                                   /* PPR9             */
    unsigned char  dummy31[2];                             /* Reserved         */
    unsigned short PPR10;                                  /* PPR10            */
    unsigned char  dummy32[158];                           /* Reserved         */
    unsigned short APPR0;                                  /* APPR0            */
    unsigned char  dummy33[54];                            /* Reserved         */
    unsigned short PM0;                                    /* PM0              */
    unsigned char  dummy34[30];                            /* Reserved         */
    unsigned short PM8;                                    /* PM8              */
    unsigned char  dummy35[2];                             /* Reserved         */
    unsigned short PM9;                                    /* PM9              */
    unsigned char  dummy36[2];                             /* Reserved         */
    unsigned short PM10;                                   /* PM10             */
    unsigned char  dummy37[158];                           /* Reserved         */
    unsigned short APM0;                                   /* APM0             */
    unsigned char  dummy38[54];                            /* Reserved         */
    unsigned short PMC0;                                   /* PMC0             */
    unsigned char  dummy39[30];                            /* Reserved         */
    unsigned short PMC8;                                   /* PMC8             */
    unsigned char  dummy40[2];                             /* Reserved         */
    unsigned short PMC9;                                   /* PMC9             */
    unsigned char  dummy41[2];                             /* Reserved         */
    unsigned short PMC10;                                  /* PMC10            */
    unsigned char  dummy42[214];                           /* Reserved         */
    unsigned short PFC0;                                   /* PFC0             */
    unsigned char  dummy43[30];                            /* Reserved         */
    unsigned short PFC8;                                   /* PFC8             */
    unsigned char  dummy44[2];                             /* Reserved         */
    unsigned short PFC9;                                   /* PFC9             */
    unsigned char  dummy45[2];                             /* Reserved         */
    unsigned short PFC10;                                  /* PFC10            */
    unsigned char  dummy46[214];                           /* Reserved         */
    unsigned short PFCE0;                                  /* PFCE0            */
    unsigned char  dummy47[30];                            /* Reserved         */
    unsigned short PFCE8;                                  /* PFCE8            */
    unsigned char  dummy48[2];                             /* Reserved         */
    unsigned short PFCE9;                                  /* PFCE9            */
    unsigned char  dummy49[2];                             /* Reserved         */
    unsigned short PFCE10;                                 /* PFCE10           */
    unsigned char  dummy50[214];                           /* Reserved         */
    unsigned short PNOT0;                                  /* PNOT0            */
    unsigned char  dummy51[30];                            /* Reserved         */
    unsigned short PNOT8;                                  /* PNOT8            */
    unsigned char  dummy52[2];                             /* Reserved         */
    unsigned short PNOT9;                                  /* PNOT9            */
    unsigned char  dummy53[2];                             /* Reserved         */
    unsigned short PNOT10;                                 /* PNOT10           */
    unsigned char  dummy54[158];                           /* Reserved         */
    unsigned short APNOT0;                                 /* APNOT0           */
    unsigned char  dummy55[54];                            /* Reserved         */
    unsigned long  PMSR0;                                  /* PMSR0            */
    unsigned char  dummy56[28];                            /* Reserved         */
    unsigned long  PMSR8;                                  /* PMSR8            */
    unsigned long  PMSR9;                                  /* PMSR9            */
    unsigned long  PMSR10;                                 /* PMSR10           */
    unsigned char  dummy57[156];                           /* Reserved         */
    unsigned long  APMSR0;                                 /* APMSR0           */
    unsigned char  dummy58[52];                            /* Reserved         */
    unsigned long  PMCSR0;                                 /* PMCSR0           */
    unsigned char  dummy59[28];                            /* Reserved         */
    unsigned long  PMCSR8;                                 /* PMCSR8           */
    unsigned long  PMCSR9;                                 /* PMCSR9           */
    unsigned long  PMCSR10;                                /* PMCSR10          */
    unsigned char  dummy60[212];                           /* Reserved         */
    unsigned short PFCAE0;                                 /* PFCAE0           */
    unsigned char  dummy61[30];                            /* Reserved         */
    unsigned short PFCAE8;                                 /* PFCAE8           */
    unsigned char  dummy62[2];                             /* Reserved         */
    unsigned short PFCAE9;                                 /* PFCAE9           */
    unsigned char  dummy63[2];                             /* Reserved         */
    unsigned short PFCAE10;                                /* PFCAE10          */
    unsigned char  dummy64[13782];                         /* Reserved         */
    unsigned short PIBC0;                                  /* PIBC0            */
    unsigned char  dummy65[30];                            /* Reserved         */
    unsigned short PIBC8;                                  /* PIBC8            */
    unsigned char  dummy66[2];                             /* Reserved         */
    unsigned short PIBC9;                                  /* PIBC9            */
    unsigned char  dummy67[2];                             /* Reserved         */
    unsigned short PIBC10;                                 /* PIBC10           */
    unsigned char  dummy68[158];                           /* Reserved         */
    unsigned short APIBC0;                                 /* APIBC0           */
    unsigned char  dummy69[54];                            /* Reserved         */
    unsigned short PBDC0;                                  /* PBDC0            */
    unsigned char  dummy70[30];                            /* Reserved         */
    unsigned short PBDC8;                                  /* PBDC8            */
    unsigned char  dummy71[2];                             /* Reserved         */
    unsigned short PBDC9;                                  /* PBDC9            */
    unsigned char  dummy72[2];                             /* Reserved         */
    unsigned short PBDC10;                                 /* PBDC10           */
    unsigned char  dummy73[158];                           /* Reserved         */
    unsigned short APBDC0;                                 /* APBDC0           */
    unsigned char  dummy74[54];                            /* Reserved         */
    unsigned short PIPC0;                                  /* PIPC0            */
    unsigned char  dummy75[38];                            /* Reserved         */
    unsigned short PIPC10;                                 /* PIPC10           */
    unsigned char  dummy76[214];                           /* Reserved         */
    unsigned short PU0;                                    /* PU0              */
    unsigned char  dummy77[30];                            /* Reserved         */
    unsigned short PU8;                                    /* PU8              */
    unsigned char  dummy78[2];                             /* Reserved         */
    unsigned short PU9;                                    /* PU9              */
    unsigned char  dummy79[2];                             /* Reserved         */
    unsigned short PU10;                                   /* PU10             */
    unsigned char  dummy80[214];                           /* Reserved         */
    unsigned short PD0;                                    /* PD0              */
    unsigned char  dummy81[30];                            /* Reserved         */
    unsigned short PD8;                                    /* PD8              */
    unsigned char  dummy82[2];                             /* Reserved         */
    unsigned short PD9;                                    /* PD9              */
    unsigned char  dummy83[2];                             /* Reserved         */
    unsigned short PD10;                                   /* PD10             */
    unsigned char  dummy84[214];                           /* Reserved         */
    unsigned long  PODC0;                                  /* PODC0            */
    unsigned char  dummy85[28];                            /* Reserved         */
    unsigned long  PODC8;                                  /* PODC8            */
    unsigned long  PODC9;                                  /* PODC9            */
    unsigned long  PODC10;                                 /* PODC10           */
    unsigned char  dummy86[212];                           /* Reserved         */
    unsigned long  PDSC0;                                  /* PDSC0            */
    unsigned char  dummy87[36];                            /* Reserved         */
    unsigned long  PDSC10;                                 /* PDSC10           */
    unsigned char  dummy88[212];                           /* Reserved         */
    unsigned short PIS0;                                   /* PIS0             */
    unsigned char  dummy89[30];                            /* Reserved         */
    unsigned short PIS8;                                   /* PIS8             */
    unsigned char  dummy90[2];                             /* Reserved         */
    unsigned short PIS9;                                   /* PIS9             */
    unsigned char  dummy91[2];                             /* Reserved         */
    unsigned short PIS10;                                  /* PIS10            */
    unsigned char  dummy92[982];                           /* Reserved         */
    unsigned long  PPROTS0;                                /* PPROTS0          */
    unsigned char  dummy93[28];                            /* Reserved         */
    unsigned long  PPROTS8;                                /* PPROTS8          */
    unsigned long  PPROTS9;                                /* PPROTS9          */
    unsigned long  PPROTS10;                               /* PPROTS10         */
    unsigned char  dummy94[212];                           /* Reserved         */
    unsigned long  PPCMD0;                                 /* PPCMD0           */
    unsigned char  dummy95[28];                            /* Reserved         */
    unsigned long  PPCMD8;                                 /* PPCMD8           */
    unsigned long  PPCMD9;                                 /* PPCMD9           */
    unsigned long  PPCMD10;                                /* PPCMD10          */
};
struct __tag313
{                                                          /* Module           */
    unsigned char  JP0;                                    /* JP0              */
    unsigned char  dummy96[15];                            /* Reserved         */
    unsigned long  JPSR0;                                  /* JPSR0            */
    unsigned char  dummy97[12];                            /* Reserved         */
    unsigned char  JPPR0;                                  /* JPPR0            */
    unsigned char  dummy98[15];                            /* Reserved         */
    unsigned char  JPM0;                                   /* JPM0             */
    unsigned char  dummy99[15];                            /* Reserved         */
    unsigned char  JPMC0;                                  /* JPMC0            */
    unsigned char  dummy100[15];                           /* Reserved         */
    unsigned char  JPFC0;                                  /* JPFC0            */
    unsigned char  dummy101[15];                           /* Reserved         */
    unsigned char  JPFCE0;                                 /* JPFCE0           */
    unsigned char  dummy102[15];                           /* Reserved         */
    unsigned char  JPNOT0;                                 /* JPNOT0           */
    unsigned char  dummy103[15];                           /* Reserved         */
    unsigned long  JPMSR0;                                 /* JPMSR0           */
    unsigned char  dummy104[12];                           /* Reserved         */
    unsigned long  JPMCSR0;                                /* JPMCSR0          */
    unsigned char  dummy105[876];                          /* Reserved         */
    unsigned char  JPIBC0;                                 /* JPIBC0           */
    unsigned char  dummy106[15];                           /* Reserved         */
    unsigned char  JPBDC0;                                 /* JPBDC0           */
    unsigned char  dummy107[31];                           /* Reserved         */
    unsigned char  JPU0;                                   /* JPU0             */
    unsigned char  dummy108[15];                           /* Reserved         */
    unsigned char  JPD0;                                   /* JPD0             */
    unsigned char  dummy109[15];                           /* Reserved         */
    unsigned long  JPODC0;                                 /* JPODC0           */
    unsigned char  dummy110[12];                           /* Reserved         */
    unsigned long  JPDSC0;                                 /* JPDSC0           */
    unsigned char  dummy111[12];                           /* Reserved         */
    unsigned char  JPIS0;                                  /* JPIS0            */
    unsigned char  dummy112[47];                           /* Reserved         */
    unsigned char  JPISA0;                                 /* JPISA0           */
    unsigned char  dummy113[15];                           /* Reserved         */
    unsigned long  JPPROTS0;                               /* JPPROTS0         */
    unsigned char  dummy114[12];                           /* Reserved         */
    unsigned long  JPPCMD0;                                /* JPPCMD0          */
};
struct __tag314
{                                                          /* Module           */
    unsigned char  ATAUD0ICTL;                             /* ATAUD0ICTL       */
    unsigned char  dummy115[3];                            /* Reserved         */
    unsigned short ATAUD0IEN;                              /* ATAUD0IEN        */
    unsigned char  dummy116[2];                            /* Reserved         */
    union __tag149 ATAUD0IENH;                             /* ATAUD0IENH       */
    unsigned char  dummy117[3];                            /* Reserved         */
    union __tag150 ATAUD0IENL;                             /* ATAUD0IENL       */
    unsigned char  dummy118[83];                           /* Reserved         */
    unsigned char  AENCA0ICTL;                             /* AENCA0ICTL       */
    unsigned char  dummy119[3];                            /* Reserved         */
    unsigned short AENCA0IEN;                              /* AENCA0IEN        */
    unsigned char  dummy120[6];                            /* Reserved         */
    union __tag151 AENCA0IENL;                             /* AENCA0IENL       */
    unsigned char  dummy121[51];                           /* Reserved         */
    unsigned char  AADCTL0CTL;                             /* AADCTL0CTL       */
    unsigned char  dummy122[3];                            /* Reserved         */
    unsigned short AADCTL0EN;                              /* AADCTL0EN        */
    unsigned char  dummy123[6];                            /* Reserved         */
    union __tag152 AADCTL0ENL;                             /* AADCTL0ENL       */
    unsigned char  dummy124[51];                           /* Reserved         */
    unsigned char  ASENTICTL;                              /* ASENTICTL        */
    unsigned char  dummy125[3];                            /* Reserved         */
    unsigned short ASENTIEN;                               /* ASENTIEN         */
    unsigned char  dummy126[6];                            /* Reserved         */
    union __tag153 ASENTIENL;                              /* ASENTIENL        */
};
struct __tag315
{                                                          /* Module           */
    unsigned char  CTL0_NMI;                               /* CTL0_NMI         */
    unsigned char  dummy127[31];                           /* Reserved         */
    unsigned char  CTL0_INTPL;                             /* CTL0_INTPL       */
    unsigned char  dummy128[3];                            /* Reserved         */
    unsigned char  CTL1_INTPL;                             /* CTL1_INTPL       */
    unsigned char  dummy129[3];                            /* Reserved         */
    unsigned char  CTL2_INTPL;                             /* CTL2_INTPL       */
    unsigned char  dummy130[3];                            /* Reserved         */
    unsigned char  CTL3_INTPL;                             /* CTL3_INTPL       */
    unsigned char  dummy131[3];                            /* Reserved         */
    unsigned char  CTL4_INTPL;                             /* CTL4_INTPL       */
    unsigned char  dummy132[3];                            /* Reserved         */
    unsigned char  CTL5_INTPL;                             /* CTL5_INTPL       */
    unsigned char  dummy133[19];                           /* Reserved         */
    unsigned char  CTL2_INTPH;                             /* CTL2_INTPH       */
    unsigned char  dummy134[3];                            /* Reserved         */
    unsigned char  CTL3_INTPH;                             /* CTL3_INTPH       */
    unsigned char  dummy135[19];                           /* Reserved         */
    unsigned char  CTL0_ADC0;                              /* CTL0_ADC0        */
    unsigned char  dummy136[3];                            /* Reserved         */
    unsigned char  CTL1_ADC0;                              /* CTL1_ADC0        */
    unsigned char  dummy137[3];                            /* Reserved         */
    unsigned char  CTL2_ADC0;                              /* CTL2_ADC0        */
};
struct __tag316
{                                                          /* Module           */
    union __tag148 FSGD00PROT0;                            /* FSGD00PROT0      */
    union __tag148 FSGD00PROT1;                            /* FSGD00PROT1      */
    union __tag148 FSGD00PROT2;                            /* FSGD00PROT2      */
    union __tag148 FSGD00PROT3;                            /* FSGD00PROT3      */
    union __tag148 FSGD00PROT4;                            /* FSGD00PROT4      */
    union __tag148 FSGD00PROT5;                            /* FSGD00PROT5      */
    union __tag148 FSGD00PROT6;                            /* FSGD00PROT6      */
    union __tag148 FSGD00PROT7;                            /* FSGD00PROT7      */
    union __tag148 FSGD00PROT8;                            /* FSGD00PROT8      */
    unsigned char  dummy138[28];                           /* Reserved         */
    union __tag148 ERRSLV00CTL;                            /* ERRSLV00CTL      */
    union __tag148 ERRSLV00STAT;                           /* ERRSLV00STAT     */
    unsigned long  ERRSLV00ADDR;                           /* ERRSLV00ADDR     */
    union __tag154 ERRSLV00TYPE;                           /* ERRSLV00TYPE     */
};
struct __tag317
{                                                          /* Module           */
    union __tag148 FSGD01PROT0;                            /* FSGD01PROT0      */
    union __tag148 FSGD01PROT1;                            /* FSGD01PROT1      */
    union __tag148 FSGD01PROT2;                            /* FSGD01PROT2      */
    union __tag148 FSGD01PROT3;                            /* FSGD01PROT3      */
    union __tag148 FSGD01PROT4;                            /* FSGD01PROT4      */
    union __tag148 FSGD01PROT5;                            /* FSGD01PROT5      */
    union __tag148 FSGD01PROT6;                            /* FSGD01PROT6      */
    unsigned char  dummy139[20];                           /* Reserved         */
    union __tag148 FSGD01PROT12;                           /* FSGD01PROT12     */
    union __tag148 FSGD01PROT13;                           /* FSGD01PROT13     */
    union __tag148 FSGD01PROT14;                           /* FSGD01PROT14     */
    unsigned char  dummy140[4];                            /* Reserved         */
    union __tag148 ERRSLV01CTL;                            /* ERRSLV01CTL      */
    union __tag148 ERRSLV01STAT;                           /* ERRSLV01STAT     */
    unsigned long  ERRSLV01ADDR;                           /* ERRSLV01ADDR     */
    union __tag154 ERRSLV01TYPE;                           /* ERRSLV01TYPE     */
};
struct __tag318
{                                                          /* Module           */
    union __tag148 FSGD07PROT0;                            /* FSGD07PROT0      */
    union __tag148 FSGD07PROT1;                            /* FSGD07PROT1      */
    union __tag148 FSGD07PROT2;                            /* FSGD07PROT2      */
    unsigned char  dummy141[48];                           /* Reserved         */
    union __tag148 FSGD07PROT15;                           /* FSGD07PROT15     */
    union __tag148 ERRSLV07CTL;                            /* ERRSLV07CTL      */
    union __tag148 ERRSLV07STAT;                           /* ERRSLV07STAT     */
    unsigned long  ERRSLV07ADDR;                           /* ERRSLV07ADDR     */
    union __tag154 ERRSLV07TYPE;                           /* ERRSLV07TYPE     */
};
struct __tag319
{                                                          /* Module           */
    union __tag148 FSGD08PROT0;                            /* FSGD08PROT0      */
    unsigned char  dummy142[12];                           /* Reserved         */
    union __tag148 FSGD08PROT4;                            /* FSGD08PROT4      */
    union __tag148 FSGD08PROT5;                            /* FSGD08PROT5      */
    union __tag148 FSGD08PROT6;                            /* FSGD08PROT6      */
    unsigned char  dummy143[4];                            /* Reserved         */
    union __tag148 FSGD08PROT8;                            /* FSGD08PROT8      */
    unsigned char  dummy144[16];                           /* Reserved         */
    union __tag148 FSGD08PROT13;                           /* FSGD08PROT13     */
    union __tag148 FSGD08PROT14;                           /* FSGD08PROT14     */
    unsigned char  dummy145[4];                            /* Reserved         */
    union __tag148 ERRSLV08CTL;                            /* ERRSLV08CTL      */
    union __tag148 ERRSLV08STAT;                           /* ERRSLV08STAT     */
    unsigned long  ERRSLV08ADDR;                           /* ERRSLV08ADDR     */
    union __tag154 ERRSLV08TYPE;                           /* ERRSLV08TYPE     */
};
struct __tag320
{                                                          /* Module           */
    union __tag148 FSGDC0PROT0;                            /* FSGDC0PROT0      */
    union __tag148 FSGDC0PROT1;                            /* FSGDC0PROT1      */
    unsigned char  dummy146[2040];                         /* Reserved         */
    union __tag148 ERRSLVC0CTL;                            /* ERRSLVC0CTL      */
    union __tag148 ERRSLVC0STAT;                           /* ERRSLVC0STAT     */
    unsigned long  ERRSLVC0ADDR;                           /* ERRSLVC0ADDR     */
    union __tag154 ERRSLVC0TYPE;                           /* ERRSLVC0TYPE     */
};
struct __tag321
{                                                          /* Module           */
    union __tag148 FSGDC1PROT0;                            /* FSGDC1PROT0      */
    union __tag148 FSGDC1PROT1;                            /* FSGDC1PROT1      */
    union __tag148 FSGDC1PROT2;                            /* FSGDC1PROT2      */
    union __tag148 FSGDC1PROT3;                            /* FSGDC1PROT3      */
    union __tag148 FSGDC1PROT4;                            /* FSGDC1PROT4      */
    union __tag148 FSGDC1PROT5;                            /* FSGDC1PROT5      */
    unsigned char  dummy147[1992];                         /* Reserved         */
    union __tag148 ERRSLVC1CTL;                            /* ERRSLVC1CTL      */
    union __tag148 ERRSLVC1STAT;                           /* ERRSLVC1STAT     */
    unsigned long  ERRSLVC1ADDR;                           /* ERRSLVC1ADDR     */
    union __tag154 ERRSLVC1TYPE;                           /* ERRSLVC1TYPE     */
};
struct __tag322
{                                                          /* Module           */
    unsigned char  EEPRDCYCL;                              /* EEPRDCYCL        */
};
struct __tag323
{                                                          /* Module           */
    union __tag148 FBUFCCTL;                               /* FBUFCCTL         */
};
struct __tag324
{                                                          /* Module           */
    union __tag154 CFECCCTL_VCI;                           /* CFECCCTL_VCI     */
    union __tag148 CFERRINT_VCI;                           /* CFERRINT_VCI     */
    union __tag148 CFSTCLR_VCI;                            /* CFSTCLR_VCI      */
    union __tag148 CFOVFSTR_VCI;                           /* CFOVFSTR_VCI     */
    union __tag148 CF1STERSTR_VCI;                         /* CF1STERSTR_VCI   */
    unsigned char  dummy148[60];                           /* Reserved         */
    union __tag148 CF1STEADR0_VCI;                         /* CF1STEADR0_VCI   */
    unsigned char  dummy149[252];                          /* Reserved         */
    union __tag154 CFSTSTCTL_VCI;                          /* CFSTSTCTL_VCI    */
};
struct __tag325
{                                                          /* Module           */
    union __tag154 CFECCCTL_PE1;                           /* CFECCCTL_PE1     */
    union __tag148 CFERRINT_PE1;                           /* CFERRINT_PE1     */
    union __tag148 CFSTCLR_PE1;                            /* CFSTCLR_PE1      */
    union __tag148 CFOVFSTR_PE1;                           /* CFOVFSTR_PE1     */
    union __tag148 CF1STERSTR_PE1;                         /* CF1STERSTR_PE1   */
    unsigned char  dummy150[60];                           /* Reserved         */
    union __tag148 CF1STEADR0_PE1;                         /* CF1STEADR0_PE1   */
};
struct __tag326
{                                                          /* Module           */
    unsigned short CTL;                                    /* CTL              */
    unsigned char  dummy151[2];                            /* Reserved         */
    unsigned char  DFERSTR;                                /* DFERSTR          */
    unsigned char  dummy152[3];                            /* Reserved         */
    unsigned char  DFERSTC;                                /* DFERSTC          */
    unsigned char  dummy153[3];                            /* Reserved         */
    unsigned char  DFOVFSTR;                               /* DFOVFSTR         */
    unsigned char  dummy154[3];                            /* Reserved         */
    unsigned char  DFOVFSTC;                               /* DFOVFSTC         */
    unsigned char  dummy155[3];                            /* Reserved         */
    unsigned char  DFERRINT;                               /* DFERRINT         */
    unsigned char  dummy156[3];                            /* Reserved         */
    unsigned long  DFEADR;                                 /* DFEADR           */
    unsigned short DFTSTCTL;                               /* DFTSTCTL         */
};
struct __tag327
{                                                          /* Module           */
    union __tag154 CTL_PE1;                                /* CTL_PE1          */
    unsigned long  LRTDATBF0_PE1;                          /* LRTDATBF0_PE1    */
};
struct __tag328
{                                                          /* Module           */
    union __tag154 CTL_PE1;                                /* CTL_PE1          */
    union __tag148 LRERRINT_PE1;                           /* LRERRINT_PE1     */
    union __tag148 LRSTCLR_PE1;                            /* LRSTCLR_PE1      */
    union __tag148 LROVFSTR_PE1;                           /* LROVFSTR_PE1     */
    union __tag148 LR1STERSTR_PE1;                         /* LR1STERSTR_PE1   */
    unsigned char  dummy157[60];                           /* Reserved         */
    union __tag148 LR1STEADR0_PE1;                         /* LR1STEADR0_PE1   */
};
struct __tag329
{                                                          /* Module           */
    unsigned short CTL;                                    /* CTL              */
    unsigned char  dummy158[2];                            /* Reserved         */
    unsigned short TMC;                                    /* TMC              */
    unsigned char  dummy159[2];                            /* Reserved         */
    union __tag155 TRC;                                    /* TRC              */
    unsigned long  TED;                                    /* TED              */
    unsigned long  AD0;                                    /* AD0              */
};
struct __tag330
{                                                          /* Module           */
    unsigned short SELB_READTEST;                          /* SELB_READTEST    */
};
struct __tag331
{                                                          /* Module           */
    union __tag148 CR1;                                    /* CR1              */
    union __tag148 CR2;                                    /* CR2              */
    union __tag148 MR1;                                    /* MR1              */
    union __tag148 MR2;                                    /* MR2              */
    union __tag148 MR3;                                    /* MR3              */
    union __tag148 FER;                                    /* FER              */
    union __tag148 SER;                                    /* SER              */
    union __tag148 IER;                                    /* IER              */
    union __tag148 SR1;                                    /* SR1              */
    union __tag148 SR2;                                    /* SR2              */
    union __tag148 SAR0;                                   /* SAR0             */
    union __tag148 SAR1;                                   /* SAR1             */
    union __tag148 SAR2;                                   /* SAR2             */
    union __tag148 BRL;                                    /* BRL              */
    union __tag148 BRH;                                    /* BRH              */
    union __tag148 DRT;                                    /* DRT              */
    union __tag148 DRR;                                    /* DRR              */
};
struct __tag332
{                                                          /* Module           */
    unsigned long  PRDNAME1;                               /* PRDNAME1         */
    unsigned long  PRDNAME2;                               /* PRDNAME2         */
    unsigned long  PRDNAME3;                               /* PRDNAME3         */
    unsigned char  dummy160[4];                            /* Reserved         */
    unsigned long  CHIPID1LL;                              /* CHIPID1LL        */
    unsigned long  CHIPID1LH;                              /* CHIPID1LH        */
    unsigned long  CHIPID1HL;                              /* CHIPID1HL        */
    unsigned long  CHIPID1HH;                              /* CHIPID1HH        */
    unsigned long  CHIPID2LL;                              /* CHIPID2LL        */
    unsigned long  CHIPID2LH;                              /* CHIPID2LH        */
    unsigned long  CHIPID2HL;                              /* CHIPID2HL        */
    unsigned long  CHIPID2HH;                              /* CHIPID2HH        */
};
struct __tag333
{                                                          /* Module           */
    unsigned char  dummy161[1];                            /* Reserved         */
    unsigned char  GLWBR;                                  /* GLWBR            */
    unsigned char  GLBRP0;                                 /* GLBRP0           */
    unsigned char  GLBRP1;                                 /* GLBRP1           */
    unsigned char  GLSTC;                                  /* GLSTC            */
};
struct __tag334
{                                                          /* Module           */
    unsigned char  L0MD;                                   /* L0MD             */
    unsigned char  L0BFC;                                  /* L0BFC            */
    unsigned char  L0SC;                                   /* L0SC             */
    unsigned char  L0WUP;                                  /* L0WUP            */
    unsigned char  L0IE;                                   /* L0IE             */
    unsigned char  L0EDE;                                  /* L0EDE            */
    unsigned char  L0CUC;                                  /* L0CUC            */
    unsigned char  dummy162[1];                            /* Reserved         */
    unsigned char  L0TRC;                                  /* L0TRC            */
    unsigned char  L0MST;                                  /* L0MST            */
    unsigned char  L0ST;                                   /* L0ST             */
    unsigned char  L0EST;                                  /* L0EST            */
    unsigned char  L0DFC;                                  /* L0DFC            */
    unsigned char  L0IDB;                                  /* L0IDB            */
    unsigned char  L0CBR;                                  /* L0CBR            */
    unsigned char  dummy163[1];                            /* Reserved         */
    unsigned char  L0DBR1;                                 /* L0DBR1           */
    unsigned char  L0DBR2;                                 /* L0DBR2           */
    unsigned char  L0DBR3;                                 /* L0DBR3           */
    unsigned char  L0DBR4;                                 /* L0DBR4           */
    unsigned char  L0DBR5;                                 /* L0DBR5           */
    unsigned char  L0DBR6;                                 /* L0DBR6           */
    unsigned char  L0DBR7;                                 /* L0DBR7           */
    unsigned char  L0DBR8;                                 /* L0DBR8           */
};
struct __tag335
{                                                          /* Module           */
    unsigned char  L1MD;                                   /* L1MD             */
    unsigned char  L1BFC;                                  /* L1BFC            */
    unsigned char  L1SC;                                   /* L1SC             */
    unsigned char  L1WUP;                                  /* L1WUP            */
    unsigned char  L1IE;                                   /* L1IE             */
    unsigned char  L1EDE;                                  /* L1EDE            */
    unsigned char  L1CUC;                                  /* L1CUC            */
    unsigned char  dummy164[1];                            /* Reserved         */
    unsigned char  L1TRC;                                  /* L1TRC            */
    unsigned char  L1MST;                                  /* L1MST            */
    unsigned char  L1ST;                                   /* L1ST             */
    unsigned char  L1EST;                                  /* L1EST            */
    unsigned char  L1DFC;                                  /* L1DFC            */
    unsigned char  L1IDB;                                  /* L1IDB            */
    unsigned char  L1CBR;                                  /* L1CBR            */
    unsigned char  dummy165[1];                            /* Reserved         */
    unsigned char  L1DBR1;                                 /* L1DBR1           */
    unsigned char  L1DBR2;                                 /* L1DBR2           */
    unsigned char  L1DBR3;                                 /* L1DBR3           */
    unsigned char  L1DBR4;                                 /* L1DBR4           */
    unsigned char  L1DBR5;                                 /* L1DBR5           */
    unsigned char  L1DBR6;                                 /* L1DBR6           */
    unsigned char  L1DBR7;                                 /* L1DBR7           */
    unsigned char  L1DBR8;                                 /* L1DBR8           */
};
struct __tag336
{                                                          /* Module           */
    unsigned char  dummy166[1];                            /* Reserved         */
    unsigned char  LWBR;                                   /* LWBR             */
    union __tag156 LBRP01;                                 /* LBRP01           */
    unsigned char  LSTC;                                   /* LSTC             */
    unsigned char  dummy167[3];                            /* Reserved         */
    unsigned char  LMD;                                    /* LMD              */
    unsigned char  LBFC;                                   /* LBFC             */
    unsigned char  LSC;                                    /* LSC              */
    unsigned char  LWUP;                                   /* LWUP             */
    unsigned char  LIE;                                    /* LIE              */
    unsigned char  LEDE;                                   /* LEDE             */
    unsigned char  LCUC;                                   /* LCUC             */
    unsigned char  dummy168[1];                            /* Reserved         */
    unsigned char  LTRC;                                   /* LTRC             */
    unsigned char  LMST;                                   /* LMST             */
    unsigned char  LST;                                    /* LST              */
    unsigned char  LEST;                                   /* LEST             */
    unsigned char  LDFC;                                   /* LDFC             */
    unsigned char  LIDB;                                   /* LIDB             */
    unsigned char  LCBR;                                   /* LCBR             */
    unsigned char  LUDB0;                                  /* LUDB0            */
    unsigned char  LDBR1;                                  /* LDBR1            */
    unsigned char  LDBR2;                                  /* LDBR2            */
    unsigned char  LDBR3;                                  /* LDBR3            */
    unsigned char  LDBR4;                                  /* LDBR4            */
    unsigned char  LDBR5;                                  /* LDBR5            */
    unsigned char  LDBR6;                                  /* LDBR6            */
    unsigned char  LDBR7;                                  /* LDBR7            */
    unsigned char  LDBR8;                                  /* LDBR8            */
    unsigned char  LUOER;                                  /* LUOER            */
    unsigned char  LUOR1;                                  /* LUOR1            */
    unsigned char  dummy169[2];                            /* Reserved         */
    union __tag157 LUTDR;                                  /* LUTDR            */
    union __tag157 LURDR;                                  /* LURDR            */
    union __tag157 LUWTDR;                                 /* LUWTDR           */
};
struct __tag337
{                                                          /* Module           */
    unsigned long  TSPC;                                   /* TSPC             */
    unsigned long  TSC;                                    /* TSC              */
    unsigned char  dummy170[8];                            /* Reserved         */
    unsigned long  CC;                                     /* CC               */
    unsigned long  BRP;                                    /* BRP              */
    unsigned long  IDE;                                    /* IDE              */
    unsigned long  MDC;                                    /* MDC              */
    unsigned long  SPCT;                                   /* SPCT             */
    unsigned long  MST;                                    /* MST              */
    unsigned long  CS;                                     /* CS               */
    unsigned long  CSC;                                    /* CSC              */
    unsigned long  SRTS;                                   /* SRTS             */
    unsigned long  SRXD;                                   /* SRXD             */
    unsigned long  CPL;                                    /* CPL              */
    unsigned long  ML;                                     /* ML               */
    unsigned long  FRTS;                                   /* FRTS             */
    unsigned long  FRXD;                                   /* FRXD             */
};
struct __tag338
{                                                          /* Module           */
    union __tag148 CFDC0NCFG;                              /* CFDC0NCFG        */
    union __tag148 CFDC0CTR;                               /* CFDC0CTR         */
    union __tag148 CFDC0STS;                               /* CFDC0STS         */
    union __tag148 CFDC0ERFL;                              /* CFDC0ERFL        */
    unsigned char  dummy171[116];                          /* Reserved         */
    union __tag148 CFDGCFG;                                /* CFDGCFG          */
    union __tag148 CFDGCTR;                                /* CFDGCTR          */
    union __tag148 CFDGSTS;                                /* CFDGSTS          */
    union __tag148 CFDGERFL;                               /* CFDGERFL         */
    union __tag154 CFDGTSC;                                /* CFDGTSC          */
    union __tag148 CFDGAFLECTR;                            /* CFDGAFLECTR      */
    union __tag148 CFDGAFLCFG0;                            /* CFDGAFLCFG0      */
    unsigned char  dummy172[4];                            /* Reserved         */
    union __tag148 CFDRMNB;                                /* CFDRMNB          */
    union __tag148 CFDRMND0;                               /* CFDRMND0         */
    unsigned char  dummy173[12];                           /* Reserved         */
    union __tag148 CFDRFCC0;                               /* CFDRFCC0         */
    union __tag148 CFDRFCC1;                               /* CFDRFCC1         */
    union __tag148 CFDRFCC2;                               /* CFDRFCC2         */
    union __tag148 CFDRFCC3;                               /* CFDRFCC3         */
    union __tag148 CFDRFCC4;                               /* CFDRFCC4         */
    union __tag148 CFDRFCC5;                               /* CFDRFCC5         */
    union __tag148 CFDRFCC6;                               /* CFDRFCC6         */
    union __tag148 CFDRFCC7;                               /* CFDRFCC7         */
    union __tag148 CFDRFSTS0;                              /* CFDRFSTS0        */
    union __tag148 CFDRFSTS1;                              /* CFDRFSTS1        */
    union __tag148 CFDRFSTS2;                              /* CFDRFSTS2        */
    union __tag148 CFDRFSTS3;                              /* CFDRFSTS3        */
    union __tag148 CFDRFSTS4;                              /* CFDRFSTS4        */
    union __tag148 CFDRFSTS5;                              /* CFDRFSTS5        */
    union __tag148 CFDRFSTS6;                              /* CFDRFSTS6        */
    union __tag148 CFDRFSTS7;                              /* CFDRFSTS7        */
    union __tag148 CFDRFPCTR0;                             /* CFDRFPCTR0       */
    union __tag148 CFDRFPCTR1;                             /* CFDRFPCTR1       */
    union __tag148 CFDRFPCTR2;                             /* CFDRFPCTR2       */
    union __tag148 CFDRFPCTR3;                             /* CFDRFPCTR3       */
    union __tag148 CFDRFPCTR4;                             /* CFDRFPCTR4       */
    union __tag148 CFDRFPCTR5;                             /* CFDRFPCTR5       */
    union __tag148 CFDRFPCTR6;                             /* CFDRFPCTR6       */
    union __tag148 CFDRFPCTR7;                             /* CFDRFPCTR7       */
    union __tag148 CFDCFCC0;                               /* CFDCFCC0         */
    union __tag148 CFDCFCC1;                               /* CFDCFCC1         */
    union __tag148 CFDCFCC2;                               /* CFDCFCC2         */
    unsigned char  dummy174[84];                           /* Reserved         */
    union __tag148 CFDCFSTS0;                              /* CFDCFSTS0        */
    union __tag148 CFDCFSTS1;                              /* CFDCFSTS1        */
    union __tag148 CFDCFSTS2;                              /* CFDCFSTS2        */
    unsigned char  dummy175[84];                           /* Reserved         */
    union __tag148 CFDCFPCTR0;                             /* CFDCFPCTR0       */
    union __tag148 CFDCFPCTR1;                             /* CFDCFPCTR1       */
    union __tag148 CFDCFPCTR2;                             /* CFDCFPCTR2       */
    unsigned char  dummy176[84];                           /* Reserved         */
    union __tag148 CFDFESTS;                               /* CFDFESTS         */
    union __tag148 CFDFFSTS;                               /* CFDFFSTS         */
    union __tag148 CFDFMSTS;                               /* CFDFMSTS         */
    union __tag148 CFDRFISTS;                              /* CFDRFISTS        */
    union __tag148 CFDCFRISTS;                             /* CFDCFRISTS       */
    union __tag148 CFDCFTISTS;                             /* CFDCFTISTS       */
    unsigned char  CFDTMC0;                                /* CFDTMC0          */
    unsigned char  CFDTMC1;                                /* CFDTMC1          */
    unsigned char  CFDTMC2;                                /* CFDTMC2          */
    unsigned char  CFDTMC3;                                /* CFDTMC3          */
    unsigned char  CFDTMC4;                                /* CFDTMC4          */
    unsigned char  CFDTMC5;                                /* CFDTMC5          */
    unsigned char  CFDTMC6;                                /* CFDTMC6          */
    unsigned char  CFDTMC7;                                /* CFDTMC7          */
    unsigned char  CFDTMC8;                                /* CFDTMC8          */
    unsigned char  CFDTMC9;                                /* CFDTMC9          */
    unsigned char  CFDTMC10;                               /* CFDTMC10         */
    unsigned char  CFDTMC11;                               /* CFDTMC11         */
    unsigned char  CFDTMC12;                               /* CFDTMC12         */
    unsigned char  CFDTMC13;                               /* CFDTMC13         */
    unsigned char  CFDTMC14;                               /* CFDTMC14         */
    unsigned char  CFDTMC15;                               /* CFDTMC15         */
    unsigned char  CFDTMC16;                               /* CFDTMC16         */
    unsigned char  CFDTMC17;                               /* CFDTMC17         */
    unsigned char  CFDTMC18;                               /* CFDTMC18         */
    unsigned char  CFDTMC19;                               /* CFDTMC19         */
    unsigned char  CFDTMC20;                               /* CFDTMC20         */
    unsigned char  CFDTMC21;                               /* CFDTMC21         */
    unsigned char  CFDTMC22;                               /* CFDTMC22         */
    unsigned char  CFDTMC23;                               /* CFDTMC23         */
    unsigned char  CFDTMC24;                               /* CFDTMC24         */
    unsigned char  CFDTMC25;                               /* CFDTMC25         */
    unsigned char  CFDTMC26;                               /* CFDTMC26         */
    unsigned char  CFDTMC27;                               /* CFDTMC27         */
    unsigned char  CFDTMC28;                               /* CFDTMC28         */
    unsigned char  CFDTMC29;                               /* CFDTMC29         */
    unsigned char  CFDTMC30;                               /* CFDTMC30         */
    unsigned char  CFDTMC31;                               /* CFDTMC31         */
    unsigned char  dummy177[224];                          /* Reserved         */
    unsigned char  CFDTMSTS0;                              /* CFDTMSTS0        */
    unsigned char  CFDTMSTS1;                              /* CFDTMSTS1        */
    unsigned char  CFDTMSTS2;                              /* CFDTMSTS2        */
    unsigned char  CFDTMSTS3;                              /* CFDTMSTS3        */
    unsigned char  CFDTMSTS4;                              /* CFDTMSTS4        */
    unsigned char  CFDTMSTS5;                              /* CFDTMSTS5        */
    unsigned char  CFDTMSTS6;                              /* CFDTMSTS6        */
    unsigned char  CFDTMSTS7;                              /* CFDTMSTS7        */
    unsigned char  CFDTMSTS8;                              /* CFDTMSTS8        */
    unsigned char  CFDTMSTS9;                              /* CFDTMSTS9        */
    unsigned char  CFDTMSTS10;                             /* CFDTMSTS10       */
    unsigned char  CFDTMSTS11;                             /* CFDTMSTS11       */
    unsigned char  CFDTMSTS12;                             /* CFDTMSTS12       */
    unsigned char  CFDTMSTS13;                             /* CFDTMSTS13       */
    unsigned char  CFDTMSTS14;                             /* CFDTMSTS14       */
    unsigned char  CFDTMSTS15;                             /* CFDTMSTS15       */
    unsigned char  CFDTMSTS16;                             /* CFDTMSTS16       */
    unsigned char  CFDTMSTS17;                             /* CFDTMSTS17       */
    unsigned char  CFDTMSTS18;                             /* CFDTMSTS18       */
    unsigned char  CFDTMSTS19;                             /* CFDTMSTS19       */
    unsigned char  CFDTMSTS20;                             /* CFDTMSTS20       */
    unsigned char  CFDTMSTS21;                             /* CFDTMSTS21       */
    unsigned char  CFDTMSTS22;                             /* CFDTMSTS22       */
    unsigned char  CFDTMSTS23;                             /* CFDTMSTS23       */
    unsigned char  CFDTMSTS24;                             /* CFDTMSTS24       */
    unsigned char  CFDTMSTS25;                             /* CFDTMSTS25       */
    unsigned char  CFDTMSTS26;                             /* CFDTMSTS26       */
    unsigned char  CFDTMSTS27;                             /* CFDTMSTS27       */
    unsigned char  CFDTMSTS28;                             /* CFDTMSTS28       */
    unsigned char  CFDTMSTS29;                             /* CFDTMSTS29       */
    unsigned char  CFDTMSTS30;                             /* CFDTMSTS30       */
    unsigned char  CFDTMSTS31;                             /* CFDTMSTS31       */
    unsigned char  dummy178[224];                          /* Reserved         */
    union __tag148 CFDTMTRSTS0;                            /* CFDTMTRSTS0      */
    unsigned char  dummy179[28];                           /* Reserved         */
    union __tag148 CFDTMTARSTS0;                           /* CFDTMTARSTS0     */
    unsigned char  dummy180[28];                           /* Reserved         */
    union __tag148 CFDTMTCSTS0;                            /* CFDTMTCSTS0      */
    unsigned char  dummy181[28];                           /* Reserved         */
    union __tag148 CFDTMTASTS0;                            /* CFDTMTASTS0      */
    unsigned char  dummy182[28];                           /* Reserved         */
    union __tag148 CFDTMIEC0;                              /* CFDTMIEC0        */
    unsigned char  dummy183[124];                          /* Reserved         */
    union __tag148 CFDTXQCC0;                              /* CFDTXQCC0        */
    unsigned char  dummy184[28];                           /* Reserved         */
    union __tag148 CFDTXQSTS0;                             /* CFDTXQSTS0       */
    unsigned char  dummy185[28];                           /* Reserved         */
    union __tag148 CFDTXQPCTR0;                            /* CFDTXQPCTR0      */
    unsigned char  dummy186[28];                           /* Reserved         */
    union __tag148 CFDTHLCC0;                              /* CFDTHLCC0        */
    unsigned char  dummy187[28];                           /* Reserved         */
    union __tag148 CFDTHLSTS0;                             /* CFDTHLSTS0       */
    unsigned char  dummy188[28];                           /* Reserved         */
    union __tag148 CFDTHLPCTR0;                            /* CFDTHLPCTR0      */
    unsigned char  dummy189[28];                           /* Reserved         */
    union __tag148 CFDGTINTSTS0;                           /* CFDGTINTSTS0     */
    unsigned char  dummy190[4];                            /* Reserved         */
    union __tag148 CFDGTSTCFG;                             /* CFDGTSTCFG       */
    union __tag148 CFDGTSTCTR;                             /* CFDGTSTCTR       */
    unsigned char  dummy191[4];                            /* Reserved         */
    union __tag148 CFDGFDCFG;                              /* CFDGFDCFG        */
    unsigned char  dummy192[4];                            /* Reserved         */
    union __tag154 CFDGLOCKK;                              /* CFDGLOCKK        */
    unsigned char  dummy193[16];                           /* Reserved         */
    union __tag148 CFDCDTCT;                               /* CFDCDTCT         */
    union __tag148 CFDCDTSTS;                              /* CFDCDTSTS        */
    unsigned char  dummy194[184];                          /* Reserved         */
    union __tag148 CFDC0DCFG;                              /* CFDC0DCFG        */
    union __tag148 CFDC0FDCFG;                             /* CFDC0FDCFG       */
    union __tag148 CFDC0FDCTR;                             /* CFDC0FDCTR       */
    union __tag148 CFDC0FDSTS;                             /* CFDC0FDSTS       */
    union __tag148 CFDC0FDCRC;                             /* CFDC0FDCRC       */
    unsigned char  dummy195[2284];                         /* Reserved         */
    union __tag148 CFDGAFLID0;                             /* CFDGAFLID0       */
    union __tag148 CFDGAFLM0;                              /* CFDGAFLM0        */
    union __tag148 CFDGAFLP0_0;                            /* CFDGAFLP0_0      */
    union __tag148 CFDGAFLP1_0;                            /* CFDGAFLP1_0      */
    union __tag148 CFDGAFLID1;                             /* CFDGAFLID1       */
    union __tag148 CFDGAFLM1;                              /* CFDGAFLM1        */
    union __tag148 CFDGAFLP0_1;                            /* CFDGAFLP0_1      */
    union __tag148 CFDGAFLP1_1;                            /* CFDGAFLP1_1      */
    union __tag148 CFDGAFLID2;                             /* CFDGAFLID2       */
    union __tag148 CFDGAFLM2;                              /* CFDGAFLM2        */
    union __tag148 CFDGAFLP0_2;                            /* CFDGAFLP0_2      */
    union __tag148 CFDGAFLP1_2;                            /* CFDGAFLP1_2      */
    union __tag148 CFDGAFLID3;                             /* CFDGAFLID3       */
    union __tag148 CFDGAFLM3;                              /* CFDGAFLM3        */
    union __tag148 CFDGAFLP0_3;                            /* CFDGAFLP0_3      */
    union __tag148 CFDGAFLP1_3;                            /* CFDGAFLP1_3      */
    union __tag148 CFDGAFLID4;                             /* CFDGAFLID4       */
    union __tag148 CFDGAFLM4;                              /* CFDGAFLM4        */
    union __tag148 CFDGAFLP0_4;                            /* CFDGAFLP0_4      */
    union __tag148 CFDGAFLP1_4;                            /* CFDGAFLP1_4      */
    union __tag148 CFDGAFLID5;                             /* CFDGAFLID5       */
    union __tag148 CFDGAFLM5;                              /* CFDGAFLM5        */
    union __tag148 CFDGAFLP0_5;                            /* CFDGAFLP0_5      */
    union __tag148 CFDGAFLP1_5;                            /* CFDGAFLP1_5      */
    union __tag148 CFDGAFLID6;                             /* CFDGAFLID6       */
    union __tag148 CFDGAFLM6;                              /* CFDGAFLM6        */
    union __tag148 CFDGAFLP0_6;                            /* CFDGAFLP0_6      */
    union __tag148 CFDGAFLP1_6;                            /* CFDGAFLP1_6      */
    union __tag148 CFDGAFLID7;                             /* CFDGAFLID7       */
    union __tag148 CFDGAFLM7;                              /* CFDGAFLM7        */
    union __tag148 CFDGAFLP0_7;                            /* CFDGAFLP0_7      */
    union __tag148 CFDGAFLP1_7;                            /* CFDGAFLP1_7      */
    union __tag148 CFDGAFLID8;                             /* CFDGAFLID8       */
    union __tag148 CFDGAFLM8;                              /* CFDGAFLM8        */
    union __tag148 CFDGAFLP0_8;                            /* CFDGAFLP0_8      */
    union __tag148 CFDGAFLP1_8;                            /* CFDGAFLP1_8      */
    union __tag148 CFDGAFLID9;                             /* CFDGAFLID9       */
    union __tag148 CFDGAFLM9;                              /* CFDGAFLM9        */
    union __tag148 CFDGAFLP0_9;                            /* CFDGAFLP0_9      */
    union __tag148 CFDGAFLP1_9;                            /* CFDGAFLP1_9      */
    union __tag148 CFDGAFLID10;                            /* CFDGAFLID10      */
    union __tag148 CFDGAFLM10;                             /* CFDGAFLM10       */
    union __tag148 CFDGAFLP0_10;                           /* CFDGAFLP0_10     */
    union __tag148 CFDGAFLP1_10;                           /* CFDGAFLP1_10     */
    union __tag148 CFDGAFLID11;                            /* CFDGAFLID11      */
    union __tag148 CFDGAFLM11;                             /* CFDGAFLM11       */
    union __tag148 CFDGAFLP0_11;                           /* CFDGAFLP0_11     */
    union __tag148 CFDGAFLP1_11;                           /* CFDGAFLP1_11     */
    union __tag148 CFDGAFLID12;                            /* CFDGAFLID12      */
    union __tag148 CFDGAFLM12;                             /* CFDGAFLM12       */
    union __tag148 CFDGAFLP0_12;                           /* CFDGAFLP0_12     */
    union __tag148 CFDGAFLP1_12;                           /* CFDGAFLP1_12     */
    union __tag148 CFDGAFLID13;                            /* CFDGAFLID13      */
    union __tag148 CFDGAFLM13;                             /* CFDGAFLM13       */
    union __tag148 CFDGAFLP0_13;                           /* CFDGAFLP0_13     */
    union __tag148 CFDGAFLP1_13;                           /* CFDGAFLP1_13     */
    union __tag148 CFDGAFLID14;                            /* CFDGAFLID14      */
    union __tag148 CFDGAFLM14;                             /* CFDGAFLM14       */
    union __tag148 CFDGAFLP0_14;                           /* CFDGAFLP0_14     */
    union __tag148 CFDGAFLP1_14;                           /* CFDGAFLP1_14     */
    union __tag148 CFDGAFLID15;                            /* CFDGAFLID15      */
    union __tag148 CFDGAFLM15;                             /* CFDGAFLM15       */
    union __tag148 CFDGAFLP0_15;                           /* CFDGAFLP0_15     */
    union __tag148 CFDGAFLP1_15;                           /* CFDGAFLP1_15     */
    unsigned char  dummy196[3840];                         /* Reserved         */
    union __tag148 CFDRMID0;                               /* CFDRMID0         */
    union __tag148 CFDRMPTR0;                              /* CFDRMPTR0        */
    union __tag148 CFDRMFDSTS0;                            /* CFDRMFDSTS0      */
    union __tag148 CFDRMDF0_0;                             /* CFDRMDF0_0       */
    union __tag148 CFDRMDF1_0;                             /* CFDRMDF1_0       */
    union __tag148 CFDRMDF2_0;                             /* CFDRMDF2_0       */
    union __tag148 CFDRMDF3_0;                             /* CFDRMDF3_0       */
    union __tag148 CFDRMDF4_0;                             /* CFDRMDF4_0       */
    union __tag148 CFDRMDF5_0;                             /* CFDRMDF5_0       */
    union __tag148 CFDRMDF6_0;                             /* CFDRMDF6_0       */
    union __tag148 CFDRMDF7_0;                             /* CFDRMDF7_0       */
    union __tag148 CFDRMDF8_0;                             /* CFDRMDF8_0       */
    union __tag148 CFDRMDF9_0;                             /* CFDRMDF9_0       */
    union __tag148 CFDRMDF10_0;                            /* CFDRMDF10_0      */
    union __tag148 CFDRMDF11_0;                            /* CFDRMDF11_0      */
    union __tag148 CFDRMDF12_0;                            /* CFDRMDF12_0      */
    union __tag148 CFDRMDF13_0;                            /* CFDRMDF13_0      */
    union __tag148 CFDRMDF14_0;                            /* CFDRMDF14_0      */
    union __tag148 CFDRMDF15_0;                            /* CFDRMDF15_0      */
    unsigned char  dummy197[52];                           /* Reserved         */
    union __tag148 CFDRMID1;                               /* CFDRMID1         */
    union __tag148 CFDRMPTR1;                              /* CFDRMPTR1        */
    union __tag148 CFDRMFDSTS1;                            /* CFDRMFDSTS1      */
    union __tag148 CFDRMDF0_1;                             /* CFDRMDF0_1       */
    union __tag148 CFDRMDF1_1;                             /* CFDRMDF1_1       */
    union __tag148 CFDRMDF2_1;                             /* CFDRMDF2_1       */
    union __tag148 CFDRMDF3_1;                             /* CFDRMDF3_1       */
    union __tag148 CFDRMDF4_1;                             /* CFDRMDF4_1       */
    union __tag148 CFDRMDF5_1;                             /* CFDRMDF5_1       */
    union __tag148 CFDRMDF6_1;                             /* CFDRMDF6_1       */
    union __tag148 CFDRMDF7_1;                             /* CFDRMDF7_1       */
    union __tag148 CFDRMDF8_1;                             /* CFDRMDF8_1       */
    union __tag148 CFDRMDF9_1;                             /* CFDRMDF9_1       */
    union __tag148 CFDRMDF10_1;                            /* CFDRMDF10_1      */
    union __tag148 CFDRMDF11_1;                            /* CFDRMDF11_1      */
    union __tag148 CFDRMDF12_1;                            /* CFDRMDF12_1      */
    union __tag148 CFDRMDF13_1;                            /* CFDRMDF13_1      */
    union __tag148 CFDRMDF14_1;                            /* CFDRMDF14_1      */
    union __tag148 CFDRMDF15_1;                            /* CFDRMDF15_1      */
    unsigned char  dummy198[52];                           /* Reserved         */
    union __tag148 CFDRMID2;                               /* CFDRMID2         */
    union __tag148 CFDRMPTR2;                              /* CFDRMPTR2        */
    union __tag148 CFDRMFDSTS2;                            /* CFDRMFDSTS2      */
    union __tag148 CFDRMDF0_2;                             /* CFDRMDF0_2       */
    union __tag148 CFDRMDF1_2;                             /* CFDRMDF1_2       */
    union __tag148 CFDRMDF2_2;                             /* CFDRMDF2_2       */
    union __tag148 CFDRMDF3_2;                             /* CFDRMDF3_2       */
    union __tag148 CFDRMDF4_2;                             /* CFDRMDF4_2       */
    union __tag148 CFDRMDF5_2;                             /* CFDRMDF5_2       */
    union __tag148 CFDRMDF6_2;                             /* CFDRMDF6_2       */
    union __tag148 CFDRMDF7_2;                             /* CFDRMDF7_2       */
    union __tag148 CFDRMDF8_2;                             /* CFDRMDF8_2       */
    union __tag148 CFDRMDF9_2;                             /* CFDRMDF9_2       */
    union __tag148 CFDRMDF10_2;                            /* CFDRMDF10_2      */
    union __tag148 CFDRMDF11_2;                            /* CFDRMDF11_2      */
    union __tag148 CFDRMDF12_2;                            /* CFDRMDF12_2      */
    union __tag148 CFDRMDF13_2;                            /* CFDRMDF13_2      */
    union __tag148 CFDRMDF14_2;                            /* CFDRMDF14_2      */
    union __tag148 CFDRMDF15_2;                            /* CFDRMDF15_2      */
    unsigned char  dummy199[52];                           /* Reserved         */
    union __tag148 CFDRMID3;                               /* CFDRMID3         */
    union __tag148 CFDRMPTR3;                              /* CFDRMPTR3        */
    union __tag148 CFDRMFDSTS3;                            /* CFDRMFDSTS3      */
    union __tag148 CFDRMDF0_3;                             /* CFDRMDF0_3       */
    union __tag148 CFDRMDF1_3;                             /* CFDRMDF1_3       */
    union __tag148 CFDRMDF2_3;                             /* CFDRMDF2_3       */
    union __tag148 CFDRMDF3_3;                             /* CFDRMDF3_3       */
    union __tag148 CFDRMDF4_3;                             /* CFDRMDF4_3       */
    union __tag148 CFDRMDF5_3;                             /* CFDRMDF5_3       */
    union __tag148 CFDRMDF6_3;                             /* CFDRMDF6_3       */
    union __tag148 CFDRMDF7_3;                             /* CFDRMDF7_3       */
    union __tag148 CFDRMDF8_3;                             /* CFDRMDF8_3       */
    union __tag148 CFDRMDF9_3;                             /* CFDRMDF9_3       */
    union __tag148 CFDRMDF10_3;                            /* CFDRMDF10_3      */
    union __tag148 CFDRMDF11_3;                            /* CFDRMDF11_3      */
    union __tag148 CFDRMDF12_3;                            /* CFDRMDF12_3      */
    union __tag148 CFDRMDF13_3;                            /* CFDRMDF13_3      */
    union __tag148 CFDRMDF14_3;                            /* CFDRMDF14_3      */
    union __tag148 CFDRMDF15_3;                            /* CFDRMDF15_3      */
    unsigned char  dummy200[52];                           /* Reserved         */
    union __tag148 CFDRMID4;                               /* CFDRMID4         */
    union __tag148 CFDRMPTR4;                              /* CFDRMPTR4        */
    union __tag148 CFDRMFDSTS4;                            /* CFDRMFDSTS4      */
    union __tag148 CFDRMDF0_4;                             /* CFDRMDF0_4       */
    union __tag148 CFDRMDF1_4;                             /* CFDRMDF1_4       */
    union __tag148 CFDRMDF2_4;                             /* CFDRMDF2_4       */
    union __tag148 CFDRMDF3_4;                             /* CFDRMDF3_4       */
    union __tag148 CFDRMDF4_4;                             /* CFDRMDF4_4       */
    union __tag148 CFDRMDF5_4;                             /* CFDRMDF5_4       */
    union __tag148 CFDRMDF6_4;                             /* CFDRMDF6_4       */
    union __tag148 CFDRMDF7_4;                             /* CFDRMDF7_4       */
    union __tag148 CFDRMDF8_4;                             /* CFDRMDF8_4       */
    union __tag148 CFDRMDF9_4;                             /* CFDRMDF9_4       */
    union __tag148 CFDRMDF10_4;                            /* CFDRMDF10_4      */
    union __tag148 CFDRMDF11_4;                            /* CFDRMDF11_4      */
    union __tag148 CFDRMDF12_4;                            /* CFDRMDF12_4      */
    union __tag148 CFDRMDF13_4;                            /* CFDRMDF13_4      */
    union __tag148 CFDRMDF14_4;                            /* CFDRMDF14_4      */
    union __tag148 CFDRMDF15_4;                            /* CFDRMDF15_4      */
    unsigned char  dummy201[52];                           /* Reserved         */
    union __tag148 CFDRMID5;                               /* CFDRMID5         */
    union __tag148 CFDRMPTR5;                              /* CFDRMPTR5        */
    union __tag148 CFDRMFDSTS5;                            /* CFDRMFDSTS5      */
    union __tag148 CFDRMDF0_5;                             /* CFDRMDF0_5       */
    union __tag148 CFDRMDF1_5;                             /* CFDRMDF1_5       */
    union __tag148 CFDRMDF2_5;                             /* CFDRMDF2_5       */
    union __tag148 CFDRMDF3_5;                             /* CFDRMDF3_5       */
    union __tag148 CFDRMDF4_5;                             /* CFDRMDF4_5       */
    union __tag148 CFDRMDF5_5;                             /* CFDRMDF5_5       */
    union __tag148 CFDRMDF6_5;                             /* CFDRMDF6_5       */
    union __tag148 CFDRMDF7_5;                             /* CFDRMDF7_5       */
    union __tag148 CFDRMDF8_5;                             /* CFDRMDF8_5       */
    union __tag148 CFDRMDF9_5;                             /* CFDRMDF9_5       */
    union __tag148 CFDRMDF10_5;                            /* CFDRMDF10_5      */
    union __tag148 CFDRMDF11_5;                            /* CFDRMDF11_5      */
    union __tag148 CFDRMDF12_5;                            /* CFDRMDF12_5      */
    union __tag148 CFDRMDF13_5;                            /* CFDRMDF13_5      */
    union __tag148 CFDRMDF14_5;                            /* CFDRMDF14_5      */
    union __tag148 CFDRMDF15_5;                            /* CFDRMDF15_5      */
    unsigned char  dummy202[52];                           /* Reserved         */
    union __tag148 CFDRMID6;                               /* CFDRMID6         */
    union __tag148 CFDRMPTR6;                              /* CFDRMPTR6        */
    union __tag148 CFDRMFDSTS6;                            /* CFDRMFDSTS6      */
    union __tag148 CFDRMDF0_6;                             /* CFDRMDF0_6       */
    union __tag148 CFDRMDF1_6;                             /* CFDRMDF1_6       */
    union __tag148 CFDRMDF2_6;                             /* CFDRMDF2_6       */
    union __tag148 CFDRMDF3_6;                             /* CFDRMDF3_6       */
    union __tag148 CFDRMDF4_6;                             /* CFDRMDF4_6       */
    union __tag148 CFDRMDF5_6;                             /* CFDRMDF5_6       */
    union __tag148 CFDRMDF6_6;                             /* CFDRMDF6_6       */
    union __tag148 CFDRMDF7_6;                             /* CFDRMDF7_6       */
    union __tag148 CFDRMDF8_6;                             /* CFDRMDF8_6       */
    union __tag148 CFDRMDF9_6;                             /* CFDRMDF9_6       */
    union __tag148 CFDRMDF10_6;                            /* CFDRMDF10_6      */
    union __tag148 CFDRMDF11_6;                            /* CFDRMDF11_6      */
    union __tag148 CFDRMDF12_6;                            /* CFDRMDF12_6      */
    union __tag148 CFDRMDF13_6;                            /* CFDRMDF13_6      */
    union __tag148 CFDRMDF14_6;                            /* CFDRMDF14_6      */
    union __tag148 CFDRMDF15_6;                            /* CFDRMDF15_6      */
    unsigned char  dummy203[52];                           /* Reserved         */
    union __tag148 CFDRMID7;                               /* CFDRMID7         */
    union __tag148 CFDRMPTR7;                              /* CFDRMPTR7        */
    union __tag148 CFDRMFDSTS7;                            /* CFDRMFDSTS7      */
    union __tag148 CFDRMDF0_7;                             /* CFDRMDF0_7       */
    union __tag148 CFDRMDF1_7;                             /* CFDRMDF1_7       */
    union __tag148 CFDRMDF2_7;                             /* CFDRMDF2_7       */
    union __tag148 CFDRMDF3_7;                             /* CFDRMDF3_7       */
    union __tag148 CFDRMDF4_7;                             /* CFDRMDF4_7       */
    union __tag148 CFDRMDF5_7;                             /* CFDRMDF5_7       */
    union __tag148 CFDRMDF6_7;                             /* CFDRMDF6_7       */
    union __tag148 CFDRMDF7_7;                             /* CFDRMDF7_7       */
    union __tag148 CFDRMDF8_7;                             /* CFDRMDF8_7       */
    union __tag148 CFDRMDF9_7;                             /* CFDRMDF9_7       */
    union __tag148 CFDRMDF10_7;                            /* CFDRMDF10_7      */
    union __tag148 CFDRMDF11_7;                            /* CFDRMDF11_7      */
    union __tag148 CFDRMDF12_7;                            /* CFDRMDF12_7      */
    union __tag148 CFDRMDF13_7;                            /* CFDRMDF13_7      */
    union __tag148 CFDRMDF14_7;                            /* CFDRMDF14_7      */
    union __tag148 CFDRMDF15_7;                            /* CFDRMDF15_7      */
    unsigned char  dummy204[52];                           /* Reserved         */
    union __tag148 CFDRMID8;                               /* CFDRMID8         */
    union __tag148 CFDRMPTR8;                              /* CFDRMPTR8        */
    union __tag148 CFDRMFDSTS8;                            /* CFDRMFDSTS8      */
    union __tag148 CFDRMDF0_8;                             /* CFDRMDF0_8       */
    union __tag148 CFDRMDF1_8;                             /* CFDRMDF1_8       */
    union __tag148 CFDRMDF2_8;                             /* CFDRMDF2_8       */
    union __tag148 CFDRMDF3_8;                             /* CFDRMDF3_8       */
    union __tag148 CFDRMDF4_8;                             /* CFDRMDF4_8       */
    union __tag148 CFDRMDF5_8;                             /* CFDRMDF5_8       */
    union __tag148 CFDRMDF6_8;                             /* CFDRMDF6_8       */
    union __tag148 CFDRMDF7_8;                             /* CFDRMDF7_8       */
    union __tag148 CFDRMDF8_8;                             /* CFDRMDF8_8       */
    union __tag148 CFDRMDF9_8;                             /* CFDRMDF9_8       */
    union __tag148 CFDRMDF10_8;                            /* CFDRMDF10_8      */
    union __tag148 CFDRMDF11_8;                            /* CFDRMDF11_8      */
    union __tag148 CFDRMDF12_8;                            /* CFDRMDF12_8      */
    union __tag148 CFDRMDF13_8;                            /* CFDRMDF13_8      */
    union __tag148 CFDRMDF14_8;                            /* CFDRMDF14_8      */
    union __tag148 CFDRMDF15_8;                            /* CFDRMDF15_8      */
    unsigned char  dummy205[52];                           /* Reserved         */
    union __tag148 CFDRMID9;                               /* CFDRMID9         */
    union __tag148 CFDRMPTR9;                              /* CFDRMPTR9        */
    union __tag148 CFDRMFDSTS9;                            /* CFDRMFDSTS9      */
    union __tag148 CFDRMDF0_9;                             /* CFDRMDF0_9       */
    union __tag148 CFDRMDF1_9;                             /* CFDRMDF1_9       */
    union __tag148 CFDRMDF2_9;                             /* CFDRMDF2_9       */
    union __tag148 CFDRMDF3_9;                             /* CFDRMDF3_9       */
    union __tag148 CFDRMDF4_9;                             /* CFDRMDF4_9       */
    union __tag148 CFDRMDF5_9;                             /* CFDRMDF5_9       */
    union __tag148 CFDRMDF6_9;                             /* CFDRMDF6_9       */
    union __tag148 CFDRMDF7_9;                             /* CFDRMDF7_9       */
    union __tag148 CFDRMDF8_9;                             /* CFDRMDF8_9       */
    union __tag148 CFDRMDF9_9;                             /* CFDRMDF9_9       */
    union __tag148 CFDRMDF10_9;                            /* CFDRMDF10_9      */
    union __tag148 CFDRMDF11_9;                            /* CFDRMDF11_9      */
    union __tag148 CFDRMDF12_9;                            /* CFDRMDF12_9      */
    union __tag148 CFDRMDF13_9;                            /* CFDRMDF13_9      */
    union __tag148 CFDRMDF14_9;                            /* CFDRMDF14_9      */
    union __tag148 CFDRMDF15_9;                            /* CFDRMDF15_9      */
    unsigned char  dummy206[52];                           /* Reserved         */
    union __tag148 CFDRMID10;                              /* CFDRMID10        */
    union __tag148 CFDRMPTR10;                             /* CFDRMPTR10       */
    union __tag148 CFDRMFDSTS10;                           /* CFDRMFDSTS10     */
    union __tag148 CFDRMDF0_10;                            /* CFDRMDF0_10      */
    union __tag148 CFDRMDF1_10;                            /* CFDRMDF1_10      */
    union __tag148 CFDRMDF2_10;                            /* CFDRMDF2_10      */
    union __tag148 CFDRMDF3_10;                            /* CFDRMDF3_10      */
    union __tag148 CFDRMDF4_10;                            /* CFDRMDF4_10      */
    union __tag148 CFDRMDF5_10;                            /* CFDRMDF5_10      */
    union __tag148 CFDRMDF6_10;                            /* CFDRMDF6_10      */
    union __tag148 CFDRMDF7_10;                            /* CFDRMDF7_10      */
    union __tag148 CFDRMDF8_10;                            /* CFDRMDF8_10      */
    union __tag148 CFDRMDF9_10;                            /* CFDRMDF9_10      */
    union __tag148 CFDRMDF10_10;                           /* CFDRMDF10_10     */
    union __tag148 CFDRMDF11_10;                           /* CFDRMDF11_10     */
    union __tag148 CFDRMDF12_10;                           /* CFDRMDF12_10     */
    union __tag148 CFDRMDF13_10;                           /* CFDRMDF13_10     */
    union __tag148 CFDRMDF14_10;                           /* CFDRMDF14_10     */
    union __tag148 CFDRMDF15_10;                           /* CFDRMDF15_10     */
    unsigned char  dummy207[52];                           /* Reserved         */
    union __tag148 CFDRMID11;                              /* CFDRMID11        */
    union __tag148 CFDRMPTR11;                             /* CFDRMPTR11       */
    union __tag148 CFDRMFDSTS11;                           /* CFDRMFDSTS11     */
    union __tag148 CFDRMDF0_11;                            /* CFDRMDF0_11      */
    union __tag148 CFDRMDF1_11;                            /* CFDRMDF1_11      */
    union __tag148 CFDRMDF2_11;                            /* CFDRMDF2_11      */
    union __tag148 CFDRMDF3_11;                            /* CFDRMDF3_11      */
    union __tag148 CFDRMDF4_11;                            /* CFDRMDF4_11      */
    union __tag148 CFDRMDF5_11;                            /* CFDRMDF5_11      */
    union __tag148 CFDRMDF6_11;                            /* CFDRMDF6_11      */
    union __tag148 CFDRMDF7_11;                            /* CFDRMDF7_11      */
    union __tag148 CFDRMDF8_11;                            /* CFDRMDF8_11      */
    union __tag148 CFDRMDF9_11;                            /* CFDRMDF9_11      */
    union __tag148 CFDRMDF10_11;                           /* CFDRMDF10_11     */
    union __tag148 CFDRMDF11_11;                           /* CFDRMDF11_11     */
    union __tag148 CFDRMDF12_11;                           /* CFDRMDF12_11     */
    union __tag148 CFDRMDF13_11;                           /* CFDRMDF13_11     */
    union __tag148 CFDRMDF14_11;                           /* CFDRMDF14_11     */
    union __tag148 CFDRMDF15_11;                           /* CFDRMDF15_11     */
    unsigned char  dummy208[52];                           /* Reserved         */
    union __tag148 CFDRMID12;                              /* CFDRMID12        */
    union __tag148 CFDRMPTR12;                             /* CFDRMPTR12       */
    union __tag148 CFDRMFDSTS12;                           /* CFDRMFDSTS12     */
    union __tag148 CFDRMDF0_12;                            /* CFDRMDF0_12      */
    union __tag148 CFDRMDF1_12;                            /* CFDRMDF1_12      */
    union __tag148 CFDRMDF2_12;                            /* CFDRMDF2_12      */
    union __tag148 CFDRMDF3_12;                            /* CFDRMDF3_12      */
    union __tag148 CFDRMDF4_12;                            /* CFDRMDF4_12      */
    union __tag148 CFDRMDF5_12;                            /* CFDRMDF5_12      */
    union __tag148 CFDRMDF6_12;                            /* CFDRMDF6_12      */
    union __tag148 CFDRMDF7_12;                            /* CFDRMDF7_12      */
    union __tag148 CFDRMDF8_12;                            /* CFDRMDF8_12      */
    union __tag148 CFDRMDF9_12;                            /* CFDRMDF9_12      */
    union __tag148 CFDRMDF10_12;                           /* CFDRMDF10_12     */
    union __tag148 CFDRMDF11_12;                           /* CFDRMDF11_12     */
    union __tag148 CFDRMDF12_12;                           /* CFDRMDF12_12     */
    union __tag148 CFDRMDF13_12;                           /* CFDRMDF13_12     */
    union __tag148 CFDRMDF14_12;                           /* CFDRMDF14_12     */
    union __tag148 CFDRMDF15_12;                           /* CFDRMDF15_12     */
    unsigned char  dummy209[52];                           /* Reserved         */
    union __tag148 CFDRMID13;                              /* CFDRMID13        */
    union __tag148 CFDRMPTR13;                             /* CFDRMPTR13       */
    union __tag148 CFDRMFDSTS13;                           /* CFDRMFDSTS13     */
    union __tag148 CFDRMDF0_13;                            /* CFDRMDF0_13      */
    union __tag148 CFDRMDF1_13;                            /* CFDRMDF1_13      */
    union __tag148 CFDRMDF2_13;                            /* CFDRMDF2_13      */
    union __tag148 CFDRMDF3_13;                            /* CFDRMDF3_13      */
    union __tag148 CFDRMDF4_13;                            /* CFDRMDF4_13      */
    union __tag148 CFDRMDF5_13;                            /* CFDRMDF5_13      */
    union __tag148 CFDRMDF6_13;                            /* CFDRMDF6_13      */
    union __tag148 CFDRMDF7_13;                            /* CFDRMDF7_13      */
    union __tag148 CFDRMDF8_13;                            /* CFDRMDF8_13      */
    union __tag148 CFDRMDF9_13;                            /* CFDRMDF9_13      */
    union __tag148 CFDRMDF10_13;                           /* CFDRMDF10_13     */
    union __tag148 CFDRMDF11_13;                           /* CFDRMDF11_13     */
    union __tag148 CFDRMDF12_13;                           /* CFDRMDF12_13     */
    union __tag148 CFDRMDF13_13;                           /* CFDRMDF13_13     */
    union __tag148 CFDRMDF14_13;                           /* CFDRMDF14_13     */
    union __tag148 CFDRMDF15_13;                           /* CFDRMDF15_13     */
    unsigned char  dummy210[52];                           /* Reserved         */
    union __tag148 CFDRMID14;                              /* CFDRMID14        */
    union __tag148 CFDRMPTR14;                             /* CFDRMPTR14       */
    union __tag148 CFDRMFDSTS14;                           /* CFDRMFDSTS14     */
    union __tag148 CFDRMDF0_14;                            /* CFDRMDF0_14      */
    union __tag148 CFDRMDF1_14;                            /* CFDRMDF1_14      */
    union __tag148 CFDRMDF2_14;                            /* CFDRMDF2_14      */
    union __tag148 CFDRMDF3_14;                            /* CFDRMDF3_14      */
    union __tag148 CFDRMDF4_14;                            /* CFDRMDF4_14      */
    union __tag148 CFDRMDF5_14;                            /* CFDRMDF5_14      */
    union __tag148 CFDRMDF6_14;                            /* CFDRMDF6_14      */
    union __tag148 CFDRMDF7_14;                            /* CFDRMDF7_14      */
    union __tag148 CFDRMDF8_14;                            /* CFDRMDF8_14      */
    union __tag148 CFDRMDF9_14;                            /* CFDRMDF9_14      */
    union __tag148 CFDRMDF10_14;                           /* CFDRMDF10_14     */
    union __tag148 CFDRMDF11_14;                           /* CFDRMDF11_14     */
    union __tag148 CFDRMDF12_14;                           /* CFDRMDF12_14     */
    union __tag148 CFDRMDF13_14;                           /* CFDRMDF13_14     */
    union __tag148 CFDRMDF14_14;                           /* CFDRMDF14_14     */
    union __tag148 CFDRMDF15_14;                           /* CFDRMDF15_14     */
    unsigned char  dummy211[52];                           /* Reserved         */
    union __tag148 CFDRMID15;                              /* CFDRMID15        */
    union __tag148 CFDRMPTR15;                             /* CFDRMPTR15       */
    union __tag148 CFDRMFDSTS15;                           /* CFDRMFDSTS15     */
    union __tag148 CFDRMDF0_15;                            /* CFDRMDF0_15      */
    union __tag148 CFDRMDF1_15;                            /* CFDRMDF1_15      */
    union __tag148 CFDRMDF2_15;                            /* CFDRMDF2_15      */
    union __tag148 CFDRMDF3_15;                            /* CFDRMDF3_15      */
    union __tag148 CFDRMDF4_15;                            /* CFDRMDF4_15      */
    union __tag148 CFDRMDF5_15;                            /* CFDRMDF5_15      */
    union __tag148 CFDRMDF6_15;                            /* CFDRMDF6_15      */
    union __tag148 CFDRMDF7_15;                            /* CFDRMDF7_15      */
    union __tag148 CFDRMDF8_15;                            /* CFDRMDF8_15      */
    union __tag148 CFDRMDF9_15;                            /* CFDRMDF9_15      */
    union __tag148 CFDRMDF10_15;                           /* CFDRMDF10_15     */
    union __tag148 CFDRMDF11_15;                           /* CFDRMDF11_15     */
    union __tag148 CFDRMDF12_15;                           /* CFDRMDF12_15     */
    union __tag148 CFDRMDF13_15;                           /* CFDRMDF13_15     */
    union __tag148 CFDRMDF14_15;                           /* CFDRMDF14_15     */
    union __tag148 CFDRMDF15_15;                           /* CFDRMDF15_15     */
    unsigned char  dummy212[14388];                        /* Reserved         */
    union __tag148 CFDRFID0;                               /* CFDRFID0         */
    union __tag148 CFDRFPTR0;                              /* CFDRFPTR0        */
    union __tag148 CFDRFFDSTS0;                            /* CFDRFFDSTS0      */
    union __tag148 CFDRFDF0_0;                             /* CFDRFDF0_0       */
    union __tag148 CFDRFDF1_0;                             /* CFDRFDF1_0       */
    union __tag148 CFDRFDF2_0;                             /* CFDRFDF2_0       */
    union __tag148 CFDRFDF3_0;                             /* CFDRFDF3_0       */
    union __tag148 CFDRFDF4_0;                             /* CFDRFDF4_0       */
    union __tag148 CFDRFDF5_0;                             /* CFDRFDF5_0       */
    union __tag148 CFDRFDF6_0;                             /* CFDRFDF6_0       */
    union __tag148 CFDRFDF7_0;                             /* CFDRFDF7_0       */
    union __tag148 CFDRFDF8_0;                             /* CFDRFDF8_0       */
    union __tag148 CFDRFDF9_0;                             /* CFDRFDF9_0       */
    union __tag148 CFDRFDF10_0;                            /* CFDRFDF10_0      */
    union __tag148 CFDRFDF11_0;                            /* CFDRFDF11_0      */
    union __tag148 CFDRFDF12_0;                            /* CFDRFDF12_0      */
    union __tag148 CFDRFDF13_0;                            /* CFDRFDF13_0      */
    union __tag148 CFDRFDF14_0;                            /* CFDRFDF14_0      */
    union __tag148 CFDRFDF15_0;                            /* CFDRFDF15_0      */
    unsigned char  dummy213[52];                           /* Reserved         */
    union __tag148 CFDRFID1;                               /* CFDRFID1         */
    union __tag148 CFDRFPTR1;                              /* CFDRFPTR1        */
    union __tag148 CFDRFFDSTS1;                            /* CFDRFFDSTS1      */
    union __tag148 CFDRFDF0_1;                             /* CFDRFDF0_1       */
    union __tag148 CFDRFDF1_1;                             /* CFDRFDF1_1       */
    union __tag148 CFDRFDF2_1;                             /* CFDRFDF2_1       */
    union __tag148 CFDRFDF3_1;                             /* CFDRFDF3_1       */
    union __tag148 CFDRFDF4_1;                             /* CFDRFDF4_1       */
    union __tag148 CFDRFDF5_1;                             /* CFDRFDF5_1       */
    union __tag148 CFDRFDF6_1;                             /* CFDRFDF6_1       */
    union __tag148 CFDRFDF7_1;                             /* CFDRFDF7_1       */
    union __tag148 CFDRFDF8_1;                             /* CFDRFDF8_1       */
    union __tag148 CFDRFDF9_1;                             /* CFDRFDF9_1       */
    union __tag148 CFDRFDF10_1;                            /* CFDRFDF10_1      */
    union __tag148 CFDRFDF11_1;                            /* CFDRFDF11_1      */
    union __tag148 CFDRFDF12_1;                            /* CFDRFDF12_1      */
    union __tag148 CFDRFDF13_1;                            /* CFDRFDF13_1      */
    union __tag148 CFDRFDF14_1;                            /* CFDRFDF14_1      */
    union __tag148 CFDRFDF15_1;                            /* CFDRFDF15_1      */
    unsigned char  dummy214[52];                           /* Reserved         */
    union __tag148 CFDRFID2;                               /* CFDRFID2         */
    union __tag148 CFDRFPTR2;                              /* CFDRFPTR2        */
    union __tag148 CFDRFFDSTS2;                            /* CFDRFFDSTS2      */
    union __tag148 CFDRFDF0_2;                             /* CFDRFDF0_2       */
    union __tag148 CFDRFDF1_2;                             /* CFDRFDF1_2       */
    union __tag148 CFDRFDF2_2;                             /* CFDRFDF2_2       */
    union __tag148 CFDRFDF3_2;                             /* CFDRFDF3_2       */
    union __tag148 CFDRFDF4_2;                             /* CFDRFDF4_2       */
    union __tag148 CFDRFDF5_2;                             /* CFDRFDF5_2       */
    union __tag148 CFDRFDF6_2;                             /* CFDRFDF6_2       */
    union __tag148 CFDRFDF7_2;                             /* CFDRFDF7_2       */
    union __tag148 CFDRFDF8_2;                             /* CFDRFDF8_2       */
    union __tag148 CFDRFDF9_2;                             /* CFDRFDF9_2       */
    union __tag148 CFDRFDF10_2;                            /* CFDRFDF10_2      */
    union __tag148 CFDRFDF11_2;                            /* CFDRFDF11_2      */
    union __tag148 CFDRFDF12_2;                            /* CFDRFDF12_2      */
    union __tag148 CFDRFDF13_2;                            /* CFDRFDF13_2      */
    union __tag148 CFDRFDF14_2;                            /* CFDRFDF14_2      */
    union __tag148 CFDRFDF15_2;                            /* CFDRFDF15_2      */
    unsigned char  dummy215[52];                           /* Reserved         */
    union __tag148 CFDRFID3;                               /* CFDRFID3         */
    union __tag148 CFDRFPTR3;                              /* CFDRFPTR3        */
    union __tag148 CFDRFFDSTS3;                            /* CFDRFFDSTS3      */
    union __tag148 CFDRFDF0_3;                             /* CFDRFDF0_3       */
    union __tag148 CFDRFDF1_3;                             /* CFDRFDF1_3       */
    union __tag148 CFDRFDF2_3;                             /* CFDRFDF2_3       */
    union __tag148 CFDRFDF3_3;                             /* CFDRFDF3_3       */
    union __tag148 CFDRFDF4_3;                             /* CFDRFDF4_3       */
    union __tag148 CFDRFDF5_3;                             /* CFDRFDF5_3       */
    union __tag148 CFDRFDF6_3;                             /* CFDRFDF6_3       */
    union __tag148 CFDRFDF7_3;                             /* CFDRFDF7_3       */
    union __tag148 CFDRFDF8_3;                             /* CFDRFDF8_3       */
    union __tag148 CFDRFDF9_3;                             /* CFDRFDF9_3       */
    union __tag148 CFDRFDF10_3;                            /* CFDRFDF10_3      */
    union __tag148 CFDRFDF11_3;                            /* CFDRFDF11_3      */
    union __tag148 CFDRFDF12_3;                            /* CFDRFDF12_3      */
    union __tag148 CFDRFDF13_3;                            /* CFDRFDF13_3      */
    union __tag148 CFDRFDF14_3;                            /* CFDRFDF14_3      */
    union __tag148 CFDRFDF15_3;                            /* CFDRFDF15_3      */
    unsigned char  dummy216[52];                           /* Reserved         */
    union __tag148 CFDRFID4;                               /* CFDRFID4         */
    union __tag148 CFDRFPTR4;                              /* CFDRFPTR4        */
    union __tag148 CFDRFFDSTS4;                            /* CFDRFFDSTS4      */
    union __tag148 CFDRFDF0_4;                             /* CFDRFDF0_4       */
    union __tag148 CFDRFDF1_4;                             /* CFDRFDF1_4       */
    union __tag148 CFDRFDF2_4;                             /* CFDRFDF2_4       */
    union __tag148 CFDRFDF3_4;                             /* CFDRFDF3_4       */
    union __tag148 CFDRFDF4_4;                             /* CFDRFDF4_4       */
    union __tag148 CFDRFDF5_4;                             /* CFDRFDF5_4       */
    union __tag148 CFDRFDF6_4;                             /* CFDRFDF6_4       */
    union __tag148 CFDRFDF7_4;                             /* CFDRFDF7_4       */
    union __tag148 CFDRFDF8_4;                             /* CFDRFDF8_4       */
    union __tag148 CFDRFDF9_4;                             /* CFDRFDF9_4       */
    union __tag148 CFDRFDF10_4;                            /* CFDRFDF10_4      */
    union __tag148 CFDRFDF11_4;                            /* CFDRFDF11_4      */
    union __tag148 CFDRFDF12_4;                            /* CFDRFDF12_4      */
    union __tag148 CFDRFDF13_4;                            /* CFDRFDF13_4      */
    union __tag148 CFDRFDF14_4;                            /* CFDRFDF14_4      */
    union __tag148 CFDRFDF15_4;                            /* CFDRFDF15_4      */
    unsigned char  dummy217[52];                           /* Reserved         */
    union __tag148 CFDRFID5;                               /* CFDRFID5         */
    union __tag148 CFDRFPTR5;                              /* CFDRFPTR5        */
    union __tag148 CFDRFFDSTS5;                            /* CFDRFFDSTS5      */
    union __tag148 CFDRFDF0_5;                             /* CFDRFDF0_5       */
    union __tag148 CFDRFDF1_5;                             /* CFDRFDF1_5       */
    union __tag148 CFDRFDF2_5;                             /* CFDRFDF2_5       */
    union __tag148 CFDRFDF3_5;                             /* CFDRFDF3_5       */
    union __tag148 CFDRFDF4_5;                             /* CFDRFDF4_5       */
    union __tag148 CFDRFDF5_5;                             /* CFDRFDF5_5       */
    union __tag148 CFDRFDF6_5;                             /* CFDRFDF6_5       */
    union __tag148 CFDRFDF7_5;                             /* CFDRFDF7_5       */
    union __tag148 CFDRFDF8_5;                             /* CFDRFDF8_5       */
    union __tag148 CFDRFDF9_5;                             /* CFDRFDF9_5       */
    union __tag148 CFDRFDF10_5;                            /* CFDRFDF10_5      */
    union __tag148 CFDRFDF11_5;                            /* CFDRFDF11_5      */
    union __tag148 CFDRFDF12_5;                            /* CFDRFDF12_5      */
    union __tag148 CFDRFDF13_5;                            /* CFDRFDF13_5      */
    union __tag148 CFDRFDF14_5;                            /* CFDRFDF14_5      */
    union __tag148 CFDRFDF15_5;                            /* CFDRFDF15_5      */
    unsigned char  dummy218[52];                           /* Reserved         */
    union __tag148 CFDRFID6;                               /* CFDRFID6         */
    union __tag148 CFDRFPTR6;                              /* CFDRFPTR6        */
    union __tag148 CFDRFFDSTS6;                            /* CFDRFFDSTS6      */
    union __tag148 CFDRFDF0_6;                             /* CFDRFDF0_6       */
    union __tag148 CFDRFDF1_6;                             /* CFDRFDF1_6       */
    union __tag148 CFDRFDF2_6;                             /* CFDRFDF2_6       */
    union __tag148 CFDRFDF3_6;                             /* CFDRFDF3_6       */
    union __tag148 CFDRFDF4_6;                             /* CFDRFDF4_6       */
    union __tag148 CFDRFDF5_6;                             /* CFDRFDF5_6       */
    union __tag148 CFDRFDF6_6;                             /* CFDRFDF6_6       */
    union __tag148 CFDRFDF7_6;                             /* CFDRFDF7_6       */
    union __tag148 CFDRFDF8_6;                             /* CFDRFDF8_6       */
    union __tag148 CFDRFDF9_6;                             /* CFDRFDF9_6       */
    union __tag148 CFDRFDF10_6;                            /* CFDRFDF10_6      */
    union __tag148 CFDRFDF11_6;                            /* CFDRFDF11_6      */
    union __tag148 CFDRFDF12_6;                            /* CFDRFDF12_6      */
    union __tag148 CFDRFDF13_6;                            /* CFDRFDF13_6      */
    union __tag148 CFDRFDF14_6;                            /* CFDRFDF14_6      */
    union __tag148 CFDRFDF15_6;                            /* CFDRFDF15_6      */
    unsigned char  dummy219[52];                           /* Reserved         */
    union __tag148 CFDRFID7;                               /* CFDRFID7         */
    union __tag148 CFDRFPTR7;                              /* CFDRFPTR7        */
    union __tag148 CFDRFFDSTS7;                            /* CFDRFFDSTS7      */
    union __tag148 CFDRFDF0_7;                             /* CFDRFDF0_7       */
    union __tag148 CFDRFDF1_7;                             /* CFDRFDF1_7       */
    union __tag148 CFDRFDF2_7;                             /* CFDRFDF2_7       */
    union __tag148 CFDRFDF3_7;                             /* CFDRFDF3_7       */
    union __tag148 CFDRFDF4_7;                             /* CFDRFDF4_7       */
    union __tag148 CFDRFDF5_7;                             /* CFDRFDF5_7       */
    union __tag148 CFDRFDF6_7;                             /* CFDRFDF6_7       */
    union __tag148 CFDRFDF7_7;                             /* CFDRFDF7_7       */
    union __tag148 CFDRFDF8_7;                             /* CFDRFDF8_7       */
    union __tag148 CFDRFDF9_7;                             /* CFDRFDF9_7       */
    union __tag148 CFDRFDF10_7;                            /* CFDRFDF10_7      */
    union __tag148 CFDRFDF11_7;                            /* CFDRFDF11_7      */
    union __tag148 CFDRFDF12_7;                            /* CFDRFDF12_7      */
    union __tag148 CFDRFDF13_7;                            /* CFDRFDF13_7      */
    union __tag148 CFDRFDF14_7;                            /* CFDRFDF14_7      */
    union __tag148 CFDRFDF15_7;                            /* CFDRFDF15_7      */
    unsigned char  dummy220[52];                           /* Reserved         */
    union __tag148 CFDCFID0;                               /* CFDCFID0         */
    union __tag148 CFDCFPTR0;                              /* CFDCFPTR0        */
    union __tag148 CFDCFFDCSTS0;                           /* CFDCFFDCSTS0     */
    union __tag148 CFDCFDF0_0;                             /* CFDCFDF0_0       */
    union __tag148 CFDCFDF1_0;                             /* CFDCFDF1_0       */
    union __tag148 CFDCFDF2_0;                             /* CFDCFDF2_0       */
    union __tag148 CFDCFDF3_0;                             /* CFDCFDF3_0       */
    union __tag148 CFDCFDF4_0;                             /* CFDCFDF4_0       */
    union __tag148 CFDCFDF5_0;                             /* CFDCFDF5_0       */
    union __tag148 CFDCFDF6_0;                             /* CFDCFDF6_0       */
    union __tag148 CFDCFDF7_0;                             /* CFDCFDF7_0       */
    union __tag148 CFDCFDF8_0;                             /* CFDCFDF8_0       */
    union __tag148 CFDCFDF9_0;                             /* CFDCFDF9_0       */
    union __tag148 CFDCFDF10_0;                            /* CFDCFDF10_0      */
    union __tag148 CFDCFDF11_0;                            /* CFDCFDF11_0      */
    union __tag148 CFDCFDF12_0;                            /* CFDCFDF12_0      */
    union __tag148 CFDCFDF13_0;                            /* CFDCFDF13_0      */
    union __tag148 CFDCFDF14_0;                            /* CFDCFDF14_0      */
    union __tag148 CFDCFDF15_0;                            /* CFDCFDF15_0      */
    unsigned char  dummy221[52];                           /* Reserved         */
    union __tag148 CFDCFID1;                               /* CFDCFID1         */
    union __tag148 CFDCFPTR1;                              /* CFDCFPTR1        */
    union __tag148 CFDCFFDCSTS1;                           /* CFDCFFDCSTS1     */
    union __tag148 CFDCFDF0_1;                             /* CFDCFDF0_1       */
    union __tag148 CFDCFDF1_1;                             /* CFDCFDF1_1       */
    union __tag148 CFDCFDF2_1;                             /* CFDCFDF2_1       */
    union __tag148 CFDCFDF3_1;                             /* CFDCFDF3_1       */
    union __tag148 CFDCFDF4_1;                             /* CFDCFDF4_1       */
    union __tag148 CFDCFDF5_1;                             /* CFDCFDF5_1       */
    union __tag148 CFDCFDF6_1;                             /* CFDCFDF6_1       */
    union __tag148 CFDCFDF7_1;                             /* CFDCFDF7_1       */
    union __tag148 CFDCFDF8_1;                             /* CFDCFDF8_1       */
    union __tag148 CFDCFDF9_1;                             /* CFDCFDF9_1       */
    union __tag148 CFDCFDF10_1;                            /* CFDCFDF10_1      */
    union __tag148 CFDCFDF11_1;                            /* CFDCFDF11_1      */
    union __tag148 CFDCFDF12_1;                            /* CFDCFDF12_1      */
    union __tag148 CFDCFDF13_1;                            /* CFDCFDF13_1      */
    union __tag148 CFDCFDF14_1;                            /* CFDCFDF14_1      */
    union __tag148 CFDCFDF15_1;                            /* CFDCFDF15_1      */
    unsigned char  dummy222[52];                           /* Reserved         */
    union __tag148 CFDCFID2;                               /* CFDCFID2         */
    union __tag148 CFDCFPTR2;                              /* CFDCFPTR2        */
    union __tag148 CFDCFFDCSTS2;                           /* CFDCFFDCSTS2     */
    union __tag148 CFDCFDF0_2;                             /* CFDCFDF0_2       */
    union __tag148 CFDCFDF1_2;                             /* CFDCFDF1_2       */
    union __tag148 CFDCFDF2_2;                             /* CFDCFDF2_2       */
    union __tag148 CFDCFDF3_2;                             /* CFDCFDF3_2       */
    union __tag148 CFDCFDF4_2;                             /* CFDCFDF4_2       */
    union __tag148 CFDCFDF5_2;                             /* CFDCFDF5_2       */
    union __tag148 CFDCFDF6_2;                             /* CFDCFDF6_2       */
    union __tag148 CFDCFDF7_2;                             /* CFDCFDF7_2       */
    union __tag148 CFDCFDF8_2;                             /* CFDCFDF8_2       */
    union __tag148 CFDCFDF9_2;                             /* CFDCFDF9_2       */
    union __tag148 CFDCFDF10_2;                            /* CFDCFDF10_2      */
    union __tag148 CFDCFDF11_2;                            /* CFDCFDF11_2      */
    union __tag148 CFDCFDF12_2;                            /* CFDCFDF12_2      */
    union __tag148 CFDCFDF13_2;                            /* CFDCFDF13_2      */
    union __tag148 CFDCFDF14_2;                            /* CFDCFDF14_2      */
    union __tag148 CFDCFDF15_2;                            /* CFDCFDF15_2      */
    unsigned char  dummy223[6836];                         /* Reserved         */
    union __tag148 CFDTMID0;                               /* CFDTMID0         */
    union __tag148 CFDTMPTR0;                              /* CFDTMPTR0        */
    union __tag148 CFDTMFDCTR0;                            /* CFDTMFDCTR0      */
    union __tag148 CFDTMDF0_0;                             /* CFDTMDF0_0       */
    union __tag148 CFDTMDF1_0;                             /* CFDTMDF1_0       */
    union __tag148 CFDTMDF2_0;                             /* CFDTMDF2_0       */
    union __tag148 CFDTMDF3_0;                             /* CFDTMDF3_0       */
    union __tag148 CFDTMDF4_0;                             /* CFDTMDF4_0       */
    union __tag148 CFDTMDF5_0;                             /* CFDTMDF5_0       */
    union __tag148 CFDTMDF6_0;                             /* CFDTMDF6_0       */
    union __tag148 CFDTMDF7_0;                             /* CFDTMDF7_0       */
    union __tag148 CFDTMDF8_0;                             /* CFDTMDF8_0       */
    union __tag148 CFDTMDF9_0;                             /* CFDTMDF9_0       */
    union __tag148 CFDTMDF10_0;                            /* CFDTMDF10_0      */
    union __tag148 CFDTMDF11_0;                            /* CFDTMDF11_0      */
    union __tag148 CFDTMDF12_0;                            /* CFDTMDF12_0      */
    union __tag148 CFDTMDF13_0;                            /* CFDTMDF13_0      */
    union __tag148 CFDTMDF14_0;                            /* CFDTMDF14_0      */
    union __tag148 CFDTMDF15_0;                            /* CFDTMDF15_0      */
    unsigned char  dummy224[52];                           /* Reserved         */
    union __tag148 CFDTMID1;                               /* CFDTMID1         */
    union __tag148 CFDTMPTR1;                              /* CFDTMPTR1        */
    union __tag148 CFDTMFDCTR1;                            /* CFDTMFDCTR1      */
    union __tag148 CFDTMDF0_1;                             /* CFDTMDF0_1       */
    union __tag148 CFDTMDF1_1;                             /* CFDTMDF1_1       */
    union __tag148 CFDTMDF2_1;                             /* CFDTMDF2_1       */
    union __tag148 CFDTMDF3_1;                             /* CFDTMDF3_1       */
    union __tag148 CFDTMDF4_1;                             /* CFDTMDF4_1       */
    union __tag148 CFDTMDF5_1;                             /* CFDTMDF5_1       */
    union __tag148 CFDTMDF6_1;                             /* CFDTMDF6_1       */
    union __tag148 CFDTMDF7_1;                             /* CFDTMDF7_1       */
    union __tag148 CFDTMDF8_1;                             /* CFDTMDF8_1       */
    union __tag148 CFDTMDF9_1;                             /* CFDTMDF9_1       */
    union __tag148 CFDTMDF10_1;                            /* CFDTMDF10_1      */
    union __tag148 CFDTMDF11_1;                            /* CFDTMDF11_1      */
    union __tag148 CFDTMDF12_1;                            /* CFDTMDF12_1      */
    union __tag148 CFDTMDF13_1;                            /* CFDTMDF13_1      */
    union __tag148 CFDTMDF14_1;                            /* CFDTMDF14_1      */
    union __tag148 CFDTMDF15_1;                            /* CFDTMDF15_1      */
    unsigned char  dummy225[52];                           /* Reserved         */
    union __tag148 CFDTMID2;                               /* CFDTMID2         */
    union __tag148 CFDTMPTR2;                              /* CFDTMPTR2        */
    union __tag148 CFDTMFDCTR2;                            /* CFDTMFDCTR2      */
    union __tag148 CFDTMDF0_2;                             /* CFDTMDF0_2       */
    union __tag148 CFDTMDF1_2;                             /* CFDTMDF1_2       */
    union __tag148 CFDTMDF2_2;                             /* CFDTMDF2_2       */
    union __tag148 CFDTMDF3_2;                             /* CFDTMDF3_2       */
    union __tag148 CFDTMDF4_2;                             /* CFDTMDF4_2       */
    union __tag148 CFDTMDF5_2;                             /* CFDTMDF5_2       */
    union __tag148 CFDTMDF6_2;                             /* CFDTMDF6_2       */
    union __tag148 CFDTMDF7_2;                             /* CFDTMDF7_2       */
    union __tag148 CFDTMDF8_2;                             /* CFDTMDF8_2       */
    union __tag148 CFDTMDF9_2;                             /* CFDTMDF9_2       */
    union __tag148 CFDTMDF10_2;                            /* CFDTMDF10_2      */
    union __tag148 CFDTMDF11_2;                            /* CFDTMDF11_2      */
    union __tag148 CFDTMDF12_2;                            /* CFDTMDF12_2      */
    union __tag148 CFDTMDF13_2;                            /* CFDTMDF13_2      */
    union __tag148 CFDTMDF14_2;                            /* CFDTMDF14_2      */
    union __tag148 CFDTMDF15_2;                            /* CFDTMDF15_2      */
    unsigned char  dummy226[52];                           /* Reserved         */
    union __tag148 CFDTMID3;                               /* CFDTMID3         */
    union __tag148 CFDTMPTR3;                              /* CFDTMPTR3        */
    union __tag148 CFDTMFDCTR3;                            /* CFDTMFDCTR3      */
    union __tag148 CFDTMDF0_3;                             /* CFDTMDF0_3       */
    union __tag148 CFDTMDF1_3;                             /* CFDTMDF1_3       */
    union __tag148 CFDTMDF2_3;                             /* CFDTMDF2_3       */
    union __tag148 CFDTMDF3_3;                             /* CFDTMDF3_3       */
    union __tag148 CFDTMDF4_3;                             /* CFDTMDF4_3       */
    union __tag148 CFDTMDF5_3;                             /* CFDTMDF5_3       */
    union __tag148 CFDTMDF6_3;                             /* CFDTMDF6_3       */
    union __tag148 CFDTMDF7_3;                             /* CFDTMDF7_3       */
    union __tag148 CFDTMDF8_3;                             /* CFDTMDF8_3       */
    union __tag148 CFDTMDF9_3;                             /* CFDTMDF9_3       */
    union __tag148 CFDTMDF10_3;                            /* CFDTMDF10_3      */
    union __tag148 CFDTMDF11_3;                            /* CFDTMDF11_3      */
    union __tag148 CFDTMDF12_3;                            /* CFDTMDF12_3      */
    union __tag148 CFDTMDF13_3;                            /* CFDTMDF13_3      */
    union __tag148 CFDTMDF14_3;                            /* CFDTMDF14_3      */
    union __tag148 CFDTMDF15_3;                            /* CFDTMDF15_3      */
    unsigned char  dummy227[52];                           /* Reserved         */
    union __tag148 CFDTMID4;                               /* CFDTMID4         */
    union __tag148 CFDTMPTR4;                              /* CFDTMPTR4        */
    union __tag148 CFDTMFDCTR4;                            /* CFDTMFDCTR4      */
    union __tag148 CFDTMDF0_4;                             /* CFDTMDF0_4       */
    union __tag148 CFDTMDF1_4;                             /* CFDTMDF1_4       */
    union __tag148 CFDTMDF2_4;                             /* CFDTMDF2_4       */
    union __tag148 CFDTMDF3_4;                             /* CFDTMDF3_4       */
    union __tag148 CFDTMDF4_4;                             /* CFDTMDF4_4       */
    union __tag148 CFDTMDF5_4;                             /* CFDTMDF5_4       */
    union __tag148 CFDTMDF6_4;                             /* CFDTMDF6_4       */
    union __tag148 CFDTMDF7_4;                             /* CFDTMDF7_4       */
    union __tag148 CFDTMDF8_4;                             /* CFDTMDF8_4       */
    union __tag148 CFDTMDF9_4;                             /* CFDTMDF9_4       */
    union __tag148 CFDTMDF10_4;                            /* CFDTMDF10_4      */
    union __tag148 CFDTMDF11_4;                            /* CFDTMDF11_4      */
    union __tag148 CFDTMDF12_4;                            /* CFDTMDF12_4      */
    union __tag148 CFDTMDF13_4;                            /* CFDTMDF13_4      */
    union __tag148 CFDTMDF14_4;                            /* CFDTMDF14_4      */
    union __tag148 CFDTMDF15_4;                            /* CFDTMDF15_4      */
    unsigned char  dummy228[52];                           /* Reserved         */
    union __tag148 CFDTMID5;                               /* CFDTMID5         */
    union __tag148 CFDTMPTR5;                              /* CFDTMPTR5        */
    union __tag148 CFDTMFDCTR5;                            /* CFDTMFDCTR5      */
    union __tag148 CFDTMDF0_5;                             /* CFDTMDF0_5       */
    union __tag148 CFDTMDF1_5;                             /* CFDTMDF1_5       */
    union __tag148 CFDTMDF2_5;                             /* CFDTMDF2_5       */
    union __tag148 CFDTMDF3_5;                             /* CFDTMDF3_5       */
    union __tag148 CFDTMDF4_5;                             /* CFDTMDF4_5       */
    union __tag148 CFDTMDF5_5;                             /* CFDTMDF5_5       */
    union __tag148 CFDTMDF6_5;                             /* CFDTMDF6_5       */
    union __tag148 CFDTMDF7_5;                             /* CFDTMDF7_5       */
    union __tag148 CFDTMDF8_5;                             /* CFDTMDF8_5       */
    union __tag148 CFDTMDF9_5;                             /* CFDTMDF9_5       */
    union __tag148 CFDTMDF10_5;                            /* CFDTMDF10_5      */
    union __tag148 CFDTMDF11_5;                            /* CFDTMDF11_5      */
    union __tag148 CFDTMDF12_5;                            /* CFDTMDF12_5      */
    union __tag148 CFDTMDF13_5;                            /* CFDTMDF13_5      */
    union __tag148 CFDTMDF14_5;                            /* CFDTMDF14_5      */
    union __tag148 CFDTMDF15_5;                            /* CFDTMDF15_5      */
    unsigned char  dummy229[52];                           /* Reserved         */
    union __tag148 CFDTMID6;                               /* CFDTMID6         */
    union __tag148 CFDTMPTR6;                              /* CFDTMPTR6        */
    union __tag148 CFDTMFDCTR6;                            /* CFDTMFDCTR6      */
    union __tag148 CFDTMDF0_6;                             /* CFDTMDF0_6       */
    union __tag148 CFDTMDF1_6;                             /* CFDTMDF1_6       */
    union __tag148 CFDTMDF2_6;                             /* CFDTMDF2_6       */
    union __tag148 CFDTMDF3_6;                             /* CFDTMDF3_6       */
    union __tag148 CFDTMDF4_6;                             /* CFDTMDF4_6       */
    union __tag148 CFDTMDF5_6;                             /* CFDTMDF5_6       */
    union __tag148 CFDTMDF6_6;                             /* CFDTMDF6_6       */
    union __tag148 CFDTMDF7_6;                             /* CFDTMDF7_6       */
    union __tag148 CFDTMDF8_6;                             /* CFDTMDF8_6       */
    union __tag148 CFDTMDF9_6;                             /* CFDTMDF9_6       */
    union __tag148 CFDTMDF10_6;                            /* CFDTMDF10_6      */
    union __tag148 CFDTMDF11_6;                            /* CFDTMDF11_6      */
    union __tag148 CFDTMDF12_6;                            /* CFDTMDF12_6      */
    union __tag148 CFDTMDF13_6;                            /* CFDTMDF13_6      */
    union __tag148 CFDTMDF14_6;                            /* CFDTMDF14_6      */
    union __tag148 CFDTMDF15_6;                            /* CFDTMDF15_6      */
    unsigned char  dummy230[52];                           /* Reserved         */
    union __tag148 CFDTMID7;                               /* CFDTMID7         */
    union __tag148 CFDTMPTR7;                              /* CFDTMPTR7        */
    union __tag148 CFDTMFDCTR7;                            /* CFDTMFDCTR7      */
    union __tag148 CFDTMDF0_7;                             /* CFDTMDF0_7       */
    union __tag148 CFDTMDF1_7;                             /* CFDTMDF1_7       */
    union __tag148 CFDTMDF2_7;                             /* CFDTMDF2_7       */
    union __tag148 CFDTMDF3_7;                             /* CFDTMDF3_7       */
    union __tag148 CFDTMDF4_7;                             /* CFDTMDF4_7       */
    union __tag148 CFDTMDF5_7;                             /* CFDTMDF5_7       */
    union __tag148 CFDTMDF6_7;                             /* CFDTMDF6_7       */
    union __tag148 CFDTMDF7_7;                             /* CFDTMDF7_7       */
    union __tag148 CFDTMDF8_7;                             /* CFDTMDF8_7       */
    union __tag148 CFDTMDF9_7;                             /* CFDTMDF9_7       */
    union __tag148 CFDTMDF10_7;                            /* CFDTMDF10_7      */
    union __tag148 CFDTMDF11_7;                            /* CFDTMDF11_7      */
    union __tag148 CFDTMDF12_7;                            /* CFDTMDF12_7      */
    union __tag148 CFDTMDF13_7;                            /* CFDTMDF13_7      */
    union __tag148 CFDTMDF14_7;                            /* CFDTMDF14_7      */
    union __tag148 CFDTMDF15_7;                            /* CFDTMDF15_7      */
    unsigned char  dummy231[52];                           /* Reserved         */
    union __tag148 CFDTMID8;                               /* CFDTMID8         */
    union __tag148 CFDTMPTR8;                              /* CFDTMPTR8        */
    union __tag148 CFDTMFDCTR8;                            /* CFDTMFDCTR8      */
    union __tag148 CFDTMDF0_8;                             /* CFDTMDF0_8       */
    union __tag148 CFDTMDF1_8;                             /* CFDTMDF1_8       */
    union __tag148 CFDTMDF2_8;                             /* CFDTMDF2_8       */
    union __tag148 CFDTMDF3_8;                             /* CFDTMDF3_8       */
    union __tag148 CFDTMDF4_8;                             /* CFDTMDF4_8       */
    union __tag148 CFDTMDF5_8;                             /* CFDTMDF5_8       */
    union __tag148 CFDTMDF6_8;                             /* CFDTMDF6_8       */
    union __tag148 CFDTMDF7_8;                             /* CFDTMDF7_8       */
    union __tag148 CFDTMDF8_8;                             /* CFDTMDF8_8       */
    union __tag148 CFDTMDF9_8;                             /* CFDTMDF9_8       */
    union __tag148 CFDTMDF10_8;                            /* CFDTMDF10_8      */
    union __tag148 CFDTMDF11_8;                            /* CFDTMDF11_8      */
    union __tag148 CFDTMDF12_8;                            /* CFDTMDF12_8      */
    union __tag148 CFDTMDF13_8;                            /* CFDTMDF13_8      */
    union __tag148 CFDTMDF14_8;                            /* CFDTMDF14_8      */
    union __tag148 CFDTMDF15_8;                            /* CFDTMDF15_8      */
    unsigned char  dummy232[52];                           /* Reserved         */
    union __tag148 CFDTMID9;                               /* CFDTMID9         */
    union __tag148 CFDTMPTR9;                              /* CFDTMPTR9        */
    union __tag148 CFDTMFDCTR9;                            /* CFDTMFDCTR9      */
    union __tag148 CFDTMDF0_9;                             /* CFDTMDF0_9       */
    union __tag148 CFDTMDF1_9;                             /* CFDTMDF1_9       */
    union __tag148 CFDTMDF2_9;                             /* CFDTMDF2_9       */
    union __tag148 CFDTMDF3_9;                             /* CFDTMDF3_9       */
    union __tag148 CFDTMDF4_9;                             /* CFDTMDF4_9       */
    union __tag148 CFDTMDF5_9;                             /* CFDTMDF5_9       */
    union __tag148 CFDTMDF6_9;                             /* CFDTMDF6_9       */
    union __tag148 CFDTMDF7_9;                             /* CFDTMDF7_9       */
    union __tag148 CFDTMDF8_9;                             /* CFDTMDF8_9       */
    union __tag148 CFDTMDF9_9;                             /* CFDTMDF9_9       */
    union __tag148 CFDTMDF10_9;                            /* CFDTMDF10_9      */
    union __tag148 CFDTMDF11_9;                            /* CFDTMDF11_9      */
    union __tag148 CFDTMDF12_9;                            /* CFDTMDF12_9      */
    union __tag148 CFDTMDF13_9;                            /* CFDTMDF13_9      */
    union __tag148 CFDTMDF14_9;                            /* CFDTMDF14_9      */
    union __tag148 CFDTMDF15_9;                            /* CFDTMDF15_9      */
    unsigned char  dummy233[52];                           /* Reserved         */
    union __tag148 CFDTMID10;                              /* CFDTMID10        */
    union __tag148 CFDTMPTR10;                             /* CFDTMPTR10       */
    union __tag148 CFDTMFDCTR10;                           /* CFDTMFDCTR10     */
    union __tag148 CFDTMDF0_10;                            /* CFDTMDF0_10      */
    union __tag148 CFDTMDF1_10;                            /* CFDTMDF1_10      */
    union __tag148 CFDTMDF2_10;                            /* CFDTMDF2_10      */
    union __tag148 CFDTMDF3_10;                            /* CFDTMDF3_10      */
    union __tag148 CFDTMDF4_10;                            /* CFDTMDF4_10      */
    union __tag148 CFDTMDF5_10;                            /* CFDTMDF5_10      */
    union __tag148 CFDTMDF6_10;                            /* CFDTMDF6_10      */
    union __tag148 CFDTMDF7_10;                            /* CFDTMDF7_10      */
    union __tag148 CFDTMDF8_10;                            /* CFDTMDF8_10      */
    union __tag148 CFDTMDF9_10;                            /* CFDTMDF9_10      */
    union __tag148 CFDTMDF10_10;                           /* CFDTMDF10_10     */
    union __tag148 CFDTMDF11_10;                           /* CFDTMDF11_10     */
    union __tag148 CFDTMDF12_10;                           /* CFDTMDF12_10     */
    union __tag148 CFDTMDF13_10;                           /* CFDTMDF13_10     */
    union __tag148 CFDTMDF14_10;                           /* CFDTMDF14_10     */
    union __tag148 CFDTMDF15_10;                           /* CFDTMDF15_10     */
    unsigned char  dummy234[52];                           /* Reserved         */
    union __tag148 CFDTMID11;                              /* CFDTMID11        */
    union __tag148 CFDTMPTR11;                             /* CFDTMPTR11       */
    union __tag148 CFDTMFDCTR11;                           /* CFDTMFDCTR11     */
    union __tag148 CFDTMDF0_11;                            /* CFDTMDF0_11      */
    union __tag148 CFDTMDF1_11;                            /* CFDTMDF1_11      */
    union __tag148 CFDTMDF2_11;                            /* CFDTMDF2_11      */
    union __tag148 CFDTMDF3_11;                            /* CFDTMDF3_11      */
    union __tag148 CFDTMDF4_11;                            /* CFDTMDF4_11      */
    union __tag148 CFDTMDF5_11;                            /* CFDTMDF5_11      */
    union __tag148 CFDTMDF6_11;                            /* CFDTMDF6_11      */
    union __tag148 CFDTMDF7_11;                            /* CFDTMDF7_11      */
    union __tag148 CFDTMDF8_11;                            /* CFDTMDF8_11      */
    union __tag148 CFDTMDF9_11;                            /* CFDTMDF9_11      */
    union __tag148 CFDTMDF10_11;                           /* CFDTMDF10_11     */
    union __tag148 CFDTMDF11_11;                           /* CFDTMDF11_11     */
    union __tag148 CFDTMDF12_11;                           /* CFDTMDF12_11     */
    union __tag148 CFDTMDF13_11;                           /* CFDTMDF13_11     */
    union __tag148 CFDTMDF14_11;                           /* CFDTMDF14_11     */
    union __tag148 CFDTMDF15_11;                           /* CFDTMDF15_11     */
    unsigned char  dummy235[52];                           /* Reserved         */
    union __tag148 CFDTMID12;                              /* CFDTMID12        */
    union __tag148 CFDTMPTR12;                             /* CFDTMPTR12       */
    union __tag148 CFDTMFDCTR12;                           /* CFDTMFDCTR12     */
    union __tag148 CFDTMDF0_12;                            /* CFDTMDF0_12      */
    union __tag148 CFDTMDF1_12;                            /* CFDTMDF1_12      */
    union __tag148 CFDTMDF2_12;                            /* CFDTMDF2_12      */
    union __tag148 CFDTMDF3_12;                            /* CFDTMDF3_12      */
    union __tag148 CFDTMDF4_12;                            /* CFDTMDF4_12      */
    union __tag148 CFDTMDF5_12;                            /* CFDTMDF5_12      */
    union __tag148 CFDTMDF6_12;                            /* CFDTMDF6_12      */
    union __tag148 CFDTMDF7_12;                            /* CFDTMDF7_12      */
    union __tag148 CFDTMDF8_12;                            /* CFDTMDF8_12      */
    union __tag148 CFDTMDF9_12;                            /* CFDTMDF9_12      */
    union __tag148 CFDTMDF10_12;                           /* CFDTMDF10_12     */
    union __tag148 CFDTMDF11_12;                           /* CFDTMDF11_12     */
    union __tag148 CFDTMDF12_12;                           /* CFDTMDF12_12     */
    union __tag148 CFDTMDF13_12;                           /* CFDTMDF13_12     */
    union __tag148 CFDTMDF14_12;                           /* CFDTMDF14_12     */
    union __tag148 CFDTMDF15_12;                           /* CFDTMDF15_12     */
    unsigned char  dummy236[52];                           /* Reserved         */
    union __tag148 CFDTMID13;                              /* CFDTMID13        */
    union __tag148 CFDTMPTR13;                             /* CFDTMPTR13       */
    union __tag148 CFDTMFDCTR13;                           /* CFDTMFDCTR13     */
    union __tag148 CFDTMDF0_13;                            /* CFDTMDF0_13      */
    union __tag148 CFDTMDF1_13;                            /* CFDTMDF1_13      */
    union __tag148 CFDTMDF2_13;                            /* CFDTMDF2_13      */
    union __tag148 CFDTMDF3_13;                            /* CFDTMDF3_13      */
    union __tag148 CFDTMDF4_13;                            /* CFDTMDF4_13      */
    union __tag148 CFDTMDF5_13;                            /* CFDTMDF5_13      */
    union __tag148 CFDTMDF6_13;                            /* CFDTMDF6_13      */
    union __tag148 CFDTMDF7_13;                            /* CFDTMDF7_13      */
    union __tag148 CFDTMDF8_13;                            /* CFDTMDF8_13      */
    union __tag148 CFDTMDF9_13;                            /* CFDTMDF9_13      */
    union __tag148 CFDTMDF10_13;                           /* CFDTMDF10_13     */
    union __tag148 CFDTMDF11_13;                           /* CFDTMDF11_13     */
    union __tag148 CFDTMDF12_13;                           /* CFDTMDF12_13     */
    union __tag148 CFDTMDF13_13;                           /* CFDTMDF13_13     */
    union __tag148 CFDTMDF14_13;                           /* CFDTMDF14_13     */
    union __tag148 CFDTMDF15_13;                           /* CFDTMDF15_13     */
    unsigned char  dummy237[52];                           /* Reserved         */
    union __tag148 CFDTMID14;                              /* CFDTMID14        */
    union __tag148 CFDTMPTR14;                             /* CFDTMPTR14       */
    union __tag148 CFDTMFDCTR14;                           /* CFDTMFDCTR14     */
    union __tag148 CFDTMDF0_14;                            /* CFDTMDF0_14      */
    union __tag148 CFDTMDF1_14;                            /* CFDTMDF1_14      */
    union __tag148 CFDTMDF2_14;                            /* CFDTMDF2_14      */
    union __tag148 CFDTMDF3_14;                            /* CFDTMDF3_14      */
    union __tag148 CFDTMDF4_14;                            /* CFDTMDF4_14      */
    union __tag148 CFDTMDF5_14;                            /* CFDTMDF5_14      */
    union __tag148 CFDTMDF6_14;                            /* CFDTMDF6_14      */
    union __tag148 CFDTMDF7_14;                            /* CFDTMDF7_14      */
    union __tag148 CFDTMDF8_14;                            /* CFDTMDF8_14      */
    union __tag148 CFDTMDF9_14;                            /* CFDTMDF9_14      */
    union __tag148 CFDTMDF10_14;                           /* CFDTMDF10_14     */
    union __tag148 CFDTMDF11_14;                           /* CFDTMDF11_14     */
    union __tag148 CFDTMDF12_14;                           /* CFDTMDF12_14     */
    union __tag148 CFDTMDF13_14;                           /* CFDTMDF13_14     */
    union __tag148 CFDTMDF14_14;                           /* CFDTMDF14_14     */
    union __tag148 CFDTMDF15_14;                           /* CFDTMDF15_14     */
    unsigned char  dummy238[52];                           /* Reserved         */
    union __tag148 CFDTMID15;                              /* CFDTMID15        */
    union __tag148 CFDTMPTR15;                             /* CFDTMPTR15       */
    union __tag148 CFDTMFDCTR15;                           /* CFDTMFDCTR15     */
    union __tag148 CFDTMDF0_15;                            /* CFDTMDF0_15      */
    union __tag148 CFDTMDF1_15;                            /* CFDTMDF1_15      */
    union __tag148 CFDTMDF2_15;                            /* CFDTMDF2_15      */
    union __tag148 CFDTMDF3_15;                            /* CFDTMDF3_15      */
    union __tag148 CFDTMDF4_15;                            /* CFDTMDF4_15      */
    union __tag148 CFDTMDF5_15;                            /* CFDTMDF5_15      */
    union __tag148 CFDTMDF6_15;                            /* CFDTMDF6_15      */
    union __tag148 CFDTMDF7_15;                            /* CFDTMDF7_15      */
    union __tag148 CFDTMDF8_15;                            /* CFDTMDF8_15      */
    union __tag148 CFDTMDF9_15;                            /* CFDTMDF9_15      */
    union __tag148 CFDTMDF10_15;                           /* CFDTMDF10_15     */
    union __tag148 CFDTMDF11_15;                           /* CFDTMDF11_15     */
    union __tag148 CFDTMDF12_15;                           /* CFDTMDF12_15     */
    union __tag148 CFDTMDF13_15;                           /* CFDTMDF13_15     */
    union __tag148 CFDTMDF14_15;                           /* CFDTMDF14_15     */
    union __tag148 CFDTMDF15_15;                           /* CFDTMDF15_15     */
    unsigned char  dummy239[52];                           /* Reserved         */
    union __tag148 CFDTMID16;                              /* CFDTMID16        */
    union __tag148 CFDTMPTR16;                             /* CFDTMPTR16       */
    union __tag148 CFDTMFDCTR16;                           /* CFDTMFDCTR16     */
    union __tag148 CFDTMDF0_16;                            /* CFDTMDF0_16      */
    union __tag148 CFDTMDF1_16;                            /* CFDTMDF1_16      */
    union __tag148 CFDTMDF2_16;                            /* CFDTMDF2_16      */
    union __tag148 CFDTMDF3_16;                            /* CFDTMDF3_16      */
    union __tag148 CFDTMDF4_16;                            /* CFDTMDF4_16      */
    union __tag148 CFDTMDF5_16;                            /* CFDTMDF5_16      */
    union __tag148 CFDTMDF6_16;                            /* CFDTMDF6_16      */
    union __tag148 CFDTMDF7_16;                            /* CFDTMDF7_16      */
    union __tag148 CFDTMDF8_16;                            /* CFDTMDF8_16      */
    union __tag148 CFDTMDF9_16;                            /* CFDTMDF9_16      */
    union __tag148 CFDTMDF10_16;                           /* CFDTMDF10_16     */
    union __tag148 CFDTMDF11_16;                           /* CFDTMDF11_16     */
    union __tag148 CFDTMDF12_16;                           /* CFDTMDF12_16     */
    union __tag148 CFDTMDF13_16;                           /* CFDTMDF13_16     */
    union __tag148 CFDTMDF14_16;                           /* CFDTMDF14_16     */
    union __tag148 CFDTMDF15_16;                           /* CFDTMDF15_16     */
    unsigned char  dummy240[52];                           /* Reserved         */
    union __tag148 CFDTMID17;                              /* CFDTMID17        */
    union __tag148 CFDTMPTR17;                             /* CFDTMPTR17       */
    union __tag148 CFDTMFDCTR17;                           /* CFDTMFDCTR17     */
    union __tag148 CFDTMDF0_17;                            /* CFDTMDF0_17      */
    union __tag148 CFDTMDF1_17;                            /* CFDTMDF1_17      */
    union __tag148 CFDTMDF2_17;                            /* CFDTMDF2_17      */
    union __tag148 CFDTMDF3_17;                            /* CFDTMDF3_17      */
    union __tag148 CFDTMDF4_17;                            /* CFDTMDF4_17      */
    union __tag148 CFDTMDF5_17;                            /* CFDTMDF5_17      */
    union __tag148 CFDTMDF6_17;                            /* CFDTMDF6_17      */
    union __tag148 CFDTMDF7_17;                            /* CFDTMDF7_17      */
    union __tag148 CFDTMDF8_17;                            /* CFDTMDF8_17      */
    union __tag148 CFDTMDF9_17;                            /* CFDTMDF9_17      */
    union __tag148 CFDTMDF10_17;                           /* CFDTMDF10_17     */
    union __tag148 CFDTMDF11_17;                           /* CFDTMDF11_17     */
    union __tag148 CFDTMDF12_17;                           /* CFDTMDF12_17     */
    union __tag148 CFDTMDF13_17;                           /* CFDTMDF13_17     */
    union __tag148 CFDTMDF14_17;                           /* CFDTMDF14_17     */
    union __tag148 CFDTMDF15_17;                           /* CFDTMDF15_17     */
    unsigned char  dummy241[52];                           /* Reserved         */
    union __tag148 CFDTMID18;                              /* CFDTMID18        */
    union __tag148 CFDTMPTR18;                             /* CFDTMPTR18       */
    union __tag148 CFDTMFDCTR18;                           /* CFDTMFDCTR18     */
    union __tag148 CFDTMDF0_18;                            /* CFDTMDF0_18      */
    union __tag148 CFDTMDF1_18;                            /* CFDTMDF1_18      */
    union __tag148 CFDTMDF2_18;                            /* CFDTMDF2_18      */
    union __tag148 CFDTMDF3_18;                            /* CFDTMDF3_18      */
    union __tag148 CFDTMDF4_18;                            /* CFDTMDF4_18      */
    union __tag148 CFDTMDF5_18;                            /* CFDTMDF5_18      */
    union __tag148 CFDTMDF6_18;                            /* CFDTMDF6_18      */
    union __tag148 CFDTMDF7_18;                            /* CFDTMDF7_18      */
    union __tag148 CFDTMDF8_18;                            /* CFDTMDF8_18      */
    union __tag148 CFDTMDF9_18;                            /* CFDTMDF9_18      */
    union __tag148 CFDTMDF10_18;                           /* CFDTMDF10_18     */
    union __tag148 CFDTMDF11_18;                           /* CFDTMDF11_18     */
    union __tag148 CFDTMDF12_18;                           /* CFDTMDF12_18     */
    union __tag148 CFDTMDF13_18;                           /* CFDTMDF13_18     */
    union __tag148 CFDTMDF14_18;                           /* CFDTMDF14_18     */
    union __tag148 CFDTMDF15_18;                           /* CFDTMDF15_18     */
    unsigned char  dummy242[52];                           /* Reserved         */
    union __tag148 CFDTMID19;                              /* CFDTMID19        */
    union __tag148 CFDTMPTR19;                             /* CFDTMPTR19       */
    union __tag148 CFDTMFDCTR19;                           /* CFDTMFDCTR19     */
    union __tag148 CFDTMDF0_19;                            /* CFDTMDF0_19      */
    union __tag148 CFDTMDF1_19;                            /* CFDTMDF1_19      */
    union __tag148 CFDTMDF2_19;                            /* CFDTMDF2_19      */
    union __tag148 CFDTMDF3_19;                            /* CFDTMDF3_19      */
    union __tag148 CFDTMDF4_19;                            /* CFDTMDF4_19      */
    union __tag148 CFDTMDF5_19;                            /* CFDTMDF5_19      */
    union __tag148 CFDTMDF6_19;                            /* CFDTMDF6_19      */
    union __tag148 CFDTMDF7_19;                            /* CFDTMDF7_19      */
    union __tag148 CFDTMDF8_19;                            /* CFDTMDF8_19      */
    union __tag148 CFDTMDF9_19;                            /* CFDTMDF9_19      */
    union __tag148 CFDTMDF10_19;                           /* CFDTMDF10_19     */
    union __tag148 CFDTMDF11_19;                           /* CFDTMDF11_19     */
    union __tag148 CFDTMDF12_19;                           /* CFDTMDF12_19     */
    union __tag148 CFDTMDF13_19;                           /* CFDTMDF13_19     */
    union __tag148 CFDTMDF14_19;                           /* CFDTMDF14_19     */
    union __tag148 CFDTMDF15_19;                           /* CFDTMDF15_19     */
    unsigned char  dummy243[52];                           /* Reserved         */
    union __tag148 CFDTMID20;                              /* CFDTMID20        */
    union __tag148 CFDTMPTR20;                             /* CFDTMPTR20       */
    union __tag148 CFDTMFDCTR20;                           /* CFDTMFDCTR20     */
    union __tag148 CFDTMDF0_20;                            /* CFDTMDF0_20      */
    union __tag148 CFDTMDF1_20;                            /* CFDTMDF1_20      */
    union __tag148 CFDTMDF2_20;                            /* CFDTMDF2_20      */
    union __tag148 CFDTMDF3_20;                            /* CFDTMDF3_20      */
    union __tag148 CFDTMDF4_20;                            /* CFDTMDF4_20      */
    union __tag148 CFDTMDF5_20;                            /* CFDTMDF5_20      */
    union __tag148 CFDTMDF6_20;                            /* CFDTMDF6_20      */
    union __tag148 CFDTMDF7_20;                            /* CFDTMDF7_20      */
    union __tag148 CFDTMDF8_20;                            /* CFDTMDF8_20      */
    union __tag148 CFDTMDF9_20;                            /* CFDTMDF9_20      */
    union __tag148 CFDTMDF10_20;                           /* CFDTMDF10_20     */
    union __tag148 CFDTMDF11_20;                           /* CFDTMDF11_20     */
    union __tag148 CFDTMDF12_20;                           /* CFDTMDF12_20     */
    union __tag148 CFDTMDF13_20;                           /* CFDTMDF13_20     */
    union __tag148 CFDTMDF14_20;                           /* CFDTMDF14_20     */
    union __tag148 CFDTMDF15_20;                           /* CFDTMDF15_20     */
    unsigned char  dummy244[52];                           /* Reserved         */
    union __tag148 CFDTMID21;                              /* CFDTMID21        */
    union __tag148 CFDTMPTR21;                             /* CFDTMPTR21       */
    union __tag148 CFDTMFDCTR21;                           /* CFDTMFDCTR21     */
    union __tag148 CFDTMDF0_21;                            /* CFDTMDF0_21      */
    union __tag148 CFDTMDF1_21;                            /* CFDTMDF1_21      */
    union __tag148 CFDTMDF2_21;                            /* CFDTMDF2_21      */
    union __tag148 CFDTMDF3_21;                            /* CFDTMDF3_21      */
    union __tag148 CFDTMDF4_21;                            /* CFDTMDF4_21      */
    union __tag148 CFDTMDF5_21;                            /* CFDTMDF5_21      */
    union __tag148 CFDTMDF6_21;                            /* CFDTMDF6_21      */
    union __tag148 CFDTMDF7_21;                            /* CFDTMDF7_21      */
    union __tag148 CFDTMDF8_21;                            /* CFDTMDF8_21      */
    union __tag148 CFDTMDF9_21;                            /* CFDTMDF9_21      */
    union __tag148 CFDTMDF10_21;                           /* CFDTMDF10_21     */
    union __tag148 CFDTMDF11_21;                           /* CFDTMDF11_21     */
    union __tag148 CFDTMDF12_21;                           /* CFDTMDF12_21     */
    union __tag148 CFDTMDF13_21;                           /* CFDTMDF13_21     */
    union __tag148 CFDTMDF14_21;                           /* CFDTMDF14_21     */
    union __tag148 CFDTMDF15_21;                           /* CFDTMDF15_21     */
    unsigned char  dummy245[52];                           /* Reserved         */
    union __tag148 CFDTMID22;                              /* CFDTMID22        */
    union __tag148 CFDTMPTR22;                             /* CFDTMPTR22       */
    union __tag148 CFDTMFDCTR22;                           /* CFDTMFDCTR22     */
    union __tag148 CFDTMDF0_22;                            /* CFDTMDF0_22      */
    union __tag148 CFDTMDF1_22;                            /* CFDTMDF1_22      */
    union __tag148 CFDTMDF2_22;                            /* CFDTMDF2_22      */
    union __tag148 CFDTMDF3_22;                            /* CFDTMDF3_22      */
    union __tag148 CFDTMDF4_22;                            /* CFDTMDF4_22      */
    union __tag148 CFDTMDF5_22;                            /* CFDTMDF5_22      */
    union __tag148 CFDTMDF6_22;                            /* CFDTMDF6_22      */
    union __tag148 CFDTMDF7_22;                            /* CFDTMDF7_22      */
    union __tag148 CFDTMDF8_22;                            /* CFDTMDF8_22      */
    union __tag148 CFDTMDF9_22;                            /* CFDTMDF9_22      */
    union __tag148 CFDTMDF10_22;                           /* CFDTMDF10_22     */
    union __tag148 CFDTMDF11_22;                           /* CFDTMDF11_22     */
    union __tag148 CFDTMDF12_22;                           /* CFDTMDF12_22     */
    union __tag148 CFDTMDF13_22;                           /* CFDTMDF13_22     */
    union __tag148 CFDTMDF14_22;                           /* CFDTMDF14_22     */
    union __tag148 CFDTMDF15_22;                           /* CFDTMDF15_22     */
    unsigned char  dummy246[52];                           /* Reserved         */
    union __tag148 CFDTMID23;                              /* CFDTMID23        */
    union __tag148 CFDTMPTR23;                             /* CFDTMPTR23       */
    union __tag148 CFDTMFDCTR23;                           /* CFDTMFDCTR23     */
    union __tag148 CFDTMDF0_23;                            /* CFDTMDF0_23      */
    union __tag148 CFDTMDF1_23;                            /* CFDTMDF1_23      */
    union __tag148 CFDTMDF2_23;                            /* CFDTMDF2_23      */
    union __tag148 CFDTMDF3_23;                            /* CFDTMDF3_23      */
    union __tag148 CFDTMDF4_23;                            /* CFDTMDF4_23      */
    union __tag148 CFDTMDF5_23;                            /* CFDTMDF5_23      */
    union __tag148 CFDTMDF6_23;                            /* CFDTMDF6_23      */
    union __tag148 CFDTMDF7_23;                            /* CFDTMDF7_23      */
    union __tag148 CFDTMDF8_23;                            /* CFDTMDF8_23      */
    union __tag148 CFDTMDF9_23;                            /* CFDTMDF9_23      */
    union __tag148 CFDTMDF10_23;                           /* CFDTMDF10_23     */
    union __tag148 CFDTMDF11_23;                           /* CFDTMDF11_23     */
    union __tag148 CFDTMDF12_23;                           /* CFDTMDF12_23     */
    union __tag148 CFDTMDF13_23;                           /* CFDTMDF13_23     */
    union __tag148 CFDTMDF14_23;                           /* CFDTMDF14_23     */
    union __tag148 CFDTMDF15_23;                           /* CFDTMDF15_23     */
    unsigned char  dummy247[52];                           /* Reserved         */
    union __tag148 CFDTMID24;                              /* CFDTMID24        */
    union __tag148 CFDTMPTR24;                             /* CFDTMPTR24       */
    union __tag148 CFDTMFDCTR24;                           /* CFDTMFDCTR24     */
    union __tag148 CFDTMDF0_24;                            /* CFDTMDF0_24      */
    union __tag148 CFDTMDF1_24;                            /* CFDTMDF1_24      */
    union __tag148 CFDTMDF2_24;                            /* CFDTMDF2_24      */
    union __tag148 CFDTMDF3_24;                            /* CFDTMDF3_24      */
    union __tag148 CFDTMDF4_24;                            /* CFDTMDF4_24      */
    union __tag148 CFDTMDF5_24;                            /* CFDTMDF5_24      */
    union __tag148 CFDTMDF6_24;                            /* CFDTMDF6_24      */
    union __tag148 CFDTMDF7_24;                            /* CFDTMDF7_24      */
    union __tag148 CFDTMDF8_24;                            /* CFDTMDF8_24      */
    union __tag148 CFDTMDF9_24;                            /* CFDTMDF9_24      */
    union __tag148 CFDTMDF10_24;                           /* CFDTMDF10_24     */
    union __tag148 CFDTMDF11_24;                           /* CFDTMDF11_24     */
    union __tag148 CFDTMDF12_24;                           /* CFDTMDF12_24     */
    union __tag148 CFDTMDF13_24;                           /* CFDTMDF13_24     */
    union __tag148 CFDTMDF14_24;                           /* CFDTMDF14_24     */
    union __tag148 CFDTMDF15_24;                           /* CFDTMDF15_24     */
    unsigned char  dummy248[52];                           /* Reserved         */
    union __tag148 CFDTMID25;                              /* CFDTMID25        */
    union __tag148 CFDTMPTR25;                             /* CFDTMPTR25       */
    union __tag148 CFDTMFDCTR25;                           /* CFDTMFDCTR25     */
    union __tag148 CFDTMDF0_25;                            /* CFDTMDF0_25      */
    union __tag148 CFDTMDF1_25;                            /* CFDTMDF1_25      */
    union __tag148 CFDTMDF2_25;                            /* CFDTMDF2_25      */
    union __tag148 CFDTMDF3_25;                            /* CFDTMDF3_25      */
    union __tag148 CFDTMDF4_25;                            /* CFDTMDF4_25      */
    union __tag148 CFDTMDF5_25;                            /* CFDTMDF5_25      */
    union __tag148 CFDTMDF6_25;                            /* CFDTMDF6_25      */
    union __tag148 CFDTMDF7_25;                            /* CFDTMDF7_25      */
    union __tag148 CFDTMDF8_25;                            /* CFDTMDF8_25      */
    union __tag148 CFDTMDF9_25;                            /* CFDTMDF9_25      */
    union __tag148 CFDTMDF10_25;                           /* CFDTMDF10_25     */
    union __tag148 CFDTMDF11_25;                           /* CFDTMDF11_25     */
    union __tag148 CFDTMDF12_25;                           /* CFDTMDF12_25     */
    union __tag148 CFDTMDF13_25;                           /* CFDTMDF13_25     */
    union __tag148 CFDTMDF14_25;                           /* CFDTMDF14_25     */
    union __tag148 CFDTMDF15_25;                           /* CFDTMDF15_25     */
    unsigned char  dummy249[52];                           /* Reserved         */
    union __tag148 CFDTMID26;                              /* CFDTMID26        */
    union __tag148 CFDTMPTR26;                             /* CFDTMPTR26       */
    union __tag148 CFDTMFDCTR26;                           /* CFDTMFDCTR26     */
    union __tag148 CFDTMDF0_26;                            /* CFDTMDF0_26      */
    union __tag148 CFDTMDF1_26;                            /* CFDTMDF1_26      */
    union __tag148 CFDTMDF2_26;                            /* CFDTMDF2_26      */
    union __tag148 CFDTMDF3_26;                            /* CFDTMDF3_26      */
    union __tag148 CFDTMDF4_26;                            /* CFDTMDF4_26      */
    union __tag148 CFDTMDF5_26;                            /* CFDTMDF5_26      */
    union __tag148 CFDTMDF6_26;                            /* CFDTMDF6_26      */
    union __tag148 CFDTMDF7_26;                            /* CFDTMDF7_26      */
    union __tag148 CFDTMDF8_26;                            /* CFDTMDF8_26      */
    union __tag148 CFDTMDF9_26;                            /* CFDTMDF9_26      */
    union __tag148 CFDTMDF10_26;                           /* CFDTMDF10_26     */
    union __tag148 CFDTMDF11_26;                           /* CFDTMDF11_26     */
    union __tag148 CFDTMDF12_26;                           /* CFDTMDF12_26     */
    union __tag148 CFDTMDF13_26;                           /* CFDTMDF13_26     */
    union __tag148 CFDTMDF14_26;                           /* CFDTMDF14_26     */
    union __tag148 CFDTMDF15_26;                           /* CFDTMDF15_26     */
    unsigned char  dummy250[52];                           /* Reserved         */
    union __tag148 CFDTMID27;                              /* CFDTMID27        */
    union __tag148 CFDTMPTR27;                             /* CFDTMPTR27       */
    union __tag148 CFDTMFDCTR27;                           /* CFDTMFDCTR27     */
    union __tag148 CFDTMDF0_27;                            /* CFDTMDF0_27      */
    union __tag148 CFDTMDF1_27;                            /* CFDTMDF1_27      */
    union __tag148 CFDTMDF2_27;                            /* CFDTMDF2_27      */
    union __tag148 CFDTMDF3_27;                            /* CFDTMDF3_27      */
    union __tag148 CFDTMDF4_27;                            /* CFDTMDF4_27      */
    union __tag148 CFDTMDF5_27;                            /* CFDTMDF5_27      */
    union __tag148 CFDTMDF6_27;                            /* CFDTMDF6_27      */
    union __tag148 CFDTMDF7_27;                            /* CFDTMDF7_27      */
    union __tag148 CFDTMDF8_27;                            /* CFDTMDF8_27      */
    union __tag148 CFDTMDF9_27;                            /* CFDTMDF9_27      */
    union __tag148 CFDTMDF10_27;                           /* CFDTMDF10_27     */
    union __tag148 CFDTMDF11_27;                           /* CFDTMDF11_27     */
    union __tag148 CFDTMDF12_27;                           /* CFDTMDF12_27     */
    union __tag148 CFDTMDF13_27;                           /* CFDTMDF13_27     */
    union __tag148 CFDTMDF14_27;                           /* CFDTMDF14_27     */
    union __tag148 CFDTMDF15_27;                           /* CFDTMDF15_27     */
    unsigned char  dummy251[52];                           /* Reserved         */
    union __tag148 CFDTMID28;                              /* CFDTMID28        */
    union __tag148 CFDTMPTR28;                             /* CFDTMPTR28       */
    union __tag148 CFDTMFDCTR28;                           /* CFDTMFDCTR28     */
    union __tag148 CFDTMDF0_28;                            /* CFDTMDF0_28      */
    union __tag148 CFDTMDF1_28;                            /* CFDTMDF1_28      */
    union __tag148 CFDTMDF2_28;                            /* CFDTMDF2_28      */
    union __tag148 CFDTMDF3_28;                            /* CFDTMDF3_28      */
    union __tag148 CFDTMDF4_28;                            /* CFDTMDF4_28      */
    union __tag148 CFDTMDF5_28;                            /* CFDTMDF5_28      */
    union __tag148 CFDTMDF6_28;                            /* CFDTMDF6_28      */
    union __tag148 CFDTMDF7_28;                            /* CFDTMDF7_28      */
    union __tag148 CFDTMDF8_28;                            /* CFDTMDF8_28      */
    union __tag148 CFDTMDF9_28;                            /* CFDTMDF9_28      */
    union __tag148 CFDTMDF10_28;                           /* CFDTMDF10_28     */
    union __tag148 CFDTMDF11_28;                           /* CFDTMDF11_28     */
    union __tag148 CFDTMDF12_28;                           /* CFDTMDF12_28     */
    union __tag148 CFDTMDF13_28;                           /* CFDTMDF13_28     */
    union __tag148 CFDTMDF14_28;                           /* CFDTMDF14_28     */
    union __tag148 CFDTMDF15_28;                           /* CFDTMDF15_28     */
    unsigned char  dummy252[52];                           /* Reserved         */
    union __tag148 CFDTMID29;                              /* CFDTMID29        */
    union __tag148 CFDTMPTR29;                             /* CFDTMPTR29       */
    union __tag148 CFDTMFDCTR29;                           /* CFDTMFDCTR29     */
    union __tag148 CFDTMDF0_29;                            /* CFDTMDF0_29      */
    union __tag148 CFDTMDF1_29;                            /* CFDTMDF1_29      */
    union __tag148 CFDTMDF2_29;                            /* CFDTMDF2_29      */
    union __tag148 CFDTMDF3_29;                            /* CFDTMDF3_29      */
    union __tag148 CFDTMDF4_29;                            /* CFDTMDF4_29      */
    union __tag148 CFDTMDF5_29;                            /* CFDTMDF5_29      */
    union __tag148 CFDTMDF6_29;                            /* CFDTMDF6_29      */
    union __tag148 CFDTMDF7_29;                            /* CFDTMDF7_29      */
    union __tag148 CFDTMDF8_29;                            /* CFDTMDF8_29      */
    union __tag148 CFDTMDF9_29;                            /* CFDTMDF9_29      */
    union __tag148 CFDTMDF10_29;                           /* CFDTMDF10_29     */
    union __tag148 CFDTMDF11_29;                           /* CFDTMDF11_29     */
    union __tag148 CFDTMDF12_29;                           /* CFDTMDF12_29     */
    union __tag148 CFDTMDF13_29;                           /* CFDTMDF13_29     */
    union __tag148 CFDTMDF14_29;                           /* CFDTMDF14_29     */
    union __tag148 CFDTMDF15_29;                           /* CFDTMDF15_29     */
    unsigned char  dummy253[52];                           /* Reserved         */
    union __tag148 CFDTMID30;                              /* CFDTMID30        */
    union __tag148 CFDTMPTR30;                             /* CFDTMPTR30       */
    union __tag148 CFDTMFDCTR30;                           /* CFDTMFDCTR30     */
    union __tag148 CFDTMDF0_30;                            /* CFDTMDF0_30      */
    union __tag148 CFDTMDF1_30;                            /* CFDTMDF1_30      */
    union __tag148 CFDTMDF2_30;                            /* CFDTMDF2_30      */
    union __tag148 CFDTMDF3_30;                            /* CFDTMDF3_30      */
    union __tag148 CFDTMDF4_30;                            /* CFDTMDF4_30      */
    union __tag148 CFDTMDF5_30;                            /* CFDTMDF5_30      */
    union __tag148 CFDTMDF6_30;                            /* CFDTMDF6_30      */
    union __tag148 CFDTMDF7_30;                            /* CFDTMDF7_30      */
    union __tag148 CFDTMDF8_30;                            /* CFDTMDF8_30      */
    union __tag148 CFDTMDF9_30;                            /* CFDTMDF9_30      */
    union __tag148 CFDTMDF10_30;                           /* CFDTMDF10_30     */
    union __tag148 CFDTMDF11_30;                           /* CFDTMDF11_30     */
    union __tag148 CFDTMDF12_30;                           /* CFDTMDF12_30     */
    union __tag148 CFDTMDF13_30;                           /* CFDTMDF13_30     */
    union __tag148 CFDTMDF14_30;                           /* CFDTMDF14_30     */
    union __tag148 CFDTMDF15_30;                           /* CFDTMDF15_30     */
    unsigned char  dummy254[52];                           /* Reserved         */
    union __tag148 CFDTMID31;                              /* CFDTMID31        */
    union __tag148 CFDTMPTR31;                             /* CFDTMPTR31       */
    union __tag148 CFDTMFDCTR31;                           /* CFDTMFDCTR31     */
    union __tag148 CFDTMDF0_31;                            /* CFDTMDF0_31      */
    union __tag148 CFDTMDF1_31;                            /* CFDTMDF1_31      */
    union __tag148 CFDTMDF2_31;                            /* CFDTMDF2_31      */
    union __tag148 CFDTMDF3_31;                            /* CFDTMDF3_31      */
    union __tag148 CFDTMDF4_31;                            /* CFDTMDF4_31      */
    union __tag148 CFDTMDF5_31;                            /* CFDTMDF5_31      */
    union __tag148 CFDTMDF6_31;                            /* CFDTMDF6_31      */
    union __tag148 CFDTMDF7_31;                            /* CFDTMDF7_31      */
    union __tag148 CFDTMDF8_31;                            /* CFDTMDF8_31      */
    union __tag148 CFDTMDF9_31;                            /* CFDTMDF9_31      */
    union __tag148 CFDTMDF10_31;                           /* CFDTMDF10_31     */
    union __tag148 CFDTMDF11_31;                           /* CFDTMDF11_31     */
    union __tag148 CFDTMDF12_31;                           /* CFDTMDF12_31     */
    union __tag148 CFDTMDF13_31;                           /* CFDTMDF13_31     */
    union __tag148 CFDTMDF14_31;                           /* CFDTMDF14_31     */
    union __tag148 CFDTMDF15_31;                           /* CFDTMDF15_31     */
    unsigned char  dummy255[28724];                        /* Reserved         */
    union __tag148 CFDTHLACC00;                            /* CFDTHLACC00      */
    union __tag148 CFDTHLACC10;                            /* CFDTHLACC10      */
    unsigned char  dummy256[1016];                         /* Reserved         */
    union __tag148 CFDRPGACC0;                             /* CFDRPGACC0       */
    union __tag148 CFDRPGACC1;                             /* CFDRPGACC1       */
    union __tag148 CFDRPGACC2;                             /* CFDRPGACC2       */
    union __tag148 CFDRPGACC3;                             /* CFDRPGACC3       */
    union __tag148 CFDRPGACC4;                             /* CFDRPGACC4       */
    union __tag148 CFDRPGACC5;                             /* CFDRPGACC5       */
    union __tag148 CFDRPGACC6;                             /* CFDRPGACC6       */
    union __tag148 CFDRPGACC7;                             /* CFDRPGACC7       */
    union __tag148 CFDRPGACC8;                             /* CFDRPGACC8       */
    union __tag148 CFDRPGACC9;                             /* CFDRPGACC9       */
    union __tag148 CFDRPGACC10;                            /* CFDRPGACC10      */
    union __tag148 CFDRPGACC11;                            /* CFDRPGACC11      */
    union __tag148 CFDRPGACC12;                            /* CFDRPGACC12      */
    union __tag148 CFDRPGACC13;                            /* CFDRPGACC13      */
    union __tag148 CFDRPGACC14;                            /* CFDRPGACC14      */
    union __tag148 CFDRPGACC15;                            /* CFDRPGACC15      */
    union __tag148 CFDRPGACC16;                            /* CFDRPGACC16      */
    union __tag148 CFDRPGACC17;                            /* CFDRPGACC17      */
    union __tag148 CFDRPGACC18;                            /* CFDRPGACC18      */
    union __tag148 CFDRPGACC19;                            /* CFDRPGACC19      */
    union __tag148 CFDRPGACC20;                            /* CFDRPGACC20      */
    union __tag148 CFDRPGACC21;                            /* CFDRPGACC21      */
    union __tag148 CFDRPGACC22;                            /* CFDRPGACC22      */
    union __tag148 CFDRPGACC23;                            /* CFDRPGACC23      */
    union __tag148 CFDRPGACC24;                            /* CFDRPGACC24      */
    union __tag148 CFDRPGACC25;                            /* CFDRPGACC25      */
    union __tag148 CFDRPGACC26;                            /* CFDRPGACC26      */
    union __tag148 CFDRPGACC27;                            /* CFDRPGACC27      */
    union __tag148 CFDRPGACC28;                            /* CFDRPGACC28      */
    union __tag148 CFDRPGACC29;                            /* CFDRPGACC29      */
    union __tag148 CFDRPGACC30;                            /* CFDRPGACC30      */
    union __tag148 CFDRPGACC31;                            /* CFDRPGACC31      */
    union __tag148 CFDRPGACC32;                            /* CFDRPGACC32      */
    union __tag148 CFDRPGACC33;                            /* CFDRPGACC33      */
    union __tag148 CFDRPGACC34;                            /* CFDRPGACC34      */
    union __tag148 CFDRPGACC35;                            /* CFDRPGACC35      */
    union __tag148 CFDRPGACC36;                            /* CFDRPGACC36      */
    union __tag148 CFDRPGACC37;                            /* CFDRPGACC37      */
    union __tag148 CFDRPGACC38;                            /* CFDRPGACC38      */
    union __tag148 CFDRPGACC39;                            /* CFDRPGACC39      */
    union __tag148 CFDRPGACC40;                            /* CFDRPGACC40      */
    union __tag148 CFDRPGACC41;                            /* CFDRPGACC41      */
    union __tag148 CFDRPGACC42;                            /* CFDRPGACC42      */
    union __tag148 CFDRPGACC43;                            /* CFDRPGACC43      */
    union __tag148 CFDRPGACC44;                            /* CFDRPGACC44      */
    union __tag148 CFDRPGACC45;                            /* CFDRPGACC45      */
    union __tag148 CFDRPGACC46;                            /* CFDRPGACC46      */
    union __tag148 CFDRPGACC47;                            /* CFDRPGACC47      */
    union __tag148 CFDRPGACC48;                            /* CFDRPGACC48      */
    union __tag148 CFDRPGACC49;                            /* CFDRPGACC49      */
    union __tag148 CFDRPGACC50;                            /* CFDRPGACC50      */
    union __tag148 CFDRPGACC51;                            /* CFDRPGACC51      */
    union __tag148 CFDRPGACC52;                            /* CFDRPGACC52      */
    union __tag148 CFDRPGACC53;                            /* CFDRPGACC53      */
    union __tag148 CFDRPGACC54;                            /* CFDRPGACC54      */
    union __tag148 CFDRPGACC55;                            /* CFDRPGACC55      */
    union __tag148 CFDRPGACC56;                            /* CFDRPGACC56      */
    union __tag148 CFDRPGACC57;                            /* CFDRPGACC57      */
    union __tag148 CFDRPGACC58;                            /* CFDRPGACC58      */
    union __tag148 CFDRPGACC59;                            /* CFDRPGACC59      */
    union __tag148 CFDRPGACC60;                            /* CFDRPGACC60      */
    union __tag148 CFDRPGACC61;                            /* CFDRPGACC61      */
    union __tag148 CFDRPGACC62;                            /* CFDRPGACC62      */
    union __tag148 CFDRPGACC63;                            /* CFDRPGACC63      */
};
struct __tag339
{                                                          /* Module           */
    unsigned long  CMP;                                    /* CMP              */
    unsigned long  CNT;                                    /* CNT              */
    unsigned char  dummy257[8];                            /* Reserved         */
    unsigned char  TE;                                     /* TE               */
    unsigned char  dummy258[3];                            /* Reserved         */
    unsigned char  TS;                                     /* TS               */
    unsigned char  dummy259[3];                            /* Reserved         */
    unsigned char  TT;                                     /* TT               */
    unsigned char  dummy260[7];                            /* Reserved         */
    unsigned char  CTL;                                    /* CTL              */
    unsigned char  dummy261[3];                            /* Reserved         */
    unsigned char  EMU;                                    /* EMU              */
};
struct __tag340
{                                                          /* Module           */
    unsigned char  CTL0;                                   /* CTL0             */
    unsigned char  dummy262[3];                            /* Reserved         */
    unsigned long  STR0;                                   /* STR0             */
    unsigned short STCR0;                                  /* STCR0            */
    unsigned char  dummy263[6];                            /* Reserved         */
    unsigned long  CTL1;                                   /* CTL1             */
    unsigned short CTL2;                                   /* CTL2             */
    unsigned char  dummy264[2];                            /* Reserved         */
    union __tag158 EMU;                                    /* EMU              */
    unsigned char  dummy265[4071];                         /* Reserved         */
    unsigned long  MCTL1;                                  /* MCTL1            */
    unsigned long  MCTL2;                                  /* MCTL2            */
    unsigned long  TX0W;                                   /* TX0W             */
    unsigned short TX0H;                                   /* TX0H             */
    unsigned char  dummy266[2];                            /* Reserved         */
    unsigned long  RX0W;                                   /* RX0W             */
    unsigned short RX0H;                                   /* RX0H             */
    unsigned char  dummy267[2];                            /* Reserved         */
    unsigned long  MRWP0;                                  /* MRWP0            */
    unsigned char  dummy268[36];                           /* Reserved         */
    unsigned short MCTL0;                                  /* MCTL0            */
    unsigned char  dummy269[2];                            /* Reserved         */
    unsigned long  CFG0;                                   /* CFG0             */
    unsigned long  CFG1;                                   /* CFG1             */
    unsigned char  dummy270[28];                           /* Reserved         */
    unsigned short BRS0;                                   /* BRS0             */
    unsigned char  dummy271[2];                            /* Reserved         */
    unsigned short BRS1;                                   /* BRS1             */
    unsigned char  dummy272[2];                            /* Reserved         */
    unsigned short BRS2;                                   /* BRS2             */
    unsigned char  dummy273[2];                            /* Reserved         */
    unsigned short BRS3;                                   /* BRS3             */
};
struct __tag341
{                                                          /* Module           */
    unsigned char  CTL0;                                   /* CTL0             */
    unsigned char  dummy274[3];                            /* Reserved         */
    unsigned long  STR0;                                   /* STR0             */
    unsigned short STCR0;                                  /* STCR0            */
    unsigned char  dummy275[6];                            /* Reserved         */
    unsigned long  CTL1;                                   /* CTL1             */
    unsigned short CTL2;                                   /* CTL2             */
    unsigned char  dummy276[2];                            /* Reserved         */
    union __tag158 EMU;                                    /* EMU              */
    unsigned char  dummy277[4071];                         /* Reserved         */
    union __tag159 BCTL0;                                  /* BCTL0            */
    unsigned char  dummy278[3];                            /* Reserved         */
    unsigned long  TX0W;                                   /* TX0W             */
    unsigned short TX0H;                                   /* TX0H             */
    unsigned char  dummy279[2];                            /* Reserved         */
    unsigned short RX0;                                    /* RX0              */
    unsigned char  dummy280[2];                            /* Reserved         */
    unsigned long  CFG0;                                   /* CFG0             */
};
struct __tag342
{                                                          /* Module           */
    unsigned char  SST;                                    /* SST              */
    unsigned char  dummy281[11];                           /* Reserved         */
    unsigned short SSER0;                                  /* SSER0            */
    unsigned char  dummy282[6];                            /* Reserved         */
    unsigned short SSER2;                                  /* SSER2            */
    unsigned char  dummy283[102];                          /* Reserved         */
    unsigned char  HIZCEN0;                                /* HIZCEN0          */
    unsigned char  dummy284[15];                           /* Reserved         */
    unsigned short ADTEN400;                               /* ADTEN400         */
    unsigned char  dummy285[2];                            /* Reserved         */
    unsigned short ADTEN401;                               /* ADTEN401         */
    unsigned char  dummy286[2];                            /* Reserved         */
    unsigned short ADTEN402;                               /* ADTEN402         */
    unsigned char  dummy287[38];                           /* Reserved         */
    unsigned long  REG200;                                 /* REG200           */
    unsigned long  REG201;                                 /* REG201           */
    unsigned long  REG202;                                 /* REG202           */
    unsigned long  REG203;                                 /* REG203           */
    unsigned char  dummy288[24];                           /* Reserved         */
    unsigned long  REG30;                                  /* REG30            */
    unsigned long  REG31;                                  /* REG31            */
};
struct __tag343
{                                                          /* Module           */
    union __tag148 FSGD02PROT0;                            /* FSGD02PROT0      */
    union __tag148 FSGD02PROT1;                            /* FSGD02PROT1      */
    union __tag148 FSGD02PROT2;                            /* FSGD02PROT2      */
    union __tag148 FSGD02PROT3;                            /* FSGD02PROT3      */
    union __tag148 FSGD02PROT4;                            /* FSGD02PROT4      */
    union __tag148 FSGD02PROT5;                            /* FSGD02PROT5      */
    union __tag148 FSGD02PROT6;                            /* FSGD02PROT6      */
    unsigned char  dummy289[4];                            /* Reserved         */
    union __tag148 FSGD02PROT8;                            /* FSGD02PROT8      */
    union __tag148 FSGD02PROT9;                            /* FSGD02PROT9      */
    union __tag148 FSGD02PROT10;                           /* FSGD02PROT10     */
    union __tag148 FSGD02PROT11;                           /* FSGD02PROT11     */
    unsigned char  dummy290[8];                            /* Reserved         */
    union __tag148 FSGD02PROT14;                           /* FSGD02PROT14     */
    union __tag148 FSGD02PROT15;                           /* FSGD02PROT15     */
    union __tag148 ERRSLV02CTL;                            /* ERRSLV02CTL      */
    union __tag148 ERRSLV02STAT;                           /* ERRSLV02STAT     */
    unsigned long  ERRSLV02ADDR;                           /* ERRSLV02ADDR     */
    union __tag154 ERRSLV02TYPE;                           /* ERRSLV02TYPE     */
};
struct __tag344
{                                                          /* Module           */
    union __tag148 FSGD09PROT0;                            /* FSGD09PROT0      */
    union __tag148 FSGD09PROT1;                            /* FSGD09PROT1      */
    unsigned char  dummy291[24];                           /* Reserved         */
    union __tag148 FSGD09PROT8;                            /* FSGD09PROT8      */
    union __tag148 FSGD09PROT9;                            /* FSGD09PROT9      */
    unsigned char  dummy292[24];                           /* Reserved         */
    union __tag148 ERRSLV09CTL;                            /* ERRSLV09CTL      */
    union __tag148 ERRSLV09STAT;                           /* ERRSLV09STAT     */
    unsigned long  ERRSLV09ADDR;                           /* ERRSLV09ADDR     */
    union __tag154 ERRSLV09TYPE;                           /* ERRSLV09TYPE     */
};
struct __tag345
{                                                          /* Module           */
    unsigned short CDR0;                                   /* CDR0             */
    unsigned char  dummy293[2];                            /* Reserved         */
    unsigned short CDR1;                                   /* CDR1             */
    unsigned char  dummy294[2];                            /* Reserved         */
    unsigned short CDR2;                                   /* CDR2             */
    unsigned char  dummy295[2];                            /* Reserved         */
    unsigned short CDR3;                                   /* CDR3             */
    unsigned char  dummy296[2];                            /* Reserved         */
    unsigned short CDR4;                                   /* CDR4             */
    unsigned char  dummy297[2];                            /* Reserved         */
    unsigned short CDR5;                                   /* CDR5             */
    unsigned char  dummy298[2];                            /* Reserved         */
    unsigned short CDR6;                                   /* CDR6             */
    unsigned char  dummy299[2];                            /* Reserved         */
    unsigned short CDR7;                                   /* CDR7             */
    unsigned char  dummy300[2];                            /* Reserved         */
    unsigned short CDR8;                                   /* CDR8             */
    unsigned char  dummy301[2];                            /* Reserved         */
    unsigned short CDR9;                                   /* CDR9             */
    unsigned char  dummy302[2];                            /* Reserved         */
    unsigned short CDR10;                                  /* CDR10            */
    unsigned char  dummy303[2];                            /* Reserved         */
    unsigned short CDR11;                                  /* CDR11            */
    unsigned char  dummy304[2];                            /* Reserved         */
    unsigned short CDR12;                                  /* CDR12            */
    unsigned char  dummy305[2];                            /* Reserved         */
    unsigned short CDR13;                                  /* CDR13            */
    unsigned char  dummy306[2];                            /* Reserved         */
    unsigned short CDR14;                                  /* CDR14            */
    unsigned char  dummy307[2];                            /* Reserved         */
    unsigned short CDR15;                                  /* CDR15            */
    unsigned char  dummy308[2];                            /* Reserved         */
    unsigned short TOL;                                    /* TOL              */
    unsigned char  dummy309[2];                            /* Reserved         */
    unsigned short RDT;                                    /* RDT              */
    unsigned char  dummy310[2];                            /* Reserved         */
    unsigned short RSF;                                    /* RSF              */
    unsigned char  dummy311[2];                            /* Reserved         */
    unsigned short TRO;                                    /* TRO              */
    unsigned char  dummy312[2];                            /* Reserved         */
    unsigned short TME;                                    /* TME              */
    unsigned char  dummy313[2];                            /* Reserved         */
    unsigned short TDL;                                    /* TDL              */
    unsigned char  dummy314[2];                            /* Reserved         */
    unsigned short TO;                                     /* TO               */
    unsigned char  dummy315[2];                            /* Reserved         */
    unsigned short TOE;                                    /* TOE              */
    unsigned char  dummy316[34];                           /* Reserved         */
    unsigned short CNT0;                                   /* CNT0             */
    unsigned char  dummy317[2];                            /* Reserved         */
    unsigned short CNT1;                                   /* CNT1             */
    unsigned char  dummy318[2];                            /* Reserved         */
    unsigned short CNT2;                                   /* CNT2             */
    unsigned char  dummy319[2];                            /* Reserved         */
    unsigned short CNT3;                                   /* CNT3             */
    unsigned char  dummy320[2];                            /* Reserved         */
    unsigned short CNT4;                                   /* CNT4             */
    unsigned char  dummy321[2];                            /* Reserved         */
    unsigned short CNT5;                                   /* CNT5             */
    unsigned char  dummy322[2];                            /* Reserved         */
    unsigned short CNT6;                                   /* CNT6             */
    unsigned char  dummy323[2];                            /* Reserved         */
    unsigned short CNT7;                                   /* CNT7             */
    unsigned char  dummy324[2];                            /* Reserved         */
    unsigned short CNT8;                                   /* CNT8             */
    unsigned char  dummy325[2];                            /* Reserved         */
    unsigned short CNT9;                                   /* CNT9             */
    unsigned char  dummy326[2];                            /* Reserved         */
    unsigned short CNT10;                                  /* CNT10            */
    unsigned char  dummy327[2];                            /* Reserved         */
    unsigned short CNT11;                                  /* CNT11            */
    unsigned char  dummy328[2];                            /* Reserved         */
    unsigned short CNT12;                                  /* CNT12            */
    unsigned char  dummy329[2];                            /* Reserved         */
    unsigned short CNT13;                                  /* CNT13            */
    unsigned char  dummy330[2];                            /* Reserved         */
    unsigned short CNT14;                                  /* CNT14            */
    unsigned char  dummy331[2];                            /* Reserved         */
    unsigned short CNT15;                                  /* CNT15            */
    unsigned char  dummy332[2];                            /* Reserved         */
    unsigned char  CMUR0;                                  /* CMUR0            */
    unsigned char  dummy333[3];                            /* Reserved         */
    unsigned char  CMUR1;                                  /* CMUR1            */
    unsigned char  dummy334[3];                            /* Reserved         */
    unsigned char  CMUR2;                                  /* CMUR2            */
    unsigned char  dummy335[3];                            /* Reserved         */
    unsigned char  CMUR3;                                  /* CMUR3            */
    unsigned char  dummy336[3];                            /* Reserved         */
    unsigned char  CMUR4;                                  /* CMUR4            */
    unsigned char  dummy337[3];                            /* Reserved         */
    unsigned char  CMUR5;                                  /* CMUR5            */
    unsigned char  dummy338[3];                            /* Reserved         */
    unsigned char  CMUR6;                                  /* CMUR6            */
    unsigned char  dummy339[3];                            /* Reserved         */
    unsigned char  CMUR7;                                  /* CMUR7            */
    unsigned char  dummy340[3];                            /* Reserved         */
    unsigned char  CMUR8;                                  /* CMUR8            */
    unsigned char  dummy341[3];                            /* Reserved         */
    unsigned char  CMUR9;                                  /* CMUR9            */
    unsigned char  dummy342[3];                            /* Reserved         */
    unsigned char  CMUR10;                                 /* CMUR10           */
    unsigned char  dummy343[3];                            /* Reserved         */
    unsigned char  CMUR11;                                 /* CMUR11           */
    unsigned char  dummy344[3];                            /* Reserved         */
    unsigned char  CMUR12;                                 /* CMUR12           */
    unsigned char  dummy345[3];                            /* Reserved         */
    unsigned char  CMUR13;                                 /* CMUR13           */
    unsigned char  dummy346[3];                            /* Reserved         */
    unsigned char  CMUR14;                                 /* CMUR14           */
    unsigned char  dummy347[3];                            /* Reserved         */
    unsigned char  CMUR15;                                 /* CMUR15           */
    unsigned char  dummy348[67];                           /* Reserved         */
    unsigned char  CSR0;                                   /* CSR0             */
    unsigned char  dummy349[3];                            /* Reserved         */
    unsigned char  CSR1;                                   /* CSR1             */
    unsigned char  dummy350[3];                            /* Reserved         */
    unsigned char  CSR2;                                   /* CSR2             */
    unsigned char  dummy351[3];                            /* Reserved         */
    unsigned char  CSR3;                                   /* CSR3             */
    unsigned char  dummy352[3];                            /* Reserved         */
    unsigned char  CSR4;                                   /* CSR4             */
    unsigned char  dummy353[3];                            /* Reserved         */
    unsigned char  CSR5;                                   /* CSR5             */
    unsigned char  dummy354[3];                            /* Reserved         */
    unsigned char  CSR6;                                   /* CSR6             */
    unsigned char  dummy355[3];                            /* Reserved         */
    unsigned char  CSR7;                                   /* CSR7             */
    unsigned char  dummy356[3];                            /* Reserved         */
    unsigned char  CSR8;                                   /* CSR8             */
    unsigned char  dummy357[3];                            /* Reserved         */
    unsigned char  CSR9;                                   /* CSR9             */
    unsigned char  dummy358[3];                            /* Reserved         */
    unsigned char  CSR10;                                  /* CSR10            */
    unsigned char  dummy359[3];                            /* Reserved         */
    unsigned char  CSR11;                                  /* CSR11            */
    unsigned char  dummy360[3];                            /* Reserved         */
    unsigned char  CSR12;                                  /* CSR12            */
    unsigned char  dummy361[3];                            /* Reserved         */
    unsigned char  CSR13;                                  /* CSR13            */
    unsigned char  dummy362[3];                            /* Reserved         */
    unsigned char  CSR14;                                  /* CSR14            */
    unsigned char  dummy363[3];                            /* Reserved         */
    unsigned char  CSR15;                                  /* CSR15            */
    unsigned char  dummy364[3];                            /* Reserved         */
    unsigned char  CSC0;                                   /* CSC0             */
    unsigned char  dummy365[3];                            /* Reserved         */
    unsigned char  CSC1;                                   /* CSC1             */
    unsigned char  dummy366[3];                            /* Reserved         */
    unsigned char  CSC2;                                   /* CSC2             */
    unsigned char  dummy367[3];                            /* Reserved         */
    unsigned char  CSC3;                                   /* CSC3             */
    unsigned char  dummy368[3];                            /* Reserved         */
    unsigned char  CSC4;                                   /* CSC4             */
    unsigned char  dummy369[3];                            /* Reserved         */
    unsigned char  CSC5;                                   /* CSC5             */
    unsigned char  dummy370[3];                            /* Reserved         */
    unsigned char  CSC6;                                   /* CSC6             */
    unsigned char  dummy371[3];                            /* Reserved         */
    unsigned char  CSC7;                                   /* CSC7             */
    unsigned char  dummy372[3];                            /* Reserved         */
    unsigned char  CSC8;                                   /* CSC8             */
    unsigned char  dummy373[3];                            /* Reserved         */
    unsigned char  CSC9;                                   /* CSC9             */
    unsigned char  dummy374[3];                            /* Reserved         */
    unsigned char  CSC10;                                  /* CSC10            */
    unsigned char  dummy375[3];                            /* Reserved         */
    unsigned char  CSC11;                                  /* CSC11            */
    unsigned char  dummy376[3];                            /* Reserved         */
    unsigned char  CSC12;                                  /* CSC12            */
    unsigned char  dummy377[3];                            /* Reserved         */
    unsigned char  CSC13;                                  /* CSC13            */
    unsigned char  dummy378[3];                            /* Reserved         */
    unsigned char  CSC14;                                  /* CSC14            */
    unsigned char  dummy379[3];                            /* Reserved         */
    unsigned char  CSC15;                                  /* CSC15            */
    unsigned char  dummy380[3];                            /* Reserved         */
    unsigned short TE;                                     /* TE               */
    unsigned char  dummy381[2];                            /* Reserved         */
    unsigned short TS;                                     /* TS               */
    unsigned char  dummy382[2];                            /* Reserved         */
    unsigned short TT;                                     /* TT               */
    unsigned char  dummy383[54];                           /* Reserved         */
    unsigned short CMOR0;                                  /* CMOR0            */
    unsigned char  dummy384[2];                            /* Reserved         */
    unsigned short CMOR1;                                  /* CMOR1            */
    unsigned char  dummy385[2];                            /* Reserved         */
    unsigned short CMOR2;                                  /* CMOR2            */
    unsigned char  dummy386[2];                            /* Reserved         */
    unsigned short CMOR3;                                  /* CMOR3            */
    unsigned char  dummy387[2];                            /* Reserved         */
    unsigned short CMOR4;                                  /* CMOR4            */
    unsigned char  dummy388[2];                            /* Reserved         */
    unsigned short CMOR5;                                  /* CMOR5            */
    unsigned char  dummy389[2];                            /* Reserved         */
    unsigned short CMOR6;                                  /* CMOR6            */
    unsigned char  dummy390[2];                            /* Reserved         */
    unsigned short CMOR7;                                  /* CMOR7            */
    unsigned char  dummy391[2];                            /* Reserved         */
    unsigned short CMOR8;                                  /* CMOR8            */
    unsigned char  dummy392[2];                            /* Reserved         */
    unsigned short CMOR9;                                  /* CMOR9            */
    unsigned char  dummy393[2];                            /* Reserved         */
    unsigned short CMOR10;                                 /* CMOR10           */
    unsigned char  dummy394[2];                            /* Reserved         */
    unsigned short CMOR11;                                 /* CMOR11           */
    unsigned char  dummy395[2];                            /* Reserved         */
    unsigned short CMOR12;                                 /* CMOR12           */
    unsigned char  dummy396[2];                            /* Reserved         */
    unsigned short CMOR13;                                 /* CMOR13           */
    unsigned char  dummy397[2];                            /* Reserved         */
    unsigned short CMOR14;                                 /* CMOR14           */
    unsigned char  dummy398[2];                            /* Reserved         */
    unsigned short CMOR15;                                 /* CMOR15           */
    unsigned char  dummy399[2];                            /* Reserved         */
    unsigned short TPS;                                    /* TPS              */
    unsigned char  dummy400[2];                            /* Reserved         */
    unsigned char  BRS;                                    /* BRS              */
    unsigned char  dummy401[3];                            /* Reserved         */
    unsigned short TOM;                                    /* TOM              */
    unsigned char  dummy402[2];                            /* Reserved         */
    unsigned short TOC;                                    /* TOC              */
    unsigned char  dummy403[2];                            /* Reserved         */
    unsigned short TDE;                                    /* TDE              */
    unsigned char  dummy404[2];                            /* Reserved         */
    unsigned short TDM;                                    /* TDM              */
    unsigned char  dummy405[2];                            /* Reserved         */
    unsigned short TRE;                                    /* TRE              */
    unsigned char  dummy406[2];                            /* Reserved         */
    unsigned short TRC;                                    /* TRC              */
    unsigned char  dummy407[2];                            /* Reserved         */
    unsigned short RDE;                                    /* RDE              */
    unsigned char  dummy408[2];                            /* Reserved         */
    unsigned short RDM;                                    /* RDM              */
    unsigned char  dummy409[2];                            /* Reserved         */
    unsigned short RDS;                                    /* RDS              */
    unsigned char  dummy410[2];                            /* Reserved         */
    unsigned short RDC;                                    /* RDC              */
    unsigned char  dummy411[34];                           /* Reserved         */
    unsigned char  EMU;                                    /* EMU              */
};
struct __tag346
{                                                          /* Module           */
    unsigned short SELB_TAUD0I;                            /* SELB_TAUD0I      */
};
struct __tag347
{                                                          /* Module           */
    unsigned long  CDR0;                                   /* CDR0             */
    unsigned long  CDR1;                                   /* CDR1             */
    unsigned long  CDR2;                                   /* CDR2             */
    unsigned long  CDR3;                                   /* CDR3             */
    unsigned long  CNT0;                                   /* CNT0             */
    unsigned long  CNT1;                                   /* CNT1             */
    unsigned long  CNT2;                                   /* CNT2             */
    unsigned long  CNT3;                                   /* CNT3             */
    unsigned char  CMUR0;                                  /* CMUR0            */
    unsigned char  dummy412[3];                            /* Reserved         */
    unsigned char  CMUR1;                                  /* CMUR1            */
    unsigned char  dummy413[3];                            /* Reserved         */
    unsigned char  CMUR2;                                  /* CMUR2            */
    unsigned char  dummy414[3];                            /* Reserved         */
    unsigned char  CMUR3;                                  /* CMUR3            */
    unsigned char  dummy415[3];                            /* Reserved         */
    unsigned char  CSR0;                                   /* CSR0             */
    unsigned char  dummy416[3];                            /* Reserved         */
    unsigned char  CSR1;                                   /* CSR1             */
    unsigned char  dummy417[3];                            /* Reserved         */
    unsigned char  CSR2;                                   /* CSR2             */
    unsigned char  dummy418[3];                            /* Reserved         */
    unsigned char  CSR3;                                   /* CSR3             */
    unsigned char  dummy419[3];                            /* Reserved         */
    unsigned char  CSC0;                                   /* CSC0             */
    unsigned char  dummy420[3];                            /* Reserved         */
    unsigned char  CSC1;                                   /* CSC1             */
    unsigned char  dummy421[3];                            /* Reserved         */
    unsigned char  CSC2;                                   /* CSC2             */
    unsigned char  dummy422[3];                            /* Reserved         */
    unsigned char  CSC3;                                   /* CSC3             */
    unsigned char  dummy423[3];                            /* Reserved         */
    unsigned char  TE;                                     /* TE               */
    unsigned char  dummy424[3];                            /* Reserved         */
    unsigned char  TS;                                     /* TS               */
    unsigned char  dummy425[3];                            /* Reserved         */
    unsigned char  TT;                                     /* TT               */
    unsigned char  dummy426[3];                            /* Reserved         */
    unsigned char  TO;                                     /* TO               */
    unsigned char  dummy427[3];                            /* Reserved         */
    unsigned char  TOE;                                    /* TOE              */
    unsigned char  dummy428[3];                            /* Reserved         */
    unsigned char  TOL;                                    /* TOL              */
    unsigned char  dummy429[3];                            /* Reserved         */
    unsigned char  RDT;                                    /* RDT              */
    unsigned char  dummy430[3];                            /* Reserved         */
    unsigned char  RSF;                                    /* RSF              */
    unsigned char  dummy431[19];                           /* Reserved         */
    unsigned short CMOR0;                                  /* CMOR0            */
    unsigned char  dummy432[2];                            /* Reserved         */
    unsigned short CMOR1;                                  /* CMOR1            */
    unsigned char  dummy433[2];                            /* Reserved         */
    unsigned short CMOR2;                                  /* CMOR2            */
    unsigned char  dummy434[2];                            /* Reserved         */
    unsigned short CMOR3;                                  /* CMOR3            */
    unsigned char  dummy435[2];                            /* Reserved         */
    unsigned short TPS;                                    /* TPS              */
    unsigned char  dummy436[2];                            /* Reserved         */
    unsigned char  BRS;                                    /* BRS              */
    unsigned char  dummy437[3];                            /* Reserved         */
    unsigned char  TOM;                                    /* TOM              */
    unsigned char  dummy438[3];                            /* Reserved         */
    unsigned char  TOC;                                    /* TOC              */
    unsigned char  dummy439[3];                            /* Reserved         */
    unsigned char  RDE;                                    /* RDE              */
    unsigned char  dummy440[3];                            /* Reserved         */
    unsigned char  RDM;                                    /* RDM              */
    unsigned char  dummy441[3];                            /* Reserved         */
    unsigned char  EMU;                                    /* EMU              */
};
struct __tag348
{                                                          /* Module           */
    unsigned char  SELB_TAUJ0I;                            /* SELB_TAUJ0I      */
};
struct __tag349
{                                                          /* Module           */
    unsigned char  SELB_TAUJ2I;                            /* SELB_TAUJ2I      */
};
struct __tag350
{                                                          /* Module           */
    unsigned char  CTL;                                    /* CTL              */
    unsigned char  dummy442[3];                            /* Reserved         */
    unsigned char  STR;                                    /* STR              */
    unsigned char  dummy443[3];                            /* Reserved         */
    unsigned char  STC;                                    /* STC              */
    unsigned char  dummy444[3];                            /* Reserved         */
    unsigned char  EMU;                                    /* EMU              */
    unsigned char  dummy445[19];                           /* Reserved         */
    unsigned char  QUE0;                                   /* QUE0             */
    unsigned char  dummy446[3];                            /* Reserved         */
    unsigned char  QUE1;                                   /* QUE1             */
    unsigned char  dummy447[3];                            /* Reserved         */
    unsigned char  QUE2;                                   /* QUE2             */
    unsigned char  dummy448[3];                            /* Reserved         */
    unsigned char  QUE3;                                   /* QUE3             */
    unsigned char  dummy449[3];                            /* Reserved         */
    unsigned char  QUE4;                                   /* QUE4             */
    unsigned char  dummy450[3];                            /* Reserved         */
    unsigned char  QUE5;                                   /* QUE5             */
    unsigned char  dummy451[3];                            /* Reserved         */
    unsigned char  QUE6;                                   /* QUE6             */
    unsigned char  dummy452[3];                            /* Reserved         */
    unsigned char  QUE7;                                   /* QUE7             */
    unsigned char  dummy453[3];                            /* Reserved         */
    union __tag154 PVCR00_01;                              /* PVCR00_01        */
    union __tag154 PVCR02_03;                              /* PVCR02_03        */
    union __tag154 PVCR04_05;                              /* PVCR04_05        */
    union __tag154 PVCR06_07;                              /* PVCR06_07        */
    union __tag154 PVCR08_09;                              /* PVCR08_09        */
    union __tag154 PVCR10_11;                              /* PVCR10_11        */
    union __tag154 PVCR12_13;                              /* PVCR12_13        */
    unsigned char  dummy454[420];                          /* Reserved         */
    unsigned long  PWDDIR00;                               /* PWDDIR00         */
    unsigned long  PWDDIR01;                               /* PWDDIR01         */
    unsigned long  PWDDIR02;                               /* PWDDIR02         */
    unsigned long  PWDDIR03;                               /* PWDDIR03         */
    unsigned long  PWDDIR04;                               /* PWDDIR04         */
    unsigned long  PWDDIR05;                               /* PWDDIR05         */
    unsigned long  PWDDIR06;                               /* PWDDIR06         */
    unsigned long  PWDDIR07;                               /* PWDDIR07         */
    unsigned long  PWDDIR08;                               /* PWDDIR08         */
    unsigned long  PWDDIR09;                               /* PWDDIR09         */
    unsigned long  PWDDIR10;                               /* PWDDIR10         */
    unsigned long  PWDDIR11;                               /* PWDDIR11         */
    unsigned long  PWDDIR12;                               /* PWDDIR12         */
};
struct __tag351
{                                                          /* Module           */
    unsigned short CSDR;                                   /* CSDR             */
    unsigned char  dummy455[2];                            /* Reserved         */
    unsigned short CRDR;                                   /* CRDR             */
    unsigned char  dummy456[2];                            /* Reserved         */
    unsigned short CTDR;                                   /* CTDR             */
    unsigned char  dummy457[2];                            /* Reserved         */
    unsigned char  RDT;                                    /* RDT              */
    unsigned char  dummy458[3];                            /* Reserved         */
    unsigned char  RSF;                                    /* RSF              */
    unsigned char  dummy459[3];                            /* Reserved         */
    unsigned short CNT;                                    /* CNT              */
    unsigned char  dummy460[2];                            /* Reserved         */
    unsigned char  TCR;                                    /* TCR              */
    unsigned char  dummy461[3];                            /* Reserved         */
    unsigned char  TCBR;                                   /* TCBR             */
    unsigned char  dummy462[3];                            /* Reserved         */
    unsigned char  CTL;                                    /* CTL              */
    unsigned char  dummy463[3];                            /* Reserved         */
    unsigned short CSBR;                                   /* CSBR             */
    unsigned char  dummy464[2];                            /* Reserved         */
    unsigned short CRBR;                                   /* CRBR             */
    unsigned char  dummy465[2];                            /* Reserved         */
    unsigned short CTBR;                                   /* CTBR             */
};
struct __tag352
{                                                          /* Module           */
    unsigned short BRS0;                                   /* BRS0             */
    unsigned char  dummy466[2];                            /* Reserved         */
    unsigned short BRS1;                                   /* BRS1             */
    unsigned char  dummy467[2];                            /* Reserved         */
    unsigned short BRS2;                                   /* BRS2             */
    unsigned char  dummy468[2];                            /* Reserved         */
    unsigned short BRS3;                                   /* BRS3             */
    unsigned char  dummy469[2];                            /* Reserved         */
    unsigned char  TE;                                     /* TE               */
    unsigned char  dummy470[3];                            /* Reserved         */
    unsigned char  TS;                                     /* TS               */
    unsigned char  dummy471[3];                            /* Reserved         */
    unsigned char  TT;                                     /* TT               */
    unsigned char  dummy472[3];                            /* Reserved         */
    unsigned char  EMU;                                    /* EMU              */
};
struct __tag353
{                                                          /* Module           */
    unsigned long  A0;                                     /* A0               */
    unsigned char  dummy473[8];                            /* Reserved         */
    unsigned short PWGAPRD;                                /* PWGAPRD          */
    unsigned char  dummy474[2];                            /* Reserved         */
    unsigned long  PWGAPRDSL0;                             /* PWGAPRDSL0       */
};
struct __tag354
{                                                          /* Module           */
    unsigned long  PWGAINTF00;                             /* PWGAINTF00       */
    unsigned long  PWGAINTMSK00;                           /* PWGAINTMSK00     */
    unsigned long  PWGAINTFC00;                            /* PWGAINTFC00      */
};
struct __tag355
{                                                          /* Module           */
    union __tag160 CTL0;                                   /* CTL0             */
    unsigned char  dummy475[3];                            /* Reserved         */
    union __tag161 CTL1;                                   /* CTL1             */
    unsigned char  dummy476[3];                            /* Reserved         */
    union __tag162 CTL2;                                   /* CTL2             */
    unsigned char  dummy477[3];                            /* Reserved         */
    unsigned long  SUBC;                                   /* SUBC             */
    unsigned long  SRBU;                                   /* SRBU             */
    unsigned char  SEC;                                    /* SEC              */
    unsigned char  dummy478[3];                            /* Reserved         */
    unsigned char  MIN;                                    /* MIN              */
    unsigned char  dummy479[3];                            /* Reserved         */
    unsigned char  HOUR;                                   /* HOUR             */
    unsigned char  dummy480[3];                            /* Reserved         */
    unsigned char  WEEK;                                   /* WEEK             */
    unsigned char  dummy481[3];                            /* Reserved         */
    unsigned char  DAY;                                    /* DAY              */
    unsigned char  dummy482[3];                            /* Reserved         */
    unsigned char  MONTH;                                  /* MONTH            */
    unsigned char  dummy483[3];                            /* Reserved         */
    unsigned char  YEAR;                                   /* YEAR             */
    unsigned char  dummy484[3];                            /* Reserved         */
    unsigned long  TIME;                                   /* TIME             */
    unsigned long  CAL;                                    /* CAL              */
    unsigned char  SUBU;                                   /* SUBU             */
    unsigned char  dummy485[3];                            /* Reserved         */
    unsigned long  SCMP;                                   /* SCMP             */
    unsigned char  ALM;                                    /* ALM              */
    unsigned char  dummy486[3];                            /* Reserved         */
    unsigned char  ALH;                                    /* ALH              */
    unsigned char  dummy487[3];                            /* Reserved         */
    unsigned char  ALW;                                    /* ALW              */
    unsigned char  dummy488[3];                            /* Reserved         */
    unsigned char  SECC;                                   /* SECC             */
    unsigned char  dummy489[3];                            /* Reserved         */
    unsigned char  MINC;                                   /* MINC             */
    unsigned char  dummy490[3];                            /* Reserved         */
    unsigned char  HOURC;                                  /* HOURC            */
    unsigned char  dummy491[3];                            /* Reserved         */
    unsigned char  WEEKC;                                  /* WEEKC            */
    unsigned char  dummy492[3];                            /* Reserved         */
    unsigned char  DAYC;                                   /* DAYC             */
    unsigned char  dummy493[3];                            /* Reserved         */
    unsigned char  MONC;                                   /* MONC             */
    unsigned char  dummy494[3];                            /* Reserved         */
    unsigned char  YEARC;                                  /* YEARC            */
    unsigned char  dummy495[3];                            /* Reserved         */
    unsigned long  TIMEC;                                  /* TIMEC            */
    unsigned long  CALC;                                   /* CALC             */
    unsigned char  dummy496[4];                            /* Reserved         */
    union __tag158 EMU;                                    /* EMU              */
};
struct __tag356
{                                                          /* Module           */
    unsigned short CCR0;                                   /* CCR0             */
    unsigned char  dummy497[2];                            /* Reserved         */
    unsigned short CCR1;                                   /* CCR1             */
    unsigned char  dummy498[2];                            /* Reserved         */
    unsigned short CNT;                                    /* CNT              */
    unsigned char  dummy499[2];                            /* Reserved         */
    unsigned char  FLG;                                    /* FLG              */
    unsigned char  dummy500[3];                            /* Reserved         */
    unsigned char  FGC;                                    /* FGC              */
    unsigned char  dummy501[3];                            /* Reserved         */
    unsigned char  TE;                                     /* TE               */
    unsigned char  dummy502[3];                            /* Reserved         */
    unsigned char  TS;                                     /* TS               */
    unsigned char  dummy503[3];                            /* Reserved         */
    unsigned char  TT;                                     /* TT               */
    unsigned char  dummy504[3];                            /* Reserved         */
    unsigned char  IOC0;                                   /* IOC0             */
    unsigned char  dummy505[31];                           /* Reserved         */
    unsigned short CTL;                                    /* CTL              */
    unsigned char  dummy506[2];                            /* Reserved         */
    unsigned char  IOC1;                                   /* IOC1             */
    unsigned char  dummy507[3];                            /* Reserved         */
    unsigned char  EMU;                                    /* EMU              */
};
struct __tag357
{                                                          /* Module           */
    unsigned short FLG;                                    /* FLG              */
    unsigned char  dummy508[2];                            /* Reserved         */
    unsigned char  ACWE;                                   /* ACWE             */
    unsigned char  dummy509[3];                            /* Reserved         */
    unsigned char  ACTS;                                   /* ACTS             */
    unsigned char  dummy510[3];                            /* Reserved         */
    unsigned char  ACTT;                                   /* ACTT             */
    unsigned char  dummy511[7];                            /* Reserved         */
    unsigned char  OPHS;                                   /* OPHS             */
    unsigned char  dummy512[3];                            /* Reserved         */
    unsigned char  OPHT;                                   /* OPHT             */
    unsigned char  dummy513[7];                            /* Reserved         */
    unsigned short CTL0;                                   /* CTL0             */
    unsigned char  dummy514[2];                            /* Reserved         */
    unsigned char  CTL1;                                   /* CTL1             */
    unsigned char  dummy515[3];                            /* Reserved         */
    unsigned char  EMU;                                    /* EMU              */
};
struct __tag358
{                                                          /* Module           */
    unsigned char  WDTE;                                   /* WDTE             */
    unsigned char  dummy516[3];                            /* Reserved         */
    unsigned char  EVAC;                                   /* EVAC             */
    unsigned char  dummy517[3];                            /* Reserved         */
    unsigned char  REF;                                    /* REF              */
    unsigned char  dummy518[3];                            /* Reserved         */
    unsigned char  MD;                                     /* MD               */
};
struct __tag359
{                                                          /* Module           */
    union __tag148 VCR00;                                  /* VCR00            */
    union __tag148 VCR01;                                  /* VCR01            */
    union __tag148 VCR02;                                  /* VCR02            */
    union __tag148 VCR03;                                  /* VCR03            */
    union __tag148 VCR04;                                  /* VCR04            */
    union __tag148 VCR05;                                  /* VCR05            */
    union __tag148 VCR06;                                  /* VCR06            */
    union __tag148 VCR07;                                  /* VCR07            */
    union __tag148 VCR08;                                  /* VCR08            */
    union __tag148 VCR09;                                  /* VCR09            */
    union __tag148 VCR10;                                  /* VCR10            */
    union __tag148 VCR11;                                  /* VCR11            */
    union __tag148 VCR12;                                  /* VCR12            */
    union __tag148 VCR13;                                  /* VCR13            */
    union __tag148 VCR14;                                  /* VCR14            */
    union __tag148 VCR15;                                  /* VCR15            */
    union __tag148 VCR16;                                  /* VCR16            */
    union __tag148 VCR17;                                  /* VCR17            */
    union __tag148 VCR18;                                  /* VCR18            */
    union __tag148 VCR19;                                  /* VCR19            */
    unsigned char  dummy519[52];                           /* Reserved         */
    union __tag148 VCR33;                                  /* VCR33            */
    union __tag148 VCR34;                                  /* VCR34            */
    union __tag148 VCR35;                                  /* VCR35            */
    unsigned char  dummy520[100];                          /* Reserved         */
    union __tag148 PWDVCR;                                 /* PWDVCR           */
    unsigned char  dummy521[8];                            /* Reserved         */
    union __tag154 DR00;                                   /* DR00             */
    union __tag154 DR02;                                   /* DR02             */
    union __tag154 DR04;                                   /* DR04             */
    union __tag154 DR06;                                   /* DR06             */
    union __tag154 DR08;                                   /* DR08             */
    union __tag154 DR10;                                   /* DR10             */
    union __tag154 DR12;                                   /* DR12             */
    union __tag154 DR14;                                   /* DR14             */
    union __tag154 DR16;                                   /* DR16             */
    union __tag154 DR18;                                   /* DR18             */
    unsigned char  dummy522[24];                           /* Reserved         */
    union __tag154 DR32;                                   /* DR32             */
    union __tag154 DR34;                                   /* DR34             */
    unsigned char  dummy523[48];                           /* Reserved         */
    union __tag154 PWDTSNDR;                               /* PWDTSNDR         */
    unsigned char  dummy524[132];                          /* Reserved         */
    unsigned long  DIR00;                                  /* DIR00            */
    unsigned long  DIR01;                                  /* DIR01            */
    unsigned long  DIR02;                                  /* DIR02            */
    unsigned long  DIR03;                                  /* DIR03            */
    unsigned long  DIR04;                                  /* DIR04            */
    unsigned long  DIR05;                                  /* DIR05            */
    unsigned long  DIR06;                                  /* DIR06            */
    unsigned long  DIR07;                                  /* DIR07            */
    unsigned long  DIR08;                                  /* DIR08            */
    unsigned long  DIR09;                                  /* DIR09            */
    unsigned long  DIR10;                                  /* DIR10            */
    unsigned long  DIR11;                                  /* DIR11            */
    unsigned long  DIR12;                                  /* DIR12            */
    unsigned long  DIR13;                                  /* DIR13            */
    unsigned long  DIR14;                                  /* DIR14            */
    unsigned long  DIR15;                                  /* DIR15            */
    unsigned long  DIR16;                                  /* DIR16            */
    unsigned long  DIR17;                                  /* DIR17            */
    unsigned long  DIR18;                                  /* DIR18            */
    unsigned long  DIR19;                                  /* DIR19            */
    unsigned char  dummy525[52];                           /* Reserved         */
    unsigned long  DIR33;                                  /* DIR33            */
    unsigned long  DIR34;                                  /* DIR34            */
    unsigned long  DIR35;                                  /* DIR35            */
    unsigned char  dummy526[100];                          /* Reserved         */
    unsigned long  PWDDIR;                                 /* PWDDIR           */
    unsigned char  dummy527[8];                            /* Reserved         */
    union __tag148 ADHALTR;                                /* ADHALTR          */
    union __tag148 ADCR;                                   /* ADCR             */
    union __tag154 SGSTR;                                  /* SGSTR            */
    union __tag148 MPXCURR;                                /* MPXCURR          */
    unsigned char  dummy528[4];                            /* Reserved         */
    union __tag148 THSMPSTCR;                              /* THSMPSTCR        */
    union __tag148 THCR;                                   /* THCR             */
    union __tag148 THAHLDSTCR;                             /* THAHLDSTCR       */
    union __tag148 THBHLDSTCR;                             /* THBHLDSTCR       */
    union __tag148 THACR;                                  /* THACR            */
    union __tag148 THBCR;                                  /* THBCR            */
    union __tag148 THER;                                   /* THER             */
    union __tag148 THGSR;                                  /* THGSR            */
    union __tag148 SFTCR;                                  /* SFTCR            */
    union __tag154 ULLMTBR0;                               /* ULLMTBR0         */
    union __tag154 ULLMTBR1;                               /* ULLMTBR1         */
    union __tag154 ULLMTBR2;                               /* ULLMTBR2         */
    union __tag148 ECR;                                    /* ECR              */
    union __tag148 ULER;                                   /* ULER             */
    union __tag148 OWER;                                   /* OWER             */
    union __tag148 DGCTL0;                                 /* DGCTL0           */
    union __tag154 DGCTL1;                                 /* DGCTL1           */
    union __tag154 PDCTL1;                                 /* PDCTL1           */
    union __tag148 PDCTL2;                                 /* PDCTL2           */
    unsigned char  dummy529[32];                           /* Reserved         */
    union __tag148 SMPCR;                                  /* SMPCR            */
    unsigned char  dummy530[4];                            /* Reserved         */
    unsigned char  EMU;                                    /* EMU              */
    unsigned char  dummy531[183];                          /* Reserved         */
    union __tag148 SGSTCR1;                                /* SGSTCR1          */
    union __tag148 SGSTPCR1;                               /* SGSTPCR1         */
    union __tag148 SGCR1;                                  /* SGCR1            */
    union __tag148 SGVCSP1;                                /* SGVCSP1          */
    union __tag148 SGVCEP1;                                /* SGVCEP1          */
    union __tag148 SGMCYCR1;                               /* SGMCYCR1         */
    union __tag148 SGSEFCR1;                               /* SGSEFCR1         */
    union __tag154 SGTSEL1;                                /* SGTSEL1          */
    unsigned char  dummy532[32];                           /* Reserved         */
    union __tag148 SGSTCR2;                                /* SGSTCR2          */
    union __tag148 SGSTPCR2;                               /* SGSTPCR2         */
    union __tag148 SGCR2;                                  /* SGCR2            */
    union __tag148 SGVCSP2;                                /* SGVCSP2          */
    union __tag148 SGVCEP2;                                /* SGVCEP2          */
    union __tag148 SGMCYCR2;                               /* SGMCYCR2         */
    union __tag148 SGSEFCR2;                               /* SGSEFCR2         */
    union __tag154 SGTSEL2;                                /* SGTSEL2          */
    unsigned char  dummy533[32];                           /* Reserved         */
    union __tag148 SGSTCR3;                                /* SGSTCR3          */
    union __tag148 SGSTPCR3;                               /* SGSTPCR3         */
    union __tag148 SGCR3;                                  /* SGCR3            */
    union __tag148 SGVCSP3;                                /* SGVCSP3          */
    union __tag148 SGVCEP3;                                /* SGVCEP3          */
    union __tag148 SGMCYCR3;                               /* SGMCYCR3         */
    union __tag148 SGSEFCR3;                               /* SGSEFCR3         */
    union __tag154 SGTSEL3;                                /* SGTSEL3          */
    unsigned char  dummy534[36];                           /* Reserved         */
    union __tag148 PWDSGSTPCR;                             /* PWDSGSTPCR       */
    union __tag148 PWDSGCR;                                /* PWDSGCR          */
    unsigned char  dummy535[12];                           /* Reserved         */
    union __tag148 PWDSGSEFCR;                             /* PWDSGSEFCR       */
    unsigned char  dummy536[36];                           /* Reserved         */
    unsigned long  ULEVCFR0;                               /* ULEVCFR0         */
    unsigned long  ULEVCFR1;                               /* ULEVCFR1         */
    unsigned char  dummy537[28];                           /* Reserved         */
    union __tag154 ULLMTBR3;                               /* ULLMTBR3         */
    union __tag154 ULLMTBR4;                               /* ULLMTBR4         */
    union __tag154 ULLMTBR5;                               /* ULLMTBR5         */
    union __tag154 ULLMTBR6;                               /* ULLMTBR6         */
    union __tag154 ULLMTBR7;                               /* ULLMTBR7         */
    unsigned char  dummy538[120];                          /* Reserved         */
    union __tag154 MPXSTBTSELR0;                           /* MPXSTBTSELR0     */
    unsigned char  dummy539[4];                            /* Reserved         */
    union __tag154 MPXSTBTSELR2;                           /* MPXSTBTSELR2     */
    unsigned char  dummy540[20];                           /* Reserved         */
    union __tag154 MPXSTBTR0;                              /* MPXSTBTR0        */
    union __tag154 MPXSTBTR1;                              /* MPXSTBTR1        */
    union __tag154 MPXSTBTR2;                              /* MPXSTBTR2        */
    union __tag154 MPXSTBTR3;                              /* MPXSTBTR3        */
    union __tag154 MPXSTBTR4;                              /* MPXSTBTR4        */
    union __tag154 MPXSTBTR5;                              /* MPXSTBTR5        */
    union __tag154 MPXSTBTR6;                              /* MPXSTBTR6        */
    union __tag154 MPXSTBTR7;                              /* MPXSTBTR7        */
};
struct __tag360
{                                                          /* Module           */
    unsigned long  CIN;                                    /* CIN              */
    unsigned long  COUT;                                   /* COUT             */
    unsigned char  dummy541[24];                           /* Reserved         */
    unsigned char  CTL;                                    /* CTL              */
};
struct __tag361
{                                                          /* Module           */
    union __tag163 KRM;                                    /* KRM              */
};
struct __tag362
{                                                          /* Module           */
    unsigned long  PROTCMD0;                               /* PROTCMD0         */
    unsigned long  PROTS0;                                 /* PROTS0           */
    unsigned char  dummy542[32760];                        /* Reserved         */
    unsigned long  PROTCMD1;                               /* PROTCMD1         */
    unsigned long  PROTS1;                                 /* PROTS1           */
};
struct __tag363
{                                                          /* Module           */
    unsigned long  PSC;                                    /* PSC              */
    unsigned char  dummy543[12];                           /* Reserved         */
    unsigned long  STPT;                                   /* STPT             */
};
struct __tag364
{                                                          /* Module           */
    unsigned long  WUF0;                                   /* WUF0             */
    unsigned long  WUFMSK0;                                /* WUFMSK0          */
    unsigned long  WUFC0;                                  /* WUFC0            */
};
struct __tag365
{                                                          /* Module           */
    unsigned long  WUF1;                                   /* WUF1             */
    unsigned long  WUFMSK1;                                /* WUFMSK1          */
    unsigned long  WUFC1;                                  /* WUFC1            */
};
struct __tag366
{                                                          /* Module           */
    unsigned long  WUF20;                                  /* WUF20            */
    unsigned long  WUFMSK20;                               /* WUFMSK20         */
    unsigned long  WUFC20;                                 /* WUFC20           */
};
struct __tag367
{                                                          /* Module           */
    unsigned long  RESF;                                   /* RESF             */
    unsigned char  dummy544[4];                            /* Reserved         */
    unsigned long  RESFC;                                  /* RESFC            */
    unsigned char  dummy545[244];                          /* Reserved         */
    unsigned long  RESFR;                                  /* RESFR            */
    unsigned char  dummy546[4];                            /* Reserved         */
    unsigned long  RESFCR;                                 /* RESFCR           */
    unsigned char  dummy547[408];                          /* Reserved         */
    unsigned long  SWRESA;                                 /* SWRESA           */
    unsigned char  dummy548[11256];                        /* Reserved         */
    unsigned long  CYCRBASE;                               /* CYCRBASE         */
};
struct __tag368
{                                                          /* Module           */
    unsigned long  VLVF;                                   /* VLVF             */
    unsigned char  dummy549[4];                            /* Reserved         */
    unsigned long  VLVFC;                                  /* VLVFC            */
    unsigned char  dummy550[116];                          /* Reserved         */
    unsigned long  LVICNT;                                 /* LVICNT           */
    unsigned char  dummy551[9980];                         /* Reserved         */
    unsigned long  CVMF;                                   /* CVMF             */
    unsigned long  CVMDE;                                  /* CVMDE            */
    unsigned char  dummy552[12];                           /* Reserved         */
    unsigned long  CVMDIAG;                                /* CVMDIAG          */
    unsigned char  dummy553[232];                          /* Reserved         */
    unsigned long  PROTCMDCVM;                             /* PROTCMDCVM       */
    unsigned long  PROTSCVM;                               /* PROTSCVM         */
};
struct __tag369
{                                                          /* Module           */
    unsigned long  IOHOLD;                                 /* IOHOLD           */
};
struct __tag370
{                                                          /* Module           */
    unsigned long  ROSCE;                                  /* ROSCE            */
    unsigned long  ROSCS;                                  /* ROSCS            */
    unsigned char  dummy554[16];                           /* Reserved         */
    unsigned long  ROSCSTPM;                               /* ROSCSTPM         */
    unsigned long  ROSCUT;                                 /* ROSCUT           */
    unsigned char  dummy555[224];                          /* Reserved         */
    unsigned long  MOSCE;                                  /* MOSCE            */
    unsigned long  MOSCS;                                  /* MOSCS            */
    unsigned long  MOSCC;                                  /* MOSCC            */
    unsigned long  MOSCST;                                 /* MOSCST           */
    unsigned char  dummy556[8];                            /* Reserved         */
    unsigned long  MOSCSTPM;                               /* MOSCSTPM         */
    unsigned long  MOSCM;                                  /* MOSCM            */
    unsigned char  dummy557[3808];                         /* Reserved         */
    unsigned long  CKSC_AWDTAD_CTL;                        /* CKSC_AWDTAD_CTL  */
    unsigned char  dummy558[4];                            /* Reserved         */
    unsigned long  CKSC_AWDTAD_ACT;                        /* CKSC_AWDTAD_ACT  */
    unsigned char  dummy559[12];                           /* Reserved         */
    unsigned long  CKSC_AWDTAD_STPM;                       /* CKSC_AWDTAD_STPM */
    unsigned char  dummy560[228];                          /* Reserved         */
    unsigned long  CKSC_ATAUJS_CTL;                        /* CKSC_ATAUJS_CTL  */
    unsigned char  dummy561[4];                            /* Reserved         */
    unsigned long  CKSC_ATAUJS_ACT;                        /* CKSC_ATAUJS_ACT  */
    unsigned char  dummy562[244];                          /* Reserved         */
    unsigned long  CKSC_ATAUJD_CTL;                        /* CKSC_ATAUJD_CTL  */
    unsigned char  dummy563[4];                            /* Reserved         */
    unsigned long  CKSC_ATAUJD_ACT;                        /* CKSC_ATAUJD_ACT  */
    unsigned char  dummy564[12];                           /* Reserved         */
    unsigned long  CKSC_ATAUJD_STPM;                       /* CKSC_ATAUJD_STPM */
    unsigned char  dummy565[228];                          /* Reserved         */
    unsigned long  CKSC_ARTCAS_CTL;                        /* CKSC_ARTCAS_CTL  */
    unsigned char  dummy566[4];                            /* Reserved         */
    unsigned long  CKSC_ARTCAS_ACT;                        /* CKSC_ARTCAS_ACT  */
    unsigned char  dummy567[244];                          /* Reserved         */
    unsigned long  CKSC_ARTCAD_CTL;                        /* CKSC_ARTCAD_CTL  */
    unsigned char  dummy568[4];                            /* Reserved         */
    unsigned long  CKSC_ARTCAD_ACT;                        /* CKSC_ARTCAD_ACT  */
    unsigned char  dummy569[12];                           /* Reserved         */
    unsigned long  CKSC_ARTCAD_STPM;                       /* CKSC_ARTCAD_STPM */
    unsigned char  dummy570[228];                          /* Reserved         */
    unsigned long  CKSC_AADCAS_CTL;                        /* CKSC_AADCAS_CTL  */
    unsigned char  dummy571[4];                            /* Reserved         */
    unsigned long  CKSC_AADCAS_ACT;                        /* CKSC_AADCAS_ACT  */
    unsigned char  dummy572[244];                          /* Reserved         */
    unsigned long  CKSC_AADCAD_CTL;                        /* CKSC_AADCAD_CTL  */
    unsigned char  dummy573[4];                            /* Reserved         */
    unsigned long  CKSC_AADCAD_ACT;                        /* CKSC_AADCAD_ACT  */
    unsigned char  dummy574[12];                           /* Reserved         */
    unsigned long  CKSC_AADCAD_STPM;                       /* CKSC_AADCAD_STPM */
    unsigned char  dummy575[228];                          /* Reserved         */
    unsigned long  CKSC_AFOUTS_CTL;                        /* CKSC_AFOUTS_CTL  */
    unsigned char  dummy576[4];                            /* Reserved         */
    unsigned long  CKSC_AFOUTS_ACT;                        /* CKSC_AFOUTS_ACT  */
    unsigned char  dummy577[12];                           /* Reserved         */
    unsigned long  CKSC_AFOUTS_STPM;                       /* CKSC_AFOUTS_STPM */
    unsigned char  dummy578[228];                          /* Reserved         */
    unsigned long  FOUTDIV;                                /* FOUTDIV          */
    unsigned long  FOUTSTAT;                               /* FOUTSTAT         */
    unsigned char  dummy579[26616];                        /* Reserved         */
    unsigned long  PLL1E;                                  /* PLL1E            */
    unsigned long  PLL1S;                                  /* PLL1S            */
    unsigned long  PLL1C;                                  /* PLL1C            */
    unsigned char  dummy580[4084];                         /* Reserved         */
    unsigned long  CKSC_CPUCLKS_CTL;                       /* CKSC_CPUCLKS_CTL */
    unsigned char  dummy581[4];                            /* Reserved         */
    unsigned long  CKSC_CPUCLKS_ACT;                       /* CKSC_CPUCLKS_ACT */
    unsigned char  dummy582[4];                            /* Reserved         */
    unsigned long  CKSC_PPLLCLKS_CTL;                      /* CKSC_PPLLCLKS_CTL */
    unsigned char  dummy583[4];                            /* Reserved         */
    unsigned long  CKSC_PPLLCLKS_ACT;                      /* CKSC_PPLLCLKS_ACT */
    unsigned char  dummy584[228];                          /* Reserved         */
    unsigned long  CKSC_CPUCLKD_CTL;                       /* CKSC_CPUCLKD_CTL */
    unsigned char  dummy585[4];                            /* Reserved         */
    unsigned long  CKSC_CPUCLKD_ACT;                       /* CKSC_CPUCLKD_ACT */
    unsigned char  dummy586[244];                          /* Reserved         */
    unsigned long  CKSC_IPERI1S_CTL;                       /* CKSC_IPERI1S_CTL */
    unsigned char  dummy587[4];                            /* Reserved         */
    unsigned long  CKSC_IPERI1S_ACT;                       /* CKSC_IPERI1S_ACT */
    unsigned char  dummy588[244];                          /* Reserved         */
    unsigned long  CKSC_IPERI2S_CTL;                       /* CKSC_IPERI2S_CTL */
    unsigned char  dummy589[4];                            /* Reserved         */
    unsigned long  CKSC_IPERI2S_ACT;                       /* CKSC_IPERI2S_ACT */
    unsigned char  dummy590[244];                          /* Reserved         */
    unsigned long  CKSC_ILINS_CTL;                         /* CKSC_ILINS_CTL   */
    unsigned char  dummy591[4];                            /* Reserved         */
    unsigned long  CKSC_ILINS_ACT;                         /* CKSC_ILINS_ACT   */
    unsigned char  dummy592[756];                          /* Reserved         */
    unsigned long  CKSC_PLL1IS_CTL;                        /* CKSC_PLL1IS_CTL  */
    unsigned char  dummy593[4];                            /* Reserved         */
    unsigned long  CKSC_PLL1IS_ACT;                        /* CKSC_PLL1IS_ACT  */
    unsigned char  dummy594[244];                          /* Reserved         */
    unsigned long  CKSC_ILIND_CTL;                         /* CKSC_ILIND_CTL   */
    unsigned char  dummy595[4];                            /* Reserved         */
    unsigned long  CKSC_ILIND_ACT;                         /* CKSC_ILIND_ACT   */
    unsigned char  dummy596[12];                           /* Reserved         */
    unsigned long  CKSC_ILIND_STPM;                        /* CKSC_ILIND_STPM  */
    unsigned char  dummy597[228];                          /* Reserved         */
    unsigned long  CKSC_ICANS_CTL;                         /* CKSC_ICANS_CTL   */
    unsigned char  dummy598[4];                            /* Reserved         */
    unsigned long  CKSC_ICANS_ACT;                         /* CKSC_ICANS_ACT   */
    unsigned char  dummy599[12];                           /* Reserved         */
    unsigned long  CKSC_ICANS_STPM;                        /* CKSC_ICANS_STPM  */
    unsigned char  dummy600[228];                          /* Reserved         */
    unsigned long  CKSC_ICANOSCD_CTL;                      /* CKSC_ICANOSCD_CTL */
    unsigned char  dummy601[4];                            /* Reserved         */
    unsigned long  CKSC_ICANOSCD_ACT;                      /* CKSC_ICANOSCD_ACT */
    unsigned char  dummy602[12];                           /* Reserved         */
    unsigned long  CKSC_ICANOSCD_STPM;                     /* CKSC_ICANOSCD_STPM */
    unsigned char  dummy603[228];                          /* Reserved         */
    unsigned long  CKSC_ICSIS_CTL;                         /* CKSC_ICSIS_CTL   */
    unsigned char  dummy604[4];                            /* Reserved         */
    unsigned long  CKSC_ICSIS_ACT;                         /* CKSC_ICSIS_ACT   */
    unsigned char  dummy605[244];                          /* Reserved         */
    unsigned long  CKSC_IIICS_CTL;                         /* CKSC_IIICS_CTL   */
    unsigned char  dummy606[4];                            /* Reserved         */
    unsigned long  CKSC_IIICS_ACT;                         /* CKSC_IIICS_ACT   */
};
struct __tag371
{                                                          /* Module           */
    unsigned long  SCTLR;                                  /* SCTLR            */
    unsigned long  EVFR;                                   /* EVFR             */
    unsigned long  DPSELR0;                                /* DPSELR0          */
    union __tag164 DPSELRM;                                /* DPSELRM          */
    union __tag165 DPSELRH;                                /* DPSELRH          */
    unsigned long  DPDSR0;                                 /* DPDSR0           */
    union __tag166 DPDSRM;                                 /* DPDSRM           */
    union __tag167 DPDSRH;                                 /* DPDSRH           */
    unsigned long  DPDIMR0;                                /* DPDIMR0          */
    unsigned char  DPDIMR1;                                /* DPDIMR1          */
    unsigned char  dummy607[3];                            /* Reserved         */
    unsigned char  DPDIMR2;                                /* DPDIMR2          */
    unsigned char  dummy608[3];                            /* Reserved         */
    unsigned char  DPDIMR3;                                /* DPDIMR3          */
    unsigned char  dummy609[3];                            /* Reserved         */
    unsigned char  DPDIMR4;                                /* DPDIMR4          */
    unsigned char  dummy610[3];                            /* Reserved         */
    unsigned char  DPDIMR5;                                /* DPDIMR5          */
    unsigned char  dummy611[3];                            /* Reserved         */
    unsigned char  DPDIMR6;                                /* DPDIMR6          */
    unsigned char  dummy612[3];                            /* Reserved         */
    unsigned char  DPDIMR7;                                /* DPDIMR7          */
    unsigned char  dummy613[3];                            /* Reserved         */
    unsigned short CNTVAL;                                 /* CNTVAL           */
    unsigned char  dummy614[2];                            /* Reserved         */
    unsigned char  SOSTR;                                  /* SOSTR            */
};
struct __tag372
{                                                          /* Module           */
    unsigned long  WUF_ISO0;                               /* WUF_ISO0         */
    unsigned long  WUFMSK_ISO0;                            /* WUFMSK_ISO0      */
    unsigned long  WUFC_ISO0;                              /* WUFC_ISO0        */
};
struct __tag373
{                                                          /* Module           */
    unsigned char  CTL0;                                   /* CTL0             */
    unsigned char  dummy615[7];                            /* Reserved         */
    unsigned short CMPL;                                   /* CMPL             */
    unsigned char  dummy616[2];                            /* Reserved         */
    unsigned short CMPH;                                   /* CMPH             */
    unsigned char  dummy617[2];                            /* Reserved         */
    unsigned char  PCMD;                                   /* PCMD             */
    unsigned char  dummy618[3];                            /* Reserved         */
    unsigned char  PS;                                     /* PS               */
    unsigned char  dummy619[3];                            /* Reserved         */
    unsigned char  EMU0;                                   /* EMU0             */
};
struct __tag374
{                                                          /* Module           */
    unsigned long  TEST;                                   /* TEST             */
    unsigned long  TESTS;                                  /* TESTS            */
    unsigned char  dummy620[248];                          /* Reserved         */
    unsigned long  PROTCMDCLMA;                            /* PROTCMDCLMA      */
    unsigned long  PROTSCLMA;                              /* PROTSCLMA        */
};
struct __tag375
{                                                          /* Module           */
    union __tag148 FSGD06PROT0;                            /* FSGD06PROT0      */
    union __tag148 FSGD06PROT1;                            /* FSGD06PROT1      */
    unsigned char  dummy621[8];                            /* Reserved         */
    union __tag148 FSGD06PROT4;                            /* FSGD06PROT4      */
    union __tag148 FSGD06PROT5;                            /* FSGD06PROT5      */
    union __tag148 FSGD06PROT6;                            /* FSGD06PROT6      */
    union __tag148 FSGD06PROT7;                            /* FSGD06PROT7      */
    union __tag148 FSGD06PROT8;                            /* FSGD06PROT8      */
    unsigned char  dummy622[28];                           /* Reserved         */
    union __tag148 ERRSLV06CTL;                            /* ERRSLV06CTL      */
    union __tag148 ERRSLV06STAT;                           /* ERRSLV06STAT     */
    unsigned long  ERRSLV06ADDR;                           /* ERRSLV06ADDR     */
    union __tag154 ERRSLV06TYPE;                           /* ERRSLV06TYPE     */
};
struct __tag376
{                                                          /* Module           */
    union __tag148 FSGD03PROT0;                            /* FSGD03PROT0      */
    unsigned char  dummy623[28];                           /* Reserved         */
    union __tag148 FSGD03PROT8;                            /* FSGD03PROT8      */
    unsigned char  dummy624[28];                           /* Reserved         */
    union __tag148 ERRSLV03CTL;                            /* ERRSLV03CTL      */
    union __tag148 ERRSLV03STAT;                           /* ERRSLV03STAT     */
    unsigned long  ERRSLV03ADDR;                           /* ERRSLV03ADDR     */
    union __tag154 ERRSLV03TYPE;                           /* ERRSLV03TYPE     */
};
struct __tag377
{                                                          /* Module           */
    union __tag148 FSGD04PROT0;                            /* FSGD04PROT0      */
    unsigned char  dummy625[12];                           /* Reserved         */
    union __tag148 FSGD04PROT4;                            /* FSGD04PROT4      */
    unsigned char  dummy626[12];                           /* Reserved         */
    union __tag148 FSGD04PROT8;                            /* FSGD04PROT8      */
    union __tag148 FSGD04PROT9;                            /* FSGD04PROT9      */
    union __tag148 FSGD04PROT10;                           /* FSGD04PROT10     */
    unsigned char  dummy627[20];                           /* Reserved         */
    union __tag148 ERRSLV04CTL;                            /* ERRSLV04CTL      */
    union __tag148 ERRSLV04STAT;                           /* ERRSLV04STAT     */
    unsigned long  ERRSLV04ADDR;                           /* ERRSLV04ADDR     */
    union __tag154 ERRSLV04TYPE;                           /* ERRSLV04TYPE     */
};
struct __tag378
{                                                          /* Module           */
    union __tag148 FSGD05PROT0;                            /* FSGD05PROT0      */
    union __tag148 FSGD05PROT1;                            /* FSGD05PROT1      */
    unsigned char  dummy628[24];                           /* Reserved         */
    union __tag148 FSGD05PROT8;                            /* FSGD05PROT8      */
    union __tag148 FSGD05PROT9;                            /* FSGD05PROT9      */
    unsigned char  dummy629[24];                           /* Reserved         */
    union __tag148 ERRSLV05CTL;                            /* ERRSLV05CTL      */
    union __tag148 ERRSLV05STAT;                           /* ERRSLV05STAT     */
    unsigned long  ERRSLV05ADDR;                           /* ERRSLV05ADDR     */
    union __tag154 ERRSLV05TYPE;                           /* ERRSLV05TYPE     */
};
struct __tag379
{                                                          /* Module           */
    unsigned char  dummy630[2];                            /* Reserved         */
    union __tag157 ECRUM;                                  /* ECRUM            */
    unsigned char  dummy631[4];                            /* Reserved         */
    union __tag148 ADRUM;                                  /* ADRUM            */
    unsigned char  dummy632[1];                            /* Reserved         */
    unsigned char  ENUM;                                   /* ENUM             */
    unsigned char  dummy633[18];                           /* Reserved         */
    unsigned char  PMTUM0;                                 /* PMTUM0           */
    unsigned char  dummy634[1];                            /* Reserved         */
    unsigned char  PMTUM2;                                 /* PMTUM2           */
    unsigned char  PMTUM3;                                 /* PMTUM3           */
    unsigned char  PMTUM4;                                 /* PMTUM4           */
};
struct __tag380
{                                                          /* Module           */
    union __tag148 SP;                                     /* SP               */
    unsigned char  dummy635[112];                          /* Reserved         */
    union __tag148 G0MK;                                   /* G0MK             */
    union __tag148 G0BA;                                   /* G0BA             */
    unsigned char  dummy636[8];                            /* Reserved         */
    union __tag148 G1MK;                                   /* G1MK             */
    union __tag148 G1BA;                                   /* G1BA             */
    unsigned char  dummy637[8];                            /* Reserved         */
    union __tag148 G2MK;                                   /* G2MK             */
    union __tag148 G2BA;                                   /* G2BA             */
    unsigned char  dummy638[8];                            /* Reserved         */
    union __tag148 G3MK;                                   /* G3MK             */
    union __tag148 G3BA;                                   /* G3BA             */
};
struct __tag381
{                                                          /* Module           */
    unsigned short CONT;                                   /* CONT             */
    unsigned short FLAG;                                   /* FLAG             */
    unsigned char  dummy639[4];                            /* Reserved         */
    unsigned long  ADDR;                                   /* ADDR             */
};
struct __tag382
{                                                          /* Module           */
    union __tag168 ICTAUD0I0;                              /* ICTAUD0I0        */
    union __tag169 ICTAUD0I2;                              /* ICTAUD0I2        */
    union __tag170 ICTAUD0I4;                              /* ICTAUD0I4        */
    union __tag171 ICTAUD0I6;                              /* ICTAUD0I6        */
    union __tag172 ICTAUD0I8;                              /* ICTAUD0I8        */
    union __tag173 ICTAUD0I10;                             /* ICTAUD0I10       */
    union __tag174 ICTAUD0I12;                             /* ICTAUD0I12       */
    union __tag175 ICTAUD0I14;                             /* ICTAUD0I14       */
    union __tag176 ICTAPA0IPEK0;                           /* ICTAPA0IPEK0     */
    union __tag177 ICTAPA0IVLY0;                           /* ICTAPA0IVLY0     */
    union __tag178 ICADCA0I0;                              /* ICADCA0I0        */
    union __tag179 ICADCA0I1;                              /* ICADCA0I1        */
    union __tag180 ICADCA0I2;                              /* ICADCA0I2        */
    union __tag181 ICDCUTDI;                               /* ICDCUTDI         */
    union __tag182 ICRCANGERR0;                            /* ICRCANGERR0      */
    union __tag183 ICRCANGRECC0;                           /* ICRCANGRECC0     */
    union __tag184 ICRCAN0ERR;                             /* ICRCAN0ERR       */
    union __tag185 ICRCAN0REC;                             /* ICRCAN0REC       */
    union __tag186 ICRCAN0TRX;                             /* ICRCAN0TRX       */
    union __tag187 ICCSIG0IC;                              /* ICCSIG0IC        */
    union __tag188 ICCSIG0IR;                              /* ICCSIG0IR        */
    union __tag189 ICCSIH0IC;                              /* ICCSIH0IC        */
    union __tag190 ICCSIH0IR;                              /* ICCSIH0IR        */
    union __tag191 ICCSIH0IRE;                             /* ICCSIH0IRE       */
    unsigned char  dummy640[56];                           /* Reserved         */
    union __tag192 FNC;                                    /* FNC              */
    union __tag193 FIC;                                    /* FIC              */
    unsigned char  dummy641[116];                          /* Reserved         */
    union __tag194 IMR0;                                   /* IMR0             */
};
struct __tag383
{                                                          /* Module           */
    unsigned long  DMACTL;                                 /* DMACTL           */
    unsigned char  dummy642[28];                           /* Reserved         */
    unsigned long  DMACER;                                 /* DMACER           */
    unsigned char  dummy643[12];                           /* Reserved         */
    unsigned long  DM0CMV;                                 /* DM0CMV           */
    unsigned long  DM1CMV;                                 /* DM1CMV           */
    unsigned char  dummy644[4];                            /* Reserved         */
    unsigned long  CMVC;                                   /* CMVC             */
    unsigned char  dummy645[192];                          /* Reserved         */
    unsigned long  DM00CM;                                 /* DM00CM           */
    unsigned long  DM01CM;                                 /* DM01CM           */
    unsigned long  DM02CM;                                 /* DM02CM           */
    unsigned long  DM03CM;                                 /* DM03CM           */
    unsigned long  DM04CM;                                 /* DM04CM           */
    unsigned long  DM05CM;                                 /* DM05CM           */
    unsigned long  DM06CM;                                 /* DM06CM           */
    unsigned long  DM07CM;                                 /* DM07CM           */
    unsigned long  DM10CM;                                 /* DM10CM           */
    unsigned long  DM11CM;                                 /* DM11CM           */
    unsigned long  DM12CM;                                 /* DM12CM           */
    unsigned long  DM13CM;                                 /* DM13CM           */
    unsigned long  DM14CM;                                 /* DM14CM           */
    unsigned long  DM15CM;                                 /* DM15CM           */
    unsigned long  DM16CM;                                 /* DM16CM           */
    unsigned long  DM17CM;                                 /* DM17CM           */
    unsigned char  dummy646[704];                          /* Reserved         */
    unsigned long  DSA0;                                   /* DSA0             */
    unsigned long  DDA0;                                   /* DDA0             */
    unsigned long  DTC0;                                   /* DTC0             */
    unsigned long  DTCT0;                                  /* DTCT0            */
    unsigned long  DRSA0;                                  /* DRSA0            */
    unsigned long  DRDA0;                                  /* DRDA0            */
    unsigned long  DRTC0;                                  /* DRTC0            */
    unsigned char  dummy647[4];                            /* Reserved         */
    unsigned long  DCEN0;                                  /* DCEN0            */
    unsigned long  DCST0;                                  /* DCST0            */
    unsigned long  DCSTS0;                                 /* DCSTS0           */
    unsigned long  DCSTC0;                                 /* DCSTC0           */
    unsigned long  DTFR0;                                  /* DTFR0            */
    unsigned long  DTFRRQ0;                                /* DTFRRQ0          */
    unsigned long  DTFRRQC0;                               /* DTFRRQC0         */
    unsigned char  dummy648[4];                            /* Reserved         */
    unsigned long  DSA1;                                   /* DSA1             */
    unsigned long  DDA1;                                   /* DDA1             */
    unsigned long  DTC1;                                   /* DTC1             */
    unsigned long  DTCT1;                                  /* DTCT1            */
    unsigned long  DRSA1;                                  /* DRSA1            */
    unsigned long  DRDA1;                                  /* DRDA1            */
    unsigned long  DRTC1;                                  /* DRTC1            */
    unsigned char  dummy649[4];                            /* Reserved         */
    unsigned long  DCEN1;                                  /* DCEN1            */
    unsigned long  DCST1;                                  /* DCST1            */
    unsigned long  DCSTS1;                                 /* DCSTS1           */
    unsigned long  DCSTC1;                                 /* DCSTC1           */
    unsigned long  DTFR1;                                  /* DTFR1            */
    unsigned long  DTFRRQ1;                                /* DTFRRQ1          */
    unsigned long  DTFRRQC1;                               /* DTFRRQC1         */
    unsigned char  dummy650[4];                            /* Reserved         */
    unsigned long  DSA2;                                   /* DSA2             */
    unsigned long  DDA2;                                   /* DDA2             */
    unsigned long  DTC2;                                   /* DTC2             */
    unsigned long  DTCT2;                                  /* DTCT2            */
    unsigned long  DRSA2;                                  /* DRSA2            */
    unsigned long  DRDA2;                                  /* DRDA2            */
    unsigned long  DRTC2;                                  /* DRTC2            */
    unsigned char  dummy651[4];                            /* Reserved         */
    unsigned long  DCEN2;                                  /* DCEN2            */
    unsigned long  DCST2;                                  /* DCST2            */
    unsigned long  DCSTS2;                                 /* DCSTS2           */
    unsigned long  DCSTC2;                                 /* DCSTC2           */
    unsigned long  DTFR2;                                  /* DTFR2            */
    unsigned long  DTFRRQ2;                                /* DTFRRQ2          */
    unsigned long  DTFRRQC2;                               /* DTFRRQC2         */
    unsigned char  dummy652[4];                            /* Reserved         */
    unsigned long  DSA3;                                   /* DSA3             */
    unsigned long  DDA3;                                   /* DDA3             */
    unsigned long  DTC3;                                   /* DTC3             */
    unsigned long  DTCT3;                                  /* DTCT3            */
    unsigned long  DRSA3;                                  /* DRSA3            */
    unsigned long  DRDA3;                                  /* DRDA3            */
    unsigned long  DRTC3;                                  /* DRTC3            */
    unsigned char  dummy653[4];                            /* Reserved         */
    unsigned long  DCEN3;                                  /* DCEN3            */
    unsigned long  DCST3;                                  /* DCST3            */
    unsigned long  DCSTS3;                                 /* DCSTS3           */
    unsigned long  DCSTC3;                                 /* DCSTC3           */
    unsigned long  DTFR3;                                  /* DTFR3            */
    unsigned long  DTFRRQ3;                                /* DTFRRQ3          */
    unsigned long  DTFRRQC3;                               /* DTFRRQC3         */
    unsigned char  dummy654[4];                            /* Reserved         */
    unsigned long  DSA4;                                   /* DSA4             */
    unsigned long  DDA4;                                   /* DDA4             */
    unsigned long  DTC4;                                   /* DTC4             */
    unsigned long  DTCT4;                                  /* DTCT4            */
    unsigned long  DRSA4;                                  /* DRSA4            */
    unsigned long  DRDA4;                                  /* DRDA4            */
    unsigned long  DRTC4;                                  /* DRTC4            */
    unsigned char  dummy655[4];                            /* Reserved         */
    unsigned long  DCEN4;                                  /* DCEN4            */
    unsigned long  DCST4;                                  /* DCST4            */
    unsigned long  DCSTS4;                                 /* DCSTS4           */
    unsigned long  DCSTC4;                                 /* DCSTC4           */
    unsigned long  DTFR4;                                  /* DTFR4            */
    unsigned long  DTFRRQ4;                                /* DTFRRQ4          */
    unsigned long  DTFRRQC4;                               /* DTFRRQC4         */
    unsigned char  dummy656[4];                            /* Reserved         */
    unsigned long  DSA5;                                   /* DSA5             */
    unsigned long  DDA5;                                   /* DDA5             */
    unsigned long  DTC5;                                   /* DTC5             */
    unsigned long  DTCT5;                                  /* DTCT5            */
    unsigned long  DRSA5;                                  /* DRSA5            */
    unsigned long  DRDA5;                                  /* DRDA5            */
    unsigned long  DRTC5;                                  /* DRTC5            */
    unsigned char  dummy657[4];                            /* Reserved         */
    unsigned long  DCEN5;                                  /* DCEN5            */
    unsigned long  DCST5;                                  /* DCST5            */
    unsigned long  DCSTS5;                                 /* DCSTS5           */
    unsigned long  DCSTC5;                                 /* DCSTC5           */
    unsigned long  DTFR5;                                  /* DTFR5            */
    unsigned long  DTFRRQ5;                                /* DTFRRQ5          */
    unsigned long  DTFRRQC5;                               /* DTFRRQC5         */
    unsigned char  dummy658[4];                            /* Reserved         */
    unsigned long  DSA6;                                   /* DSA6             */
    unsigned long  DDA6;                                   /* DDA6             */
    unsigned long  DTC6;                                   /* DTC6             */
    unsigned long  DTCT6;                                  /* DTCT6            */
    unsigned long  DRSA6;                                  /* DRSA6            */
    unsigned long  DRDA6;                                  /* DRDA6            */
    unsigned long  DRTC6;                                  /* DRTC6            */
    unsigned char  dummy659[4];                            /* Reserved         */
    unsigned long  DCEN6;                                  /* DCEN6            */
    unsigned long  DCST6;                                  /* DCST6            */
    unsigned long  DCSTS6;                                 /* DCSTS6           */
    unsigned long  DCSTC6;                                 /* DCSTC6           */
    unsigned long  DTFR6;                                  /* DTFR6            */
    unsigned long  DTFRRQ6;                                /* DTFRRQ6          */
    unsigned long  DTFRRQC6;                               /* DTFRRQC6         */
    unsigned char  dummy660[4];                            /* Reserved         */
    unsigned long  DSA7;                                   /* DSA7             */
    unsigned long  DDA7;                                   /* DDA7             */
    unsigned long  DTC7;                                   /* DTC7             */
    unsigned long  DTCT7;                                  /* DTCT7            */
    unsigned long  DRSA7;                                  /* DRSA7            */
    unsigned long  DRDA7;                                  /* DRDA7            */
    unsigned long  DRTC7;                                  /* DRTC7            */
    unsigned char  dummy661[4];                            /* Reserved         */
    unsigned long  DCEN7;                                  /* DCEN7            */
    unsigned long  DCST7;                                  /* DCST7            */
    unsigned long  DCSTS7;                                 /* DCSTS7           */
    unsigned long  DCSTC7;                                 /* DCSTC7           */
    unsigned long  DTFR7;                                  /* DTFR7            */
    unsigned long  DTFRRQ7;                                /* DTFRRQ7          */
    unsigned long  DTFRRQC7;                               /* DTFRRQC7         */
    unsigned char  dummy662[4];                            /* Reserved         */
    unsigned long  DSA8;                                   /* DSA8             */
    unsigned long  DDA8;                                   /* DDA8             */
    unsigned long  DTC8;                                   /* DTC8             */
    unsigned long  DTCT8;                                  /* DTCT8            */
    unsigned long  DRSA8;                                  /* DRSA8            */
    unsigned long  DRDA8;                                  /* DRDA8            */
    unsigned long  DRTC8;                                  /* DRTC8            */
    unsigned char  dummy663[4];                            /* Reserved         */
    unsigned long  DCEN8;                                  /* DCEN8            */
    unsigned long  DCST8;                                  /* DCST8            */
    unsigned long  DCSTS8;                                 /* DCSTS8           */
    unsigned long  DCSTC8;                                 /* DCSTC8           */
    unsigned long  DTFR8;                                  /* DTFR8            */
    unsigned long  DTFRRQ8;                                /* DTFRRQ8          */
    unsigned long  DTFRRQC8;                               /* DTFRRQC8         */
    unsigned char  dummy664[4];                            /* Reserved         */
    unsigned long  DSA9;                                   /* DSA9             */
    unsigned long  DDA9;                                   /* DDA9             */
    unsigned long  DTC9;                                   /* DTC9             */
    unsigned long  DTCT9;                                  /* DTCT9            */
    unsigned long  DRSA9;                                  /* DRSA9            */
    unsigned long  DRDA9;                                  /* DRDA9            */
    unsigned long  DRTC9;                                  /* DRTC9            */
    unsigned char  dummy665[4];                            /* Reserved         */
    unsigned long  DCEN9;                                  /* DCEN9            */
    unsigned long  DCST9;                                  /* DCST9            */
    unsigned long  DCSTS9;                                 /* DCSTS9           */
    unsigned long  DCSTC9;                                 /* DCSTC9           */
    unsigned long  DTFR9;                                  /* DTFR9            */
    unsigned long  DTFRRQ9;                                /* DTFRRQ9          */
    unsigned long  DTFRRQC9;                               /* DTFRRQC9         */
    unsigned char  dummy666[4];                            /* Reserved         */
    unsigned long  DSA10;                                  /* DSA10            */
    unsigned long  DDA10;                                  /* DDA10            */
    unsigned long  DTC10;                                  /* DTC10            */
    unsigned long  DTCT10;                                 /* DTCT10           */
    unsigned long  DRSA10;                                 /* DRSA10           */
    unsigned long  DRDA10;                                 /* DRDA10           */
    unsigned long  DRTC10;                                 /* DRTC10           */
    unsigned char  dummy667[4];                            /* Reserved         */
    unsigned long  DCEN10;                                 /* DCEN10           */
    unsigned long  DCST10;                                 /* DCST10           */
    unsigned long  DCSTS10;                                /* DCSTS10          */
    unsigned long  DCSTC10;                                /* DCSTC10          */
    unsigned long  DTFR10;                                 /* DTFR10           */
    unsigned long  DTFRRQ10;                               /* DTFRRQ10         */
    unsigned long  DTFRRQC10;                              /* DTFRRQC10        */
    unsigned char  dummy668[4];                            /* Reserved         */
    unsigned long  DSA11;                                  /* DSA11            */
    unsigned long  DDA11;                                  /* DDA11            */
    unsigned long  DTC11;                                  /* DTC11            */
    unsigned long  DTCT11;                                 /* DTCT11           */
    unsigned long  DRSA11;                                 /* DRSA11           */
    unsigned long  DRDA11;                                 /* DRDA11           */
    unsigned long  DRTC11;                                 /* DRTC11           */
    unsigned char  dummy669[4];                            /* Reserved         */
    unsigned long  DCEN11;                                 /* DCEN11           */
    unsigned long  DCST11;                                 /* DCST11           */
    unsigned long  DCSTS11;                                /* DCSTS11          */
    unsigned long  DCSTC11;                                /* DCSTC11          */
    unsigned long  DTFR11;                                 /* DTFR11           */
    unsigned long  DTFRRQ11;                               /* DTFRRQ11         */
    unsigned long  DTFRRQC11;                              /* DTFRRQC11        */
    unsigned char  dummy670[4];                            /* Reserved         */
    unsigned long  DSA12;                                  /* DSA12            */
    unsigned long  DDA12;                                  /* DDA12            */
    unsigned long  DTC12;                                  /* DTC12            */
    unsigned long  DTCT12;                                 /* DTCT12           */
    unsigned long  DRSA12;                                 /* DRSA12           */
    unsigned long  DRDA12;                                 /* DRDA12           */
    unsigned long  DRTC12;                                 /* DRTC12           */
    unsigned char  dummy671[4];                            /* Reserved         */
    unsigned long  DCEN12;                                 /* DCEN12           */
    unsigned long  DCST12;                                 /* DCST12           */
    unsigned long  DCSTS12;                                /* DCSTS12          */
    unsigned long  DCSTC12;                                /* DCSTC12          */
    unsigned long  DTFR12;                                 /* DTFR12           */
    unsigned long  DTFRRQ12;                               /* DTFRRQ12         */
    unsigned long  DTFRRQC12;                              /* DTFRRQC12        */
    unsigned char  dummy672[4];                            /* Reserved         */
    unsigned long  DSA13;                                  /* DSA13            */
    unsigned long  DDA13;                                  /* DDA13            */
    unsigned long  DTC13;                                  /* DTC13            */
    unsigned long  DTCT13;                                 /* DTCT13           */
    unsigned long  DRSA13;                                 /* DRSA13           */
    unsigned long  DRDA13;                                 /* DRDA13           */
    unsigned long  DRTC13;                                 /* DRTC13           */
    unsigned char  dummy673[4];                            /* Reserved         */
    unsigned long  DCEN13;                                 /* DCEN13           */
    unsigned long  DCST13;                                 /* DCST13           */
    unsigned long  DCSTS13;                                /* DCSTS13          */
    unsigned long  DCSTC13;                                /* DCSTC13          */
    unsigned long  DTFR13;                                 /* DTFR13           */
    unsigned long  DTFRRQ13;                               /* DTFRRQ13         */
    unsigned long  DTFRRQC13;                              /* DTFRRQC13        */
    unsigned char  dummy674[4];                            /* Reserved         */
    unsigned long  DSA14;                                  /* DSA14            */
    unsigned long  DDA14;                                  /* DDA14            */
    unsigned long  DTC14;                                  /* DTC14            */
    unsigned long  DTCT14;                                 /* DTCT14           */
    unsigned long  DRSA14;                                 /* DRSA14           */
    unsigned long  DRDA14;                                 /* DRDA14           */
    unsigned long  DRTC14;                                 /* DRTC14           */
    unsigned char  dummy675[4];                            /* Reserved         */
    unsigned long  DCEN14;                                 /* DCEN14           */
    unsigned long  DCST14;                                 /* DCST14           */
    unsigned long  DCSTS14;                                /* DCSTS14          */
    unsigned long  DCSTC14;                                /* DCSTC14          */
    unsigned long  DTFR14;                                 /* DTFR14           */
    unsigned long  DTFRRQ14;                               /* DTFRRQ14         */
    unsigned long  DTFRRQC14;                              /* DTFRRQC14        */
    unsigned char  dummy676[4];                            /* Reserved         */
    unsigned long  DSA15;                                  /* DSA15            */
    unsigned long  DDA15;                                  /* DDA15            */
    unsigned long  DTC15;                                  /* DTC15            */
    unsigned long  DTCT15;                                 /* DTCT15           */
    unsigned long  DRSA15;                                 /* DRSA15           */
    unsigned long  DRDA15;                                 /* DRDA15           */
    unsigned long  DRTC15;                                 /* DRTC15           */
    unsigned char  dummy677[4];                            /* Reserved         */
    unsigned long  DCEN15;                                 /* DCEN15           */
    unsigned long  DCST15;                                 /* DCST15           */
    unsigned long  DCSTS15;                                /* DCSTS15          */
    unsigned long  DCSTC15;                                /* DCSTC15          */
    unsigned long  DTFR15;                                 /* DTFR15           */
    unsigned long  DTFRRQ15;                               /* DTFRRQ15         */
    unsigned long  DTFRRQC15;                              /* DTFRRQC15        */
};
struct __tag384
{                                                          /* Module           */
    union __tag195 ICADCA0I2_2;                            /* ICADCA0I2_2      */
    union __tag196 ICRLIN30;                               /* ICRLIN30         */
    union __tag197 ICRLIN30UR0;                            /* ICRLIN30UR0      */
    union __tag198 ICRLIN30UR1;                            /* ICRLIN30UR1      */
    union __tag199 ICRLIN30UR2;                            /* ICRLIN30UR2      */
    union __tag200 ICP0;                                   /* ICP0             */
    union __tag201 ICP1;                                   /* ICP1             */
    union __tag202 ICP2;                                   /* ICP2             */
    union __tag203 ICWDTA0;                                /* ICWDTA0          */
    union __tag204 ICWDTA1;                                /* ICWDTA1          */
    unsigned char  dummy678[2];                            /* Reserved         */
    union __tag205 ICP3;                                   /* ICP3             */
    union __tag206 ICP4;                                   /* ICP4             */
    union __tag207 ICP5;                                   /* ICP5             */
    union __tag208 ICP10;                                  /* ICP10            */
    union __tag209 ICP11;                                  /* ICP11            */
    union __tag210 ICTAUD0I1;                              /* ICTAUD0I1        */
    union __tag211 ICTAUD0I3;                              /* ICTAUD0I3        */
    union __tag212 ICTAUD0I5;                              /* ICTAUD0I5        */
    union __tag213 ICTAUD0I7;                              /* ICTAUD0I7        */
    union __tag214 ICTAUD0I9;                              /* ICTAUD0I9        */
    union __tag215 ICTAUD0I11;                             /* ICTAUD0I11       */
    union __tag216 ICTAUD0I13;                             /* ICTAUD0I13       */
    union __tag217 ICTAUD0I15;                             /* ICTAUD0I15       */
    union __tag218 ICADCA0ERR;                             /* ICADCA0ERR       */
    union __tag219 ICCSIG0IRE;                             /* ICCSIG0IRE       */
    union __tag220 ICRLIN20;                               /* ICRLIN20         */
    union __tag221 ICRLIN21;                               /* ICRLIN21         */
    union __tag222 ICDMA0;                                 /* ICDMA0           */
    union __tag223 ICDMA1;                                 /* ICDMA1           */
    union __tag224 ICDMA2;                                 /* ICDMA2           */
    union __tag225 ICDMA3;                                 /* ICDMA3           */
    union __tag226 ICDMA4;                                 /* ICDMA4           */
    union __tag227 ICDMA5;                                 /* ICDMA5           */
    union __tag228 ICDMA6;                                 /* ICDMA6           */
    union __tag229 ICDMA7;                                 /* ICDMA7           */
    union __tag230 ICDMA8;                                 /* ICDMA8           */
    union __tag231 ICDMA9;                                 /* ICDMA9           */
    union __tag232 ICDMA10;                                /* ICDMA10          */
    union __tag233 ICDMA11;                                /* ICDMA11          */
    union __tag234 ICDMA12;                                /* ICDMA12          */
    union __tag235 ICDMA13;                                /* ICDMA13          */
    union __tag236 ICDMA14;                                /* ICDMA14          */
    union __tag237 ICDMA15;                                /* ICDMA15          */
    union __tag238 ICRIIC0TI;                              /* ICRIIC0TI        */
    union __tag239 ICRIIC0EE;                              /* ICRIIC0EE        */
    union __tag240 ICRIIC0RI;                              /* ICRIIC0RI        */
    union __tag241 ICRIIC0TEI;                             /* ICRIIC0TEI       */
    union __tag242 ICTAUJ0I0;                              /* ICTAUJ0I0        */
    union __tag243 ICTAUJ0I1;                              /* ICTAUJ0I1        */
    union __tag244 ICTAUJ0I2;                              /* ICTAUJ0I2        */
    union __tag245 ICTAUJ0I3;                              /* ICTAUJ0I3        */
    union __tag246 ICOSTM0;                                /* ICOSTM0          */
    union __tag247 ICENCA0IOV;                             /* ICENCA0IOV       */
    union __tag248 ICENCA0IUD;                             /* ICENCA0IUD       */
    union __tag249 ICENCA0I0;                              /* ICENCA0I0        */
    union __tag250 ICENCA0I1;                              /* ICENCA0I1        */
    union __tag251 ICENCA0IEC;                             /* ICENCA0IEC       */
    union __tag252 ICKR0;                                  /* ICKR0            */
    union __tag253 ICQFULL;                                /* ICQFULL          */
    union __tag254 ICPWGAG00;                              /* ICPWGAG00        */
    unsigned char  dummy679[34];                           /* Reserved         */
    union __tag255 ICFLERR;                                /* ICFLERR          */
    union __tag256 ICFLENDNM;                              /* ICFLENDNM        */
    union __tag257 ICCWEND;                                /* ICCWEND          */
    unsigned char  dummy680[6];                            /* Reserved         */
    union __tag258 ICTAPA0IPEK0_2;                         /* ICTAPA0IPEK0_2   */
    union __tag259 ICTAPA0IVLY0_2;                         /* ICTAPA0IVLY0_2   */
    union __tag260 ICCSIG0IC_2;                            /* ICCSIG0IC_2      */
    union __tag261 ICCSIG0IR_2;                            /* ICCSIG0IR_2      */
    unsigned char  dummy681[24];                           /* Reserved         */
    union __tag262 ICTAUD0I0_2;                            /* ICTAUD0I0_2      */
    union __tag263 ICTAUD0I4_2;                            /* ICTAUD0I4_2      */
    union __tag264 ICTAUD0I6_2;                            /* ICTAUD0I6_2      */
    union __tag265 ICTAUD0I8_2;                            /* ICTAUD0I8_2      */
    unsigned char  dummy682[44];                           /* Reserved         */
    union __tag266 ICTAUD0I2_2;                            /* ICTAUD0I2_2      */
    union __tag267 ICTAUD0I10_2;                           /* ICTAUD0I10_2     */
    union __tag268 ICTAUD0I12_2;                           /* ICTAUD0I12_2     */
    union __tag269 ICTAUD0I14_2;                           /* ICTAUD0I14_2     */
    unsigned char  dummy683[12];                           /* Reserved         */
    union __tag270 ICTAUJ1I0;                              /* ICTAUJ1I0        */
    union __tag271 ICTAUJ1I1;                              /* ICTAUJ1I1        */
    union __tag272 ICTAUJ1I2;                              /* ICTAUJ1I2        */
    union __tag273 ICTAUJ1I3;                              /* ICTAUJ1I3        */
    unsigned char  dummy684[74];                           /* Reserved         */
    union __tag274 ICRTCA01S;                              /* ICRTCA01S        */
    union __tag275 ICRTCA0AL;                              /* ICRTCA0AL        */
    union __tag276 ICRTCA0R;                               /* ICRTCA0R         */
    unsigned char  dummy685[56];                           /* Reserved         */
    union __tag277 ICRIIC1TI;                              /* ICRIIC1TI        */
    union __tag278 ICRIIC1EE;                              /* ICRIIC1EE        */
    union __tag279 ICRIIC1RI;                              /* ICRIIC1RI        */
    union __tag280 ICRIIC1TEI;                             /* ICRIIC1TEI       */
    unsigned char  dummy686[66];                           /* Reserved         */
    union __tag281 ICTAUJ2I0;                              /* ICTAUJ2I0        */
    union __tag282 ICTAUJ2I1;                              /* ICTAUJ2I1        */
    union __tag283 ICTAUJ2I2;                              /* ICTAUJ2I2        */
    union __tag284 ICTAUJ2I3;                              /* ICTAUJ2I3        */
    union __tag285 ICTAUJ3I0;                              /* ICTAUJ3I0        */
    union __tag286 ICTAUJ3I1;                              /* ICTAUJ3I1        */
    union __tag287 ICTAUJ3I2;                              /* ICTAUJ3I2        */
    union __tag288 ICTAUJ3I3;                              /* ICTAUJ3I3        */
    unsigned char  dummy687[124];                          /* Reserved         */
    union __tag289 ICSENT0SI;                              /* ICSENT0SI        */
    union __tag290 ICSENT0RI;                              /* ICSENT0RI        */
    union __tag291 ICSENT1SI;                              /* ICSENT1SI        */
    union __tag292 ICSENT1RI;                              /* ICSENT1RI        */
    unsigned char  dummy688[10];                           /* Reserved         */
    union __tag293 ICDPE;                                  /* ICDPE            */
    union __tag294 ICAPE;                                  /* ICAPE            */
    unsigned char  dummy689[312];                          /* Reserved         */
    union __tag295 IMR1;                                   /* IMR1             */
    union __tag296 IMR2;                                   /* IMR2             */
    union __tag297 IMR3;                                   /* IMR3             */
    union __tag298 IMR4;                                   /* IMR4             */
    union __tag299 IMR5;                                   /* IMR5             */
    union __tag300 IMR6;                                   /* IMR6             */
    union __tag301 IMR7;                                   /* IMR7             */
    union __tag302 IMR8;                                   /* IMR8             */
    unsigned char  dummy690[4];                            /* Reserved         */
    union __tag303 IMR10;                                  /* IMR10            */
    union __tag304 IMR11;                                  /* IMR11            */
};

#define ICCSIH0IJC_1 ICADCA0I2
#define ICCSIH0IJC_1L ICADCA0I2L
#define ICCSIH0IJC_1H ICADCA0I2H
#define ICCSIH0IJC ICADCA0I2_2
#define ICCSIH0IJCL ICADCA0I2_2L
#define ICCSIH0IJCH ICADCA0I2_2H
#define P0CSIH0IJC_1 P0ADCA0I2
#define P1CSIH0IJC_1 P1ADCA0I2
#define P2CSIH0IJC_1 P2ADCA0I2
#define P3CSIH0IJC_1 P3ADCA0I2
#define TBCSIH0IJC_1 TBADCA0I2
#define MKCSIH0IJC_1 MKADCA0I2
#define RFCSIH0IJC_1 RFADCA0I2
#define CTCSIH0IJC_1 CTADCA0I2
#define P0CSIH0IJC P0ADCA0I2_2
#define P1CSIH0IJC P1ADCA0I2_2
#define P2CSIH0IJC P2ADCA0I2_2
#define P3CSIH0IJC P3ADCA0I2_2
#define TBCSIH0IJC TBADCA0I2_2
#define MKCSIH0IJC MKADCA0I2_2
#define RFCSIH0IJC RFADCA0I2_2
#define CTCSIH0IJC CTADCA0I2_2


#define FLMD     (*(volatile struct __tag305 *)0xFFA00000) /* FLMD */
#define SELF     (*(volatile struct __tag306 *)0xFFA08000) /* SELF */
#define FACI     (*(volatile struct __tag307 *)0xFFA10000) /* FACI */
#define ECON_NMI (*(volatile struct __tag308 *)0xFFC00000) /* ECON_NMI */
#define ECON_FEINT (*(volatile struct __tag309 *)0xFFC00100) /* ECON_FEINT */
#define SL_INTC  (*(volatile struct __tag310 *)0xFFC01000) /* SL_INTC */
#define SL_DMAC  (*(volatile struct __tag311 *)0xFFC02000) /* SL_DMAC */
#define PORT     (*(volatile struct __tag312 *)0xFFC10000) /* PORT */
#define JTAG     (*(volatile struct __tag313 *)0xFFC20000) /* JTAG */
#define DNF      (*(volatile struct __tag314 *)0xFFC30000) /* DNF */
#define FCLA0    (*(volatile struct __tag315 *)0xFFC34000) /* FCLA0 */
#define PBG10    (*(volatile struct __tag316 *)0xFFC40000) /* PBG10 */
#define PBG11    (*(volatile struct __tag317 *)0xFFC40100) /* PBG11 */
#define PBG12    (*(volatile struct __tag318 *)0xFFC40400) /* PBG12 */
#define PBG13    (*(volatile struct __tag319 *)0xFFC40500) /* PBG13 */
#define PBGC0    (*(volatile struct __tag320 *)0xFFC4C000) /* PBGC0 */
#define PBGC1    (*(volatile struct __tag321 *)0xFFC4C120) /* PBGC1 */
#define DCIB     (*(volatile struct __tag322 *)0xFFC59810) /* DCIB */
#define FBUF_CTRL (*(volatile struct __tag323 *)0xFFC5B000) /* FBUF_CTRL */
#define CFECC_VCI (*(volatile struct __tag324 *)0xFFC62200) /* CFECC_VCI */
#define CFECC_CPU1 (*(volatile struct __tag325 *)0xFFC62400) /* CFECC_CPU1 */
#define DFECC    (*(volatile struct __tag326 *)0xFFC62A00) /* DFECC */
#define LRTST    (*(volatile struct __tag327 *)0xFFC65004) /* LRTST */
#define LRECC    (*(volatile struct __tag328 *)0xFFC65400) /* LRECC */
#define ECCCSIH0 (*(volatile struct __tag329 *)0xFFC70100) /* ECCCSIH0 */
#define ECCCFD0MB (*(volatile struct __tag329 *)0xFFC71300) /* ECCCFD0MB */
#define ECCCFD0AFL0 (*(volatile struct __tag329 *)0xFFC71400) /* ECCCFD0AFL0 */
#define ECCCFD0AFL1 (*(volatile struct __tag329 *)0xFFC71500) /* ECCCFD0AFL1 */
#define SL_READTEST (*(volatile struct __tag330 *)0xFFC78000) /* SL_READTEST */
#define RIIC0    (*(volatile struct __tag331 *)0xFFCA0000) /* RIIC0 */
#define RIIC1    (*(volatile struct __tag331 *)0xFFCA0080) /* RIIC1 */
#define SCDS     (*(volatile struct __tag332 *)0xFFCD00D0) /* SCDS */
#define RLN240   (*(volatile struct __tag333 *)0xFFCE0000) /* RLN240 */
#define RLN2400  (*(volatile struct __tag334 *)0xFFCE0008) /* RLN2400 */
#define RLN2401  (*(volatile struct __tag335 *)0xFFCE0028) /* RLN2401 */
#define RLN30    (*(volatile struct __tag336 *)0xFFCE2000) /* RLN30 */
#define RSENT0   (*(volatile struct __tag337 *)0xFFCF0000) /* RSENT0 */
#define RSENT1   (*(volatile struct __tag337 *)0xFFCF0100) /* RSENT1 */
#define RCFDC0   (*(volatile struct __tag338 *)0xFFD00000) /* RCFDC0 */
#define OSTM0    (*(volatile struct __tag339 *)0xFFD70000) /* OSTM0 */
#define CSIH0    (*(volatile struct __tag340 *)0xFFD80000) /* CSIH0 */
#define CSIG0    (*(volatile struct __tag341 *)0xFFD88000) /* CSIG0 */
#define PIC0     (*(volatile struct __tag342 *)0xFFDD0004) /* PIC0 */
#define PBG20    (*(volatile struct __tag343 *)0xFFDDD000) /* PBG20 */
#define PBG21    (*(volatile struct __tag344 *)0xFFDDD100) /* PBG21 */
#define TAUD0    (*(volatile struct __tag345 *)0xFFE20000) /* TAUD0 */
#define SL_TAUD0 (*(volatile struct __tag346 *)0xFFE24000) /* SL_TAUD0 */
#define TAUJ0    (*(volatile struct __tag347 *)0xFFE50000) /* TAUJ0 */
#define TAUJ2    (*(volatile struct __tag347 *)0xFFE50100) /* TAUJ2 */
#define TAUJ1    (*(volatile struct __tag347 *)0xFFE51000) /* TAUJ1 */
#define TAUJ3    (*(volatile struct __tag347 *)0xFFE51100) /* TAUJ3 */
#define SL_TAUJ0 (*(volatile struct __tag348 *)0xFFE54000) /* SL_TAUJ0 */
#define SL_TAUJ2 (*(volatile struct __tag349 *)0xFFE54004) /* SL_TAUJ2 */
#define PWSA0    (*(volatile struct __tag350 *)0xFFE70000) /* PWSA0 */
#define PWGA0    (*(volatile struct __tag351 *)0xFFE71000) /* PWGA0 */
#define PWGA1    (*(volatile struct __tag351 *)0xFFE71040) /* PWGA1 */
#define PWGA2    (*(volatile struct __tag351 *)0xFFE71080) /* PWGA2 */
#define PWGA3    (*(volatile struct __tag351 *)0xFFE710C0) /* PWGA3 */
#define PWGA4    (*(volatile struct __tag351 *)0xFFE71100) /* PWGA4 */
#define PWGA5    (*(volatile struct __tag351 *)0xFFE71140) /* PWGA5 */
#define PWGA6    (*(volatile struct __tag351 *)0xFFE71180) /* PWGA6 */
#define PWGA7    (*(volatile struct __tag351 *)0xFFE711C0) /* PWGA7 */
#define PWGA8    (*(volatile struct __tag351 *)0xFFE71200) /* PWGA8 */
#define PWGA9    (*(volatile struct __tag351 *)0xFFE71240) /* PWGA9 */
#define PWGA10   (*(volatile struct __tag351 *)0xFFE71280) /* PWGA10 */
#define PWGA11   (*(volatile struct __tag351 *)0xFFE712C0) /* PWGA11 */
#define PWGA12   (*(volatile struct __tag351 *)0xFFE71300) /* PWGA12 */
#define PWBA0    (*(volatile struct __tag352 *)0xFFE72800) /* PWBA0 */
#define SLPWG    (*(volatile struct __tag353 *)0xFFE73000) /* SLPWG */
#define PWGA_INTF (*(volatile struct __tag354 *)0xFFE73100) /* PWGA_INTF */
#define RTCA0    (*(volatile struct __tag355 *)0xFFE78000) /* RTCA0 */
#define ENCA0    (*(volatile struct __tag356 *)0xFFE80000) /* ENCA0 */
#define TAPA0    (*(volatile struct __tag357 *)0xFFE90000) /* TAPA0 */
#define WDTA0    (*(volatile struct __tag358 *)0xFFED0000) /* WDTA0 */
#define WDTA1    (*(volatile struct __tag358 *)0xFFED1000) /* WDTA1 */
#define ADCA0    (*(volatile struct __tag359 *)0xFFF20000) /* ADCA0 */
#define DCRA0    (*(volatile struct __tag360 *)0xFFF70000) /* DCRA0 */
#define KR0      (*(volatile struct __tag361 *)0xFFF78000) /* KR0 */
#define WPROTR   (*(volatile struct __tag362 *)0xFFF80000) /* WPROTR */
#define STBC0    (*(volatile struct __tag363 *)0xFFF80100) /* STBC0 */
#define STBC_WUF0 (*(volatile struct __tag364 *)0xFFF80400) /* STBC_WUF0 */
#define STBC_WUF1 (*(volatile struct __tag365 *)0xFFF80410) /* STBC_WUF1 */
#define STBC_WUF20 (*(volatile struct __tag366 *)0xFFF80520) /* STBC_WUF20 */
#define RESCTL   (*(volatile struct __tag367 *)0xFFF80760) /* RESCTL */
#define SVM      (*(volatile struct __tag368 *)0xFFF80980) /* SVM */
#define STBC_IOHOLD (*(volatile struct __tag369 *)0xFFF80B00) /* STBC_IOHOLD */
#define CLKCTL   (*(volatile struct __tag370 *)0xFFF81000) /* CLKCTL */
#define LPS0     (*(volatile struct __tag371 *)0xFFF83000) /* LPS0 */
#define STBC_WUFISO (*(volatile struct __tag372 *)0xFFF88110) /* STBC_WUFISO */
#define CLMA0    (*(volatile struct __tag373 *)0xFFF8C000) /* CLMA0 */
#define CLMA     (*(volatile struct __tag374 *)0xFFF8C100) /* CLMA */
#define CLMA1    (*(volatile struct __tag373 *)0xFFF8D000) /* CLMA1 */
#define CLMA3    (*(volatile struct __tag373 *)0xFFF8E000) /* CLMA3 */
#define PBG50    (*(volatile struct __tag375 *)0xFFF90000) /* PBG50 */
#define PBG30    (*(volatile struct __tag376 *)0xFFF94000) /* PBG30 */
#define PBG31    (*(volatile struct __tag377 *)0xFFF94100) /* PBG31 */
#define PBG32    (*(volatile struct __tag378 *)0xFFF94200) /* PBG32 */
#define IPG      (*(volatile struct __tag379 *)0xFFFEE000) /* IPG */
#define PEG      (*(volatile struct __tag380 *)0xFFFEE60C) /* PEG */
#define SEG      (*(volatile struct __tag381 *)0xFFFEE980) /* SEG */
#define INTC1    (*(volatile struct __tag382 *)0xFFFEEA10) /* INTC1 */
#define PDMA0    (*(volatile struct __tag383 *)0xFFFF8000) /* PDMA0 */
#define INTC2    (*(volatile struct __tag384 *)0xFFFFB040) /* INTC2 */

/* IOR List *
FLMD.CNT
FLMD.PCMD
FLMD.PS
SELF.ID0 ... SELF.ID3
SELF.IDST.UINT32
SELF.IDST.UINT16[L]
SELF.IDST.UINT8[LL]
FACI.FPMON
FACI.FASTAT
FACI.FAEINT
FACI.FAREASELC
FACI.FSADDR
FACI.FEADDR
FACI.FSTATR.UINT32
FACI.FSTATR.UINT16[L/H]
FACI.FSTATR.UINT8[LL/LH/HL]
FACI.FENTRYR
FACI.FPROTR
FACI.FSUINITR
FACI.FLKSTAT
FACI.FRTSTAT
FACI.FCMDR
FACI.FPESTAT
FACI.FBCCNT
FACI.FBCSTAT
FACI.FPSADDR
FACI.FCPSR
FACI.FPCKAR
FACI.FECCEMON
FACI.FECCTMD
FACI.FDMYECC
FACI.BFASELR
ECON_NMI.WDTNMIF
ECON_NMI.WDTNMIFC
ECON_FEINT.FEINTF
ECON_FEINT.FEINTFMSK
ECON_FEINT.FEINTFC
SL_INTC.SELB_INTC1
SL_DMAC.DTFSEL_TAUD0
PORT.P0
PORT.P8 ... PORT.P10
PORT.AP0
PORT.PSR0
PORT.PSR8 ... PORT.PSR10
PORT.APSR0
PORT.PPR0
PORT.PPR8 ... PORT.PPR10
PORT.APPR0
PORT.PM0
PORT.PM8 ... PORT.PM10
PORT.APM0
PORT.PMC0
PORT.PMC8 ... PORT.PMC10
PORT.PFC0
PORT.PFC8 ... PORT.PFC10
PORT.PFCE0
PORT.PFCE8 ... PORT.PFCE10
PORT.PNOT0
PORT.PNOT8 ... PORT.PNOT10
PORT.APNOT0
PORT.PMSR0
PORT.PMSR8 ... PORT.PMSR10
PORT.APMSR0
PORT.PMCSR0
PORT.PMCSR8 ... PORT.PMCSR10
PORT.PFCAE0
PORT.PFCAE8 ... PORT.PFCAE10
PORT.PIBC0
PORT.PIBC8 ... PORT.PIBC10
PORT.APIBC0
PORT.PBDC0
PORT.PBDC8 ... PORT.PBDC10
PORT.APBDC0
PORT.PIPC0
PORT.PIPC10
PORT.PU0
PORT.PU8 ... PORT.PU10
PORT.PD0
PORT.PD8 ... PORT.PD10
PORT.PODC0
PORT.PODC8 ... PORT.PODC10
PORT.PDSC0
PORT.PDSC10
PORT.PIS0
PORT.PIS8 ... PORT.PIS10
PORT.PPROTS0
PORT.PPROTS8 ... PORT.PPROTS10
PORT.PPCMD0
PORT.PPCMD8 ... PORT.PPCMD10
JTAG.JP0
JTAG.JPSR0
JTAG.JPPR0
JTAG.JPM0
JTAG.JPMC0
JTAG.JPFC0
JTAG.JPFCE0
JTAG.JPNOT0
JTAG.JPMSR0
JTAG.JPMCSR0
JTAG.JPIBC0
JTAG.JPBDC0
JTAG.JPU0
JTAG.JPD0
JTAG.JPODC0
JTAG.JPDSC0
JTAG.JPIS0
JTAG.JPISA0
JTAG.JPPROTS0
JTAG.JPPCMD0
DNF.ATAUD0ICTL
DNF.ATAUD0IEN
DNF.ATAUD0IENH.UINT8
DNF.ATAUD0IENH.BIT.ATAUD0IENH0 ... DNF.ATAUD0IENH.BIT.ATAUD0IENH7
DNF.ATAUD0IENL.UINT8
DNF.ATAUD0IENL.BIT.ATAUD0IENL0 ... DNF.ATAUD0IENL.BIT.ATAUD0IENL7
DNF.AENCA0ICTL
DNF.AENCA0IEN
DNF.AENCA0IENL.UINT8
DNF.AENCA0IENL.BIT.AENCA0IENL0 ... DNF.AENCA0IENL.BIT.AENCA0IENL4
DNF.AADCTL0CTL
DNF.AADCTL0EN
DNF.AADCTL0ENL.UINT8
DNF.AADCTL0ENL.BIT.AADCTL0ENL0 ... DNF.AADCTL0ENL.BIT.AADCTL0ENL2
DNF.ASENTICTL
DNF.ASENTIEN
DNF.ASENTIENL.UINT8
DNF.ASENTIENL.BIT.ASENTIENL0
DNF.ASENTIENL.BIT.ASENTIENL1
FCLA0.CTL0_NMI
FCLA0.CTL0_INTPL
FCLA0.CTL1_INTPL
FCLA0.CTL2_INTPL
FCLA0.CTL3_INTPL
FCLA0.CTL4_INTPL
FCLA0.CTL5_INTPL
FCLA0.CTL2_INTPH
FCLA0.CTL3_INTPH
FCLA0.CTL0_ADC0
FCLA0.CTL1_ADC0
FCLA0.CTL2_ADC0
PBG10.FSGD00PROT0.UINT32
PBG10.FSGD00PROT0.UINT16[L/H]
PBG10.FSGD00PROT0.UINT8[LL/HL/HH]
PBG10.FSGD00PROT1.UINT32
PBG10.FSGD00PROT1.UINT16[L/H]
PBG10.FSGD00PROT1.UINT8[LL/HL/HH]
PBG10.FSGD00PROT2.UINT32
PBG10.FSGD00PROT2.UINT16[L/H]
PBG10.FSGD00PROT2.UINT8[LL/HL/HH]
PBG10.FSGD00PROT3.UINT32
PBG10.FSGD00PROT3.UINT16[L/H]
PBG10.FSGD00PROT3.UINT8[LL/HL/HH]
PBG10.FSGD00PROT4.UINT32
PBG10.FSGD00PROT4.UINT16[L/H]
PBG10.FSGD00PROT4.UINT8[LL/HL/HH]
PBG10.FSGD00PROT5.UINT32
PBG10.FSGD00PROT5.UINT16[L/H]
PBG10.FSGD00PROT5.UINT8[LL/HL/HH]
PBG10.FSGD00PROT6.UINT32
PBG10.FSGD00PROT6.UINT16[L/H]
PBG10.FSGD00PROT6.UINT8[LL/HL/HH]
PBG10.FSGD00PROT7.UINT32
PBG10.FSGD00PROT7.UINT16[L/H]
PBG10.FSGD00PROT7.UINT8[LL/HL/HH]
PBG10.FSGD00PROT8.UINT32
PBG10.FSGD00PROT8.UINT16[L/H]
PBG10.FSGD00PROT8.UINT8[LL/HL/HH]
PBG10.ERRSLV00CTL.UINT32
PBG10.ERRSLV00CTL.UINT16[L]
PBG10.ERRSLV00CTL.UINT8[LL]
PBG10.ERRSLV00STAT.UINT32
PBG10.ERRSLV00STAT.UINT16[L]
PBG10.ERRSLV00STAT.UINT8[LL]
PBG10.ERRSLV00ADDR
PBG10.ERRSLV00TYPE.UINT32
PBG10.ERRSLV00TYPE.UINT16[L]
PBG11.FSGD01PROT0.UINT32
PBG11.FSGD01PROT0.UINT16[L/H]
PBG11.FSGD01PROT0.UINT8[LL/HL/HH]
PBG11.FSGD01PROT1.UINT32
PBG11.FSGD01PROT1.UINT16[L/H]
PBG11.FSGD01PROT1.UINT8[LL/HL/HH]
PBG11.FSGD01PROT2.UINT32
PBG11.FSGD01PROT2.UINT16[L/H]
PBG11.FSGD01PROT2.UINT8[LL/HL/HH]
PBG11.FSGD01PROT3.UINT32
PBG11.FSGD01PROT3.UINT16[L/H]
PBG11.FSGD01PROT3.UINT8[LL/HL/HH]
PBG11.FSGD01PROT4.UINT32
PBG11.FSGD01PROT4.UINT16[L/H]
PBG11.FSGD01PROT4.UINT8[LL/HL/HH]
PBG11.FSGD01PROT5.UINT32
PBG11.FSGD01PROT5.UINT16[L/H]
PBG11.FSGD01PROT5.UINT8[LL/HL/HH]
PBG11.FSGD01PROT6.UINT32
PBG11.FSGD01PROT6.UINT16[L/H]
PBG11.FSGD01PROT6.UINT8[LL/HL/HH]
PBG11.FSGD01PROT12.UINT32
PBG11.FSGD01PROT12.UINT16[L/H]
PBG11.FSGD01PROT12.UINT8[LL/HL/HH]
PBG11.FSGD01PROT13.UINT32
PBG11.FSGD01PROT13.UINT16[L/H]
PBG11.FSGD01PROT13.UINT8[LL/HL/HH]
PBG11.FSGD01PROT14.UINT32
PBG11.FSGD01PROT14.UINT16[L/H]
PBG11.FSGD01PROT14.UINT8[LL/HL/HH]
PBG11.ERRSLV01CTL.UINT32
PBG11.ERRSLV01CTL.UINT16[L]
PBG11.ERRSLV01CTL.UINT8[LL]
PBG11.ERRSLV01STAT.UINT32
PBG11.ERRSLV01STAT.UINT16[L]
PBG11.ERRSLV01STAT.UINT8[LL]
PBG11.ERRSLV01ADDR
PBG11.ERRSLV01TYPE.UINT32
PBG11.ERRSLV01TYPE.UINT16[L]
PBG12.FSGD07PROT0.UINT32
PBG12.FSGD07PROT0.UINT16[L/H]
PBG12.FSGD07PROT0.UINT8[LL/HL/HH]
PBG12.FSGD07PROT1.UINT32
PBG12.FSGD07PROT1.UINT16[L/H]
PBG12.FSGD07PROT1.UINT8[LL/HL/HH]
PBG12.FSGD07PROT2.UINT32
PBG12.FSGD07PROT2.UINT16[L/H]
PBG12.FSGD07PROT2.UINT8[LL/HL/HH]
PBG12.FSGD07PROT15.UINT32
PBG12.FSGD07PROT15.UINT16[L/H]
PBG12.FSGD07PROT15.UINT8[LL/HL/HH]
PBG12.ERRSLV07CTL.UINT32
PBG12.ERRSLV07CTL.UINT16[L]
PBG12.ERRSLV07CTL.UINT8[LL]
PBG12.ERRSLV07STAT.UINT32
PBG12.ERRSLV07STAT.UINT16[L]
PBG12.ERRSLV07STAT.UINT8[LL]
PBG12.ERRSLV07ADDR
PBG12.ERRSLV07TYPE.UINT32
PBG12.ERRSLV07TYPE.UINT16[L]
PBG13.FSGD08PROT0.UINT32
PBG13.FSGD08PROT0.UINT16[L/H]
PBG13.FSGD08PROT0.UINT8[LL/HL/HH]
PBG13.FSGD08PROT4.UINT32
PBG13.FSGD08PROT4.UINT16[L/H]
PBG13.FSGD08PROT4.UINT8[LL/HL/HH]
PBG13.FSGD08PROT5.UINT32
PBG13.FSGD08PROT5.UINT16[L/H]
PBG13.FSGD08PROT5.UINT8[LL/HL/HH]
PBG13.FSGD08PROT6.UINT32
PBG13.FSGD08PROT6.UINT16[L/H]
PBG13.FSGD08PROT6.UINT8[LL/HL/HH]
PBG13.FSGD08PROT8.UINT32
PBG13.FSGD08PROT8.UINT16[L/H]
PBG13.FSGD08PROT8.UINT8[LL/HL/HH]
PBG13.FSGD08PROT13.UINT32
PBG13.FSGD08PROT13.UINT16[L/H]
PBG13.FSGD08PROT13.UINT8[LL/HL/HH]
PBG13.FSGD08PROT14.UINT32
PBG13.FSGD08PROT14.UINT16[L/H]
PBG13.FSGD08PROT14.UINT8[LL/HL/HH]
PBG13.ERRSLV08CTL.UINT32
PBG13.ERRSLV08CTL.UINT16[L]
PBG13.ERRSLV08CTL.UINT8[LL]
PBG13.ERRSLV08STAT.UINT32
PBG13.ERRSLV08STAT.UINT16[L]
PBG13.ERRSLV08STAT.UINT8[LL]
PBG13.ERRSLV08ADDR
PBG13.ERRSLV08TYPE.UINT32
PBG13.ERRSLV08TYPE.UINT16[L]
PBGC0.FSGDC0PROT0.UINT32
PBGC0.FSGDC0PROT0.UINT16[L/H]
PBGC0.FSGDC0PROT0.UINT8[LL/HL/HH]
PBGC0.FSGDC0PROT1.UINT32
PBGC0.FSGDC0PROT1.UINT16[L/H]
PBGC0.FSGDC0PROT1.UINT8[LL/HL/HH]
PBGC0.ERRSLVC0CTL.UINT32
PBGC0.ERRSLVC0CTL.UINT16[L]
PBGC0.ERRSLVC0CTL.UINT8[LL]
PBGC0.ERRSLVC0STAT.UINT32
PBGC0.ERRSLVC0STAT.UINT16[L]
PBGC0.ERRSLVC0STAT.UINT8[LL]
PBGC0.ERRSLVC0ADDR
PBGC0.ERRSLVC0TYPE.UINT32
PBGC0.ERRSLVC0TYPE.UINT16[L]
PBGC1.FSGDC1PROT0.UINT32
PBGC1.FSGDC1PROT0.UINT16[L/H]
PBGC1.FSGDC1PROT0.UINT8[LL/HL/HH]
PBGC1.FSGDC1PROT1.UINT32
PBGC1.FSGDC1PROT1.UINT16[L/H]
PBGC1.FSGDC1PROT1.UINT8[LL/HL/HH]
PBGC1.FSGDC1PROT2.UINT32
PBGC1.FSGDC1PROT2.UINT16[L/H]
PBGC1.FSGDC1PROT2.UINT8[LL/HL/HH]
PBGC1.FSGDC1PROT3.UINT32
PBGC1.FSGDC1PROT3.UINT16[L/H]
PBGC1.FSGDC1PROT3.UINT8[LL/HL/HH]
PBGC1.FSGDC1PROT4.UINT32
PBGC1.FSGDC1PROT4.UINT16[L/H]
PBGC1.FSGDC1PROT4.UINT8[LL/HL/HH]
PBGC1.FSGDC1PROT5.UINT32
PBGC1.FSGDC1PROT5.UINT16[L/H]
PBGC1.FSGDC1PROT5.UINT8[LL/HL/HH]
PBGC1.ERRSLVC1CTL.UINT32
PBGC1.ERRSLVC1CTL.UINT16[L]
PBGC1.ERRSLVC1CTL.UINT8[LL]
PBGC1.ERRSLVC1STAT.UINT32
PBGC1.ERRSLVC1STAT.UINT16[L]
PBGC1.ERRSLVC1STAT.UINT8[LL]
PBGC1.ERRSLVC1ADDR
PBGC1.ERRSLVC1TYPE.UINT32
PBGC1.ERRSLVC1TYPE.UINT16[L]
DCIB.EEPRDCYCL
FBUF_CTRL.FBUFCCTL.UINT32
FBUF_CTRL.FBUFCCTL.UINT16[L]
FBUF_CTRL.FBUFCCTL.UINT8[LL]
CFECC_VCI.CFECCCTL_VCI.UINT32
CFECC_VCI.CFECCCTL_VCI.UINT16[L]
CFECC_VCI.CFERRINT_VCI.UINT32
CFECC_VCI.CFERRINT_VCI.UINT16[L]
CFECC_VCI.CFERRINT_VCI.UINT8[LL]
CFECC_VCI.CFSTCLR_VCI.UINT32
CFECC_VCI.CFSTCLR_VCI.UINT16[L]
CFECC_VCI.CFSTCLR_VCI.UINT8[LL]
CFECC_VCI.CFOVFSTR_VCI.UINT32
CFECC_VCI.CFOVFSTR_VCI.UINT16[L]
CFECC_VCI.CFOVFSTR_VCI.UINT8[LL]
CFECC_VCI.CF1STERSTR_VCI.UINT32
CFECC_VCI.CF1STERSTR_VCI.UINT16[L]
CFECC_VCI.CF1STERSTR_VCI.UINT8[LL]
CFECC_VCI.CF1STEADR0_VCI.UINT32
CFECC_VCI.CF1STEADR0_VCI.UINT16[L/H]
CFECC_VCI.CF1STEADR0_VCI.UINT8[LL/LH/HL/HH]
CFECC_VCI.CFSTSTCTL_VCI.UINT32
CFECC_VCI.CFSTSTCTL_VCI.UINT16[L]
CFECC_CPU1.CFECCCTL_PE1.UINT32
CFECC_CPU1.CFECCCTL_PE1.UINT16[L]
CFECC_CPU1.CFERRINT_PE1.UINT32
CFECC_CPU1.CFERRINT_PE1.UINT16[L]
CFECC_CPU1.CFERRINT_PE1.UINT8[LL]
CFECC_CPU1.CFSTCLR_PE1.UINT32
CFECC_CPU1.CFSTCLR_PE1.UINT16[L]
CFECC_CPU1.CFSTCLR_PE1.UINT8[LL]
CFECC_CPU1.CFOVFSTR_PE1.UINT32
CFECC_CPU1.CFOVFSTR_PE1.UINT16[L]
CFECC_CPU1.CFOVFSTR_PE1.UINT8[LL]
CFECC_CPU1.CF1STERSTR_PE1.UINT32
CFECC_CPU1.CF1STERSTR_PE1.UINT16[L]
CFECC_CPU1.CF1STERSTR_PE1.UINT8[LL]
CFECC_CPU1.CF1STEADR0_PE1.UINT32
CFECC_CPU1.CF1STEADR0_PE1.UINT16[L/H]
CFECC_CPU1.CF1STEADR0_PE1.UINT8[LL/LH/HL/HH]
DFECC.CTL
DFECC.DFERSTR
DFECC.DFERSTC
DFECC.DFOVFSTR
DFECC.DFOVFSTC
DFECC.DFERRINT
DFECC.DFEADR
DFECC.DFTSTCTL
LRTST.CTL_PE1.UINT32
LRTST.CTL_PE1.UINT16[L]
LRTST.LRTDATBF0_PE1
LRECC.CTL_PE1.UINT32
LRECC.CTL_PE1.UINT16[L]
LRECC.LRERRINT_PE1.UINT32
LRECC.LRERRINT_PE1.UINT16[L]
LRECC.LRERRINT_PE1.UINT8[LL]
LRECC.LRSTCLR_PE1.UINT32
LRECC.LRSTCLR_PE1.UINT16[L]
LRECC.LRSTCLR_PE1.UINT8[LL]
LRECC.LROVFSTR_PE1.UINT32
LRECC.LROVFSTR_PE1.UINT16[L]
LRECC.LROVFSTR_PE1.UINT8[LL]
LRECC.LR1STERSTR_PE1.UINT32
LRECC.LR1STERSTR_PE1.UINT16[L]
LRECC.LR1STERSTR_PE1.UINT8[LL]
LRECC.LR1STEADR0_PE1.UINT32
LRECC.LR1STEADR0_PE1.UINT16[L/H]
LRECC.LR1STEADR0_PE1.UINT8[LL/LH/HL]
ECCCSIH0.CTL
ECCCSIH0.TMC
ECCCSIH0.TRC.UINT32
ECCCSIH0.TRC.UINT8[LL/LH/HL/HH]
ECCCSIH0.TRC.REGS8.ERDB.UINT8
ECCCSIH0.TRC.REGS8.ECRD.UINT8
ECCCSIH0.TRC.REGS8.HORD.UINT8
ECCCSIH0.TRC.REGS8.SYND.UINT8
ECCCSIH0.TED
ECCCSIH0.AD0
ECCCFD0MB.CTL
ECCCFD0MB.TMC
ECCCFD0MB.TRC.UINT32
ECCCFD0MB.TRC.UINT8[LL/LH/HL/HH]
ECCCFD0MB.TRC.REGS8.ERDB.UINT8
ECCCFD0MB.TRC.REGS8.ECRD.UINT8
ECCCFD0MB.TRC.REGS8.HORD.UINT8
ECCCFD0MB.TRC.REGS8.SYND.UINT8
ECCCFD0MB.TED
ECCCFD0MB.AD0
ECCCFD0AFL0.CTL
ECCCFD0AFL0.TMC
ECCCFD0AFL0.TRC.UINT32
ECCCFD0AFL0.TRC.UINT8[LL/LH/HL/HH]
ECCCFD0AFL0.TRC.REGS8.ERDB.UINT8
ECCCFD0AFL0.TRC.REGS8.ECRD.UINT8
ECCCFD0AFL0.TRC.REGS8.HORD.UINT8
ECCCFD0AFL0.TRC.REGS8.SYND.UINT8
ECCCFD0AFL0.TED
ECCCFD0AFL0.AD0
ECCCFD0AFL1.CTL
ECCCFD0AFL1.TMC
ECCCFD0AFL1.TRC.UINT32
ECCCFD0AFL1.TRC.UINT8[LL/LH/HL/HH]
ECCCFD0AFL1.TRC.REGS8.ERDB.UINT8
ECCCFD0AFL1.TRC.REGS8.ECRD.UINT8
ECCCFD0AFL1.TRC.REGS8.HORD.UINT8
ECCCFD0AFL1.TRC.REGS8.SYND.UINT8
ECCCFD0AFL1.TED
ECCCFD0AFL1.AD0
SL_READTEST.SELB_READTEST
RIIC0.CR1.UINT32
RIIC0.CR1.UINT16[L]
RIIC0.CR1.UINT8[LL]
RIIC0.CR2.UINT32
RIIC0.CR2.UINT16[L]
RIIC0.CR2.UINT8[LL]
RIIC0.MR1.UINT32
RIIC0.MR1.UINT16[L]
RIIC0.MR1.UINT8[LL]
RIIC0.MR2.UINT32
RIIC0.MR2.UINT16[L]
RIIC0.MR2.UINT8[LL]
RIIC0.MR3.UINT32
RIIC0.MR3.UINT16[L]
RIIC0.MR3.UINT8[LL]
RIIC0.FER.UINT32
RIIC0.FER.UINT16[L]
RIIC0.FER.UINT8[LL]
RIIC0.SER.UINT32
RIIC0.SER.UINT16[L]
RIIC0.SER.UINT8[LL]
RIIC0.IER.UINT32
RIIC0.IER.UINT16[L]
RIIC0.IER.UINT8[LL]
RIIC0.SR1.UINT32
RIIC0.SR1.UINT16[L]
RIIC0.SR1.UINT8[LL]
RIIC0.SR2.UINT32
RIIC0.SR2.UINT16[L]
RIIC0.SR2.UINT8[LL]
RIIC0.SAR0.UINT32
RIIC0.SAR0.UINT16[L]
RIIC0.SAR0.UINT8[LL/LH]
RIIC0.SAR1.UINT32
RIIC0.SAR1.UINT16[L]
RIIC0.SAR1.UINT8[LL/LH]
RIIC0.SAR2.UINT32
RIIC0.SAR2.UINT16[L]
RIIC0.SAR2.UINT8[LL/LH]
RIIC0.BRL.UINT32
RIIC0.BRL.UINT16[L]
RIIC0.BRL.UINT8[LL]
RIIC0.BRH.UINT32
RIIC0.BRH.UINT16[L]
RIIC0.BRH.UINT8[LL]
RIIC0.DRT.UINT32
RIIC0.DRT.UINT16[L]
RIIC0.DRT.UINT8[LL]
RIIC0.DRR.UINT32
RIIC0.DRR.UINT16[L]
RIIC0.DRR.UINT8[LL]
RIIC1.CR1.UINT32
RIIC1.CR1.UINT16[L]
RIIC1.CR1.UINT8[LL]
RIIC1.CR2.UINT32
RIIC1.CR2.UINT16[L]
RIIC1.CR2.UINT8[LL]
RIIC1.MR1.UINT32
RIIC1.MR1.UINT16[L]
RIIC1.MR1.UINT8[LL]
RIIC1.MR2.UINT32
RIIC1.MR2.UINT16[L]
RIIC1.MR2.UINT8[LL]
RIIC1.MR3.UINT32
RIIC1.MR3.UINT16[L]
RIIC1.MR3.UINT8[LL]
RIIC1.FER.UINT32
RIIC1.FER.UINT16[L]
RIIC1.FER.UINT8[LL]
RIIC1.SER.UINT32
RIIC1.SER.UINT16[L]
RIIC1.SER.UINT8[LL]
RIIC1.IER.UINT32
RIIC1.IER.UINT16[L]
RIIC1.IER.UINT8[LL]
RIIC1.SR1.UINT32
RIIC1.SR1.UINT16[L]
RIIC1.SR1.UINT8[LL]
RIIC1.SR2.UINT32
RIIC1.SR2.UINT16[L]
RIIC1.SR2.UINT8[LL]
RIIC1.SAR0.UINT32
RIIC1.SAR0.UINT16[L]
RIIC1.SAR0.UINT8[LL/LH]
RIIC1.SAR1.UINT32
RIIC1.SAR1.UINT16[L]
RIIC1.SAR1.UINT8[LL/LH]
RIIC1.SAR2.UINT32
RIIC1.SAR2.UINT16[L]
RIIC1.SAR2.UINT8[LL/LH]
RIIC1.BRL.UINT32
RIIC1.BRL.UINT16[L]
RIIC1.BRL.UINT8[LL]
RIIC1.BRH.UINT32
RIIC1.BRH.UINT16[L]
RIIC1.BRH.UINT8[LL]
RIIC1.DRT.UINT32
RIIC1.DRT.UINT16[L]
RIIC1.DRT.UINT8[LL]
RIIC1.DRR.UINT32
RIIC1.DRR.UINT16[L]
RIIC1.DRR.UINT8[LL]
SCDS.PRDNAME1 ... SCDS.PRDNAME3
SCDS.CHIPID1LL
SCDS.CHIPID1LH
SCDS.CHIPID1HL
SCDS.CHIPID1HH
SCDS.CHIPID2LL
SCDS.CHIPID2LH
SCDS.CHIPID2HL
SCDS.CHIPID2HH
RLN240.GLWBR
RLN240.GLBRP0
RLN240.GLBRP1
RLN240.GLSTC
RLN2400.L0MD
RLN2400.L0BFC
RLN2400.L0SC
RLN2400.L0WUP
RLN2400.L0IE
RLN2400.L0EDE
RLN2400.L0CUC
RLN2400.L0TRC
RLN2400.L0MST
RLN2400.L0ST
RLN2400.L0EST
RLN2400.L0DFC
RLN2400.L0IDB
RLN2400.L0CBR
RLN2400.L0DBR1 ... RLN2400.L0DBR8
RLN2401.L1MD
RLN2401.L1BFC
RLN2401.L1SC
RLN2401.L1WUP
RLN2401.L1IE
RLN2401.L1EDE
RLN2401.L1CUC
RLN2401.L1TRC
RLN2401.L1MST
RLN2401.L1ST
RLN2401.L1EST
RLN2401.L1DFC
RLN2401.L1IDB
RLN2401.L1CBR
RLN2401.L1DBR1 ... RLN2401.L1DBR8
RLN30.LWBR
RLN30.LBRP01.UINT16
RLN30.LBRP01.UINT8[L/H]
RLN30.LBRP01.REGS8.LBRP0.UINT8
RLN30.LBRP01.REGS8.LBRP1.UINT8
RLN30.LSTC
RLN30.LMD
RLN30.LBFC
RLN30.LSC
RLN30.LWUP
RLN30.LIE
RLN30.LEDE
RLN30.LCUC
RLN30.LTRC
RLN30.LMST
RLN30.LST
RLN30.LEST
RLN30.LDFC
RLN30.LIDB
RLN30.LCBR
RLN30.LUDB0
RLN30.LDBR1 ... RLN30.LDBR8
RLN30.LUOER
RLN30.LUOR1
RLN30.LUTDR.UINT16
RLN30.LUTDR.UINT8[L/H]
RLN30.LURDR.UINT16
RLN30.LURDR.UINT8[L/H]
RLN30.LUWTDR.UINT16
RLN30.LUWTDR.UINT8[L/H]
RSENT0.TSPC
RSENT0.TSC
RSENT0.CC
RSENT0.BRP
RSENT0.IDE
RSENT0.MDC
RSENT0.SPCT
RSENT0.MST
RSENT0.CS
RSENT0.CSC
RSENT0.SRTS
RSENT0.SRXD
RSENT0.CPL
RSENT0.ML
RSENT0.FRTS
RSENT0.FRXD
RSENT1.TSPC
RSENT1.TSC
RSENT1.CC
RSENT1.BRP
RSENT1.IDE
RSENT1.MDC
RSENT1.SPCT
RSENT1.MST
RSENT1.CS
RSENT1.CSC
RSENT1.SRTS
RSENT1.SRXD
RSENT1.CPL
RSENT1.ML
RSENT1.FRTS
RSENT1.FRXD
RCFDC0.CFDC0NCFG.UINT32
RCFDC0.CFDC0NCFG.UINT16[L/H]
RCFDC0.CFDC0NCFG.UINT8[LL/LH/HL/HH]
RCFDC0.CFDC0CTR.UINT32
RCFDC0.CFDC0CTR.UINT16[L/H]
RCFDC0.CFDC0CTR.UINT8[LL/LH/HL/HH]
RCFDC0.CFDC0STS.UINT32
RCFDC0.CFDC0STS.UINT16[L/H]
RCFDC0.CFDC0STS.UINT8[LL/LH/HL/HH]
RCFDC0.CFDC0ERFL.UINT32
RCFDC0.CFDC0ERFL.UINT16[L/H]
RCFDC0.CFDC0ERFL.UINT8[LL/LH/HL/HH]
RCFDC0.CFDGCFG.UINT32
RCFDC0.CFDGCFG.UINT16[L/H]
RCFDC0.CFDGCFG.UINT8[LL/LH/HL/HH]
RCFDC0.CFDGCTR.UINT32
RCFDC0.CFDGCTR.UINT16[L/H]
RCFDC0.CFDGCTR.UINT8[LL/LH/HL]
RCFDC0.CFDGSTS.UINT32
RCFDC0.CFDGSTS.UINT16[L]
RCFDC0.CFDGSTS.UINT8[LL]
RCFDC0.CFDGERFL.UINT32
RCFDC0.CFDGERFL.UINT16[L/H]
RCFDC0.CFDGERFL.UINT8[LL/HL]
RCFDC0.CFDGTSC.UINT32
RCFDC0.CFDGTSC.UINT16[L]
RCFDC0.CFDGAFLECTR.UINT32
RCFDC0.CFDGAFLECTR.UINT16[L]
RCFDC0.CFDGAFLECTR.UINT8[LL/LH]
RCFDC0.CFDGAFLCFG0.UINT32
RCFDC0.CFDGAFLCFG0.UINT16[H]
RCFDC0.CFDGAFLCFG0.UINT8[HH]
RCFDC0.CFDRMNB.UINT32
RCFDC0.CFDRMNB.UINT16[L]
RCFDC0.CFDRMNB.UINT8[LL/LH]
RCFDC0.CFDRMND0.UINT32
RCFDC0.CFDRMND0.UINT16[L]
RCFDC0.CFDRMND0.UINT8[LL/LH]
RCFDC0.CFDRFCC0.UINT32
RCFDC0.CFDRFCC0.UINT16[L]
RCFDC0.CFDRFCC0.UINT8[LL/LH]
RCFDC0.CFDRFCC1.UINT32
RCFDC0.CFDRFCC1.UINT16[L]
RCFDC0.CFDRFCC1.UINT8[LL/LH]
RCFDC0.CFDRFCC2.UINT32
RCFDC0.CFDRFCC2.UINT16[L]
RCFDC0.CFDRFCC2.UINT8[LL/LH]
RCFDC0.CFDRFCC3.UINT32
RCFDC0.CFDRFCC3.UINT16[L]
RCFDC0.CFDRFCC3.UINT8[LL/LH]
RCFDC0.CFDRFCC4.UINT32
RCFDC0.CFDRFCC4.UINT16[L]
RCFDC0.CFDRFCC4.UINT8[LL/LH]
RCFDC0.CFDRFCC5.UINT32
RCFDC0.CFDRFCC5.UINT16[L]
RCFDC0.CFDRFCC5.UINT8[LL/LH]
RCFDC0.CFDRFCC6.UINT32
RCFDC0.CFDRFCC6.UINT16[L]
RCFDC0.CFDRFCC6.UINT8[LL/LH]
RCFDC0.CFDRFCC7.UINT32
RCFDC0.CFDRFCC7.UINT16[L]
RCFDC0.CFDRFCC7.UINT8[LL/LH]
RCFDC0.CFDRFSTS0.UINT32
RCFDC0.CFDRFSTS0.UINT16[L]
RCFDC0.CFDRFSTS0.UINT8[LL/LH]
RCFDC0.CFDRFSTS1.UINT32
RCFDC0.CFDRFSTS1.UINT16[L]
RCFDC0.CFDRFSTS1.UINT8[LL/LH]
RCFDC0.CFDRFSTS2.UINT32
RCFDC0.CFDRFSTS2.UINT16[L]
RCFDC0.CFDRFSTS2.UINT8[LL/LH]
RCFDC0.CFDRFSTS3.UINT32
RCFDC0.CFDRFSTS3.UINT16[L]
RCFDC0.CFDRFSTS3.UINT8[LL/LH]
RCFDC0.CFDRFSTS4.UINT32
RCFDC0.CFDRFSTS4.UINT16[L]
RCFDC0.CFDRFSTS4.UINT8[LL/LH]
RCFDC0.CFDRFSTS5.UINT32
RCFDC0.CFDRFSTS5.UINT16[L]
RCFDC0.CFDRFSTS5.UINT8[LL/LH]
RCFDC0.CFDRFSTS6.UINT32
RCFDC0.CFDRFSTS6.UINT16[L]
RCFDC0.CFDRFSTS6.UINT8[LL/LH]
RCFDC0.CFDRFSTS7.UINT32
RCFDC0.CFDRFSTS7.UINT16[L]
RCFDC0.CFDRFSTS7.UINT8[LL/LH]
RCFDC0.CFDRFPCTR0.UINT32
RCFDC0.CFDRFPCTR0.UINT16[L]
RCFDC0.CFDRFPCTR0.UINT8[LL]
RCFDC0.CFDRFPCTR1.UINT32
RCFDC0.CFDRFPCTR1.UINT16[L]
RCFDC0.CFDRFPCTR1.UINT8[LL]
RCFDC0.CFDRFPCTR2.UINT32
RCFDC0.CFDRFPCTR2.UINT16[L]
RCFDC0.CFDRFPCTR2.UINT8[LL]
RCFDC0.CFDRFPCTR3.UINT32
RCFDC0.CFDRFPCTR3.UINT16[L]
RCFDC0.CFDRFPCTR3.UINT8[LL]
RCFDC0.CFDRFPCTR4.UINT32
RCFDC0.CFDRFPCTR4.UINT16[L]
RCFDC0.CFDRFPCTR4.UINT8[LL]
RCFDC0.CFDRFPCTR5.UINT32
RCFDC0.CFDRFPCTR5.UINT16[L]
RCFDC0.CFDRFPCTR5.UINT8[LL]
RCFDC0.CFDRFPCTR6.UINT32
RCFDC0.CFDRFPCTR6.UINT16[L]
RCFDC0.CFDRFPCTR6.UINT8[LL]
RCFDC0.CFDRFPCTR7.UINT32
RCFDC0.CFDRFPCTR7.UINT16[L]
RCFDC0.CFDRFPCTR7.UINT8[LL]
RCFDC0.CFDCFCC0.UINT32
RCFDC0.CFDCFCC0.UINT16[L/H]
RCFDC0.CFDCFCC0.UINT8[LL/LH/HL/HH]
RCFDC0.CFDCFCC1.UINT32
RCFDC0.CFDCFCC1.UINT16[L/H]
RCFDC0.CFDCFCC1.UINT8[LL/LH/HL/HH]
RCFDC0.CFDCFCC2.UINT32
RCFDC0.CFDCFCC2.UINT16[L/H]
RCFDC0.CFDCFCC2.UINT8[LL/LH/HL/HH]
RCFDC0.CFDCFSTS0.UINT32
RCFDC0.CFDCFSTS0.UINT16[L]
RCFDC0.CFDCFSTS0.UINT8[LL/LH]
RCFDC0.CFDCFSTS1.UINT32
RCFDC0.CFDCFSTS1.UINT16[L]
RCFDC0.CFDCFSTS1.UINT8[LL/LH]
RCFDC0.CFDCFSTS2.UINT32
RCFDC0.CFDCFSTS2.UINT16[L]
RCFDC0.CFDCFSTS2.UINT8[LL/LH]
RCFDC0.CFDCFPCTR0.UINT32
RCFDC0.CFDCFPCTR0.UINT16[L]
RCFDC0.CFDCFPCTR0.UINT8[LL]
RCFDC0.CFDCFPCTR1.UINT32
RCFDC0.CFDCFPCTR1.UINT16[L]
RCFDC0.CFDCFPCTR1.UINT8[LL]
RCFDC0.CFDCFPCTR2.UINT32
RCFDC0.CFDCFPCTR2.UINT16[L]
RCFDC0.CFDCFPCTR2.UINT8[LL]
RCFDC0.CFDFESTS.UINT32
RCFDC0.CFDFESTS.UINT16[L]
RCFDC0.CFDFESTS.UINT8[LL/LH]
RCFDC0.CFDFFSTS.UINT32
RCFDC0.CFDFFSTS.UINT16[L]
RCFDC0.CFDFFSTS.UINT8[LL/LH]
RCFDC0.CFDFMSTS.UINT32
RCFDC0.CFDFMSTS.UINT16[L/H]
RCFDC0.CFDFMSTS.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFISTS.UINT32
RCFDC0.CFDRFISTS.UINT16[L]
RCFDC0.CFDRFISTS.UINT8[LL]
RCFDC0.CFDCFRISTS.UINT32
RCFDC0.CFDCFRISTS.UINT16[L]
RCFDC0.CFDCFRISTS.UINT8[LL]
RCFDC0.CFDCFTISTS.UINT32
RCFDC0.CFDCFTISTS.UINT16[L]
RCFDC0.CFDCFTISTS.UINT8[LL]
RCFDC0.CFDTMC0 ... RCFDC0.CFDTMC31
RCFDC0.CFDTMSTS0 ... RCFDC0.CFDTMSTS31
RCFDC0.CFDTMTRSTS0.UINT32
RCFDC0.CFDTMTRSTS0.UINT16[L/H]
RCFDC0.CFDTMTRSTS0.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMTARSTS0.UINT32
RCFDC0.CFDTMTARSTS0.UINT16[L/H]
RCFDC0.CFDTMTARSTS0.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMTCSTS0.UINT32
RCFDC0.CFDTMTCSTS0.UINT16[L/H]
RCFDC0.CFDTMTCSTS0.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMTASTS0.UINT32
RCFDC0.CFDTMTASTS0.UINT16[L/H]
RCFDC0.CFDTMTASTS0.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMIEC0.UINT32
RCFDC0.CFDTMIEC0.UINT16[L/H]
RCFDC0.CFDTMIEC0.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTXQCC0.UINT32
RCFDC0.CFDTXQCC0.UINT16[L]
RCFDC0.CFDTXQCC0.UINT8[LL/LH]
RCFDC0.CFDTXQSTS0.UINT32
RCFDC0.CFDTXQSTS0.UINT16[L]
RCFDC0.CFDTXQSTS0.UINT8[LL]
RCFDC0.CFDTXQPCTR0.UINT32
RCFDC0.CFDTXQPCTR0.UINT16[L]
RCFDC0.CFDTXQPCTR0.UINT8[LL]
RCFDC0.CFDTHLCC0.UINT32
RCFDC0.CFDTHLCC0.UINT16[L]
RCFDC0.CFDTHLCC0.UINT8[LL/LH]
RCFDC0.CFDTHLSTS0.UINT32
RCFDC0.CFDTHLSTS0.UINT16[L]
RCFDC0.CFDTHLSTS0.UINT8[LL/LH]
RCFDC0.CFDTHLPCTR0.UINT32
RCFDC0.CFDTHLPCTR0.UINT16[L]
RCFDC0.CFDTHLPCTR0.UINT8[LL]
RCFDC0.CFDGTINTSTS0.UINT32
RCFDC0.CFDGTINTSTS0.UINT16[L]
RCFDC0.CFDGTINTSTS0.UINT8[LL]
RCFDC0.CFDGTSTCFG.UINT32
RCFDC0.CFDGTSTCFG.UINT16[L/H]
RCFDC0.CFDGTSTCFG.UINT8[LL/HL/HH]
RCFDC0.CFDGTSTCTR.UINT32
RCFDC0.CFDGTSTCTR.UINT16[L]
RCFDC0.CFDGTSTCTR.UINT8[LL]
RCFDC0.CFDGFDCFG.UINT32
RCFDC0.CFDGFDCFG.UINT16[L]
RCFDC0.CFDGFDCFG.UINT8[LL/LH]
RCFDC0.CFDGLOCKK.UINT32
RCFDC0.CFDGLOCKK.UINT16[L]
RCFDC0.CFDCDTCT.UINT32
RCFDC0.CFDCDTCT.UINT16[L]
RCFDC0.CFDCDTCT.UINT8[LL/LH]
RCFDC0.CFDCDTSTS.UINT32
RCFDC0.CFDCDTSTS.UINT16[L]
RCFDC0.CFDCDTSTS.UINT8[LL/LH]
RCFDC0.CFDC0DCFG.UINT32
RCFDC0.CFDC0DCFG.UINT16[L/H]
RCFDC0.CFDC0DCFG.UINT8[LL/HL/HH]
RCFDC0.CFDC0FDCFG.UINT32
RCFDC0.CFDC0FDCFG.UINT16[L/H]
RCFDC0.CFDC0FDCFG.UINT8[LL/LH/HL/HH]
RCFDC0.CFDC0FDCTR.UINT32
RCFDC0.CFDC0FDCTR.UINT16[L]
RCFDC0.CFDC0FDCTR.UINT8[LL]
RCFDC0.CFDC0FDSTS.UINT32
RCFDC0.CFDC0FDSTS.UINT16[L/H]
RCFDC0.CFDC0FDSTS.UINT8[LL/LH/HL/HH]
RCFDC0.CFDC0FDCRC.UINT32
RCFDC0.CFDC0FDCRC.UINT16[L/H]
RCFDC0.CFDC0FDCRC.UINT8[LL/LH/HL/HH]
RCFDC0.CFDGAFLID0.UINT32
RCFDC0.CFDGAFLID0.UINT16[L/H]
RCFDC0.CFDGAFLID0.UINT8[LL/LH/HL/HH]
RCFDC0.CFDGAFLM0.UINT32
RCFDC0.CFDGAFLM0.UINT16[L/H]
RCFDC0.CFDGAFLM0.UINT8[LL/LH/HL/HH]
RCFDC0.CFDGAFLP0_0.UINT32
RCFDC0.CFDGAFLP0_0.UINT16[L/H]
RCFDC0.CFDGAFLP0_0.UINT8[LL/LH/HL/HH]
RCFDC0.CFDGAFLP1_0.UINT32
RCFDC0.CFDGAFLP1_0.UINT16[L]
RCFDC0.CFDGAFLP1_0.UINT8[LL/LH]
RCFDC0.CFDGAFLID1.UINT32
RCFDC0.CFDGAFLID1.UINT16[L/H]
RCFDC0.CFDGAFLID1.UINT8[LL/LH/HL/HH]
RCFDC0.CFDGAFLM1.UINT32
RCFDC0.CFDGAFLM1.UINT16[L/H]
RCFDC0.CFDGAFLM1.UINT8[LL/LH/HL/HH]
RCFDC0.CFDGAFLP0_1.UINT32
RCFDC0.CFDGAFLP0_1.UINT16[L/H]
RCFDC0.CFDGAFLP0_1.UINT8[LL/LH/HL/HH]
RCFDC0.CFDGAFLP1_1.UINT32
RCFDC0.CFDGAFLP1_1.UINT16[L]
RCFDC0.CFDGAFLP1_1.UINT8[LL/LH]
RCFDC0.CFDGAFLID2.UINT32
RCFDC0.CFDGAFLID2.UINT16[L/H]
RCFDC0.CFDGAFLID2.UINT8[LL/LH/HL/HH]
RCFDC0.CFDGAFLM2.UINT32
RCFDC0.CFDGAFLM2.UINT16[L/H]
RCFDC0.CFDGAFLM2.UINT8[LL/LH/HL/HH]
RCFDC0.CFDGAFLP0_2.UINT32
RCFDC0.CFDGAFLP0_2.UINT16[L/H]
RCFDC0.CFDGAFLP0_2.UINT8[LL/LH/HL/HH]
RCFDC0.CFDGAFLP1_2.UINT32
RCFDC0.CFDGAFLP1_2.UINT16[L]
RCFDC0.CFDGAFLP1_2.UINT8[LL/LH]
RCFDC0.CFDGAFLID3.UINT32
RCFDC0.CFDGAFLID3.UINT16[L/H]
RCFDC0.CFDGAFLID3.UINT8[LL/LH/HL/HH]
RCFDC0.CFDGAFLM3.UINT32
RCFDC0.CFDGAFLM3.UINT16[L/H]
RCFDC0.CFDGAFLM3.UINT8[LL/LH/HL/HH]
RCFDC0.CFDGAFLP0_3.UINT32
RCFDC0.CFDGAFLP0_3.UINT16[L/H]
RCFDC0.CFDGAFLP0_3.UINT8[LL/LH/HL/HH]
RCFDC0.CFDGAFLP1_3.UINT32
RCFDC0.CFDGAFLP1_3.UINT16[L]
RCFDC0.CFDGAFLP1_3.UINT8[LL/LH]
RCFDC0.CFDGAFLID4.UINT32
RCFDC0.CFDGAFLID4.UINT16[L/H]
RCFDC0.CFDGAFLID4.UINT8[LL/LH/HL/HH]
RCFDC0.CFDGAFLM4.UINT32
RCFDC0.CFDGAFLM4.UINT16[L/H]
RCFDC0.CFDGAFLM4.UINT8[LL/LH/HL/HH]
RCFDC0.CFDGAFLP0_4.UINT32
RCFDC0.CFDGAFLP0_4.UINT16[L/H]
RCFDC0.CFDGAFLP0_4.UINT8[LL/LH/HL/HH]
RCFDC0.CFDGAFLP1_4.UINT32
RCFDC0.CFDGAFLP1_4.UINT16[L]
RCFDC0.CFDGAFLP1_4.UINT8[LL/LH]
RCFDC0.CFDGAFLID5.UINT32
RCFDC0.CFDGAFLID5.UINT16[L/H]
RCFDC0.CFDGAFLID5.UINT8[LL/LH/HL/HH]
RCFDC0.CFDGAFLM5.UINT32
RCFDC0.CFDGAFLM5.UINT16[L/H]
RCFDC0.CFDGAFLM5.UINT8[LL/LH/HL/HH]
RCFDC0.CFDGAFLP0_5.UINT32
RCFDC0.CFDGAFLP0_5.UINT16[L/H]
RCFDC0.CFDGAFLP0_5.UINT8[LL/LH/HL/HH]
RCFDC0.CFDGAFLP1_5.UINT32
RCFDC0.CFDGAFLP1_5.UINT16[L]
RCFDC0.CFDGAFLP1_5.UINT8[LL/LH]
RCFDC0.CFDGAFLID6.UINT32
RCFDC0.CFDGAFLID6.UINT16[L/H]
RCFDC0.CFDGAFLID6.UINT8[LL/LH/HL/HH]
RCFDC0.CFDGAFLM6.UINT32
RCFDC0.CFDGAFLM6.UINT16[L/H]
RCFDC0.CFDGAFLM6.UINT8[LL/LH/HL/HH]
RCFDC0.CFDGAFLP0_6.UINT32
RCFDC0.CFDGAFLP0_6.UINT16[L/H]
RCFDC0.CFDGAFLP0_6.UINT8[LL/LH/HL/HH]
RCFDC0.CFDGAFLP1_6.UINT32
RCFDC0.CFDGAFLP1_6.UINT16[L]
RCFDC0.CFDGAFLP1_6.UINT8[LL/LH]
RCFDC0.CFDGAFLID7.UINT32
RCFDC0.CFDGAFLID7.UINT16[L/H]
RCFDC0.CFDGAFLID7.UINT8[LL/LH/HL/HH]
RCFDC0.CFDGAFLM7.UINT32
RCFDC0.CFDGAFLM7.UINT16[L/H]
RCFDC0.CFDGAFLM7.UINT8[LL/LH/HL/HH]
RCFDC0.CFDGAFLP0_7.UINT32
RCFDC0.CFDGAFLP0_7.UINT16[L/H]
RCFDC0.CFDGAFLP0_7.UINT8[LL/LH/HL/HH]
RCFDC0.CFDGAFLP1_7.UINT32
RCFDC0.CFDGAFLP1_7.UINT16[L]
RCFDC0.CFDGAFLP1_7.UINT8[LL/LH]
RCFDC0.CFDGAFLID8.UINT32
RCFDC0.CFDGAFLID8.UINT16[L/H]
RCFDC0.CFDGAFLID8.UINT8[LL/LH/HL/HH]
RCFDC0.CFDGAFLM8.UINT32
RCFDC0.CFDGAFLM8.UINT16[L/H]
RCFDC0.CFDGAFLM8.UINT8[LL/LH/HL/HH]
RCFDC0.CFDGAFLP0_8.UINT32
RCFDC0.CFDGAFLP0_8.UINT16[L/H]
RCFDC0.CFDGAFLP0_8.UINT8[LL/LH/HL/HH]
RCFDC0.CFDGAFLP1_8.UINT32
RCFDC0.CFDGAFLP1_8.UINT16[L]
RCFDC0.CFDGAFLP1_8.UINT8[LL/LH]
RCFDC0.CFDGAFLID9.UINT32
RCFDC0.CFDGAFLID9.UINT16[L/H]
RCFDC0.CFDGAFLID9.UINT8[LL/LH/HL/HH]
RCFDC0.CFDGAFLM9.UINT32
RCFDC0.CFDGAFLM9.UINT16[L/H]
RCFDC0.CFDGAFLM9.UINT8[LL/LH/HL/HH]
RCFDC0.CFDGAFLP0_9.UINT32
RCFDC0.CFDGAFLP0_9.UINT16[L/H]
RCFDC0.CFDGAFLP0_9.UINT8[LL/LH/HL/HH]
RCFDC0.CFDGAFLP1_9.UINT32
RCFDC0.CFDGAFLP1_9.UINT16[L]
RCFDC0.CFDGAFLP1_9.UINT8[LL/LH]
RCFDC0.CFDGAFLID10.UINT32
RCFDC0.CFDGAFLID10.UINT16[L/H]
RCFDC0.CFDGAFLID10.UINT8[LL/LH/HL/HH]
RCFDC0.CFDGAFLM10.UINT32
RCFDC0.CFDGAFLM10.UINT16[L/H]
RCFDC0.CFDGAFLM10.UINT8[LL/LH/HL/HH]
RCFDC0.CFDGAFLP0_10.UINT32
RCFDC0.CFDGAFLP0_10.UINT16[L/H]
RCFDC0.CFDGAFLP0_10.UINT8[LL/LH/HL/HH]
RCFDC0.CFDGAFLP1_10.UINT32
RCFDC0.CFDGAFLP1_10.UINT16[L]
RCFDC0.CFDGAFLP1_10.UINT8[LL/LH]
RCFDC0.CFDGAFLID11.UINT32
RCFDC0.CFDGAFLID11.UINT16[L/H]
RCFDC0.CFDGAFLID11.UINT8[LL/LH/HL/HH]
RCFDC0.CFDGAFLM11.UINT32
RCFDC0.CFDGAFLM11.UINT16[L/H]
RCFDC0.CFDGAFLM11.UINT8[LL/LH/HL/HH]
RCFDC0.CFDGAFLP0_11.UINT32
RCFDC0.CFDGAFLP0_11.UINT16[L/H]
RCFDC0.CFDGAFLP0_11.UINT8[LL/LH/HL/HH]
RCFDC0.CFDGAFLP1_11.UINT32
RCFDC0.CFDGAFLP1_11.UINT16[L]
RCFDC0.CFDGAFLP1_11.UINT8[LL/LH]
RCFDC0.CFDGAFLID12.UINT32
RCFDC0.CFDGAFLID12.UINT16[L/H]
RCFDC0.CFDGAFLID12.UINT8[LL/LH/HL/HH]
RCFDC0.CFDGAFLM12.UINT32
RCFDC0.CFDGAFLM12.UINT16[L/H]
RCFDC0.CFDGAFLM12.UINT8[LL/LH/HL/HH]
RCFDC0.CFDGAFLP0_12.UINT32
RCFDC0.CFDGAFLP0_12.UINT16[L/H]
RCFDC0.CFDGAFLP0_12.UINT8[LL/LH/HL/HH]
RCFDC0.CFDGAFLP1_12.UINT32
RCFDC0.CFDGAFLP1_12.UINT16[L]
RCFDC0.CFDGAFLP1_12.UINT8[LL/LH]
RCFDC0.CFDGAFLID13.UINT32
RCFDC0.CFDGAFLID13.UINT16[L/H]
RCFDC0.CFDGAFLID13.UINT8[LL/LH/HL/HH]
RCFDC0.CFDGAFLM13.UINT32
RCFDC0.CFDGAFLM13.UINT16[L/H]
RCFDC0.CFDGAFLM13.UINT8[LL/LH/HL/HH]
RCFDC0.CFDGAFLP0_13.UINT32
RCFDC0.CFDGAFLP0_13.UINT16[L/H]
RCFDC0.CFDGAFLP0_13.UINT8[LL/LH/HL/HH]
RCFDC0.CFDGAFLP1_13.UINT32
RCFDC0.CFDGAFLP1_13.UINT16[L]
RCFDC0.CFDGAFLP1_13.UINT8[LL/LH]
RCFDC0.CFDGAFLID14.UINT32
RCFDC0.CFDGAFLID14.UINT16[L/H]
RCFDC0.CFDGAFLID14.UINT8[LL/LH/HL/HH]
RCFDC0.CFDGAFLM14.UINT32
RCFDC0.CFDGAFLM14.UINT16[L/H]
RCFDC0.CFDGAFLM14.UINT8[LL/LH/HL/HH]
RCFDC0.CFDGAFLP0_14.UINT32
RCFDC0.CFDGAFLP0_14.UINT16[L/H]
RCFDC0.CFDGAFLP0_14.UINT8[LL/LH/HL/HH]
RCFDC0.CFDGAFLP1_14.UINT32
RCFDC0.CFDGAFLP1_14.UINT16[L]
RCFDC0.CFDGAFLP1_14.UINT8[LL/LH]
RCFDC0.CFDGAFLID15.UINT32
RCFDC0.CFDGAFLID15.UINT16[L/H]
RCFDC0.CFDGAFLID15.UINT8[LL/LH/HL/HH]
RCFDC0.CFDGAFLM15.UINT32
RCFDC0.CFDGAFLM15.UINT16[L/H]
RCFDC0.CFDGAFLM15.UINT8[LL/LH/HL/HH]
RCFDC0.CFDGAFLP0_15.UINT32
RCFDC0.CFDGAFLP0_15.UINT16[L/H]
RCFDC0.CFDGAFLP0_15.UINT8[LL/LH/HL/HH]
RCFDC0.CFDGAFLP1_15.UINT32
RCFDC0.CFDGAFLP1_15.UINT16[L]
RCFDC0.CFDGAFLP1_15.UINT8[LL/LH]
RCFDC0.CFDRMID0.UINT32
RCFDC0.CFDRMID0.UINT16[L/H]
RCFDC0.CFDRMID0.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMPTR0.UINT32
RCFDC0.CFDRMPTR0.UINT16[L/H]
RCFDC0.CFDRMPTR0.UINT8[LL/LH/HH]
RCFDC0.CFDRMFDSTS0.UINT32
RCFDC0.CFDRMFDSTS0.UINT16[L/H]
RCFDC0.CFDRMFDSTS0.UINT8[LL/HL/HH]
RCFDC0.CFDRMDF0_0.UINT32
RCFDC0.CFDRMDF0_0.UINT16[L/H]
RCFDC0.CFDRMDF0_0.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF1_0.UINT32
RCFDC0.CFDRMDF1_0.UINT16[L/H]
RCFDC0.CFDRMDF1_0.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF2_0.UINT32
RCFDC0.CFDRMDF2_0.UINT16[L/H]
RCFDC0.CFDRMDF2_0.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF3_0.UINT32
RCFDC0.CFDRMDF3_0.UINT16[L/H]
RCFDC0.CFDRMDF3_0.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF4_0.UINT32
RCFDC0.CFDRMDF4_0.UINT16[L/H]
RCFDC0.CFDRMDF4_0.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF5_0.UINT32
RCFDC0.CFDRMDF5_0.UINT16[L/H]
RCFDC0.CFDRMDF5_0.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF6_0.UINT32
RCFDC0.CFDRMDF6_0.UINT16[L/H]
RCFDC0.CFDRMDF6_0.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF7_0.UINT32
RCFDC0.CFDRMDF7_0.UINT16[L/H]
RCFDC0.CFDRMDF7_0.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF8_0.UINT32
RCFDC0.CFDRMDF8_0.UINT16[L/H]
RCFDC0.CFDRMDF8_0.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF9_0.UINT32
RCFDC0.CFDRMDF9_0.UINT16[L/H]
RCFDC0.CFDRMDF9_0.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF10_0.UINT32
RCFDC0.CFDRMDF10_0.UINT16[L/H]
RCFDC0.CFDRMDF10_0.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF11_0.UINT32
RCFDC0.CFDRMDF11_0.UINT16[L/H]
RCFDC0.CFDRMDF11_0.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF12_0.UINT32
RCFDC0.CFDRMDF12_0.UINT16[L/H]
RCFDC0.CFDRMDF12_0.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF13_0.UINT32
RCFDC0.CFDRMDF13_0.UINT16[L/H]
RCFDC0.CFDRMDF13_0.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF14_0.UINT32
RCFDC0.CFDRMDF14_0.UINT16[L/H]
RCFDC0.CFDRMDF14_0.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF15_0.UINT32
RCFDC0.CFDRMDF15_0.UINT16[L/H]
RCFDC0.CFDRMDF15_0.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMID1.UINT32
RCFDC0.CFDRMID1.UINT16[L/H]
RCFDC0.CFDRMID1.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMPTR1.UINT32
RCFDC0.CFDRMPTR1.UINT16[L/H]
RCFDC0.CFDRMPTR1.UINT8[LL/LH/HH]
RCFDC0.CFDRMFDSTS1.UINT32
RCFDC0.CFDRMFDSTS1.UINT16[L/H]
RCFDC0.CFDRMFDSTS1.UINT8[LL/HL/HH]
RCFDC0.CFDRMDF0_1.UINT32
RCFDC0.CFDRMDF0_1.UINT16[L/H]
RCFDC0.CFDRMDF0_1.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF1_1.UINT32
RCFDC0.CFDRMDF1_1.UINT16[L/H]
RCFDC0.CFDRMDF1_1.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF2_1.UINT32
RCFDC0.CFDRMDF2_1.UINT16[L/H]
RCFDC0.CFDRMDF2_1.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF3_1.UINT32
RCFDC0.CFDRMDF3_1.UINT16[L/H]
RCFDC0.CFDRMDF3_1.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF4_1.UINT32
RCFDC0.CFDRMDF4_1.UINT16[L/H]
RCFDC0.CFDRMDF4_1.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF5_1.UINT32
RCFDC0.CFDRMDF5_1.UINT16[L/H]
RCFDC0.CFDRMDF5_1.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF6_1.UINT32
RCFDC0.CFDRMDF6_1.UINT16[L/H]
RCFDC0.CFDRMDF6_1.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF7_1.UINT32
RCFDC0.CFDRMDF7_1.UINT16[L/H]
RCFDC0.CFDRMDF7_1.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF8_1.UINT32
RCFDC0.CFDRMDF8_1.UINT16[L/H]
RCFDC0.CFDRMDF8_1.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF9_1.UINT32
RCFDC0.CFDRMDF9_1.UINT16[L/H]
RCFDC0.CFDRMDF9_1.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF10_1.UINT32
RCFDC0.CFDRMDF10_1.UINT16[L/H]
RCFDC0.CFDRMDF10_1.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF11_1.UINT32
RCFDC0.CFDRMDF11_1.UINT16[L/H]
RCFDC0.CFDRMDF11_1.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF12_1.UINT32
RCFDC0.CFDRMDF12_1.UINT16[L/H]
RCFDC0.CFDRMDF12_1.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF13_1.UINT32
RCFDC0.CFDRMDF13_1.UINT16[L/H]
RCFDC0.CFDRMDF13_1.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF14_1.UINT32
RCFDC0.CFDRMDF14_1.UINT16[L/H]
RCFDC0.CFDRMDF14_1.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF15_1.UINT32
RCFDC0.CFDRMDF15_1.UINT16[L/H]
RCFDC0.CFDRMDF15_1.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMID2.UINT32
RCFDC0.CFDRMID2.UINT16[L/H]
RCFDC0.CFDRMID2.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMPTR2.UINT32
RCFDC0.CFDRMPTR2.UINT16[L/H]
RCFDC0.CFDRMPTR2.UINT8[LL/LH/HH]
RCFDC0.CFDRMFDSTS2.UINT32
RCFDC0.CFDRMFDSTS2.UINT16[L/H]
RCFDC0.CFDRMFDSTS2.UINT8[LL/HL/HH]
RCFDC0.CFDRMDF0_2.UINT32
RCFDC0.CFDRMDF0_2.UINT16[L/H]
RCFDC0.CFDRMDF0_2.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF1_2.UINT32
RCFDC0.CFDRMDF1_2.UINT16[L/H]
RCFDC0.CFDRMDF1_2.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF2_2.UINT32
RCFDC0.CFDRMDF2_2.UINT16[L/H]
RCFDC0.CFDRMDF2_2.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF3_2.UINT32
RCFDC0.CFDRMDF3_2.UINT16[L/H]
RCFDC0.CFDRMDF3_2.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF4_2.UINT32
RCFDC0.CFDRMDF4_2.UINT16[L/H]
RCFDC0.CFDRMDF4_2.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF5_2.UINT32
RCFDC0.CFDRMDF5_2.UINT16[L/H]
RCFDC0.CFDRMDF5_2.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF6_2.UINT32
RCFDC0.CFDRMDF6_2.UINT16[L/H]
RCFDC0.CFDRMDF6_2.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF7_2.UINT32
RCFDC0.CFDRMDF7_2.UINT16[L/H]
RCFDC0.CFDRMDF7_2.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF8_2.UINT32
RCFDC0.CFDRMDF8_2.UINT16[L/H]
RCFDC0.CFDRMDF8_2.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF9_2.UINT32
RCFDC0.CFDRMDF9_2.UINT16[L/H]
RCFDC0.CFDRMDF9_2.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF10_2.UINT32
RCFDC0.CFDRMDF10_2.UINT16[L/H]
RCFDC0.CFDRMDF10_2.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF11_2.UINT32
RCFDC0.CFDRMDF11_2.UINT16[L/H]
RCFDC0.CFDRMDF11_2.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF12_2.UINT32
RCFDC0.CFDRMDF12_2.UINT16[L/H]
RCFDC0.CFDRMDF12_2.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF13_2.UINT32
RCFDC0.CFDRMDF13_2.UINT16[L/H]
RCFDC0.CFDRMDF13_2.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF14_2.UINT32
RCFDC0.CFDRMDF14_2.UINT16[L/H]
RCFDC0.CFDRMDF14_2.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF15_2.UINT32
RCFDC0.CFDRMDF15_2.UINT16[L/H]
RCFDC0.CFDRMDF15_2.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMID3.UINT32
RCFDC0.CFDRMID3.UINT16[L/H]
RCFDC0.CFDRMID3.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMPTR3.UINT32
RCFDC0.CFDRMPTR3.UINT16[L/H]
RCFDC0.CFDRMPTR3.UINT8[LL/LH/HH]
RCFDC0.CFDRMFDSTS3.UINT32
RCFDC0.CFDRMFDSTS3.UINT16[L/H]
RCFDC0.CFDRMFDSTS3.UINT8[LL/HL/HH]
RCFDC0.CFDRMDF0_3.UINT32
RCFDC0.CFDRMDF0_3.UINT16[L/H]
RCFDC0.CFDRMDF0_3.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF1_3.UINT32
RCFDC0.CFDRMDF1_3.UINT16[L/H]
RCFDC0.CFDRMDF1_3.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF2_3.UINT32
RCFDC0.CFDRMDF2_3.UINT16[L/H]
RCFDC0.CFDRMDF2_3.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF3_3.UINT32
RCFDC0.CFDRMDF3_3.UINT16[L/H]
RCFDC0.CFDRMDF3_3.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF4_3.UINT32
RCFDC0.CFDRMDF4_3.UINT16[L/H]
RCFDC0.CFDRMDF4_3.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF5_3.UINT32
RCFDC0.CFDRMDF5_3.UINT16[L/H]
RCFDC0.CFDRMDF5_3.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF6_3.UINT32
RCFDC0.CFDRMDF6_3.UINT16[L/H]
RCFDC0.CFDRMDF6_3.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF7_3.UINT32
RCFDC0.CFDRMDF7_3.UINT16[L/H]
RCFDC0.CFDRMDF7_3.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF8_3.UINT32
RCFDC0.CFDRMDF8_3.UINT16[L/H]
RCFDC0.CFDRMDF8_3.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF9_3.UINT32
RCFDC0.CFDRMDF9_3.UINT16[L/H]
RCFDC0.CFDRMDF9_3.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF10_3.UINT32
RCFDC0.CFDRMDF10_3.UINT16[L/H]
RCFDC0.CFDRMDF10_3.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF11_3.UINT32
RCFDC0.CFDRMDF11_3.UINT16[L/H]
RCFDC0.CFDRMDF11_3.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF12_3.UINT32
RCFDC0.CFDRMDF12_3.UINT16[L/H]
RCFDC0.CFDRMDF12_3.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF13_3.UINT32
RCFDC0.CFDRMDF13_3.UINT16[L/H]
RCFDC0.CFDRMDF13_3.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF14_3.UINT32
RCFDC0.CFDRMDF14_3.UINT16[L/H]
RCFDC0.CFDRMDF14_3.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF15_3.UINT32
RCFDC0.CFDRMDF15_3.UINT16[L/H]
RCFDC0.CFDRMDF15_3.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMID4.UINT32
RCFDC0.CFDRMID4.UINT16[L/H]
RCFDC0.CFDRMID4.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMPTR4.UINT32
RCFDC0.CFDRMPTR4.UINT16[L/H]
RCFDC0.CFDRMPTR4.UINT8[LL/LH/HH]
RCFDC0.CFDRMFDSTS4.UINT32
RCFDC0.CFDRMFDSTS4.UINT16[L/H]
RCFDC0.CFDRMFDSTS4.UINT8[LL/HL/HH]
RCFDC0.CFDRMDF0_4.UINT32
RCFDC0.CFDRMDF0_4.UINT16[L/H]
RCFDC0.CFDRMDF0_4.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF1_4.UINT32
RCFDC0.CFDRMDF1_4.UINT16[L/H]
RCFDC0.CFDRMDF1_4.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF2_4.UINT32
RCFDC0.CFDRMDF2_4.UINT16[L/H]
RCFDC0.CFDRMDF2_4.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF3_4.UINT32
RCFDC0.CFDRMDF3_4.UINT16[L/H]
RCFDC0.CFDRMDF3_4.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF4_4.UINT32
RCFDC0.CFDRMDF4_4.UINT16[L/H]
RCFDC0.CFDRMDF4_4.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF5_4.UINT32
RCFDC0.CFDRMDF5_4.UINT16[L/H]
RCFDC0.CFDRMDF5_4.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF6_4.UINT32
RCFDC0.CFDRMDF6_4.UINT16[L/H]
RCFDC0.CFDRMDF6_4.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF7_4.UINT32
RCFDC0.CFDRMDF7_4.UINT16[L/H]
RCFDC0.CFDRMDF7_4.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF8_4.UINT32
RCFDC0.CFDRMDF8_4.UINT16[L/H]
RCFDC0.CFDRMDF8_4.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF9_4.UINT32
RCFDC0.CFDRMDF9_4.UINT16[L/H]
RCFDC0.CFDRMDF9_4.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF10_4.UINT32
RCFDC0.CFDRMDF10_4.UINT16[L/H]
RCFDC0.CFDRMDF10_4.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF11_4.UINT32
RCFDC0.CFDRMDF11_4.UINT16[L/H]
RCFDC0.CFDRMDF11_4.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF12_4.UINT32
RCFDC0.CFDRMDF12_4.UINT16[L/H]
RCFDC0.CFDRMDF12_4.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF13_4.UINT32
RCFDC0.CFDRMDF13_4.UINT16[L/H]
RCFDC0.CFDRMDF13_4.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF14_4.UINT32
RCFDC0.CFDRMDF14_4.UINT16[L/H]
RCFDC0.CFDRMDF14_4.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF15_4.UINT32
RCFDC0.CFDRMDF15_4.UINT16[L/H]
RCFDC0.CFDRMDF15_4.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMID5.UINT32
RCFDC0.CFDRMID5.UINT16[L/H]
RCFDC0.CFDRMID5.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMPTR5.UINT32
RCFDC0.CFDRMPTR5.UINT16[L/H]
RCFDC0.CFDRMPTR5.UINT8[LL/LH/HH]
RCFDC0.CFDRMFDSTS5.UINT32
RCFDC0.CFDRMFDSTS5.UINT16[L/H]
RCFDC0.CFDRMFDSTS5.UINT8[LL/HL/HH]
RCFDC0.CFDRMDF0_5.UINT32
RCFDC0.CFDRMDF0_5.UINT16[L/H]
RCFDC0.CFDRMDF0_5.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF1_5.UINT32
RCFDC0.CFDRMDF1_5.UINT16[L/H]
RCFDC0.CFDRMDF1_5.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF2_5.UINT32
RCFDC0.CFDRMDF2_5.UINT16[L/H]
RCFDC0.CFDRMDF2_5.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF3_5.UINT32
RCFDC0.CFDRMDF3_5.UINT16[L/H]
RCFDC0.CFDRMDF3_5.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF4_5.UINT32
RCFDC0.CFDRMDF4_5.UINT16[L/H]
RCFDC0.CFDRMDF4_5.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF5_5.UINT32
RCFDC0.CFDRMDF5_5.UINT16[L/H]
RCFDC0.CFDRMDF5_5.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF6_5.UINT32
RCFDC0.CFDRMDF6_5.UINT16[L/H]
RCFDC0.CFDRMDF6_5.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF7_5.UINT32
RCFDC0.CFDRMDF7_5.UINT16[L/H]
RCFDC0.CFDRMDF7_5.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF8_5.UINT32
RCFDC0.CFDRMDF8_5.UINT16[L/H]
RCFDC0.CFDRMDF8_5.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF9_5.UINT32
RCFDC0.CFDRMDF9_5.UINT16[L/H]
RCFDC0.CFDRMDF9_5.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF10_5.UINT32
RCFDC0.CFDRMDF10_5.UINT16[L/H]
RCFDC0.CFDRMDF10_5.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF11_5.UINT32
RCFDC0.CFDRMDF11_5.UINT16[L/H]
RCFDC0.CFDRMDF11_5.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF12_5.UINT32
RCFDC0.CFDRMDF12_5.UINT16[L/H]
RCFDC0.CFDRMDF12_5.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF13_5.UINT32
RCFDC0.CFDRMDF13_5.UINT16[L/H]
RCFDC0.CFDRMDF13_5.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF14_5.UINT32
RCFDC0.CFDRMDF14_5.UINT16[L/H]
RCFDC0.CFDRMDF14_5.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF15_5.UINT32
RCFDC0.CFDRMDF15_5.UINT16[L/H]
RCFDC0.CFDRMDF15_5.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMID6.UINT32
RCFDC0.CFDRMID6.UINT16[L/H]
RCFDC0.CFDRMID6.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMPTR6.UINT32
RCFDC0.CFDRMPTR6.UINT16[L/H]
RCFDC0.CFDRMPTR6.UINT8[LL/LH/HH]
RCFDC0.CFDRMFDSTS6.UINT32
RCFDC0.CFDRMFDSTS6.UINT16[L/H]
RCFDC0.CFDRMFDSTS6.UINT8[LL/HL/HH]
RCFDC0.CFDRMDF0_6.UINT32
RCFDC0.CFDRMDF0_6.UINT16[L/H]
RCFDC0.CFDRMDF0_6.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF1_6.UINT32
RCFDC0.CFDRMDF1_6.UINT16[L/H]
RCFDC0.CFDRMDF1_6.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF2_6.UINT32
RCFDC0.CFDRMDF2_6.UINT16[L/H]
RCFDC0.CFDRMDF2_6.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF3_6.UINT32
RCFDC0.CFDRMDF3_6.UINT16[L/H]
RCFDC0.CFDRMDF3_6.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF4_6.UINT32
RCFDC0.CFDRMDF4_6.UINT16[L/H]
RCFDC0.CFDRMDF4_6.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF5_6.UINT32
RCFDC0.CFDRMDF5_6.UINT16[L/H]
RCFDC0.CFDRMDF5_6.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF6_6.UINT32
RCFDC0.CFDRMDF6_6.UINT16[L/H]
RCFDC0.CFDRMDF6_6.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF7_6.UINT32
RCFDC0.CFDRMDF7_6.UINT16[L/H]
RCFDC0.CFDRMDF7_6.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF8_6.UINT32
RCFDC0.CFDRMDF8_6.UINT16[L/H]
RCFDC0.CFDRMDF8_6.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF9_6.UINT32
RCFDC0.CFDRMDF9_6.UINT16[L/H]
RCFDC0.CFDRMDF9_6.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF10_6.UINT32
RCFDC0.CFDRMDF10_6.UINT16[L/H]
RCFDC0.CFDRMDF10_6.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF11_6.UINT32
RCFDC0.CFDRMDF11_6.UINT16[L/H]
RCFDC0.CFDRMDF11_6.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF12_6.UINT32
RCFDC0.CFDRMDF12_6.UINT16[L/H]
RCFDC0.CFDRMDF12_6.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF13_6.UINT32
RCFDC0.CFDRMDF13_6.UINT16[L/H]
RCFDC0.CFDRMDF13_6.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF14_6.UINT32
RCFDC0.CFDRMDF14_6.UINT16[L/H]
RCFDC0.CFDRMDF14_6.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF15_6.UINT32
RCFDC0.CFDRMDF15_6.UINT16[L/H]
RCFDC0.CFDRMDF15_6.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMID7.UINT32
RCFDC0.CFDRMID7.UINT16[L/H]
RCFDC0.CFDRMID7.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMPTR7.UINT32
RCFDC0.CFDRMPTR7.UINT16[L/H]
RCFDC0.CFDRMPTR7.UINT8[LL/LH/HH]
RCFDC0.CFDRMFDSTS7.UINT32
RCFDC0.CFDRMFDSTS7.UINT16[L/H]
RCFDC0.CFDRMFDSTS7.UINT8[LL/HL/HH]
RCFDC0.CFDRMDF0_7.UINT32
RCFDC0.CFDRMDF0_7.UINT16[L/H]
RCFDC0.CFDRMDF0_7.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF1_7.UINT32
RCFDC0.CFDRMDF1_7.UINT16[L/H]
RCFDC0.CFDRMDF1_7.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF2_7.UINT32
RCFDC0.CFDRMDF2_7.UINT16[L/H]
RCFDC0.CFDRMDF2_7.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF3_7.UINT32
RCFDC0.CFDRMDF3_7.UINT16[L/H]
RCFDC0.CFDRMDF3_7.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF4_7.UINT32
RCFDC0.CFDRMDF4_7.UINT16[L/H]
RCFDC0.CFDRMDF4_7.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF5_7.UINT32
RCFDC0.CFDRMDF5_7.UINT16[L/H]
RCFDC0.CFDRMDF5_7.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF6_7.UINT32
RCFDC0.CFDRMDF6_7.UINT16[L/H]
RCFDC0.CFDRMDF6_7.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF7_7.UINT32
RCFDC0.CFDRMDF7_7.UINT16[L/H]
RCFDC0.CFDRMDF7_7.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF8_7.UINT32
RCFDC0.CFDRMDF8_7.UINT16[L/H]
RCFDC0.CFDRMDF8_7.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF9_7.UINT32
RCFDC0.CFDRMDF9_7.UINT16[L/H]
RCFDC0.CFDRMDF9_7.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF10_7.UINT32
RCFDC0.CFDRMDF10_7.UINT16[L/H]
RCFDC0.CFDRMDF10_7.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF11_7.UINT32
RCFDC0.CFDRMDF11_7.UINT16[L/H]
RCFDC0.CFDRMDF11_7.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF12_7.UINT32
RCFDC0.CFDRMDF12_7.UINT16[L/H]
RCFDC0.CFDRMDF12_7.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF13_7.UINT32
RCFDC0.CFDRMDF13_7.UINT16[L/H]
RCFDC0.CFDRMDF13_7.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF14_7.UINT32
RCFDC0.CFDRMDF14_7.UINT16[L/H]
RCFDC0.CFDRMDF14_7.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF15_7.UINT32
RCFDC0.CFDRMDF15_7.UINT16[L/H]
RCFDC0.CFDRMDF15_7.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMID8.UINT32
RCFDC0.CFDRMID8.UINT16[L/H]
RCFDC0.CFDRMID8.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMPTR8.UINT32
RCFDC0.CFDRMPTR8.UINT16[L/H]
RCFDC0.CFDRMPTR8.UINT8[LL/LH/HH]
RCFDC0.CFDRMFDSTS8.UINT32
RCFDC0.CFDRMFDSTS8.UINT16[L/H]
RCFDC0.CFDRMFDSTS8.UINT8[LL/HL/HH]
RCFDC0.CFDRMDF0_8.UINT32
RCFDC0.CFDRMDF0_8.UINT16[L/H]
RCFDC0.CFDRMDF0_8.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF1_8.UINT32
RCFDC0.CFDRMDF1_8.UINT16[L/H]
RCFDC0.CFDRMDF1_8.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF2_8.UINT32
RCFDC0.CFDRMDF2_8.UINT16[L/H]
RCFDC0.CFDRMDF2_8.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF3_8.UINT32
RCFDC0.CFDRMDF3_8.UINT16[L/H]
RCFDC0.CFDRMDF3_8.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF4_8.UINT32
RCFDC0.CFDRMDF4_8.UINT16[L/H]
RCFDC0.CFDRMDF4_8.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF5_8.UINT32
RCFDC0.CFDRMDF5_8.UINT16[L/H]
RCFDC0.CFDRMDF5_8.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF6_8.UINT32
RCFDC0.CFDRMDF6_8.UINT16[L/H]
RCFDC0.CFDRMDF6_8.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF7_8.UINT32
RCFDC0.CFDRMDF7_8.UINT16[L/H]
RCFDC0.CFDRMDF7_8.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF8_8.UINT32
RCFDC0.CFDRMDF8_8.UINT16[L/H]
RCFDC0.CFDRMDF8_8.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF9_8.UINT32
RCFDC0.CFDRMDF9_8.UINT16[L/H]
RCFDC0.CFDRMDF9_8.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF10_8.UINT32
RCFDC0.CFDRMDF10_8.UINT16[L/H]
RCFDC0.CFDRMDF10_8.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF11_8.UINT32
RCFDC0.CFDRMDF11_8.UINT16[L/H]
RCFDC0.CFDRMDF11_8.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF12_8.UINT32
RCFDC0.CFDRMDF12_8.UINT16[L/H]
RCFDC0.CFDRMDF12_8.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF13_8.UINT32
RCFDC0.CFDRMDF13_8.UINT16[L/H]
RCFDC0.CFDRMDF13_8.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF14_8.UINT32
RCFDC0.CFDRMDF14_8.UINT16[L/H]
RCFDC0.CFDRMDF14_8.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF15_8.UINT32
RCFDC0.CFDRMDF15_8.UINT16[L/H]
RCFDC0.CFDRMDF15_8.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMID9.UINT32
RCFDC0.CFDRMID9.UINT16[L/H]
RCFDC0.CFDRMID9.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMPTR9.UINT32
RCFDC0.CFDRMPTR9.UINT16[L/H]
RCFDC0.CFDRMPTR9.UINT8[LL/LH/HH]
RCFDC0.CFDRMFDSTS9.UINT32
RCFDC0.CFDRMFDSTS9.UINT16[L/H]
RCFDC0.CFDRMFDSTS9.UINT8[LL/HL/HH]
RCFDC0.CFDRMDF0_9.UINT32
RCFDC0.CFDRMDF0_9.UINT16[L/H]
RCFDC0.CFDRMDF0_9.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF1_9.UINT32
RCFDC0.CFDRMDF1_9.UINT16[L/H]
RCFDC0.CFDRMDF1_9.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF2_9.UINT32
RCFDC0.CFDRMDF2_9.UINT16[L/H]
RCFDC0.CFDRMDF2_9.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF3_9.UINT32
RCFDC0.CFDRMDF3_9.UINT16[L/H]
RCFDC0.CFDRMDF3_9.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF4_9.UINT32
RCFDC0.CFDRMDF4_9.UINT16[L/H]
RCFDC0.CFDRMDF4_9.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF5_9.UINT32
RCFDC0.CFDRMDF5_9.UINT16[L/H]
RCFDC0.CFDRMDF5_9.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF6_9.UINT32
RCFDC0.CFDRMDF6_9.UINT16[L/H]
RCFDC0.CFDRMDF6_9.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF7_9.UINT32
RCFDC0.CFDRMDF7_9.UINT16[L/H]
RCFDC0.CFDRMDF7_9.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF8_9.UINT32
RCFDC0.CFDRMDF8_9.UINT16[L/H]
RCFDC0.CFDRMDF8_9.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF9_9.UINT32
RCFDC0.CFDRMDF9_9.UINT16[L/H]
RCFDC0.CFDRMDF9_9.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF10_9.UINT32
RCFDC0.CFDRMDF10_9.UINT16[L/H]
RCFDC0.CFDRMDF10_9.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF11_9.UINT32
RCFDC0.CFDRMDF11_9.UINT16[L/H]
RCFDC0.CFDRMDF11_9.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF12_9.UINT32
RCFDC0.CFDRMDF12_9.UINT16[L/H]
RCFDC0.CFDRMDF12_9.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF13_9.UINT32
RCFDC0.CFDRMDF13_9.UINT16[L/H]
RCFDC0.CFDRMDF13_9.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF14_9.UINT32
RCFDC0.CFDRMDF14_9.UINT16[L/H]
RCFDC0.CFDRMDF14_9.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF15_9.UINT32
RCFDC0.CFDRMDF15_9.UINT16[L/H]
RCFDC0.CFDRMDF15_9.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMID10.UINT32
RCFDC0.CFDRMID10.UINT16[L/H]
RCFDC0.CFDRMID10.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMPTR10.UINT32
RCFDC0.CFDRMPTR10.UINT16[L/H]
RCFDC0.CFDRMPTR10.UINT8[LL/LH/HH]
RCFDC0.CFDRMFDSTS10.UINT32
RCFDC0.CFDRMFDSTS10.UINT16[L/H]
RCFDC0.CFDRMFDSTS10.UINT8[LL/HL/HH]
RCFDC0.CFDRMDF0_10.UINT32
RCFDC0.CFDRMDF0_10.UINT16[L/H]
RCFDC0.CFDRMDF0_10.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF1_10.UINT32
RCFDC0.CFDRMDF1_10.UINT16[L/H]
RCFDC0.CFDRMDF1_10.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF2_10.UINT32
RCFDC0.CFDRMDF2_10.UINT16[L/H]
RCFDC0.CFDRMDF2_10.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF3_10.UINT32
RCFDC0.CFDRMDF3_10.UINT16[L/H]
RCFDC0.CFDRMDF3_10.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF4_10.UINT32
RCFDC0.CFDRMDF4_10.UINT16[L/H]
RCFDC0.CFDRMDF4_10.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF5_10.UINT32
RCFDC0.CFDRMDF5_10.UINT16[L/H]
RCFDC0.CFDRMDF5_10.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF6_10.UINT32
RCFDC0.CFDRMDF6_10.UINT16[L/H]
RCFDC0.CFDRMDF6_10.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF7_10.UINT32
RCFDC0.CFDRMDF7_10.UINT16[L/H]
RCFDC0.CFDRMDF7_10.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF8_10.UINT32
RCFDC0.CFDRMDF8_10.UINT16[L/H]
RCFDC0.CFDRMDF8_10.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF9_10.UINT32
RCFDC0.CFDRMDF9_10.UINT16[L/H]
RCFDC0.CFDRMDF9_10.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF10_10.UINT32
RCFDC0.CFDRMDF10_10.UINT16[L/H]
RCFDC0.CFDRMDF10_10.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF11_10.UINT32
RCFDC0.CFDRMDF11_10.UINT16[L/H]
RCFDC0.CFDRMDF11_10.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF12_10.UINT32
RCFDC0.CFDRMDF12_10.UINT16[L/H]
RCFDC0.CFDRMDF12_10.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF13_10.UINT32
RCFDC0.CFDRMDF13_10.UINT16[L/H]
RCFDC0.CFDRMDF13_10.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF14_10.UINT32
RCFDC0.CFDRMDF14_10.UINT16[L/H]
RCFDC0.CFDRMDF14_10.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF15_10.UINT32
RCFDC0.CFDRMDF15_10.UINT16[L/H]
RCFDC0.CFDRMDF15_10.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMID11.UINT32
RCFDC0.CFDRMID11.UINT16[L/H]
RCFDC0.CFDRMID11.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMPTR11.UINT32
RCFDC0.CFDRMPTR11.UINT16[L/H]
RCFDC0.CFDRMPTR11.UINT8[LL/LH/HH]
RCFDC0.CFDRMFDSTS11.UINT32
RCFDC0.CFDRMFDSTS11.UINT16[L/H]
RCFDC0.CFDRMFDSTS11.UINT8[LL/HL/HH]
RCFDC0.CFDRMDF0_11.UINT32
RCFDC0.CFDRMDF0_11.UINT16[L/H]
RCFDC0.CFDRMDF0_11.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF1_11.UINT32
RCFDC0.CFDRMDF1_11.UINT16[L/H]
RCFDC0.CFDRMDF1_11.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF2_11.UINT32
RCFDC0.CFDRMDF2_11.UINT16[L/H]
RCFDC0.CFDRMDF2_11.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF3_11.UINT32
RCFDC0.CFDRMDF3_11.UINT16[L/H]
RCFDC0.CFDRMDF3_11.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF4_11.UINT32
RCFDC0.CFDRMDF4_11.UINT16[L/H]
RCFDC0.CFDRMDF4_11.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF5_11.UINT32
RCFDC0.CFDRMDF5_11.UINT16[L/H]
RCFDC0.CFDRMDF5_11.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF6_11.UINT32
RCFDC0.CFDRMDF6_11.UINT16[L/H]
RCFDC0.CFDRMDF6_11.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF7_11.UINT32
RCFDC0.CFDRMDF7_11.UINT16[L/H]
RCFDC0.CFDRMDF7_11.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF8_11.UINT32
RCFDC0.CFDRMDF8_11.UINT16[L/H]
RCFDC0.CFDRMDF8_11.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF9_11.UINT32
RCFDC0.CFDRMDF9_11.UINT16[L/H]
RCFDC0.CFDRMDF9_11.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF10_11.UINT32
RCFDC0.CFDRMDF10_11.UINT16[L/H]
RCFDC0.CFDRMDF10_11.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF11_11.UINT32
RCFDC0.CFDRMDF11_11.UINT16[L/H]
RCFDC0.CFDRMDF11_11.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF12_11.UINT32
RCFDC0.CFDRMDF12_11.UINT16[L/H]
RCFDC0.CFDRMDF12_11.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF13_11.UINT32
RCFDC0.CFDRMDF13_11.UINT16[L/H]
RCFDC0.CFDRMDF13_11.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF14_11.UINT32
RCFDC0.CFDRMDF14_11.UINT16[L/H]
RCFDC0.CFDRMDF14_11.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF15_11.UINT32
RCFDC0.CFDRMDF15_11.UINT16[L/H]
RCFDC0.CFDRMDF15_11.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMID12.UINT32
RCFDC0.CFDRMID12.UINT16[L/H]
RCFDC0.CFDRMID12.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMPTR12.UINT32
RCFDC0.CFDRMPTR12.UINT16[L/H]
RCFDC0.CFDRMPTR12.UINT8[LL/LH/HH]
RCFDC0.CFDRMFDSTS12.UINT32
RCFDC0.CFDRMFDSTS12.UINT16[L/H]
RCFDC0.CFDRMFDSTS12.UINT8[LL/HL/HH]
RCFDC0.CFDRMDF0_12.UINT32
RCFDC0.CFDRMDF0_12.UINT16[L/H]
RCFDC0.CFDRMDF0_12.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF1_12.UINT32
RCFDC0.CFDRMDF1_12.UINT16[L/H]
RCFDC0.CFDRMDF1_12.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF2_12.UINT32
RCFDC0.CFDRMDF2_12.UINT16[L/H]
RCFDC0.CFDRMDF2_12.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF3_12.UINT32
RCFDC0.CFDRMDF3_12.UINT16[L/H]
RCFDC0.CFDRMDF3_12.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF4_12.UINT32
RCFDC0.CFDRMDF4_12.UINT16[L/H]
RCFDC0.CFDRMDF4_12.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF5_12.UINT32
RCFDC0.CFDRMDF5_12.UINT16[L/H]
RCFDC0.CFDRMDF5_12.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF6_12.UINT32
RCFDC0.CFDRMDF6_12.UINT16[L/H]
RCFDC0.CFDRMDF6_12.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF7_12.UINT32
RCFDC0.CFDRMDF7_12.UINT16[L/H]
RCFDC0.CFDRMDF7_12.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF8_12.UINT32
RCFDC0.CFDRMDF8_12.UINT16[L/H]
RCFDC0.CFDRMDF8_12.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF9_12.UINT32
RCFDC0.CFDRMDF9_12.UINT16[L/H]
RCFDC0.CFDRMDF9_12.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF10_12.UINT32
RCFDC0.CFDRMDF10_12.UINT16[L/H]
RCFDC0.CFDRMDF10_12.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF11_12.UINT32
RCFDC0.CFDRMDF11_12.UINT16[L/H]
RCFDC0.CFDRMDF11_12.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF12_12.UINT32
RCFDC0.CFDRMDF12_12.UINT16[L/H]
RCFDC0.CFDRMDF12_12.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF13_12.UINT32
RCFDC0.CFDRMDF13_12.UINT16[L/H]
RCFDC0.CFDRMDF13_12.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF14_12.UINT32
RCFDC0.CFDRMDF14_12.UINT16[L/H]
RCFDC0.CFDRMDF14_12.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF15_12.UINT32
RCFDC0.CFDRMDF15_12.UINT16[L/H]
RCFDC0.CFDRMDF15_12.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMID13.UINT32
RCFDC0.CFDRMID13.UINT16[L/H]
RCFDC0.CFDRMID13.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMPTR13.UINT32
RCFDC0.CFDRMPTR13.UINT16[L/H]
RCFDC0.CFDRMPTR13.UINT8[LL/LH/HH]
RCFDC0.CFDRMFDSTS13.UINT32
RCFDC0.CFDRMFDSTS13.UINT16[L/H]
RCFDC0.CFDRMFDSTS13.UINT8[LL/HL/HH]
RCFDC0.CFDRMDF0_13.UINT32
RCFDC0.CFDRMDF0_13.UINT16[L/H]
RCFDC0.CFDRMDF0_13.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF1_13.UINT32
RCFDC0.CFDRMDF1_13.UINT16[L/H]
RCFDC0.CFDRMDF1_13.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF2_13.UINT32
RCFDC0.CFDRMDF2_13.UINT16[L/H]
RCFDC0.CFDRMDF2_13.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF3_13.UINT32
RCFDC0.CFDRMDF3_13.UINT16[L/H]
RCFDC0.CFDRMDF3_13.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF4_13.UINT32
RCFDC0.CFDRMDF4_13.UINT16[L/H]
RCFDC0.CFDRMDF4_13.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF5_13.UINT32
RCFDC0.CFDRMDF5_13.UINT16[L/H]
RCFDC0.CFDRMDF5_13.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF6_13.UINT32
RCFDC0.CFDRMDF6_13.UINT16[L/H]
RCFDC0.CFDRMDF6_13.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF7_13.UINT32
RCFDC0.CFDRMDF7_13.UINT16[L/H]
RCFDC0.CFDRMDF7_13.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF8_13.UINT32
RCFDC0.CFDRMDF8_13.UINT16[L/H]
RCFDC0.CFDRMDF8_13.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF9_13.UINT32
RCFDC0.CFDRMDF9_13.UINT16[L/H]
RCFDC0.CFDRMDF9_13.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF10_13.UINT32
RCFDC0.CFDRMDF10_13.UINT16[L/H]
RCFDC0.CFDRMDF10_13.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF11_13.UINT32
RCFDC0.CFDRMDF11_13.UINT16[L/H]
RCFDC0.CFDRMDF11_13.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF12_13.UINT32
RCFDC0.CFDRMDF12_13.UINT16[L/H]
RCFDC0.CFDRMDF12_13.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF13_13.UINT32
RCFDC0.CFDRMDF13_13.UINT16[L/H]
RCFDC0.CFDRMDF13_13.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF14_13.UINT32
RCFDC0.CFDRMDF14_13.UINT16[L/H]
RCFDC0.CFDRMDF14_13.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF15_13.UINT32
RCFDC0.CFDRMDF15_13.UINT16[L/H]
RCFDC0.CFDRMDF15_13.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMID14.UINT32
RCFDC0.CFDRMID14.UINT16[L/H]
RCFDC0.CFDRMID14.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMPTR14.UINT32
RCFDC0.CFDRMPTR14.UINT16[L/H]
RCFDC0.CFDRMPTR14.UINT8[LL/LH/HH]
RCFDC0.CFDRMFDSTS14.UINT32
RCFDC0.CFDRMFDSTS14.UINT16[L/H]
RCFDC0.CFDRMFDSTS14.UINT8[LL/HL/HH]
RCFDC0.CFDRMDF0_14.UINT32
RCFDC0.CFDRMDF0_14.UINT16[L/H]
RCFDC0.CFDRMDF0_14.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF1_14.UINT32
RCFDC0.CFDRMDF1_14.UINT16[L/H]
RCFDC0.CFDRMDF1_14.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF2_14.UINT32
RCFDC0.CFDRMDF2_14.UINT16[L/H]
RCFDC0.CFDRMDF2_14.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF3_14.UINT32
RCFDC0.CFDRMDF3_14.UINT16[L/H]
RCFDC0.CFDRMDF3_14.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF4_14.UINT32
RCFDC0.CFDRMDF4_14.UINT16[L/H]
RCFDC0.CFDRMDF4_14.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF5_14.UINT32
RCFDC0.CFDRMDF5_14.UINT16[L/H]
RCFDC0.CFDRMDF5_14.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF6_14.UINT32
RCFDC0.CFDRMDF6_14.UINT16[L/H]
RCFDC0.CFDRMDF6_14.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF7_14.UINT32
RCFDC0.CFDRMDF7_14.UINT16[L/H]
RCFDC0.CFDRMDF7_14.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF8_14.UINT32
RCFDC0.CFDRMDF8_14.UINT16[L/H]
RCFDC0.CFDRMDF8_14.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF9_14.UINT32
RCFDC0.CFDRMDF9_14.UINT16[L/H]
RCFDC0.CFDRMDF9_14.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF10_14.UINT32
RCFDC0.CFDRMDF10_14.UINT16[L/H]
RCFDC0.CFDRMDF10_14.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF11_14.UINT32
RCFDC0.CFDRMDF11_14.UINT16[L/H]
RCFDC0.CFDRMDF11_14.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF12_14.UINT32
RCFDC0.CFDRMDF12_14.UINT16[L/H]
RCFDC0.CFDRMDF12_14.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF13_14.UINT32
RCFDC0.CFDRMDF13_14.UINT16[L/H]
RCFDC0.CFDRMDF13_14.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF14_14.UINT32
RCFDC0.CFDRMDF14_14.UINT16[L/H]
RCFDC0.CFDRMDF14_14.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF15_14.UINT32
RCFDC0.CFDRMDF15_14.UINT16[L/H]
RCFDC0.CFDRMDF15_14.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMID15.UINT32
RCFDC0.CFDRMID15.UINT16[L/H]
RCFDC0.CFDRMID15.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMPTR15.UINT32
RCFDC0.CFDRMPTR15.UINT16[L/H]
RCFDC0.CFDRMPTR15.UINT8[LL/LH/HH]
RCFDC0.CFDRMFDSTS15.UINT32
RCFDC0.CFDRMFDSTS15.UINT16[L/H]
RCFDC0.CFDRMFDSTS15.UINT8[LL/HL/HH]
RCFDC0.CFDRMDF0_15.UINT32
RCFDC0.CFDRMDF0_15.UINT16[L/H]
RCFDC0.CFDRMDF0_15.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF1_15.UINT32
RCFDC0.CFDRMDF1_15.UINT16[L/H]
RCFDC0.CFDRMDF1_15.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF2_15.UINT32
RCFDC0.CFDRMDF2_15.UINT16[L/H]
RCFDC0.CFDRMDF2_15.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF3_15.UINT32
RCFDC0.CFDRMDF3_15.UINT16[L/H]
RCFDC0.CFDRMDF3_15.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF4_15.UINT32
RCFDC0.CFDRMDF4_15.UINT16[L/H]
RCFDC0.CFDRMDF4_15.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF5_15.UINT32
RCFDC0.CFDRMDF5_15.UINT16[L/H]
RCFDC0.CFDRMDF5_15.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF6_15.UINT32
RCFDC0.CFDRMDF6_15.UINT16[L/H]
RCFDC0.CFDRMDF6_15.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF7_15.UINT32
RCFDC0.CFDRMDF7_15.UINT16[L/H]
RCFDC0.CFDRMDF7_15.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF8_15.UINT32
RCFDC0.CFDRMDF8_15.UINT16[L/H]
RCFDC0.CFDRMDF8_15.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF9_15.UINT32
RCFDC0.CFDRMDF9_15.UINT16[L/H]
RCFDC0.CFDRMDF9_15.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF10_15.UINT32
RCFDC0.CFDRMDF10_15.UINT16[L/H]
RCFDC0.CFDRMDF10_15.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF11_15.UINT32
RCFDC0.CFDRMDF11_15.UINT16[L/H]
RCFDC0.CFDRMDF11_15.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF12_15.UINT32
RCFDC0.CFDRMDF12_15.UINT16[L/H]
RCFDC0.CFDRMDF12_15.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF13_15.UINT32
RCFDC0.CFDRMDF13_15.UINT16[L/H]
RCFDC0.CFDRMDF13_15.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF14_15.UINT32
RCFDC0.CFDRMDF14_15.UINT16[L/H]
RCFDC0.CFDRMDF14_15.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRMDF15_15.UINT32
RCFDC0.CFDRMDF15_15.UINT16[L/H]
RCFDC0.CFDRMDF15_15.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFID0.UINT32
RCFDC0.CFDRFID0.UINT16[L/H]
RCFDC0.CFDRFID0.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFPTR0.UINT32
RCFDC0.CFDRFPTR0.UINT16[L/H]
RCFDC0.CFDRFPTR0.UINT8[LL/LH/HH]
RCFDC0.CFDRFFDSTS0.UINT32
RCFDC0.CFDRFFDSTS0.UINT16[L/H]
RCFDC0.CFDRFFDSTS0.UINT8[LL/HL/HH]
RCFDC0.CFDRFDF0_0.UINT32
RCFDC0.CFDRFDF0_0.UINT16[L/H]
RCFDC0.CFDRFDF0_0.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF1_0.UINT32
RCFDC0.CFDRFDF1_0.UINT16[L/H]
RCFDC0.CFDRFDF1_0.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF2_0.UINT32
RCFDC0.CFDRFDF2_0.UINT16[L/H]
RCFDC0.CFDRFDF2_0.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF3_0.UINT32
RCFDC0.CFDRFDF3_0.UINT16[L/H]
RCFDC0.CFDRFDF3_0.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF4_0.UINT32
RCFDC0.CFDRFDF4_0.UINT16[L/H]
RCFDC0.CFDRFDF4_0.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF5_0.UINT32
RCFDC0.CFDRFDF5_0.UINT16[L/H]
RCFDC0.CFDRFDF5_0.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF6_0.UINT32
RCFDC0.CFDRFDF6_0.UINT16[L/H]
RCFDC0.CFDRFDF6_0.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF7_0.UINT32
RCFDC0.CFDRFDF7_0.UINT16[L/H]
RCFDC0.CFDRFDF7_0.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF8_0.UINT32
RCFDC0.CFDRFDF8_0.UINT16[L/H]
RCFDC0.CFDRFDF8_0.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF9_0.UINT32
RCFDC0.CFDRFDF9_0.UINT16[L/H]
RCFDC0.CFDRFDF9_0.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF10_0.UINT32
RCFDC0.CFDRFDF10_0.UINT16[L/H]
RCFDC0.CFDRFDF10_0.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF11_0.UINT32
RCFDC0.CFDRFDF11_0.UINT16[L/H]
RCFDC0.CFDRFDF11_0.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF12_0.UINT32
RCFDC0.CFDRFDF12_0.UINT16[L/H]
RCFDC0.CFDRFDF12_0.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF13_0.UINT32
RCFDC0.CFDRFDF13_0.UINT16[L/H]
RCFDC0.CFDRFDF13_0.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF14_0.UINT32
RCFDC0.CFDRFDF14_0.UINT16[L/H]
RCFDC0.CFDRFDF14_0.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF15_0.UINT32
RCFDC0.CFDRFDF15_0.UINT16[L/H]
RCFDC0.CFDRFDF15_0.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFID1.UINT32
RCFDC0.CFDRFID1.UINT16[L/H]
RCFDC0.CFDRFID1.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFPTR1.UINT32
RCFDC0.CFDRFPTR1.UINT16[L/H]
RCFDC0.CFDRFPTR1.UINT8[LL/LH/HH]
RCFDC0.CFDRFFDSTS1.UINT32
RCFDC0.CFDRFFDSTS1.UINT16[L/H]
RCFDC0.CFDRFFDSTS1.UINT8[LL/HL/HH]
RCFDC0.CFDRFDF0_1.UINT32
RCFDC0.CFDRFDF0_1.UINT16[L/H]
RCFDC0.CFDRFDF0_1.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF1_1.UINT32
RCFDC0.CFDRFDF1_1.UINT16[L/H]
RCFDC0.CFDRFDF1_1.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF2_1.UINT32
RCFDC0.CFDRFDF2_1.UINT16[L/H]
RCFDC0.CFDRFDF2_1.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF3_1.UINT32
RCFDC0.CFDRFDF3_1.UINT16[L/H]
RCFDC0.CFDRFDF3_1.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF4_1.UINT32
RCFDC0.CFDRFDF4_1.UINT16[L/H]
RCFDC0.CFDRFDF4_1.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF5_1.UINT32
RCFDC0.CFDRFDF5_1.UINT16[L/H]
RCFDC0.CFDRFDF5_1.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF6_1.UINT32
RCFDC0.CFDRFDF6_1.UINT16[L/H]
RCFDC0.CFDRFDF6_1.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF7_1.UINT32
RCFDC0.CFDRFDF7_1.UINT16[L/H]
RCFDC0.CFDRFDF7_1.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF8_1.UINT32
RCFDC0.CFDRFDF8_1.UINT16[L/H]
RCFDC0.CFDRFDF8_1.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF9_1.UINT32
RCFDC0.CFDRFDF9_1.UINT16[L/H]
RCFDC0.CFDRFDF9_1.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF10_1.UINT32
RCFDC0.CFDRFDF10_1.UINT16[L/H]
RCFDC0.CFDRFDF10_1.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF11_1.UINT32
RCFDC0.CFDRFDF11_1.UINT16[L/H]
RCFDC0.CFDRFDF11_1.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF12_1.UINT32
RCFDC0.CFDRFDF12_1.UINT16[L/H]
RCFDC0.CFDRFDF12_1.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF13_1.UINT32
RCFDC0.CFDRFDF13_1.UINT16[L/H]
RCFDC0.CFDRFDF13_1.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF14_1.UINT32
RCFDC0.CFDRFDF14_1.UINT16[L/H]
RCFDC0.CFDRFDF14_1.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF15_1.UINT32
RCFDC0.CFDRFDF15_1.UINT16[L/H]
RCFDC0.CFDRFDF15_1.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFID2.UINT32
RCFDC0.CFDRFID2.UINT16[L/H]
RCFDC0.CFDRFID2.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFPTR2.UINT32
RCFDC0.CFDRFPTR2.UINT16[L/H]
RCFDC0.CFDRFPTR2.UINT8[LL/LH/HH]
RCFDC0.CFDRFFDSTS2.UINT32
RCFDC0.CFDRFFDSTS2.UINT16[L/H]
RCFDC0.CFDRFFDSTS2.UINT8[LL/HL/HH]
RCFDC0.CFDRFDF0_2.UINT32
RCFDC0.CFDRFDF0_2.UINT16[L/H]
RCFDC0.CFDRFDF0_2.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF1_2.UINT32
RCFDC0.CFDRFDF1_2.UINT16[L/H]
RCFDC0.CFDRFDF1_2.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF2_2.UINT32
RCFDC0.CFDRFDF2_2.UINT16[L/H]
RCFDC0.CFDRFDF2_2.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF3_2.UINT32
RCFDC0.CFDRFDF3_2.UINT16[L/H]
RCFDC0.CFDRFDF3_2.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF4_2.UINT32
RCFDC0.CFDRFDF4_2.UINT16[L/H]
RCFDC0.CFDRFDF4_2.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF5_2.UINT32
RCFDC0.CFDRFDF5_2.UINT16[L/H]
RCFDC0.CFDRFDF5_2.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF6_2.UINT32
RCFDC0.CFDRFDF6_2.UINT16[L/H]
RCFDC0.CFDRFDF6_2.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF7_2.UINT32
RCFDC0.CFDRFDF7_2.UINT16[L/H]
RCFDC0.CFDRFDF7_2.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF8_2.UINT32
RCFDC0.CFDRFDF8_2.UINT16[L/H]
RCFDC0.CFDRFDF8_2.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF9_2.UINT32
RCFDC0.CFDRFDF9_2.UINT16[L/H]
RCFDC0.CFDRFDF9_2.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF10_2.UINT32
RCFDC0.CFDRFDF10_2.UINT16[L/H]
RCFDC0.CFDRFDF10_2.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF11_2.UINT32
RCFDC0.CFDRFDF11_2.UINT16[L/H]
RCFDC0.CFDRFDF11_2.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF12_2.UINT32
RCFDC0.CFDRFDF12_2.UINT16[L/H]
RCFDC0.CFDRFDF12_2.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF13_2.UINT32
RCFDC0.CFDRFDF13_2.UINT16[L/H]
RCFDC0.CFDRFDF13_2.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF14_2.UINT32
RCFDC0.CFDRFDF14_2.UINT16[L/H]
RCFDC0.CFDRFDF14_2.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF15_2.UINT32
RCFDC0.CFDRFDF15_2.UINT16[L/H]
RCFDC0.CFDRFDF15_2.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFID3.UINT32
RCFDC0.CFDRFID3.UINT16[L/H]
RCFDC0.CFDRFID3.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFPTR3.UINT32
RCFDC0.CFDRFPTR3.UINT16[L/H]
RCFDC0.CFDRFPTR3.UINT8[LL/LH/HH]
RCFDC0.CFDRFFDSTS3.UINT32
RCFDC0.CFDRFFDSTS3.UINT16[L/H]
RCFDC0.CFDRFFDSTS3.UINT8[LL/HL/HH]
RCFDC0.CFDRFDF0_3.UINT32
RCFDC0.CFDRFDF0_3.UINT16[L/H]
RCFDC0.CFDRFDF0_3.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF1_3.UINT32
RCFDC0.CFDRFDF1_3.UINT16[L/H]
RCFDC0.CFDRFDF1_3.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF2_3.UINT32
RCFDC0.CFDRFDF2_3.UINT16[L/H]
RCFDC0.CFDRFDF2_3.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF3_3.UINT32
RCFDC0.CFDRFDF3_3.UINT16[L/H]
RCFDC0.CFDRFDF3_3.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF4_3.UINT32
RCFDC0.CFDRFDF4_3.UINT16[L/H]
RCFDC0.CFDRFDF4_3.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF5_3.UINT32
RCFDC0.CFDRFDF5_3.UINT16[L/H]
RCFDC0.CFDRFDF5_3.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF6_3.UINT32
RCFDC0.CFDRFDF6_3.UINT16[L/H]
RCFDC0.CFDRFDF6_3.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF7_3.UINT32
RCFDC0.CFDRFDF7_3.UINT16[L/H]
RCFDC0.CFDRFDF7_3.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF8_3.UINT32
RCFDC0.CFDRFDF8_3.UINT16[L/H]
RCFDC0.CFDRFDF8_3.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF9_3.UINT32
RCFDC0.CFDRFDF9_3.UINT16[L/H]
RCFDC0.CFDRFDF9_3.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF10_3.UINT32
RCFDC0.CFDRFDF10_3.UINT16[L/H]
RCFDC0.CFDRFDF10_3.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF11_3.UINT32
RCFDC0.CFDRFDF11_3.UINT16[L/H]
RCFDC0.CFDRFDF11_3.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF12_3.UINT32
RCFDC0.CFDRFDF12_3.UINT16[L/H]
RCFDC0.CFDRFDF12_3.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF13_3.UINT32
RCFDC0.CFDRFDF13_3.UINT16[L/H]
RCFDC0.CFDRFDF13_3.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF14_3.UINT32
RCFDC0.CFDRFDF14_3.UINT16[L/H]
RCFDC0.CFDRFDF14_3.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF15_3.UINT32
RCFDC0.CFDRFDF15_3.UINT16[L/H]
RCFDC0.CFDRFDF15_3.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFID4.UINT32
RCFDC0.CFDRFID4.UINT16[L/H]
RCFDC0.CFDRFID4.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFPTR4.UINT32
RCFDC0.CFDRFPTR4.UINT16[L/H]
RCFDC0.CFDRFPTR4.UINT8[LL/LH/HH]
RCFDC0.CFDRFFDSTS4.UINT32
RCFDC0.CFDRFFDSTS4.UINT16[L/H]
RCFDC0.CFDRFFDSTS4.UINT8[LL/HL/HH]
RCFDC0.CFDRFDF0_4.UINT32
RCFDC0.CFDRFDF0_4.UINT16[L/H]
RCFDC0.CFDRFDF0_4.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF1_4.UINT32
RCFDC0.CFDRFDF1_4.UINT16[L/H]
RCFDC0.CFDRFDF1_4.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF2_4.UINT32
RCFDC0.CFDRFDF2_4.UINT16[L/H]
RCFDC0.CFDRFDF2_4.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF3_4.UINT32
RCFDC0.CFDRFDF3_4.UINT16[L/H]
RCFDC0.CFDRFDF3_4.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF4_4.UINT32
RCFDC0.CFDRFDF4_4.UINT16[L/H]
RCFDC0.CFDRFDF4_4.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF5_4.UINT32
RCFDC0.CFDRFDF5_4.UINT16[L/H]
RCFDC0.CFDRFDF5_4.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF6_4.UINT32
RCFDC0.CFDRFDF6_4.UINT16[L/H]
RCFDC0.CFDRFDF6_4.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF7_4.UINT32
RCFDC0.CFDRFDF7_4.UINT16[L/H]
RCFDC0.CFDRFDF7_4.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF8_4.UINT32
RCFDC0.CFDRFDF8_4.UINT16[L/H]
RCFDC0.CFDRFDF8_4.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF9_4.UINT32
RCFDC0.CFDRFDF9_4.UINT16[L/H]
RCFDC0.CFDRFDF9_4.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF10_4.UINT32
RCFDC0.CFDRFDF10_4.UINT16[L/H]
RCFDC0.CFDRFDF10_4.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF11_4.UINT32
RCFDC0.CFDRFDF11_4.UINT16[L/H]
RCFDC0.CFDRFDF11_4.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF12_4.UINT32
RCFDC0.CFDRFDF12_4.UINT16[L/H]
RCFDC0.CFDRFDF12_4.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF13_4.UINT32
RCFDC0.CFDRFDF13_4.UINT16[L/H]
RCFDC0.CFDRFDF13_4.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF14_4.UINT32
RCFDC0.CFDRFDF14_4.UINT16[L/H]
RCFDC0.CFDRFDF14_4.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF15_4.UINT32
RCFDC0.CFDRFDF15_4.UINT16[L/H]
RCFDC0.CFDRFDF15_4.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFID5.UINT32
RCFDC0.CFDRFID5.UINT16[L/H]
RCFDC0.CFDRFID5.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFPTR5.UINT32
RCFDC0.CFDRFPTR5.UINT16[L/H]
RCFDC0.CFDRFPTR5.UINT8[LL/LH/HH]
RCFDC0.CFDRFFDSTS5.UINT32
RCFDC0.CFDRFFDSTS5.UINT16[L/H]
RCFDC0.CFDRFFDSTS5.UINT8[LL/HL/HH]
RCFDC0.CFDRFDF0_5.UINT32
RCFDC0.CFDRFDF0_5.UINT16[L/H]
RCFDC0.CFDRFDF0_5.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF1_5.UINT32
RCFDC0.CFDRFDF1_5.UINT16[L/H]
RCFDC0.CFDRFDF1_5.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF2_5.UINT32
RCFDC0.CFDRFDF2_5.UINT16[L/H]
RCFDC0.CFDRFDF2_5.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF3_5.UINT32
RCFDC0.CFDRFDF3_5.UINT16[L/H]
RCFDC0.CFDRFDF3_5.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF4_5.UINT32
RCFDC0.CFDRFDF4_5.UINT16[L/H]
RCFDC0.CFDRFDF4_5.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF5_5.UINT32
RCFDC0.CFDRFDF5_5.UINT16[L/H]
RCFDC0.CFDRFDF5_5.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF6_5.UINT32
RCFDC0.CFDRFDF6_5.UINT16[L/H]
RCFDC0.CFDRFDF6_5.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF7_5.UINT32
RCFDC0.CFDRFDF7_5.UINT16[L/H]
RCFDC0.CFDRFDF7_5.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF8_5.UINT32
RCFDC0.CFDRFDF8_5.UINT16[L/H]
RCFDC0.CFDRFDF8_5.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF9_5.UINT32
RCFDC0.CFDRFDF9_5.UINT16[L/H]
RCFDC0.CFDRFDF9_5.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF10_5.UINT32
RCFDC0.CFDRFDF10_5.UINT16[L/H]
RCFDC0.CFDRFDF10_5.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF11_5.UINT32
RCFDC0.CFDRFDF11_5.UINT16[L/H]
RCFDC0.CFDRFDF11_5.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF12_5.UINT32
RCFDC0.CFDRFDF12_5.UINT16[L/H]
RCFDC0.CFDRFDF12_5.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF13_5.UINT32
RCFDC0.CFDRFDF13_5.UINT16[L/H]
RCFDC0.CFDRFDF13_5.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF14_5.UINT32
RCFDC0.CFDRFDF14_5.UINT16[L/H]
RCFDC0.CFDRFDF14_5.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF15_5.UINT32
RCFDC0.CFDRFDF15_5.UINT16[L/H]
RCFDC0.CFDRFDF15_5.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFID6.UINT32
RCFDC0.CFDRFID6.UINT16[L/H]
RCFDC0.CFDRFID6.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFPTR6.UINT32
RCFDC0.CFDRFPTR6.UINT16[L/H]
RCFDC0.CFDRFPTR6.UINT8[LL/LH/HH]
RCFDC0.CFDRFFDSTS6.UINT32
RCFDC0.CFDRFFDSTS6.UINT16[L/H]
RCFDC0.CFDRFFDSTS6.UINT8[LL/HL/HH]
RCFDC0.CFDRFDF0_6.UINT32
RCFDC0.CFDRFDF0_6.UINT16[L/H]
RCFDC0.CFDRFDF0_6.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF1_6.UINT32
RCFDC0.CFDRFDF1_6.UINT16[L/H]
RCFDC0.CFDRFDF1_6.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF2_6.UINT32
RCFDC0.CFDRFDF2_6.UINT16[L/H]
RCFDC0.CFDRFDF2_6.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF3_6.UINT32
RCFDC0.CFDRFDF3_6.UINT16[L/H]
RCFDC0.CFDRFDF3_6.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF4_6.UINT32
RCFDC0.CFDRFDF4_6.UINT16[L/H]
RCFDC0.CFDRFDF4_6.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF5_6.UINT32
RCFDC0.CFDRFDF5_6.UINT16[L/H]
RCFDC0.CFDRFDF5_6.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF6_6.UINT32
RCFDC0.CFDRFDF6_6.UINT16[L/H]
RCFDC0.CFDRFDF6_6.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF7_6.UINT32
RCFDC0.CFDRFDF7_6.UINT16[L/H]
RCFDC0.CFDRFDF7_6.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF8_6.UINT32
RCFDC0.CFDRFDF8_6.UINT16[L/H]
RCFDC0.CFDRFDF8_6.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF9_6.UINT32
RCFDC0.CFDRFDF9_6.UINT16[L/H]
RCFDC0.CFDRFDF9_6.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF10_6.UINT32
RCFDC0.CFDRFDF10_6.UINT16[L/H]
RCFDC0.CFDRFDF10_6.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF11_6.UINT32
RCFDC0.CFDRFDF11_6.UINT16[L/H]
RCFDC0.CFDRFDF11_6.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF12_6.UINT32
RCFDC0.CFDRFDF12_6.UINT16[L/H]
RCFDC0.CFDRFDF12_6.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF13_6.UINT32
RCFDC0.CFDRFDF13_6.UINT16[L/H]
RCFDC0.CFDRFDF13_6.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF14_6.UINT32
RCFDC0.CFDRFDF14_6.UINT16[L/H]
RCFDC0.CFDRFDF14_6.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF15_6.UINT32
RCFDC0.CFDRFDF15_6.UINT16[L/H]
RCFDC0.CFDRFDF15_6.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFID7.UINT32
RCFDC0.CFDRFID7.UINT16[L/H]
RCFDC0.CFDRFID7.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFPTR7.UINT32
RCFDC0.CFDRFPTR7.UINT16[L/H]
RCFDC0.CFDRFPTR7.UINT8[LL/LH/HH]
RCFDC0.CFDRFFDSTS7.UINT32
RCFDC0.CFDRFFDSTS7.UINT16[L/H]
RCFDC0.CFDRFFDSTS7.UINT8[LL/HL/HH]
RCFDC0.CFDRFDF0_7.UINT32
RCFDC0.CFDRFDF0_7.UINT16[L/H]
RCFDC0.CFDRFDF0_7.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF1_7.UINT32
RCFDC0.CFDRFDF1_7.UINT16[L/H]
RCFDC0.CFDRFDF1_7.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF2_7.UINT32
RCFDC0.CFDRFDF2_7.UINT16[L/H]
RCFDC0.CFDRFDF2_7.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF3_7.UINT32
RCFDC0.CFDRFDF3_7.UINT16[L/H]
RCFDC0.CFDRFDF3_7.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF4_7.UINT32
RCFDC0.CFDRFDF4_7.UINT16[L/H]
RCFDC0.CFDRFDF4_7.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF5_7.UINT32
RCFDC0.CFDRFDF5_7.UINT16[L/H]
RCFDC0.CFDRFDF5_7.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF6_7.UINT32
RCFDC0.CFDRFDF6_7.UINT16[L/H]
RCFDC0.CFDRFDF6_7.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF7_7.UINT32
RCFDC0.CFDRFDF7_7.UINT16[L/H]
RCFDC0.CFDRFDF7_7.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF8_7.UINT32
RCFDC0.CFDRFDF8_7.UINT16[L/H]
RCFDC0.CFDRFDF8_7.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF9_7.UINT32
RCFDC0.CFDRFDF9_7.UINT16[L/H]
RCFDC0.CFDRFDF9_7.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF10_7.UINT32
RCFDC0.CFDRFDF10_7.UINT16[L/H]
RCFDC0.CFDRFDF10_7.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF11_7.UINT32
RCFDC0.CFDRFDF11_7.UINT16[L/H]
RCFDC0.CFDRFDF11_7.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF12_7.UINT32
RCFDC0.CFDRFDF12_7.UINT16[L/H]
RCFDC0.CFDRFDF12_7.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF13_7.UINT32
RCFDC0.CFDRFDF13_7.UINT16[L/H]
RCFDC0.CFDRFDF13_7.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF14_7.UINT32
RCFDC0.CFDRFDF14_7.UINT16[L/H]
RCFDC0.CFDRFDF14_7.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRFDF15_7.UINT32
RCFDC0.CFDRFDF15_7.UINT16[L/H]
RCFDC0.CFDRFDF15_7.UINT8[LL/LH/HL/HH]
RCFDC0.CFDCFID0.UINT32
RCFDC0.CFDCFID0.UINT16[L/H]
RCFDC0.CFDCFID0.UINT8[LL/LH/HL/HH]
RCFDC0.CFDCFPTR0.UINT32
RCFDC0.CFDCFPTR0.UINT16[L/H]
RCFDC0.CFDCFPTR0.UINT8[LL/LH/HH]
RCFDC0.CFDCFFDCSTS0.UINT32
RCFDC0.CFDCFFDCSTS0.UINT16[L/H]
RCFDC0.CFDCFFDCSTS0.UINT8[LL/HL/HH]
RCFDC0.CFDCFDF0_0.UINT32
RCFDC0.CFDCFDF0_0.UINT16[L/H]
RCFDC0.CFDCFDF0_0.UINT8[LL/LH/HL/HH]
RCFDC0.CFDCFDF1_0.UINT32
RCFDC0.CFDCFDF1_0.UINT16[L/H]
RCFDC0.CFDCFDF1_0.UINT8[LL/LH/HL/HH]
RCFDC0.CFDCFDF2_0.UINT32
RCFDC0.CFDCFDF2_0.UINT16[L/H]
RCFDC0.CFDCFDF2_0.UINT8[LL/LH/HL/HH]
RCFDC0.CFDCFDF3_0.UINT32
RCFDC0.CFDCFDF3_0.UINT16[L/H]
RCFDC0.CFDCFDF3_0.UINT8[LL/LH/HL/HH]
RCFDC0.CFDCFDF4_0.UINT32
RCFDC0.CFDCFDF4_0.UINT16[L/H]
RCFDC0.CFDCFDF4_0.UINT8[LL/LH/HL/HH]
RCFDC0.CFDCFDF5_0.UINT32
RCFDC0.CFDCFDF5_0.UINT16[L/H]
RCFDC0.CFDCFDF5_0.UINT8[LL/LH/HL/HH]
RCFDC0.CFDCFDF6_0.UINT32
RCFDC0.CFDCFDF6_0.UINT16[L/H]
RCFDC0.CFDCFDF6_0.UINT8[LL/LH/HL/HH]
RCFDC0.CFDCFDF7_0.UINT32
RCFDC0.CFDCFDF7_0.UINT16[L/H]
RCFDC0.CFDCFDF7_0.UINT8[LL/LH/HL/HH]
RCFDC0.CFDCFDF8_0.UINT32
RCFDC0.CFDCFDF8_0.UINT16[L/H]
RCFDC0.CFDCFDF8_0.UINT8[LL/LH/HL/HH]
RCFDC0.CFDCFDF9_0.UINT32
RCFDC0.CFDCFDF9_0.UINT16[L/H]
RCFDC0.CFDCFDF9_0.UINT8[LL/LH/HL/HH]
RCFDC0.CFDCFDF10_0.UINT32
RCFDC0.CFDCFDF10_0.UINT16[L/H]
RCFDC0.CFDCFDF10_0.UINT8[LL/LH/HL/HH]
RCFDC0.CFDCFDF11_0.UINT32
RCFDC0.CFDCFDF11_0.UINT16[L/H]
RCFDC0.CFDCFDF11_0.UINT8[LL/LH/HL/HH]
RCFDC0.CFDCFDF12_0.UINT32
RCFDC0.CFDCFDF12_0.UINT16[L/H]
RCFDC0.CFDCFDF12_0.UINT8[LL/LH/HL/HH]
RCFDC0.CFDCFDF13_0.UINT32
RCFDC0.CFDCFDF13_0.UINT16[L/H]
RCFDC0.CFDCFDF13_0.UINT8[LL/LH/HL/HH]
RCFDC0.CFDCFDF14_0.UINT32
RCFDC0.CFDCFDF14_0.UINT16[L/H]
RCFDC0.CFDCFDF14_0.UINT8[LL/LH/HL/HH]
RCFDC0.CFDCFDF15_0.UINT32
RCFDC0.CFDCFDF15_0.UINT16[L/H]
RCFDC0.CFDCFDF15_0.UINT8[LL/LH/HL/HH]
RCFDC0.CFDCFID1.UINT32
RCFDC0.CFDCFID1.UINT16[L/H]
RCFDC0.CFDCFID1.UINT8[LL/LH/HL/HH]
RCFDC0.CFDCFPTR1.UINT32
RCFDC0.CFDCFPTR1.UINT16[L/H]
RCFDC0.CFDCFPTR1.UINT8[LL/LH/HH]
RCFDC0.CFDCFFDCSTS1.UINT32
RCFDC0.CFDCFFDCSTS1.UINT16[L/H]
RCFDC0.CFDCFFDCSTS1.UINT8[LL/HL/HH]
RCFDC0.CFDCFDF0_1.UINT32
RCFDC0.CFDCFDF0_1.UINT16[L/H]
RCFDC0.CFDCFDF0_1.UINT8[LL/LH/HL/HH]
RCFDC0.CFDCFDF1_1.UINT32
RCFDC0.CFDCFDF1_1.UINT16[L/H]
RCFDC0.CFDCFDF1_1.UINT8[LL/LH/HL/HH]
RCFDC0.CFDCFDF2_1.UINT32
RCFDC0.CFDCFDF2_1.UINT16[L/H]
RCFDC0.CFDCFDF2_1.UINT8[LL/LH/HL/HH]
RCFDC0.CFDCFDF3_1.UINT32
RCFDC0.CFDCFDF3_1.UINT16[L/H]
RCFDC0.CFDCFDF3_1.UINT8[LL/LH/HL/HH]
RCFDC0.CFDCFDF4_1.UINT32
RCFDC0.CFDCFDF4_1.UINT16[L/H]
RCFDC0.CFDCFDF4_1.UINT8[LL/LH/HL/HH]
RCFDC0.CFDCFDF5_1.UINT32
RCFDC0.CFDCFDF5_1.UINT16[L/H]
RCFDC0.CFDCFDF5_1.UINT8[LL/LH/HL/HH]
RCFDC0.CFDCFDF6_1.UINT32
RCFDC0.CFDCFDF6_1.UINT16[L/H]
RCFDC0.CFDCFDF6_1.UINT8[LL/LH/HL/HH]
RCFDC0.CFDCFDF7_1.UINT32
RCFDC0.CFDCFDF7_1.UINT16[L/H]
RCFDC0.CFDCFDF7_1.UINT8[LL/LH/HL/HH]
RCFDC0.CFDCFDF8_1.UINT32
RCFDC0.CFDCFDF8_1.UINT16[L/H]
RCFDC0.CFDCFDF8_1.UINT8[LL/LH/HL/HH]
RCFDC0.CFDCFDF9_1.UINT32
RCFDC0.CFDCFDF9_1.UINT16[L/H]
RCFDC0.CFDCFDF9_1.UINT8[LL/LH/HL/HH]
RCFDC0.CFDCFDF10_1.UINT32
RCFDC0.CFDCFDF10_1.UINT16[L/H]
RCFDC0.CFDCFDF10_1.UINT8[LL/LH/HL/HH]
RCFDC0.CFDCFDF11_1.UINT32
RCFDC0.CFDCFDF11_1.UINT16[L/H]
RCFDC0.CFDCFDF11_1.UINT8[LL/LH/HL/HH]
RCFDC0.CFDCFDF12_1.UINT32
RCFDC0.CFDCFDF12_1.UINT16[L/H]
RCFDC0.CFDCFDF12_1.UINT8[LL/LH/HL/HH]
RCFDC0.CFDCFDF13_1.UINT32
RCFDC0.CFDCFDF13_1.UINT16[L/H]
RCFDC0.CFDCFDF13_1.UINT8[LL/LH/HL/HH]
RCFDC0.CFDCFDF14_1.UINT32
RCFDC0.CFDCFDF14_1.UINT16[L/H]
RCFDC0.CFDCFDF14_1.UINT8[LL/LH/HL/HH]
RCFDC0.CFDCFDF15_1.UINT32
RCFDC0.CFDCFDF15_1.UINT16[L/H]
RCFDC0.CFDCFDF15_1.UINT8[LL/LH/HL/HH]
RCFDC0.CFDCFID2.UINT32
RCFDC0.CFDCFID2.UINT16[L/H]
RCFDC0.CFDCFID2.UINT8[LL/LH/HL/HH]
RCFDC0.CFDCFPTR2.UINT32
RCFDC0.CFDCFPTR2.UINT16[L/H]
RCFDC0.CFDCFPTR2.UINT8[LL/LH/HH]
RCFDC0.CFDCFFDCSTS2.UINT32
RCFDC0.CFDCFFDCSTS2.UINT16[L/H]
RCFDC0.CFDCFFDCSTS2.UINT8[LL/HL/HH]
RCFDC0.CFDCFDF0_2.UINT32
RCFDC0.CFDCFDF0_2.UINT16[L/H]
RCFDC0.CFDCFDF0_2.UINT8[LL/LH/HL/HH]
RCFDC0.CFDCFDF1_2.UINT32
RCFDC0.CFDCFDF1_2.UINT16[L/H]
RCFDC0.CFDCFDF1_2.UINT8[LL/LH/HL/HH]
RCFDC0.CFDCFDF2_2.UINT32
RCFDC0.CFDCFDF2_2.UINT16[L/H]
RCFDC0.CFDCFDF2_2.UINT8[LL/LH/HL/HH]
RCFDC0.CFDCFDF3_2.UINT32
RCFDC0.CFDCFDF3_2.UINT16[L/H]
RCFDC0.CFDCFDF3_2.UINT8[LL/LH/HL/HH]
RCFDC0.CFDCFDF4_2.UINT32
RCFDC0.CFDCFDF4_2.UINT16[L/H]
RCFDC0.CFDCFDF4_2.UINT8[LL/LH/HL/HH]
RCFDC0.CFDCFDF5_2.UINT32
RCFDC0.CFDCFDF5_2.UINT16[L/H]
RCFDC0.CFDCFDF5_2.UINT8[LL/LH/HL/HH]
RCFDC0.CFDCFDF6_2.UINT32
RCFDC0.CFDCFDF6_2.UINT16[L/H]
RCFDC0.CFDCFDF6_2.UINT8[LL/LH/HL/HH]
RCFDC0.CFDCFDF7_2.UINT32
RCFDC0.CFDCFDF7_2.UINT16[L/H]
RCFDC0.CFDCFDF7_2.UINT8[LL/LH/HL/HH]
RCFDC0.CFDCFDF8_2.UINT32
RCFDC0.CFDCFDF8_2.UINT16[L/H]
RCFDC0.CFDCFDF8_2.UINT8[LL/LH/HL/HH]
RCFDC0.CFDCFDF9_2.UINT32
RCFDC0.CFDCFDF9_2.UINT16[L/H]
RCFDC0.CFDCFDF9_2.UINT8[LL/LH/HL/HH]
RCFDC0.CFDCFDF10_2.UINT32
RCFDC0.CFDCFDF10_2.UINT16[L/H]
RCFDC0.CFDCFDF10_2.UINT8[LL/LH/HL/HH]
RCFDC0.CFDCFDF11_2.UINT32
RCFDC0.CFDCFDF11_2.UINT16[L/H]
RCFDC0.CFDCFDF11_2.UINT8[LL/LH/HL/HH]
RCFDC0.CFDCFDF12_2.UINT32
RCFDC0.CFDCFDF12_2.UINT16[L/H]
RCFDC0.CFDCFDF12_2.UINT8[LL/LH/HL/HH]
RCFDC0.CFDCFDF13_2.UINT32
RCFDC0.CFDCFDF13_2.UINT16[L/H]
RCFDC0.CFDCFDF13_2.UINT8[LL/LH/HL/HH]
RCFDC0.CFDCFDF14_2.UINT32
RCFDC0.CFDCFDF14_2.UINT16[L/H]
RCFDC0.CFDCFDF14_2.UINT8[LL/LH/HL/HH]
RCFDC0.CFDCFDF15_2.UINT32
RCFDC0.CFDCFDF15_2.UINT16[L/H]
RCFDC0.CFDCFDF15_2.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMID0.UINT32
RCFDC0.CFDTMID0.UINT16[L/H]
RCFDC0.CFDTMID0.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMPTR0.UINT32
RCFDC0.CFDTMPTR0.UINT16[H]
RCFDC0.CFDTMPTR0.UINT8[HH]
RCFDC0.CFDTMFDCTR0.UINT32
RCFDC0.CFDTMFDCTR0.UINT16[L/H]
RCFDC0.CFDTMFDCTR0.UINT8[LL/HL/HH]
RCFDC0.CFDTMDF0_0.UINT32
RCFDC0.CFDTMDF0_0.UINT16[L/H]
RCFDC0.CFDTMDF0_0.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF1_0.UINT32
RCFDC0.CFDTMDF1_0.UINT16[L/H]
RCFDC0.CFDTMDF1_0.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF2_0.UINT32
RCFDC0.CFDTMDF2_0.UINT16[L/H]
RCFDC0.CFDTMDF2_0.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF3_0.UINT32
RCFDC0.CFDTMDF3_0.UINT16[L/H]
RCFDC0.CFDTMDF3_0.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF4_0.UINT32
RCFDC0.CFDTMDF4_0.UINT16[L/H]
RCFDC0.CFDTMDF4_0.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF5_0.UINT32
RCFDC0.CFDTMDF5_0.UINT16[L/H]
RCFDC0.CFDTMDF5_0.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF6_0.UINT32
RCFDC0.CFDTMDF6_0.UINT16[L/H]
RCFDC0.CFDTMDF6_0.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF7_0.UINT32
RCFDC0.CFDTMDF7_0.UINT16[L/H]
RCFDC0.CFDTMDF7_0.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF8_0.UINT32
RCFDC0.CFDTMDF8_0.UINT16[L/H]
RCFDC0.CFDTMDF8_0.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF9_0.UINT32
RCFDC0.CFDTMDF9_0.UINT16[L/H]
RCFDC0.CFDTMDF9_0.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF10_0.UINT32
RCFDC0.CFDTMDF10_0.UINT16[L/H]
RCFDC0.CFDTMDF10_0.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF11_0.UINT32
RCFDC0.CFDTMDF11_0.UINT16[L/H]
RCFDC0.CFDTMDF11_0.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF12_0.UINT32
RCFDC0.CFDTMDF12_0.UINT16[L/H]
RCFDC0.CFDTMDF12_0.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF13_0.UINT32
RCFDC0.CFDTMDF13_0.UINT16[L/H]
RCFDC0.CFDTMDF13_0.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF14_0.UINT32
RCFDC0.CFDTMDF14_0.UINT16[L/H]
RCFDC0.CFDTMDF14_0.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF15_0.UINT32
RCFDC0.CFDTMDF15_0.UINT16[L/H]
RCFDC0.CFDTMDF15_0.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMID1.UINT32
RCFDC0.CFDTMID1.UINT16[L/H]
RCFDC0.CFDTMID1.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMPTR1.UINT32
RCFDC0.CFDTMPTR1.UINT16[H]
RCFDC0.CFDTMPTR1.UINT8[HH]
RCFDC0.CFDTMFDCTR1.UINT32
RCFDC0.CFDTMFDCTR1.UINT16[L/H]
RCFDC0.CFDTMFDCTR1.UINT8[LL/HL/HH]
RCFDC0.CFDTMDF0_1.UINT32
RCFDC0.CFDTMDF0_1.UINT16[L/H]
RCFDC0.CFDTMDF0_1.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF1_1.UINT32
RCFDC0.CFDTMDF1_1.UINT16[L/H]
RCFDC0.CFDTMDF1_1.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF2_1.UINT32
RCFDC0.CFDTMDF2_1.UINT16[L/H]
RCFDC0.CFDTMDF2_1.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF3_1.UINT32
RCFDC0.CFDTMDF3_1.UINT16[L/H]
RCFDC0.CFDTMDF3_1.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF4_1.UINT32
RCFDC0.CFDTMDF4_1.UINT16[L/H]
RCFDC0.CFDTMDF4_1.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF5_1.UINT32
RCFDC0.CFDTMDF5_1.UINT16[L/H]
RCFDC0.CFDTMDF5_1.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF6_1.UINT32
RCFDC0.CFDTMDF6_1.UINT16[L/H]
RCFDC0.CFDTMDF6_1.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF7_1.UINT32
RCFDC0.CFDTMDF7_1.UINT16[L/H]
RCFDC0.CFDTMDF7_1.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF8_1.UINT32
RCFDC0.CFDTMDF8_1.UINT16[L/H]
RCFDC0.CFDTMDF8_1.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF9_1.UINT32
RCFDC0.CFDTMDF9_1.UINT16[L/H]
RCFDC0.CFDTMDF9_1.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF10_1.UINT32
RCFDC0.CFDTMDF10_1.UINT16[L/H]
RCFDC0.CFDTMDF10_1.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF11_1.UINT32
RCFDC0.CFDTMDF11_1.UINT16[L/H]
RCFDC0.CFDTMDF11_1.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF12_1.UINT32
RCFDC0.CFDTMDF12_1.UINT16[L/H]
RCFDC0.CFDTMDF12_1.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF13_1.UINT32
RCFDC0.CFDTMDF13_1.UINT16[L/H]
RCFDC0.CFDTMDF13_1.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF14_1.UINT32
RCFDC0.CFDTMDF14_1.UINT16[L/H]
RCFDC0.CFDTMDF14_1.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF15_1.UINT32
RCFDC0.CFDTMDF15_1.UINT16[L/H]
RCFDC0.CFDTMDF15_1.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMID2.UINT32
RCFDC0.CFDTMID2.UINT16[L/H]
RCFDC0.CFDTMID2.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMPTR2.UINT32
RCFDC0.CFDTMPTR2.UINT16[H]
RCFDC0.CFDTMPTR2.UINT8[HH]
RCFDC0.CFDTMFDCTR2.UINT32
RCFDC0.CFDTMFDCTR2.UINT16[L/H]
RCFDC0.CFDTMFDCTR2.UINT8[LL/HL/HH]
RCFDC0.CFDTMDF0_2.UINT32
RCFDC0.CFDTMDF0_2.UINT16[L/H]
RCFDC0.CFDTMDF0_2.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF1_2.UINT32
RCFDC0.CFDTMDF1_2.UINT16[L/H]
RCFDC0.CFDTMDF1_2.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF2_2.UINT32
RCFDC0.CFDTMDF2_2.UINT16[L/H]
RCFDC0.CFDTMDF2_2.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF3_2.UINT32
RCFDC0.CFDTMDF3_2.UINT16[L/H]
RCFDC0.CFDTMDF3_2.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF4_2.UINT32
RCFDC0.CFDTMDF4_2.UINT16[L/H]
RCFDC0.CFDTMDF4_2.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF5_2.UINT32
RCFDC0.CFDTMDF5_2.UINT16[L/H]
RCFDC0.CFDTMDF5_2.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF6_2.UINT32
RCFDC0.CFDTMDF6_2.UINT16[L/H]
RCFDC0.CFDTMDF6_2.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF7_2.UINT32
RCFDC0.CFDTMDF7_2.UINT16[L/H]
RCFDC0.CFDTMDF7_2.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF8_2.UINT32
RCFDC0.CFDTMDF8_2.UINT16[L/H]
RCFDC0.CFDTMDF8_2.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF9_2.UINT32
RCFDC0.CFDTMDF9_2.UINT16[L/H]
RCFDC0.CFDTMDF9_2.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF10_2.UINT32
RCFDC0.CFDTMDF10_2.UINT16[L/H]
RCFDC0.CFDTMDF10_2.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF11_2.UINT32
RCFDC0.CFDTMDF11_2.UINT16[L/H]
RCFDC0.CFDTMDF11_2.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF12_2.UINT32
RCFDC0.CFDTMDF12_2.UINT16[L/H]
RCFDC0.CFDTMDF12_2.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF13_2.UINT32
RCFDC0.CFDTMDF13_2.UINT16[L/H]
RCFDC0.CFDTMDF13_2.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF14_2.UINT32
RCFDC0.CFDTMDF14_2.UINT16[L/H]
RCFDC0.CFDTMDF14_2.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF15_2.UINT32
RCFDC0.CFDTMDF15_2.UINT16[L/H]
RCFDC0.CFDTMDF15_2.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMID3.UINT32
RCFDC0.CFDTMID3.UINT16[L/H]
RCFDC0.CFDTMID3.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMPTR3.UINT32
RCFDC0.CFDTMPTR3.UINT16[H]
RCFDC0.CFDTMPTR3.UINT8[HH]
RCFDC0.CFDTMFDCTR3.UINT32
RCFDC0.CFDTMFDCTR3.UINT16[L/H]
RCFDC0.CFDTMFDCTR3.UINT8[LL/HL/HH]
RCFDC0.CFDTMDF0_3.UINT32
RCFDC0.CFDTMDF0_3.UINT16[L/H]
RCFDC0.CFDTMDF0_3.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF1_3.UINT32
RCFDC0.CFDTMDF1_3.UINT16[L/H]
RCFDC0.CFDTMDF1_3.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF2_3.UINT32
RCFDC0.CFDTMDF2_3.UINT16[L/H]
RCFDC0.CFDTMDF2_3.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF3_3.UINT32
RCFDC0.CFDTMDF3_3.UINT16[L/H]
RCFDC0.CFDTMDF3_3.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF4_3.UINT32
RCFDC0.CFDTMDF4_3.UINT16[L/H]
RCFDC0.CFDTMDF4_3.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF5_3.UINT32
RCFDC0.CFDTMDF5_3.UINT16[L/H]
RCFDC0.CFDTMDF5_3.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF6_3.UINT32
RCFDC0.CFDTMDF6_3.UINT16[L/H]
RCFDC0.CFDTMDF6_3.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF7_3.UINT32
RCFDC0.CFDTMDF7_3.UINT16[L/H]
RCFDC0.CFDTMDF7_3.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF8_3.UINT32
RCFDC0.CFDTMDF8_3.UINT16[L/H]
RCFDC0.CFDTMDF8_3.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF9_3.UINT32
RCFDC0.CFDTMDF9_3.UINT16[L/H]
RCFDC0.CFDTMDF9_3.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF10_3.UINT32
RCFDC0.CFDTMDF10_3.UINT16[L/H]
RCFDC0.CFDTMDF10_3.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF11_3.UINT32
RCFDC0.CFDTMDF11_3.UINT16[L/H]
RCFDC0.CFDTMDF11_3.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF12_3.UINT32
RCFDC0.CFDTMDF12_3.UINT16[L/H]
RCFDC0.CFDTMDF12_3.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF13_3.UINT32
RCFDC0.CFDTMDF13_3.UINT16[L/H]
RCFDC0.CFDTMDF13_3.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF14_3.UINT32
RCFDC0.CFDTMDF14_3.UINT16[L/H]
RCFDC0.CFDTMDF14_3.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF15_3.UINT32
RCFDC0.CFDTMDF15_3.UINT16[L/H]
RCFDC0.CFDTMDF15_3.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMID4.UINT32
RCFDC0.CFDTMID4.UINT16[L/H]
RCFDC0.CFDTMID4.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMPTR4.UINT32
RCFDC0.CFDTMPTR4.UINT16[H]
RCFDC0.CFDTMPTR4.UINT8[HH]
RCFDC0.CFDTMFDCTR4.UINT32
RCFDC0.CFDTMFDCTR4.UINT16[L/H]
RCFDC0.CFDTMFDCTR4.UINT8[LL/HL/HH]
RCFDC0.CFDTMDF0_4.UINT32
RCFDC0.CFDTMDF0_4.UINT16[L/H]
RCFDC0.CFDTMDF0_4.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF1_4.UINT32
RCFDC0.CFDTMDF1_4.UINT16[L/H]
RCFDC0.CFDTMDF1_4.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF2_4.UINT32
RCFDC0.CFDTMDF2_4.UINT16[L/H]
RCFDC0.CFDTMDF2_4.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF3_4.UINT32
RCFDC0.CFDTMDF3_4.UINT16[L/H]
RCFDC0.CFDTMDF3_4.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF4_4.UINT32
RCFDC0.CFDTMDF4_4.UINT16[L/H]
RCFDC0.CFDTMDF4_4.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF5_4.UINT32
RCFDC0.CFDTMDF5_4.UINT16[L/H]
RCFDC0.CFDTMDF5_4.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF6_4.UINT32
RCFDC0.CFDTMDF6_4.UINT16[L/H]
RCFDC0.CFDTMDF6_4.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF7_4.UINT32
RCFDC0.CFDTMDF7_4.UINT16[L/H]
RCFDC0.CFDTMDF7_4.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF8_4.UINT32
RCFDC0.CFDTMDF8_4.UINT16[L/H]
RCFDC0.CFDTMDF8_4.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF9_4.UINT32
RCFDC0.CFDTMDF9_4.UINT16[L/H]
RCFDC0.CFDTMDF9_4.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF10_4.UINT32
RCFDC0.CFDTMDF10_4.UINT16[L/H]
RCFDC0.CFDTMDF10_4.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF11_4.UINT32
RCFDC0.CFDTMDF11_4.UINT16[L/H]
RCFDC0.CFDTMDF11_4.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF12_4.UINT32
RCFDC0.CFDTMDF12_4.UINT16[L/H]
RCFDC0.CFDTMDF12_4.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF13_4.UINT32
RCFDC0.CFDTMDF13_4.UINT16[L/H]
RCFDC0.CFDTMDF13_4.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF14_4.UINT32
RCFDC0.CFDTMDF14_4.UINT16[L/H]
RCFDC0.CFDTMDF14_4.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF15_4.UINT32
RCFDC0.CFDTMDF15_4.UINT16[L/H]
RCFDC0.CFDTMDF15_4.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMID5.UINT32
RCFDC0.CFDTMID5.UINT16[L/H]
RCFDC0.CFDTMID5.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMPTR5.UINT32
RCFDC0.CFDTMPTR5.UINT16[H]
RCFDC0.CFDTMPTR5.UINT8[HH]
RCFDC0.CFDTMFDCTR5.UINT32
RCFDC0.CFDTMFDCTR5.UINT16[L/H]
RCFDC0.CFDTMFDCTR5.UINT8[LL/HL/HH]
RCFDC0.CFDTMDF0_5.UINT32
RCFDC0.CFDTMDF0_5.UINT16[L/H]
RCFDC0.CFDTMDF0_5.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF1_5.UINT32
RCFDC0.CFDTMDF1_5.UINT16[L/H]
RCFDC0.CFDTMDF1_5.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF2_5.UINT32
RCFDC0.CFDTMDF2_5.UINT16[L/H]
RCFDC0.CFDTMDF2_5.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF3_5.UINT32
RCFDC0.CFDTMDF3_5.UINT16[L/H]
RCFDC0.CFDTMDF3_5.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF4_5.UINT32
RCFDC0.CFDTMDF4_5.UINT16[L/H]
RCFDC0.CFDTMDF4_5.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF5_5.UINT32
RCFDC0.CFDTMDF5_5.UINT16[L/H]
RCFDC0.CFDTMDF5_5.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF6_5.UINT32
RCFDC0.CFDTMDF6_5.UINT16[L/H]
RCFDC0.CFDTMDF6_5.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF7_5.UINT32
RCFDC0.CFDTMDF7_5.UINT16[L/H]
RCFDC0.CFDTMDF7_5.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF8_5.UINT32
RCFDC0.CFDTMDF8_5.UINT16[L/H]
RCFDC0.CFDTMDF8_5.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF9_5.UINT32
RCFDC0.CFDTMDF9_5.UINT16[L/H]
RCFDC0.CFDTMDF9_5.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF10_5.UINT32
RCFDC0.CFDTMDF10_5.UINT16[L/H]
RCFDC0.CFDTMDF10_5.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF11_5.UINT32
RCFDC0.CFDTMDF11_5.UINT16[L/H]
RCFDC0.CFDTMDF11_5.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF12_5.UINT32
RCFDC0.CFDTMDF12_5.UINT16[L/H]
RCFDC0.CFDTMDF12_5.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF13_5.UINT32
RCFDC0.CFDTMDF13_5.UINT16[L/H]
RCFDC0.CFDTMDF13_5.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF14_5.UINT32
RCFDC0.CFDTMDF14_5.UINT16[L/H]
RCFDC0.CFDTMDF14_5.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF15_5.UINT32
RCFDC0.CFDTMDF15_5.UINT16[L/H]
RCFDC0.CFDTMDF15_5.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMID6.UINT32
RCFDC0.CFDTMID6.UINT16[L/H]
RCFDC0.CFDTMID6.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMPTR6.UINT32
RCFDC0.CFDTMPTR6.UINT16[H]
RCFDC0.CFDTMPTR6.UINT8[HH]
RCFDC0.CFDTMFDCTR6.UINT32
RCFDC0.CFDTMFDCTR6.UINT16[L/H]
RCFDC0.CFDTMFDCTR6.UINT8[LL/HL/HH]
RCFDC0.CFDTMDF0_6.UINT32
RCFDC0.CFDTMDF0_6.UINT16[L/H]
RCFDC0.CFDTMDF0_6.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF1_6.UINT32
RCFDC0.CFDTMDF1_6.UINT16[L/H]
RCFDC0.CFDTMDF1_6.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF2_6.UINT32
RCFDC0.CFDTMDF2_6.UINT16[L/H]
RCFDC0.CFDTMDF2_6.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF3_6.UINT32
RCFDC0.CFDTMDF3_6.UINT16[L/H]
RCFDC0.CFDTMDF3_6.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF4_6.UINT32
RCFDC0.CFDTMDF4_6.UINT16[L/H]
RCFDC0.CFDTMDF4_6.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF5_6.UINT32
RCFDC0.CFDTMDF5_6.UINT16[L/H]
RCFDC0.CFDTMDF5_6.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF6_6.UINT32
RCFDC0.CFDTMDF6_6.UINT16[L/H]
RCFDC0.CFDTMDF6_6.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF7_6.UINT32
RCFDC0.CFDTMDF7_6.UINT16[L/H]
RCFDC0.CFDTMDF7_6.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF8_6.UINT32
RCFDC0.CFDTMDF8_6.UINT16[L/H]
RCFDC0.CFDTMDF8_6.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF9_6.UINT32
RCFDC0.CFDTMDF9_6.UINT16[L/H]
RCFDC0.CFDTMDF9_6.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF10_6.UINT32
RCFDC0.CFDTMDF10_6.UINT16[L/H]
RCFDC0.CFDTMDF10_6.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF11_6.UINT32
RCFDC0.CFDTMDF11_6.UINT16[L/H]
RCFDC0.CFDTMDF11_6.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF12_6.UINT32
RCFDC0.CFDTMDF12_6.UINT16[L/H]
RCFDC0.CFDTMDF12_6.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF13_6.UINT32
RCFDC0.CFDTMDF13_6.UINT16[L/H]
RCFDC0.CFDTMDF13_6.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF14_6.UINT32
RCFDC0.CFDTMDF14_6.UINT16[L/H]
RCFDC0.CFDTMDF14_6.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF15_6.UINT32
RCFDC0.CFDTMDF15_6.UINT16[L/H]
RCFDC0.CFDTMDF15_6.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMID7.UINT32
RCFDC0.CFDTMID7.UINT16[L/H]
RCFDC0.CFDTMID7.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMPTR7.UINT32
RCFDC0.CFDTMPTR7.UINT16[H]
RCFDC0.CFDTMPTR7.UINT8[HH]
RCFDC0.CFDTMFDCTR7.UINT32
RCFDC0.CFDTMFDCTR7.UINT16[L/H]
RCFDC0.CFDTMFDCTR7.UINT8[LL/HL/HH]
RCFDC0.CFDTMDF0_7.UINT32
RCFDC0.CFDTMDF0_7.UINT16[L/H]
RCFDC0.CFDTMDF0_7.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF1_7.UINT32
RCFDC0.CFDTMDF1_7.UINT16[L/H]
RCFDC0.CFDTMDF1_7.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF2_7.UINT32
RCFDC0.CFDTMDF2_7.UINT16[L/H]
RCFDC0.CFDTMDF2_7.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF3_7.UINT32
RCFDC0.CFDTMDF3_7.UINT16[L/H]
RCFDC0.CFDTMDF3_7.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF4_7.UINT32
RCFDC0.CFDTMDF4_7.UINT16[L/H]
RCFDC0.CFDTMDF4_7.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF5_7.UINT32
RCFDC0.CFDTMDF5_7.UINT16[L/H]
RCFDC0.CFDTMDF5_7.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF6_7.UINT32
RCFDC0.CFDTMDF6_7.UINT16[L/H]
RCFDC0.CFDTMDF6_7.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF7_7.UINT32
RCFDC0.CFDTMDF7_7.UINT16[L/H]
RCFDC0.CFDTMDF7_7.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF8_7.UINT32
RCFDC0.CFDTMDF8_7.UINT16[L/H]
RCFDC0.CFDTMDF8_7.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF9_7.UINT32
RCFDC0.CFDTMDF9_7.UINT16[L/H]
RCFDC0.CFDTMDF9_7.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF10_7.UINT32
RCFDC0.CFDTMDF10_7.UINT16[L/H]
RCFDC0.CFDTMDF10_7.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF11_7.UINT32
RCFDC0.CFDTMDF11_7.UINT16[L/H]
RCFDC0.CFDTMDF11_7.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF12_7.UINT32
RCFDC0.CFDTMDF12_7.UINT16[L/H]
RCFDC0.CFDTMDF12_7.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF13_7.UINT32
RCFDC0.CFDTMDF13_7.UINT16[L/H]
RCFDC0.CFDTMDF13_7.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF14_7.UINT32
RCFDC0.CFDTMDF14_7.UINT16[L/H]
RCFDC0.CFDTMDF14_7.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF15_7.UINT32
RCFDC0.CFDTMDF15_7.UINT16[L/H]
RCFDC0.CFDTMDF15_7.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMID8.UINT32
RCFDC0.CFDTMID8.UINT16[L/H]
RCFDC0.CFDTMID8.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMPTR8.UINT32
RCFDC0.CFDTMPTR8.UINT16[H]
RCFDC0.CFDTMPTR8.UINT8[HH]
RCFDC0.CFDTMFDCTR8.UINT32
RCFDC0.CFDTMFDCTR8.UINT16[L/H]
RCFDC0.CFDTMFDCTR8.UINT8[LL/HL/HH]
RCFDC0.CFDTMDF0_8.UINT32
RCFDC0.CFDTMDF0_8.UINT16[L/H]
RCFDC0.CFDTMDF0_8.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF1_8.UINT32
RCFDC0.CFDTMDF1_8.UINT16[L/H]
RCFDC0.CFDTMDF1_8.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF2_8.UINT32
RCFDC0.CFDTMDF2_8.UINT16[L/H]
RCFDC0.CFDTMDF2_8.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF3_8.UINT32
RCFDC0.CFDTMDF3_8.UINT16[L/H]
RCFDC0.CFDTMDF3_8.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF4_8.UINT32
RCFDC0.CFDTMDF4_8.UINT16[L/H]
RCFDC0.CFDTMDF4_8.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF5_8.UINT32
RCFDC0.CFDTMDF5_8.UINT16[L/H]
RCFDC0.CFDTMDF5_8.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF6_8.UINT32
RCFDC0.CFDTMDF6_8.UINT16[L/H]
RCFDC0.CFDTMDF6_8.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF7_8.UINT32
RCFDC0.CFDTMDF7_8.UINT16[L/H]
RCFDC0.CFDTMDF7_8.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF8_8.UINT32
RCFDC0.CFDTMDF8_8.UINT16[L/H]
RCFDC0.CFDTMDF8_8.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF9_8.UINT32
RCFDC0.CFDTMDF9_8.UINT16[L/H]
RCFDC0.CFDTMDF9_8.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF10_8.UINT32
RCFDC0.CFDTMDF10_8.UINT16[L/H]
RCFDC0.CFDTMDF10_8.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF11_8.UINT32
RCFDC0.CFDTMDF11_8.UINT16[L/H]
RCFDC0.CFDTMDF11_8.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF12_8.UINT32
RCFDC0.CFDTMDF12_8.UINT16[L/H]
RCFDC0.CFDTMDF12_8.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF13_8.UINT32
RCFDC0.CFDTMDF13_8.UINT16[L/H]
RCFDC0.CFDTMDF13_8.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF14_8.UINT32
RCFDC0.CFDTMDF14_8.UINT16[L/H]
RCFDC0.CFDTMDF14_8.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF15_8.UINT32
RCFDC0.CFDTMDF15_8.UINT16[L/H]
RCFDC0.CFDTMDF15_8.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMID9.UINT32
RCFDC0.CFDTMID9.UINT16[L/H]
RCFDC0.CFDTMID9.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMPTR9.UINT32
RCFDC0.CFDTMPTR9.UINT16[H]
RCFDC0.CFDTMPTR9.UINT8[HH]
RCFDC0.CFDTMFDCTR9.UINT32
RCFDC0.CFDTMFDCTR9.UINT16[L/H]
RCFDC0.CFDTMFDCTR9.UINT8[LL/HL/HH]
RCFDC0.CFDTMDF0_9.UINT32
RCFDC0.CFDTMDF0_9.UINT16[L/H]
RCFDC0.CFDTMDF0_9.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF1_9.UINT32
RCFDC0.CFDTMDF1_9.UINT16[L/H]
RCFDC0.CFDTMDF1_9.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF2_9.UINT32
RCFDC0.CFDTMDF2_9.UINT16[L/H]
RCFDC0.CFDTMDF2_9.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF3_9.UINT32
RCFDC0.CFDTMDF3_9.UINT16[L/H]
RCFDC0.CFDTMDF3_9.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF4_9.UINT32
RCFDC0.CFDTMDF4_9.UINT16[L/H]
RCFDC0.CFDTMDF4_9.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF5_9.UINT32
RCFDC0.CFDTMDF5_9.UINT16[L/H]
RCFDC0.CFDTMDF5_9.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF6_9.UINT32
RCFDC0.CFDTMDF6_9.UINT16[L/H]
RCFDC0.CFDTMDF6_9.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF7_9.UINT32
RCFDC0.CFDTMDF7_9.UINT16[L/H]
RCFDC0.CFDTMDF7_9.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF8_9.UINT32
RCFDC0.CFDTMDF8_9.UINT16[L/H]
RCFDC0.CFDTMDF8_9.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF9_9.UINT32
RCFDC0.CFDTMDF9_9.UINT16[L/H]
RCFDC0.CFDTMDF9_9.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF10_9.UINT32
RCFDC0.CFDTMDF10_9.UINT16[L/H]
RCFDC0.CFDTMDF10_9.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF11_9.UINT32
RCFDC0.CFDTMDF11_9.UINT16[L/H]
RCFDC0.CFDTMDF11_9.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF12_9.UINT32
RCFDC0.CFDTMDF12_9.UINT16[L/H]
RCFDC0.CFDTMDF12_9.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF13_9.UINT32
RCFDC0.CFDTMDF13_9.UINT16[L/H]
RCFDC0.CFDTMDF13_9.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF14_9.UINT32
RCFDC0.CFDTMDF14_9.UINT16[L/H]
RCFDC0.CFDTMDF14_9.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF15_9.UINT32
RCFDC0.CFDTMDF15_9.UINT16[L/H]
RCFDC0.CFDTMDF15_9.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMID10.UINT32
RCFDC0.CFDTMID10.UINT16[L/H]
RCFDC0.CFDTMID10.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMPTR10.UINT32
RCFDC0.CFDTMPTR10.UINT16[H]
RCFDC0.CFDTMPTR10.UINT8[HH]
RCFDC0.CFDTMFDCTR10.UINT32
RCFDC0.CFDTMFDCTR10.UINT16[L/H]
RCFDC0.CFDTMFDCTR10.UINT8[LL/HL/HH]
RCFDC0.CFDTMDF0_10.UINT32
RCFDC0.CFDTMDF0_10.UINT16[L/H]
RCFDC0.CFDTMDF0_10.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF1_10.UINT32
RCFDC0.CFDTMDF1_10.UINT16[L/H]
RCFDC0.CFDTMDF1_10.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF2_10.UINT32
RCFDC0.CFDTMDF2_10.UINT16[L/H]
RCFDC0.CFDTMDF2_10.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF3_10.UINT32
RCFDC0.CFDTMDF3_10.UINT16[L/H]
RCFDC0.CFDTMDF3_10.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF4_10.UINT32
RCFDC0.CFDTMDF4_10.UINT16[L/H]
RCFDC0.CFDTMDF4_10.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF5_10.UINT32
RCFDC0.CFDTMDF5_10.UINT16[L/H]
RCFDC0.CFDTMDF5_10.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF6_10.UINT32
RCFDC0.CFDTMDF6_10.UINT16[L/H]
RCFDC0.CFDTMDF6_10.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF7_10.UINT32
RCFDC0.CFDTMDF7_10.UINT16[L/H]
RCFDC0.CFDTMDF7_10.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF8_10.UINT32
RCFDC0.CFDTMDF8_10.UINT16[L/H]
RCFDC0.CFDTMDF8_10.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF9_10.UINT32
RCFDC0.CFDTMDF9_10.UINT16[L/H]
RCFDC0.CFDTMDF9_10.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF10_10.UINT32
RCFDC0.CFDTMDF10_10.UINT16[L/H]
RCFDC0.CFDTMDF10_10.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF11_10.UINT32
RCFDC0.CFDTMDF11_10.UINT16[L/H]
RCFDC0.CFDTMDF11_10.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF12_10.UINT32
RCFDC0.CFDTMDF12_10.UINT16[L/H]
RCFDC0.CFDTMDF12_10.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF13_10.UINT32
RCFDC0.CFDTMDF13_10.UINT16[L/H]
RCFDC0.CFDTMDF13_10.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF14_10.UINT32
RCFDC0.CFDTMDF14_10.UINT16[L/H]
RCFDC0.CFDTMDF14_10.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF15_10.UINT32
RCFDC0.CFDTMDF15_10.UINT16[L/H]
RCFDC0.CFDTMDF15_10.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMID11.UINT32
RCFDC0.CFDTMID11.UINT16[L/H]
RCFDC0.CFDTMID11.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMPTR11.UINT32
RCFDC0.CFDTMPTR11.UINT16[H]
RCFDC0.CFDTMPTR11.UINT8[HH]
RCFDC0.CFDTMFDCTR11.UINT32
RCFDC0.CFDTMFDCTR11.UINT16[L/H]
RCFDC0.CFDTMFDCTR11.UINT8[LL/HL/HH]
RCFDC0.CFDTMDF0_11.UINT32
RCFDC0.CFDTMDF0_11.UINT16[L/H]
RCFDC0.CFDTMDF0_11.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF1_11.UINT32
RCFDC0.CFDTMDF1_11.UINT16[L/H]
RCFDC0.CFDTMDF1_11.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF2_11.UINT32
RCFDC0.CFDTMDF2_11.UINT16[L/H]
RCFDC0.CFDTMDF2_11.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF3_11.UINT32
RCFDC0.CFDTMDF3_11.UINT16[L/H]
RCFDC0.CFDTMDF3_11.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF4_11.UINT32
RCFDC0.CFDTMDF4_11.UINT16[L/H]
RCFDC0.CFDTMDF4_11.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF5_11.UINT32
RCFDC0.CFDTMDF5_11.UINT16[L/H]
RCFDC0.CFDTMDF5_11.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF6_11.UINT32
RCFDC0.CFDTMDF6_11.UINT16[L/H]
RCFDC0.CFDTMDF6_11.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF7_11.UINT32
RCFDC0.CFDTMDF7_11.UINT16[L/H]
RCFDC0.CFDTMDF7_11.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF8_11.UINT32
RCFDC0.CFDTMDF8_11.UINT16[L/H]
RCFDC0.CFDTMDF8_11.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF9_11.UINT32
RCFDC0.CFDTMDF9_11.UINT16[L/H]
RCFDC0.CFDTMDF9_11.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF10_11.UINT32
RCFDC0.CFDTMDF10_11.UINT16[L/H]
RCFDC0.CFDTMDF10_11.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF11_11.UINT32
RCFDC0.CFDTMDF11_11.UINT16[L/H]
RCFDC0.CFDTMDF11_11.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF12_11.UINT32
RCFDC0.CFDTMDF12_11.UINT16[L/H]
RCFDC0.CFDTMDF12_11.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF13_11.UINT32
RCFDC0.CFDTMDF13_11.UINT16[L/H]
RCFDC0.CFDTMDF13_11.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF14_11.UINT32
RCFDC0.CFDTMDF14_11.UINT16[L/H]
RCFDC0.CFDTMDF14_11.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF15_11.UINT32
RCFDC0.CFDTMDF15_11.UINT16[L/H]
RCFDC0.CFDTMDF15_11.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMID12.UINT32
RCFDC0.CFDTMID12.UINT16[L/H]
RCFDC0.CFDTMID12.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMPTR12.UINT32
RCFDC0.CFDTMPTR12.UINT16[H]
RCFDC0.CFDTMPTR12.UINT8[HH]
RCFDC0.CFDTMFDCTR12.UINT32
RCFDC0.CFDTMFDCTR12.UINT16[L/H]
RCFDC0.CFDTMFDCTR12.UINT8[LL/HL/HH]
RCFDC0.CFDTMDF0_12.UINT32
RCFDC0.CFDTMDF0_12.UINT16[L/H]
RCFDC0.CFDTMDF0_12.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF1_12.UINT32
RCFDC0.CFDTMDF1_12.UINT16[L/H]
RCFDC0.CFDTMDF1_12.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF2_12.UINT32
RCFDC0.CFDTMDF2_12.UINT16[L/H]
RCFDC0.CFDTMDF2_12.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF3_12.UINT32
RCFDC0.CFDTMDF3_12.UINT16[L/H]
RCFDC0.CFDTMDF3_12.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF4_12.UINT32
RCFDC0.CFDTMDF4_12.UINT16[L/H]
RCFDC0.CFDTMDF4_12.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF5_12.UINT32
RCFDC0.CFDTMDF5_12.UINT16[L/H]
RCFDC0.CFDTMDF5_12.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF6_12.UINT32
RCFDC0.CFDTMDF6_12.UINT16[L/H]
RCFDC0.CFDTMDF6_12.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF7_12.UINT32
RCFDC0.CFDTMDF7_12.UINT16[L/H]
RCFDC0.CFDTMDF7_12.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF8_12.UINT32
RCFDC0.CFDTMDF8_12.UINT16[L/H]
RCFDC0.CFDTMDF8_12.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF9_12.UINT32
RCFDC0.CFDTMDF9_12.UINT16[L/H]
RCFDC0.CFDTMDF9_12.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF10_12.UINT32
RCFDC0.CFDTMDF10_12.UINT16[L/H]
RCFDC0.CFDTMDF10_12.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF11_12.UINT32
RCFDC0.CFDTMDF11_12.UINT16[L/H]
RCFDC0.CFDTMDF11_12.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF12_12.UINT32
RCFDC0.CFDTMDF12_12.UINT16[L/H]
RCFDC0.CFDTMDF12_12.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF13_12.UINT32
RCFDC0.CFDTMDF13_12.UINT16[L/H]
RCFDC0.CFDTMDF13_12.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF14_12.UINT32
RCFDC0.CFDTMDF14_12.UINT16[L/H]
RCFDC0.CFDTMDF14_12.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF15_12.UINT32
RCFDC0.CFDTMDF15_12.UINT16[L/H]
RCFDC0.CFDTMDF15_12.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMID13.UINT32
RCFDC0.CFDTMID13.UINT16[L/H]
RCFDC0.CFDTMID13.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMPTR13.UINT32
RCFDC0.CFDTMPTR13.UINT16[H]
RCFDC0.CFDTMPTR13.UINT8[HH]
RCFDC0.CFDTMFDCTR13.UINT32
RCFDC0.CFDTMFDCTR13.UINT16[L/H]
RCFDC0.CFDTMFDCTR13.UINT8[LL/HL/HH]
RCFDC0.CFDTMDF0_13.UINT32
RCFDC0.CFDTMDF0_13.UINT16[L/H]
RCFDC0.CFDTMDF0_13.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF1_13.UINT32
RCFDC0.CFDTMDF1_13.UINT16[L/H]
RCFDC0.CFDTMDF1_13.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF2_13.UINT32
RCFDC0.CFDTMDF2_13.UINT16[L/H]
RCFDC0.CFDTMDF2_13.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF3_13.UINT32
RCFDC0.CFDTMDF3_13.UINT16[L/H]
RCFDC0.CFDTMDF3_13.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF4_13.UINT32
RCFDC0.CFDTMDF4_13.UINT16[L/H]
RCFDC0.CFDTMDF4_13.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF5_13.UINT32
RCFDC0.CFDTMDF5_13.UINT16[L/H]
RCFDC0.CFDTMDF5_13.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF6_13.UINT32
RCFDC0.CFDTMDF6_13.UINT16[L/H]
RCFDC0.CFDTMDF6_13.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF7_13.UINT32
RCFDC0.CFDTMDF7_13.UINT16[L/H]
RCFDC0.CFDTMDF7_13.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF8_13.UINT32
RCFDC0.CFDTMDF8_13.UINT16[L/H]
RCFDC0.CFDTMDF8_13.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF9_13.UINT32
RCFDC0.CFDTMDF9_13.UINT16[L/H]
RCFDC0.CFDTMDF9_13.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF10_13.UINT32
RCFDC0.CFDTMDF10_13.UINT16[L/H]
RCFDC0.CFDTMDF10_13.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF11_13.UINT32
RCFDC0.CFDTMDF11_13.UINT16[L/H]
RCFDC0.CFDTMDF11_13.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF12_13.UINT32
RCFDC0.CFDTMDF12_13.UINT16[L/H]
RCFDC0.CFDTMDF12_13.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF13_13.UINT32
RCFDC0.CFDTMDF13_13.UINT16[L/H]
RCFDC0.CFDTMDF13_13.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF14_13.UINT32
RCFDC0.CFDTMDF14_13.UINT16[L/H]
RCFDC0.CFDTMDF14_13.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF15_13.UINT32
RCFDC0.CFDTMDF15_13.UINT16[L/H]
RCFDC0.CFDTMDF15_13.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMID14.UINT32
RCFDC0.CFDTMID14.UINT16[L/H]
RCFDC0.CFDTMID14.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMPTR14.UINT32
RCFDC0.CFDTMPTR14.UINT16[H]
RCFDC0.CFDTMPTR14.UINT8[HH]
RCFDC0.CFDTMFDCTR14.UINT32
RCFDC0.CFDTMFDCTR14.UINT16[L/H]
RCFDC0.CFDTMFDCTR14.UINT8[LL/HL/HH]
RCFDC0.CFDTMDF0_14.UINT32
RCFDC0.CFDTMDF0_14.UINT16[L/H]
RCFDC0.CFDTMDF0_14.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF1_14.UINT32
RCFDC0.CFDTMDF1_14.UINT16[L/H]
RCFDC0.CFDTMDF1_14.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF2_14.UINT32
RCFDC0.CFDTMDF2_14.UINT16[L/H]
RCFDC0.CFDTMDF2_14.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF3_14.UINT32
RCFDC0.CFDTMDF3_14.UINT16[L/H]
RCFDC0.CFDTMDF3_14.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF4_14.UINT32
RCFDC0.CFDTMDF4_14.UINT16[L/H]
RCFDC0.CFDTMDF4_14.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF5_14.UINT32
RCFDC0.CFDTMDF5_14.UINT16[L/H]
RCFDC0.CFDTMDF5_14.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF6_14.UINT32
RCFDC0.CFDTMDF6_14.UINT16[L/H]
RCFDC0.CFDTMDF6_14.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF7_14.UINT32
RCFDC0.CFDTMDF7_14.UINT16[L/H]
RCFDC0.CFDTMDF7_14.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF8_14.UINT32
RCFDC0.CFDTMDF8_14.UINT16[L/H]
RCFDC0.CFDTMDF8_14.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF9_14.UINT32
RCFDC0.CFDTMDF9_14.UINT16[L/H]
RCFDC0.CFDTMDF9_14.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF10_14.UINT32
RCFDC0.CFDTMDF10_14.UINT16[L/H]
RCFDC0.CFDTMDF10_14.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF11_14.UINT32
RCFDC0.CFDTMDF11_14.UINT16[L/H]
RCFDC0.CFDTMDF11_14.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF12_14.UINT32
RCFDC0.CFDTMDF12_14.UINT16[L/H]
RCFDC0.CFDTMDF12_14.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF13_14.UINT32
RCFDC0.CFDTMDF13_14.UINT16[L/H]
RCFDC0.CFDTMDF13_14.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF14_14.UINT32
RCFDC0.CFDTMDF14_14.UINT16[L/H]
RCFDC0.CFDTMDF14_14.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF15_14.UINT32
RCFDC0.CFDTMDF15_14.UINT16[L/H]
RCFDC0.CFDTMDF15_14.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMID15.UINT32
RCFDC0.CFDTMID15.UINT16[L/H]
RCFDC0.CFDTMID15.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMPTR15.UINT32
RCFDC0.CFDTMPTR15.UINT16[H]
RCFDC0.CFDTMPTR15.UINT8[HH]
RCFDC0.CFDTMFDCTR15.UINT32
RCFDC0.CFDTMFDCTR15.UINT16[L/H]
RCFDC0.CFDTMFDCTR15.UINT8[LL/HL/HH]
RCFDC0.CFDTMDF0_15.UINT32
RCFDC0.CFDTMDF0_15.UINT16[L/H]
RCFDC0.CFDTMDF0_15.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF1_15.UINT32
RCFDC0.CFDTMDF1_15.UINT16[L/H]
RCFDC0.CFDTMDF1_15.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF2_15.UINT32
RCFDC0.CFDTMDF2_15.UINT16[L/H]
RCFDC0.CFDTMDF2_15.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF3_15.UINT32
RCFDC0.CFDTMDF3_15.UINT16[L/H]
RCFDC0.CFDTMDF3_15.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF4_15.UINT32
RCFDC0.CFDTMDF4_15.UINT16[L/H]
RCFDC0.CFDTMDF4_15.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF5_15.UINT32
RCFDC0.CFDTMDF5_15.UINT16[L/H]
RCFDC0.CFDTMDF5_15.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF6_15.UINT32
RCFDC0.CFDTMDF6_15.UINT16[L/H]
RCFDC0.CFDTMDF6_15.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF7_15.UINT32
RCFDC0.CFDTMDF7_15.UINT16[L/H]
RCFDC0.CFDTMDF7_15.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF8_15.UINT32
RCFDC0.CFDTMDF8_15.UINT16[L/H]
RCFDC0.CFDTMDF8_15.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF9_15.UINT32
RCFDC0.CFDTMDF9_15.UINT16[L/H]
RCFDC0.CFDTMDF9_15.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF10_15.UINT32
RCFDC0.CFDTMDF10_15.UINT16[L/H]
RCFDC0.CFDTMDF10_15.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF11_15.UINT32
RCFDC0.CFDTMDF11_15.UINT16[L/H]
RCFDC0.CFDTMDF11_15.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF12_15.UINT32
RCFDC0.CFDTMDF12_15.UINT16[L/H]
RCFDC0.CFDTMDF12_15.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF13_15.UINT32
RCFDC0.CFDTMDF13_15.UINT16[L/H]
RCFDC0.CFDTMDF13_15.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF14_15.UINT32
RCFDC0.CFDTMDF14_15.UINT16[L/H]
RCFDC0.CFDTMDF14_15.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF15_15.UINT32
RCFDC0.CFDTMDF15_15.UINT16[L/H]
RCFDC0.CFDTMDF15_15.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMID16.UINT32
RCFDC0.CFDTMID16.UINT16[L/H]
RCFDC0.CFDTMID16.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMPTR16.UINT32
RCFDC0.CFDTMPTR16.UINT16[H]
RCFDC0.CFDTMPTR16.UINT8[HH]
RCFDC0.CFDTMFDCTR16.UINT32
RCFDC0.CFDTMFDCTR16.UINT16[L/H]
RCFDC0.CFDTMFDCTR16.UINT8[LL/HL/HH]
RCFDC0.CFDTMDF0_16.UINT32
RCFDC0.CFDTMDF0_16.UINT16[L/H]
RCFDC0.CFDTMDF0_16.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF1_16.UINT32
RCFDC0.CFDTMDF1_16.UINT16[L/H]
RCFDC0.CFDTMDF1_16.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF2_16.UINT32
RCFDC0.CFDTMDF2_16.UINT16[L/H]
RCFDC0.CFDTMDF2_16.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF3_16.UINT32
RCFDC0.CFDTMDF3_16.UINT16[L/H]
RCFDC0.CFDTMDF3_16.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF4_16.UINT32
RCFDC0.CFDTMDF4_16.UINT16[L/H]
RCFDC0.CFDTMDF4_16.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF5_16.UINT32
RCFDC0.CFDTMDF5_16.UINT16[L/H]
RCFDC0.CFDTMDF5_16.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF6_16.UINT32
RCFDC0.CFDTMDF6_16.UINT16[L/H]
RCFDC0.CFDTMDF6_16.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF7_16.UINT32
RCFDC0.CFDTMDF7_16.UINT16[L/H]
RCFDC0.CFDTMDF7_16.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF8_16.UINT32
RCFDC0.CFDTMDF8_16.UINT16[L/H]
RCFDC0.CFDTMDF8_16.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF9_16.UINT32
RCFDC0.CFDTMDF9_16.UINT16[L/H]
RCFDC0.CFDTMDF9_16.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF10_16.UINT32
RCFDC0.CFDTMDF10_16.UINT16[L/H]
RCFDC0.CFDTMDF10_16.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF11_16.UINT32
RCFDC0.CFDTMDF11_16.UINT16[L/H]
RCFDC0.CFDTMDF11_16.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF12_16.UINT32
RCFDC0.CFDTMDF12_16.UINT16[L/H]
RCFDC0.CFDTMDF12_16.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF13_16.UINT32
RCFDC0.CFDTMDF13_16.UINT16[L/H]
RCFDC0.CFDTMDF13_16.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF14_16.UINT32
RCFDC0.CFDTMDF14_16.UINT16[L/H]
RCFDC0.CFDTMDF14_16.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF15_16.UINT32
RCFDC0.CFDTMDF15_16.UINT16[L/H]
RCFDC0.CFDTMDF15_16.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMID17.UINT32
RCFDC0.CFDTMID17.UINT16[L/H]
RCFDC0.CFDTMID17.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMPTR17.UINT32
RCFDC0.CFDTMPTR17.UINT16[H]
RCFDC0.CFDTMPTR17.UINT8[HH]
RCFDC0.CFDTMFDCTR17.UINT32
RCFDC0.CFDTMFDCTR17.UINT16[L/H]
RCFDC0.CFDTMFDCTR17.UINT8[LL/HL/HH]
RCFDC0.CFDTMDF0_17.UINT32
RCFDC0.CFDTMDF0_17.UINT16[L/H]
RCFDC0.CFDTMDF0_17.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF1_17.UINT32
RCFDC0.CFDTMDF1_17.UINT16[L/H]
RCFDC0.CFDTMDF1_17.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF2_17.UINT32
RCFDC0.CFDTMDF2_17.UINT16[L/H]
RCFDC0.CFDTMDF2_17.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF3_17.UINT32
RCFDC0.CFDTMDF3_17.UINT16[L/H]
RCFDC0.CFDTMDF3_17.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF4_17.UINT32
RCFDC0.CFDTMDF4_17.UINT16[L/H]
RCFDC0.CFDTMDF4_17.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF5_17.UINT32
RCFDC0.CFDTMDF5_17.UINT16[L/H]
RCFDC0.CFDTMDF5_17.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF6_17.UINT32
RCFDC0.CFDTMDF6_17.UINT16[L/H]
RCFDC0.CFDTMDF6_17.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF7_17.UINT32
RCFDC0.CFDTMDF7_17.UINT16[L/H]
RCFDC0.CFDTMDF7_17.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF8_17.UINT32
RCFDC0.CFDTMDF8_17.UINT16[L/H]
RCFDC0.CFDTMDF8_17.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF9_17.UINT32
RCFDC0.CFDTMDF9_17.UINT16[L/H]
RCFDC0.CFDTMDF9_17.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF10_17.UINT32
RCFDC0.CFDTMDF10_17.UINT16[L/H]
RCFDC0.CFDTMDF10_17.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF11_17.UINT32
RCFDC0.CFDTMDF11_17.UINT16[L/H]
RCFDC0.CFDTMDF11_17.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF12_17.UINT32
RCFDC0.CFDTMDF12_17.UINT16[L/H]
RCFDC0.CFDTMDF12_17.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF13_17.UINT32
RCFDC0.CFDTMDF13_17.UINT16[L/H]
RCFDC0.CFDTMDF13_17.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF14_17.UINT32
RCFDC0.CFDTMDF14_17.UINT16[L/H]
RCFDC0.CFDTMDF14_17.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF15_17.UINT32
RCFDC0.CFDTMDF15_17.UINT16[L/H]
RCFDC0.CFDTMDF15_17.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMID18.UINT32
RCFDC0.CFDTMID18.UINT16[L/H]
RCFDC0.CFDTMID18.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMPTR18.UINT32
RCFDC0.CFDTMPTR18.UINT16[H]
RCFDC0.CFDTMPTR18.UINT8[HH]
RCFDC0.CFDTMFDCTR18.UINT32
RCFDC0.CFDTMFDCTR18.UINT16[L/H]
RCFDC0.CFDTMFDCTR18.UINT8[LL/HL/HH]
RCFDC0.CFDTMDF0_18.UINT32
RCFDC0.CFDTMDF0_18.UINT16[L/H]
RCFDC0.CFDTMDF0_18.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF1_18.UINT32
RCFDC0.CFDTMDF1_18.UINT16[L/H]
RCFDC0.CFDTMDF1_18.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF2_18.UINT32
RCFDC0.CFDTMDF2_18.UINT16[L/H]
RCFDC0.CFDTMDF2_18.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF3_18.UINT32
RCFDC0.CFDTMDF3_18.UINT16[L/H]
RCFDC0.CFDTMDF3_18.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF4_18.UINT32
RCFDC0.CFDTMDF4_18.UINT16[L/H]
RCFDC0.CFDTMDF4_18.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF5_18.UINT32
RCFDC0.CFDTMDF5_18.UINT16[L/H]
RCFDC0.CFDTMDF5_18.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF6_18.UINT32
RCFDC0.CFDTMDF6_18.UINT16[L/H]
RCFDC0.CFDTMDF6_18.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF7_18.UINT32
RCFDC0.CFDTMDF7_18.UINT16[L/H]
RCFDC0.CFDTMDF7_18.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF8_18.UINT32
RCFDC0.CFDTMDF8_18.UINT16[L/H]
RCFDC0.CFDTMDF8_18.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF9_18.UINT32
RCFDC0.CFDTMDF9_18.UINT16[L/H]
RCFDC0.CFDTMDF9_18.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF10_18.UINT32
RCFDC0.CFDTMDF10_18.UINT16[L/H]
RCFDC0.CFDTMDF10_18.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF11_18.UINT32
RCFDC0.CFDTMDF11_18.UINT16[L/H]
RCFDC0.CFDTMDF11_18.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF12_18.UINT32
RCFDC0.CFDTMDF12_18.UINT16[L/H]
RCFDC0.CFDTMDF12_18.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF13_18.UINT32
RCFDC0.CFDTMDF13_18.UINT16[L/H]
RCFDC0.CFDTMDF13_18.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF14_18.UINT32
RCFDC0.CFDTMDF14_18.UINT16[L/H]
RCFDC0.CFDTMDF14_18.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF15_18.UINT32
RCFDC0.CFDTMDF15_18.UINT16[L/H]
RCFDC0.CFDTMDF15_18.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMID19.UINT32
RCFDC0.CFDTMID19.UINT16[L/H]
RCFDC0.CFDTMID19.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMPTR19.UINT32
RCFDC0.CFDTMPTR19.UINT16[H]
RCFDC0.CFDTMPTR19.UINT8[HH]
RCFDC0.CFDTMFDCTR19.UINT32
RCFDC0.CFDTMFDCTR19.UINT16[L/H]
RCFDC0.CFDTMFDCTR19.UINT8[LL/HL/HH]
RCFDC0.CFDTMDF0_19.UINT32
RCFDC0.CFDTMDF0_19.UINT16[L/H]
RCFDC0.CFDTMDF0_19.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF1_19.UINT32
RCFDC0.CFDTMDF1_19.UINT16[L/H]
RCFDC0.CFDTMDF1_19.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF2_19.UINT32
RCFDC0.CFDTMDF2_19.UINT16[L/H]
RCFDC0.CFDTMDF2_19.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF3_19.UINT32
RCFDC0.CFDTMDF3_19.UINT16[L/H]
RCFDC0.CFDTMDF3_19.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF4_19.UINT32
RCFDC0.CFDTMDF4_19.UINT16[L/H]
RCFDC0.CFDTMDF4_19.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF5_19.UINT32
RCFDC0.CFDTMDF5_19.UINT16[L/H]
RCFDC0.CFDTMDF5_19.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF6_19.UINT32
RCFDC0.CFDTMDF6_19.UINT16[L/H]
RCFDC0.CFDTMDF6_19.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF7_19.UINT32
RCFDC0.CFDTMDF7_19.UINT16[L/H]
RCFDC0.CFDTMDF7_19.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF8_19.UINT32
RCFDC0.CFDTMDF8_19.UINT16[L/H]
RCFDC0.CFDTMDF8_19.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF9_19.UINT32
RCFDC0.CFDTMDF9_19.UINT16[L/H]
RCFDC0.CFDTMDF9_19.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF10_19.UINT32
RCFDC0.CFDTMDF10_19.UINT16[L/H]
RCFDC0.CFDTMDF10_19.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF11_19.UINT32
RCFDC0.CFDTMDF11_19.UINT16[L/H]
RCFDC0.CFDTMDF11_19.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF12_19.UINT32
RCFDC0.CFDTMDF12_19.UINT16[L/H]
RCFDC0.CFDTMDF12_19.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF13_19.UINT32
RCFDC0.CFDTMDF13_19.UINT16[L/H]
RCFDC0.CFDTMDF13_19.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF14_19.UINT32
RCFDC0.CFDTMDF14_19.UINT16[L/H]
RCFDC0.CFDTMDF14_19.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF15_19.UINT32
RCFDC0.CFDTMDF15_19.UINT16[L/H]
RCFDC0.CFDTMDF15_19.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMID20.UINT32
RCFDC0.CFDTMID20.UINT16[L/H]
RCFDC0.CFDTMID20.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMPTR20.UINT32
RCFDC0.CFDTMPTR20.UINT16[H]
RCFDC0.CFDTMPTR20.UINT8[HH]
RCFDC0.CFDTMFDCTR20.UINT32
RCFDC0.CFDTMFDCTR20.UINT16[L/H]
RCFDC0.CFDTMFDCTR20.UINT8[LL/HL/HH]
RCFDC0.CFDTMDF0_20.UINT32
RCFDC0.CFDTMDF0_20.UINT16[L/H]
RCFDC0.CFDTMDF0_20.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF1_20.UINT32
RCFDC0.CFDTMDF1_20.UINT16[L/H]
RCFDC0.CFDTMDF1_20.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF2_20.UINT32
RCFDC0.CFDTMDF2_20.UINT16[L/H]
RCFDC0.CFDTMDF2_20.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF3_20.UINT32
RCFDC0.CFDTMDF3_20.UINT16[L/H]
RCFDC0.CFDTMDF3_20.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF4_20.UINT32
RCFDC0.CFDTMDF4_20.UINT16[L/H]
RCFDC0.CFDTMDF4_20.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF5_20.UINT32
RCFDC0.CFDTMDF5_20.UINT16[L/H]
RCFDC0.CFDTMDF5_20.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF6_20.UINT32
RCFDC0.CFDTMDF6_20.UINT16[L/H]
RCFDC0.CFDTMDF6_20.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF7_20.UINT32
RCFDC0.CFDTMDF7_20.UINT16[L/H]
RCFDC0.CFDTMDF7_20.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF8_20.UINT32
RCFDC0.CFDTMDF8_20.UINT16[L/H]
RCFDC0.CFDTMDF8_20.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF9_20.UINT32
RCFDC0.CFDTMDF9_20.UINT16[L/H]
RCFDC0.CFDTMDF9_20.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF10_20.UINT32
RCFDC0.CFDTMDF10_20.UINT16[L/H]
RCFDC0.CFDTMDF10_20.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF11_20.UINT32
RCFDC0.CFDTMDF11_20.UINT16[L/H]
RCFDC0.CFDTMDF11_20.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF12_20.UINT32
RCFDC0.CFDTMDF12_20.UINT16[L/H]
RCFDC0.CFDTMDF12_20.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF13_20.UINT32
RCFDC0.CFDTMDF13_20.UINT16[L/H]
RCFDC0.CFDTMDF13_20.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF14_20.UINT32
RCFDC0.CFDTMDF14_20.UINT16[L/H]
RCFDC0.CFDTMDF14_20.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF15_20.UINT32
RCFDC0.CFDTMDF15_20.UINT16[L/H]
RCFDC0.CFDTMDF15_20.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMID21.UINT32
RCFDC0.CFDTMID21.UINT16[L/H]
RCFDC0.CFDTMID21.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMPTR21.UINT32
RCFDC0.CFDTMPTR21.UINT16[H]
RCFDC0.CFDTMPTR21.UINT8[HH]
RCFDC0.CFDTMFDCTR21.UINT32
RCFDC0.CFDTMFDCTR21.UINT16[L/H]
RCFDC0.CFDTMFDCTR21.UINT8[LL/HL/HH]
RCFDC0.CFDTMDF0_21.UINT32
RCFDC0.CFDTMDF0_21.UINT16[L/H]
RCFDC0.CFDTMDF0_21.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF1_21.UINT32
RCFDC0.CFDTMDF1_21.UINT16[L/H]
RCFDC0.CFDTMDF1_21.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF2_21.UINT32
RCFDC0.CFDTMDF2_21.UINT16[L/H]
RCFDC0.CFDTMDF2_21.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF3_21.UINT32
RCFDC0.CFDTMDF3_21.UINT16[L/H]
RCFDC0.CFDTMDF3_21.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF4_21.UINT32
RCFDC0.CFDTMDF4_21.UINT16[L/H]
RCFDC0.CFDTMDF4_21.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF5_21.UINT32
RCFDC0.CFDTMDF5_21.UINT16[L/H]
RCFDC0.CFDTMDF5_21.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF6_21.UINT32
RCFDC0.CFDTMDF6_21.UINT16[L/H]
RCFDC0.CFDTMDF6_21.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF7_21.UINT32
RCFDC0.CFDTMDF7_21.UINT16[L/H]
RCFDC0.CFDTMDF7_21.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF8_21.UINT32
RCFDC0.CFDTMDF8_21.UINT16[L/H]
RCFDC0.CFDTMDF8_21.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF9_21.UINT32
RCFDC0.CFDTMDF9_21.UINT16[L/H]
RCFDC0.CFDTMDF9_21.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF10_21.UINT32
RCFDC0.CFDTMDF10_21.UINT16[L/H]
RCFDC0.CFDTMDF10_21.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF11_21.UINT32
RCFDC0.CFDTMDF11_21.UINT16[L/H]
RCFDC0.CFDTMDF11_21.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF12_21.UINT32
RCFDC0.CFDTMDF12_21.UINT16[L/H]
RCFDC0.CFDTMDF12_21.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF13_21.UINT32
RCFDC0.CFDTMDF13_21.UINT16[L/H]
RCFDC0.CFDTMDF13_21.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF14_21.UINT32
RCFDC0.CFDTMDF14_21.UINT16[L/H]
RCFDC0.CFDTMDF14_21.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF15_21.UINT32
RCFDC0.CFDTMDF15_21.UINT16[L/H]
RCFDC0.CFDTMDF15_21.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMID22.UINT32
RCFDC0.CFDTMID22.UINT16[L/H]
RCFDC0.CFDTMID22.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMPTR22.UINT32
RCFDC0.CFDTMPTR22.UINT16[H]
RCFDC0.CFDTMPTR22.UINT8[HH]
RCFDC0.CFDTMFDCTR22.UINT32
RCFDC0.CFDTMFDCTR22.UINT16[L/H]
RCFDC0.CFDTMFDCTR22.UINT8[LL/HL/HH]
RCFDC0.CFDTMDF0_22.UINT32
RCFDC0.CFDTMDF0_22.UINT16[L/H]
RCFDC0.CFDTMDF0_22.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF1_22.UINT32
RCFDC0.CFDTMDF1_22.UINT16[L/H]
RCFDC0.CFDTMDF1_22.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF2_22.UINT32
RCFDC0.CFDTMDF2_22.UINT16[L/H]
RCFDC0.CFDTMDF2_22.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF3_22.UINT32
RCFDC0.CFDTMDF3_22.UINT16[L/H]
RCFDC0.CFDTMDF3_22.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF4_22.UINT32
RCFDC0.CFDTMDF4_22.UINT16[L/H]
RCFDC0.CFDTMDF4_22.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF5_22.UINT32
RCFDC0.CFDTMDF5_22.UINT16[L/H]
RCFDC0.CFDTMDF5_22.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF6_22.UINT32
RCFDC0.CFDTMDF6_22.UINT16[L/H]
RCFDC0.CFDTMDF6_22.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF7_22.UINT32
RCFDC0.CFDTMDF7_22.UINT16[L/H]
RCFDC0.CFDTMDF7_22.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF8_22.UINT32
RCFDC0.CFDTMDF8_22.UINT16[L/H]
RCFDC0.CFDTMDF8_22.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF9_22.UINT32
RCFDC0.CFDTMDF9_22.UINT16[L/H]
RCFDC0.CFDTMDF9_22.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF10_22.UINT32
RCFDC0.CFDTMDF10_22.UINT16[L/H]
RCFDC0.CFDTMDF10_22.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF11_22.UINT32
RCFDC0.CFDTMDF11_22.UINT16[L/H]
RCFDC0.CFDTMDF11_22.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF12_22.UINT32
RCFDC0.CFDTMDF12_22.UINT16[L/H]
RCFDC0.CFDTMDF12_22.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF13_22.UINT32
RCFDC0.CFDTMDF13_22.UINT16[L/H]
RCFDC0.CFDTMDF13_22.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF14_22.UINT32
RCFDC0.CFDTMDF14_22.UINT16[L/H]
RCFDC0.CFDTMDF14_22.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF15_22.UINT32
RCFDC0.CFDTMDF15_22.UINT16[L/H]
RCFDC0.CFDTMDF15_22.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMID23.UINT32
RCFDC0.CFDTMID23.UINT16[L/H]
RCFDC0.CFDTMID23.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMPTR23.UINT32
RCFDC0.CFDTMPTR23.UINT16[H]
RCFDC0.CFDTMPTR23.UINT8[HH]
RCFDC0.CFDTMFDCTR23.UINT32
RCFDC0.CFDTMFDCTR23.UINT16[L/H]
RCFDC0.CFDTMFDCTR23.UINT8[LL/HL/HH]
RCFDC0.CFDTMDF0_23.UINT32
RCFDC0.CFDTMDF0_23.UINT16[L/H]
RCFDC0.CFDTMDF0_23.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF1_23.UINT32
RCFDC0.CFDTMDF1_23.UINT16[L/H]
RCFDC0.CFDTMDF1_23.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF2_23.UINT32
RCFDC0.CFDTMDF2_23.UINT16[L/H]
RCFDC0.CFDTMDF2_23.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF3_23.UINT32
RCFDC0.CFDTMDF3_23.UINT16[L/H]
RCFDC0.CFDTMDF3_23.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF4_23.UINT32
RCFDC0.CFDTMDF4_23.UINT16[L/H]
RCFDC0.CFDTMDF4_23.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF5_23.UINT32
RCFDC0.CFDTMDF5_23.UINT16[L/H]
RCFDC0.CFDTMDF5_23.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF6_23.UINT32
RCFDC0.CFDTMDF6_23.UINT16[L/H]
RCFDC0.CFDTMDF6_23.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF7_23.UINT32
RCFDC0.CFDTMDF7_23.UINT16[L/H]
RCFDC0.CFDTMDF7_23.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF8_23.UINT32
RCFDC0.CFDTMDF8_23.UINT16[L/H]
RCFDC0.CFDTMDF8_23.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF9_23.UINT32
RCFDC0.CFDTMDF9_23.UINT16[L/H]
RCFDC0.CFDTMDF9_23.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF10_23.UINT32
RCFDC0.CFDTMDF10_23.UINT16[L/H]
RCFDC0.CFDTMDF10_23.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF11_23.UINT32
RCFDC0.CFDTMDF11_23.UINT16[L/H]
RCFDC0.CFDTMDF11_23.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF12_23.UINT32
RCFDC0.CFDTMDF12_23.UINT16[L/H]
RCFDC0.CFDTMDF12_23.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF13_23.UINT32
RCFDC0.CFDTMDF13_23.UINT16[L/H]
RCFDC0.CFDTMDF13_23.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF14_23.UINT32
RCFDC0.CFDTMDF14_23.UINT16[L/H]
RCFDC0.CFDTMDF14_23.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF15_23.UINT32
RCFDC0.CFDTMDF15_23.UINT16[L/H]
RCFDC0.CFDTMDF15_23.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMID24.UINT32
RCFDC0.CFDTMID24.UINT16[L/H]
RCFDC0.CFDTMID24.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMPTR24.UINT32
RCFDC0.CFDTMPTR24.UINT16[H]
RCFDC0.CFDTMPTR24.UINT8[HH]
RCFDC0.CFDTMFDCTR24.UINT32
RCFDC0.CFDTMFDCTR24.UINT16[L/H]
RCFDC0.CFDTMFDCTR24.UINT8[LL/HL/HH]
RCFDC0.CFDTMDF0_24.UINT32
RCFDC0.CFDTMDF0_24.UINT16[L/H]
RCFDC0.CFDTMDF0_24.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF1_24.UINT32
RCFDC0.CFDTMDF1_24.UINT16[L/H]
RCFDC0.CFDTMDF1_24.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF2_24.UINT32
RCFDC0.CFDTMDF2_24.UINT16[L/H]
RCFDC0.CFDTMDF2_24.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF3_24.UINT32
RCFDC0.CFDTMDF3_24.UINT16[L/H]
RCFDC0.CFDTMDF3_24.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF4_24.UINT32
RCFDC0.CFDTMDF4_24.UINT16[L/H]
RCFDC0.CFDTMDF4_24.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF5_24.UINT32
RCFDC0.CFDTMDF5_24.UINT16[L/H]
RCFDC0.CFDTMDF5_24.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF6_24.UINT32
RCFDC0.CFDTMDF6_24.UINT16[L/H]
RCFDC0.CFDTMDF6_24.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF7_24.UINT32
RCFDC0.CFDTMDF7_24.UINT16[L/H]
RCFDC0.CFDTMDF7_24.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF8_24.UINT32
RCFDC0.CFDTMDF8_24.UINT16[L/H]
RCFDC0.CFDTMDF8_24.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF9_24.UINT32
RCFDC0.CFDTMDF9_24.UINT16[L/H]
RCFDC0.CFDTMDF9_24.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF10_24.UINT32
RCFDC0.CFDTMDF10_24.UINT16[L/H]
RCFDC0.CFDTMDF10_24.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF11_24.UINT32
RCFDC0.CFDTMDF11_24.UINT16[L/H]
RCFDC0.CFDTMDF11_24.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF12_24.UINT32
RCFDC0.CFDTMDF12_24.UINT16[L/H]
RCFDC0.CFDTMDF12_24.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF13_24.UINT32
RCFDC0.CFDTMDF13_24.UINT16[L/H]
RCFDC0.CFDTMDF13_24.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF14_24.UINT32
RCFDC0.CFDTMDF14_24.UINT16[L/H]
RCFDC0.CFDTMDF14_24.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF15_24.UINT32
RCFDC0.CFDTMDF15_24.UINT16[L/H]
RCFDC0.CFDTMDF15_24.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMID25.UINT32
RCFDC0.CFDTMID25.UINT16[L/H]
RCFDC0.CFDTMID25.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMPTR25.UINT32
RCFDC0.CFDTMPTR25.UINT16[H]
RCFDC0.CFDTMPTR25.UINT8[HH]
RCFDC0.CFDTMFDCTR25.UINT32
RCFDC0.CFDTMFDCTR25.UINT16[L/H]
RCFDC0.CFDTMFDCTR25.UINT8[LL/HL/HH]
RCFDC0.CFDTMDF0_25.UINT32
RCFDC0.CFDTMDF0_25.UINT16[L/H]
RCFDC0.CFDTMDF0_25.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF1_25.UINT32
RCFDC0.CFDTMDF1_25.UINT16[L/H]
RCFDC0.CFDTMDF1_25.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF2_25.UINT32
RCFDC0.CFDTMDF2_25.UINT16[L/H]
RCFDC0.CFDTMDF2_25.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF3_25.UINT32
RCFDC0.CFDTMDF3_25.UINT16[L/H]
RCFDC0.CFDTMDF3_25.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF4_25.UINT32
RCFDC0.CFDTMDF4_25.UINT16[L/H]
RCFDC0.CFDTMDF4_25.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF5_25.UINT32
RCFDC0.CFDTMDF5_25.UINT16[L/H]
RCFDC0.CFDTMDF5_25.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF6_25.UINT32
RCFDC0.CFDTMDF6_25.UINT16[L/H]
RCFDC0.CFDTMDF6_25.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF7_25.UINT32
RCFDC0.CFDTMDF7_25.UINT16[L/H]
RCFDC0.CFDTMDF7_25.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF8_25.UINT32
RCFDC0.CFDTMDF8_25.UINT16[L/H]
RCFDC0.CFDTMDF8_25.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF9_25.UINT32
RCFDC0.CFDTMDF9_25.UINT16[L/H]
RCFDC0.CFDTMDF9_25.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF10_25.UINT32
RCFDC0.CFDTMDF10_25.UINT16[L/H]
RCFDC0.CFDTMDF10_25.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF11_25.UINT32
RCFDC0.CFDTMDF11_25.UINT16[L/H]
RCFDC0.CFDTMDF11_25.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF12_25.UINT32
RCFDC0.CFDTMDF12_25.UINT16[L/H]
RCFDC0.CFDTMDF12_25.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF13_25.UINT32
RCFDC0.CFDTMDF13_25.UINT16[L/H]
RCFDC0.CFDTMDF13_25.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF14_25.UINT32
RCFDC0.CFDTMDF14_25.UINT16[L/H]
RCFDC0.CFDTMDF14_25.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF15_25.UINT32
RCFDC0.CFDTMDF15_25.UINT16[L/H]
RCFDC0.CFDTMDF15_25.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMID26.UINT32
RCFDC0.CFDTMID26.UINT16[L/H]
RCFDC0.CFDTMID26.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMPTR26.UINT32
RCFDC0.CFDTMPTR26.UINT16[H]
RCFDC0.CFDTMPTR26.UINT8[HH]
RCFDC0.CFDTMFDCTR26.UINT32
RCFDC0.CFDTMFDCTR26.UINT16[L/H]
RCFDC0.CFDTMFDCTR26.UINT8[LL/HL/HH]
RCFDC0.CFDTMDF0_26.UINT32
RCFDC0.CFDTMDF0_26.UINT16[L/H]
RCFDC0.CFDTMDF0_26.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF1_26.UINT32
RCFDC0.CFDTMDF1_26.UINT16[L/H]
RCFDC0.CFDTMDF1_26.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF2_26.UINT32
RCFDC0.CFDTMDF2_26.UINT16[L/H]
RCFDC0.CFDTMDF2_26.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF3_26.UINT32
RCFDC0.CFDTMDF3_26.UINT16[L/H]
RCFDC0.CFDTMDF3_26.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF4_26.UINT32
RCFDC0.CFDTMDF4_26.UINT16[L/H]
RCFDC0.CFDTMDF4_26.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF5_26.UINT32
RCFDC0.CFDTMDF5_26.UINT16[L/H]
RCFDC0.CFDTMDF5_26.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF6_26.UINT32
RCFDC0.CFDTMDF6_26.UINT16[L/H]
RCFDC0.CFDTMDF6_26.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF7_26.UINT32
RCFDC0.CFDTMDF7_26.UINT16[L/H]
RCFDC0.CFDTMDF7_26.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF8_26.UINT32
RCFDC0.CFDTMDF8_26.UINT16[L/H]
RCFDC0.CFDTMDF8_26.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF9_26.UINT32
RCFDC0.CFDTMDF9_26.UINT16[L/H]
RCFDC0.CFDTMDF9_26.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF10_26.UINT32
RCFDC0.CFDTMDF10_26.UINT16[L/H]
RCFDC0.CFDTMDF10_26.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF11_26.UINT32
RCFDC0.CFDTMDF11_26.UINT16[L/H]
RCFDC0.CFDTMDF11_26.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF12_26.UINT32
RCFDC0.CFDTMDF12_26.UINT16[L/H]
RCFDC0.CFDTMDF12_26.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF13_26.UINT32
RCFDC0.CFDTMDF13_26.UINT16[L/H]
RCFDC0.CFDTMDF13_26.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF14_26.UINT32
RCFDC0.CFDTMDF14_26.UINT16[L/H]
RCFDC0.CFDTMDF14_26.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF15_26.UINT32
RCFDC0.CFDTMDF15_26.UINT16[L/H]
RCFDC0.CFDTMDF15_26.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMID27.UINT32
RCFDC0.CFDTMID27.UINT16[L/H]
RCFDC0.CFDTMID27.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMPTR27.UINT32
RCFDC0.CFDTMPTR27.UINT16[H]
RCFDC0.CFDTMPTR27.UINT8[HH]
RCFDC0.CFDTMFDCTR27.UINT32
RCFDC0.CFDTMFDCTR27.UINT16[L/H]
RCFDC0.CFDTMFDCTR27.UINT8[LL/HL/HH]
RCFDC0.CFDTMDF0_27.UINT32
RCFDC0.CFDTMDF0_27.UINT16[L/H]
RCFDC0.CFDTMDF0_27.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF1_27.UINT32
RCFDC0.CFDTMDF1_27.UINT16[L/H]
RCFDC0.CFDTMDF1_27.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF2_27.UINT32
RCFDC0.CFDTMDF2_27.UINT16[L/H]
RCFDC0.CFDTMDF2_27.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF3_27.UINT32
RCFDC0.CFDTMDF3_27.UINT16[L/H]
RCFDC0.CFDTMDF3_27.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF4_27.UINT32
RCFDC0.CFDTMDF4_27.UINT16[L/H]
RCFDC0.CFDTMDF4_27.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF5_27.UINT32
RCFDC0.CFDTMDF5_27.UINT16[L/H]
RCFDC0.CFDTMDF5_27.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF6_27.UINT32
RCFDC0.CFDTMDF6_27.UINT16[L/H]
RCFDC0.CFDTMDF6_27.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF7_27.UINT32
RCFDC0.CFDTMDF7_27.UINT16[L/H]
RCFDC0.CFDTMDF7_27.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF8_27.UINT32
RCFDC0.CFDTMDF8_27.UINT16[L/H]
RCFDC0.CFDTMDF8_27.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF9_27.UINT32
RCFDC0.CFDTMDF9_27.UINT16[L/H]
RCFDC0.CFDTMDF9_27.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF10_27.UINT32
RCFDC0.CFDTMDF10_27.UINT16[L/H]
RCFDC0.CFDTMDF10_27.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF11_27.UINT32
RCFDC0.CFDTMDF11_27.UINT16[L/H]
RCFDC0.CFDTMDF11_27.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF12_27.UINT32
RCFDC0.CFDTMDF12_27.UINT16[L/H]
RCFDC0.CFDTMDF12_27.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF13_27.UINT32
RCFDC0.CFDTMDF13_27.UINT16[L/H]
RCFDC0.CFDTMDF13_27.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF14_27.UINT32
RCFDC0.CFDTMDF14_27.UINT16[L/H]
RCFDC0.CFDTMDF14_27.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF15_27.UINT32
RCFDC0.CFDTMDF15_27.UINT16[L/H]
RCFDC0.CFDTMDF15_27.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMID28.UINT32
RCFDC0.CFDTMID28.UINT16[L/H]
RCFDC0.CFDTMID28.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMPTR28.UINT32
RCFDC0.CFDTMPTR28.UINT16[H]
RCFDC0.CFDTMPTR28.UINT8[HH]
RCFDC0.CFDTMFDCTR28.UINT32
RCFDC0.CFDTMFDCTR28.UINT16[L/H]
RCFDC0.CFDTMFDCTR28.UINT8[LL/HL/HH]
RCFDC0.CFDTMDF0_28.UINT32
RCFDC0.CFDTMDF0_28.UINT16[L/H]
RCFDC0.CFDTMDF0_28.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF1_28.UINT32
RCFDC0.CFDTMDF1_28.UINT16[L/H]
RCFDC0.CFDTMDF1_28.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF2_28.UINT32
RCFDC0.CFDTMDF2_28.UINT16[L/H]
RCFDC0.CFDTMDF2_28.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF3_28.UINT32
RCFDC0.CFDTMDF3_28.UINT16[L/H]
RCFDC0.CFDTMDF3_28.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF4_28.UINT32
RCFDC0.CFDTMDF4_28.UINT16[L/H]
RCFDC0.CFDTMDF4_28.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF5_28.UINT32
RCFDC0.CFDTMDF5_28.UINT16[L/H]
RCFDC0.CFDTMDF5_28.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF6_28.UINT32
RCFDC0.CFDTMDF6_28.UINT16[L/H]
RCFDC0.CFDTMDF6_28.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF7_28.UINT32
RCFDC0.CFDTMDF7_28.UINT16[L/H]
RCFDC0.CFDTMDF7_28.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF8_28.UINT32
RCFDC0.CFDTMDF8_28.UINT16[L/H]
RCFDC0.CFDTMDF8_28.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF9_28.UINT32
RCFDC0.CFDTMDF9_28.UINT16[L/H]
RCFDC0.CFDTMDF9_28.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF10_28.UINT32
RCFDC0.CFDTMDF10_28.UINT16[L/H]
RCFDC0.CFDTMDF10_28.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF11_28.UINT32
RCFDC0.CFDTMDF11_28.UINT16[L/H]
RCFDC0.CFDTMDF11_28.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF12_28.UINT32
RCFDC0.CFDTMDF12_28.UINT16[L/H]
RCFDC0.CFDTMDF12_28.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF13_28.UINT32
RCFDC0.CFDTMDF13_28.UINT16[L/H]
RCFDC0.CFDTMDF13_28.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF14_28.UINT32
RCFDC0.CFDTMDF14_28.UINT16[L/H]
RCFDC0.CFDTMDF14_28.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF15_28.UINT32
RCFDC0.CFDTMDF15_28.UINT16[L/H]
RCFDC0.CFDTMDF15_28.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMID29.UINT32
RCFDC0.CFDTMID29.UINT16[L/H]
RCFDC0.CFDTMID29.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMPTR29.UINT32
RCFDC0.CFDTMPTR29.UINT16[H]
RCFDC0.CFDTMPTR29.UINT8[HH]
RCFDC0.CFDTMFDCTR29.UINT32
RCFDC0.CFDTMFDCTR29.UINT16[L/H]
RCFDC0.CFDTMFDCTR29.UINT8[LL/HL/HH]
RCFDC0.CFDTMDF0_29.UINT32
RCFDC0.CFDTMDF0_29.UINT16[L/H]
RCFDC0.CFDTMDF0_29.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF1_29.UINT32
RCFDC0.CFDTMDF1_29.UINT16[L/H]
RCFDC0.CFDTMDF1_29.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF2_29.UINT32
RCFDC0.CFDTMDF2_29.UINT16[L/H]
RCFDC0.CFDTMDF2_29.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF3_29.UINT32
RCFDC0.CFDTMDF3_29.UINT16[L/H]
RCFDC0.CFDTMDF3_29.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF4_29.UINT32
RCFDC0.CFDTMDF4_29.UINT16[L/H]
RCFDC0.CFDTMDF4_29.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF5_29.UINT32
RCFDC0.CFDTMDF5_29.UINT16[L/H]
RCFDC0.CFDTMDF5_29.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF6_29.UINT32
RCFDC0.CFDTMDF6_29.UINT16[L/H]
RCFDC0.CFDTMDF6_29.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF7_29.UINT32
RCFDC0.CFDTMDF7_29.UINT16[L/H]
RCFDC0.CFDTMDF7_29.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF8_29.UINT32
RCFDC0.CFDTMDF8_29.UINT16[L/H]
RCFDC0.CFDTMDF8_29.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF9_29.UINT32
RCFDC0.CFDTMDF9_29.UINT16[L/H]
RCFDC0.CFDTMDF9_29.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF10_29.UINT32
RCFDC0.CFDTMDF10_29.UINT16[L/H]
RCFDC0.CFDTMDF10_29.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF11_29.UINT32
RCFDC0.CFDTMDF11_29.UINT16[L/H]
RCFDC0.CFDTMDF11_29.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF12_29.UINT32
RCFDC0.CFDTMDF12_29.UINT16[L/H]
RCFDC0.CFDTMDF12_29.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF13_29.UINT32
RCFDC0.CFDTMDF13_29.UINT16[L/H]
RCFDC0.CFDTMDF13_29.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF14_29.UINT32
RCFDC0.CFDTMDF14_29.UINT16[L/H]
RCFDC0.CFDTMDF14_29.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF15_29.UINT32
RCFDC0.CFDTMDF15_29.UINT16[L/H]
RCFDC0.CFDTMDF15_29.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMID30.UINT32
RCFDC0.CFDTMID30.UINT16[L/H]
RCFDC0.CFDTMID30.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMPTR30.UINT32
RCFDC0.CFDTMPTR30.UINT16[H]
RCFDC0.CFDTMPTR30.UINT8[HH]
RCFDC0.CFDTMFDCTR30.UINT32
RCFDC0.CFDTMFDCTR30.UINT16[L/H]
RCFDC0.CFDTMFDCTR30.UINT8[LL/HL/HH]
RCFDC0.CFDTMDF0_30.UINT32
RCFDC0.CFDTMDF0_30.UINT16[L/H]
RCFDC0.CFDTMDF0_30.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF1_30.UINT32
RCFDC0.CFDTMDF1_30.UINT16[L/H]
RCFDC0.CFDTMDF1_30.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF2_30.UINT32
RCFDC0.CFDTMDF2_30.UINT16[L/H]
RCFDC0.CFDTMDF2_30.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF3_30.UINT32
RCFDC0.CFDTMDF3_30.UINT16[L/H]
RCFDC0.CFDTMDF3_30.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF4_30.UINT32
RCFDC0.CFDTMDF4_30.UINT16[L/H]
RCFDC0.CFDTMDF4_30.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF5_30.UINT32
RCFDC0.CFDTMDF5_30.UINT16[L/H]
RCFDC0.CFDTMDF5_30.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF6_30.UINT32
RCFDC0.CFDTMDF6_30.UINT16[L/H]
RCFDC0.CFDTMDF6_30.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF7_30.UINT32
RCFDC0.CFDTMDF7_30.UINT16[L/H]
RCFDC0.CFDTMDF7_30.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF8_30.UINT32
RCFDC0.CFDTMDF8_30.UINT16[L/H]
RCFDC0.CFDTMDF8_30.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF9_30.UINT32
RCFDC0.CFDTMDF9_30.UINT16[L/H]
RCFDC0.CFDTMDF9_30.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF10_30.UINT32
RCFDC0.CFDTMDF10_30.UINT16[L/H]
RCFDC0.CFDTMDF10_30.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF11_30.UINT32
RCFDC0.CFDTMDF11_30.UINT16[L/H]
RCFDC0.CFDTMDF11_30.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF12_30.UINT32
RCFDC0.CFDTMDF12_30.UINT16[L/H]
RCFDC0.CFDTMDF12_30.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF13_30.UINT32
RCFDC0.CFDTMDF13_30.UINT16[L/H]
RCFDC0.CFDTMDF13_30.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF14_30.UINT32
RCFDC0.CFDTMDF14_30.UINT16[L/H]
RCFDC0.CFDTMDF14_30.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF15_30.UINT32
RCFDC0.CFDTMDF15_30.UINT16[L/H]
RCFDC0.CFDTMDF15_30.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMID31.UINT32
RCFDC0.CFDTMID31.UINT16[L/H]
RCFDC0.CFDTMID31.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMPTR31.UINT32
RCFDC0.CFDTMPTR31.UINT16[H]
RCFDC0.CFDTMPTR31.UINT8[HH]
RCFDC0.CFDTMFDCTR31.UINT32
RCFDC0.CFDTMFDCTR31.UINT16[L/H]
RCFDC0.CFDTMFDCTR31.UINT8[LL/HL/HH]
RCFDC0.CFDTMDF0_31.UINT32
RCFDC0.CFDTMDF0_31.UINT16[L/H]
RCFDC0.CFDTMDF0_31.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF1_31.UINT32
RCFDC0.CFDTMDF1_31.UINT16[L/H]
RCFDC0.CFDTMDF1_31.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF2_31.UINT32
RCFDC0.CFDTMDF2_31.UINT16[L/H]
RCFDC0.CFDTMDF2_31.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF3_31.UINT32
RCFDC0.CFDTMDF3_31.UINT16[L/H]
RCFDC0.CFDTMDF3_31.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF4_31.UINT32
RCFDC0.CFDTMDF4_31.UINT16[L/H]
RCFDC0.CFDTMDF4_31.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF5_31.UINT32
RCFDC0.CFDTMDF5_31.UINT16[L/H]
RCFDC0.CFDTMDF5_31.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF6_31.UINT32
RCFDC0.CFDTMDF6_31.UINT16[L/H]
RCFDC0.CFDTMDF6_31.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF7_31.UINT32
RCFDC0.CFDTMDF7_31.UINT16[L/H]
RCFDC0.CFDTMDF7_31.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF8_31.UINT32
RCFDC0.CFDTMDF8_31.UINT16[L/H]
RCFDC0.CFDTMDF8_31.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF9_31.UINT32
RCFDC0.CFDTMDF9_31.UINT16[L/H]
RCFDC0.CFDTMDF9_31.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF10_31.UINT32
RCFDC0.CFDTMDF10_31.UINT16[L/H]
RCFDC0.CFDTMDF10_31.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF11_31.UINT32
RCFDC0.CFDTMDF11_31.UINT16[L/H]
RCFDC0.CFDTMDF11_31.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF12_31.UINT32
RCFDC0.CFDTMDF12_31.UINT16[L/H]
RCFDC0.CFDTMDF12_31.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF13_31.UINT32
RCFDC0.CFDTMDF13_31.UINT16[L/H]
RCFDC0.CFDTMDF13_31.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF14_31.UINT32
RCFDC0.CFDTMDF14_31.UINT16[L/H]
RCFDC0.CFDTMDF14_31.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTMDF15_31.UINT32
RCFDC0.CFDTMDF15_31.UINT16[L/H]
RCFDC0.CFDTMDF15_31.UINT8[LL/LH/HL/HH]
RCFDC0.CFDTHLACC00.UINT32
RCFDC0.CFDTHLACC00.UINT16[L/H]
RCFDC0.CFDTHLACC00.UINT8[LL/HL/HH]
RCFDC0.CFDTHLACC10.UINT32
RCFDC0.CFDTHLACC10.UINT16[L]
RCFDC0.CFDTHLACC10.UINT8[LL/LH]
RCFDC0.CFDRPGACC0.UINT32
RCFDC0.CFDRPGACC0.UINT16[L/H]
RCFDC0.CFDRPGACC0.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRPGACC1.UINT32
RCFDC0.CFDRPGACC1.UINT16[L/H]
RCFDC0.CFDRPGACC1.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRPGACC2.UINT32
RCFDC0.CFDRPGACC2.UINT16[L/H]
RCFDC0.CFDRPGACC2.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRPGACC3.UINT32
RCFDC0.CFDRPGACC3.UINT16[L/H]
RCFDC0.CFDRPGACC3.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRPGACC4.UINT32
RCFDC0.CFDRPGACC4.UINT16[L/H]
RCFDC0.CFDRPGACC4.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRPGACC5.UINT32
RCFDC0.CFDRPGACC5.UINT16[L/H]
RCFDC0.CFDRPGACC5.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRPGACC6.UINT32
RCFDC0.CFDRPGACC6.UINT16[L/H]
RCFDC0.CFDRPGACC6.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRPGACC7.UINT32
RCFDC0.CFDRPGACC7.UINT16[L/H]
RCFDC0.CFDRPGACC7.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRPGACC8.UINT32
RCFDC0.CFDRPGACC8.UINT16[L/H]
RCFDC0.CFDRPGACC8.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRPGACC9.UINT32
RCFDC0.CFDRPGACC9.UINT16[L/H]
RCFDC0.CFDRPGACC9.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRPGACC10.UINT32
RCFDC0.CFDRPGACC10.UINT16[L/H]
RCFDC0.CFDRPGACC10.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRPGACC11.UINT32
RCFDC0.CFDRPGACC11.UINT16[L/H]
RCFDC0.CFDRPGACC11.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRPGACC12.UINT32
RCFDC0.CFDRPGACC12.UINT16[L/H]
RCFDC0.CFDRPGACC12.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRPGACC13.UINT32
RCFDC0.CFDRPGACC13.UINT16[L/H]
RCFDC0.CFDRPGACC13.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRPGACC14.UINT32
RCFDC0.CFDRPGACC14.UINT16[L/H]
RCFDC0.CFDRPGACC14.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRPGACC15.UINT32
RCFDC0.CFDRPGACC15.UINT16[L/H]
RCFDC0.CFDRPGACC15.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRPGACC16.UINT32
RCFDC0.CFDRPGACC16.UINT16[L/H]
RCFDC0.CFDRPGACC16.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRPGACC17.UINT32
RCFDC0.CFDRPGACC17.UINT16[L/H]
RCFDC0.CFDRPGACC17.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRPGACC18.UINT32
RCFDC0.CFDRPGACC18.UINT16[L/H]
RCFDC0.CFDRPGACC18.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRPGACC19.UINT32
RCFDC0.CFDRPGACC19.UINT16[L/H]
RCFDC0.CFDRPGACC19.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRPGACC20.UINT32
RCFDC0.CFDRPGACC20.UINT16[L/H]
RCFDC0.CFDRPGACC20.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRPGACC21.UINT32
RCFDC0.CFDRPGACC21.UINT16[L/H]
RCFDC0.CFDRPGACC21.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRPGACC22.UINT32
RCFDC0.CFDRPGACC22.UINT16[L/H]
RCFDC0.CFDRPGACC22.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRPGACC23.UINT32
RCFDC0.CFDRPGACC23.UINT16[L/H]
RCFDC0.CFDRPGACC23.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRPGACC24.UINT32
RCFDC0.CFDRPGACC24.UINT16[L/H]
RCFDC0.CFDRPGACC24.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRPGACC25.UINT32
RCFDC0.CFDRPGACC25.UINT16[L/H]
RCFDC0.CFDRPGACC25.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRPGACC26.UINT32
RCFDC0.CFDRPGACC26.UINT16[L/H]
RCFDC0.CFDRPGACC26.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRPGACC27.UINT32
RCFDC0.CFDRPGACC27.UINT16[L/H]
RCFDC0.CFDRPGACC27.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRPGACC28.UINT32
RCFDC0.CFDRPGACC28.UINT16[L/H]
RCFDC0.CFDRPGACC28.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRPGACC29.UINT32
RCFDC0.CFDRPGACC29.UINT16[L/H]
RCFDC0.CFDRPGACC29.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRPGACC30.UINT32
RCFDC0.CFDRPGACC30.UINT16[L/H]
RCFDC0.CFDRPGACC30.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRPGACC31.UINT32
RCFDC0.CFDRPGACC31.UINT16[L/H]
RCFDC0.CFDRPGACC31.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRPGACC32.UINT32
RCFDC0.CFDRPGACC32.UINT16[L/H]
RCFDC0.CFDRPGACC32.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRPGACC33.UINT32
RCFDC0.CFDRPGACC33.UINT16[L/H]
RCFDC0.CFDRPGACC33.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRPGACC34.UINT32
RCFDC0.CFDRPGACC34.UINT16[L/H]
RCFDC0.CFDRPGACC34.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRPGACC35.UINT32
RCFDC0.CFDRPGACC35.UINT16[L/H]
RCFDC0.CFDRPGACC35.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRPGACC36.UINT32
RCFDC0.CFDRPGACC36.UINT16[L/H]
RCFDC0.CFDRPGACC36.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRPGACC37.UINT32
RCFDC0.CFDRPGACC37.UINT16[L/H]
RCFDC0.CFDRPGACC37.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRPGACC38.UINT32
RCFDC0.CFDRPGACC38.UINT16[L/H]
RCFDC0.CFDRPGACC38.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRPGACC39.UINT32
RCFDC0.CFDRPGACC39.UINT16[L/H]
RCFDC0.CFDRPGACC39.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRPGACC40.UINT32
RCFDC0.CFDRPGACC40.UINT16[L/H]
RCFDC0.CFDRPGACC40.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRPGACC41.UINT32
RCFDC0.CFDRPGACC41.UINT16[L/H]
RCFDC0.CFDRPGACC41.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRPGACC42.UINT32
RCFDC0.CFDRPGACC42.UINT16[L/H]
RCFDC0.CFDRPGACC42.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRPGACC43.UINT32
RCFDC0.CFDRPGACC43.UINT16[L/H]
RCFDC0.CFDRPGACC43.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRPGACC44.UINT32
RCFDC0.CFDRPGACC44.UINT16[L/H]
RCFDC0.CFDRPGACC44.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRPGACC45.UINT32
RCFDC0.CFDRPGACC45.UINT16[L/H]
RCFDC0.CFDRPGACC45.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRPGACC46.UINT32
RCFDC0.CFDRPGACC46.UINT16[L/H]
RCFDC0.CFDRPGACC46.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRPGACC47.UINT32
RCFDC0.CFDRPGACC47.UINT16[L/H]
RCFDC0.CFDRPGACC47.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRPGACC48.UINT32
RCFDC0.CFDRPGACC48.UINT16[L/H]
RCFDC0.CFDRPGACC48.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRPGACC49.UINT32
RCFDC0.CFDRPGACC49.UINT16[L/H]
RCFDC0.CFDRPGACC49.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRPGACC50.UINT32
RCFDC0.CFDRPGACC50.UINT16[L/H]
RCFDC0.CFDRPGACC50.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRPGACC51.UINT32
RCFDC0.CFDRPGACC51.UINT16[L/H]
RCFDC0.CFDRPGACC51.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRPGACC52.UINT32
RCFDC0.CFDRPGACC52.UINT16[L/H]
RCFDC0.CFDRPGACC52.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRPGACC53.UINT32
RCFDC0.CFDRPGACC53.UINT16[L/H]
RCFDC0.CFDRPGACC53.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRPGACC54.UINT32
RCFDC0.CFDRPGACC54.UINT16[L/H]
RCFDC0.CFDRPGACC54.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRPGACC55.UINT32
RCFDC0.CFDRPGACC55.UINT16[L/H]
RCFDC0.CFDRPGACC55.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRPGACC56.UINT32
RCFDC0.CFDRPGACC56.UINT16[L/H]
RCFDC0.CFDRPGACC56.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRPGACC57.UINT32
RCFDC0.CFDRPGACC57.UINT16[L/H]
RCFDC0.CFDRPGACC57.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRPGACC58.UINT32
RCFDC0.CFDRPGACC58.UINT16[L/H]
RCFDC0.CFDRPGACC58.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRPGACC59.UINT32
RCFDC0.CFDRPGACC59.UINT16[L/H]
RCFDC0.CFDRPGACC59.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRPGACC60.UINT32
RCFDC0.CFDRPGACC60.UINT16[L/H]
RCFDC0.CFDRPGACC60.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRPGACC61.UINT32
RCFDC0.CFDRPGACC61.UINT16[L/H]
RCFDC0.CFDRPGACC61.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRPGACC62.UINT32
RCFDC0.CFDRPGACC62.UINT16[L/H]
RCFDC0.CFDRPGACC62.UINT8[LL/LH/HL/HH]
RCFDC0.CFDRPGACC63.UINT32
RCFDC0.CFDRPGACC63.UINT16[L/H]
RCFDC0.CFDRPGACC63.UINT8[LL/LH/HL/HH]
OSTM0.CMP
OSTM0.CNT
OSTM0.TE
OSTM0.TS
OSTM0.TT
OSTM0.CTL
OSTM0.EMU
CSIH0.CTL0
CSIH0.STR0
CSIH0.STCR0
CSIH0.CTL1
CSIH0.CTL2
CSIH0.EMU.UINT8
CSIH0.EMU.BIT.SVSDIS
CSIH0.MCTL1
CSIH0.MCTL2
CSIH0.TX0W
CSIH0.TX0H
CSIH0.RX0W
CSIH0.RX0H
CSIH0.MRWP0
CSIH0.MCTL0
CSIH0.CFG0
CSIH0.CFG1
CSIH0.BRS0 ... CSIH0.BRS3
CSIG0.CTL0
CSIG0.STR0
CSIG0.STCR0
CSIG0.CTL1
CSIG0.CTL2
CSIG0.EMU.UINT8
CSIG0.EMU.BIT.SVSDIS
CSIG0.BCTL0.UINT8
CSIG0.BCTL0.BIT.SCE
CSIG0.TX0W
CSIG0.TX0H
CSIG0.RX0
CSIG0.CFG0
PIC0.SST
PIC0.SSER0
PIC0.SSER2
PIC0.HIZCEN0
PIC0.ADTEN400 ... PIC0.ADTEN402
PIC0.REG200 ... PIC0.REG203
PIC0.REG30
PIC0.REG31
PBG20.FSGD02PROT0.UINT32
PBG20.FSGD02PROT0.UINT16[L/H]
PBG20.FSGD02PROT0.UINT8[LL/HL/HH]
PBG20.FSGD02PROT1.UINT32
PBG20.FSGD02PROT1.UINT16[L/H]
PBG20.FSGD02PROT1.UINT8[LL/HL/HH]
PBG20.FSGD02PROT2.UINT32
PBG20.FSGD02PROT2.UINT16[L/H]
PBG20.FSGD02PROT2.UINT8[LL/HL/HH]
PBG20.FSGD02PROT3.UINT32
PBG20.FSGD02PROT3.UINT16[L/H]
PBG20.FSGD02PROT3.UINT8[LL/HL/HH]
PBG20.FSGD02PROT4.UINT32
PBG20.FSGD02PROT4.UINT16[L/H]
PBG20.FSGD02PROT4.UINT8[LL/HL/HH]
PBG20.FSGD02PROT5.UINT32
PBG20.FSGD02PROT5.UINT16[L/H]
PBG20.FSGD02PROT5.UINT8[LL/HL/HH]
PBG20.FSGD02PROT6.UINT32
PBG20.FSGD02PROT6.UINT16[L/H]
PBG20.FSGD02PROT6.UINT8[LL/HL/HH]
PBG20.FSGD02PROT8.UINT32
PBG20.FSGD02PROT8.UINT16[L/H]
PBG20.FSGD02PROT8.UINT8[LL/HL/HH]
PBG20.FSGD02PROT9.UINT32
PBG20.FSGD02PROT9.UINT16[L/H]
PBG20.FSGD02PROT9.UINT8[LL/HL/HH]
PBG20.FSGD02PROT10.UINT32
PBG20.FSGD02PROT10.UINT16[L/H]
PBG20.FSGD02PROT10.UINT8[LL/HL/HH]
PBG20.FSGD02PROT11.UINT32
PBG20.FSGD02PROT11.UINT16[L/H]
PBG20.FSGD02PROT11.UINT8[LL/HL/HH]
PBG20.FSGD02PROT14.UINT32
PBG20.FSGD02PROT14.UINT16[L/H]
PBG20.FSGD02PROT14.UINT8[LL/HL/HH]
PBG20.FSGD02PROT15.UINT32
PBG20.FSGD02PROT15.UINT16[L/H]
PBG20.FSGD02PROT15.UINT8[LL/HL/HH]
PBG20.ERRSLV02CTL.UINT32
PBG20.ERRSLV02CTL.UINT16[L]
PBG20.ERRSLV02CTL.UINT8[LL]
PBG20.ERRSLV02STAT.UINT32
PBG20.ERRSLV02STAT.UINT16[L]
PBG20.ERRSLV02STAT.UINT8[LL]
PBG20.ERRSLV02ADDR
PBG20.ERRSLV02TYPE.UINT32
PBG20.ERRSLV02TYPE.UINT16[L]
PBG21.FSGD09PROT0.UINT32
PBG21.FSGD09PROT0.UINT16[L/H]
PBG21.FSGD09PROT0.UINT8[LL/HL/HH]
PBG21.FSGD09PROT1.UINT32
PBG21.FSGD09PROT1.UINT16[L/H]
PBG21.FSGD09PROT1.UINT8[LL/HL/HH]
PBG21.FSGD09PROT8.UINT32
PBG21.FSGD09PROT8.UINT16[L/H]
PBG21.FSGD09PROT8.UINT8[LL/HL/HH]
PBG21.FSGD09PROT9.UINT32
PBG21.FSGD09PROT9.UINT16[L/H]
PBG21.FSGD09PROT9.UINT8[LL/HL/HH]
PBG21.ERRSLV09CTL.UINT32
PBG21.ERRSLV09CTL.UINT16[L]
PBG21.ERRSLV09CTL.UINT8[LL]
PBG21.ERRSLV09STAT.UINT32
PBG21.ERRSLV09STAT.UINT16[L]
PBG21.ERRSLV09STAT.UINT8[LL]
PBG21.ERRSLV09ADDR
PBG21.ERRSLV09TYPE.UINT32
PBG21.ERRSLV09TYPE.UINT16[L]
TAUD0.CDR0 ... TAUD0.CDR15
TAUD0.TOL
TAUD0.RDT
TAUD0.RSF
TAUD0.TRO
TAUD0.TME
TAUD0.TDL
TAUD0.TO
TAUD0.TOE
TAUD0.CNT0 ... TAUD0.CNT15
TAUD0.CMUR0 ... TAUD0.CMUR15
TAUD0.CSR0 ... TAUD0.CSR15
TAUD0.CSC0 ... TAUD0.CSC15
TAUD0.TE
TAUD0.TS
TAUD0.TT
TAUD0.CMOR0 ... TAUD0.CMOR15
TAUD0.TPS
TAUD0.BRS
TAUD0.TOM
TAUD0.TOC
TAUD0.TDE
TAUD0.TDM
TAUD0.TRE
TAUD0.TRC
TAUD0.RDE
TAUD0.RDM
TAUD0.RDS
TAUD0.RDC
TAUD0.EMU
SL_TAUD0.SELB_TAUD0I
TAUJ0.CDR0 ... TAUJ0.CDR3
TAUJ0.CNT0 ... TAUJ0.CNT3
TAUJ0.CMUR0 ... TAUJ0.CMUR3
TAUJ0.CSR0 ... TAUJ0.CSR3
TAUJ0.CSC0 ... TAUJ0.CSC3
TAUJ0.TE
TAUJ0.TS
TAUJ0.TT
TAUJ0.TO
TAUJ0.TOE
TAUJ0.TOL
TAUJ0.RDT
TAUJ0.RSF
TAUJ0.CMOR0 ... TAUJ0.CMOR3
TAUJ0.TPS
TAUJ0.BRS
TAUJ0.TOM
TAUJ0.TOC
TAUJ0.RDE
TAUJ0.RDM
TAUJ0.EMU
TAUJ2.CDR0 ... TAUJ2.CDR3
TAUJ2.CNT0 ... TAUJ2.CNT3
TAUJ2.CMUR0 ... TAUJ2.CMUR3
TAUJ2.CSR0 ... TAUJ2.CSR3
TAUJ2.CSC0 ... TAUJ2.CSC3
TAUJ2.TE
TAUJ2.TS
TAUJ2.TT
TAUJ2.TO
TAUJ2.TOE
TAUJ2.TOL
TAUJ2.RDT
TAUJ2.RSF
TAUJ2.CMOR0 ... TAUJ2.CMOR3
TAUJ2.TPS
TAUJ2.BRS
TAUJ2.TOM
TAUJ2.TOC
TAUJ2.RDE
TAUJ2.RDM
TAUJ2.EMU
TAUJ1.CDR0 ... TAUJ1.CDR3
TAUJ1.CNT0 ... TAUJ1.CNT3
TAUJ1.CMUR0 ... TAUJ1.CMUR3
TAUJ1.CSR0 ... TAUJ1.CSR3
TAUJ1.CSC0 ... TAUJ1.CSC3
TAUJ1.TE
TAUJ1.TS
TAUJ1.TT
TAUJ1.TO
TAUJ1.TOE
TAUJ1.TOL
TAUJ1.RDT
TAUJ1.RSF
TAUJ1.CMOR0 ... TAUJ1.CMOR3
TAUJ1.TPS
TAUJ1.BRS
TAUJ1.TOM
TAUJ1.TOC
TAUJ1.RDE
TAUJ1.RDM
TAUJ1.EMU
TAUJ3.CDR0 ... TAUJ3.CDR3
TAUJ3.CNT0 ... TAUJ3.CNT3
TAUJ3.CMUR0 ... TAUJ3.CMUR3
TAUJ3.CSR0 ... TAUJ3.CSR3
TAUJ3.CSC0 ... TAUJ3.CSC3
TAUJ3.TE
TAUJ3.TS
TAUJ3.TT
TAUJ3.TO
TAUJ3.TOE
TAUJ3.TOL
TAUJ3.RDT
TAUJ3.RSF
TAUJ3.CMOR0 ... TAUJ3.CMOR3
TAUJ3.TPS
TAUJ3.BRS
TAUJ3.TOM
TAUJ3.TOC
TAUJ3.RDE
TAUJ3.RDM
TAUJ3.EMU
SL_TAUJ0.SELB_TAUJ0I
SL_TAUJ2.SELB_TAUJ2I
PWSA0.CTL
PWSA0.STR
PWSA0.STC
PWSA0.EMU
PWSA0.QUE0 ... PWSA0.QUE7
PWSA0.PVCR00_01.UINT32
PWSA0.PVCR00_01.UINT16[L/H]
PWSA0.PVCR02_03.UINT32
PWSA0.PVCR02_03.UINT16[L/H]
PWSA0.PVCR04_05.UINT32
PWSA0.PVCR04_05.UINT16[L/H]
PWSA0.PVCR06_07.UINT32
PWSA0.PVCR06_07.UINT16[L/H]
PWSA0.PVCR08_09.UINT32
PWSA0.PVCR08_09.UINT16[L/H]
PWSA0.PVCR10_11.UINT32
PWSA0.PVCR10_11.UINT16[L/H]
PWSA0.PVCR12_13.UINT32
PWSA0.PVCR12_13.UINT16[L]
PWSA0.PWDDIR00 ... PWSA0.PWDDIR12
PWGA0.CSDR
PWGA0.CRDR
PWGA0.CTDR
PWGA0.RDT
PWGA0.RSF
PWGA0.CNT
PWGA0.TCR
PWGA0.TCBR
PWGA0.CTL
PWGA0.CSBR
PWGA0.CRBR
PWGA0.CTBR
PWGA1.CSDR
PWGA1.CRDR
PWGA1.CTDR
PWGA1.RDT
PWGA1.RSF
PWGA1.CNT
PWGA1.TCR
PWGA1.TCBR
PWGA1.CTL
PWGA1.CSBR
PWGA1.CRBR
PWGA1.CTBR
PWGA2.CSDR
PWGA2.CRDR
PWGA2.CTDR
PWGA2.RDT
PWGA2.RSF
PWGA2.CNT
PWGA2.TCR
PWGA2.TCBR
PWGA2.CTL
PWGA2.CSBR
PWGA2.CRBR
PWGA2.CTBR
PWGA3.CSDR
PWGA3.CRDR
PWGA3.CTDR
PWGA3.RDT
PWGA3.RSF
PWGA3.CNT
PWGA3.TCR
PWGA3.TCBR
PWGA3.CTL
PWGA3.CSBR
PWGA3.CRBR
PWGA3.CTBR
PWGA4.CSDR
PWGA4.CRDR
PWGA4.CTDR
PWGA4.RDT
PWGA4.RSF
PWGA4.CNT
PWGA4.TCR
PWGA4.TCBR
PWGA4.CTL
PWGA4.CSBR
PWGA4.CRBR
PWGA4.CTBR
PWGA5.CSDR
PWGA5.CRDR
PWGA5.CTDR
PWGA5.RDT
PWGA5.RSF
PWGA5.CNT
PWGA5.TCR
PWGA5.TCBR
PWGA5.CTL
PWGA5.CSBR
PWGA5.CRBR
PWGA5.CTBR
PWGA6.CSDR
PWGA6.CRDR
PWGA6.CTDR
PWGA6.RDT
PWGA6.RSF
PWGA6.CNT
PWGA6.TCR
PWGA6.TCBR
PWGA6.CTL
PWGA6.CSBR
PWGA6.CRBR
PWGA6.CTBR
PWGA7.CSDR
PWGA7.CRDR
PWGA7.CTDR
PWGA7.RDT
PWGA7.RSF
PWGA7.CNT
PWGA7.TCR
PWGA7.TCBR
PWGA7.CTL
PWGA7.CSBR
PWGA7.CRBR
PWGA7.CTBR
PWGA8.CSDR
PWGA8.CRDR
PWGA8.CTDR
PWGA8.RDT
PWGA8.RSF
PWGA8.CNT
PWGA8.TCR
PWGA8.TCBR
PWGA8.CTL
PWGA8.CSBR
PWGA8.CRBR
PWGA8.CTBR
PWGA9.CSDR
PWGA9.CRDR
PWGA9.CTDR
PWGA9.RDT
PWGA9.RSF
PWGA9.CNT
PWGA9.TCR
PWGA9.TCBR
PWGA9.CTL
PWGA9.CSBR
PWGA9.CRBR
PWGA9.CTBR
PWGA10.CSDR
PWGA10.CRDR
PWGA10.CTDR
PWGA10.RDT
PWGA10.RSF
PWGA10.CNT
PWGA10.TCR
PWGA10.TCBR
PWGA10.CTL
PWGA10.CSBR
PWGA10.CRBR
PWGA10.CTBR
PWGA11.CSDR
PWGA11.CRDR
PWGA11.CTDR
PWGA11.RDT
PWGA11.RSF
PWGA11.CNT
PWGA11.TCR
PWGA11.TCBR
PWGA11.CTL
PWGA11.CSBR
PWGA11.CRBR
PWGA11.CTBR
PWGA12.CSDR
PWGA12.CRDR
PWGA12.CTDR
PWGA12.RDT
PWGA12.RSF
PWGA12.CNT
PWGA12.TCR
PWGA12.TCBR
PWGA12.CTL
PWGA12.CSBR
PWGA12.CRBR
PWGA12.CTBR
PWBA0.BRS0 ... PWBA0.BRS3
PWBA0.TE
PWBA0.TS
PWBA0.TT
PWBA0.EMU
SLPWG.A0
SLPWG.PWGAPRD
SLPWG.PWGAPRDSL0
PWGA_INTF.PWGAINTF00
PWGA_INTF.PWGAINTMSK00
PWGA_INTF.PWGAINTFC00
RTCA0.CTL0.UINT8
RTCA0.CTL0.BIT.SLSB
RTCA0.CTL0.BIT.AMPM
RTCA0.CTL0.BIT.CEST
RTCA0.CTL0.BIT.CE
RTCA0.CTL1.UINT8
RTCA0.CTL1.BIT.CT0 ... RTCA0.CTL1.BIT.CT2
RTCA0.CTL1.BIT.EN1S
RTCA0.CTL1.BIT.ENALM
RTCA0.CTL1.BIT.EN1HZ
RTCA0.CTL2.UINT8
RTCA0.CTL2.BIT.WAIT
RTCA0.CTL2.BIT.WST
RTCA0.CTL2.BIT.RSUB
RTCA0.CTL2.BIT.RSST
RTCA0.CTL2.BIT.WSST
RTCA0.CTL2.BIT.WUST
RTCA0.SUBC
RTCA0.SRBU
RTCA0.SEC
RTCA0.MIN
RTCA0.HOUR
RTCA0.WEEK
RTCA0.DAY
RTCA0.MONTH
RTCA0.YEAR
RTCA0.TIME
RTCA0.CAL
RTCA0.SUBU
RTCA0.SCMP
RTCA0.ALM
RTCA0.ALH
RTCA0.ALW
RTCA0.SECC
RTCA0.MINC
RTCA0.HOURC
RTCA0.WEEKC
RTCA0.DAYC
RTCA0.MONC
RTCA0.YEARC
RTCA0.TIMEC
RTCA0.CALC
RTCA0.EMU.UINT8
RTCA0.EMU.BIT.SVSDIS
ENCA0.CCR0
ENCA0.CCR1
ENCA0.CNT
ENCA0.FLG
ENCA0.FGC
ENCA0.TE
ENCA0.TS
ENCA0.TT
ENCA0.IOC0
ENCA0.CTL
ENCA0.IOC1
ENCA0.EMU
TAPA0.FLG
TAPA0.ACWE
TAPA0.ACTS
TAPA0.ACTT
TAPA0.OPHS
TAPA0.OPHT
TAPA0.CTL0
TAPA0.CTL1
TAPA0.EMU
WDTA0.WDTE
WDTA0.EVAC
WDTA0.REF
WDTA0.MD
WDTA1.WDTE
WDTA1.EVAC
WDTA1.REF
WDTA1.MD
ADCA0.VCR00.UINT32
ADCA0.VCR00.UINT16[L]
ADCA0.VCR00.UINT8[LL/LH]
ADCA0.VCR01.UINT32
ADCA0.VCR01.UINT16[L]
ADCA0.VCR01.UINT8[LL/LH]
ADCA0.VCR02.UINT32
ADCA0.VCR02.UINT16[L]
ADCA0.VCR02.UINT8[LL/LH]
ADCA0.VCR03.UINT32
ADCA0.VCR03.UINT16[L]
ADCA0.VCR03.UINT8[LL/LH]
ADCA0.VCR04.UINT32
ADCA0.VCR04.UINT16[L]
ADCA0.VCR04.UINT8[LL/LH]
ADCA0.VCR05.UINT32
ADCA0.VCR05.UINT16[L]
ADCA0.VCR05.UINT8[LL/LH]
ADCA0.VCR06.UINT32
ADCA0.VCR06.UINT16[L]
ADCA0.VCR06.UINT8[LL/LH]
ADCA0.VCR07.UINT32
ADCA0.VCR07.UINT16[L]
ADCA0.VCR07.UINT8[LL/LH]
ADCA0.VCR08.UINT32
ADCA0.VCR08.UINT16[L]
ADCA0.VCR08.UINT8[LL/LH]
ADCA0.VCR09.UINT32
ADCA0.VCR09.UINT16[L]
ADCA0.VCR09.UINT8[LL/LH]
ADCA0.VCR10.UINT32
ADCA0.VCR10.UINT16[L]
ADCA0.VCR10.UINT8[LL/LH]
ADCA0.VCR11.UINT32
ADCA0.VCR11.UINT16[L]
ADCA0.VCR11.UINT8[LL/LH]
ADCA0.VCR12.UINT32
ADCA0.VCR12.UINT16[L]
ADCA0.VCR12.UINT8[LL/LH]
ADCA0.VCR13.UINT32
ADCA0.VCR13.UINT16[L]
ADCA0.VCR13.UINT8[LL/LH]
ADCA0.VCR14.UINT32
ADCA0.VCR14.UINT16[L]
ADCA0.VCR14.UINT8[LL/LH]
ADCA0.VCR15.UINT32
ADCA0.VCR15.UINT16[L]
ADCA0.VCR15.UINT8[LL/LH]
ADCA0.VCR16.UINT32
ADCA0.VCR16.UINT16[L]
ADCA0.VCR16.UINT8[LL/LH]
ADCA0.VCR17.UINT32
ADCA0.VCR17.UINT16[L]
ADCA0.VCR17.UINT8[LL/LH]
ADCA0.VCR18.UINT32
ADCA0.VCR18.UINT16[L]
ADCA0.VCR18.UINT8[LL/LH]
ADCA0.VCR19.UINT32
ADCA0.VCR19.UINT16[L]
ADCA0.VCR19.UINT8[LL/LH]
ADCA0.VCR33.UINT32
ADCA0.VCR33.UINT16[L]
ADCA0.VCR33.UINT8[LL/LH]
ADCA0.VCR34.UINT32
ADCA0.VCR34.UINT16[L]
ADCA0.VCR34.UINT8[LL/LH]
ADCA0.VCR35.UINT32
ADCA0.VCR35.UINT16[L]
ADCA0.VCR35.UINT8[LL/LH]
ADCA0.PWDVCR.UINT32
ADCA0.PWDVCR.UINT16[L]
ADCA0.PWDVCR.UINT8[LL/LH]
ADCA0.DR00.UINT32
ADCA0.DR00.UINT16[L/H]
ADCA0.DR02.UINT32
ADCA0.DR02.UINT16[L/H]
ADCA0.DR04.UINT32
ADCA0.DR04.UINT16[L/H]
ADCA0.DR06.UINT32
ADCA0.DR06.UINT16[L/H]
ADCA0.DR08.UINT32
ADCA0.DR08.UINT16[L/H]
ADCA0.DR10.UINT32
ADCA0.DR10.UINT16[L/H]
ADCA0.DR12.UINT32
ADCA0.DR12.UINT16[L/H]
ADCA0.DR14.UINT32
ADCA0.DR14.UINT16[L/H]
ADCA0.DR16.UINT32
ADCA0.DR16.UINT16[L/H]
ADCA0.DR18.UINT32
ADCA0.DR18.UINT16[L/H]
ADCA0.DR32.UINT32
ADCA0.DR32.UINT16[H]
ADCA0.DR34.UINT32
ADCA0.DR34.UINT16[L/H]
ADCA0.PWDTSNDR.UINT32
ADCA0.PWDTSNDR.UINT16[H]
ADCA0.DIR00 ... ADCA0.DIR19
ADCA0.DIR33 ... ADCA0.DIR35
ADCA0.PWDDIR
ADCA0.ADHALTR.UINT32
ADCA0.ADHALTR.UINT16[L]
ADCA0.ADHALTR.UINT8[LL]
ADCA0.ADCR.UINT32
ADCA0.ADCR.UINT16[L]
ADCA0.ADCR.UINT8[LL]
ADCA0.SGSTR.UINT32
ADCA0.SGSTR.UINT16[L]
ADCA0.MPXCURR.UINT32
ADCA0.MPXCURR.UINT16[L]
ADCA0.MPXCURR.UINT8[LL]
ADCA0.THSMPSTCR.UINT32
ADCA0.THSMPSTCR.UINT16[L]
ADCA0.THSMPSTCR.UINT8[LL]
ADCA0.THCR.UINT32
ADCA0.THCR.UINT16[L]
ADCA0.THCR.UINT8[LL]
ADCA0.THAHLDSTCR.UINT32
ADCA0.THAHLDSTCR.UINT16[L]
ADCA0.THAHLDSTCR.UINT8[LL]
ADCA0.THBHLDSTCR.UINT32
ADCA0.THBHLDSTCR.UINT16[L]
ADCA0.THBHLDSTCR.UINT8[LL]
ADCA0.THACR.UINT32
ADCA0.THACR.UINT16[L]
ADCA0.THACR.UINT8[LL]
ADCA0.THBCR.UINT32
ADCA0.THBCR.UINT16[L]
ADCA0.THBCR.UINT8[LL]
ADCA0.THER.UINT32
ADCA0.THER.UINT16[L]
ADCA0.THER.UINT8[LL]
ADCA0.THGSR.UINT32
ADCA0.THGSR.UINT16[L]
ADCA0.THGSR.UINT8[LL]
ADCA0.SFTCR.UINT32
ADCA0.SFTCR.UINT16[L]
ADCA0.SFTCR.UINT8[LL]
ADCA0.ULLMTBR0.UINT32
ADCA0.ULLMTBR0.UINT16[L/H]
ADCA0.ULLMTBR1.UINT32
ADCA0.ULLMTBR1.UINT16[L/H]
ADCA0.ULLMTBR2.UINT32
ADCA0.ULLMTBR2.UINT16[L/H]
ADCA0.ECR.UINT32
ADCA0.ECR.UINT16[L]
ADCA0.ECR.UINT8[LL]
ADCA0.ULER.UINT32
ADCA0.ULER.UINT16[L]
ADCA0.ULER.UINT8[LL/LH]
ADCA0.OWER.UINT32
ADCA0.OWER.UINT16[L]
ADCA0.OWER.UINT8[LL]
ADCA0.DGCTL0.UINT32
ADCA0.DGCTL0.UINT16[L]
ADCA0.DGCTL0.UINT8[LL]
ADCA0.DGCTL1.UINT32
ADCA0.DGCTL1.UINT16[L]
ADCA0.PDCTL1.UINT32
ADCA0.PDCTL1.UINT16[L]
ADCA0.PDCTL2.UINT32
ADCA0.PDCTL2.UINT16[L]
ADCA0.PDCTL2.UINT8[LL]
ADCA0.SMPCR.UINT32
ADCA0.SMPCR.UINT16[L]
ADCA0.SMPCR.UINT8[LL]
ADCA0.EMU
ADCA0.SGSTCR1.UINT32
ADCA0.SGSTCR1.UINT16[L]
ADCA0.SGSTCR1.UINT8[LL]
ADCA0.SGSTPCR1.UINT32
ADCA0.SGSTPCR1.UINT16[L]
ADCA0.SGSTPCR1.UINT8[LL]
ADCA0.SGCR1.UINT32
ADCA0.SGCR1.UINT16[L]
ADCA0.SGCR1.UINT8[LL]
ADCA0.SGVCSP1.UINT32
ADCA0.SGVCSP1.UINT16[L]
ADCA0.SGVCSP1.UINT8[LL]
ADCA0.SGVCEP1.UINT32
ADCA0.SGVCEP1.UINT16[L]
ADCA0.SGVCEP1.UINT8[LL]
ADCA0.SGMCYCR1.UINT32
ADCA0.SGMCYCR1.UINT16[L]
ADCA0.SGMCYCR1.UINT8[LL]
ADCA0.SGSEFCR1.UINT32
ADCA0.SGSEFCR1.UINT16[L]
ADCA0.SGSEFCR1.UINT8[LL]
ADCA0.SGTSEL1.UINT32
ADCA0.SGTSEL1.UINT16[L]
ADCA0.SGSTCR2.UINT32
ADCA0.SGSTCR2.UINT16[L]
ADCA0.SGSTCR2.UINT8[LL]
ADCA0.SGSTPCR2.UINT32
ADCA0.SGSTPCR2.UINT16[L]
ADCA0.SGSTPCR2.UINT8[LL]
ADCA0.SGCR2.UINT32
ADCA0.SGCR2.UINT16[L]
ADCA0.SGCR2.UINT8[LL]
ADCA0.SGVCSP2.UINT32
ADCA0.SGVCSP2.UINT16[L]
ADCA0.SGVCSP2.UINT8[LL]
ADCA0.SGVCEP2.UINT32
ADCA0.SGVCEP2.UINT16[L]
ADCA0.SGVCEP2.UINT8[LL]
ADCA0.SGMCYCR2.UINT32
ADCA0.SGMCYCR2.UINT16[L]
ADCA0.SGMCYCR2.UINT8[LL]
ADCA0.SGSEFCR2.UINT32
ADCA0.SGSEFCR2.UINT16[L]
ADCA0.SGSEFCR2.UINT8[LL]
ADCA0.SGTSEL2.UINT32
ADCA0.SGTSEL2.UINT16[L]
ADCA0.SGSTCR3.UINT32
ADCA0.SGSTCR3.UINT16[L]
ADCA0.SGSTCR3.UINT8[LL]
ADCA0.SGSTPCR3.UINT32
ADCA0.SGSTPCR3.UINT16[L]
ADCA0.SGSTPCR3.UINT8[LL]
ADCA0.SGCR3.UINT32
ADCA0.SGCR3.UINT16[L]
ADCA0.SGCR3.UINT8[LL]
ADCA0.SGVCSP3.UINT32
ADCA0.SGVCSP3.UINT16[L]
ADCA0.SGVCSP3.UINT8[LL]
ADCA0.SGVCEP3.UINT32
ADCA0.SGVCEP3.UINT16[L]
ADCA0.SGVCEP3.UINT8[LL]
ADCA0.SGMCYCR3.UINT32
ADCA0.SGMCYCR3.UINT16[L]
ADCA0.SGMCYCR3.UINT8[LL]
ADCA0.SGSEFCR3.UINT32
ADCA0.SGSEFCR3.UINT16[L]
ADCA0.SGSEFCR3.UINT8[LL]
ADCA0.SGTSEL3.UINT32
ADCA0.SGTSEL3.UINT16[L]
ADCA0.PWDSGSTPCR.UINT32
ADCA0.PWDSGSTPCR.UINT16[L]
ADCA0.PWDSGSTPCR.UINT8[LL]
ADCA0.PWDSGCR.UINT32
ADCA0.PWDSGCR.UINT16[L]
ADCA0.PWDSGCR.UINT8[LL]
ADCA0.PWDSGSEFCR.UINT32
ADCA0.PWDSGSEFCR.UINT16[L]
ADCA0.PWDSGSEFCR.UINT8[LL]
ADCA0.ULEVCFR0
ADCA0.ULEVCFR1
ADCA0.ULLMTBR3.UINT32
ADCA0.ULLMTBR3.UINT16[L/H]
ADCA0.ULLMTBR4.UINT32
ADCA0.ULLMTBR4.UINT16[L/H]
ADCA0.ULLMTBR5.UINT32
ADCA0.ULLMTBR5.UINT16[L/H]
ADCA0.ULLMTBR6.UINT32
ADCA0.ULLMTBR6.UINT16[L/H]
ADCA0.ULLMTBR7.UINT32
ADCA0.ULLMTBR7.UINT16[L/H]
ADCA0.MPXSTBTSELR0.UINT32
ADCA0.MPXSTBTSELR0.UINT16[L/H]
ADCA0.MPXSTBTSELR2.UINT32
ADCA0.MPXSTBTSELR2.UINT16[L]
ADCA0.MPXSTBTR0.UINT32
ADCA0.MPXSTBTR0.UINT16[L]
ADCA0.MPXSTBTR1.UINT32
ADCA0.MPXSTBTR1.UINT16[L]
ADCA0.MPXSTBTR2.UINT32
ADCA0.MPXSTBTR2.UINT16[L]
ADCA0.MPXSTBTR3.UINT32
ADCA0.MPXSTBTR3.UINT16[L]
ADCA0.MPXSTBTR4.UINT32
ADCA0.MPXSTBTR4.UINT16[L]
ADCA0.MPXSTBTR5.UINT32
ADCA0.MPXSTBTR5.UINT16[L]
ADCA0.MPXSTBTR6.UINT32
ADCA0.MPXSTBTR6.UINT16[L]
ADCA0.MPXSTBTR7.UINT32
ADCA0.MPXSTBTR7.UINT16[L]
DCRA0.CIN
DCRA0.COUT
DCRA0.CTL
KR0.KRM.UINT8
KR0.KRM.BIT.KRM0 ... KR0.KRM.BIT.KRM5
WPROTR.PROTCMD0
WPROTR.PROTS0
WPROTR.PROTCMD1
WPROTR.PROTS1
STBC0.PSC
STBC0.STPT
STBC_WUF0.WUF0
STBC_WUF0.WUFMSK0
STBC_WUF0.WUFC0
STBC_WUF1.WUF1
STBC_WUF1.WUFMSK1
STBC_WUF1.WUFC1
STBC_WUF20.WUF20
STBC_WUF20.WUFMSK20
STBC_WUF20.WUFC20
RESCTL.RESF
RESCTL.RESFC
RESCTL.RESFR
RESCTL.RESFCR
RESCTL.SWRESA
RESCTL.CYCRBASE
SVM.VLVF
SVM.VLVFC
SVM.LVICNT
SVM.CVMF
SVM.CVMDE
SVM.CVMDIAG
SVM.PROTCMDCVM
SVM.PROTSCVM
STBC_IOHOLD.IOHOLD
CLKCTL.ROSCE
CLKCTL.ROSCS
CLKCTL.ROSCSTPM
CLKCTL.ROSCUT
CLKCTL.MOSCE
CLKCTL.MOSCS
CLKCTL.MOSCC
CLKCTL.MOSCST
CLKCTL.MOSCSTPM
CLKCTL.MOSCM
CLKCTL.CKSC_AWDTAD_CTL
CLKCTL.CKSC_AWDTAD_ACT
CLKCTL.CKSC_AWDTAD_STPM
CLKCTL.CKSC_ATAUJS_CTL
CLKCTL.CKSC_ATAUJS_ACT
CLKCTL.CKSC_ATAUJD_CTL
CLKCTL.CKSC_ATAUJD_ACT
CLKCTL.CKSC_ATAUJD_STPM
CLKCTL.CKSC_ARTCAS_CTL
CLKCTL.CKSC_ARTCAS_ACT
CLKCTL.CKSC_ARTCAD_CTL
CLKCTL.CKSC_ARTCAD_ACT
CLKCTL.CKSC_ARTCAD_STPM
CLKCTL.CKSC_AADCAS_CTL
CLKCTL.CKSC_AADCAS_ACT
CLKCTL.CKSC_AADCAD_CTL
CLKCTL.CKSC_AADCAD_ACT
CLKCTL.CKSC_AADCAD_STPM
CLKCTL.CKSC_AFOUTS_CTL
CLKCTL.CKSC_AFOUTS_ACT
CLKCTL.CKSC_AFOUTS_STPM
CLKCTL.FOUTDIV
CLKCTL.FOUTSTAT
CLKCTL.PLL1E
CLKCTL.PLL1S
CLKCTL.PLL1C
CLKCTL.CKSC_CPUCLKS_CTL
CLKCTL.CKSC_CPUCLKS_ACT
CLKCTL.CKSC_PPLLCLKS_CTL
CLKCTL.CKSC_PPLLCLKS_ACT
CLKCTL.CKSC_CPUCLKD_CTL
CLKCTL.CKSC_CPUCLKD_ACT
CLKCTL.CKSC_IPERI1S_CTL
CLKCTL.CKSC_IPERI1S_ACT
CLKCTL.CKSC_IPERI2S_CTL
CLKCTL.CKSC_IPERI2S_ACT
CLKCTL.CKSC_ILINS_CTL
CLKCTL.CKSC_ILINS_ACT
CLKCTL.CKSC_PLL1IS_CTL
CLKCTL.CKSC_PLL1IS_ACT
CLKCTL.CKSC_ILIND_CTL
CLKCTL.CKSC_ILIND_ACT
CLKCTL.CKSC_ILIND_STPM
CLKCTL.CKSC_ICANS_CTL
CLKCTL.CKSC_ICANS_ACT
CLKCTL.CKSC_ICANS_STPM
CLKCTL.CKSC_ICANOSCD_CTL
CLKCTL.CKSC_ICANOSCD_ACT
CLKCTL.CKSC_ICANOSCD_STPM
CLKCTL.CKSC_ICSIS_CTL
CLKCTL.CKSC_ICSIS_ACT
CLKCTL.CKSC_IIICS_CTL
CLKCTL.CKSC_IIICS_ACT
LPS0.SCTLR
LPS0.EVFR
LPS0.DPSELR0
LPS0.DPSELRM.UINT32
LPS0.DPSELRM.UINT16[L/H]
LPS0.DPSELRM.UINT8[LL/LH/HL/HH]
LPS0.DPSELRM.REGS8.DPSELR1.UINT8
LPS0.DPSELRM.REGS8.DPSELR2.UINT8
LPS0.DPSELRM.REGS8.DPSELR3.UINT8
LPS0.DPSELRM.REGS8.DPSELR4.UINT8
LPS0.DPSELRH.UINT32
LPS0.DPSELRH.UINT16[L/H]
LPS0.DPSELRH.UINT8[LL/LH/HL]
LPS0.DPSELRH.REGS8.DPSELR5.UINT8
LPS0.DPSELRH.REGS8.DPSELR6.UINT8
LPS0.DPSELRH.REGS8.DPSELR7.UINT8
LPS0.DPDSR0
LPS0.DPDSRM.UINT32
LPS0.DPDSRM.UINT16[L/H]
LPS0.DPDSRM.UINT8[LL/LH/HL/HH]
LPS0.DPDSRM.REGS8.DPDSR1.UINT8
LPS0.DPDSRM.REGS8.DPDSR2.UINT8
LPS0.DPDSRM.REGS8.DPDSR3.UINT8
LPS0.DPDSRM.REGS8.DPDSR4.UINT8
LPS0.DPDSRH.UINT32
LPS0.DPDSRH.UINT16[L/H]
LPS0.DPDSRH.UINT8[LL/LH/HL]
LPS0.DPDSRH.REGS8.DPDSR5.UINT8
LPS0.DPDSRH.REGS8.DPDSR6.UINT8
LPS0.DPDSRH.REGS8.DPDSR7.UINT8
LPS0.DPDIMR0 ... LPS0.DPDIMR7
LPS0.CNTVAL
LPS0.SOSTR
STBC_WUFISO.WUF_ISO0
STBC_WUFISO.WUFMSK_ISO0
STBC_WUFISO.WUFC_ISO0
CLMA0.CTL0
CLMA0.CMPL
CLMA0.CMPH
CLMA0.PCMD
CLMA0.PS
CLMA0.EMU0
CLMA.TEST
CLMA.TESTS
CLMA.PROTCMDCLMA
CLMA.PROTSCLMA
CLMA1.CTL0
CLMA1.CMPL
CLMA1.CMPH
CLMA1.PCMD
CLMA1.PS
CLMA1.EMU0
CLMA3.CTL0
CLMA3.CMPL
CLMA3.CMPH
CLMA3.PCMD
CLMA3.PS
CLMA3.EMU0
PBG50.FSGD06PROT0.UINT32
PBG50.FSGD06PROT0.UINT16[L/H]
PBG50.FSGD06PROT0.UINT8[LL/HL/HH]
PBG50.FSGD06PROT1.UINT32
PBG50.FSGD06PROT1.UINT16[L/H]
PBG50.FSGD06PROT1.UINT8[LL/HL/HH]
PBG50.FSGD06PROT4.UINT32
PBG50.FSGD06PROT4.UINT16[L/H]
PBG50.FSGD06PROT4.UINT8[LL/HL/HH]
PBG50.FSGD06PROT5.UINT32
PBG50.FSGD06PROT5.UINT16[L/H]
PBG50.FSGD06PROT5.UINT8[LL/HL/HH]
PBG50.FSGD06PROT6.UINT32
PBG50.FSGD06PROT6.UINT16[L/H]
PBG50.FSGD06PROT6.UINT8[LL/HL/HH]
PBG50.FSGD06PROT7.UINT32
PBG50.FSGD06PROT7.UINT16[L/H]
PBG50.FSGD06PROT7.UINT8[LL/HL/HH]
PBG50.FSGD06PROT8.UINT32
PBG50.FSGD06PROT8.UINT16[L/H]
PBG50.FSGD06PROT8.UINT8[LL/HL/HH]
PBG50.ERRSLV06CTL.UINT32
PBG50.ERRSLV06CTL.UINT16[L]
PBG50.ERRSLV06CTL.UINT8[LL]
PBG50.ERRSLV06STAT.UINT32
PBG50.ERRSLV06STAT.UINT16[L]
PBG50.ERRSLV06STAT.UINT8[LL]
PBG50.ERRSLV06ADDR
PBG50.ERRSLV06TYPE.UINT32
PBG50.ERRSLV06TYPE.UINT16[L]
PBG30.FSGD03PROT0.UINT32
PBG30.FSGD03PROT0.UINT16[L/H]
PBG30.FSGD03PROT0.UINT8[LL/HL/HH]
PBG30.FSGD03PROT8.UINT32
PBG30.FSGD03PROT8.UINT16[L/H]
PBG30.FSGD03PROT8.UINT8[LL/HL/HH]
PBG30.ERRSLV03CTL.UINT32
PBG30.ERRSLV03CTL.UINT16[L]
PBG30.ERRSLV03CTL.UINT8[LL]
PBG30.ERRSLV03STAT.UINT32
PBG30.ERRSLV03STAT.UINT16[L]
PBG30.ERRSLV03STAT.UINT8[LL]
PBG30.ERRSLV03ADDR
PBG30.ERRSLV03TYPE.UINT32
PBG30.ERRSLV03TYPE.UINT16[L]
PBG31.FSGD04PROT0.UINT32
PBG31.FSGD04PROT0.UINT16[L/H]
PBG31.FSGD04PROT0.UINT8[LL/HL/HH]
PBG31.FSGD04PROT4.UINT32
PBG31.FSGD04PROT4.UINT16[L/H]
PBG31.FSGD04PROT4.UINT8[LL/HL/HH]
PBG31.FSGD04PROT8.UINT32
PBG31.FSGD04PROT8.UINT16[L/H]
PBG31.FSGD04PROT8.UINT8[LL/HL/HH]
PBG31.FSGD04PROT9.UINT32
PBG31.FSGD04PROT9.UINT16[L/H]
PBG31.FSGD04PROT9.UINT8[LL/HL/HH]
PBG31.FSGD04PROT10.UINT32
PBG31.FSGD04PROT10.UINT16[L/H]
PBG31.FSGD04PROT10.UINT8[LL/HL/HH]
PBG31.ERRSLV04CTL.UINT32
PBG31.ERRSLV04CTL.UINT16[L]
PBG31.ERRSLV04CTL.UINT8[LL]
PBG31.ERRSLV04STAT.UINT32
PBG31.ERRSLV04STAT.UINT16[L]
PBG31.ERRSLV04STAT.UINT8[LL]
PBG31.ERRSLV04ADDR
PBG31.ERRSLV04TYPE.UINT32
PBG31.ERRSLV04TYPE.UINT16[L]
PBG32.FSGD05PROT0.UINT32
PBG32.FSGD05PROT0.UINT16[L/H]
PBG32.FSGD05PROT0.UINT8[LL/HL/HH]
PBG32.FSGD05PROT1.UINT32
PBG32.FSGD05PROT1.UINT16[L/H]
PBG32.FSGD05PROT1.UINT8[LL/HL/HH]
PBG32.FSGD05PROT8.UINT32
PBG32.FSGD05PROT8.UINT16[L/H]
PBG32.FSGD05PROT8.UINT8[LL/HL/HH]
PBG32.FSGD05PROT9.UINT32
PBG32.FSGD05PROT9.UINT16[L/H]
PBG32.FSGD05PROT9.UINT8[LL/HL/HH]
PBG32.ERRSLV05CTL.UINT32
PBG32.ERRSLV05CTL.UINT16[L]
PBG32.ERRSLV05CTL.UINT8[LL]
PBG32.ERRSLV05STAT.UINT32
PBG32.ERRSLV05STAT.UINT16[L]
PBG32.ERRSLV05STAT.UINT8[LL]
PBG32.ERRSLV05ADDR
PBG32.ERRSLV05TYPE.UINT32
PBG32.ERRSLV05TYPE.UINT16[L]
IPG.ECRUM.UINT16
IPG.ECRUM.UINT8[L]
IPG.ADRUM.UINT32
IPG.ADRUM.UINT16[L/H]
IPG.ADRUM.UINT8[LL/LH/HL/HH]
IPG.ENUM
IPG.PMTUM0
IPG.PMTUM2 ... IPG.PMTUM4
PEG.SP.UINT32
PEG.SP.UINT16[L]
PEG.SP.UINT8[LL]
PEG.G0MK.UINT32
PEG.G0MK.UINT16[L/H]
PEG.G0MK.UINT8[LH/HL/HH]
PEG.G0BA.UINT32
PEG.G0BA.UINT16[L/H]
PEG.G0BA.UINT8[LL/LH/HL/HH]
PEG.G1MK.UINT32
PEG.G1MK.UINT16[L/H]
PEG.G1MK.UINT8[LH/HL/HH]
PEG.G1BA.UINT32
PEG.G1BA.UINT16[L/H]
PEG.G1BA.UINT8[LL/LH/HL/HH]
PEG.G2MK.UINT32
PEG.G2MK.UINT16[L/H]
PEG.G2MK.UINT8[LH/HL/HH]
PEG.G2BA.UINT32
PEG.G2BA.UINT16[L/H]
PEG.G2BA.UINT8[LL/LH/HL/HH]
PEG.G3MK.UINT32
PEG.G3MK.UINT16[L/H]
PEG.G3MK.UINT8[LH/HL/HH]
PEG.G3BA.UINT32
PEG.G3BA.UINT16[L/H]
PEG.G3BA.UINT8[LL/LH/HL/HH]
SEG.CONT
SEG.FLAG
SEG.ADDR
INTC1.ICTAUD0I0.UINT16
INTC1.ICTAUD0I0.UINT8[L/H]
INTC1.ICTAUD0I0.BIT.P0TAUD0I0
INTC1.ICTAUD0I0.BIT.P1TAUD0I0
INTC1.ICTAUD0I0.BIT.P2TAUD0I0
INTC1.ICTAUD0I0.BIT.P3TAUD0I0
INTC1.ICTAUD0I0.BIT.TBTAUD0I0
INTC1.ICTAUD0I0.BIT.MKTAUD0I0
INTC1.ICTAUD0I0.BIT.RFTAUD0I0
INTC1.ICTAUD0I0.BIT.CTTAUD0I0
INTC1.ICTAUD0I2.UINT16
INTC1.ICTAUD0I2.UINT8[L/H]
INTC1.ICTAUD0I2.BIT.P0TAUD0I2
INTC1.ICTAUD0I2.BIT.P1TAUD0I2
INTC1.ICTAUD0I2.BIT.P2TAUD0I2
INTC1.ICTAUD0I2.BIT.P3TAUD0I2
INTC1.ICTAUD0I2.BIT.TBTAUD0I2
INTC1.ICTAUD0I2.BIT.MKTAUD0I2
INTC1.ICTAUD0I2.BIT.RFTAUD0I2
INTC1.ICTAUD0I2.BIT.CTTAUD0I2
INTC1.ICTAUD0I4.UINT16
INTC1.ICTAUD0I4.UINT8[L/H]
INTC1.ICTAUD0I4.BIT.P0TAUD0I4
INTC1.ICTAUD0I4.BIT.P1TAUD0I4
INTC1.ICTAUD0I4.BIT.P2TAUD0I4
INTC1.ICTAUD0I4.BIT.P3TAUD0I4
INTC1.ICTAUD0I4.BIT.TBTAUD0I4
INTC1.ICTAUD0I4.BIT.MKTAUD0I4
INTC1.ICTAUD0I4.BIT.RFTAUD0I4
INTC1.ICTAUD0I4.BIT.CTTAUD0I4
INTC1.ICTAUD0I6.UINT16
INTC1.ICTAUD0I6.UINT8[L/H]
INTC1.ICTAUD0I6.BIT.P0TAUD0I6
INTC1.ICTAUD0I6.BIT.P1TAUD0I6
INTC1.ICTAUD0I6.BIT.P2TAUD0I6
INTC1.ICTAUD0I6.BIT.P3TAUD0I6
INTC1.ICTAUD0I6.BIT.TBTAUD0I6
INTC1.ICTAUD0I6.BIT.MKTAUD0I6
INTC1.ICTAUD0I6.BIT.RFTAUD0I6
INTC1.ICTAUD0I6.BIT.CTTAUD0I6
INTC1.ICTAUD0I8.UINT16
INTC1.ICTAUD0I8.UINT8[L/H]
INTC1.ICTAUD0I8.BIT.P0TAUD0I8
INTC1.ICTAUD0I8.BIT.P1TAUD0I8
INTC1.ICTAUD0I8.BIT.P2TAUD0I8
INTC1.ICTAUD0I8.BIT.P3TAUD0I8
INTC1.ICTAUD0I8.BIT.TBTAUD0I8
INTC1.ICTAUD0I8.BIT.MKTAUD0I8
INTC1.ICTAUD0I8.BIT.RFTAUD0I8
INTC1.ICTAUD0I8.BIT.CTTAUD0I8
INTC1.ICTAUD0I10.UINT16
INTC1.ICTAUD0I10.UINT8[L/H]
INTC1.ICTAUD0I10.BIT.P0TAUD0I10
INTC1.ICTAUD0I10.BIT.P1TAUD0I10
INTC1.ICTAUD0I10.BIT.P2TAUD0I10
INTC1.ICTAUD0I10.BIT.P3TAUD0I10
INTC1.ICTAUD0I10.BIT.TBTAUD0I10
INTC1.ICTAUD0I10.BIT.MKTAUD0I10
INTC1.ICTAUD0I10.BIT.RFTAUD0I10
INTC1.ICTAUD0I10.BIT.CTTAUD0I10
INTC1.ICTAUD0I12.UINT16
INTC1.ICTAUD0I12.UINT8[L/H]
INTC1.ICTAUD0I12.BIT.P0TAUD0I12
INTC1.ICTAUD0I12.BIT.P1TAUD0I12
INTC1.ICTAUD0I12.BIT.P2TAUD0I12
INTC1.ICTAUD0I12.BIT.P3TAUD0I12
INTC1.ICTAUD0I12.BIT.TBTAUD0I12
INTC1.ICTAUD0I12.BIT.MKTAUD0I12
INTC1.ICTAUD0I12.BIT.RFTAUD0I12
INTC1.ICTAUD0I12.BIT.CTTAUD0I12
INTC1.ICTAUD0I14.UINT16
INTC1.ICTAUD0I14.UINT8[L/H]
INTC1.ICTAUD0I14.BIT.P0TAUD0I14
INTC1.ICTAUD0I14.BIT.P1TAUD0I14
INTC1.ICTAUD0I14.BIT.P2TAUD0I14
INTC1.ICTAUD0I14.BIT.P3TAUD0I14
INTC1.ICTAUD0I14.BIT.TBTAUD0I14
INTC1.ICTAUD0I14.BIT.MKTAUD0I14
INTC1.ICTAUD0I14.BIT.RFTAUD0I14
INTC1.ICTAUD0I14.BIT.CTTAUD0I14
INTC1.ICTAPA0IPEK0.UINT16
INTC1.ICTAPA0IPEK0.UINT8[L/H]
INTC1.ICTAPA0IPEK0.BIT.P0TAPA0IPEK0
INTC1.ICTAPA0IPEK0.BIT.P1TAPA0IPEK0
INTC1.ICTAPA0IPEK0.BIT.P2TAPA0IPEK0
INTC1.ICTAPA0IPEK0.BIT.P3TAPA0IPEK0
INTC1.ICTAPA0IPEK0.BIT.TBTAPA0IPEK0
INTC1.ICTAPA0IPEK0.BIT.MKTAPA0IPEK0
INTC1.ICTAPA0IPEK0.BIT.RFTAPA0IPEK0
INTC1.ICTAPA0IPEK0.BIT.CTTAPA0IPEK0
INTC1.ICTAPA0IVLY0.UINT16
INTC1.ICTAPA0IVLY0.UINT8[L/H]
INTC1.ICTAPA0IVLY0.BIT.P0TAPA0IVLY0
INTC1.ICTAPA0IVLY0.BIT.P1TAPA0IVLY0
INTC1.ICTAPA0IVLY0.BIT.P2TAPA0IVLY0
INTC1.ICTAPA0IVLY0.BIT.P3TAPA0IVLY0
INTC1.ICTAPA0IVLY0.BIT.TBTAPA0IVLY0
INTC1.ICTAPA0IVLY0.BIT.MKTAPA0IVLY0
INTC1.ICTAPA0IVLY0.BIT.RFTAPA0IVLY0
INTC1.ICTAPA0IVLY0.BIT.CTTAPA0IVLY0
INTC1.ICADCA0I0.UINT16
INTC1.ICADCA0I0.UINT8[L/H]
INTC1.ICADCA0I0.BIT.P0ADCA0I0
INTC1.ICADCA0I0.BIT.P1ADCA0I0
INTC1.ICADCA0I0.BIT.P2ADCA0I0
INTC1.ICADCA0I0.BIT.P3ADCA0I0
INTC1.ICADCA0I0.BIT.TBADCA0I0
INTC1.ICADCA0I0.BIT.MKADCA0I0
INTC1.ICADCA0I0.BIT.RFADCA0I0
INTC1.ICADCA0I0.BIT.CTADCA0I0
INTC1.ICADCA0I1.UINT16
INTC1.ICADCA0I1.UINT8[L/H]
INTC1.ICADCA0I1.BIT.P0ADCA0I1
INTC1.ICADCA0I1.BIT.P1ADCA0I1
INTC1.ICADCA0I1.BIT.P2ADCA0I1
INTC1.ICADCA0I1.BIT.P3ADCA0I1
INTC1.ICADCA0I1.BIT.TBADCA0I1
INTC1.ICADCA0I1.BIT.MKADCA0I1
INTC1.ICADCA0I1.BIT.RFADCA0I1
INTC1.ICADCA0I1.BIT.CTADCA0I1
INTC1.ICADCA0I2.UINT16
INTC1.ICADCA0I2.UINT16
INTC1.ICADCA0I2.UINT8[L/H]
INTC1.ICADCA0I2.REGS8.ICCSIH0IJC_1L.UINT8
INTC1.ICADCA0I2.REGS8.ICCSIH0IJC_1H.UINT8
INTC1.ICADCA0I2.BIT.P0ADCA0I2
INTC1.ICADCA0I2.BIT.P0CSIH0IJC_1
INTC1.ICADCA0I2.BIT.P1ADCA0I2
INTC1.ICADCA0I2.BIT.P1CSIH0IJC_1
INTC1.ICADCA0I2.BIT.P2ADCA0I2
INTC1.ICADCA0I2.BIT.P2CSIH0IJC_1
INTC1.ICADCA0I2.BIT.P3ADCA0I2
INTC1.ICADCA0I2.BIT.P3CSIH0IJC_1
INTC1.ICADCA0I2.BIT.TBADCA0I2
INTC1.ICADCA0I2.BIT.TBCSIH0IJC_1
INTC1.ICADCA0I2.BIT.MKADCA0I2
INTC1.ICADCA0I2.BIT.MKCSIH0IJC_1
INTC1.ICADCA0I2.BIT.RFADCA0I2
INTC1.ICADCA0I2.BIT.RFCSIH0IJC_1
INTC1.ICADCA0I2.BIT.CTADCA0I2
INTC1.ICADCA0I2.BIT.CTCSIH0IJC_1
INTC1.ICDCUTDI.UINT16
INTC1.ICDCUTDI.UINT8[L/H]
INTC1.ICDCUTDI.BIT.P0DCUTDI
INTC1.ICDCUTDI.BIT.P1DCUTDI
INTC1.ICDCUTDI.BIT.P2DCUTDI
INTC1.ICDCUTDI.BIT.P3DCUTDI
INTC1.ICDCUTDI.BIT.TBDCUTDI
INTC1.ICDCUTDI.BIT.MKDCUTDI
INTC1.ICDCUTDI.BIT.RFDCUTDI
INTC1.ICDCUTDI.BIT.CTDCUTDI
INTC1.ICRCANGERR0.UINT16
INTC1.ICRCANGERR0.UINT8[L/H]
INTC1.ICRCANGERR0.BIT.P0RCANGERR0
INTC1.ICRCANGERR0.BIT.P1RCANGERR0
INTC1.ICRCANGERR0.BIT.P2RCANGERR0
INTC1.ICRCANGERR0.BIT.P3RCANGERR0
INTC1.ICRCANGERR0.BIT.TBRCANGERR0
INTC1.ICRCANGERR0.BIT.MKRCANGERR0
INTC1.ICRCANGERR0.BIT.RFRCANGERR0
INTC1.ICRCANGERR0.BIT.CTRCANGERR0
INTC1.ICRCANGRECC0.UINT16
INTC1.ICRCANGRECC0.UINT8[L/H]
INTC1.ICRCANGRECC0.BIT.P0RCANGRECC0
INTC1.ICRCANGRECC0.BIT.P1RCANGRECC0
INTC1.ICRCANGRECC0.BIT.P2RCANGRECC0
INTC1.ICRCANGRECC0.BIT.P3RCANGRECC0
INTC1.ICRCANGRECC0.BIT.TBRCANGRECC0
INTC1.ICRCANGRECC0.BIT.MKRCANGRECC0
INTC1.ICRCANGRECC0.BIT.RFRCANGRECC0
INTC1.ICRCANGRECC0.BIT.CTRCANGRECC0
INTC1.ICRCAN0ERR.UINT16
INTC1.ICRCAN0ERR.UINT8[L/H]
INTC1.ICRCAN0ERR.BIT.P0RCAN0ERR
INTC1.ICRCAN0ERR.BIT.P1RCAN0ERR
INTC1.ICRCAN0ERR.BIT.P2RCAN0ERR
INTC1.ICRCAN0ERR.BIT.P3RCAN0ERR
INTC1.ICRCAN0ERR.BIT.TBRCAN0ERR
INTC1.ICRCAN0ERR.BIT.MKRCAN0ERR
INTC1.ICRCAN0ERR.BIT.RFRCAN0ERR
INTC1.ICRCAN0ERR.BIT.CTRCAN0ERR
INTC1.ICRCAN0REC.UINT16
INTC1.ICRCAN0REC.UINT8[L/H]
INTC1.ICRCAN0REC.BIT.P0RCAN0REC
INTC1.ICRCAN0REC.BIT.P1RCAN0REC
INTC1.ICRCAN0REC.BIT.P2RCAN0REC
INTC1.ICRCAN0REC.BIT.P3RCAN0REC
INTC1.ICRCAN0REC.BIT.TBRCAN0REC
INTC1.ICRCAN0REC.BIT.MKRCAN0REC
INTC1.ICRCAN0REC.BIT.RFRCAN0REC
INTC1.ICRCAN0REC.BIT.CTRCAN0REC
INTC1.ICRCAN0TRX.UINT16
INTC1.ICRCAN0TRX.UINT8[L/H]
INTC1.ICRCAN0TRX.BIT.P0RCAN0TRX
INTC1.ICRCAN0TRX.BIT.P1RCAN0TRX
INTC1.ICRCAN0TRX.BIT.P2RCAN0TRX
INTC1.ICRCAN0TRX.BIT.P3RCAN0TRX
INTC1.ICRCAN0TRX.BIT.TBRCAN0TRX
INTC1.ICRCAN0TRX.BIT.MKRCAN0TRX
INTC1.ICRCAN0TRX.BIT.RFRCAN0TRX
INTC1.ICRCAN0TRX.BIT.CTRCAN0TRX
INTC1.ICCSIG0IC.UINT16
INTC1.ICCSIG0IC.UINT8[L/H]
INTC1.ICCSIG0IC.BIT.P0CSIG0IC
INTC1.ICCSIG0IC.BIT.P1CSIG0IC
INTC1.ICCSIG0IC.BIT.P2CSIG0IC
INTC1.ICCSIG0IC.BIT.P3CSIG0IC
INTC1.ICCSIG0IC.BIT.TBCSIG0IC
INTC1.ICCSIG0IC.BIT.MKCSIG0IC
INTC1.ICCSIG0IC.BIT.RFCSIG0IC
INTC1.ICCSIG0IC.BIT.CTCSIG0IC
INTC1.ICCSIG0IR.UINT16
INTC1.ICCSIG0IR.UINT8[L/H]
INTC1.ICCSIG0IR.BIT.P0CSIG0IR
INTC1.ICCSIG0IR.BIT.P1CSIG0IR
INTC1.ICCSIG0IR.BIT.P2CSIG0IR
INTC1.ICCSIG0IR.BIT.P3CSIG0IR
INTC1.ICCSIG0IR.BIT.TBCSIG0IR
INTC1.ICCSIG0IR.BIT.MKCSIG0IR
INTC1.ICCSIG0IR.BIT.RFCSIG0IR
INTC1.ICCSIG0IR.BIT.CTCSIG0IR
INTC1.ICCSIH0IC.UINT16
INTC1.ICCSIH0IC.UINT8[L/H]
INTC1.ICCSIH0IC.BIT.P0CSIH0IC
INTC1.ICCSIH0IC.BIT.P1CSIH0IC
INTC1.ICCSIH0IC.BIT.P2CSIH0IC
INTC1.ICCSIH0IC.BIT.P3CSIH0IC
INTC1.ICCSIH0IC.BIT.TBCSIH0IC
INTC1.ICCSIH0IC.BIT.MKCSIH0IC
INTC1.ICCSIH0IC.BIT.RFCSIH0IC
INTC1.ICCSIH0IC.BIT.CTCSIH0IC
INTC1.ICCSIH0IR.UINT16
INTC1.ICCSIH0IR.UINT8[L/H]
INTC1.ICCSIH0IR.BIT.P0CSIH0IR
INTC1.ICCSIH0IR.BIT.P1CSIH0IR
INTC1.ICCSIH0IR.BIT.P2CSIH0IR
INTC1.ICCSIH0IR.BIT.P3CSIH0IR
INTC1.ICCSIH0IR.BIT.TBCSIH0IR
INTC1.ICCSIH0IR.BIT.MKCSIH0IR
INTC1.ICCSIH0IR.BIT.RFCSIH0IR
INTC1.ICCSIH0IR.BIT.CTCSIH0IR
INTC1.ICCSIH0IRE.UINT16
INTC1.ICCSIH0IRE.UINT8[L/H]
INTC1.ICCSIH0IRE.BIT.P0CSIH0IRE
INTC1.ICCSIH0IRE.BIT.P1CSIH0IRE
INTC1.ICCSIH0IRE.BIT.P2CSIH0IRE
INTC1.ICCSIH0IRE.BIT.P3CSIH0IRE
INTC1.ICCSIH0IRE.BIT.TBCSIH0IRE
INTC1.ICCSIH0IRE.BIT.MKCSIH0IRE
INTC1.ICCSIH0IRE.BIT.RFCSIH0IRE
INTC1.ICCSIH0IRE.BIT.CTCSIH0IRE
INTC1.FNC.UINT16
INTC1.FNC.UINT8[H]
INTC1.FNC.BIT.FNRF
INTC1.FIC.UINT16
INTC1.FIC.UINT8[H]
INTC1.FIC.BIT.FIRF
INTC1.IMR0.UINT32
INTC1.IMR0.UINT16[L/H]
INTC1.IMR0.UINT8[LH/HL/HH]
INTC1.IMR0.BIT.IMR0EIMK8 ... INTC1.IMR0.BIT.IMR0EIMK31
PDMA0.DMACTL
PDMA0.DMACER
PDMA0.DM0CMV
PDMA0.DM1CMV
PDMA0.CMVC
PDMA0.DM00CM
PDMA0.DM01CM
PDMA0.DM02CM
PDMA0.DM03CM
PDMA0.DM04CM
PDMA0.DM05CM
PDMA0.DM06CM
PDMA0.DM07CM
PDMA0.DM10CM
PDMA0.DM11CM
PDMA0.DM12CM
PDMA0.DM13CM
PDMA0.DM14CM
PDMA0.DM15CM
PDMA0.DM16CM
PDMA0.DM17CM
PDMA0.DSA0
PDMA0.DDA0
PDMA0.DTC0
PDMA0.DTCT0
PDMA0.DRSA0
PDMA0.DRDA0
PDMA0.DRTC0
PDMA0.DCEN0
PDMA0.DCST0
PDMA0.DCSTS0
PDMA0.DCSTC0
PDMA0.DTFR0
PDMA0.DTFRRQ0
PDMA0.DTFRRQC0
PDMA0.DSA1
PDMA0.DDA1
PDMA0.DTC1
PDMA0.DTCT1
PDMA0.DRSA1
PDMA0.DRDA1
PDMA0.DRTC1
PDMA0.DCEN1
PDMA0.DCST1
PDMA0.DCSTS1
PDMA0.DCSTC1
PDMA0.DTFR1
PDMA0.DTFRRQ1
PDMA0.DTFRRQC1
PDMA0.DSA2
PDMA0.DDA2
PDMA0.DTC2
PDMA0.DTCT2
PDMA0.DRSA2
PDMA0.DRDA2
PDMA0.DRTC2
PDMA0.DCEN2
PDMA0.DCST2
PDMA0.DCSTS2
PDMA0.DCSTC2
PDMA0.DTFR2
PDMA0.DTFRRQ2
PDMA0.DTFRRQC2
PDMA0.DSA3
PDMA0.DDA3
PDMA0.DTC3
PDMA0.DTCT3
PDMA0.DRSA3
PDMA0.DRDA3
PDMA0.DRTC3
PDMA0.DCEN3
PDMA0.DCST3
PDMA0.DCSTS3
PDMA0.DCSTC3
PDMA0.DTFR3
PDMA0.DTFRRQ3
PDMA0.DTFRRQC3
PDMA0.DSA4
PDMA0.DDA4
PDMA0.DTC4
PDMA0.DTCT4
PDMA0.DRSA4
PDMA0.DRDA4
PDMA0.DRTC4
PDMA0.DCEN4
PDMA0.DCST4
PDMA0.DCSTS4
PDMA0.DCSTC4
PDMA0.DTFR4
PDMA0.DTFRRQ4
PDMA0.DTFRRQC4
PDMA0.DSA5
PDMA0.DDA5
PDMA0.DTC5
PDMA0.DTCT5
PDMA0.DRSA5
PDMA0.DRDA5
PDMA0.DRTC5
PDMA0.DCEN5
PDMA0.DCST5
PDMA0.DCSTS5
PDMA0.DCSTC5
PDMA0.DTFR5
PDMA0.DTFRRQ5
PDMA0.DTFRRQC5
PDMA0.DSA6
PDMA0.DDA6
PDMA0.DTC6
PDMA0.DTCT6
PDMA0.DRSA6
PDMA0.DRDA6
PDMA0.DRTC6
PDMA0.DCEN6
PDMA0.DCST6
PDMA0.DCSTS6
PDMA0.DCSTC6
PDMA0.DTFR6
PDMA0.DTFRRQ6
PDMA0.DTFRRQC6
PDMA0.DSA7
PDMA0.DDA7
PDMA0.DTC7
PDMA0.DTCT7
PDMA0.DRSA7
PDMA0.DRDA7
PDMA0.DRTC7
PDMA0.DCEN7
PDMA0.DCST7
PDMA0.DCSTS7
PDMA0.DCSTC7
PDMA0.DTFR7
PDMA0.DTFRRQ7
PDMA0.DTFRRQC7
PDMA0.DSA8
PDMA0.DDA8
PDMA0.DTC8
PDMA0.DTCT8
PDMA0.DRSA8
PDMA0.DRDA8
PDMA0.DRTC8
PDMA0.DCEN8
PDMA0.DCST8
PDMA0.DCSTS8
PDMA0.DCSTC8
PDMA0.DTFR8
PDMA0.DTFRRQ8
PDMA0.DTFRRQC8
PDMA0.DSA9
PDMA0.DDA9
PDMA0.DTC9
PDMA0.DTCT9
PDMA0.DRSA9
PDMA0.DRDA9
PDMA0.DRTC9
PDMA0.DCEN9
PDMA0.DCST9
PDMA0.DCSTS9
PDMA0.DCSTC9
PDMA0.DTFR9
PDMA0.DTFRRQ9
PDMA0.DTFRRQC9
PDMA0.DSA10
PDMA0.DDA10
PDMA0.DTC10
PDMA0.DTCT10
PDMA0.DRSA10
PDMA0.DRDA10
PDMA0.DRTC10
PDMA0.DCEN10
PDMA0.DCST10
PDMA0.DCSTS10
PDMA0.DCSTC10
PDMA0.DTFR10
PDMA0.DTFRRQ10
PDMA0.DTFRRQC10
PDMA0.DSA11
PDMA0.DDA11
PDMA0.DTC11
PDMA0.DTCT11
PDMA0.DRSA11
PDMA0.DRDA11
PDMA0.DRTC11
PDMA0.DCEN11
PDMA0.DCST11
PDMA0.DCSTS11
PDMA0.DCSTC11
PDMA0.DTFR11
PDMA0.DTFRRQ11
PDMA0.DTFRRQC11
PDMA0.DSA12
PDMA0.DDA12
PDMA0.DTC12
PDMA0.DTCT12
PDMA0.DRSA12
PDMA0.DRDA12
PDMA0.DRTC12
PDMA0.DCEN12
PDMA0.DCST12
PDMA0.DCSTS12
PDMA0.DCSTC12
PDMA0.DTFR12
PDMA0.DTFRRQ12
PDMA0.DTFRRQC12
PDMA0.DSA13
PDMA0.DDA13
PDMA0.DTC13
PDMA0.DTCT13
PDMA0.DRSA13
PDMA0.DRDA13
PDMA0.DRTC13
PDMA0.DCEN13
PDMA0.DCST13
PDMA0.DCSTS13
PDMA0.DCSTC13
PDMA0.DTFR13
PDMA0.DTFRRQ13
PDMA0.DTFRRQC13
PDMA0.DSA14
PDMA0.DDA14
PDMA0.DTC14
PDMA0.DTCT14
PDMA0.DRSA14
PDMA0.DRDA14
PDMA0.DRTC14
PDMA0.DCEN14
PDMA0.DCST14
PDMA0.DCSTS14
PDMA0.DCSTC14
PDMA0.DTFR14
PDMA0.DTFRRQ14
PDMA0.DTFRRQC14
PDMA0.DSA15
PDMA0.DDA15
PDMA0.DTC15
PDMA0.DTCT15
PDMA0.DRSA15
PDMA0.DRDA15
PDMA0.DRTC15
PDMA0.DCEN15
PDMA0.DCST15
PDMA0.DCSTS15
PDMA0.DCSTC15
PDMA0.DTFR15
PDMA0.DTFRRQ15
PDMA0.DTFRRQC15
INTC2.ICADCA0I2_2.UINT16
INTC2.ICADCA0I2_2.UINT16
INTC2.ICADCA0I2_2.UINT8[L/H]
INTC2.ICADCA0I2_2.REGS8.ICCSIH0IJCL.UINT8
INTC2.ICADCA0I2_2.REGS8.ICCSIH0IJCH.UINT8
INTC2.ICADCA0I2_2.BIT.P0ADCA0I2_2
INTC2.ICADCA0I2_2.BIT.P0CSIH0IJC
INTC2.ICADCA0I2_2.BIT.P1ADCA0I2_2
INTC2.ICADCA0I2_2.BIT.P1CSIH0IJC
INTC2.ICADCA0I2_2.BIT.P2ADCA0I2_2
INTC2.ICADCA0I2_2.BIT.P2CSIH0IJC
INTC2.ICADCA0I2_2.BIT.P3ADCA0I2_2
INTC2.ICADCA0I2_2.BIT.P3CSIH0IJC
INTC2.ICADCA0I2_2.BIT.TBADCA0I2_2
INTC2.ICADCA0I2_2.BIT.TBCSIH0IJC
INTC2.ICADCA0I2_2.BIT.MKADCA0I2_2
INTC2.ICADCA0I2_2.BIT.MKCSIH0IJC
INTC2.ICADCA0I2_2.BIT.RFADCA0I2_2
INTC2.ICADCA0I2_2.BIT.RFCSIH0IJC
INTC2.ICADCA0I2_2.BIT.CTADCA0I2_2
INTC2.ICADCA0I2_2.BIT.CTCSIH0IJC
INTC2.ICRLIN30.UINT16
INTC2.ICRLIN30.UINT8[L/H]
INTC2.ICRLIN30.BIT.P0RLIN30
INTC2.ICRLIN30.BIT.P1RLIN30
INTC2.ICRLIN30.BIT.P2RLIN30
INTC2.ICRLIN30.BIT.P3RLIN30
INTC2.ICRLIN30.BIT.TBRLIN30
INTC2.ICRLIN30.BIT.MKRLIN30
INTC2.ICRLIN30.BIT.RFRLIN30
INTC2.ICRLIN30.BIT.CTRLIN30
INTC2.ICRLIN30UR0.UINT16
INTC2.ICRLIN30UR0.UINT8[L/H]
INTC2.ICRLIN30UR0.BIT.P0RLIN30UR0
INTC2.ICRLIN30UR0.BIT.P1RLIN30UR0
INTC2.ICRLIN30UR0.BIT.P2RLIN30UR0
INTC2.ICRLIN30UR0.BIT.P3RLIN30UR0
INTC2.ICRLIN30UR0.BIT.TBRLIN30UR0
INTC2.ICRLIN30UR0.BIT.MKRLIN30UR0
INTC2.ICRLIN30UR0.BIT.RFRLIN30UR0
INTC2.ICRLIN30UR0.BIT.CTRLIN30UR0
INTC2.ICRLIN30UR1.UINT16
INTC2.ICRLIN30UR1.UINT8[L/H]
INTC2.ICRLIN30UR1.BIT.P0RLIN30UR1
INTC2.ICRLIN30UR1.BIT.P1RLIN30UR1
INTC2.ICRLIN30UR1.BIT.P2RLIN30UR1
INTC2.ICRLIN30UR1.BIT.P3RLIN30UR1
INTC2.ICRLIN30UR1.BIT.TBRLIN30UR1
INTC2.ICRLIN30UR1.BIT.MKRLIN30UR1
INTC2.ICRLIN30UR1.BIT.RFRLIN30UR1
INTC2.ICRLIN30UR1.BIT.CTRLIN30UR1
INTC2.ICRLIN30UR2.UINT16
INTC2.ICRLIN30UR2.UINT8[L/H]
INTC2.ICRLIN30UR2.BIT.P0RLIN30UR2
INTC2.ICRLIN30UR2.BIT.P1RLIN30UR2
INTC2.ICRLIN30UR2.BIT.P2RLIN30UR2
INTC2.ICRLIN30UR2.BIT.P3RLIN30UR2
INTC2.ICRLIN30UR2.BIT.TBRLIN30UR2
INTC2.ICRLIN30UR2.BIT.MKRLIN30UR2
INTC2.ICRLIN30UR2.BIT.RFRLIN30UR2
INTC2.ICRLIN30UR2.BIT.CTRLIN30UR2
INTC2.ICP0.UINT16
INTC2.ICP0.UINT8[L/H]
INTC2.ICP0.BIT.P0P0
INTC2.ICP0.BIT.P1P0
INTC2.ICP0.BIT.P2P0
INTC2.ICP0.BIT.P3P0
INTC2.ICP0.BIT.TBP0
INTC2.ICP0.BIT.MKP0
INTC2.ICP0.BIT.RFP0
INTC2.ICP0.BIT.CTP0
INTC2.ICP1.UINT16
INTC2.ICP1.UINT8[L/H]
INTC2.ICP1.BIT.P0P1
INTC2.ICP1.BIT.P1P1
INTC2.ICP1.BIT.P2P1
INTC2.ICP1.BIT.P3P1
INTC2.ICP1.BIT.TBP1
INTC2.ICP1.BIT.MKP1
INTC2.ICP1.BIT.RFP1
INTC2.ICP1.BIT.CTP1
INTC2.ICP2.UINT16
INTC2.ICP2.UINT8[L/H]
INTC2.ICP2.BIT.P0P2
INTC2.ICP2.BIT.P1P2
INTC2.ICP2.BIT.P2P2
INTC2.ICP2.BIT.P3P2
INTC2.ICP2.BIT.TBP2
INTC2.ICP2.BIT.MKP2
INTC2.ICP2.BIT.RFP2
INTC2.ICP2.BIT.CTP2
INTC2.ICWDTA0.UINT16
INTC2.ICWDTA0.UINT8[L/H]
INTC2.ICWDTA0.BIT.P0WDTA0
INTC2.ICWDTA0.BIT.P1WDTA0
INTC2.ICWDTA0.BIT.P2WDTA0
INTC2.ICWDTA0.BIT.P3WDTA0
INTC2.ICWDTA0.BIT.TBWDTA0
INTC2.ICWDTA0.BIT.MKWDTA0
INTC2.ICWDTA0.BIT.RFWDTA0
INTC2.ICWDTA0.BIT.CTWDTA0
INTC2.ICWDTA1.UINT16
INTC2.ICWDTA1.UINT8[L/H]
INTC2.ICWDTA1.BIT.P0WDTA1
INTC2.ICWDTA1.BIT.P1WDTA1
INTC2.ICWDTA1.BIT.P2WDTA1
INTC2.ICWDTA1.BIT.P3WDTA1
INTC2.ICWDTA1.BIT.TBWDTA1
INTC2.ICWDTA1.BIT.MKWDTA1
INTC2.ICWDTA1.BIT.RFWDTA1
INTC2.ICWDTA1.BIT.CTWDTA1
INTC2.ICP3.UINT16
INTC2.ICP3.UINT8[L/H]
INTC2.ICP3.BIT.P0P3
INTC2.ICP3.BIT.P1P3
INTC2.ICP3.BIT.P2P3
INTC2.ICP3.BIT.P3P3
INTC2.ICP3.BIT.TBP3
INTC2.ICP3.BIT.MKP3
INTC2.ICP3.BIT.RFP3
INTC2.ICP3.BIT.CTP3
INTC2.ICP4.UINT16
INTC2.ICP4.UINT8[L/H]
INTC2.ICP4.BIT.P0P4
INTC2.ICP4.BIT.P1P4
INTC2.ICP4.BIT.P2P4
INTC2.ICP4.BIT.P3P4
INTC2.ICP4.BIT.TBP4
INTC2.ICP4.BIT.MKP4
INTC2.ICP4.BIT.RFP4
INTC2.ICP4.BIT.CTP4
INTC2.ICP5.UINT16
INTC2.ICP5.UINT8[L/H]
INTC2.ICP5.BIT.P0P5
INTC2.ICP5.BIT.P1P5
INTC2.ICP5.BIT.P2P5
INTC2.ICP5.BIT.P3P5
INTC2.ICP5.BIT.TBP5
INTC2.ICP5.BIT.MKP5
INTC2.ICP5.BIT.RFP5
INTC2.ICP5.BIT.CTP5
INTC2.ICP10.UINT16
INTC2.ICP10.UINT8[L/H]
INTC2.ICP10.BIT.P0P10
INTC2.ICP10.BIT.P1P10
INTC2.ICP10.BIT.P2P10
INTC2.ICP10.BIT.P3P10
INTC2.ICP10.BIT.TBP10
INTC2.ICP10.BIT.MKP10
INTC2.ICP10.BIT.RFP10
INTC2.ICP10.BIT.CTP10
INTC2.ICP11.UINT16
INTC2.ICP11.UINT8[L/H]
INTC2.ICP11.BIT.P0P11
INTC2.ICP11.BIT.P1P11
INTC2.ICP11.BIT.P2P11
INTC2.ICP11.BIT.P3P11
INTC2.ICP11.BIT.TBP11
INTC2.ICP11.BIT.MKP11
INTC2.ICP11.BIT.RFP11
INTC2.ICP11.BIT.CTP11
INTC2.ICTAUD0I1.UINT16
INTC2.ICTAUD0I1.UINT8[L/H]
INTC2.ICTAUD0I1.BIT.P0TAUD0I1
INTC2.ICTAUD0I1.BIT.P1TAUD0I1
INTC2.ICTAUD0I1.BIT.P2TAUD0I1
INTC2.ICTAUD0I1.BIT.P3TAUD0I1
INTC2.ICTAUD0I1.BIT.TBTAUD0I1
INTC2.ICTAUD0I1.BIT.MKTAUD0I1
INTC2.ICTAUD0I1.BIT.RFTAUD0I1
INTC2.ICTAUD0I1.BIT.CTTAUD0I1
INTC2.ICTAUD0I3.UINT16
INTC2.ICTAUD0I3.UINT8[L/H]
INTC2.ICTAUD0I3.BIT.P0TAUD0I3
INTC2.ICTAUD0I3.BIT.P1TAUD0I3
INTC2.ICTAUD0I3.BIT.P2TAUD0I3
INTC2.ICTAUD0I3.BIT.P3TAUD0I3
INTC2.ICTAUD0I3.BIT.TBTAUD0I3
INTC2.ICTAUD0I3.BIT.MKTAUD0I3
INTC2.ICTAUD0I3.BIT.RFTAUD0I3
INTC2.ICTAUD0I3.BIT.CTTAUD0I3
INTC2.ICTAUD0I5.UINT16
INTC2.ICTAUD0I5.UINT8[L/H]
INTC2.ICTAUD0I5.BIT.P0TAUD0I5
INTC2.ICTAUD0I5.BIT.P1TAUD0I5
INTC2.ICTAUD0I5.BIT.P2TAUD0I5
INTC2.ICTAUD0I5.BIT.P3TAUD0I5
INTC2.ICTAUD0I5.BIT.TBTAUD0I5
INTC2.ICTAUD0I5.BIT.MKTAUD0I5
INTC2.ICTAUD0I5.BIT.RFTAUD0I5
INTC2.ICTAUD0I5.BIT.CTTAUD0I5
INTC2.ICTAUD0I7.UINT16
INTC2.ICTAUD0I7.UINT8[L/H]
INTC2.ICTAUD0I7.BIT.P0TAUD0I7
INTC2.ICTAUD0I7.BIT.P1TAUD0I7
INTC2.ICTAUD0I7.BIT.P2TAUD0I7
INTC2.ICTAUD0I7.BIT.P3TAUD0I7
INTC2.ICTAUD0I7.BIT.TBTAUD0I7
INTC2.ICTAUD0I7.BIT.MKTAUD0I7
INTC2.ICTAUD0I7.BIT.RFTAUD0I7
INTC2.ICTAUD0I7.BIT.CTTAUD0I7
INTC2.ICTAUD0I9.UINT16
INTC2.ICTAUD0I9.UINT8[L/H]
INTC2.ICTAUD0I9.BIT.P0TAUD0I9
INTC2.ICTAUD0I9.BIT.P1TAUD0I9
INTC2.ICTAUD0I9.BIT.P2TAUD0I9
INTC2.ICTAUD0I9.BIT.P3TAUD0I9
INTC2.ICTAUD0I9.BIT.TBTAUD0I9
INTC2.ICTAUD0I9.BIT.MKTAUD0I9
INTC2.ICTAUD0I9.BIT.RFTAUD0I9
INTC2.ICTAUD0I9.BIT.CTTAUD0I9
INTC2.ICTAUD0I11.UINT16
INTC2.ICTAUD0I11.UINT8[L/H]
INTC2.ICTAUD0I11.BIT.P0TAUD0I11
INTC2.ICTAUD0I11.BIT.P1TAUD0I11
INTC2.ICTAUD0I11.BIT.P2TAUD0I11
INTC2.ICTAUD0I11.BIT.P3TAUD0I11
INTC2.ICTAUD0I11.BIT.TBTAUD0I11
INTC2.ICTAUD0I11.BIT.MKTAUD0I11
INTC2.ICTAUD0I11.BIT.RFTAUD0I11
INTC2.ICTAUD0I11.BIT.CTTAUD0I11
INTC2.ICTAUD0I13.UINT16
INTC2.ICTAUD0I13.UINT8[L/H]
INTC2.ICTAUD0I13.BIT.P0TAUD0I13
INTC2.ICTAUD0I13.BIT.P1TAUD0I13
INTC2.ICTAUD0I13.BIT.P2TAUD0I13
INTC2.ICTAUD0I13.BIT.P3TAUD0I13
INTC2.ICTAUD0I13.BIT.TBTAUD0I13
INTC2.ICTAUD0I13.BIT.MKTAUD0I13
INTC2.ICTAUD0I13.BIT.RFTAUD0I13
INTC2.ICTAUD0I13.BIT.CTTAUD0I13
INTC2.ICTAUD0I15.UINT16
INTC2.ICTAUD0I15.UINT8[L/H]
INTC2.ICTAUD0I15.BIT.P0TAUD0I15
INTC2.ICTAUD0I15.BIT.P1TAUD0I15
INTC2.ICTAUD0I15.BIT.P2TAUD0I15
INTC2.ICTAUD0I15.BIT.P3TAUD0I15
INTC2.ICTAUD0I15.BIT.TBTAUD0I15
INTC2.ICTAUD0I15.BIT.MKTAUD0I15
INTC2.ICTAUD0I15.BIT.RFTAUD0I15
INTC2.ICTAUD0I15.BIT.CTTAUD0I15
INTC2.ICADCA0ERR.UINT16
INTC2.ICADCA0ERR.UINT8[L/H]
INTC2.ICADCA0ERR.BIT.P0ADCA0ERR
INTC2.ICADCA0ERR.BIT.P1ADCA0ERR
INTC2.ICADCA0ERR.BIT.P2ADCA0ERR
INTC2.ICADCA0ERR.BIT.P3ADCA0ERR
INTC2.ICADCA0ERR.BIT.TBADCA0ERR
INTC2.ICADCA0ERR.BIT.MKADCA0ERR
INTC2.ICADCA0ERR.BIT.RFADCA0ERR
INTC2.ICADCA0ERR.BIT.CTADCA0ERR
INTC2.ICCSIG0IRE.UINT16
INTC2.ICCSIG0IRE.UINT8[L/H]
INTC2.ICCSIG0IRE.BIT.P0CSIG0IRE
INTC2.ICCSIG0IRE.BIT.P1CSIG0IRE
INTC2.ICCSIG0IRE.BIT.P2CSIG0IRE
INTC2.ICCSIG0IRE.BIT.P3CSIG0IRE
INTC2.ICCSIG0IRE.BIT.TBCSIG0IRE
INTC2.ICCSIG0IRE.BIT.MKCSIG0IRE
INTC2.ICCSIG0IRE.BIT.RFCSIG0IRE
INTC2.ICCSIG0IRE.BIT.CTCSIG0IRE
INTC2.ICRLIN20.UINT16
INTC2.ICRLIN20.UINT8[L/H]
INTC2.ICRLIN20.BIT.P0RLIN20
INTC2.ICRLIN20.BIT.P1RLIN20
INTC2.ICRLIN20.BIT.P2RLIN20
INTC2.ICRLIN20.BIT.P3RLIN20
INTC2.ICRLIN20.BIT.TBRLIN20
INTC2.ICRLIN20.BIT.MKRLIN20
INTC2.ICRLIN20.BIT.RFRLIN20
INTC2.ICRLIN20.BIT.CTRLIN20
INTC2.ICRLIN21.UINT16
INTC2.ICRLIN21.UINT8[L/H]
INTC2.ICRLIN21.BIT.P0RLIN21
INTC2.ICRLIN21.BIT.P1RLIN21
INTC2.ICRLIN21.BIT.P2RLIN21
INTC2.ICRLIN21.BIT.P3RLIN21
INTC2.ICRLIN21.BIT.TBRLIN21
INTC2.ICRLIN21.BIT.MKRLIN21
INTC2.ICRLIN21.BIT.RFRLIN21
INTC2.ICRLIN21.BIT.CTRLIN21
INTC2.ICDMA0.UINT16
INTC2.ICDMA0.UINT8[L/H]
INTC2.ICDMA0.BIT.P0DMA0
INTC2.ICDMA0.BIT.P1DMA0
INTC2.ICDMA0.BIT.P2DMA0
INTC2.ICDMA0.BIT.P3DMA0
INTC2.ICDMA0.BIT.TBDMA0
INTC2.ICDMA0.BIT.MKDMA0
INTC2.ICDMA0.BIT.RFDMA0
INTC2.ICDMA0.BIT.CTDMA0
INTC2.ICDMA1.UINT16
INTC2.ICDMA1.UINT8[L/H]
INTC2.ICDMA1.BIT.P0DMA1
INTC2.ICDMA1.BIT.P1DMA1
INTC2.ICDMA1.BIT.P2DMA1
INTC2.ICDMA1.BIT.P3DMA1
INTC2.ICDMA1.BIT.TBDMA1
INTC2.ICDMA1.BIT.MKDMA1
INTC2.ICDMA1.BIT.RFDMA1
INTC2.ICDMA1.BIT.CTDMA1
INTC2.ICDMA2.UINT16
INTC2.ICDMA2.UINT8[L/H]
INTC2.ICDMA2.BIT.P0DMA2
INTC2.ICDMA2.BIT.P1DMA2
INTC2.ICDMA2.BIT.P2DMA2
INTC2.ICDMA2.BIT.P3DMA2
INTC2.ICDMA2.BIT.TBDMA2
INTC2.ICDMA2.BIT.MKDMA2
INTC2.ICDMA2.BIT.RFDMA2
INTC2.ICDMA2.BIT.CTDMA2
INTC2.ICDMA3.UINT16
INTC2.ICDMA3.UINT8[L/H]
INTC2.ICDMA3.BIT.P0DMA3
INTC2.ICDMA3.BIT.P1DMA3
INTC2.ICDMA3.BIT.P2DMA3
INTC2.ICDMA3.BIT.P3DMA3
INTC2.ICDMA3.BIT.TBDMA3
INTC2.ICDMA3.BIT.MKDMA3
INTC2.ICDMA3.BIT.RFDMA3
INTC2.ICDMA3.BIT.CTDMA3
INTC2.ICDMA4.UINT16
INTC2.ICDMA4.UINT8[L/H]
INTC2.ICDMA4.BIT.P0DMA4
INTC2.ICDMA4.BIT.P1DMA4
INTC2.ICDMA4.BIT.P2DMA4
INTC2.ICDMA4.BIT.P3DMA4
INTC2.ICDMA4.BIT.TBDMA4
INTC2.ICDMA4.BIT.MKDMA4
INTC2.ICDMA4.BIT.RFDMA4
INTC2.ICDMA4.BIT.CTDMA4
INTC2.ICDMA5.UINT16
INTC2.ICDMA5.UINT8[L/H]
INTC2.ICDMA5.BIT.P0DMA5
INTC2.ICDMA5.BIT.P1DMA5
INTC2.ICDMA5.BIT.P2DMA5
INTC2.ICDMA5.BIT.P3DMA5
INTC2.ICDMA5.BIT.TBDMA5
INTC2.ICDMA5.BIT.MKDMA5
INTC2.ICDMA5.BIT.RFDMA5
INTC2.ICDMA5.BIT.CTDMA5
INTC2.ICDMA6.UINT16
INTC2.ICDMA6.UINT8[L/H]
INTC2.ICDMA6.BIT.P0DMA6
INTC2.ICDMA6.BIT.P1DMA6
INTC2.ICDMA6.BIT.P2DMA6
INTC2.ICDMA6.BIT.P3DMA6
INTC2.ICDMA6.BIT.TBDMA6
INTC2.ICDMA6.BIT.MKDMA6
INTC2.ICDMA6.BIT.RFDMA6
INTC2.ICDMA6.BIT.CTDMA6
INTC2.ICDMA7.UINT16
INTC2.ICDMA7.UINT8[L/H]
INTC2.ICDMA7.BIT.P0DMA7
INTC2.ICDMA7.BIT.P1DMA7
INTC2.ICDMA7.BIT.P2DMA7
INTC2.ICDMA7.BIT.P3DMA7
INTC2.ICDMA7.BIT.TBDMA7
INTC2.ICDMA7.BIT.MKDMA7
INTC2.ICDMA7.BIT.RFDMA7
INTC2.ICDMA7.BIT.CTDMA7
INTC2.ICDMA8.UINT16
INTC2.ICDMA8.UINT8[L/H]
INTC2.ICDMA8.BIT.P0DMA8
INTC2.ICDMA8.BIT.P1DMA8
INTC2.ICDMA8.BIT.P2DMA8
INTC2.ICDMA8.BIT.P3DMA8
INTC2.ICDMA8.BIT.TBDMA8
INTC2.ICDMA8.BIT.MKDMA8
INTC2.ICDMA8.BIT.RFDMA8
INTC2.ICDMA8.BIT.CTDMA8
INTC2.ICDMA9.UINT16
INTC2.ICDMA9.UINT8[L/H]
INTC2.ICDMA9.BIT.P0DMA9
INTC2.ICDMA9.BIT.P1DMA9
INTC2.ICDMA9.BIT.P2DMA9
INTC2.ICDMA9.BIT.P3DMA9
INTC2.ICDMA9.BIT.TBDMA9
INTC2.ICDMA9.BIT.MKDMA9
INTC2.ICDMA9.BIT.RFDMA9
INTC2.ICDMA9.BIT.CTDMA9
INTC2.ICDMA10.UINT16
INTC2.ICDMA10.UINT8[L/H]
INTC2.ICDMA10.BIT.P0DMA10
INTC2.ICDMA10.BIT.P1DMA10
INTC2.ICDMA10.BIT.P2DMA10
INTC2.ICDMA10.BIT.P3DMA10
INTC2.ICDMA10.BIT.TBDMA10
INTC2.ICDMA10.BIT.MKDMA10
INTC2.ICDMA10.BIT.RFDMA10
INTC2.ICDMA10.BIT.CTDMA10
INTC2.ICDMA11.UINT16
INTC2.ICDMA11.UINT8[L/H]
INTC2.ICDMA11.BIT.P0DMA11
INTC2.ICDMA11.BIT.P1DMA11
INTC2.ICDMA11.BIT.P2DMA11
INTC2.ICDMA11.BIT.P3DMA11
INTC2.ICDMA11.BIT.TBDMA11
INTC2.ICDMA11.BIT.MKDMA11
INTC2.ICDMA11.BIT.RFDMA11
INTC2.ICDMA11.BIT.CTDMA11
INTC2.ICDMA12.UINT16
INTC2.ICDMA12.UINT8[L/H]
INTC2.ICDMA12.BIT.P0DMA12
INTC2.ICDMA12.BIT.P1DMA12
INTC2.ICDMA12.BIT.P2DMA12
INTC2.ICDMA12.BIT.P3DMA12
INTC2.ICDMA12.BIT.TBDMA12
INTC2.ICDMA12.BIT.MKDMA12
INTC2.ICDMA12.BIT.RFDMA12
INTC2.ICDMA12.BIT.CTDMA12
INTC2.ICDMA13.UINT16
INTC2.ICDMA13.UINT8[L/H]
INTC2.ICDMA13.BIT.P0DMA13
INTC2.ICDMA13.BIT.P1DMA13
INTC2.ICDMA13.BIT.P2DMA13
INTC2.ICDMA13.BIT.P3DMA13
INTC2.ICDMA13.BIT.TBDMA13
INTC2.ICDMA13.BIT.MKDMA13
INTC2.ICDMA13.BIT.RFDMA13
INTC2.ICDMA13.BIT.CTDMA13
INTC2.ICDMA14.UINT16
INTC2.ICDMA14.UINT8[L/H]
INTC2.ICDMA14.BIT.P0DMA14
INTC2.ICDMA14.BIT.P1DMA14
INTC2.ICDMA14.BIT.P2DMA14
INTC2.ICDMA14.BIT.P3DMA14
INTC2.ICDMA14.BIT.TBDMA14
INTC2.ICDMA14.BIT.MKDMA14
INTC2.ICDMA14.BIT.RFDMA14
INTC2.ICDMA14.BIT.CTDMA14
INTC2.ICDMA15.UINT16
INTC2.ICDMA15.UINT8[L/H]
INTC2.ICDMA15.BIT.P0DMA15
INTC2.ICDMA15.BIT.P1DMA15
INTC2.ICDMA15.BIT.P2DMA15
INTC2.ICDMA15.BIT.P3DMA15
INTC2.ICDMA15.BIT.TBDMA15
INTC2.ICDMA15.BIT.MKDMA15
INTC2.ICDMA15.BIT.RFDMA15
INTC2.ICDMA15.BIT.CTDMA15
INTC2.ICRIIC0TI.UINT16
INTC2.ICRIIC0TI.UINT8[L/H]
INTC2.ICRIIC0TI.BIT.P0RIIC0TI
INTC2.ICRIIC0TI.BIT.P1RIIC0TI
INTC2.ICRIIC0TI.BIT.P2RIIC0TI
INTC2.ICRIIC0TI.BIT.P3RIIC0TI
INTC2.ICRIIC0TI.BIT.TBRIIC0TI
INTC2.ICRIIC0TI.BIT.MKRIIC0TI
INTC2.ICRIIC0TI.BIT.RFRIIC0TI
INTC2.ICRIIC0TI.BIT.CTRIIC0TI
INTC2.ICRIIC0EE.UINT16
INTC2.ICRIIC0EE.UINT8[L/H]
INTC2.ICRIIC0EE.BIT.P0RIIC0EE
INTC2.ICRIIC0EE.BIT.P1RIIC0EE
INTC2.ICRIIC0EE.BIT.P2RIIC0EE
INTC2.ICRIIC0EE.BIT.P3RIIC0EE
INTC2.ICRIIC0EE.BIT.TBRIIC0EE
INTC2.ICRIIC0EE.BIT.MKRIIC0EE
INTC2.ICRIIC0EE.BIT.RFRIIC0EE
INTC2.ICRIIC0EE.BIT.CTRIIC0EE
INTC2.ICRIIC0RI.UINT16
INTC2.ICRIIC0RI.UINT8[L/H]
INTC2.ICRIIC0RI.BIT.P0RIIC0RI
INTC2.ICRIIC0RI.BIT.P1RIIC0RI
INTC2.ICRIIC0RI.BIT.P2RIIC0RI
INTC2.ICRIIC0RI.BIT.P3RIIC0RI
INTC2.ICRIIC0RI.BIT.TBRIIC0RI
INTC2.ICRIIC0RI.BIT.MKRIIC0RI
INTC2.ICRIIC0RI.BIT.RFRIIC0RI
INTC2.ICRIIC0RI.BIT.CTRIIC0RI
INTC2.ICRIIC0TEI.UINT16
INTC2.ICRIIC0TEI.UINT8[L/H]
INTC2.ICRIIC0TEI.BIT.P0RIIC0TEI
INTC2.ICRIIC0TEI.BIT.P1RIIC0TEI
INTC2.ICRIIC0TEI.BIT.P2RIIC0TEI
INTC2.ICRIIC0TEI.BIT.P3RIIC0TEI
INTC2.ICRIIC0TEI.BIT.TBRIIC0TEI
INTC2.ICRIIC0TEI.BIT.MKRIIC0TEI
INTC2.ICRIIC0TEI.BIT.RFRIIC0TEI
INTC2.ICRIIC0TEI.BIT.CTRIIC0TEI
INTC2.ICTAUJ0I0.UINT16
INTC2.ICTAUJ0I0.UINT8[L/H]
INTC2.ICTAUJ0I0.BIT.P0TAUJ0I0
INTC2.ICTAUJ0I0.BIT.P1TAUJ0I0
INTC2.ICTAUJ0I0.BIT.P2TAUJ0I0
INTC2.ICTAUJ0I0.BIT.P3TAUJ0I0
INTC2.ICTAUJ0I0.BIT.TBTAUJ0I0
INTC2.ICTAUJ0I0.BIT.MKTAUJ0I0
INTC2.ICTAUJ0I0.BIT.RFTAUJ0I0
INTC2.ICTAUJ0I0.BIT.CTTAUJ0I0
INTC2.ICTAUJ0I1.UINT16
INTC2.ICTAUJ0I1.UINT8[L/H]
INTC2.ICTAUJ0I1.BIT.P0TAUJ0I1
INTC2.ICTAUJ0I1.BIT.P1TAUJ0I1
INTC2.ICTAUJ0I1.BIT.P2TAUJ0I1
INTC2.ICTAUJ0I1.BIT.P3TAUJ0I1
INTC2.ICTAUJ0I1.BIT.TBTAUJ0I1
INTC2.ICTAUJ0I1.BIT.MKTAUJ0I1
INTC2.ICTAUJ0I1.BIT.RFTAUJ0I1
INTC2.ICTAUJ0I1.BIT.CTTAUJ0I1
INTC2.ICTAUJ0I2.UINT16
INTC2.ICTAUJ0I2.UINT8[L/H]
INTC2.ICTAUJ0I2.BIT.P0TAUJ0I2
INTC2.ICTAUJ0I2.BIT.P1TAUJ0I2
INTC2.ICTAUJ0I2.BIT.P2TAUJ0I2
INTC2.ICTAUJ0I2.BIT.P3TAUJ0I2
INTC2.ICTAUJ0I2.BIT.TBTAUJ0I2
INTC2.ICTAUJ0I2.BIT.MKTAUJ0I2
INTC2.ICTAUJ0I2.BIT.RFTAUJ0I2
INTC2.ICTAUJ0I2.BIT.CTTAUJ0I2
INTC2.ICTAUJ0I3.UINT16
INTC2.ICTAUJ0I3.UINT8[L/H]
INTC2.ICTAUJ0I3.BIT.P0TAUJ0I3
INTC2.ICTAUJ0I3.BIT.P1TAUJ0I3
INTC2.ICTAUJ0I3.BIT.P2TAUJ0I3
INTC2.ICTAUJ0I3.BIT.P3TAUJ0I3
INTC2.ICTAUJ0I3.BIT.TBTAUJ0I3
INTC2.ICTAUJ0I3.BIT.MKTAUJ0I3
INTC2.ICTAUJ0I3.BIT.RFTAUJ0I3
INTC2.ICTAUJ0I3.BIT.CTTAUJ0I3
INTC2.ICOSTM0.UINT16
INTC2.ICOSTM0.UINT8[L/H]
INTC2.ICOSTM0.BIT.P0OSTM0
INTC2.ICOSTM0.BIT.P1OSTM0
INTC2.ICOSTM0.BIT.P2OSTM0
INTC2.ICOSTM0.BIT.P3OSTM0
INTC2.ICOSTM0.BIT.TBOSTM0
INTC2.ICOSTM0.BIT.MKOSTM0
INTC2.ICOSTM0.BIT.RFOSTM0
INTC2.ICOSTM0.BIT.CTOSTM0
INTC2.ICENCA0IOV.UINT16
INTC2.ICENCA0IOV.UINT8[L/H]
INTC2.ICENCA0IOV.BIT.P0ENCA0IOV
INTC2.ICENCA0IOV.BIT.P1ENCA0IOV
INTC2.ICENCA0IOV.BIT.P2ENCA0IOV
INTC2.ICENCA0IOV.BIT.P3ENCA0IOV
INTC2.ICENCA0IOV.BIT.TBENCA0IOV
INTC2.ICENCA0IOV.BIT.MKENCA0IOV
INTC2.ICENCA0IOV.BIT.RFENCA0IOV
INTC2.ICENCA0IOV.BIT.CTENCA0IOV
INTC2.ICENCA0IUD.UINT16
INTC2.ICENCA0IUD.UINT8[L/H]
INTC2.ICENCA0IUD.BIT.P0ENCA0IUD
INTC2.ICENCA0IUD.BIT.P1ENCA0IUD
INTC2.ICENCA0IUD.BIT.P2ENCA0IUD
INTC2.ICENCA0IUD.BIT.P3ENCA0IUD
INTC2.ICENCA0IUD.BIT.TBENCA0IUD
INTC2.ICENCA0IUD.BIT.MKENCA0IUD
INTC2.ICENCA0IUD.BIT.RFENCA0IUD
INTC2.ICENCA0IUD.BIT.CTENCA0IUD
INTC2.ICENCA0I0.UINT16
INTC2.ICENCA0I0.UINT8[L/H]
INTC2.ICENCA0I0.BIT.P0ENCA0I0
INTC2.ICENCA0I0.BIT.P1ENCA0I0
INTC2.ICENCA0I0.BIT.P2ENCA0I0
INTC2.ICENCA0I0.BIT.P3ENCA0I0
INTC2.ICENCA0I0.BIT.TBENCA0I0
INTC2.ICENCA0I0.BIT.MKENCA0I0
INTC2.ICENCA0I0.BIT.RFENCA0I0
INTC2.ICENCA0I0.BIT.CTENCA0I0
INTC2.ICENCA0I1.UINT16
INTC2.ICENCA0I1.UINT8[L/H]
INTC2.ICENCA0I1.BIT.P0ENCA0I1
INTC2.ICENCA0I1.BIT.P1ENCA0I1
INTC2.ICENCA0I1.BIT.P2ENCA0I1
INTC2.ICENCA0I1.BIT.P3ENCA0I1
INTC2.ICENCA0I1.BIT.TBENCA0I1
INTC2.ICENCA0I1.BIT.MKENCA0I1
INTC2.ICENCA0I1.BIT.RFENCA0I1
INTC2.ICENCA0I1.BIT.CTENCA0I1
INTC2.ICENCA0IEC.UINT16
INTC2.ICENCA0IEC.UINT8[L/H]
INTC2.ICENCA0IEC.BIT.P0ENCA0IEC
INTC2.ICENCA0IEC.BIT.P1ENCA0IEC
INTC2.ICENCA0IEC.BIT.P2ENCA0IEC
INTC2.ICENCA0IEC.BIT.P3ENCA0IEC
INTC2.ICENCA0IEC.BIT.TBENCA0IEC
INTC2.ICENCA0IEC.BIT.MKENCA0IEC
INTC2.ICENCA0IEC.BIT.RFENCA0IEC
INTC2.ICENCA0IEC.BIT.CTENCA0IEC
INTC2.ICKR0.UINT16
INTC2.ICKR0.UINT8[L/H]
INTC2.ICKR0.BIT.P0KR0
INTC2.ICKR0.BIT.P1KR0
INTC2.ICKR0.BIT.P2KR0
INTC2.ICKR0.BIT.P3KR0
INTC2.ICKR0.BIT.TBKR0
INTC2.ICKR0.BIT.MKKR0
INTC2.ICKR0.BIT.RFKR0
INTC2.ICKR0.BIT.CTKR0
INTC2.ICQFULL.UINT16
INTC2.ICQFULL.UINT8[L/H]
INTC2.ICQFULL.BIT.P0QFULL
INTC2.ICQFULL.BIT.P1QFULL
INTC2.ICQFULL.BIT.P2QFULL
INTC2.ICQFULL.BIT.P3QFULL
INTC2.ICQFULL.BIT.TBQFULL
INTC2.ICQFULL.BIT.MKQFULL
INTC2.ICQFULL.BIT.RFQFULL
INTC2.ICQFULL.BIT.CTQFULL
INTC2.ICPWGAG00.UINT16
INTC2.ICPWGAG00.UINT8[L/H]
INTC2.ICPWGAG00.BIT.P0PWGAG00
INTC2.ICPWGAG00.BIT.P1PWGAG00
INTC2.ICPWGAG00.BIT.P2PWGAG00
INTC2.ICPWGAG00.BIT.P3PWGAG00
INTC2.ICPWGAG00.BIT.TBPWGAG00
INTC2.ICPWGAG00.BIT.MKPWGAG00
INTC2.ICPWGAG00.BIT.RFPWGAG00
INTC2.ICPWGAG00.BIT.CTPWGAG00
INTC2.ICFLERR.UINT16
INTC2.ICFLERR.UINT8[L/H]
INTC2.ICFLERR.BIT.P0FLERR
INTC2.ICFLERR.BIT.P1FLERR
INTC2.ICFLERR.BIT.P2FLERR
INTC2.ICFLERR.BIT.P3FLERR
INTC2.ICFLERR.BIT.TBFLERR
INTC2.ICFLERR.BIT.MKFLERR
INTC2.ICFLERR.BIT.RFFLERR
INTC2.ICFLERR.BIT.CTFLERR
INTC2.ICFLENDNM.UINT16
INTC2.ICFLENDNM.UINT8[L/H]
INTC2.ICFLENDNM.BIT.P0FLENDNM
INTC2.ICFLENDNM.BIT.P1FLENDNM
INTC2.ICFLENDNM.BIT.P2FLENDNM
INTC2.ICFLENDNM.BIT.P3FLENDNM
INTC2.ICFLENDNM.BIT.TBFLENDNM
INTC2.ICFLENDNM.BIT.MKFLENDNM
INTC2.ICFLENDNM.BIT.RFFLENDNM
INTC2.ICFLENDNM.BIT.CTFLENDNM
INTC2.ICCWEND.UINT16
INTC2.ICCWEND.UINT8[L/H]
INTC2.ICCWEND.BIT.P0CWEND
INTC2.ICCWEND.BIT.P1CWEND
INTC2.ICCWEND.BIT.P2CWEND
INTC2.ICCWEND.BIT.P3CWEND
INTC2.ICCWEND.BIT.TBCWEND
INTC2.ICCWEND.BIT.MKCWEND
INTC2.ICCWEND.BIT.RFCWEND
INTC2.ICCWEND.BIT.CTCWEND
INTC2.ICTAPA0IPEK0_2.UINT16
INTC2.ICTAPA0IPEK0_2.UINT8[L/H]
INTC2.ICTAPA0IPEK0_2.BIT.P0TAPA0IPEK0_2
INTC2.ICTAPA0IPEK0_2.BIT.P1TAPA0IPEK0_2
INTC2.ICTAPA0IPEK0_2.BIT.P2TAPA0IPEK0_2
INTC2.ICTAPA0IPEK0_2.BIT.P3TAPA0IPEK0_2
INTC2.ICTAPA0IPEK0_2.BIT.TBTAPA0IPEK0_2
INTC2.ICTAPA0IPEK0_2.BIT.MKTAPA0IPEK0_2
INTC2.ICTAPA0IPEK0_2.BIT.RFTAPA0IPEK0_2
INTC2.ICTAPA0IPEK0_2.BIT.CTTAPA0IPEK0_2
INTC2.ICTAPA0IVLY0_2.UINT16
INTC2.ICTAPA0IVLY0_2.UINT8[L/H]
INTC2.ICTAPA0IVLY0_2.BIT.P0TAPA0IVLY0_2
INTC2.ICTAPA0IVLY0_2.BIT.P1TAPA0IVLY0_2
INTC2.ICTAPA0IVLY0_2.BIT.P2TAPA0IVLY0_2
INTC2.ICTAPA0IVLY0_2.BIT.P3TAPA0IVLY0_2
INTC2.ICTAPA0IVLY0_2.BIT.TBTAPA0IVLY0_2
INTC2.ICTAPA0IVLY0_2.BIT.MKTAPA0IVLY0_2
INTC2.ICTAPA0IVLY0_2.BIT.RFTAPA0IVLY0_2
INTC2.ICTAPA0IVLY0_2.BIT.CTTAPA0IVLY0_2
INTC2.ICCSIG0IC_2.UINT16
INTC2.ICCSIG0IC_2.UINT8[L/H]
INTC2.ICCSIG0IC_2.BIT.P0CSIG0IC_2
INTC2.ICCSIG0IC_2.BIT.P1CSIG0IC_2
INTC2.ICCSIG0IC_2.BIT.P2CSIG0IC_2
INTC2.ICCSIG0IC_2.BIT.P3CSIG0IC_2
INTC2.ICCSIG0IC_2.BIT.TBCSIG0IC_2
INTC2.ICCSIG0IC_2.BIT.MKCSIG0IC_2
INTC2.ICCSIG0IC_2.BIT.RFCSIG0IC_2
INTC2.ICCSIG0IC_2.BIT.CTCSIG0IC_2
INTC2.ICCSIG0IR_2.UINT16
INTC2.ICCSIG0IR_2.UINT8[L/H]
INTC2.ICCSIG0IR_2.BIT.P0CSIG0IR_2
INTC2.ICCSIG0IR_2.BIT.P1CSIG0IR_2
INTC2.ICCSIG0IR_2.BIT.P2CSIG0IR_2
INTC2.ICCSIG0IR_2.BIT.P3CSIG0IR_2
INTC2.ICCSIG0IR_2.BIT.TBCSIG0IR_2
INTC2.ICCSIG0IR_2.BIT.MKCSIG0IR_2
INTC2.ICCSIG0IR_2.BIT.RFCSIG0IR_2
INTC2.ICCSIG0IR_2.BIT.CTCSIG0IR_2
INTC2.ICTAUD0I0_2.UINT16
INTC2.ICTAUD0I0_2.UINT8[L/H]
INTC2.ICTAUD0I0_2.BIT.P0TAUD0I0_2
INTC2.ICTAUD0I0_2.BIT.P1TAUD0I0_2
INTC2.ICTAUD0I0_2.BIT.P2TAUD0I0_2
INTC2.ICTAUD0I0_2.BIT.P3TAUD0I0_2
INTC2.ICTAUD0I0_2.BIT.TBTAUD0I0_2
INTC2.ICTAUD0I0_2.BIT.MKTAUD0I0_2
INTC2.ICTAUD0I0_2.BIT.RFTAUD0I0_2
INTC2.ICTAUD0I0_2.BIT.CTTAUD0I0_2
INTC2.ICTAUD0I4_2.UINT16
INTC2.ICTAUD0I4_2.UINT8[L/H]
INTC2.ICTAUD0I4_2.BIT.P0TAUD0I4_2
INTC2.ICTAUD0I4_2.BIT.P1TAUD0I4_2
INTC2.ICTAUD0I4_2.BIT.P2TAUD0I4_2
INTC2.ICTAUD0I4_2.BIT.P3TAUD0I4_2
INTC2.ICTAUD0I4_2.BIT.TBTAUD0I4_2
INTC2.ICTAUD0I4_2.BIT.MKTAUD0I4_2
INTC2.ICTAUD0I4_2.BIT.RFTAUD0I4_2
INTC2.ICTAUD0I4_2.BIT.CTTAUD0I4_2
INTC2.ICTAUD0I6_2.UINT16
INTC2.ICTAUD0I6_2.UINT8[L/H]
INTC2.ICTAUD0I6_2.BIT.P0TAUD0I6_2
INTC2.ICTAUD0I6_2.BIT.P1TAUD0I6_2
INTC2.ICTAUD0I6_2.BIT.P2TAUD0I6_2
INTC2.ICTAUD0I6_2.BIT.P3TAUD0I6_2
INTC2.ICTAUD0I6_2.BIT.TBTAUD0I6_2
INTC2.ICTAUD0I6_2.BIT.MKTAUD0I6_2
INTC2.ICTAUD0I6_2.BIT.RFTAUD0I6_2
INTC2.ICTAUD0I6_2.BIT.CTTAUD0I6_2
INTC2.ICTAUD0I8_2.UINT16
INTC2.ICTAUD0I8_2.UINT8[L/H]
INTC2.ICTAUD0I8_2.BIT.P0TAUD0I8_2
INTC2.ICTAUD0I8_2.BIT.P1TAUD0I8_2
INTC2.ICTAUD0I8_2.BIT.P2TAUD0I8_2
INTC2.ICTAUD0I8_2.BIT.P3TAUD0I8_2
INTC2.ICTAUD0I8_2.BIT.TBTAUD0I8_2
INTC2.ICTAUD0I8_2.BIT.MKTAUD0I8_2
INTC2.ICTAUD0I8_2.BIT.RFTAUD0I8_2
INTC2.ICTAUD0I8_2.BIT.CTTAUD0I8_2
INTC2.ICTAUD0I2_2.UINT16
INTC2.ICTAUD0I2_2.UINT8[L/H]
INTC2.ICTAUD0I2_2.BIT.P0TAUD0I2_2
INTC2.ICTAUD0I2_2.BIT.P1TAUD0I2_2
INTC2.ICTAUD0I2_2.BIT.P2TAUD0I2_2
INTC2.ICTAUD0I2_2.BIT.P3TAUD0I2_2
INTC2.ICTAUD0I2_2.BIT.TBTAUD0I2_2
INTC2.ICTAUD0I2_2.BIT.MKTAUD0I2_2
INTC2.ICTAUD0I2_2.BIT.RFTAUD0I2_2
INTC2.ICTAUD0I2_2.BIT.CTTAUD0I2_2
INTC2.ICTAUD0I10_2.UINT16
INTC2.ICTAUD0I10_2.UINT8[L/H]
INTC2.ICTAUD0I10_2.BIT.P0TAUD0I10_2
INTC2.ICTAUD0I10_2.BIT.P1TAUD0I10_2
INTC2.ICTAUD0I10_2.BIT.P2TAUD0I10_2
INTC2.ICTAUD0I10_2.BIT.P3TAUD0I10_2
INTC2.ICTAUD0I10_2.BIT.TBTAUD0I10_2
INTC2.ICTAUD0I10_2.BIT.MKTAUD0I10_2
INTC2.ICTAUD0I10_2.BIT.RFTAUD0I10_2
INTC2.ICTAUD0I10_2.BIT.CTTAUD0I10_2
INTC2.ICTAUD0I12_2.UINT16
INTC2.ICTAUD0I12_2.UINT8[L/H]
INTC2.ICTAUD0I12_2.BIT.P0TAUD0I12_2
INTC2.ICTAUD0I12_2.BIT.P1TAUD0I12_2
INTC2.ICTAUD0I12_2.BIT.P2TAUD0I12_2
INTC2.ICTAUD0I12_2.BIT.P3TAUD0I12_2
INTC2.ICTAUD0I12_2.BIT.TBTAUD0I12_2
INTC2.ICTAUD0I12_2.BIT.MKTAUD0I12_2
INTC2.ICTAUD0I12_2.BIT.RFTAUD0I12_2
INTC2.ICTAUD0I12_2.BIT.CTTAUD0I12_2
INTC2.ICTAUD0I14_2.UINT16
INTC2.ICTAUD0I14_2.UINT8[L/H]
INTC2.ICTAUD0I14_2.BIT.P0TAUD0I14_2
INTC2.ICTAUD0I14_2.BIT.P1TAUD0I14_2
INTC2.ICTAUD0I14_2.BIT.P2TAUD0I14_2
INTC2.ICTAUD0I14_2.BIT.P3TAUD0I14_2
INTC2.ICTAUD0I14_2.BIT.TBTAUD0I14_2
INTC2.ICTAUD0I14_2.BIT.MKTAUD0I14_2
INTC2.ICTAUD0I14_2.BIT.RFTAUD0I14_2
INTC2.ICTAUD0I14_2.BIT.CTTAUD0I14_2
INTC2.ICTAUJ1I0.UINT16
INTC2.ICTAUJ1I0.UINT8[L/H]
INTC2.ICTAUJ1I0.BIT.P0TAUJ1I0
INTC2.ICTAUJ1I0.BIT.P1TAUJ1I0
INTC2.ICTAUJ1I0.BIT.P2TAUJ1I0
INTC2.ICTAUJ1I0.BIT.P3TAUJ1I0
INTC2.ICTAUJ1I0.BIT.TBTAUJ1I0
INTC2.ICTAUJ1I0.BIT.MKTAUJ1I0
INTC2.ICTAUJ1I0.BIT.RFTAUJ1I0
INTC2.ICTAUJ1I0.BIT.CTTAUJ1I0
INTC2.ICTAUJ1I1.UINT16
INTC2.ICTAUJ1I1.UINT8[L/H]
INTC2.ICTAUJ1I1.BIT.P0TAUJ1I1
INTC2.ICTAUJ1I1.BIT.P1TAUJ1I1
INTC2.ICTAUJ1I1.BIT.P2TAUJ1I1
INTC2.ICTAUJ1I1.BIT.P3TAUJ1I1
INTC2.ICTAUJ1I1.BIT.TBTAUJ1I1
INTC2.ICTAUJ1I1.BIT.MKTAUJ1I1
INTC2.ICTAUJ1I1.BIT.RFTAUJ1I1
INTC2.ICTAUJ1I1.BIT.CTTAUJ1I1
INTC2.ICTAUJ1I2.UINT16
INTC2.ICTAUJ1I2.UINT8[L/H]
INTC2.ICTAUJ1I2.BIT.P0TAUJ1I2
INTC2.ICTAUJ1I2.BIT.P1TAUJ1I2
INTC2.ICTAUJ1I2.BIT.P2TAUJ1I2
INTC2.ICTAUJ1I2.BIT.P3TAUJ1I2
INTC2.ICTAUJ1I2.BIT.TBTAUJ1I2
INTC2.ICTAUJ1I2.BIT.MKTAUJ1I2
INTC2.ICTAUJ1I2.BIT.RFTAUJ1I2
INTC2.ICTAUJ1I2.BIT.CTTAUJ1I2
INTC2.ICTAUJ1I3.UINT16
INTC2.ICTAUJ1I3.UINT8[L/H]
INTC2.ICTAUJ1I3.BIT.P0TAUJ1I3
INTC2.ICTAUJ1I3.BIT.P1TAUJ1I3
INTC2.ICTAUJ1I3.BIT.P2TAUJ1I3
INTC2.ICTAUJ1I3.BIT.P3TAUJ1I3
INTC2.ICTAUJ1I3.BIT.TBTAUJ1I3
INTC2.ICTAUJ1I3.BIT.MKTAUJ1I3
INTC2.ICTAUJ1I3.BIT.RFTAUJ1I3
INTC2.ICTAUJ1I3.BIT.CTTAUJ1I3
INTC2.ICRTCA01S.UINT16
INTC2.ICRTCA01S.UINT8[L/H]
INTC2.ICRTCA01S.BIT.P0RTCA01S
INTC2.ICRTCA01S.BIT.P1RTCA01S
INTC2.ICRTCA01S.BIT.P2RTCA01S
INTC2.ICRTCA01S.BIT.P3RTCA01S
INTC2.ICRTCA01S.BIT.TBRTCA01S
INTC2.ICRTCA01S.BIT.MKRTCA01S
INTC2.ICRTCA01S.BIT.RFRTCA01S
INTC2.ICRTCA01S.BIT.CTRTCA01S
INTC2.ICRTCA0AL.UINT16
INTC2.ICRTCA0AL.UINT8[L/H]
INTC2.ICRTCA0AL.BIT.P0RTCA0AL
INTC2.ICRTCA0AL.BIT.P1RTCA0AL
INTC2.ICRTCA0AL.BIT.P2RTCA0AL
INTC2.ICRTCA0AL.BIT.P3RTCA0AL
INTC2.ICRTCA0AL.BIT.TBRTCA0AL
INTC2.ICRTCA0AL.BIT.MKRTCA0AL
INTC2.ICRTCA0AL.BIT.RFRTCA0AL
INTC2.ICRTCA0AL.BIT.CTRTCA0AL
INTC2.ICRTCA0R.UINT16
INTC2.ICRTCA0R.UINT8[L/H]
INTC2.ICRTCA0R.BIT.P0RTCA0R
INTC2.ICRTCA0R.BIT.P1RTCA0R
INTC2.ICRTCA0R.BIT.P2RTCA0R
INTC2.ICRTCA0R.BIT.P3RTCA0R
INTC2.ICRTCA0R.BIT.TBRTCA0R
INTC2.ICRTCA0R.BIT.MKRTCA0R
INTC2.ICRTCA0R.BIT.RFRTCA0R
INTC2.ICRTCA0R.BIT.CTRTCA0R
INTC2.ICRIIC1TI.UINT16
INTC2.ICRIIC1TI.UINT8[L/H]
INTC2.ICRIIC1TI.BIT.P0RIIC1TI
INTC2.ICRIIC1TI.BIT.P1RIIC1TI
INTC2.ICRIIC1TI.BIT.P2RIIC1TI
INTC2.ICRIIC1TI.BIT.P3RIIC1TI
INTC2.ICRIIC1TI.BIT.TBRIIC1TI
INTC2.ICRIIC1TI.BIT.MKRIIC1TI
INTC2.ICRIIC1TI.BIT.RFRIIC1TI
INTC2.ICRIIC1TI.BIT.CTRIIC1TI
INTC2.ICRIIC1EE.UINT16
INTC2.ICRIIC1EE.UINT8[L/H]
INTC2.ICRIIC1EE.BIT.P0RIIC1EE
INTC2.ICRIIC1EE.BIT.P1RIIC1EE
INTC2.ICRIIC1EE.BIT.P2RIIC1EE
INTC2.ICRIIC1EE.BIT.P3RIIC1EE
INTC2.ICRIIC1EE.BIT.TBRIIC1EE
INTC2.ICRIIC1EE.BIT.MKRIIC1EE
INTC2.ICRIIC1EE.BIT.RFRIIC1EE
INTC2.ICRIIC1EE.BIT.CTRIIC1EE
INTC2.ICRIIC1RI.UINT16
INTC2.ICRIIC1RI.UINT8[L/H]
INTC2.ICRIIC1RI.BIT.P0RIIC1RI
INTC2.ICRIIC1RI.BIT.P1RIIC1RI
INTC2.ICRIIC1RI.BIT.P2RIIC1RI
INTC2.ICRIIC1RI.BIT.P3RIIC1RI
INTC2.ICRIIC1RI.BIT.TBRIIC1RI
INTC2.ICRIIC1RI.BIT.MKRIIC1RI
INTC2.ICRIIC1RI.BIT.RFRIIC1RI
INTC2.ICRIIC1RI.BIT.CTRIIC1RI
INTC2.ICRIIC1TEI.UINT16
INTC2.ICRIIC1TEI.UINT8[L/H]
INTC2.ICRIIC1TEI.BIT.P0RIIC1TEI
INTC2.ICRIIC1TEI.BIT.P1RIIC1TEI
INTC2.ICRIIC1TEI.BIT.P2RIIC1TEI
INTC2.ICRIIC1TEI.BIT.P3RIIC1TEI
INTC2.ICRIIC1TEI.BIT.TBRIIC1TEI
INTC2.ICRIIC1TEI.BIT.MKRIIC1TEI
INTC2.ICRIIC1TEI.BIT.RFRIIC1TEI
INTC2.ICRIIC1TEI.BIT.CTRIIC1TEI
INTC2.ICTAUJ2I0.UINT16
INTC2.ICTAUJ2I0.UINT8[L/H]
INTC2.ICTAUJ2I0.BIT.P0TAUJ2I0
INTC2.ICTAUJ2I0.BIT.P1TAUJ2I0
INTC2.ICTAUJ2I0.BIT.P2TAUJ2I0
INTC2.ICTAUJ2I0.BIT.P3TAUJ2I0
INTC2.ICTAUJ2I0.BIT.TBTAUJ2I0
INTC2.ICTAUJ2I0.BIT.MKTAUJ2I0
INTC2.ICTAUJ2I0.BIT.RFTAUJ2I0
INTC2.ICTAUJ2I0.BIT.CTTAUJ2I0
INTC2.ICTAUJ2I1.UINT16
INTC2.ICTAUJ2I1.UINT8[L/H]
INTC2.ICTAUJ2I1.BIT.P0TAUJ2I1
INTC2.ICTAUJ2I1.BIT.P1TAUJ2I1
INTC2.ICTAUJ2I1.BIT.P2TAUJ2I1
INTC2.ICTAUJ2I1.BIT.P3TAUJ2I1
INTC2.ICTAUJ2I1.BIT.TBTAUJ2I1
INTC2.ICTAUJ2I1.BIT.MKTAUJ2I1
INTC2.ICTAUJ2I1.BIT.RFTAUJ2I1
INTC2.ICTAUJ2I1.BIT.CTTAUJ2I1
INTC2.ICTAUJ2I2.UINT16
INTC2.ICTAUJ2I2.UINT8[L/H]
INTC2.ICTAUJ2I2.BIT.P0TAUJ2I2
INTC2.ICTAUJ2I2.BIT.P1TAUJ2I2
INTC2.ICTAUJ2I2.BIT.P2TAUJ2I2
INTC2.ICTAUJ2I2.BIT.P3TAUJ2I2
INTC2.ICTAUJ2I2.BIT.TBTAUJ2I2
INTC2.ICTAUJ2I2.BIT.MKTAUJ2I2
INTC2.ICTAUJ2I2.BIT.RFTAUJ2I2
INTC2.ICTAUJ2I2.BIT.CTTAUJ2I2
INTC2.ICTAUJ2I3.UINT16
INTC2.ICTAUJ2I3.UINT8[L/H]
INTC2.ICTAUJ2I3.BIT.P0TAUJ2I3
INTC2.ICTAUJ2I3.BIT.P1TAUJ2I3
INTC2.ICTAUJ2I3.BIT.P2TAUJ2I3
INTC2.ICTAUJ2I3.BIT.P3TAUJ2I3
INTC2.ICTAUJ2I3.BIT.TBTAUJ2I3
INTC2.ICTAUJ2I3.BIT.MKTAUJ2I3
INTC2.ICTAUJ2I3.BIT.RFTAUJ2I3
INTC2.ICTAUJ2I3.BIT.CTTAUJ2I3
INTC2.ICTAUJ3I0.UINT16
INTC2.ICTAUJ3I0.UINT8[L/H]
INTC2.ICTAUJ3I0.BIT.P0TAUJ3I0
INTC2.ICTAUJ3I0.BIT.P1TAUJ3I0
INTC2.ICTAUJ3I0.BIT.P2TAUJ3I0
INTC2.ICTAUJ3I0.BIT.P3TAUJ3I0
INTC2.ICTAUJ3I0.BIT.TBTAUJ3I0
INTC2.ICTAUJ3I0.BIT.MKTAUJ3I0
INTC2.ICTAUJ3I0.BIT.RFTAUJ3I0
INTC2.ICTAUJ3I0.BIT.CTTAUJ3I0
INTC2.ICTAUJ3I1.UINT16
INTC2.ICTAUJ3I1.UINT8[L/H]
INTC2.ICTAUJ3I1.BIT.P0TAUJ3I1
INTC2.ICTAUJ3I1.BIT.P1TAUJ3I1
INTC2.ICTAUJ3I1.BIT.P2TAUJ3I1
INTC2.ICTAUJ3I1.BIT.P3TAUJ3I1
INTC2.ICTAUJ3I1.BIT.TBTAUJ3I1
INTC2.ICTAUJ3I1.BIT.MKTAUJ3I1
INTC2.ICTAUJ3I1.BIT.RFTAUJ3I1
INTC2.ICTAUJ3I1.BIT.CTTAUJ3I1
INTC2.ICTAUJ3I2.UINT16
INTC2.ICTAUJ3I2.UINT8[L/H]
INTC2.ICTAUJ3I2.BIT.P0TAUJ3I2
INTC2.ICTAUJ3I2.BIT.P1TAUJ3I2
INTC2.ICTAUJ3I2.BIT.P2TAUJ3I2
INTC2.ICTAUJ3I2.BIT.P3TAUJ3I2
INTC2.ICTAUJ3I2.BIT.TBTAUJ3I2
INTC2.ICTAUJ3I2.BIT.MKTAUJ3I2
INTC2.ICTAUJ3I2.BIT.RFTAUJ3I2
INTC2.ICTAUJ3I2.BIT.CTTAUJ3I2
INTC2.ICTAUJ3I3.UINT16
INTC2.ICTAUJ3I3.UINT8[L/H]
INTC2.ICTAUJ3I3.BIT.P0TAUJ3I3
INTC2.ICTAUJ3I3.BIT.P1TAUJ3I3
INTC2.ICTAUJ3I3.BIT.P2TAUJ3I3
INTC2.ICTAUJ3I3.BIT.P3TAUJ3I3
INTC2.ICTAUJ3I3.BIT.TBTAUJ3I3
INTC2.ICTAUJ3I3.BIT.MKTAUJ3I3
INTC2.ICTAUJ3I3.BIT.RFTAUJ3I3
INTC2.ICTAUJ3I3.BIT.CTTAUJ3I3
INTC2.ICSENT0SI.UINT16
INTC2.ICSENT0SI.UINT8[L/H]
INTC2.ICSENT0SI.BIT.P0SENT0SI
INTC2.ICSENT0SI.BIT.P1SENT0SI
INTC2.ICSENT0SI.BIT.P2SENT0SI
INTC2.ICSENT0SI.BIT.P3SENT0SI
INTC2.ICSENT0SI.BIT.TBSENT0SI
INTC2.ICSENT0SI.BIT.MKSENT0SI
INTC2.ICSENT0SI.BIT.RFSENT0SI
INTC2.ICSENT0SI.BIT.CTSENT0SI
INTC2.ICSENT0RI.UINT16
INTC2.ICSENT0RI.UINT8[L/H]
INTC2.ICSENT0RI.BIT.P0SENT0RI
INTC2.ICSENT0RI.BIT.P1SENT0RI
INTC2.ICSENT0RI.BIT.P2SENT0RI
INTC2.ICSENT0RI.BIT.P3SENT0RI
INTC2.ICSENT0RI.BIT.TBSENT0RI
INTC2.ICSENT0RI.BIT.MKSENT0RI
INTC2.ICSENT0RI.BIT.RFSENT0RI
INTC2.ICSENT0RI.BIT.CTSENT0RI
INTC2.ICSENT1SI.UINT16
INTC2.ICSENT1SI.UINT8[L/H]
INTC2.ICSENT1SI.BIT.P0SENT1SI
INTC2.ICSENT1SI.BIT.P1SENT1SI
INTC2.ICSENT1SI.BIT.P2SENT1SI
INTC2.ICSENT1SI.BIT.P3SENT1SI
INTC2.ICSENT1SI.BIT.TBSENT1SI
INTC2.ICSENT1SI.BIT.MKSENT1SI
INTC2.ICSENT1SI.BIT.RFSENT1SI
INTC2.ICSENT1SI.BIT.CTSENT1SI
INTC2.ICSENT1RI.UINT16
INTC2.ICSENT1RI.UINT8[L/H]
INTC2.ICSENT1RI.BIT.P0SENT1RI
INTC2.ICSENT1RI.BIT.P1SENT1RI
INTC2.ICSENT1RI.BIT.P2SENT1RI
INTC2.ICSENT1RI.BIT.P3SENT1RI
INTC2.ICSENT1RI.BIT.TBSENT1RI
INTC2.ICSENT1RI.BIT.MKSENT1RI
INTC2.ICSENT1RI.BIT.RFSENT1RI
INTC2.ICSENT1RI.BIT.CTSENT1RI
INTC2.ICDPE.UINT16
INTC2.ICDPE.UINT8[L/H]
INTC2.ICDPE.BIT.P0DPE
INTC2.ICDPE.BIT.P1DPE
INTC2.ICDPE.BIT.P2DPE
INTC2.ICDPE.BIT.P3DPE
INTC2.ICDPE.BIT.TBDPE
INTC2.ICDPE.BIT.MKDPE
INTC2.ICDPE.BIT.RFDPE
INTC2.ICDPE.BIT.CTDPE
INTC2.ICAPE.UINT16
INTC2.ICAPE.UINT8[L/H]
INTC2.ICAPE.BIT.P0APE
INTC2.ICAPE.BIT.P1APE
INTC2.ICAPE.BIT.P2APE
INTC2.ICAPE.BIT.P3APE
INTC2.ICAPE.BIT.TBAPE
INTC2.ICAPE.BIT.MKAPE
INTC2.ICAPE.BIT.RFAPE
INTC2.ICAPE.BIT.CTAPE
INTC2.IMR1.UINT32
INTC2.IMR1.UINT16[L/H]
INTC2.IMR1.UINT8[LL/LH/HL/HH]
INTC2.IMR1.BIT.IMR1EIMK32 ... INTC2.IMR1.BIT.IMR1EIMK41
INTC2.IMR1.BIT.IMR1EIMK43 ... INTC2.IMR1.BIT.IMR1EIMK63
INTC2.IMR2.UINT32
INTC2.IMR2.UINT16[L/H]
INTC2.IMR2.UINT8[LL/LH/HL/HH]
INTC2.IMR2.BIT.IMR2EIMK64 ... INTC2.IMR2.BIT.IMR2EIMK92
INTC2.IMR3.UINT32
INTC2.IMR3.UINT16[L/H]
INTC2.IMR3.UINT8[LH/HL]
INTC2.IMR3.BIT.IMR3EIMK110 ... INTC2.IMR3.BIT.IMR3EIMK112
INTC2.IMR3.BIT.IMR3EIMK116 ... INTC2.IMR3.BIT.IMR3EIMK119
INTC2.IMR4.UINT32
INTC2.IMR4.UINT16[L/H]
INTC2.IMR4.UINT8[LL/HH]
INTC2.IMR4.BIT.IMR4EIMK132 ... INTC2.IMR4.BIT.IMR4EIMK135
INTC2.IMR4.BIT.IMR4EIMK158
INTC2.IMR4.BIT.IMR4EIMK159
INTC2.IMR5.UINT32
INTC2.IMR5.UINT16[L]
INTC2.IMR5.UINT8[LL/LH]
INTC2.IMR5.BIT.IMR5EIMK160
INTC2.IMR5.BIT.IMR5EIMK161
INTC2.IMR5.BIT.IMR5EIMK168 ... INTC2.IMR5.BIT.IMR5EIMK171
INTC2.IMR6.UINT32
INTC2.IMR6.UINT16[H]
INTC2.IMR6.UINT8[HL]
INTC2.IMR6.BIT.IMR6EIMK209 ... INTC2.IMR6.BIT.IMR6EIMK211
INTC2.IMR7.UINT32
INTC2.IMR7.UINT16[H]
INTC2.IMR7.UINT8[HL]
INTC2.IMR7.BIT.IMR7EIMK240 ... INTC2.IMR7.BIT.IMR7EIMK243
INTC2.IMR8.UINT32
INTC2.IMR8.UINT16[H]
INTC2.IMR8.UINT8[HL/HH]
INTC2.IMR8.BIT.IMR8EIMK277 ... INTC2.IMR8.BIT.IMR8EIMK284
INTC2.IMR10.UINT32
INTC2.IMR10.UINT16[H]
INTC2.IMR10.UINT8[HH]
INTC2.IMR10.BIT.IMR10EIMK347 ... INTC2.IMR10.BIT.IMR10EIMK350
INTC2.IMR11.UINT32
INTC2.IMR11.UINT16[L]
INTC2.IMR11.UINT8[LL]
INTC2.IMR11.BIT.IMR11EIMK356
INTC2.IMR11.BIT.IMR11EIMK357
*/
#endif
