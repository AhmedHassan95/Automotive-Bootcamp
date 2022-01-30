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

uint8_t gStr_message;	/* Global variable to be sent through the i2c */

/*******************************************************************************
 *                           Functions Definitions                             *
 *******************************************************************************/

/*******************************************************************************
 * [Function Name]: App_init
 *
 * [Description]: Function to Initialize the application to test i2c driver
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
	LCD_init();	/* Initialize LCD Driver */

	TWI_ConfigType twi_config = {SLAVE_ADDRESS, SCL_FREQ_400KBPS, PRESCALER_1};
	TWI_init(&twi_config);	/* Initialize Master I2C */
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

	TWI_start();				/* Start the Slave MCU */

	gStr_message = TWI_readWithACK();	/* Read the data sent by the Master MCU */

	LCD_displayCharacter(gStr_message);	/* Display the character on the LCD */
}
