 /******************************************************************************
 *
 * [MODULE]: BUTTON
 *
 * [FILE NAME]: button.h
 *
 * [DESCRIPTION]: Header file for the BUTTON Driver
 *
 * [AUTHOR]: Ahmed Hassan
 *
 *******************************************************************************/

#ifndef BUTTON_H_
#define BUTTON_H_

#include "../Includes/std_types.h"
#include "../Includes/common_macros.h"
#include "../Includes/micro_config.h"
#include "../MCAL/dio.h"

/*******************************************************************************
 *                             Preprocessor Macros                             *
 *******************************************************************************/

/* BUTTON Pin Configurations */
#define BUTTON_PORT_NUM 		DIO_PORTC
#define BUTTON_PIN_NUM			PIN_4

#define BUTTON_PRESSED	   		0x01
#define BUTTON_NOT_PRESSED		0x00

/*******************************************************************************
 *                             Functions Prototypes                            *
 *******************************************************************************/

/*******************************************************************************
 * [Function Name]: BUTTON_init
 *
 * [Description]: Function to Initialize the BUTTON Driver
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
void BUTTON_init(void);

/*******************************************************************************
 * [Function Name]: BUTTON_read
 *
 * [Description]: Function to read the value of the BUTTON
 *
 * [Args]:	 None
 *
 * [in]	         None
 *
 * [out]	 None
 *
 * [in/out] 	 None
 *
 * [Returns]:    None
 *******************************************************************************/
uint8_t BUTTON_read(void);

#endif /* BUTTON_H_ */
