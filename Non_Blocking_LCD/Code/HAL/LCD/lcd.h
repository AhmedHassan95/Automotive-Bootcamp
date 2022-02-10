 /******************************************************************************
 *
 * [MODULE]: LCD
 *
 * [FILE NAME]: lcd.h
 *
 * [DESCRIPTION]: Header file for the LCD driver
 *
 * [AUTHOR]: Ahmed Hassan
 *
 *******************************************************************************/

#ifndef LCD_H_
#define LCD_H_

#include "../../Library/std_types.h"
#include "../../Library/common_macros.h"
#include "../../Library/micro_config.h"
#include "../../MCAL/TIMER/timer.h"
#include "../../MCAL/dio.h"

/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/

/* LCD HW Pins */
#define RS PIN_0
#define RW PIN_1
#define E  PIN_2
#define LCD_CTRL_PORT 	DIO_PORTB
#define LCD_DATA_PORT 	DIO_PORTA
#define LCD_DATA_OUTPUT PORTA

/* LCD Commands */
#define CLEAR_COMMAND 0x01
#define FOUR_BITS_DATA_MODE 0x02
#define TWO_LINE_LCD_Four_BIT_MODE 0x28
#define TWO_LINE_LCD_Eight_BIT_MODE 0x38
#define CURSOR_OFF 0x0C
#define CURSOR_ON 0x0E
#define SET_CURSOR_LOCATION 0x80

#define FIRST_ROW  0x40
#define SECOND_ROW 0x10
#define THIRD_ROW  0x50

/* Macros for timer configurations */
#define INITIAL_VALUE 0
#define ONE_MS        8

/*******************************************************************************
 *                      Functions Prototypes                                   *
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
Std_ReturnType LCD_Init(void);

/********************************************************************************
* Service Name: LCD_sendCommand
* Service ID[hex]: 0x20
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): au8_command
* Parameters (in/out): None
* Parameters (out): None
* Return value: Std_ReturnType (E_OK ,E_NOT_OK)
* Description: Function to send command to the LCD
*********************************************************************************/
Std_ReturnType LCD_sendCommand(uint8_t command);

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
Std_ReturnType LCD_displayCharacter(uint8_t data);

/***********************************************************************************
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
void LCD_displayString(const uint8_t * Str);

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
Std_ReturnType LCD_goToRowColumn(uint8_t row, uint8_t col);

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
Std_ReturnType LCD_displayStringRowColumn(uint8_t row, uint8_t col, const char * Str);

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
void LCD_intgerToString(int32_t as32_data);

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
Std_ReturnType LCD_clearScreen(void);

#endif /* LCD_H_ */
