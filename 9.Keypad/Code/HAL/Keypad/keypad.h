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
#include "../../MCAL/dio.h"

/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/

/* Keypad configurations for number of rows and columns */
#define N_col 3
#define N_row 3

/* Keypad Port Configurations */
#define KEYPAD_PORT	   	DIO_PORTC
#define KEYPAD_PORT_IN  PINC
#define KEYPAD_COL_PIN 	PIN_5
#define KEYPAD_ROW_PIN 	PIN_2
#define ENABLE_PULL_UP 	0xFC

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

#define BUTTON_PLUS    (43U)
#define BUTTON_MINUS   (45U)
#define BUTTON_EQL     (61U)
#define BUTTON_MUL     (42U)
#define BUTTON_MOD     (37U)
#define BUTTON_HASH    (35U)
#define BUTTON_ENTR    (13U)

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/* 
 * Description: Function responsible for getting the pressed keypad key 
 */
uint8_t KeyPad_getPressedKey(void);

#endif /* KEYPAD_H_ */
