 /******************************************************************************
 *
 * [MODULE]: LED
 *
 * [FILE NAME]: led.h
 *
 * [DESCRIPTION]: Header file for the LED Driver
 *
 * [AUTHOR]: Ahmed Hassan
 *
 *******************************************************************************/

#ifndef LED_H_
#define LED_H_

#include "../Includes/std_types.h"
#include "../Includes/common_macros.h"
#include "../Includes/micro_config.h"
#include "../MCAL/dio.h"

/*******************************************************************************
 *                             Preprocessor Macros                             *
 *******************************************************************************/

/* LED Pin Configurations */
#define LED_PORT_NUM 	   DIO_PORTB
#define LED_PIN_NUM	   PIN_4

/*******************************************************************************
 *                             Functions Prototypes                            *
 *******************************************************************************/

/*******************************************************************************
 * [Function Name]: LED_init
 *
 * [Description]: Function to Initialize the LED Driver
 *
 * [Args]:	 None
 *
 * [in]	        None
 *
 * [out]	 None
 *
 * [in/out]	 None
 *
 * [Returns]:    None
 *******************************************************************************/
void LED_init(void);

/*******************************************************************************
 * [Function Name]: LED_turnOn
 *
 * [Description]: Function to turn on the LED
 *
 * [Args]: 	None
 *
 * [in]	       None
 *
 * [out] 	None
 *
 * [in/out] 	None
 *
 * [Returns]:    None
 *******************************************************************************/
void LED_turnOn(void);

/*******************************************************************************
 * [Function Name]: LED_turnOff
 *
 * [Description]:	Function to turn off the LED
 *
 * [Args]:	None
 *
 * [in]			None
 *
 * [out]	 None
 *
 * [in/out]	None
 *
 * [Returns]:     None
 *******************************************************************************/
void LED_turnOff(void);

/*******************************************************************************
 * [Function Name]: LED_toggle
 *
 * [Description]: Function to toggle the LED
 *
 * [Args]:	 None
 *
 * [in] None
 *
 * [out]	 None
 *
 * [in/out]	 None
 *
 * [Returns]:    None
 *******************************************************************************/
void LED_toggle(void);

#endif /* LED_H_ */
