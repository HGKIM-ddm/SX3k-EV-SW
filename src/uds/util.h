#ifdef util_c

void delayNus(uint32_t n);
void delayNms(uint32_t n);
void delayN(uint32_t n);
void OutDev0(char d);
void OutStr(const char *text);
void put_flag(uint8_t a);	
void put_int(unsigned int a);				
void put_int_dec(uint16_t a);				
void put_cr(void);				
void put_char(unsigned char a);				
void put_char_dec(uint8_t a);				
void put_long(uint32_t w); 


#else 



extern void delayNus(uint32_t n);
extern void delayNms(uint32_t n);
extern void delayN(uint32_t n);

extern void OutDev0(char d);
extern void OutStr(const char *text);
extern void put_flag(uint8_t a);	
extern void put_int(unsigned int a);				
extern void put_int_dec(uint16_t a);				
extern void put_cr(void);				
extern void put_char(unsigned char a);				
extern void put_char_dec(uint8_t a);				
extern void put_long(uint32_t w); 


#endif 
