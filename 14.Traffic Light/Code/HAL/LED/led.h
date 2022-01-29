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

#include "../../Library/std_types.h"
#include "../../Library/common_macros.h"
#include "../../Library/micro_config.h"
#include "../../MCAL/DIO/dio.h"

/*******************************************************************************
 *                             Preprocessor Macros                             *
 *******************************************************************************/

/* LED Pin Configurations */
#define LED_PORT_NUM 	   DIO_PORTB
#define LED_NUM			   4

/******************************************************************************
 *                         Types Declaration                                  *
 ******************************************************************************/

typedef enum
{
	LED_0, LED_1, LED_2
}enuLED_Id_t;

/*******************************************************************************
 *                             Functions Prototypes                            *
 *******************************************************************************/

/*******************************************************************************
 * [Function Name]: LED_init
 *
 * [Description]: Function to Initialize the LED Driver
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
void LED_init(void);

/*******************************************************************************
 * [Function Name]: LED_turnOn
 *
 * [Description]: Function to turn on the LED
 *
 * [Args]:	  enu_LedId
 *
 * [in]		  enu_LedId: Enumerator to LED ID
 *
 * [out]	  None
 *
 * [in/out]	  None
 *
 * [Returns]:     None
 *******************************************************************************/
void LED_turnOn(const enuLED_Id_t enu_LedId);

/*******************************************************************************
 * [Function Name]: LED_turnOff
 *
 * [Description]: Function to turn off the LED
 *
 * [Args]:	  enu_LedId
 *
 * [in]		  enu_LedId: Enumerator to LED ID
 *
 * [out]	  None
 *
 * [in/out]	  None
 *
 * [Returns]:     None
 *******************************************************************************/
void LED_turnOff(const enuLED_Id_t enu_LedId);

/*******************************************************************************
 * [Function Name]: LED_toggle
 *
 * [Description]: Function to toggle the LED
 *
 * [Args]:	  enu_LedId
 *
 * [in]		  enu_LedId: Enumerator to LED ID
 *
 * [out]	  None
 *
 * [in/out]	  None
 *
 * [Returns]:     None
 *******************************************************************************/
void LED_toggle(const enuLED_Id_t enu_LedId);

#endif /* LED_H_ */
