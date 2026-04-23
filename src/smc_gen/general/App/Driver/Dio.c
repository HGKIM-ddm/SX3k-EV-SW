#include "Dio.h"

void LinTrcv_On(void)
{
	PORT.P10 |= _PORT_Pn3_OUTPUT_HIGH; // MCU_LIN_SLEEP_MODE
}

void LinTrcv_Off(void)
{
	PORT.P10 &= ~_PORT_Pn3_OUTPUT_HIGH; // MCU_LIN_SLEEP_MODE
}

