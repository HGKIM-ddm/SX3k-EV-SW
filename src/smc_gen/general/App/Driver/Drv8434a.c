/***********************************************************************************************************************
 * File Name    : Drv8434a.c
 * Description  : DRV8434A-Q1 저수준 제어 구현
 **********************************************************************************************************************/
#include "Drv8434a.h"

/***********************************************************************************************************************
 * 내부 헬퍼 : 3-state (Tri / Quad level) 핀 제어
 *
 * RH850 포트 레지스터 조합
 *   출력 Low  : PM=0 (출력) , P=0
 *   출력 High : PM=0 (출력) , P=1
 *   Hi-Z      : PM=1 (입력) , PIBC=0 (입력버퍼 OFF)
 *
 * ▣ 순서 규칙
 *   Hi-Z -> 출력 : P 를 먼저 세팅한 뒤 PM=0.  (반대로 하면 직전 P 값이 순간 출력됨)
 *   출력 -> Hi-Z : PM=1 만 하면 즉시 출력버퍼가 닫힘. 글리치 없음.
 *
 * ▣ 입력버퍼(PIBC)를 끄는 이유
 *   Hi-Z 상태의 핀 전압은 약 2.0V 로 CMOS 입력 임계 중간이다.
 *   버퍼가 켜져 있으면 관통 전류가 흐른다. 이 핀들은 읽을 일이 없으므로 끈다.
 *
 * ※ P10(ENABLE) 은 호출처가 상태별 1~2곳뿐이라 헬퍼를 두지 않고
 *   각 공개 함수에서 레지스터를 직접 조작한다.
 **********************************************************************************************************************/

/* --- P0 그룹 (STL_REP=bit1, M1=bit2, STL_MODE=bit3) --------------------------- */
static void P0_OutLow(uint16_t pinMask, uint16_t pmMask)
{
    PORT.P0  &= (uint16_t)~pinMask;
    PORT.PM0 &= (uint16_t)~pmMask;      /* 출력 모드 */
}

static void P0_OutHigh(uint16_t pinMask, uint16_t pmMask)
{
    PORT.P0  |= pinMask;
    PORT.PM0 &= (uint16_t)~pmMask;      /* 출력 모드 */
}

static void P0_HiZ(uint16_t pibcMask, uint16_t pmMask)
{
    PORT.PIBC0 &= (uint16_t)~pibcMask;  /* 입력버퍼 OFF */
    PORT.PM0   |= pmMask;               /* 입력 모드 = Hi-Z */
}

/* --- P8 그룹 (M0=bit0) -------------------------------------------------------- */
static void P8_OutLow(void)
{
    PORT.P8  &= (uint16_t)~_PORT_Pn0_OUTPUT_HIGH;
    PORT.PM8 &= (uint16_t)~_PORT_PMn0_MODE_INPUT;
}

static void P8_OutHigh(void)
{
    PORT.P8  |= _PORT_Pn0_OUTPUT_HIGH;
    PORT.PM8 &= (uint16_t)~_PORT_PMn0_MODE_INPUT;
}

static void P8_HiZ(void)
{
    PORT.PIBC8 &= (uint16_t)~_PORT_PIBCn0_INPUT_BUFFER_ENABLE;
    PORT.PM8   |= _PORT_PMn0_MODE_INPUT;
}

/***********************************************************************************************************************
 * 초기화
 * 전원 인가 직후의 안전 상태를 만든다.
 *   - ENABLE  Low   : 출력 차단  (※ 구 DRVOFF 와 논리가 반대이므로 주의)
 *   - nSLEEP  Low   : 슬립
 *   - VREF    Low   : 전류 0
 *   - DIR     Low
 *   - STL_REP Low   : 드라이버 스톨 보고 차단 (nFAULT 를 OCP/OL 전용으로)
 *   - 스텝모드 1/8  : M0=1, M1=1
 *   - 스톨모드 Torque Count : STL_MODE=GND
 **********************************************************************************************************************/
void Drv8434a_GpioInit(void)
{
    Drv8434a_OFF();                       /* ENABLE = Low  (출력 차단) */
    PORT.P10 &= (uint16_t)~_PORT_Pn2_OUTPUT_HIGH;   /* nSLEEP = Low  (슬립)      */
    PORT.P10 &= (uint16_t)~_PORT_Pn4_OUTPUT_HIGH;   /* DIR    = Low              */
    R_Config_TAUD0_Stop();                          /* VREF   = Low              */       

    Drv8434a_StallReportDisable();
    Drv8434a_SetStepMode(DRV8434A_STEP_1_8);
    Drv8434a_SetStallMode(DRV8434A_STALL_TORQUE_COUNT);
}

