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

uint8_t gu8_key;	/* Global variable to store the key value */

/*******************************************************************************
 *                           Functions Definitions                             *
 *******************************************************************************/

/*******************************************************************************
 * [Function Name]: App_init
 *
 * [Description]: Function to Initialize the application to test keypad Driver
 *
 * [Args]:	None
 *
 * [in]		None
 *
 * [out]	None
 *
 * [in/out]	None
 *
 * [Returns]:   None
 *******************************************************************************/
void App_init(void)
{
	LCD_init();	/* LCD Initialization */
	LCD_displayStringRowColumn(0, 0, "Hello Sprints!!!");
	LCD_displayStringRowColumn(1, 2, "KEYPAD TEST");
	_delay_ms(3000); /* Display Time */
	LCD_clearScreen();
	LCD_displayStringRowColumn(0, 0, "PRESS ANY KEY TO");
	LCD_displayStringRowColumn(1, 2, "TEST KEYPAD");
	_delay_ms(2000); /* Display Time */
	LCD_clearScreen();
}

/*******************************************************************************
 * [Function Name]: App_Update
 *
 * [Description]: Function to update the state of the application
 *
 * [Args]:	None
 *
 * [in]		None
 *
 * [out]	None
 *
 * [in/out]	None
 *
 * [Returns]:   None
 *******************************************************************************/
void App_Update(void)
{
	/* If any switch pressed for more than 500 ms it counts only one press */

	gu8_key = KeyPad_getPressedKey(); /* get the pressed key number */

	if((gu8_key <= 9) && (gu8_key >= 0))
	{
		LCD_intgerToString(gu8_key); /* display the pressed keypad switch */
	}
	else
	{
		LCD_displayCharacter(gu8_key); /* display the pressed keypad switch */
	}
}
