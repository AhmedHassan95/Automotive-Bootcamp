 /******************************************************************************
 *
 * [MODULE]: APPLICATION
 *
 * [FILE NAME]: App.h
 *
 * [DESCRIPTION]: Header file for the Application
 *
 * [AUTHOR]: Ahmed Hassan
 *
 *******************************************************************************/

#ifndef APP_H_
#define APP_H_

#include "../Library/std_types.h"
#include "../Library/common_macros.h"
#include "../Library/micro_config.h"
#include "../MCAL/DIO/dio.h"
#include "../MCAL/I2C/i2c.h"
#include "../MCAL/UART/uart.h"
#include "../HAL/EEPROM/external_eeprom.h"

#define IDENTICAL 0

/*******************************************************************************
 *                             Functions Prototypes                            *
 *******************************************************************************/

/*******************************************************************************
 * [Function Name]: App_init
 *
 * [Description]: Function to Initialize the application to test i2c driver
 *
 * [Args]:      None
 *
 * [in]		None
 *
 * [out]	None
 *
 * [in/out]	None
 *
 * [Returns]:   None
 *******************************************************************************/
void App_init(void);

/*******************************************************************************
 * [Function Name]: APP_convertDecimal
 *
 * [Description]: Function to convert from binary to decimal
 *
 * [Args]:      au16_num
 *
 * [in]		au16_num: Unsigned long to store the decimal value
 *
 * [out]	None
 *
 * [in/out]	None
 *
 * [Returns]:   Unsigned long that contains the decimal value
 *******************************************************************************/
uint16_t APP_convertDecimal(uint16_t au16_num);

/*******************************************************************************
 * [Function Name]: power
 *
 * [Description]: Function to get the power of a certain value
 *
 * [Args]:	au16_base, au16_exponent
 *
 * [in]	       au16_base: Unsigned long to store base of the value
 *             au16_exponent: Unsigned long to store the exponent of the value
 *
 * [out]      None
 *
 * [in/out]    None
 *
 * [Returns]:  Unsigned long that contains the power of the number
 *******************************************************************************/
uint16_t power(uint16_t au16_base, uint16_t au16_exponent);

/*******************************************************************************
 * [Function Name]: App_Update
 *
 * [Description]: Function to update the state of the application
 *
 * [Args]:	None
 *
 * [in]		None
 *
 * [out]	None
 *
 * [in/out]	None
 *
 * [Returns]:   None
 *******************************************************************************/
void App_Update(void);

#endif /* APP_H_ */
