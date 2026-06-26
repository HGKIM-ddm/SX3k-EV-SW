#ifndef FDL_H
#define FDL_H

#include "Config.h"
#include "fdl_user.h"
#include "fdl_function.h"

void FDL_Init(void);
void FDL_Write(void);
void FDL_Read(void);
void Position_Temporary_write(void);
void Position_Temporary_read(void);

#endif /* FDL_H */


