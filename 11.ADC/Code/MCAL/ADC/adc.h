 /******************************************************************************
 *
 * [MODULE]: ADC
 *
 * [FILE NAME]: adc.h
 *
 * [DESCRIPTION]: Header file for the ATmega32 ADC driver
 *
 * [AUTHOR]: Ahmed Hassan
 *
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_

#include "../../Library/micro_config.h"
#include "../../Library/std_types.h"
#include "../../Library/common_macros.h"

 /*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/
 
typedef enum
{
	F_CPU_CLOCK, F_CPU_2, F_CPU_4, F_CPU_8, F_CPU_16, F_CPU_32, F_CPU_64, F_CPU_128
}ADC_Clock;

typedef enum
{
	EXTERNAL_REF = 0, VCC_REF = 1, INTERNAL_REF = 3
}ADC_ReferenceType;

typedef enum
{
	RIGHT,LEFT
}ADC_AdjustType;

typedef struct
{
	ADC_Clock clock;
	ADC_ReferenceType reference;
	ADC_AdjustType adjust;
}ADC_ConfigType;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/*
 * Description : Function to initialize the ADC driver
 * 		 - Set the required clock
 * 		 - Set the required reference
 * 		 - Set the required adjust
 * 		 - Enable the ADC Module
 * 		 - Enable the ADC Interrupt
 */
void ADC_init(const ADC_ConfigType * Config_Ptr);

/*
 * Description :
 * Function responsible for reading analog data from a certain ADC channel
 * and convert it to digital using the ADC driver
 */
void ADC_readChannel(uint8_t channel_num);

/*
 * Description: Function to set the Call Back function address
 */
void ADC_setCallBack(void(*a_ptr)(void));

/*
 * Description: 
 * Function to get the ADC Value after finishing conversion from analog to digital
 */
uint16_t ADC_getDigitalValue(void);

/*
 * Description: Function to disable the ADC driver
 */
void ADC_DeInit(void);

#endif /* ADC_H_ */
