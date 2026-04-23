#ifndef LIN_INTERRUPT_H
#define LIN_INTERRUPT_H

#include "Config.h"
#include "Lin_Driver.h"
#include "Lin_Service.h"

void Lin_ReceiveComplete_Interrupt(void);
void Lin_Transmit_Interrupt(void);
void Lin_Interrupt(void);
void Lin_Status_Interrupt(void);

#endif


