/*****************************************************************************************
 *
 * [FILE NAME] : MCU2.c
 *
 * [AUTHOR(S)] : Ahmed Hassan
 *
 * [DATE CREATED]: January 25, 2022
 *
 * [DESCRIPTION]: This Project is to design a simple application to test I2C Driver
 *
 *****************************************************************************************/

#include "Application/App.h"

/*****************************************************************************************
 *                                MAIN FUNCTION                                          *
 *****************************************************************************************/

int main(void)
{
	/********************************************************************************
	 *                           SYSTEM INITIALIZATION                              *
	 ********************************************************************************/

	App_init();	/* Initialize the application */

	/********************************************************************************
	 *                        APPLICATION	(SUPER LOOP)						    *
	 ********************************************************************************/

	while(1)
	{
		App_Update();
	}	/* END OF SUPER LOOP */
}	/* END OF MAIN FUNCTION */
