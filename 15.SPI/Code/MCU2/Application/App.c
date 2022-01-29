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

uint8_t gu8_Byte;		/* Global variable to store the value of the sent byte */
uint8_t gStr_message[20];	/* Global string to be received through spi */

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
	LCD_init();		/* Initialize LCD Driver */
	SPI_initSlave();	/* Initialize Slave SPI */

	gu8_Byte = SPI_receiveByte();	/* Receive Character from Master MCU */
	LCD_displayCharacter(gu8_Byte);	/* Display the received string on the LCD display */

	SPI_receiveString(gStr_message);		/* Receive String from Master MCU */
	LCD_displayStringRowColumn(1, 0, gStr_message);	/* Display the received string on the LCD display */
}

