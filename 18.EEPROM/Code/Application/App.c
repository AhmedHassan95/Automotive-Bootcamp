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
#define ADDRESS_SIZE 7
uint8_t gStr8_message[10];	/* Global string to be sent and received through the uart */
uint8_t gStr8_address[10];	/* Global string to be store the value of the address */
uint8_t gu8_WriteData;		/* Global variable to store the value of written data on it */
uint8_t gu8_ReadData;		/* Global variable to store the value of read data on it */

/*******************************************************************************
 *                           Functions Definitions                             *
 *******************************************************************************/

/*******************************************************************************
 * [Function Name]: App_init
 *
 * [Description]: Function to Initialize the application to test eeprom driver
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

	EEPROM_init();	/* Initialize the external EEPROM */
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
	uint16_t au8_value = 0;	/* local variable to store the address as integer */

	UART_receiveString(gStr8_message);		/* Receive string from terminal */

	/* Check if the message is write or read */
	if(strcmp(gStr8_message, "WRITE") == IDENTICAL)
	{
		UART_receiveString(gStr8_address);	/* Receive address from terminal */
		/* Convert the value from binary to decimal */
		au8_value = strtol(gStr8_address, NULL_PTR, BASE_2);

		UART_sendString("OK\r");		/* Receive acknowledge from terminal */
		gu8_WriteData = UART_recieveByte();	/* Receive data from terminal */

		EEPROM_writeByte(au8_value, gu8_WriteData);/* Write data in the external EEPROM */
		UART_sendString("\rOK\r\r");
	}
	else if(strcmp(gStr8_message, "READ") == IDENTICAL)
	{
		UART_receiveString(gStr8_address);	/* Receive string from terminal */
		/* Convert the value from binary to decimal */
		au8_value = strtol(gStr8_address, NULL_PTR, BASE_2);

		UART_sendString("OK\r");			/* Receive acknowledge from terminal */
		EEPROM_readByte(au8_value, &gu8_ReadData);	/* Read data in the external EEPROM */

		UART_sendString("The data stored is ");
		UART_sendByte(gu8_ReadData);
		UART_sendString("\r\r");
	}
}