/***********************************************************************************************************************
 * 전원 상태
 **********************************************************************************************************************/
void Drv8434a_Wakeup(void)
{
    PORT.P10 |= _PORT_Pn2_OUTPUT_HIGH;              /* nSLEEP = High */
    /* 호출자는 DRV8434A_T_WAKE_US 경과 후 출력을 켤 것 */
}

void Drv8434a_Sleep(void)
{
    Drv8434a_OFF();                       /* 출력 먼저 차단 */
    PORT.P10 &= (uint16_t)~_PORT_Pn2_OUTPUT_HIGH;   /* nSLEEP = Low   */
    PORT.P10 &= (uint16_t)~_PORT_Pn4_OUTPUT_HIGH;   /* DIR    = Low   */
    R_Config_TAUD0_Stop();                          /* VREF   = Low   */

    /* 암전류 대책 (SLOSEC6 6.3.7)
     * M0/M1/STL_MODE 를 MCU 가 High 로 잡고 있으면 슬립 중에도 드라이버 내부
     * 분압 경로로 전류가 흐른다. 전부 Low 로 내린다.
     * 요구사양 암전류 0.05mA 이하를 만족하려면 필요한 처리. */
    P8_OutLow();                                                        /* M0       */
    P0_OutLow(_PORT_Pn2_OUTPUT_HIGH, _PORT_PMn2_MODE_INPUT);            /* M1       */
    P0_OutLow(_PORT_Pn3_OUTPUT_HIGH, _PORT_PMn3_MODE_INPUT);            /* STL_MODE */
}

/***********************************************************************************************************************
 * 출력 제어 (ENABLE = P10_0, Tri-level)
 *
 * ※ 구 DRV8889 의 DRVOFF 와 논리가 정반대다.
 *      DRVOFF : High = 차단
 *      ENABLE : Low  = 차단
 * ※ 상태 변경 후 DRV8434A_T_EN_US 경과해야 출력에 반영된다.
 **********************************************************************************************************************/
void Drv8434a_OFF(void)
{
    PORT.P10  &= (uint16_t)~_PORT_Pn0_OUTPUT_HIGH;  /* ENABLE = Low  */
    PORT.PM10 &= (uint16_t)~_PORT_PMn0_MODE_INPUT;  /* 출력 모드      */
}

void Drv8434a_ON(void)
{
    PORT.P10  |= _PORT_Pn0_OUTPUT_HIGH;             /* ENABLE = High */
    PORT.PM10 &= (uint16_t)~_PORT_PMn0_MODE_INPUT;  /* 출력 모드      */
}

void Drv8434a_ON_TRQ8X(void)
{
    /* ENABLE = Hi-Z : 출력 동작 + 토크카운트 8배 스케일링
     * 토크카운트 실측이 0.26~0.3V (출력 스팬 0.2~2.3V 의 약 5%) 로 낮을 때 사용. */
    PORT.PIBC10 &= (uint16_t)~_PORT_PIBCn0_INPUT_BUFFER_ENABLE; /* 입력버퍼 OFF */
    PORT.PM10   |= _PORT_PMn0_MODE_INPUT;                       /* Hi-Z         */
}

/***********************************************************************************************************************
 * 방향 / STEP / VREF
 **********************************************************************************************************************/
void Drv8434a_DirCW(void)   { PORT.P10 |= _PORT_Pn4_OUTPUT_HIGH; }
void Drv8434a_DirCCW(void)  { PORT.P10 &= (uint16_t)~_PORT_Pn4_OUTPUT_HIGH; }

void Drv8434a_StepStart(void) { R_Config_TAUJ1_Start(); }
void Drv8434a_StepStop(void)  { R_Config_TAUJ1_Stop();  }

void Drv8434a_VrefOn(void)  { R_Config_TAUD0_Start(); }
void Drv8434a_VrefOff(void) { R_Config_TAUD0_Stop();  }

