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
#include "../../MCAL/DIO/dio.h"

/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/

/* LCD HW Pins */
#define RS PIN_1
#define RW PIN_2
#define E  PIN_3
#define LCD_CTRL_PORT 	DIO_PORTA
#define LCD_DATA_PORT 	DIO_PORTA
#define LCD_DATA_OUTPUT PORTA

/* LCD Commands */
#define CLEAR_COMMAND 				(0x01U)
#define FOUR_BITS_DATA_MODE 		(0x02U)
#define TWO_LINE_LCD_Four_BIT_MODE 	(0x28U)
#define TWO_LINE_LCD_Eight_BIT_MODE (0x38U)
#define CURSOR_OFF 					(0x0CU)
#define CURSOR_ON 					(0x0EU)
#define SET_CURSOR_LOCATION 		(0x80U)

#define FIRST_ROW  					(0x40U)
#define SECOND_ROW 					(0x10U)
#define THIRD_ROW  					(0x50U)

/* Macros for LCD Operations */
#define MASK_FOUR_HIGH_PINS  		(0x0FU)
#define MASK_FOUR_LOW_PINS   		(0xF0U)

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

void LCD_sendCommand(uint8_t au8_command);
void LCD_displayCharacter(uint8_t au8_data);
void LCD_displayString(const uint8_t * Str);
void LCD_init(void);
void LCD_clearScreen(void);
void LCD_displayStringRowColumn(uint8_t au8_row, uint8_t au8_col, const char * Str);
void LCD_goToRowColumn(uint8_t au8_row, uint8_t au8_col);
void LCD_intgerToString(int32_t s32_data);

#endif /* LCD_H_ */
