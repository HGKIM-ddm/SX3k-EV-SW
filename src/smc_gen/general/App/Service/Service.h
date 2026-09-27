#ifndef Service_H
#define Service_H

#include "Config.h"
#include "Dio.h"
#include "Drv8434a.h"
#include "Adc_Check.h"
#include "Stall_Check.h"

#include "AntiPinch.h"
#include "Error_Check.h"
#include "FailSafety_Mode.h"
#include "Fdl.h"
#include "Init_Move.h"
#include "Limp_Home.h"
#include "Lin_Check.h"
#include "Lin_Sleep.h"
#include "Motor.h"
#include "Operating_Mode.h"
#include "Protection_Mode.h"
#include "Re_Init.h"
#include "HighSpeed_Mode.h"
#include "Fault_Check.h"

void AAF_SetType(void);
void App_HwCheck(void);
void App_SwLogic(void);

#endif


