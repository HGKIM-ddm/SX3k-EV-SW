#ifndef OPERATING_MODE_H
#define OPERATING_MODE_H

#include "Config.h"

void Operating_Mode(void);
void Operate_Abort(void);
void Torque_TestMode(void);
void Operate_SelectTxPostion(void);
unsigned int Operate_GetTargetPosition(unsigned int action);

#endif


