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
 *                          Global Variables                                   *
 *******************************************************************************/

/* Global variable to store the denounce status modified in the ISR */
volatile static uint8_t debounce_Status = FALSE;

/* Global variable to store the keypad status */
static uint8_t Keypad_Status = KEYPAD_NOT_INITIALIZED;

/*******************************************************************************
 *                      Functions Prototypes(Private)                          *
 *******************************************************************************/

static Std_ReturnType KEYPAD_getPressedKey(uint8_t * au8_data);

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
 *                      Interrupt Service Routines                             *
 *******************************************************************************/

void KEYPAD_CheckDebounce(void)
{
	debounce_Status = TRUE;	/* Rise the denounce flag */

	TIMER_stop(TIMER_1);	/* Stop the timer */
}

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*******************************************************************************
* Service Name: KEYPAD_Init
* Service ID[hex]: 0x10
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): void
* Parameters (in/out): None
* Parameters (out): None
* Return value: Std_ReturnType
* Description: Function to Initialize the KEYPAD
********************************************************************************/
Std_ReturnType KEYPAD_Init(void)
{
	/* Local variable to store the counter value */
	uint8_t au8_counter;

	/* Timer configurations */
	strTIMER_ConfigType_t timer_Config = {INITIAL_VALUE, TWENTY_MS, TIMER_1, COMPARE};

	/* Timer driver initialization */
	TIMER_init(&timer_Config);

	/* Function to be called when the interrupt is fired */
	TIMER_setCallBack(KEYPAD_CheckDebounce, TIMER_1);

	/* Set columns pins to output initially High */
	for(au8_counter = INITIAL_VALUE; au8_counter < N_col; au8_counter++)
	{
		DIO_setPinDirection(KEYPAD_PORT, (KEYPAD_COL_PIN + au8_counter), OUTPUT);
		DIO_writePin(KEYPAD_PORT, (KEYPAD_COL_PIN + au8_counter), HIGH);
	}

	/* Set rows pins to input and set pull up resistors */
	for(au8_counter = INITIAL_VALUE; au8_counter < N_row; au8_counter++)
	{
		DIO_setPinDirection(KEYPAD_PORT, (KEYPAD_ROW_PIN + au8_counter), INPUT);
		DIO_writePin(KEYPAD_PORT, (KEYPAD_ROW_PIN + au8_counter), HIGH);
	}

	Keypad_Status = KEYPAD_INITIALIZED;	/* Update the status of the keypad */

	return E_OK;	/* return success status */
}

/*******************************************************************************
* Service Name: KEYPAD_getStatus
* Service ID[hex]: 0x20
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): au8_data
* Parameters (in/out): None
* Parameters (out): None
* Return value: Std_ReturnType
* Description: Function responsible for getting the status of the KEYPAD
********************************************************************************/
Std_ReturnType KEYPAD_getStatus(uint8_t * au8_data)
{
	static uint8_t au8_keypad_Status = NOT_PRESSED;	/* Static variable to retain the state of the keypad */
	uint8_t au8_keypad_RetValue = NOT_PRESSED;	/* Local variable to return the keypad status */

	if(Keypad_Status == KEYPAD_NOT_INITIALIZED)
	{
		return E_NOT_OK;	/* Return error due to we can't use this API without initialize the keypad first */
	}
	else if(au8_data == NULL_PTR)
	{
		return E_NOT_OK;	/* Return error due to the pointer sent is a NULL pointer */
	}
	else
	{
		switch(au8_keypad_Status)
		{
		case NOT_PRESSED:	au8_keypad_RetValue = KEYPAD_getPressedKey(au8_data);

					if(au8_keypad_RetValue == PRESSED)
					{
						au8_keypad_Status = DEBOUNCING;	/* Update the KEYPAD state */
						TIMER_start(TIMER_1, T1_F_CPU_8);	/* Start timer */
					}
					au8_keypad_RetValue = NOT_PRESSED;	/* Update the return value of the keypad */
					break;

		case DEBOUNCING:	if(debounce_Status == TRUE)
					{
						KEYPAD_getPressedKey(au8_data);	/* Read the data after denouncing */
						debounce_Status = FALSE;	/* Reset the denounce flag */
						au8_keypad_Status = PRESSED;	/* Update the KEYPAD state */
						au8_keypad_RetValue = PRESSED;	/* Update the return value of the keypad */
					}
					break;

		case PRESSED:		au8_keypad_RetValue = KEYPAD_getPressedKey(au8_data);

					if(au8_keypad_RetValue == NOT_PRESSED)
					{
						/* Reset the state machine of the keypad only if the key is released */
						au8_keypad_Status = NOT_PRESSED;
					}
					au8_keypad_RetValue = NOT_PRESSED;	/* Update the return value of the keypad */
					break;
		}

		return au8_keypad_RetValue;	/* Return the keypad status if it is (PRESSED, NOT PRESSED) */
	}
}

