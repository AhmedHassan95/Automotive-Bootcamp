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
 *                           Functions Definitions                             *
 *******************************************************************************/

/*******************************************************************************
 * [Function Name]: App_init
 *
 * [Description]: Function to Initialize the application to test spi Driver
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
	SPI_initMaster();	/* Initialize Master SPI */
	_delay_ms(50);		/* Delay until Slave MCU finish its initialization */
	SPI_sendByte('A');	/* Send Byte to Slave MCU */
	_delay_ms(50);		/* Delay until Slave MCU finish processing the data */
	SPI_sendString("Ahmed Hassan\r");	/* Send String to Slave MCU */
}
