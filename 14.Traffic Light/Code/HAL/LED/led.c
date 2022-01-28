 /******************************************************************************
 *
 * [MODULE]: LED
 *
 * [FILE NAME]: led.c
 *
 * [DESCRIPTION]: Source file for the LED Driver
 *
 * [AUTHOR]: Ahmed Hassan
 *
 *******************************************************************************/

#include "led.h"

/*******************************************************************************
 *                           Functions Definitions                             *
 *******************************************************************************/

/*******************************************************************************
 * [Function Name]: LED_init
 *
 * [Description]: 	Function to Initialize the LED Driver
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
void LED_init(void)
{
	enuLED_Id_t enu_LedId;

	for(enu_LedId = LED_0; enu_LedId <= LED_NUM; enu_LedId++)
	{
		/* Configure LED pin as an output pin */
		DIO_setPinDirection(LED_PORT_NUM, enu_LedId , OUTPUT);
		/* Turn off LED at the beginning as the initial state */
		DIO_writePin(LED_PORT_NUM, enu_LedId, LOW);
	}
}

/*******************************************************************************
 * [Function Name]: LED_turnOn
 *
 * [Description]: 	Function to turn on the LED
 *
 * [Args]:			enu_LedId
 *
 * [in]			  	enu_LedId: Enumerator to LED ID
 *
 * [out]		  	None
 *
 * [in/out]		 	None
 *
 * [Returns]:       None
 *******************************************************************************/
void LED_turnOn(const enuLED_Id_t enu_LedId)
{
	DIO_writePin(LED_PORT_NUM, enu_LedId, HIGH);	/* Turn On LED */
}

/*******************************************************************************
 * [Function Name]: LED_turnOff
 *
 * [Description]: 	Function to turn off the LED
 *
 * [Args]:			enu_LedId
 *
 * [in]			  	enu_LedId: Enumerator to LED ID
 *
 * [out]		  	None
 *
 * [in/out]		 	None
 *
 * [Returns]:       None
 *******************************************************************************/
void LED_turnOff(const enuLED_Id_t enu_LedId)
{
	DIO_writePin(LED_PORT_NUM, enu_LedId, LOW);	/* Turn Off LED */
}

/*******************************************************************************
 * [Function Name]: LED_toggle
 *
 * [Description]: 	Function to toggle the LED
 *
 * [Args]:			enu_LedId
 *
 * [in]			  	enu_LedId: Enumerator to LED ID
 *
 * [out]		  	None
 *
 * [in/out]		 	None
 *
 * [Returns]:       None
 *******************************************************************************/
void LED_toggle(const enuLED_Id_t enu_LedId)
{
	DIO_TogglePin(LED_PORT_NUM, enu_LedId);	/* Toggle the LED */
}
