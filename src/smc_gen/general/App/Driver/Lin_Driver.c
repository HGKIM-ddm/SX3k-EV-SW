#include "Lin_Driver.h"

//Static
/***********************************************************************************************************************
 * Function Name: Lin_ClearDataBuffer
 * Description  : This function setting all data buffer to some value
 * Arguments    : uint8_t x : setting data buff value
 * Return Value : None
 ***********************************************************************************************************************/
static void Lin_ClearDataBuffer(void)
{
	uint8_t i;
	// uint32_t Databuf_adr;
	uint8_t *Databuf_adr;

	// Databuf_adr = &RLN30.LDBR1;
	Databuf_adr = (uint8_t *)&RLN30.LDBR1;
	for (i = 0U; i < 8U; i++)
	{
		*((uint8_t *)(Databuf_adr + i)) = 0U;
	}
}

//Nomal
/***********************************************************************************************************************
 * Function Name: Lin_SlaveInit(void)
 * Description  : This function initializes the RLIN Slave node, setting clock supply,baud rate,ect.
 * Arguments    : None
 * Return Value : None
 ***********************************************************************************************************************/
void Lin_SlaveInit(void)
{
	R_PORT_SetAltFunc(Port10, 10, Alt2, Output);
	R_PORT_SetAltFunc(Port10, 9, Alt2, Input);

	do
	{
		/*LIN control register*/
		RLN30.LCUC = 0x00U; // LIN reset mode
	} while (RLN30.LMST != 0u); // LIN mode status register

	// Sets a baud rate
	RLN30.LWBR = 0x34U; // 4sampling_1/4 Prescaler
	// RLN30.LWBR = 0x00; //jdy_test
	RLN30.LBRP01.UINT16 = 0x0081U; /*  0X81=129D, Baud rate= 40M / 4 / (129+1) / 4 = 19230 bps*/
	// Sets noise filter ON/OFF
	RLN30.LMD = 0x12U; // The noise filter is enabled; transmission interrupt, reception interrupt, status interrupt are used ;LIN Slave mode (auto baud rate)
					  // Enables interrupt

#if 0 // for RLN30.LMD LIOS bit set 0
	  // RLIN30 interrupt
	INTC2.ICRLIN30.BIT.MKRLIN30 = _INT_PROCESSING_DISABLED;
	INTC2.ICRLIN30.BIT.RFRLIN30 = _INT_REQUEST_NOT_OCCUR;
	INTC2.ICRLIN30.BIT.TBRLIN30 = _INT_TABLE_VECTOR;
	INTC2.ICRLIN30.UINT16 &= _INT_PRIORITY_LOWEST;
#else // for RLN30.LMD LIOS bit set 1
	  // RLIN30 transmit interrupt
	INTC2.ICRLIN30UR0.BIT.MKRLIN30UR0 = _INT_PROCESSING_DISABLED;
	INTC2.ICRLIN30UR0.BIT.RFRLIN30UR0 = _INT_REQUEST_NOT_OCCUR;
	INTC2.ICRLIN30UR0.BIT.TBRLIN30UR0 = _INT_TABLE_VECTOR;
	INTC2.ICRLIN30UR0.UINT16 &= _INT_PRIORITY_LOWEST;

	// RLIN30 receive complete interrupt
	INTC2.ICRLIN30UR1.BIT.MKRLIN30UR1 = _INT_PROCESSING_DISABLED;
	INTC2.ICRLIN30UR1.BIT.RFRLIN30UR1 = _INT_REQUEST_NOT_OCCUR;
	INTC2.ICRLIN30UR1.BIT.TBRLIN30UR1 = _INT_TABLE_VECTOR;
	INTC2.ICRLIN30UR1.UINT16 &= _INT_PRIORITY_LOWEST;

	// RLIN30 status interrupt
	INTC2.ICRLIN30UR2.BIT.MKRLIN30UR2 = _INT_PROCESSING_DISABLED;
	INTC2.ICRLIN30UR2.BIT.RFRLIN30UR2 = _INT_REQUEST_NOT_OCCUR;
	INTC2.ICRLIN30UR2.BIT.TBRLIN30UR2 = _INT_TABLE_VECTOR;
	INTC2.ICRLIN30UR2.UINT16 &= _INT_PRIORITY_LOWEST;

	RLN30.LIE = 0x0fU; // enable all interrupt
	// Enables error detection
	RLN30.LEDE = 0xddU; // enable all error

	// Sets frame configuration parameters
	RLN30.LBFC = 0x00U; // Reception break of 9.5/10 or more Tbits
	RLN30.LSC = 0x11U;  // inter-byte space 1bit;Response space 1bit
	RLN30.LWUP = 0x30U; // Wake-up Transmission Low level Width Select 4 Tbits
	RLN30.LIDB = 0x00U; // Clear the ID buffer
#endif

	// Transitions to the LIN slave mode: LIN operation mode
	do
	{
		RLN30.LCUC = 0x03u; // LIN Opeation mode, Exit LIN reset mode.
	} while (RLN30.LMST != 0x03u);

	// Sets the FTS bit in the RLN3nLTRC register to 1 (header reception or wake-up transmission/reception started)
	RLN30.LTRC = 0x01U;

	// Interrupt processing enable
	INTC2.ICRLIN30UR0.BIT.RFRLIN30UR0 = _INT_REQUEST_NOT_OCCUR;
	INTC2.ICRLIN30UR0.BIT.MKRLIN30UR0 = _INT_PROCESSING_ENABLED;
	INTC2.ICRLIN30UR1.BIT.RFRLIN30UR1 = _INT_REQUEST_NOT_OCCUR;
	INTC2.ICRLIN30UR1.BIT.MKRLIN30UR1 = _INT_PROCESSING_ENABLED;
	INTC2.ICRLIN30UR2.BIT.RFRLIN30UR2 = _INT_REQUEST_NOT_OCCUR;
	INTC2.ICRLIN30UR2.BIT.MKRLIN30UR2 = _INT_PROCESSING_ENABLED;
}

