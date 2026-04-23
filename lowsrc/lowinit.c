/*===============================================================================================

    Copyright (c) 2013 by Renesas Electronics Europe GmbH, a company of the Renesas Electronics 
    Corporation. All rights reserved.

  ===============================================================================================

    Warranty Disclaimer                                                       
                                                                             
    Because the Product(s) is licensed free of charge, there is no warranty of any kind
    whatsoever and expressly disclaimed and excluded by Renesas, either expressed or implied, 
    including but not limited to those for non-infringement of intellectual property, 
    merchantability and/or fitness for the particular purpose.
    Renesas shall not have any obligation to maintain, service or provide bug fixes for the
    supplied Product(s) and/or the Application.

    Each User is solely responsible for determining the appropriateness of using the Product(s)
    and assumes all risks associated with its exercise of rights under this Agreement, including,
    but not limited to the risks and costs of program errors, compliance with applicable laws,
    damage to or loss of data, programs or equipment, and unavailability or interruption of
    operations.

    Limitation of Liability

    In no event shall Renesas be liable to the User for any incidental, consequential, indirect,
    or punitive damage (including but not limited to lost profits) regardless of whether such
    liability is based on breach of contract, tort, strict liability, breach of warranties, 
    failure of essential purpose or otherwise and even if advised of the possibility of such
    damages. Renesas shall not be liable for any services or products provided by third party
    vendors, developers or consultants identified or referred to the User by Renesas in 
    connection with the Product(s) and/or the Application.

  ===============================================================================================*/



//============================================================================
// Includes                                                                  
//============================================================================
#include <device.h>

//Add_RetentionRAM_init
#include "..\src\smc_gen\general\r_cg_macrodriver.h" 
#include "..\src\smc_gen\general\r_cg_userdefine.h"
//============================================================================
// Defines                                                     
//============================================================================


#define TRUE  1
#define FALSE 0

//============================================================================
// Prototypes                                                             
//============================================================================

//============================================================================
// Constants                                                             
//============================================================================

//============================================================================
// Init Functions                                                             
//============================================================================


/*
 * Very early clock tree initialization, directly after 
 * _RESET executed.
 */

//Add_RetentionRAM_init
#if 0
void __lowinit(void)
{
#ifdef HAS_CLKINIT
    CLKINIT();
#endif  /* HAS_CLKINIT */
}
#else
extern unsigned int __ghs_rramstart;
extern unsigned int __ghs_rramend;
/*****************************************************************************
** Function:    R_SYSTEM_ClearRetentionRAM
** Description: Clears Retention RAM area (GHS version)
** Parameter:   None
** Return:      None
******************************************************************************/
void R_SYSTEM_ClearRetentionRAM(void)
{  
   uint32_t* loc_ptr;
  
  loc_ptr = (uint32_t*)&__ghs_rramstart;
  while(((uint32_t*)&__ghs_rramend ) > loc_ptr)
  {
    *loc_ptr=0x00000000;
    loc_ptr++;
  }
   
}
/*****************************************************************************
** Function:    __low_level_init
** Description: called during start-up (GHS version)
** Parameter:   None
** Return:      None
******************************************************************************/
void __lowinit(void)
{
	#ifdef HAS_CLKINIT
    CLKINIT();
	#endif  /* HAS_CLKINIT */

	/* check if power-up reset has occured */
   if(STBC_WUF0.WUF0 == 0)	//R_WUF_RESET --> POR Reset
   {
     /*clear noinit area of retention RAM */
     R_SYSTEM_ClearRetentionRAM();
   }
}
#endif





