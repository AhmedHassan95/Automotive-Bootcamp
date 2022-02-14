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
 *                           Global Variables                                  *
 *******************************************************************************/

uint8_t gu8_lcdInit = E_NOT_OK;	/* Global variable to store the value of LCD initialization */
uint8_t gu8_lcdState = E_NOT_OK;/* Global variable to store the value LCD state */

uint8_t gu8_lcdDisChar1 = E_NOT_OK;
uint8_t gu8_lcdDisChar2 = E_NOT_OK;
uint8_t gu8_lcdDisStr   = E_NOT_OK;
uint8_t gu8_lcdDisNum   = E_NOT_OK;
uint8_t gu8_lcdDisCM    = E_NOT_OK;

/*******************************************************************************
 *                           Functions Definitions                             *
 *******************************************************************************/

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
		}
	}
	else
	{
		/* Display a string */
		if(gu8_lcdDisStr == E_NOT_OK)
		{
			gu8_lcdDisStr = LCD_displayStringRowColumn(0, 0, "LCD NON BLOCKING");
		}

		/* Perform a command */
		if(gu8_lcdDisCM == E_NOT_OK)
		{
			gu8_lcdDisCM = LCD_goToRowColumn(1,0);
		}

		/* Display a character */
		if(gu8_lcdDisChar1 == E_NOT_OK)
		{
			gu8_lcdDisChar1 = LCD_displayCharacter('A');
		}

		/* Display another character */
		if(gu8_lcdDisChar2 == E_NOT_OK)
		{
			gu8_lcdDisChar2 = LCD_displayCharacter(' ');
		}

		/* Display an integer number */
		if(gu8_lcdDisNum == E_NOT_OK)
		{
			gu8_lcdDisNum = LCD_intgerToString(123);
		}
	}
}
