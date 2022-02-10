 /******************************************************************************
 *
 * [MODULE]: LCD
 *
 * [FILE NAME]: lcd.c
 *
 * [DESCRIPTION]: Source file for the LCD driver
 *
 * [AUTHOR]: Ahmed Hassan
 *
 *******************************************************************************/

#include "lcd.h"

/*******************************************************************************
 *                              Definitions                	                   *
 *******************************************************************************/

/* LCD data/command configurations */
#define LCD_SEND_MODE   	 	0
#define LCD_WAIT_SEND_MODE   	1
#define LCD_SEND_DATA        	2
#define LCD_WAIT_SEND_DATA	 	3
#define LCD_FINISH		 	    4

/* LCD initialization configurations */
#define LCD_NOT_INIT   	 	    0
#define LCD_SEND_Eight_BIT_MODE 1
#define LCD_SEND_CURSOR_OFF     2
#define LCD_SEND_CLR	        3
#define LCD_INIT	            4

/*******************************************************************************
 *                          Global Variables                                   *
 *******************************************************************************/

/* Global variable to store the denounce Status modified in the ISR */
volatile static uint8_t gu8_lcdStatus = FALSE;

strTIMER_ConfigType_t timer_config = {INITIAL_VALUE, ONE_MS, TIMER_0, COMPARE};

/*******************************************************************************
 *                      Interrupt Service Routines                             *
 *******************************************************************************/

void LCD_CheckStatus(void)
{
	gu8_lcdStatus = TRUE;	/* Rise the LCD Status Flag */

	TIMER_stop(TIMER_0);	/* Stop the timer for the next time */
}

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*******************************************************************************
* Service Name: LCD_Init
* Service ID[hex]: 0x10
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): void
* Parameters (in/out): None
* Parameters (out): None
* Return value: Std_ReturnType (E_OK ,E_NOT_OK)
* Description: Function to Initialize the LCD module
*********************************************************************************/
Std_ReturnType LCD_Init(void)
{
	static uint8_t au8_lcdState = LCD_NOT_INIT;
	uint8_t au8_retValue = E_NOT_OK;

	switch(au8_lcdState)
	{

	case LCD_NOT_INIT:
					   TIMER_init(&timer_config);
					   TIMER_setCallBack(LCD_CheckStatus, TIMER_0);

					   DIO_setPortDirection(LCD_DATA_PORT, OUTPUT);	/* Configure the data port as output port */
					   DIO_setPinDirection(LCD_CTRL_PORT, RS, OUTPUT);	/* Configure the control pin RS as output pin */
					   DIO_setPinDirection(LCD_CTRL_PORT, RW, OUTPUT);	/* Configure the control pin RW as output pin */
					   DIO_setPinDirection(LCD_CTRL_PORT, E, OUTPUT);	/* Configure the control pin E as output pin  */
					   au8_lcdState = LCD_SEND_Eight_BIT_MODE;	/* Update the LCD state */
					   au8_retValue = E_NOT_OK;	/* Update the return value */
					   break;

	case LCD_SEND_Eight_BIT_MODE:

						au8_retValue = LCD_sendCommand(TWO_LINE_LCD_Eight_BIT_MODE);
						if(au8_retValue == E_OK)
						{
							au8_lcdState = LCD_SEND_CURSOR_OFF;	/* Update the LCD state */
						}
						au8_retValue = E_NOT_OK; /* Update the return value */
						break;

	case LCD_SEND_CURSOR_OFF:

						au8_retValue = LCD_sendCommand(CURSOR_OFF);
						if(au8_retValue == E_OK)
						{
							au8_lcdState = LCD_SEND_CLR;	/* Update the LCD state */
						}
						au8_retValue = E_NOT_OK; /* Update the return value */
						break;

	case LCD_SEND_CLR:
						au8_retValue = LCD_sendCommand(CLEAR_COMMAND);
						if(au8_retValue == E_OK)
						{
							au8_lcdState = LCD_INIT;	/* Update the LCD state */
						}
						au8_retValue = E_NOT_OK; /* Update the return value */
						break;

	case LCD_INIT: 		au8_lcdState = LCD_NOT_INIT;	/* Reset the LCD state */
						au8_retValue = E_OK; /* Update the return value */
						break;
	}
	return au8_retValue;	/* Return the status of the LCD (E_OK, E_NOT_OK) */
}

