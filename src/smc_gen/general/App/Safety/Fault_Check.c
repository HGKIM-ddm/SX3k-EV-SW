#include "Fault_Check.h"
#include "Service.h"

static uint8_t      fault_prev   = 0U;   /* 직전 확정 상태 (1 = Low 확정)          */
static uint8_t      fault_deb    = 0U;   /* 디바운스 카운터                        */
static uint8_t      fault_judged = 0U;   /* 1 = 이번 사이클에서 이미 분류함         */
 
static unsigned int fault_oc     = NO_ERROR;
static unsigned int fault_ol     = NO_ERROR;
static uint16_t     fault_latency_ms = 0U;
static uint16_t     fault_vbat       = 0U;
 
/***********************************************************************************************************************
 * Function Name: FaultCheck_OnMotorStart
 * Description  : 모터 인에이블 시점 기준시각을 잡는다.
 * Called By    : Motor_On()
 ***********************************************************************************************************************/
void FaultCheck_OnMotorStart(void)
{
    fault_prev = 0U;
    fault_deb  = 0U;
 
    G_Timer1ms.MotorRunTime         = 0U;
    G_Timer1msFlag.MotorRunTimeFlag = 1U;
}
 
/***********************************************************************************************************************
 * Function Name: FaultCheck_OnMotorStop
 * Description  : 경과시간 타이머 정지.
 * Called By    : Motor_Off()
 ***********************************************************************************************************************/
void FaultCheck_OnMotorStop(void)
{
    fault_prev = 0U;
    fault_deb  = 0U;
 
    G_Timer1msFlag.MotorRunTimeFlag = 0U;
    G_Timer1ms.MotorRunTime         = 0U;
}
 
/***********************************************************************************************************************
 * Function Name: FaultCheck_Clear
 * Description  : 분류 결과 초기화. Drv8434a_FaultClear() 와 짝으로 호출한다.
 * Called By    : Error_CheckShort() / Error_CheckOpen()
 ***********************************************************************************************************************/
void FaultCheck_Clear(void)
{
    fault_oc     = NO_ERROR;
    fault_ol     = NO_ERROR;
    fault_judged = 0U;
    fault_prev   = 0U;
    fault_deb    = 0U;
}
 
unsigned int FaultCheck_GetOverCurrent(void)
{
    return fault_oc;
}
 
unsigned int FaultCheck_GetOpenLoad(void)
{
    return fault_ol;
}
 
uint16_t FaultCheck_GetLatency(void)
{
    return fault_latency_ms;
}

uint16_t FaultCheck_GetVbat(void)
{
     return fault_vbat;
}

uint8_t FaultCheck_IsFaultActive(void)
{
     return fault_prev;          /* 1 = nFAULT Low 확정 상태 */
}
 
/***********************************************************************************************************************
 * Function Name: FaultCheck_Sample
 * Description  : nFAULT 하강에지를 감시하고 지연시간으로 원인을 분류한다.
 * Called By    : App_HwCheck (1 ms 주기)
 *
 *  ※ 지연시간에는 디바운스 FAULT_DEBOUNCE_CNT(=2 ms) 가 포함된다.
 *    경계 30 ms 대비 무시 가능한 크기다.
 ***********************************************************************************************************************/
void FaultCheck_Sample(void)
{
    uint8_t now;
 
    /* 정지/홀딩 구간은 평가하지 않는다 (전기각 0/90/180/270 도 OL 오검출 방지) */
    if (motor_start != ON)
    {
        fault_prev = 0U;
        fault_deb  = 0U;
        return;
    }
 
    /* ECU 레벨 전압 이상 중이면 nFAULT 원인이 UVLO / CPUV 일 수 있으므로 분류하지 않는다.
     * 이 구간의 처리는 Error_CheckVoltage() 가 담당한다. */
    if ((AAFx_Low_Volt == UNDER_VOLTAGE) || (AAFx_Over_Volt == OVER_VOLTAGE))
    {
        fault_deb = 0U;
        return;
    }
 
    now = Drv8434a_IsFault();          /* 1 = nFAULT Low = 폴트 */
 
    if (now == 0U)
    {
        fault_deb  = 0U;
        fault_prev = 0U;
        return;
    }
 
    if (fault_prev == 1U)              /* 이미 확정한 Low 가 유지 중 : 중복 처리 방지 */
    {
        return;
    }
 
    fault_deb++;
 
    if (fault_deb < FAULT_DEBOUNCE_CNT)
    {
        return;
    }
 
    fault_prev = 1U;                   /* 하강에지 확정 */
 
    if (fault_judged == 1U)            /* 이번 사이클에서 이미 분류함 */
    {
        return;
    }
 
    fault_judged     = 1U;
    fault_latency_ms = (uint16_t)G_Timer1ms.MotorRunTime;
    fault_vbat       = (uint16_t)bat_adc;    /* 폴트 순간 ADC (평균 아님) */
 
    if (fault_latency_ms < FAULT_OCP_OL_BOUNDARY)
    {
        fault_oc = OVER_CURRENT;       /* tOCP 2 us  : 즉시 → 단락  */
    }
    else
    {
        fault_ol = MOTOR_FAULT;        /* tOL 65 ms  : 지연 → 단선  */
    }
}


