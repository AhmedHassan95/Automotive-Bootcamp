 /******************************************************************************
 *
 * [MODULE]: KEYPAD
 *
 * [FILE NAME]: keypad.c
 *
 * [DESCRIPTION]: Source file for the Keypad driver
 *
 * [AUTHOR]: Ahmed Hassan
 *
 *******************************************************************************/

#include "keypad.h"

/*******************************************************************************
 *                      Functions Prototypes(Private)                          *
 *******************************************************************************/

#if (N_col == 3)
/*
 * Description: Function responsible for mapping the switch number in the keypad to
 * its corresponding functional number in the proteus for 4x3 keypad
 */
static uint8_t KeyPad_4x3_adjustKeyNumber(uint8_t button_number);
#elif (N_col == 4)
/*
 * Description: Function responsible for mapping the switch number in the keypad to
 * its corresponding functional number in the proteus for 4x4 keypad
 */
static uint8_t KeyPad_4x4_adjustKeyNumber(uint8 button_number);
#endif

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
uint8_t KeyPad_getPressedKey(void)
{
	uint8_t col,row;
	
	while(1)
	{
		for(col= 0; col < N_col; col++) /* Loop for columns */
		{
			/* 
			 * Each time only one of the column pins will be output and 
			 * the rest will be input pins include the row pins 
			 * KEYPAD_PORT = (0b00100000<<col);
			 */ 
			DIO_setPinDirection(KEYPAD_PORT, (KEYPAD_COL_PIN + col), HIGH);
			
			/* 
			 * Enable the internal pull up resistors for the rows pins and
			 * Clear the output pin column in this trace
			 * KEYPAD_PORT = (~(0b00100000<<col));
			 */ 
			DIO_writePort(KEYPAD_PORT, ENABLE_PULL_UP);

			DIO_writePin(KEYPAD_PORT, (KEYPAD_COL_PIN + col), LOW);

			for(row = KEYPAD_ROW_PIN; row < (N_row + KEYPAD_ROW_PIN); row++) /* Loop for rows */
			{
				if(BIT_IS_CLEAR(KEYPAD_PORT_IN, row)) /* If the switch is press in this row */
				{
					while(BIT_IS_CLEAR(KEYPAD_PORT_IN, row));    /* de-bouncing */
					#if (N_col == 3)  
						return KeyPad_4x3_adjustKeyNumber(((row-KEYPAD_ROW_PIN) * N_col) + col+1);
					#elif (N_col == 4)
						return KeyPad_4x4_adjustKeyNumber(((row-KEYPAD_ROW_PIN) * N_col) + col+1);
					#endif
				}
			}
		}
	}	
}

#if (N_col == 3) 

static uint8_t KeyPad_4x3_adjustKeyNumber(uint8_t au8_button_number)
{
	switch(au8_button_number)
	{
		case 10: return BUTTON_MUL; /* ASCII Code of * */
				 break;
		case 11: return BUTTON_0;
				 break;
		case 12: return BUTTON_HASH; /* ASCII Code of # */
				 break;
		default: return au8_button_number;
	}
} 

#elif (N_col == 4)
 
static uint8_t KeyPad_4x4_adjustKeyNumber(uint8_t au8_button_number)
{
	switch(au8_button_number)
	{
		case 1: return BUTTON_7;
				break;
		case 2: return BUTTON_8;
				break;
		case 3: return BUTTON_9;
				break;
		case 4: return BUTTON_MOD; 	/* ASCII Code of % */
				break;
		case 5: return BUTTON_4;
				break;
		case 6: return BUTTON_5;
				break;
		case 7: return BUTTON_6;
				break;
		case 8: return BUTTON_MUL; 	/* ASCII Code of '*' */
				break;
		case 9: return BUTTON_1;
				break;
		case 10: return BUTTON_2;
				break;
		case 11: return BUTTON_3;
				break;
		case 12: return BUTTON_MINUS; 	/* ASCII Code of '-' */
				break;
		case 13: return BUTTON_ENTR;  	/* ASCII of Enter */
				break;
		case 14: return BUTTON_0;
				break;
		case 15: return BUTTON_EQL;	/* ASCII Code of '=' */
				break;
		case 16: return BUTTON_PLUS;	/* ASCII Code of '+' */
				break;
		default: return au8_button_number;
	}
} 

#endif
