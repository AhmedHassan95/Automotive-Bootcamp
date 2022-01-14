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

uint8_t gu8_ButtonState;	/* global variable to store the button state */

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
	BUTTON_init(); 			/* BUTTON Driver Initialization */

	LED_init();				/* LED Driver Initialization */

	gu8_ButtonState = BUTTON_read();

	if(gu8_ButtonState == HIGH) /* Check if the button is pressed or not */
	{
		LED_turnOn();		 /* Turn on the LED */
	}
	else
	{
		LED_turnOff();		 /* Turn off the LED */
	}
}

/*******************************************************************************
 * [Function Name]: App_update
 *
 * [Description]: 	Function to update the application status
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
void App_update(void)
{
	gu8_ButtonState = BUTTON_read();

	if(gu8_ButtonState == HIGH) /* Check if the button is pressed or not */
	{
		LED_turnOn();		 /* Turn on the LED */
	}
	else
	{
		LED_turnOff();		 /* Turn off the LED */
	}
}
