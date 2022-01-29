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

uint8_t gStr_message[20];	/* Global variable to store the uart value */

/*******************************************************************************
 *                           Functions Definitions                             *
 *******************************************************************************/

/*******************************************************************************
 * [Function Name]: App_init
 *
 * [Description]: Function to Initialize the application to test uart Driver
 *
 * [Args]:	None
 *
 * [in]		None
 *
 * [out]	None
 *
 * [in/out]	None
 *
 * [Returns]:   None
 *******************************************************************************/
void App_init(void)
{
	UART_ConfigType uart_config = {BPS_9600, NORMAL_SPEED, EIGHT_BITS, DISABLED, ONE_BIT};
	UART_init(&uart_config);
}

/*******************************************************************************
 * [Function Name]: App_Update
 *
 * [Description]: Function to update the state of the application
 *
 * [Args]	None
 *
 * [in]		None
 *
 * [out]	None
 *
 * [in/out]	None
 *
 * [Returns]:   None
 *******************************************************************************/
void App_Update(void)
{
	UART_receiveString(gStr_message);/* Receive String from terminal */
    	UART_sendString(gStr_message);	 /* Resends the string to terminal */
    	UART_sendByte('\r');		 /* Send the new line to the terminal */
}
