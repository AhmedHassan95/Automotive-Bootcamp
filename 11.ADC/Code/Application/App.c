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

uint16_t gu16_AdcValue = 0;	/* Global variable to store the adc value */

/*******************************************************************************
 *                             Interrupt Service Routines                      *
 *******************************************************************************/

void App_ADC(void)
{
	gu16_AdcValue = ADC_getDigitalValue();
}

/*******************************************************************************
 *                           Functions Definitions                             *
 *******************************************************************************/

/*******************************************************************************
 * [Function Name]: App_init
 *
 * [Description]: 	Function to Initialize the application to test adc Driver
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
	SREG |= (1<<7); /* Enable Global Interrupt I - Bit */

	LCD_init();		/* LCD Initialization */
	LCD_displayStringRowColumn(0, 0, "Hello Sprints!!!");
	LCD_displayStringRowColumn(1, 4, "ADC TEST");
	_delay_ms(3000); /* Display Time */
	LCD_clearScreen();

	ADC_ConfigType adc_config = {F_CPU_16, VCC_REF, RIGHT};
	ADC_init(&adc_config);
	ADC_setCallBack(App_ADC);
	LCD_displayString("ADC VALUE: ");
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
	ADC_readChannel(0);
	LCD_goToRowColumn(0, 11);
	LCD_intgerToString(gu16_AdcValue);
}
