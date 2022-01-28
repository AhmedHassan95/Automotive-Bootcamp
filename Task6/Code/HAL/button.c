 /******************************************************************************
 *
 * [MODULE]: BUTTON
 *
 * [FILE NAME]: button.c
 *
 * [DESCRIPTION]: Source file for the BUTTON Driver
 *
 * [AUTHOR]: Ahmed Hassan
 *
 *******************************************************************************/

#include "button.h"

/*******************************************************************************
 *                           Functions Definitions                             *
 *******************************************************************************/

/*******************************************************************************
 * [Function Name]: BUTTON_init
 *
 * [Description]: 	Function to Initialize the BUTTON Driver
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
void BUTTON_init(void)
{
	/* Configure BUTTON pin as an input pin */
	DIO_setPinDirection(BUTTON_PORT_NUM, BUTTON_PIN_NUM, INPUT);
}

/*******************************************************************************
 * [Function Name]: BUTTON_read
 *
 * [Description]: 	Function to read the value of the BUTTON
 *
 * [Args]:			None
 *
 * [in]			  	None
 *
 * [out]		  	uint8
 *
 * [in/out]		 	None
 *
 * [Returns]:       Unsigned character that hold the BUTTON state
 *******************************************************************************/
uint8_t BUTTON_read(void)
{
	uint8_t au8_ButtonState;

	/* Read the button state */
	DIO_readPin(BUTTON_PORT_NUM, BUTTON_PIN_NUM, &au8_ButtonState);

	/* Check if the button is pressed or not */
	if(au8_ButtonState == HIGH)
	{
		return BUTTON_PRESSED;		/* Button is pressed */
	}
	else
	{
		return BUTTON_NOT_PRESSED;	/* Button is not pressed */
	}
}