/*******************************************************************************
 * Service Name: KEYPAD_getPressedKey
 * Service ID[hex]: 0x30
 * Sync/Async: Synchronous
 * Reentrancy: None reentrant
 * Parameters (in): au8_data
 * Parameters (in/out): None
 * Parameters (out): None
 * Return value: Std_ReturnType
 * Description: Function responsible for getting the pressed keypad key
 ********************************************************************************/
Std_ReturnType KEYPAD_getPressedKey(uint8_t * au8_data)
{
	uint8_t au8_ColumnCounter;
	uint8_t au8_RowCounter;
	uint8_t au8_KeyStatus;
	uint8_t au8_Keyflag = NOT_PRESSED;

	/* Loops on every column */
	for(au8_ColumnCounter = INITIAL_VALUE; au8_ColumnCounter < N_col; au8_ColumnCounter++)
	{
		/* Set column value to low */
		DIO_writePin(KEYPAD_PORT, (KEYPAD_COL_PIN + au8_ColumnCounter) , LOW);

		/* Loops on every row */
		for(au8_RowCounter = INITIAL_VALUE; au8_RowCounter < N_row; au8_RowCounter++)
		{
			/* Read row value */
			DIO_readPin(KEYPAD_PORT, (KEYPAD_ROW_PIN + au8_RowCounter), &au8_KeyStatus);
			/* Check if row is pressed */
			if(au8_KeyStatus == PRESSED)
			{
				#if (N_col == 3)
				*au8_data = KeyPad_4x3_adjustKeyNumber((au8_RowCounter * N_col) + (au8_ColumnCounter+1));
				#elif (N_col == 4)
				*au8_data = KeyPad_4x4_adjustKeyNumber((au8_RowCounter * N_col) + (au8_ColumnCounter+1));
				#endif
				/* Return column value to HIGH */
				au8_Keyflag = PRESSED;
			}
		}
		DIO_writePin(KEYPAD_PORT, (KEYPAD_COL_PIN + au8_ColumnCounter), HIGH);
	}

	return au8_Keyflag;	/* Return the key flag if it is (PRESSED, NOT_PRESSED) */
}

#if (N_col == 3) 
/*******************************************************************************
 * Service Name: KeyPad_4x3_adjustKeyNumber
 * Service ID[hex]: 0x04
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): au8_button_number
 * Parameters (in/out): None
 * Parameters (out): None
 * Return value: uint8_t
 * Description: Function responsible for getting the actual number pressed
 ********************************************************************************/
static uint8_t KeyPad_4x3_adjustKeyNumber(uint8_t au8_button_number)
{
	switch(au8_button_number)
	{
	case 10: return BUTTON_PLUS; /* ASCII Code of = */
	break;
	case 11: return BUTTON_0;
	break;
	case 12: return BUTTON_HASH; /* ASCII Code of # */
	break;
	default: return au8_button_number;
	}
}

#elif (N_col == 4)
/*******************************************************************************
 * Service Name: KeyPad_4x4_adjustKeyNumber
 * Service ID[hex]: 0x04
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): au8_button_number
 * Parameters (in/out): None
 * Parameters (out): None
 * Return value: uint8_t
 * Description: Function responsible for getting the actual number pressed
 ********************************************************************************/
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
	case 4: return BUTTON_MOD;	 /* ASCII Code of % */
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
	case 16: return BUTTON_PLUS; 	/* ASCII Code of '+' */
	break;
	default: return au8_button_number;
	}
}

#endif
