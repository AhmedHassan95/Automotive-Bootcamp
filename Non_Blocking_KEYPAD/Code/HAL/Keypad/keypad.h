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

/* Macros for keypad Status */
#define KEYPAD_INITIALIZED          (1U)
#define KEYPAD_NOT_INITIALIZED      (0U)

/* Macros for Keypad configurations "Number of rows and columns" */
#define N_col 3
#define N_row 3

/* Macros for Keypad Port configurations */
#define KEYPAD_PORT	DIO_PORTC
#define KEYPAD_COL_PIN	PIN_5
#define KEYPAD_ROW_PIN	PIN_2

/* Macros for Keypad Buttons */
#define BUTTON_0       (0U)
#define BUTTON_1       (1U)
#define BUTTON_2       (2U)
#define BUTTON_3       (3U)
#define BUTTON_4       (4U)
#define BUTTON_5       (5U)
#define BUTTON_6       (6U)
#define BUTTON_7       (7U)
#define BUTTON_8       (8U)
#define BUTTON_9       (9U)
#define BUTTON_10      (10U)
#define BUTTON_11      (11U)
#define BUTTON_12      (12U)
#define BUTTON_13      (13U)
#define BUTTON_PLUS    (43U)
#define BUTTON_MINUS   (45U)
#define BUTTON_EQL     (61U)
#define BUTTON_MUL     (42U)
#define BUTTON_MOD     (37U)
#define BUTTON_HASH    (35U)
#define BUTTON_ENTR    (13U)

/* Macros for Keypad configurations of state machine */
#define PRESSED         (0U)
#define NOT_PRESSED     (1U)
#define DEBOUNCING      (2U)

#define INITIAL_VALUE	(0U)
#define TWENTY_MS		(20000U)

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
* Reentrancy: Reentrant
* Parameters (in): au8_data
* Parameters (in/out): None
* Parameters (out): None
* Return value: Std_ReturnType
* Description: Function responsible for getting the status of the KEYPAD
********************************************************************************/
Std_ReturnType KEYPAD_getStatus(uint8_t * data);

#endif /* KEYPAD_H_ */
