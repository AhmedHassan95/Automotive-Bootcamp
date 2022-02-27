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
 *                      Functions Definitions                                  *
 *******************************************************************************/
void LCD_init(void)
{
	/* Configure the control pins(E,RS,RW) as output pins */
	DIO_setPinDirection(LCD_CTRL_PORT, E, OUTPUT);
	DIO_setPinDirection(LCD_CTRL_PORT, RS, OUTPUT);
	DIO_setPinDirection(LCD_CTRL_PORT, RW, OUTPUT);

	/* Configure the highest 4 bits of the data port as output pins */
	DIO_setPinDirection(LCD_DATA_PORT, PIN_4, OUTPUT);
	DIO_setPinDirection(LCD_DATA_PORT, PIN_5, OUTPUT);
	DIO_setPinDirection(LCD_DATA_PORT, PIN_6, OUTPUT);
	DIO_setPinDirection(LCD_DATA_PORT, PIN_7, OUTPUT);
	
	LCD_sendCommand(FOUR_BITS_DATA_MODE); 		 /* Initialize LCD in 4-bit mode */
	LCD_sendCommand(TWO_LINE_LCD_Four_BIT_MODE); /* Use 2-line LCD + 4-bit Data Mode + 5*7 dot display Mode */
	LCD_sendCommand(CURSOR_OFF); 				 /* Cursor off */
	LCD_sendCommand(CLEAR_COMMAND); 			 /* Clear LCD at the beginning */
}

void LCD_sendCommand(uint8_t au8_command)
{
	DIO_writePin(LCD_CTRL_PORT, RS, LOW);	/* Instruction Mode RS = 0 */
	DIO_writePin(LCD_CTRL_PORT, RW, LOW);	/* Write data to LCD so RW = 0 */
	_delay_ms(1); 							/* Delay for processing Tas = 50ns */

	DIO_writePin(LCD_CTRL_PORT, E, HIGH);	/* Enable LCD E = 1 */
	_delay_ms(1); /* Delay for processing Tpw - Tdws = 190ns */

	/* Out the highest 4 bits of the required command to the data bus D4 --> D7 */
	LCD_DATA_OUTPUT = (LCD_DATA_OUTPUT & MASK_FOUR_HIGH_PINS) | (au8_command & MASK_FOUR_LOW_PINS);
	_delay_ms(1); /* Delay for processing Tdsw = 100ns */

	DIO_writePin(LCD_CTRL_PORT, E, LOW);	/* Disable LCD E = 0 */
	_delay_ms(1); /* Delay for processing Th = 13ns */

	DIO_writePin(LCD_CTRL_PORT, E, HIGH);	/* Enable LCD E = 1 */
	_delay_ms(1); /* Delay for processing Tpw - Tdws = 190ns */

	/* Out the lowest 4 bits of the required command to the data bus D4 --> D7 */
	LCD_DATA_OUTPUT = (LCD_DATA_OUTPUT & MASK_FOUR_HIGH_PINS) | ((au8_command & MASK_FOUR_HIGH_PINS) << 4);
	_delay_ms(1); /* Delay for processing Tdsw = 100ns */

	DIO_writePin(LCD_CTRL_PORT, E, LOW);	/* Disable LCD E = 0 */
	_delay_ms(1); /* Delay for processing Th = 13ns */
}

void LCD_displayCharacter(uint8_t au8_data)
{
	DIO_writePin(DIO_PORTA, RS, HIGH);	/* Data Mode RS = 1 */
	DIO_writePin(DIO_PORTA, RW, LOW);	/* Write data to LCD so RW = 0 */
	_delay_ms(1); 						/* Delay for processing Tas = 50ns */

	DIO_writePin(DIO_PORTA, E, HIGH);	/* Enable LCD E = 1 */
	_delay_ms(1); /* Delay for processing Tpw - Tdws = 190ns */

	/* Out the highest 4 bits of the required data to the data bus D4 --> D7 */
	LCD_DATA_OUTPUT = (LCD_DATA_OUTPUT & MASK_FOUR_HIGH_PINS) | (au8_data & MASK_FOUR_LOW_PINS);
	_delay_ms(1); /* Delay for processing Tdsw = 100ns */

	DIO_writePin(DIO_PORTA, E, LOW);	/* Disable LCD E = 0 */
	_delay_ms(1); /* Delay for processing Th = 13ns */

	DIO_writePin(DIO_PORTA, E, HIGH);	/* Enable LCD E = 0 */
	_delay_ms(1); /* Delay for processing Tpw - Tdws = 190ns */

	/* Out the lowest 4 bits of the required data to the data bus D4 --> D7 */
	LCD_DATA_OUTPUT = (LCD_DATA_OUTPUT & MASK_FOUR_HIGH_PINS) | ((au8_data & MASK_FOUR_HIGH_PINS) << 4);
	_delay_ms(1); /* Delay for processing Tdsw = 100ns */

	DIO_writePin(DIO_PORTA, E, LOW);	/* Disable LCD E = 0 */
	_delay_ms(1); /* Delay for processing Th = 13ns */
}

void LCD_displayString(const uint8_t * Str)
{
	uint8_t au8_index = 0;

	while(Str[au8_index] != '\0')
	{
		LCD_displayCharacter(Str[au8_index]);
		au8_index++;
	}
}

void LCD_goToRowColumn(uint8_t au8_row, uint8_t au8_col)
{
	uint8_t au8_address;
	
	/* First of all calculate the required address */
	switch(au8_row)
	{
		case 0:
			au8_address = au8_col;
			break;
		case 1:
			au8_address = au8_col + FIRST_ROW;
			break;
		case 2:
			au8_address = au8_col + SECOND_ROW;
			break;
		case 3:
			au8_address = au8_col + THIRD_ROW;
			break;
	}					
	/* 
	 * To write to a specific address in the LCD 
	 * we need to apply the corresponding command 0b10000000+Address 
	 */
	LCD_sendCommand(au8_address | SET_CURSOR_LOCATION);
}

void LCD_displayStringRowColumn(uint8_t au8_row, uint8_t au8_col, const char * Str)
{
	LCD_goToRowColumn(au8_row, au8_col); /* Go to to the required LCD position */
	LCD_displayString(Str); 	 /* Display the string */
}

void LCD_intgerToString(int32_t s32_data)
{
   char buff[16]; 	   /* String to hold the ASCII result */
   itoa(s32_data,buff,10); /* 10 for decimal */
   LCD_displayString(buff);
}

void LCD_clearScreen(void)
{
	LCD_sendCommand(CLEAR_COMMAND); /* Clear display */
}
