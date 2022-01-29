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
#include "../MCAL/UART/uart.h"
#include "../HAL/LED/led.h"

#define IDENTICAL	0

#define LED_GREEN	0
#define LED_YELLOW      1
#define LED_RED		2

/*******************************************************************************
 *                             Functions Prototypes                            *
 *******************************************************************************/

/*******************************************************************************
 * [Function Name]: App_init
 *
 * [Description]: Function to Initialize the application
 *
 * [Args]:	None
 *
 * [in]	       None
 *
 * [out]	None
 *
 * [in/out]	None
 *
 * [Returns]:   None
 *******************************************************************************/
void App_init(void);

/*******************************************************************************
 * [Function Name]: App_Update
 *
 * [Description]: Function to update the state of the application
 *
 * [Args]:	None
 *
 * [in]	        None
 *
 * [out]	None
 *
 * [in/out]	None
 *
 * [Returns]:   None
 *******************************************************************************/
void App_Update(void);

#endif /* APP_H_ */
