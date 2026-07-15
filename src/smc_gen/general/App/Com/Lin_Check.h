#ifndef LIN_CHECK_H
#define LIN_CHECK_H

#include "Config.h"

void Lin_RxCheck(void);
void Lin_TxCheck(void);
void Lin_BusCheck(void);
void Lin_NrstCheck(void);

void Lin_CheckAAF1RxData(void);
void Lin_CheckAAF2RxData(void);
void Lin_CheckAAF3RxData(void);

#endif




