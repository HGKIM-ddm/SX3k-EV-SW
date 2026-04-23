
#ifndef FDL_FUNCTION_H
#define FDL_FUNCTION_H

char function_FDL_init(void);
char function_FDL_erease(uint32_t start_block,  uint16_t blcok_cnt);
char function_FDL_write(uint8_t* buff,uint32_t addr,  uint16_t size);
char function_FDL_read(uint32_t* buff, uint32_t addr, uint16_t size);

#endif

