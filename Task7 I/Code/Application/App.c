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

/*******************************************************************************
 *                             Interrupt Service Routines                      *
 *******************************************************************************/

void AppCompareMatch(void)
{
	++gu8_tick;

	if(gu8_tick == TIMER_FOR_HIGH_PERIOD)
	{
		LED_toggle();	/* Pin Toggle to generate 37.5 % Duty Cycle */
	}
	else if(gu8_tick == TIMER_FOR_LOW_PERIOD)
	{
		LED_toggle();	/* Pin Toggle to generate 62.5 % Duty Cycle */
		gu8_tick = 0;		/* Clear Global ticks for the next time */
	}
}

/*******************************************************************************
 *                           Functions Definitions                             *
 *******************************************************************************/

/*******************************************************************************
 * [Function Name]: App_init
 *
 * [Description]: 	Function to Initialize the application to test timer
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
	SREG_R |= (1<<7);	/* Enable Global Interrupt (I - bit) */

	LED_init();		/* LED Driver Initialization */

	/* Configure the timer1 in overflow mode */
	strTIMER_ConfigType_t timer_Config = {0, 781, TIMER_1, COMPARE};

	TIMER_init(&timer_Config);	/* Initialize the timer */

	/* Set the function to be called when interrupt is fired */
	TIMER_setCallBack(AppCompareMatch, TIMER_1);

	/* State the timer */
	TIMER_start(TIMER_1, T1_F_CPU_1024);
}