/***********************************************************************************************************************
 * 스텝 모드 (M0 / M1)
 * SLOSEC6 Table 6-2
 *
 *   M0      M1      모드
 *   0       0       Full step 100%
 *   1       0       Non-circular 1/2
 *   Hi-Z    0       1/2
 *   0       1       1/4
 *   1       1       1/8      <= 현행
 *   Hi-Z    1       1/16
 *   0       Hi-Z    1/32
 *   Hi-Z    Hi-Z    1/128
 *   1       Hi-Z    1/256
 *
 * ※ 주행 중 변경 시 STEP 상승엣지에서 새 모드의 다음 유효 상태로 넘어간다.
 *   위치 카운트가 어긋날 수 있으므로 정지 상태에서 변경할 것.
 **********************************************************************************************************************/
void Drv8434a_SetStepMode(Drv8434a_StepMode_t mode)
{
    /* --- M0 --- */
    switch (mode)
    {
        case DRV8434A_STEP_FULL:
        case DRV8434A_STEP_1_4:
        case DRV8434A_STEP_1_32:
            P8_OutLow();                /* M0 = 0 */
            break;

        case DRV8434A_STEP_NONCIRC_1_2:
        case DRV8434A_STEP_1_8:
        case DRV8434A_STEP_1_256:
            P8_OutHigh();               /* M0 = 1 */
            break;

        case DRV8434A_STEP_1_2:
        case DRV8434A_STEP_1_16:
        case DRV8434A_STEP_1_128:
            P8_HiZ();                   /* M0 = Hi-Z */
            break;

        default:
            P8_OutHigh();               /* 알 수 없는 값이면 1/8 로 */
            break;
    }

    /* --- M1 --- */
    switch (mode)
    {
        case DRV8434A_STEP_FULL:
        case DRV8434A_STEP_NONCIRC_1_2:
        case DRV8434A_STEP_1_2:
            P0_OutLow(_PORT_Pn2_OUTPUT_HIGH, _PORT_PMn2_MODE_INPUT);        /* M1 = 0 */
            break;

        case DRV8434A_STEP_1_4:
        case DRV8434A_STEP_1_8:
        case DRV8434A_STEP_1_16:
            P0_OutHigh(_PORT_Pn2_OUTPUT_HIGH, _PORT_PMn2_MODE_INPUT);       /* M1 = 1 */
            break;

        case DRV8434A_STEP_1_32:
        case DRV8434A_STEP_1_128:
        case DRV8434A_STEP_1_256:
            P0_HiZ(_PORT_PIBCn2_INPUT_BUFFER_ENABLE, _PORT_PMn2_MODE_INPUT);/* M1 = Hi-Z */
            break;

        default:
            P0_OutHigh(_PORT_Pn2_OUTPUT_HIGH, _PORT_PMn2_MODE_INPUT);
            break;
    }
}

/***********************************************************************************************************************
 * 스톨 검출 모드 (STL_MODE)
 * SLOSEC6 Table 6-6
 *
 * ※ STALL_THRESHOLD 모드 주의
 *   - 반드시 '모터가 정속 회전 중'에 진입할 것.
 *     정지 상태에서 진입하면 드라이버가 무조건 스톨로 판정한다.
 *   - 진입 직후 Drv8434a_FaultClear() 로 대기 중인 폴트를 지울 것.
 *   - 현 회로는 TRQ_CNT 핀이 ADC 입력 전용이라 임계 전압을 인가할 수단이 없다.
 *     이 모드를 쓰려면 별도 아날로그 출력 경로가 필요하다.
 **********************************************************************************************************************/
void Drv8434a_SetStallMode(Drv8434a_StallMode_t mode)
{
    switch (mode)
    {
        case DRV8434A_STALL_TORQUE_COUNT:
            /* GND : TRQ_CNT 핀이 토크카운트 전압을 출력 -> ADC 로 읽음 */
            P0_OutLow(_PORT_Pn3_OUTPUT_HIGH, _PORT_PMn3_MODE_INPUT);
            break;

        case DRV8434A_STALL_LEARNING:
            /* Hi-Z : 학습 모드 */
            P0_HiZ(_PORT_PIBCn3_INPUT_BUFFER_ENABLE, _PORT_PMn3_MODE_INPUT);
            break;

        case DRV8434A_STALL_THRESHOLD:
            /* DVDD : TRQ_CNT 핀이 임계 전압 입력 */
            P0_OutHigh(_PORT_Pn3_OUTPUT_HIGH, _PORT_PMn3_MODE_INPUT);
            break;

        default:
            P0_OutLow(_PORT_Pn3_OUTPUT_HIGH, _PORT_PMn3_MODE_INPUT);
            break;
    }
}

