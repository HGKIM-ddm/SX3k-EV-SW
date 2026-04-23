#ifndef LIN_DRIVER_H
#define LIN_DRIVER_H

#include "Config.h"

void Lin_SlaveInit(void);
void Lin_SlaveReceive(uint8_t Data_length);
void Lin_SlaveTransmit(uint8_t *databuf, uint8_t Data_length);
void Lin_SlaveNoResponse(void);
void Lin_GetReponseRxData(uint8_t *RxData);

#endif


