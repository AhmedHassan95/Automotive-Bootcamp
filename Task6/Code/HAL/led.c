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
 * [Description]: Function to Initialize the LED Driver
 *
 * [Args]:	  None
 *
 * [in]		  None
 *
 * [out]	  None
 *
 * [in/out]	  None
 *
 * [Returns]:     None
 *******************************************************************************/
void LED_init(void)
{
	/* Configure LED pin as an output pin */
	DIO_setPinDirection(LED_PORT_NUM, LED_PIN_NUM, OUTPUT);
	/* Turn off LED at the beginning as the initial state */
	DIO_writePin(LED_PORT_NUM, LED_PIN_NUM, LOW);
}

/*******************************************************************************
 * [Function Name]: LED_turnOn
 *
 * [Description]: Function to turn on the LED
 *
 * [Args]:	  None
 *
 * [in]		  None
 *
 * [out]	  None
 *
 * [in/out]	  None
 *
 * [Returns]:     None
 *******************************************************************************/
void LED_turnOn(void)
{
	DIO_writePin(LED_PORT_NUM, LED_PIN_NUM, HIGH);	/* Turn On LED */
}

/*******************************************************************************
 * [Function Name]: LED_turnOff
 *
 * [Description]: Function to turn off the LED
 *
 * [Args]:	  None
 *
 * [in]		  None
 *
 * [out]	  None
 *
 * [in/out]	  None
 *
 * [Returns]:     None
 *******************************************************************************/
void LED_turnOff(void)
{
	DIO_writePin(LED_PORT_NUM, LED_PIN_NUM, LOW);	/* Turn Off LED */
}
