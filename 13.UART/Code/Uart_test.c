/*****************************************************************************************
 *
 * [FILE NAME] : Uart_test.c
 *
 * [AUTHOR(S)] : Ahmed Hassan
 *
 * [DATE CREATED]: January 18, 2022
 *
 * [DESCRIPTION]: This Project is to design a simple test application for UART driver
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

	App_init();	/* Test UART in simple application */

	/********************************************************************************
	 *                        APPLICATION	(SUPER LOOP)				*
	 ********************************************************************************/

	while(1)
	{
		App_Update();
	}	/* END OF SUPER LOOP */
}	/* END OF MAIN FUNCTION */