/***********************************************************************************************************************
 * STL_REP  (P0_1, 오픈드레인 공유 라인)
 *
 * 이 핀은 드라이버와 MCU 가 함께 구동하는 오픈드레인 버스다.
 *   - 평상시  : 드라이버가 Low 로 당김
 *   - 스톨 시 : 드라이버가 릴리즈 -> 외부 풀업 R61(10k) 로 High
 *   - MCU Low : 스톨 보고 비활성 (nFAULT 에 스톨이 섞이지 않음)
 *
 * ※ Config_PORT 에서 이 핀은 Open-drain + Bidirectional 로 설정되어 있다.
 *   push-pull 로 High 를 내면 드라이버의 Low 구동과 충돌하므로 절대 금지.
 **********************************************************************************************************************/
void Drv8434a_StallReportDisable(void)
{
    /* MCU 가 Low 로 당겨 드라이버의 스톨 보고를 막는다.
     * 이렇게 하면 nFAULT 가 OCP / OL / UVLO / CPUV / OTSD 전용이 되어
     * 단선·단락 판별 로직이 깨끗해진다. */
    P0_OutLow(_PORT_Pn1_OUTPUT_HIGH, _PORT_PMn1_MODE_INPUT);
}

void Drv8434a_StallReportEnable(void)
{
    /* 오픈드레인 출력에 High 를 쓰면 라인이 해제(Hi-Z)되어
     * 드라이버가 자유롭게 구동할 수 있고 MCU 는 읽을 수 있다. */
    P0_OutHigh(_PORT_Pn1_OUTPUT_HIGH, _PORT_PMn1_MODE_INPUT);
}

uint8_t Drv8434a_IsStallReported(void)
{
    /* STL_REP 는 nFAULT 와 극성이 반대다. High = 스톨. */
    return ((PORT.PPR0 & (uint16_t)(1U << 1)) != 0U) ? 1U : 0U;
}

/***********************************************************************************************************************
 * 폴트
 **********************************************************************************************************************/
uint8_t Drv8434a_IsFault(void)
{
    /* nFAULT 는 Active Low. Low = 폴트. */
    return ((PORT.PPR10 & (uint16_t)(1U << 5)) == 0U) ? 1U : 0U;
}

/***********************************************************************************************************************
 * 폴트 클리어 : nSLEEP 20 ~ 40us Low 펄스 (SLOSEC6 6.4.4)
 *
 *  ┌ 시간 제약 ─────────────────────────────────────────────────────────────────┐
 *  │  20us 미만 : 클리어 안 됨                                                   │
 *  │  20 ~ 40us : 정상 클리어                                                    │
 *  │  40 ~ 120us: 클리어는 되지만 셧다운 여부 불확정                              │
 *  │  120us 초과: 슬립 진입                                                      │
 *  └───────────────────────────────────────────────────────────────────────────┘
 *
 *  창이 좁아 인터럽트가 끼면 상한을 넘긴다. 따라서 DI/EI 로 감싼다.
 *
 *  ※ 반드시 모터 정지 상태에서 호출할 것.
 *    구동 중에 호출하면 DI 구간 동안 TAUJ1 스텝 카운트 인터럽트가 지연되어
 *    step_position 이 어긋날 수 있다.
 *
 *  ※ DRV8434A_PULSE_LOOP 값은 컴파일러 최적화·클럭에 따라 달라진다.
 *    최초 1회는 반드시 오실로스코프로 nSLEEP 펄스폭을 실측해 보정할 것.
 **********************************************************************************************************************/
#define DRV8434A_PULSE_LOOP     (200U)   /* TODO: 실측 보정 필요 (목표 25~30us) */

void Drv8434a_FaultClear(void)
{
    volatile uint16_t i;

    DI();

    PORT.P10 &= (uint16_t)~_PORT_Pn2_OUTPUT_HIGH;   /* nSLEEP = Low */

    for (i = 0U; i < DRV8434A_PULSE_LOOP; i++)
    {
       NOP();
    }

    PORT.P10 |= _PORT_Pn2_OUTPUT_HIGH;              /* nSLEEP = High */

    EI();
}


