 /******************************************************************************
 *
 * [MODULE]: APPLICATION
 *
 * [FILE NAME]: App.c
 *
 * [DESCRIPTION]: Source file for the Application
 *
 * [AUTHOR]: Ahmed Hassan
 *
 *******************************************************************************/

#include "App.h"

/*******************************************************************************
 *                              Global Variables                               *
 *******************************************************************************/

volatile static uint8_t gu8_tick = 0;
uint8_t gu8_applicationStatus = 0;

/*******************************************************************************
 *                           Functions Definitions                             *
 *******************************************************************************/

/*******************************************************************************
 * [Function Name]: App_init
 *
 * [Description]: 	Function to Initialize the application to test timer compare
 * 					match mode
 *
 * [Args]:			None
 *
 * [in]			  	None
 *
 * [out]		  	None
 *
 * [in/out]		 	None
 *
 * [Returns]:       None
 *******************************************************************************/
void App_init(void)
{
	LED_init();		/* LED Driver Initialization */

	/* Configure the timer1 in overflow mode */
	strTIMER_ConfigType_t timer_Config = {0, 782, TIMER_1, COMPARE};

	TIMER_init(&timer_Config);	/* Initialize the timer */

	/* State the timer */
	TIMER_start(TIMER_1, T1_F_CPU_1024);
}

/*******************************************************************************
 * [Function Name]: App_Update
 *
 * [Description]: 	Function to update the state of the application
 *
 * [Args]:			None
 *
 * [in]			  	None
 *
 * [out]		  	None
 *
 * [in/out]		 	None
 *
 * [Returns]:       None
 *******************************************************************************/
void App_Update(void)
{
	/* Read the status of the timer */
	TIMER_checkStatus(TIMER_1, COMPARE, &gu8_applicationStatus);

	if(gu8_applicationStatus == TRUE)
	{
		++gu8_tick;

		if(gu8_tick == TIMER_FOR_HIGH_PERIOD)
		{
			LED_toggle();	/* Pin Toggle to generate 37.5 % Duty Cycle */
		}
		else if(gu8_tick == TIMER_FOR_LOW_PERIOD)
		{
			LED_toggle();	/* Pin Toggle to generate 62.5 % Duty Cycle */
			gu8_tick = 0;	/* Clear Global ticks for the next time */
		}

		gu8_applicationStatus = FALSE;	/* Clear the flag for the next time */
	}
}

