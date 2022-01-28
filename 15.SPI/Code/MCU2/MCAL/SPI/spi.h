 /******************************************************************************
 *
 * [MODULE]: SPI
 *
 * [FILE NAME]: spi.h
 *
 * [DESCRIPTION]: Header file for the SPI AVR driver
 *
 * [AUTHOR]: Ahmed Hassan
 *
 *******************************************************************************/
 
#ifndef SPI_H_
#define SPI_H_

#include "../../Library/micro_config.h"
#include "../../Library/std_types.h"
#include "../../Library/common_macros.h"
#include "../../Library/atmega32.h"
#include "../../MCAL/DIO/dio.h"

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void SPI_initMaster(void); 
void SPI_initSlave(void);
void SPI_sendByte(const uint8_t au8_data);
uint8_t SPI_receiveByte(void);
void SPI_sendString(const uint8_t * aStr_message);
void SPI_receiveString(uint8_t * aStr_message);

#endif
