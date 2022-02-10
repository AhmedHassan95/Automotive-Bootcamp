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

uint8_t gu8_lcdInit = E_NOT_OK;	/* Global variable to store the value of LCD initialization */
uint8_t gu8_lcdState = E_NOT_OK;/* Global variable to store the value  LCD state */

uint8_t gu8_clrFlage = E_NOT_OK;
uint8_t gu8_clrdis = E_NOT_OK;

uint8_t gu8_intFlage = E_NOT_OK;
uint8_t gu8_intdis = E_NOT_OK;

/*******************************************************************************
 * [Function Name]: App_init
 *
 * [Description]: 	Function to Initialize the application to test LCD Driver
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
	sei();	/* Enable the global Interrupt (I-bit) */
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
	if(gu8_lcdInit == E_NOT_OK)
	{
		gu8_lcdState = LCD_Init();	/* LCD Initialization */

		if(gu8_lcdState == E_OK)
		{
			gu8_lcdInit = E_OK;	/* Update the LCD Flag (LCD INIT) */

			LCD_displayString("LCD NON-BLOCKING");
		}
	}
	else if(gu8_lcdInit == E_OK)
	{
		if(gu8_clrFlage == E_NOT_OK)
		{
			gu8_clrdis  = LCD_displayStringRowColumn(1, 3 , "123456789");

			if(gu8_clrdis  == E_OK)
			{
				gu8_clrFlage = E_OK;
			}
		}
	}
}
