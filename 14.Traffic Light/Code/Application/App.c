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

uint8_t gStr_message[20];	/* Global string to be sent through uart */

/*******************************************************************************
 *                           Functions Definitions                             *
 *******************************************************************************/

/*******************************************************************************
 * [Function Name]: App_init
 *
 * [Description]: Function to Initialize the application
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
void App_init(void)
{
	LED_init();	/* Initialize LED Driver */
	UART_ConfigType uart_config = {BPS_9600, NORMAL_SPEED, EIGHT_BITS, DISABLED, ONE_BIT};
	UART_init(&uart_config);
}

/*******************************************************************************
 * [Function Name]: App_Update
 *
 * [Description]: Function to update the state of the application
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
void App_Update(void)
{
	UART_receiveString(gStr_message); /* Receive String from Terminal */

	if(strcmp(gStr_message, "START") == IDENTICAL)
	{
		LED_turnOn(LED_GREEN);
		LED_turnOff(LED_YELLOW);
		LED_turnOff(LED_RED);
		UART_sendString("Green LED is on\r");
	}
	else if(strcmp(gStr_message, "WAIT") == IDENTICAL)
	{
		LED_turnOn(LED_YELLOW);
		LED_turnOff(LED_GREEN);
		LED_turnOff(LED_RED);
		UART_sendString("Yellow LED is on\r");
	}
	else if(strcmp(gStr_message, "STOP") == IDENTICAL)
	{
		LED_turnOn(LED_RED);
		LED_turnOff(LED_YELLOW);
		LED_turnOff(LED_GREEN);
		UART_sendString("Red LED is on\r");
	}
	else if(strcmp(gStr_message, "AT") == IDENTICAL)
	{
		UART_sendString("OK\r");
	}
	else
	{
		/* No thing to do */
	}
}
