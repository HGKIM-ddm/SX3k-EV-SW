#ifdef lin_uds_c
void uds_Init(void);
void goto_reset(uint8_t mode);

#else

extern void uds_state_check(void);
extern void uds_frame_parser(void);
extern void goto_reset(uint8_t mode);
extern T_UDS_  uds;
extern char uds_1ms;
#endif
