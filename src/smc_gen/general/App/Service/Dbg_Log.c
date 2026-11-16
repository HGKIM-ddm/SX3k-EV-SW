#include "Dbg_Log.h"

/* [디버그 전용] 리셋해도 지워지지 않는 영역 (링커 .dbglog NOCLEAR, iRAM_DBG) */
#pragma ghs section bss=".dbglog"
DbgLog_t g_dbg;
#pragma ghs section

static void Dbg_ClearRec(DbgRec_t *r)
{
    uint8_t  *p = (uint8_t *)r;
    uint32_t i;

    for (i = 0U; i < (uint32_t)sizeof(DbgRec_t); i++)
    {
        p[i] = 0U;
    }
}

void Dbg_Boot(void)
{
    uint32_t resf;
    uint32_t resfr;
    uint32_t boot;

    /* RESF 는 POR 이후 누적되므로(다른 코드가 쓸 수 있어 지우지 않음) POR 판정은 RESFR 로 한다.
       RESFR 은 읽은 뒤 클리어 -> 다음 부팅에서는 그 사이 새로 발생한 리셋 원인만 남는다 */
    resf  = (uint32_t)RESCTL.RESF;
    resfr = (uint32_t)RESCTL.RESFR;
    RESCTL.RESFCR = resfr;

    /* 전원 투입(POR)이면 RAM 내용이 쓰레기이므로 읽지 않고 초기화 */
    if (((resfr & DBG_RESF_POR) != 0UL) || (g_dbg.cur.magic != DBG_MAGIC))
    {
        Dbg_ClearRec(&g_dbg.prev);
        boot = 0UL;
    }
    else
    {
        g_dbg.prev = g_dbg.cur;
        boot = g_dbg.cur.boot_no;
    }

    Dbg_ClearRec(&g_dbg.cur);
    g_dbg.cur.magic   = DBG_MAGIC;
    g_dbg.cur.boot_no = boot + 1UL;
    g_dbg.cur.resf    = resf;
    g_dbg.cur.resfr   = resfr;
}

void Dbg_Tick1ms(void)
{
    g_dbg.cur.ms++;
}

void Dbg_RxIsr(void)
{
    g_dbg.cur.rx_cnt++;
    g_dbg.cur.rx_last_ms = g_dbg.cur.ms;
}

void Dbg_LinErrIn(void)
{
    g_dbg.cur.err_cnt++;
    g_dbg.cur.err_last_ms  = g_dbg.cur.ms;
    g_dbg.cur.err_ltrc_in  = (uint8_t)RLN30.LTRC;
    g_dbg.cur.err_lst_in   = (uint8_t)RLN30.LST;
    g_dbg.cur.err_lest_in  = (uint8_t)RLN30.LEST;
    g_dbg.cur.err_lmst_in  = (uint8_t)RLN30.LMST;
    g_dbg.cur.err_loop_cnt = 0UL;
    g_dbg.cur.err_in_loop  = 1U;
}

void Dbg_LinErrLoop(void)
{
    g_dbg.cur.err_loop_cnt++;
}

void Dbg_LinErrOut(void)
{
    g_dbg.cur.err_ltrc_out = (uint8_t)RLN30.LTRC;
    g_dbg.cur.err_lest_out = (uint8_t)RLN30.LEST;
    g_dbg.cur.err_in_loop  = 0U;
}

void Dbg_BusOff(void)
{
    g_dbg.cur.busoff_cnt++;
    g_dbg.cur.busoff_last_ms = g_dbg.cur.ms;
    g_dbg.cur.bo_ltrc = (uint8_t)RLN30.LTRC;
    g_dbg.cur.bo_lst  = (uint8_t)RLN30.LST;
    g_dbg.cur.bo_lest = (uint8_t)RLN30.LEST;
    g_dbg.cur.bo_lmst = (uint8_t)RLN30.LMST;
    g_dbg.cur.bo_lcuc = (uint8_t)RLN30.LCUC;
}

void Dbg_Wake(void)
{
    g_dbg.cur.wake_cnt++;
}

void Dbg_SleepStep(unsigned int step)
{
    g_dbg.cur.sleep_call_cnt++;
    if ((uint8_t)step != g_dbg.cur.sleep_step)
    {
        g_dbg.cur.sleep_step_prev = g_dbg.cur.sleep_step;
        g_dbg.cur.sleep_step      = (uint8_t)step;
        g_dbg.cur.sleep_step_ms   = g_dbg.cur.ms;
    }
}

void Dbg_McuSleepIn(void)
{
    if (g_dbg.cur.mcu_call == 0UL)
    {
        g_dbg.cur.mcu_first_ms    = g_dbg.cur.ms;
        g_dbg.cur.mcu_pwr_chk     = (uint8_t)power_chk;
        g_dbg.cur.mcu_step_chk    = (uint8_t)step_check_flag;
        g_dbg.cur.mcu_init_status = (uint8_t)AAFx_InitStatus;
        g_dbg.cur.mcu_nrst        = (uint8_t)lin_nrst_low_flag;
        g_dbg.cur.mcu_lin_out     = (uint8_t)AAF_LINOut;
        g_dbg.cur.mcu_ldc         = (uint8_t)LDCRdy;
        g_dbg.cur.mcu_ign_chk     = (uint8_t)IGN_Chk;
    }
    g_dbg.cur.mcu_call++;
}

void Dbg_McuSleepRetPwr(void)  { g_dbg.cur.mcu_ret_pwr++; }
void Dbg_McuSleepRetNrst(void) { g_dbg.cur.mcu_ret_nrst++; }
void Dbg_McuSleepOff(void)     { g_dbg.cur.mcu_off++; }
