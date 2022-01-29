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

uint8_t gStr_message[20];	/* Global string to be sent through the spi */

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
	UART_ConfigType uart_config = {BPS_9600, NORMAL_SPEED, EIGHT_BITS, DISABLED, ONE_BIT};
	UART_init(&uart_config);

	SPI_initMaster();	/* Initialize Master SPI */
	_delay_ms(100);		/* Delay until Slave MCU finish its initialization */
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
	 UART_receiveString(gStr_message);	/* Receive string from Terminal */

	 SPI_sendByte(M2_READY);		/* Check if Slave MCU is ready */

	 SPI_sendString(gStr_message);		/* Send string to Slave MCU */
}
