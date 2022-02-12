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

uint8_t gu8_key = FALSE;	/* Global variable to store the key value */
uint8_t gu8_flag = NOT_PRESSED;	/* Global variable to store the status of the keypad */

/*******************************************************************************
 *                           Functions Definitions                             *
 *******************************************************************************/

/*******************************************************************************
 * [Function Name]: App_init
 *
 * [Description]: 	Function to Initialize the application to test keypad Driver
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

	KEYPAD_Init();	/* KEYPAD Initialization */

	LCD_init();		/* LCD Initialization */
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
	gu8_flag = KEYPAD_getStatus(&gu8_key);/* get the pressed key number */

	/* Check if the key is pressed or not */
	if(PRESSED == gu8_flag)
	{
		LCD_intgerToString(gu8_key);	/* display the pressed keypad switch */
	}
}