/************************************************************************************
* Service Name: LCD_sendCommand
* Service ID[hex]: 0x20
* Sync/Async: Synchronous
* Reentrancy: reentrant
* Parameters (in): au8_command
* Parameters (in/out): None
* Parameters (out): None
* Return value: Std_ReturnType (E_OK ,E_NOT_OK)
* Description: Function to send command to the LCD
************************************************************************************/
Std_ReturnType LCD_sendCommand(uint8_t au8_command)
{
	static uint8_t au8_lcdState = LCD_SEND_MODE;
	uint8_t au8_retValue = E_NOT_OK;

	switch(au8_lcdState)
	{
	case LCD_SEND_MODE:
							DIO_writePin(LCD_CTRL_PORT, RS, LOW);	/* Instruction Mode RS = 0 */
							DIO_writePin(LCD_CTRL_PORT, RW, LOW);	/* Write data to LCD so RW = 0 */
							TIMER_start(TIMER_0, T0_F_CPU_1024);	/* Start timer */
							au8_lcdState = LCD_WAIT_SEND_MODE;	/* Update the command state */
							break;

	case LCD_WAIT_SEND_MODE:
							if(gu8_lcdStatus == TRUE)
							{
								DIO_writePin(LCD_CTRL_PORT, E, HIGH);	/* Enable LCD E = 1 */
								gu8_lcdStatus = FALSE;	/* Clear the status flag for the next time */
								TIMER_start(TIMER_0, T0_F_CPU_1024);	/* Start the timer */
								au8_lcdState = LCD_SEND_DATA;	/* Update the command state */
							}
							break;

	case LCD_SEND_DATA:
							if(gu8_lcdStatus == TRUE)
							{
								LCD_DATA_OUTPUT = au8_command;	/* Out the required command to the data bus D0 --> D7 */
								gu8_lcdStatus = FALSE;	/* Clear the status flag for the next time */
								TIMER_start(TIMER_0,T0_F_CPU_1024);	/* Start the timer */
								au8_lcdState = LCD_WAIT_SEND_DATA;	/* Update the command state */
							}
							break;

	case LCD_WAIT_SEND_DATA:
							if(gu8_lcdStatus == TRUE)
							{
								DIO_writePin(LCD_CTRL_PORT, E, LOW);
								gu8_lcdStatus = FALSE;	/* Clear the status flag for the next time */
								TIMER_start(TIMER_0, T0_F_CPU_1024);	/* Start the timer */
								au8_lcdState = LCD_FINISH;	/* Update the command state */
							}
							break;

	case LCD_FINISH:
							if(gu8_lcdStatus == TRUE)
							{
								gu8_lcdStatus = FALSE;	/* Clear the status flag for the next time */
								au8_lcdState = LCD_SEND_MODE;	/* Reset the command state */
								au8_retValue = E_OK;	/* Update the return value */
							}
							break;
	}
	return au8_retValue;
}

/************************************************************************************
* Service Name: LCD_displayCharacter
* Service ID[hex]: 0x30
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): au8_data
* Parameters (in/out): None
* Parameters (out): None
* Return value: Std_ReturnType (E_OK ,E_NOT_OK)
* Description: Function to send data to the LCD
************************************************************************************/
Std_ReturnType LCD_displayCharacter(uint8_t au8_data)
{
	static uint8_t au8_lcd_DisplayStatus = LCD_SEND_MODE;
	uint8_t au8_retValue = E_NOT_OK;

	switch(au8_lcd_DisplayStatus)
	{
	case LCD_SEND_MODE:
							DIO_writePin(LCD_CTRL_PORT, RS, HIGH);/* Data Mode RS = 1 */
							DIO_writePin(LCD_CTRL_PORT, RW, LOW);/* Write data to LCD so RW = 0 */
							gu8_lcdStatus = FALSE;	/* Clear the status flag for the next time */
							TIMER_start(TIMER_0, T0_F_CPU_1024);	/* Start the timer */
							au8_lcd_DisplayStatus = LCD_WAIT_SEND_MODE;/* Update the character "Data" state */
							break;

	case LCD_WAIT_SEND_MODE:
							if(gu8_lcdStatus == TRUE)
							{
								DIO_writePin(LCD_CTRL_PORT, E, HIGH); /* Enable LCD E = 1 */
								gu8_lcdStatus = FALSE;	/* Clear the status flag for the next time */
								TIMER_start(TIMER_0, T0_F_CPU_1024);	/* Start the timer */
								au8_lcd_DisplayStatus = LCD_SEND_DATA;/* Update the character "Data" state */
							}
							break;

	case LCD_SEND_DATA :
							if(gu8_lcdStatus == TRUE)
							{
								LCD_DATA_OUTPUT = au8_data; /* Out the required data char to the data bus D0 --> D7 */
								gu8_lcdStatus = FALSE;	/* Clear the status flag for the next time */
								TIMER_start(TIMER_0, T0_F_CPU_1024);	/* Start the timer */
								au8_lcd_DisplayStatus = LCD_WAIT_SEND_DATA;/* Update the character "Data" state */
							}
							break;

	case LCD_WAIT_SEND_DATA:
							if(gu8_lcdStatus == TRUE)
							{
								DIO_writePin(LCD_CTRL_PORT, E, LOW); /* Disable LCD E = 0 */
								gu8_lcdStatus = FALSE;	/* Clear the status flag for the next time */
								TIMER_start(TIMER_0, T0_F_CPU_1024);	/* Start the timer */
								au8_lcd_DisplayStatus = LCD_FINISH;/* Update the character "Data" state */
							}
							break;

	case LCD_FINISH:
							if(gu8_lcdStatus == TRUE)
							{
								gu8_lcdStatus = FALSE;	/* Clear the status flag for the next time */
								au8_lcd_DisplayStatus = LCD_SEND_MODE;	/* Reset the character "Data" state */
								au8_retValue = E_OK;
							}
							break;
	}
	return au8_retValue;
}

