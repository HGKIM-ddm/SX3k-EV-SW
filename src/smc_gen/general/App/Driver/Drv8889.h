#ifndef DRV8889_H
#define DRV8889_H

#include "Config.h"

void Drv8889_Init(void);
void Drv8889_Wakeup(void);
void Drv8889_Sleep(void);

void Drv8889_On(void);
void Drv8889_On2(void);
void Drv8889_Off(void);
void Drv8889_Off2(void);

void Drv8889_ScsActive(void);
void Drv8889_ScsInactive(void);

void Drv8889_StepHigh(void); 
void Drv8889_StepLow(void); 

void Drv8889_DirCW(void);  
void Drv8889_DirCCW(void);  

void Drv8889_SpiInit(void);
void Drv8889_FaultClear(void);

#endif


