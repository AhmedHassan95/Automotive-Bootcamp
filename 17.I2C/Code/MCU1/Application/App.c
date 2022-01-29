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
	TWI_ConfigType twi_config = {MASTER_ADDRESS, SCL_FREQ_400KBPS, PRESCALER_1};

	TWI_init(&twi_config);	/* Initialize Master I2C */

	_delay_ms(50);		/* Delay until Slave MCU finish its initialization */
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
	TWI_start();				/* Send Start bit to Slave MCU */

	TWI_write(SLAVE_ADDRESS, ADDRESS);	/* Select the Slave MCU */

	TWI_write('A', DATA);			/* Sent the data to Slave MCU */

	TWI_stop();				/* Send Stop bit to Slave MCU */

	_delay_ms(100);
}
