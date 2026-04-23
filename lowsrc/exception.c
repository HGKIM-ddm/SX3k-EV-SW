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


#include <device.h> 

volatile u32_T OSTM0Tick1ms;
volatile u32_T OSTM1Tick100us;


#define FCL160	(160)
#define FCL80	(80)
#define FCL48	(48)
#define FCL40	(40)
#ifndef FCL
#define FCL		(FCL80)
#endif // FCL

#define PLL1160	(160)
#define PLL180	(80)
#define PLL140	(40)

/* #define PLL1	(FCL80) */
#define PLL1	(FCL40)

#pragma ghs interrupt(nonreentrant)
void INTOSTM0(void)
{
	OSTM0Tick1ms++;
}

#pragma ghs interrupt(nonreentrant)
void INTOSTM1(void)
{
	OSTM1Tick100us++;
}

