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

uint8_t gStr_message[20];	/* Global string to be received through the spi */

/*******************************************************************************
 *                           Functions Definitions                             *
 *******************************************************************************/

/*******************************************************************************
 * [Function Name]: App_init
 *
 * [Description]: 	Function to Initialize the application
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
	UART_ConfigType uart_config = {BPS_9600, NORMAL_SPEED, EIGHT_BITS, DISABLED, ONE_BIT};
	UART_init(&uart_config);

	SPI_initSlave();	/* Initialize Slave SPI */
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
	while(SPI_receiveByte() != M2_READY){}

	SPI_receiveString(gStr_message);	/* Receive string from Master MCU */

	UART_sendString(gStr_message);		/* Send string to the terminal */

	UART_sendByte('\r');				/* Send new line to the terminal */
}
