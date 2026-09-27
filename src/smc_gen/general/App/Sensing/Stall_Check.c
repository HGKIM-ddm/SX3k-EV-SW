#include "Stall_Check.h"

/***********************************************************************************************************************
 * MCU assisted Stall Detection  (DRV8434A-Q1 / SLOSEC6 Table 6-6)
 *
 *  드라이버는 스톨을 감지해도 출력을 끊지 않는다 (Table 6-7 : STALL = Report Only,
 *  H-Bridge / Indexer 모두 Operating). 모터를 세우는 주체는 전적으로 MCU다.
 *
 *  구성 :
 *    STL_MODE = GND      → TRQ_CNT 핀이 토크카운트 아날로그 전압 출력
 *    STL_REP  = MCU Low  → 드라이버 자체 스톨보고 차단 (데이터시트 요구사항)
 *                          nFAULT 는 OCP / OL 전용으로 남는다
 *    ENABLE   = Hi-Z     → 토크카운트 x8 스케일링
 *
 *  임계값은 SW 변수로만 관리한다. 드라이버 학습값(중간값)을 그대로 쓰면
 *  토크카운트가 바닥까지 떨어질 때까지 기다리게 되므로 그보다 위에서 자른다.
 *
 *  ※ 12bit ADC / AVREFH 5.0V 기준 → 819 counts / V
 **********************************************************************************************************************/
static uint16_t stall_th_adc = STALL_TH;

/***********************************************************************************************************************
 * Function Name: StallCheck_ChangeStallTh
 * Description  : 동작 상태에 따라 SW 스톨 임계값을 선택한다.
 *                구 코드의 Drv8889_WriteCtrl6() SPI write 를 변수 대입으로 대체.
 * Called By    : ADC_TrqCountSample (2 ms 주기)
 ***********************************************************************************************************************/
void StallCheck_ChangeStallTh(void)
{
    stall_th_adc = STALL_TH;  /* 정상 동작 구간 : 더 안정적으로 */
}

/***********************************************************************************************************************
 * Function Name: StallCheck_GetStallTh
 * Description  : 현재 적용중인 SW 스톨 임계값 (디버깅 / LIN 진단용)
 ***********************************************************************************************************************/
uint16_t StallCheck_GetStallTh(void)
{
    return stall_th_adc;
}

/***********************************************************************************************************************
 * Function Name: Stall_Check
 * Description  : 토크카운트 이동평균값과 SW 임계값을 비교하여 스톨을 판정한다.
 * Called By    : ADC_TrqCountSample (2 ms 주기)
 *
 *  확정시간 = 필터 8 ms + (cumulative_stall_count x 2 ms)
 ***********************************************************************************************************************/
void Stall_Check(void)
{
    if ((motor_start == ON)
        && (AAF_Maximum_Torque_Test_Mode == OFF)
        && (trq_cnt_valid == 1U)
        && (G_Timer1ms.StallTime >= STALL_CHK_WAIT_TIME))
    {
        if (trq_cnt_avg <= (unsigned int)stall_th_adc)
        {
            stall_count++;

            if (stall_count >= cumulative_stall_count)
            {
                motor_stall_flag = MOTOR_STALL;
                stall_count      = cumulative_stall_count;
            }
        }
        else
        {
            stall_count = 0U;
        }
    }
    else
    {
        stall_count = 0U;
    }
}

