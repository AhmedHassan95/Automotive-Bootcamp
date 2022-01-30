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
#include "../MCAL/timer.h"

#define TIMER_FOR_HIGH_PERIOD 3
#define TIMER_FOR_LOW_PERIOD  8

/*******************************************************************************
 *                             Functions Prototypes                            *
 *******************************************************************************/

/*******************************************************************************
 * [Function Name]: App_init
 *
 * [Description]: Function to Initialize the application to test timer compare
 * 	          match mode
 *
 * [Args]:	 None
 *
 * [in]	         None
 *
 * [out]	 None
 *
 * [in/out]	 None
 *
 * [Returns]:    None
 *******************************************************************************/
void App_init(void);

/*******************************************************************************
 * [Function Name]: App_Update
 *
 * [Description]: Function to update the state of the application
 *
 * [Args]:	None
 *
 * [in]        None
 *
 * [out]       None
 *
 * [in/out]      None
 *
 * [Returns]:     None
 *******************************************************************************/
void App_Update(void);

#endif /* APP_H_ */