/************************************************************************************
* Service Name: LCD_displayString
* Service ID[hex]: 0x40
* Sync/Async: Synchronous
* Reentrancy: reentrant
* Parameters (in): void
* Parameters (in/out): None
* Parameters (out): None
* Return value: None
* Description: Function to display string on the LCD
************************************************************************************/
void LCD_displayString(const uint8_t * Str)
{
	uint8_t au8_index = 0;

	while(Str[au8_index] != '\0')
	{
		if(E_OK == LCD_displayCharacter(Str[au8_index]))
		{
			++au8_index;
		}
	}
}

/***********************************************************************************
* Service Name: LCD_goToRowColumn
* Service ID[hex]: 0x05
* Sync/Async: Synchronous
* Reentrancy: reentrant
* Parameters (in): row, col
* Parameters (in/out): None
* Parameters (out): None
* Return value: Std_ReturnType
* Description: Function to go to on certain column and row
************************************************************************************/
Std_ReturnType LCD_goToRowColumn(uint8_t row, uint8_t col)
{
	uint8_t Address;
	uint16_t retValue = E_NOT_OK;

	/* First of all calculate the required address */
	switch(row)
	{
		case 0:
				Address = col;
				break;
		case 1:
				Address = col+FIRST_ROW;
				break;
		case 2:
				Address = col+SECOND_ROW;
				break;
		case 3:
				Address = col+THIRD_ROW;
				break;
	}
	/*
	 * To write to a specific address in the LCD
	 * we need to apply the corresponding command 0b10000000+Address
	 */
	retValue = LCD_sendCommand(Address | SET_CURSOR_LOCATION);

	if(retValue == E_OK)
	{
		retValue = E_OK;
	}

	return retValue;
}

/***********************************************************************************
* Service Name: LCD_displayStringRowColumn
* Service ID[hex]: 0x06
* Sync/Async: Synchronous
* Reentrancy: reentrant
* Parameters (in): row, col
* Parameters (in/out): None
* Parameters (out): None
* Return value: Std_ReturnType
* Description: Function to display a string on certain column and row
************************************************************************************/
Std_ReturnType LCD_displayStringRowColumn(uint8_t row, uint8_t col, const char * Str)
{
	uint16_t retValue = E_NOT_OK;

	/* Go to to the required LCD position */
	retValue = LCD_goToRowColumn(row,col);

	if(retValue == E_OK)
	{
		LCD_displayString(Str); /* Display the string */
		retValue = E_OK;
	}

	return retValue;
}

/***********************************************************************************
* Service Name: LCD_intgerToString
* Service ID[hex]: 0x07
* Sync/Async: Synchronous
* Reentrancy: reentrant
* Parameters (in): data
* Parameters (in/out): None
* Parameters (out): None
* Return value: None
* Description: Function to display integer on the LCD screen
************************************************************************************/
void LCD_intgerToString(int32_t as32_data)
{
   char buff[16]; /* String to hold the ASCII result */
   itoa(as32_data, buff, 10); /* 10 for decimal */
   LCD_displayString(buff);
}

/***********************************************************************************
* Service Name: LCD_clearScreen
* Service ID[hex]: 0x80
* Sync/Async: Synchronous
* Reentrancy: reentrant
* Parameters (in): void
* Parameters (in/out): None
* Parameters (out): None
* Return value: Std_ReturnType
* Description: Function to clear the LCD screen
************************************************************************************/
Std_ReturnType LCD_clearScreen(void)
{
	uint8_t retValue = E_NOT_OK;

	retValue = LCD_sendCommand(CLEAR_COMMAND); /* Clear display */

	if(retValue == E_OK)
	{
		retValue = E_OK;
	}
	return retValue;
}
