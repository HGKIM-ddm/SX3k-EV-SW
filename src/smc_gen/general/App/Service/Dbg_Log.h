#ifndef DBG_LOG_H
#define DBG_LOG_H

#include "Config.h"

/* =====================================================================
 * [디버그 전용] 리셋되어도 남는 기록 (0xFEBFFC00, 링커 .dbglog NOCLEAR)
 *   - 부팅할 때 직전 기록(cur)을 prev 로 복사하고 cur 를 새로 시작한다.
 *   - main 실행 후 연결 : g_dbg.prev = 리셋 직전 상태
 *   - 리셋 벡터에서 정지 : g_dbg.cur  = 리셋 직전 상태
 * ===================================================================== */
#define DBG_MAGIC        (0x44424722UL)   /* 구조체 변경 시 값 변경 (이전 형식 기록 무효화) */
#define DBG_RESF_POR     (0x00000200UL)   /* RESF9 / RESFR9 : Power-up reset flag (HW 매뉴얼 9BC.3.2) */

typedef struct
{
    uint32_t magic;
    uint32_t boot_no;           /* POR 이후 몇 번째 부팅인지 */
    uint32_t resf;              /* RESCTL.RESF  : POR 이후 누적된 리셋 원인 (지우지 않음) */
    uint32_t resfr;             /* RESCTL.RESFR : 직전 부팅 이후 새로 발생한 리셋 원인 (매 부팅 클리어) */
    uint32_t ms;                /* 부팅 후 경과 ms */

    uint32_t rx_cnt;            /* Lin_ReceiveComplete_Interrupt 진입 횟수 */
    uint32_t rx_last_ms;        /* 마지막 진입 시각 */

    uint32_t err_cnt;           /* Lin_Status_Interrupt 진입 횟수 */
    uint32_t err_last_ms;
    uint8_t  err_ltrc_in;       /* 진입 시 RLN30.LTRC (bit0 = FTS) */
    uint8_t  err_lst_in;        /* 진입 시 RLN30.LST */
    uint8_t  err_lest_in;       /* 진입 시 RLN30.LEST */
    uint8_t  err_lmst_in;       /* 진입 시 RLN30.LMST */
    uint8_t  err_ltrc_out;      /* 종료 시 RLN30.LTRC */
    uint8_t  err_lest_out;      /* 종료 시 RLN30.LEST */
    uint8_t  err_in_loop;       /* 1 = while 루프 안 (못 빠져나오면 1 유지) */
    uint8_t  rsv0;
    uint32_t err_loop_cnt;      /* 마지막 에러의 while 반복 횟수 */

    uint32_t busoff_cnt;        /* Lin_BusCheck 4초 무수신 진입 횟수 */
    uint32_t busoff_last_ms;
    uint8_t  bo_ltrc;           /* 4초 무수신 판정 시점 RLN30.LTRC */
    uint8_t  bo_lst;            /* 4초 무수신 판정 시점 RLN30.LST  */
    uint8_t  bo_lest;           /* 4초 무수신 판정 시점 RLN30.LEST */
    uint8_t  bo_lmst;           /* 4초 무수신 판정 시점 RLN30.LMST */
    uint8_t  bo_lcuc;           /* 4초 무수신 판정 시점 RLN30.LCUC */
    uint8_t  rsv3[3];
    uint32_t wake_cnt;          /* Lin_Wakeup 횟수 */
    uint32_t sleep_call_cnt;    /* Lin_Sleep 호출 횟수 */
    uint8_t  sleep_step;        /* 마지막 lin_sleep_step */
    uint8_t  sleep_step_prev;   /* 직전 step */
    uint16_t rsv1;
    uint32_t sleep_step_ms;     /* step 이 마지막으로 바뀐 시각 */

    uint32_t mcu_call;          /* MCU_Sleep 진입 횟수 */
    uint32_t mcu_ret_pwr;       /* power_chk == Normal_Shutdown 으로 return 횟수 */
    uint32_t mcu_ret_nrst;      /* lin_nrst_low_flag 로 return 횟수 */
    uint32_t mcu_off;           /* 전원 차단까지 진행한 횟수 */
    uint32_t mcu_first_ms;      /* 첫 진입 시각 */
    uint8_t  mcu_pwr_chk;       /* 첫 진입 시 power_chk */
    uint8_t  mcu_step_chk;      /* 첫 진입 시 step_check_flag */
    uint8_t  mcu_init_status;   /* 첫 진입 시 AAFx_InitStatus */
    uint8_t  mcu_nrst;          /* 첫 진입 시 lin_nrst_low_flag */
    uint8_t  mcu_lin_out;       /* 첫 진입 시 AAF_LINOut */
    uint8_t  mcu_ldc;           /* 첫 진입 시 LDCRdy */
    uint8_t  mcu_ign_chk;       /* 첫 진입 시 IGN_Chk */
    uint8_t  rsv2;
} DbgRec_t;

typedef struct
{
    DbgRec_t prev;
    DbgRec_t cur;
} DbgLog_t;

extern DbgLog_t g_dbg;

void Dbg_Boot(void);
void Dbg_Tick1ms(void);
void Dbg_RxIsr(void);
void Dbg_LinErrIn(void);
void Dbg_LinErrLoop(void);
void Dbg_LinErrOut(void);
void Dbg_BusOff(void);
void Dbg_Wake(void);
void Dbg_SleepStep(unsigned int step);
void Dbg_McuSleepIn(void);
void Dbg_McuSleepRetPwr(void);
void Dbg_McuSleepRetNrst(void);
void Dbg_McuSleepOff(void);

#endif
