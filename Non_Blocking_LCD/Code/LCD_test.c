/*****************************************************************************************
 *
 * [FILE NAME] : LCD_test.c
 *
 * [AUTHOR(S)] : Ahmed Hassan
 *
 * [DATE CREATED]: February 7, 2022
 *
 * [DESCRIPTION]: This Project is to design a simple test application for LCD non blocking driver
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

	App_init();	/* Test LCD in simple application */

	/********************************************************************************
	 *                        APPLICATION	(SUPER LOOP)						    *
	 ********************************************************************************/

	while(1)
	{
		App_Update();
	}	/* END OF SUPER LOOP */
}	/* END OF MAIN FUNCTION */
