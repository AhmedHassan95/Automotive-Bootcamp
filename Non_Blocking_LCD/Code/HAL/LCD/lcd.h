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
#include "../../MCAL/TIMER/timer_Lcfg.h"
#include "../../MCAL/DIO/dio.h"

/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/

/* Macros for LCD Status */
#define BUSY             (0x00U)
#define AVAILABLE        (0xFFU)

/* LCD HW Pins */
#define RS PIN_1
#define RW PIN_2
#define E  PIN_3
#define LCD_CTRL_PORT 	DIO_PORTA
#define LCD_DATA_PORT 	DIO_PORTA
#define LCD_DATA_OUTPUT PORTA

/* LCD Commands */
#define CLEAR_COMMAND               (0x01U)
#define FOUR_BITS_DATA_MODE         (0x02U)
#define TWO_LINE_LCD_Four_BIT_MODE 	(0x28U)
#define TWO_LINE_LCD_Eight_BIT_MODE (0x38U)
#define CURSOR_OFF 					            (0x0CU)
#define CURSOR_ON 					             (0x0EU)
#define SET_CURSOR_LOCATION 		      (0x80U)

#define FIRST_ROW  					(0x40U)
#define SECOND_ROW 					(0x10U)
#define THIRD_ROW  					(0x50U)

/* Macros for LCD Operations */
#define MASK_FOUR_HIGH_PINS  		     (0x0FU)
#define MASK_FOUR_LOW_PINS   		     (0xF0U)

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*******************************************************************************
* Service Name: LCD_Init
* Service ID[hex]: 0x01
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
* Service ID[hex]: 0x02
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): au8_command
* Parameters (in/out): None
* Parameters (out): None
* Return value: Std_ReturnType (E_OK ,E_NOT_OK)
* Description: Function to send command to the LCD
*********************************************************************************/
Std_ReturnType LCD_sendCommand(uint8_t command);

/********************************************************************************
* Service Name: LCD_displayCharacter
* Service ID[hex]: 0x03
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): au8_data
* Parameters (in/out): None
* Parameters (out): None
* Return value: Std_ReturnType (E_OK ,E_NOT_OK)
* Description: Function to send data to the LCD
*********************************************************************************/
Std_ReturnType LCD_displayCharacter(uint8_t data);

/********************************************************************************
* Service Name: LCD_displayString
* Service ID[hex]: 0x04
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): Str
* Parameters (in/out): None
* Parameters (out): None
* Return value: Std_ReturnType (E_OK, E_NOT_OK)
* Description: Function to display string on the LCD
*********************************************************************************/
Std_ReturnType LCD_displayString(const uint8_t * Str);

/********************************************************************************
* Service Name: LCD_goToRowColumn
* Service ID[hex]: 0x05
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): row, col
* Parameters (in/out): None
* Parameters (out): None
* Return value: Std_ReturnType (E_OK, E_NOT_OK)
* Description: Function to go to on certain column and row
*********************************************************************************/
Std_ReturnType LCD_goToRowColumn(uint8_t row, uint8_t col);

/********************************************************************************
* Service Name: LCD_displayStringRowColumn
* Service ID[hex]: 0x06
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): row, col
* Parameters (in/out): None
* Parameters (out): None
* Return value: Std_ReturnType (E_OK, E_NOT_OK)
* Description: Function to display a string on certain column and row
**********************************************************************************/
Std_ReturnType LCD_displayStringRowColumn(uint8_t row, uint8_t col, const char * Str);

/*********************************************************************************
* Service Name: LCD_intgerToString
* Service ID[hex]: 0x07
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): as32_data
* Parameters (in/out): None
* Parameters (out): None
* Return value: Std_ReturnType (E_OK, E_NOT_OK)
* Description: Function to display integer on the LCD screen
**********************************************************************************/
Std_ReturnType LCD_intgerToString(int32_t as32_data);

/*********************************************************************************
* Service Name: LCD_clearScreen
* Service ID[hex]: 0x08
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): void
* Parameters (in/out): None
* Parameters (out): None
* Return value: Std_ReturnType (E_OK, E_NOT_OK)
* Description: Function to clear the LCD screen
**********************************************************************************/
Std_ReturnType LCD_clearScreen(void);

#endif /* LCD_H_ */
