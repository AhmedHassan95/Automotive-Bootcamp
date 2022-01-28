 /***********************************************************************************
 *
 * [MODULE]: SPI
 *
 * [FILE NAME]: spi.c
 *
 * [DESCRIPTION]: Source file for the SPI AVR driver
 *
 * [AUTHOR]: Ahmed Hassan
 *
 ************************************************************************************/
 
#include "spi.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
void SPI_initMaster(void) 
{
	/******** Configure SPI Master Pins *********
	 * SS(PB4)   --> Output
	 * MOSI(PB5) --> Output 
	 * MISO(PB6) --> Input
	 * SCK(PB7)  --> Output
	 ********************************************/
	DIO_setPinDirection(DIO_PORTB, PIN_4, OUTPUT);
	DIO_setPinDirection(DIO_PORTB, PIN_5, OUTPUT);
	DIO_setPinDirection(DIO_PORTB, PIN_6, INPUT);
	DIO_setPinDirection(DIO_PORTB, PIN_7, OUTPUT);
	
	SPCR = (1<<SPE) | (1<<MSTR); /* Enable SPI + Enable Master + Choose SPI clock = Fosc/4 */
}

void SPI_initSlave(void)
{ 
	/******** Configure SPI Slave Pins *********
	 * SS(PB4)   --> Input
	 * MOSI(PB5) --> Input
	 * MISO(PB6) --> Output
	 * SCK(PB7)  --> Input
	 ********************************************/
	DIO_setPinDirection(DIO_PORTB, PIN_4, INPUT);
	DIO_setPinDirection(DIO_PORTB, PIN_5, INPUT);
	DIO_setPinDirection(DIO_PORTB, PIN_6, OUTPUT);
	DIO_setPinDirection(DIO_PORTB, PIN_7, INPUT);

	SPCR = (1<<SPE); /* Just enable SPI + Choose SPI clock = Fosc/4 */
}

void SPI_sendByte(const uint8_t au8_data)
{
	SPDR = au8_data; /* Send data by SPI */
	while(BIT_IS_CLEAR(SPSR,SPIF)){} /* Wait until SPI interrupt flag=1 (data is sent correctly) */
}

uint8_t SPI_receiveByte(void)
{
   while(BIT_IS_CLEAR(SPSR,SPIF)){} /* Wait until SPI interrupt flag=1(data is receive correctly) */
   return SPDR; /* Return the received byte from SPI data register */
}

void SPI_sendString(const uint8_t * aStr_message)
{
	uint8_t i = 0;

	while(aStr_message[i] != '\0')
	{
		SPI_sendByte(aStr_message[i]);
		i++;
	}
}

void SPI_receiveString(uint8_t * aStr_message)
{
	uint8_t i = 0;

	aStr_message[i] = SPI_receiveByte();
	while(aStr_message[i] != '\r')
	{
		i++;
		aStr_message[i] = SPI_receiveByte();
	}
	aStr_message[i] = '\r';
	i++;
	aStr_message[i] = '\0';
}
