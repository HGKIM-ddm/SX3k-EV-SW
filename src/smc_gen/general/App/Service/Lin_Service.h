#ifndef LIN_SERVICE_H
#define LIN_SERVICE_H

#include "Config.h"
#include "Lin_Driver.h"

void Lin_HandleReceivedHeader(void);
void Lin_HandleReceivedResponse(void);
void Lin_CalculateVerifyChecksum(uint8_t is_response_received);

#endif

