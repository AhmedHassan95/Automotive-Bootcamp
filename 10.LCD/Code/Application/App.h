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
#include "../HAL/LCD/lcd.h"
#include "../MCAL/dio.h"

/*******************************************************************************
 *                             Functions Prototypes                            *
 *******************************************************************************/

/*******************************************************************************
 * [Function Name]: App_init
 *
 * [Description]: Function to Initialize the application to test lcd
 *
 * [Args]: None
 *
 * [in] None
 *
 * [out] None
 *
 * [in/out] None
 *
 * [Returns]: None
 *******************************************************************************/
void App_init(void);

#endif /* APP_H_ */
