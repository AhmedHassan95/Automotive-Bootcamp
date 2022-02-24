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
#include "../MCAL/UART/uart.h"

#define MESS_SIZE 20

/*******************************************************************************
 *                             Functions Prototypes                            *
 *******************************************************************************/

/*******************************************************************************
 * [Function Name]: app_init
 *
 * [Description]: Function to Initialize the application to test uart
 *
 * [Args]:	  None
 *
 * [in]		  None
 *
 * [out]	  None
 *
 * [in/out]	  None
 *
 * [Returns]:     None
 *******************************************************************************/
void app_init(void);

/*******************************************************************************
 * [Function Name]: app_Update
 *
 * [Description]: Function to update the state of the application
 *
 * [Args]:	  None
 *
 * [in]		  None
 *
 * [out]	  None
 *
 * [in/out]       None
 *
 * [Returns]:     None
 *******************************************************************************/
void app_Update(void);

#endif /* APP_H_ */
