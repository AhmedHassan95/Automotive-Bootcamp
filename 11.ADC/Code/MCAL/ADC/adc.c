 /******************************************************************************
 *
 * [MODULE]: ADC
 *
 * [FILE NAME]: adc.c
 *
 * [DESCRIPTION]: Source file for the ATmega32 ADC driver
 *
 * [AUTHOR]: Ahmed Hassan
 *
 *******************************************************************************/

#include "adc.h"

/*******************************************************************************
 *                          Global Variables                                   *
 *******************************************************************************/
 
/* Global variables to hold the address of the call back function in the application */
static volatile void (*g_callBackPtr)(void) = NULL_PTR;

/*******************************************************************************
 *                       Interrupt Service Routines                            *
 *******************************************************************************/

ISR(ADC_vect)
{
	if(g_callBackPtr != NULL_PTR)
	{
		/* Call the Call Back function in the application after the edge is detected */
		(*g_callBackPtr)(); /* Another method to call the function using pointer to function g_callBackPtr(); */
	}
}

/*******************************************************************************
 *                          Functions Definitions                              *
 *******************************************************************************/
/*
 * Description : Function to initialize the ADC driver
 * 					- Set the required clock
 * 					- Set the required reference
 * 					- Set the required adjust
 * 					- Enable the ADC Module
 * 					- Enable the ADC Interrupt
 */
void ADC_init(const ADC_ConfigType * Config_Ptr)
{
	/*
	 * Insert the first five bits in ADMUX Register (MUX4:0 = 00000) to choose 
	 * channel 0 as initialization
	*/
	ADMUX = (ADMUX & 0xE0);
	
	/*
	 * Insert the required reference value in the last two bits (REFS1,REFS0)
	 * of ADMUX Register
	 */
	ADMUX = (ADMUX & 0x3F) | ((Config_Ptr->reference)<<6);
	
	/*
     * Insert the required adjust type in ADLAR bit in ADMUX Register
	 */
	ADMUX = (ADMUX & 0xDF) | ((Config_Ptr->adjust)<<5);
	 
	 /*
	 * Insert the required clock value in the first three bits (ADPS0, ADPS1 and ADPS2)
	 * of ADCSRA Register
	 */
	ADCSRA = (ADCSRA & 0xF8) | (Config_Ptr->clock); 
	
	/* 
	 * ADEN   = 1 Enable ADC
	 * ADIE   = 1 Enable ADC Interrupt
	 */
	ADCSRA = (1<<ADEN) | (1<<ADIE);
}

/*
 * Description :
 * Function responsible for reading analog data from a certain ADC channel
 * and convert it to digital using the ADC driver
 */
void ADC_readChannel(uint8_t channel_num)
{
	channel_num &= 0x07; /* Channel number must be from 0 --> 7 */
	ADMUX &= 0xE0; /* Clear first 5 bits in the ADMUX (channel number MUX4:0 bits) before set the required channel */
	ADMUX = ADMUX | channel_num; /* Choose the correct channel by setting the channel number in MUX4:0 bits */
	SET_BIT(ADCSRA,ADSC); /* Start conversion write '1' to ADSC */
}

/* 
 * Description: Function to set the Call Back function address 
 */
void ADC_setCallBack(void(*a_ptr)(void))
{
	/* Save the address of the Call back function in a global variable */
	g_callBackPtr = a_ptr;
}

/*
 * Description: 
 * Function to get the ADC Value after finishing conversion from analog to digital
 */
uint16_t ADC_getDigitalValue(void)
{
	return ADC;
}

/* 
 * Description: Function to disable the ADC drive
 */
void ADC_DeInit(void)
{	
	/* Clear All ADC Registers, and Disable the ACD Interrupt */
	ADMUX = 0;
	ADCSRA = 0;
}
