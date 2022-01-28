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
 * [Description]: 	Function to Initialize the application to test eeprom driver
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

	EEPROM_init();	/* Initialize the external EEPROM */
}

/*******************************************************************************
 * [Function Name]: APP_convertDecimal
 *
 * [Description]: 	Function to convert from binary to decimal
 *
 * [Args]:			au16_num
 *
 * [in]			  	au16_num: Unsigned long to store the decimal value
 *
 * [out]		  	None
 *
 * [in/out]		 	None
 *
 * [Returns]:       Unsigned long that contains the decimal value
 *******************************************************************************/
uint16_t APP_convertDecimal(uint16_t au16_num)
{
    uint16_t decimal = 0;
    uint16_t i = 0;
    uint16_t reminder;

    while (au16_num != 0)
    {
        reminder = au16_num % 10;
        au16_num /= 10;
        decimal += reminder *  power(2, i);
        ++i;
    }

  return decimal;
}

/*******************************************************************************
 * [Function Name]: power
 *
 * [Description]: 	Function to get the power of a certain value
 *
 * [Args]:			au16_base, au16_exponent
 *
 * [in]			  	au16_base: Unsigned long to store base of the value
 * 					au16_exponent: Unsigned long to store the exponent of the value
 *
 * [out]		  	None
 *
 * [in/out]		 	None
 *
 * [Returns]:       Unsigned long that contains the power of the number
 *******************************************************************************/
uint16_t power(uint16_t au16_base, uint16_t au16_exponent)
{
	uint16_t result = 1;

	for(; au16_exponent > 0; au16_exponent--)
	{
		result = result * au16_base;
	}
	return result;
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
	uint16_t au8_value = 0;	/* local variable to store the address as integer */

	UART_receiveString(gStr8_message);		/* Receive string from terminal */

	/* Check if the message is write or read */
	if(strcmp(gStr8_message, "WRITE") == IDENTICAL)
	{
		UART_receiveString(gStr8_address);	/* Receive address from terminal */
		au8_value = atoi(gStr8_address);

		au8_value = APP_convertDecimal(au8_value);/* Convert the value from binary to decimal */

		UART_sendString("OK\r");			/* Receive acknowledge from terminal */
		gu8_WriteData = UART_recieveByte();	/* Receive data from terminal */

		EEPROM_writeByte(au8_value, gu8_WriteData);	/* Write data in the external EEPROM */
		UART_sendString("\rOK\r\r");
	}
	else if(strcmp(gStr8_message, "READ") == IDENTICAL)
	{
		UART_receiveString(gStr8_address);	/* Receive string from terminal */
		au8_value = atoi(gStr8_address);

		au8_value = APP_convertDecimal(au8_value);/* Convert the value from binary to decimal */

		UART_sendString("OK\r");				/* Receive acknowledge from terminal */
		EEPROM_readByte(au8_value, &gu8_ReadData);	/* Read data in the external EEPROM */

		UART_sendString("The data stored is ");
		UART_sendByte(gu8_ReadData);
		UART_sendString("\r\r");
	}
}
