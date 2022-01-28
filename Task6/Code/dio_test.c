/*****************************************************************************************
 *
 * [FILE NAME] : test_Dio.c
 *
 * [AUTHOR(S)] : Ahmed Hassan
 *
 * [DATE CREATED]: January 1, 2022
 *
 * [DESCRIPTION]: This Project is to design a simple test application for DIO driver
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

	App_init();

	/********************************************************************************
	 *                        APPLICATION	(SUPER LOOP)						    *
	 ********************************************************************************/

	while(1)
	{
		App_update();

	}	/* END OF SUPER LOOP */
}	/* END OF MAIN FUNCTION */
