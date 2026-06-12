
#define util_c
#include "r_cg_macrodriver.h"
#include "r_cg_userdefine.h"
#include "r_cg_port.h"

#include "def_lin_uds.h"
#include "util.h"
#include "lin_uds.h"


/** ================================= 
 =================================	*/
void avoid_empty_block(void)
{
}

/** =================================

=================================  */
void delayNus(uint32_t n)
{
	uint32_t i;

	for(i=0;i<n;i++) {
		avoid_empty_block();

	}

}
void delayNms(uint32_t n)
{
	uint32_t i;
	for(i=0;i<n;i++)	{
		delayNus(7465);	
	}
}

void delayN(uint32_t n)  
{
    while(n) n--;
}


/* ===========================================================================================

=========================================================================================== */  
static void P_SCL_Write(uint8_t value)
{
	if(value==0)	PORT.P10 &= ~_PORT_Pn0_OUTPUT_HIGH;	// MCU_DRVOFF
	else PORT.P10 |= _PORT_Pn0_OUTPUT_HIGH;	// MCU_DRVOFF

}

static void P_SDA_Write(uint8_t value)
{
	if(value==0)	PORT.P10 &= ~_PORT_Pn2_OUTPUT_HIGH;
	else PORT.P10 |= _PORT_Pn2_OUTPUT_HIGH;
}



unsigned char D2C(unsigned char c)
{
	if(c<10) return (c+'0');
	return (c+'7');
}

/* ===========================================================================================

=========================================================================================== */  
#define SDELAY 30
void OutDev0(char d)
{
	uint8_t c,i;
	#ifdef USE_UART_DEBUG
	c=0x80U;
	for(i=0U;i<8U;i++) {	
		if((d&c)==0U) {
			P_SDA_Write(0);
		} else {
			P_SDA_Write(1);
		}
		delayN(SDELAY);
		P_SCL_Write(1);
		delayN(SDELAY);
		P_SCL_Write(0);
		c>>=1U; 
		delayN(SDELAY);
	}
	delayN(SDELAY*2U); 
	#endif
}

/* ===========================================================================================

=========================================================================================== */  
void OutStr(const char *text)
{
  while (*text != '\0'){
		OutDev0(*text++) ;
  }
}

/** ==========================================================================

========================================================================== */
void put_flag(uint8_t a)				
{							
	if(a) OutDev0('1');	
	else OutDev0('0');	
	OutDev0(',');	
}

void put_int(unsigned int a)				
{							
	unsigned char i;
	i=a>>12;OutDev0(D2C(i));	
	i=a>>8; i&=0x0F;	OutDev0(D2C(i));	
	i=a>>4; i&=0x0F;	OutDev0(D2C(i));	
	i=a&0x0F;	OutDev0(D2C(i));	
	OutDev0(',');	
}
/** ==========================================================================

========================================================================== */
void put_int_dec(uint16_t a)				
{							
	unsigned char c[5],z=0;
	uint16_t k,p;

	k=a;

	p=k/10000;
	if(p)	{
		c[4]=p+'0';
		z++;
	}	else { c[4]=' '; }
	k=k%10000;	


	p=k/1000;
	if(!p && !z)	{
		c[3]=' '; 
	} else {
		c[3]=p+'0';
		z++;
	}	
	k=k%1000;	

	p=k/100;
	if(!p && !z)	{
		c[2]=' '; 
	} else {
		c[2]=p+'0';
		z++;
	}	
	k=k%100;	

	p=k/10;
	if(!p && !z)	{
		c[1]=' '; 
	} else {
		c[1]=p+'0';
		z++;
	}	
	k=k%10;	
	c[0]=k+'0';


	OutDev0(c[4]);	
	OutDev0(c[3]);	
	OutDev0(c[2]);	
	OutDev0(c[1]);	
	OutDev0(c[0]);	
	OutDev0(',');	
}

void put_cr(void)				
{							
	OutDev0('\r');	
	OutDev0('\n');	
}

void put_char(unsigned char a)				
{							
	unsigned char i;
	i=a>>4; i&=0x0F;	OutDev0(D2C(i));	
	i=a&0x0F;	OutDev0(D2C(i));	
	OutDev0(',');	
}
/** ==========================================================================

========================================================================== */
void put_char_dec(uint8_t a)				
{							
	unsigned char c[5],z=0;
	uint16_t k,p;

	k=a;

	p=k/100;
	if(!p && !z)	{
		c[2]=' '; 
	} else {
		c[2]=p+'0';
		z++;
	}	
	k=k%100;	

	p=k/10;
	if(!p && !z)	{
		c[1]=' '; 
	} else {
		c[1]=p+'0';
		z++;
	}	
	k=k%10;	
	c[0]=k+'0';

	OutDev0(c[2]);	
	OutDev0(c[1]);	
	OutDev0(c[0]);	
	OutDev0(',');	
}

void put_long(uint32_t w) 
{
	unsigned char c;
	c=w>>28;c&=0x0F;OutDev0(D2C(c));
	c=w>>24;c&=0x0F;OutDev0(D2C(c));
	c=w>>20;c&=0x0F;OutDev0(D2C(c));
	c=w>>16;c&=0x0F;OutDev0(D2C(c));
	c=w>>12;c&=0x0F;OutDev0(D2C(c));
	c=w>>8;c&=0x0F;OutDev0(D2C(c));
	c=w>>4;c&=0x0F;OutDev0(D2C(c));
	c=w;c&=0x0F;OutDev0(D2C(c));
	OutDev0(',');

}

