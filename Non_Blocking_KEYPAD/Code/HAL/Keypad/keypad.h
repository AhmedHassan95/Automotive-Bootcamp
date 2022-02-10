 /******************************************************************************
 *
 * [MODULE]: KEYPAD
 *
 * [FILE NAME]: keypad.h
 *
 * [DESCRIPTION]: Header file for the Keypad driver
 *
 * [AUTHOR]: Ahmed Hassan
 *
 *******************************************************************************/

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "../../Library/std_types.h"
#include "../../Library/common_macros.h"
#include "../../Library/micro_config.h"
#include "../../MCAL/DIO/dio.h"
#include "../../MCAL/TIMER/timer.h"

/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/

/* Keypad configurations for number of rows and columns */
#define N_col 3
#define N_row 3

/* Keypad Port Configurations */
#define KEYPAD_PORT		DIO_PORTC
#define KEYPAD_COL_PIN	PIN_5
#define KEYPAD_ROW_PIN	PIN_2

/* Keypad Buttons */
#define BUTTON_0       (0u)
#define BUTTON_1       (1u)
#define BUTTON_2       (2u)
#define BUTTON_3       (3u)
#define BUTTON_4       (4u)
#define BUTTON_5       (5u)
#define BUTTON_6       (6u)
#define BUTTON_7       (7u)
#define BUTTON_8       (8u)
#define BUTTON_9       (9u)
#define BUTTON_10      (10u)
#define BUTTON_11      (11u)
#define BUTTON_12      (12u)
#define BUTTON_13      (13u)
#define BUTTON_PLUS    (43u)
#define BUTTON_MINUS   (45u)
#define BUTTON_EQL     (61u)
#define BUTTON_MUL     (42u)
#define BUTTON_MOD     (37u)
#define BUTTON_HASH    (35u)
#define BUTTON_ENTR    (13u)

/* Keypad configurations for state machine */
#define PRESSED         (0u)
#define NOT_PRESSED     (1u)
#define DEBOUNCING      (2u)

#define INITIAL_VALUE	(0u)
#define TWENTY_MS		(20000u)

/*******************************************************************************
 *                      Functions Prototypes                                   *
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
Std_ReturnType KEYPAD_Init(void);

/*******************************************************************************
* Service Name: KEYPAD_getStatus
* Service ID[hex]: 0x20
* Sync/Async: Synchronous
* Reentrancy: reentrant
* Parameters (in): au8_data
* Parameters (in/out): None
* Parameters (out): None
* Return value: Std_ReturnType
* Description: Function responsible for getting the status of the KEYPAD
********************************************************************************/
Std_ReturnType KEYPAD_getStatus(uint8_t * data);

#endif /* KEYPAD_H_ */
