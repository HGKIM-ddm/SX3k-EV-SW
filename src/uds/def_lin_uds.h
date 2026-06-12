#ifndef DEF_LIN_UDS
#define DEF_LIN_UDS  


//#define USE_TEST_DISABLE_SLEEP
//#define 

#define 	FDATA_256_ALINE		// FLASH WRITE DATA 256 ALINE RH850 ONLY

#define 	MAX_UDS_BLOCK_SIZE		0x40u			// 64
#define 	NAD_FUCTION				0x7Eu
#define 	NAD_PHY							0x10u

#define 	TESTER_FRAME_ID		0x3Cu
#define 	ECU_FRAME_ID				0x7Du			// 7D=3D+PARITY
#define 	LIN_SYNCF					0x55u			
#define 	DEFULT_LIN_BAUD		0u			// 0 = 19200u
#define 	MAX_LIN_BAUD		3u			

#define 	TIMEOUT_P2_10MS					2000u		// Time between reception of the last frame of a diagnostic request on the LIN bus and the slave node being able to provide data for a response.
#define 	V_c_timeout_p1_2ms		25U			

enum {
	EST_RX=0,
	EST_TX,	
	EST_TX_WAIT_ACTION,	
	EST_END
};	

#define 	VMECUSVNDID						0xF389u			// VehicleManufacturerECUSoftwareVersionNumberDataIdentifier 권장.

#define MAX_UDS_DATA_BUF		12U
#define APP_SIGN			0x55AA1234ul
#define MAX_UDS_DATA_BUF_LIN	12U

#define FlashPageSize 		          (128U)

#define FLASH_PAGE_SIZE_S						0x2000ul	
#define FLASH_PAGE_SIZE							0x8000ul	
#define ADDRESS_OFFSET							0

#define PROGRAM_FLASH_END_ADRESS 		0x07FFFFul
#define APP_FLASH_BASE_ADDRESS 			0x00E000ul

#define APP_FLASH_END_ADDRESS 		  PROGRAM_FLASH_END_ADRESS
#define APP_FLASH_SIZE							((APP_FLASH_END_ADDRESS-APP_FLASH_BASE_ADDRESS)+1)

#define	APP_VERSION_ADDRESS		(0xF010)
#define	BOOT_VERSION_ADDRESS 	(0x4F00)

#define APP_ENTRY_ADDRESS				APP_FLASH_BASE_ADDRESS
#define APP_END_ADDR						PROGRAM_FLASH_END_ADRESS

#define APP_SIGN_ADDRESS			(0xE100)
#define APP_RESET_VECTOR			(APP_FLASH_BASE_ADDRESS)

#define SHARED_RAM_ADDRESS	0xFEDF0000u

typedef void(* APPFn)(void);

#define CONSECUTIVE_FLOW_CONTROL_COUNT		0U
#define UDS_DID_VERSION										0XF187u			// 
#define UDS_SID_VERSION										0XF500u			// 
#define UDS_Download_block_length					0x42u;


typedef struct _T_UDS {	
	uint16_t	ndata;			
	uint8_t		packet_data[MAX_UDS_DATA_BUF_LIN];			// packet_data[2] 부터 32bit aline 절대자리옮기지말것.
	uint16_t	packet_data_len;

	uint8_t	c_tog_1ms;				
	uint8_t	c_timeout_p1_2ms;				
	uint16_t	c_timeout_session_10ms;

	uint8_t	c_10ms;				
	uint16_t	c_timeout_p2_10ms;				
	uint8_t	state;	
	uint8_t	tx_data[MAX_UDS_DATA_BUF_LIN],tx_data_len;
	uint8_t	rx_data[MAX_UDS_DATA_BUF_LIN];
	

	uint16_t	did;				
	uint8_t	sid,rsid;		//

	uint8_t	nrc;		//
	uint8_t	session;
	uint8_t	request_reset;
	uint8_t	request_response;
	uint8_t	response_to_negetive	;
	uint8_t	init;

}T_UDS_;
//============================ STRUCT
#define SID_DiagnosticSessionControl 					0x10   
#define SID_ECUReset 														0x11                   
#define SID_SecurityAccess 											0x27    
#define SID_CommunicationControl 							0x28       
#define SID_EnableNormalMessageTransmission 	0x29 
#define SID_TesterPresent 											0x3E              
#define SID_ControlDTCSetting 									0x85          
#define SID_ReadDataByIdentifier 							0x22       
#define SID_ReadScalingDataByIdentifier 			0x24 
#define SID_WriteDataByIdentifier 							0x2E 
#define SID_ReadDTCInformation 								0x19         
#define SID_ClearDiagnosticInformation 				0x14 	
#define SID_RoutineControl 											0x31    
#define SID_RequestDownload 										0x34            
#define SID_TransferData 												0x36               
#define SID_RequestTransferExit 								0x37        
   
#define SID_ReadMemoryByAddress								0x23u		
#define SID_WriteMemoryByAddress								0x3Du		
#define SID_InputOutputControlByIdentifier		0x2Fu
#define SID_DynamicallyDefineDataIdentifie		0x2Cu
#define SID_ReadDataByPeriodicIdentifier			0x2au

#define SID_Other 																0xff; 

// ========================== ERROR
#define UDS_NAK																	0x7Fu
#define UDS_NRC_serviceNotSupport						0x11u		// 
#define UDS_NRC_subFunctionNotSupported					0x12u		// subFunctionNotSupported
#define UDS_NRC_LEN													0x13u		// incorrectMessageLength
#define UDS_NRC_conditionNotCorrect					0x22u		// 
#define UDS_NRC_OUTOFRANGE										0x31u		// 
#define UDS_NRC_securityAccessDenied					0x33u		// securityAccessDenied
#define UDS_NRC_requestSequenceError					0x24u		// 
#define UDS_NRC_invalidKey										0x35u		// 
#define UDS_NRC_subFunctionNotSupportedInActiveSession		0x7eu		// 
#define UDS_NRC_serviceNotSupportedInActiveSession		0x7Fu		// 
#define UDS_NRC_transferDataSuspended                       0x71U
#define UDS_NRC_generalProgrammingFailure                   0x72U
#define UDS_NRC_wrongBlockSequenceCounter                   0x73U
#define UDS_NRC_requestCorrectlyReceived_ResponsePending    0x78U
#define UDS_NRC_conditionsNotCorrect                        0x22U
#define UDS_NRC_busyRepeatReques                            0x21U
#define UDS_NRC_generalReject                               0x10U

#define is_noresponse(n) (n&0x80)

#define is_response_supressed ((uds.rx.buf[2]&0x80)==0x80)

#define NSESSION_DEFAULT		1u
#define NSESSION_PROGRAMMING		2u
#define NSESSION_EXTENDED_DIAGNOSTIC		3u

#define V_TIMEOUT_SESSION_10MS 500u

#define is_session_default (uds.session<=NSESSION_DEFAULT)
#define is_session_extended_diagnostic (uds.session==NSESSION_EXTENDED_DIAGNOSTIC)
#define is_session_program (uds.session==NSESSION_PROGRAMMING)


#endif
