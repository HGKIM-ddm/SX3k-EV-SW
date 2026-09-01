#ifndef FAULT_CHECK_H
#define FAULT_CHECK_H

#include "Config.h"

void         FaultCheck_Sample(void);          /* 1 ms 주기. App_HwCheck 에서 호출 */
void         FaultCheck_OnMotorStart(void);    /* Motor_On() 에서 호출              */
void         FaultCheck_OnMotorStop(void);     /* Motor_Off() 에서 호출             */
void         FaultCheck_Clear(void);           /* 재시도 진입 시 분류 결과 초기화    */
 
unsigned int FaultCheck_GetOverCurrent(void);  /* OVER_CURRENT(0x800) / NO_ERROR   */
unsigned int FaultCheck_GetOpenLoad(void);     /* MOTOR_FAULT (0x100) / NO_ERROR   */
uint16_t     FaultCheck_GetLatency(void);      /* 실측용 : nFAULT 지연시간 [ms]     */
uint16_t     FaultCheck_GetVbat(void);       /* 실측용 : 폴트 순간 배터리 ADC */
uint8_t      FaultCheck_IsFaultActive(void);   /* 1 = nFAULT Low 확정 상태 */

#endif

