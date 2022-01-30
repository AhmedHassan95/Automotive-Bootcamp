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

#include "../Includes/std_types.h"
#include "../Includes/common_macros.h"
#include "../Includes/micro_config.h"
#include "../HAL/led.h"
#include "../HAL/button.h"

/*******************************************************************************
 *                             Functions Prototypes                            *
 *******************************************************************************/

/*******************************************************************************
 * [Function Name]: App_init
 *
 * [Description]: Function to Initialize the application to test the DIO Driver
 *
 * [Args]:	 None
 *
 * [in]	         None
 *
 * [out]	 None
 *
 * [in/out]      None
 *
 * [Returns]:    None
 *******************************************************************************/
void App_init(void);

/*******************************************************************************
 * [Function Name]: App_update
 *
 * [Description]: Function to update the application status
 *
 * [Args]    None
 *
 * [in]		None
 *
 * [out]	None
 *
 * [in/out]	None
 *
 * [Returns]:    None
 *******************************************************************************/
void App_update(void);

#endif /* APP_H_ */
