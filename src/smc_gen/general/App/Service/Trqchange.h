#ifndef TRQCHANGE_H
#define TRQCHANGE_H

#include "r_cg_macrodriver.h"
#include "Define.h"

#ifdef ENABLE_TORQUE_LIN_COMMUNICATION

uint8_t TrqChange_Set(uint8_t ctrl1_data, uint8_t ctrl3_data);
void TrqChange_Apply(void);
void TrqChange_ClearPending(void);
void TrqChange_ResetMicrostep(void);
uint8_t TrqChange_IsCtrl1Active(void);

#endif

#endif
