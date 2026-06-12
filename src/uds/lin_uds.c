#define lin_uds_c

#include "r_cg_macrodriver.h"
#include "r_cg_userdefine.h"

#include "def_lin_uds.h"
#include "util.h"
#include "lin_uds.h"

extern const uint32_t ECU_SIGN[4];
extern const uint8_t ECU_VER[];

T_UDS_  uds;
char uds_1ms;
/** ================================================================================
 2ms
================================================================================= */  
void uds_state_check(void)
{
	uint16_t n;
	uint8_t c;

	if(uds.init==0) {
		OutStr("\n\rRH850 APPLICATION START\n\r");
		OutStr(ECU_VER);
    uds_Init();
		return;
	}

  if(uds_1ms==0) {
    return;
  }
  uds_1ms=0;

	if(uds.c_tog_1ms) {
		uds.c_tog_1ms=0;
		uds.c_timeout_p1_2ms++; 			
		if(uds.c_timeout_p1_2ms > 200u) {
		  //OutDev0('B');
			uds_Init();
		} 
		uds.c_10ms++; 			
		if(uds.c_10ms >= 5u) {
			uds.c_10ms=0;
			//OutDev0('A');
			if(uds.c_timeout_p2_10ms++ > TIMEOUT_P2_10MS) {
				uds_Init();
			}
		}
		return;
	}	
	uds.c_tog_1ms=1;
	if(is_session_program ) {
		if(uds.state==EST_RX) {
			delayNms(10); // waite finish tx	
			__DI();
			goto_reset(1);
		} else {
			;	
		}			
	}			
}

/** ================================================================================

================================================================================= */  
void uds_Init(void)
{
	uds.state=EST_RX;
	uds.c_timeout_p1_2ms=0u;				
	uds.c_timeout_p2_10ms=0u;				
	uds.init=1u;
}
/* =================================================================================
 
================================================================================= */  
void uds_tx_data_set(void)
{
	uint8_t i;
	for(i=0;i<10;i++) {
		uds.tx_data[i]=0;
	}	
	uds.tx_data[0]=ECU_FRAME_ID;
	uds.tx_data[1]=NAD_PHY;
	uds.tx_data[2]=2u;
	uds.tx_data[3]=uds.rsid;
}


/** ==============================================================

==============================================================	*/
void uds_frame_SID_DiagnosticSessionControl(void)
{
	uint8_t *p;
	uds.tx_data[4]=uds.packet_data[1];
	if(uds.packet_data[1]>NSESSION_EXTENDED_DIAGNOSTIC) {
		uds.tx_data[3]=UDS_NAK;
		uds.nrc=UDS_NRC_subFunctionNotSupported;
		uds.tx_data[5]=uds.nrc;
	} else {
		uds.session=uds.packet_data[1];
		if(is_session_program) {
			p=(void *)BOOT_VERSION_ADDRESS;
			if(p[0]!='B') {
				uds.tx_data[3]=UDS_NAK;
				uds.nrc=UDS_NRC_OUTOFRANGE; 		// no bootloader
				uds.tx_data[5]=uds.nrc;
				uds.session=0;
				OutStr("NO bootloader");put_cr();
			} else {
				OutStr("Found bootloader");put_cr();
			}
		} 
		//OutStr("Session:");put_char(uds.session);put_cr();
	}
	uds.state=EST_TX;
}
/** ==============================================================

==============================================================	*/
void uds_frame_SID_ReadDataByIdentifier(void)
{
	uint8_t *p;
	//OutStr("RD");put_cr();
	uds.did=uds.packet_data[1];
	uds.did<<=8;
	uds.did+=uds.packet_data[2];
	uds.tx_data[4]=uds.packet_data[1];
	uds.tx_data[5]=uds.packet_data[2];
	if(uds.did==VMECUSVNDID) {
		p=(void *)APP_VERSION_ADDRESS; 
		uds.tx_data[2]=6u;
		uds.tx_data[6]=p[6];
		uds.tx_data[7]=p[8];
		uds.tx_data[8]=p[10];
		
	} else {
		uds.tx_data[2]=4u;
		uds.tx_data[3]=UDS_NAK;
		uds.tx_data[6]=UDS_NRC_OUTOFRANGE;
	}
	uds.state=EST_TX;

}
/** ================================================================================
 sid .. data
================================================================================= */  
void uds_frame_parser(void)
{
	uint8_t *p;

	uds.c_timeout_p2_10ms=0u;				
	uds.sid=uds.packet_data[0];
	uds.rsid=uds.sid | 0x40u;
	uds_tx_data_set();
	OutStr("S:");put_char(uds.sid);put_cr();
	if(uds.sid==SID_DiagnosticSessionControl) {
		uds_frame_SID_DiagnosticSessionControl();
	} else if(uds.sid==SID_ReadDataByIdentifier) {  // response 
		uds_frame_SID_ReadDataByIdentifier();
	}	else {
		//avoid_empty_block();
	}
}



/* ==================================================================== 
 # 
====================================================================== */
void goto_reset(uint8_t mode)
{
	uint32_t n,i;
	uint8_t *p;
	// ================================ user motor stop


	// ================================ user motor stop
	__DI();
	OutStr("goto reset\n\r");
	n=200;
  while(n) n--;					// ============> interrupt flush
	p=(void *)SHARED_RAM_ADDRESS;
	
	p[0]='B';
	p[1]='o';
	p[2]='o';
	p[3]='t';
	p[4]='R';
	p[5]='e';
	p[6]='1';
	p[7]=1;	


	do{
		WPROTR.PROTCMD0 = 0x000000A5;   
		RESCTL.SWRESA = 0x00000001; 
		RESCTL.SWRESA = ~0x00000001;
		RESCTL.SWRESA = 0x00000001;
	}while(WPROTR.PROTS0 != 0x00000000);
	n=20000;
  while(n) n--;					// ============>  interrupt flush
	OutStr("reset fail\n\r");
}