/***********************************************************************************************************************
 * Function Name: Lin_SlaveReceive(void)
 * Description  : This function clear data buffer for response reception start
 * Arguments    : uint8_t Data_length : receive data length.
 * Return Value : None
 ***********************************************************************************************************************/
void Lin_SlaveReceive(uint8_t Data_length)
{
	Lin_ClearDataBuffer();
	// RLN30.LDFC = 0x20;		   /*b5=1:enhanced checksum mode; b4=0:Reception*/
	if (GetIDbuffer == 0x3CU) // 0x3C / 0x3D
	{
		RLN30.LDFC = 0x00U; // b5=0 → Classic checksum
	}
	else
	{
		RLN30.LDFC = 0x20U; // b5=1 → Enhanced checksum
	}
	RLN30.LDFC |= Data_length; /* b4-b0=Data_length: response data lengh select byte*/
	RLN30.LTRC = 0x02U;		   /*setting RTS=1,response reception is started*/
}

/***********************************************************************************************************************
* Function Name: Lin_SlaveTransmit(void)
* Description  : This function seting data buffer for response transmission start
* Arguments    : uint8_t* databuf    : variable array data.
				 uint8_t Data_length : transmit data length.
* Return Value : None
***********************************************************************************************************************/
void Lin_SlaveTransmit(uint8_t *databuf, uint8_t Data_length)
{
	uint8_t i;
	// uint32_t  Databuf_adr;
	uint8_t *Databuf_adr;

	// RLN30.LDFC = 0x30;		   /*b5=1:enhanced checksum mode; b4=1:transmission*/
	if ((GetIDbuffer == 0x7DU)) // 0x3C / 0x3D
	{
		RLN30.LDFC = 0x10U; // b5=0 → Classic checksum
	}
	else
	{
		RLN30.LDFC = 0x30U; // b5=1 → Enhanced checksum
	}
	RLN30.LDFC |= Data_length; /* b4-b0=Data_length: response data lengh select byte*/
	// Databuf_adr = &RLN30.LDBR1;    /* get the data buffer address*/
	Databuf_adr = (uint8_t *)&RLN30.LDBR1; /* get the data buffer address*/

	for (i = 0; i < Data_length; i++) /* setting tansmission data to date buffer*/
	{
		*((uint8_t *)(Databuf_adr + i)) = databuf[i];
	}

	RLN30.LTRC = 0x02U; /*setting RTS=1;Response transmission start*/
}

/***********************************************************************************************************************
 * Function Name: Lin_SlaveNoResponse(void)
 * Description  : This function perform no-response for the reception ID
 * Arguments    : uint8_t Data_length : receive data length.
 * Return Value : None
 ***********************************************************************************************************************/
void Lin_SlaveNoResponse(void)
{
	RLN30.LTRC = 0x04U; /* setting LNRR=1, No response request*/
}



/***********************************************************************************************************************
 * Function Name: Lin_GetReponseRxData
 * Description  : This function get data buffer value to a variable array
 * Arguments    : uint8_t * RxData : a avriable array for store Data
 * Return Value : None
 ***********************************************************************************************************************/
void Lin_GetReponseRxData(uint8_t *RxData)
{
	uint8_t i, k;
	// uint32_t Databuf_adr;
	uint8_t *Databuf_adr;

	k = RLN30.LDFC & 0x0FU;
	// Databuf_adr = &RLN30.LDBR1;
	Databuf_adr = (uint8_t *)&RLN30.LDBR1;
	for (i = 0; i < k; i++)
	{
		RxData[i] = (*((uint8_t *)(Databuf_adr + i)));
	}
}

