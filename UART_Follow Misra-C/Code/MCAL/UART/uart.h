 /******************************************************************************
 *
 * [MODULE]: UART
 *
 * [FILE NAME]: uart.h
 *
 * [DESCRIPTION]: Header file for the UART AVR driver
 *
 * [AUTHOR]: Ahmed Hassan
 *
 *******************************************************************************/

#ifndef UART_H_
#define UART_H_

#include "../../Library/std_types.h"
#include "../../Library/common_macros.h"
#include "../../Library/micro_config.h"

/*******************************************************************************
 *                            		Macros                                 *
 *******************************************************************************/

#define MODE_MASK  			(0xFD)

#define NINE_DATA_BITS_MASK 		(0xFB)
#define NINE_DATA_BITS_SHIFT 		(0x04)

#define DATA_BITS_MASK 			(0xF9)
#define DATA_BITS_SHIFT 		(0x03)

#define PARITY_MASK  			(0xCF)
#define PARITY_SHIFT  			(4UL)

#define STOP_MASK 			(0xF7)
#define STOP_SHIFT  			(3UL)

#define NORMAL_SPEED_DIVISOR		(16UL)
#define DOUBLE_SPEED_DIVISOR		(8UL)
#define SPEED_SHIFT			(8UL)

#define USCRA_INITIAL_VALUE 		(0x20)
#define USCRC_INITIAL_VALUE  		(0x86)

 /******************************************************************************
 *                            Types Declaration                                *
 *******************************************************************************/

typedef enum
{
	BPS_100 = 100, BPS_200 = 200, BPS_300 = 300, BPS_1200 = 1200, BPS_2400 = 2400, BPS_4800 = 4800,
	BPS_9600 = 9600, BPS_19200 = 19200, BPS_38400 = 38400, BPS_57600 = 57600, BPS_115200 = 115200
}enuUART_BaudRate_t;

typedef enum
{
	NORMAL_SPEED, DOUBLE_SPEED
}enuUART_ModeType_t;

typedef enum
{
	FIVE_BITS, SIX_BITS, SEVEN_BITS, EIGHT_BITS, NINE_BITS = 7
}enuUART_NumberOfDataBits_t;

typedef enum
{
	DISABLED = 0, EVEN = 2, ODD = 3
}enuUART_ParityType_t;

typedef enum
{
	ONE_BIT, TWO_BITS
}enuUART_StopBit_t;

typedef struct
{
	enuUART_BaudRate_t uart_BaudRate;
	enuUART_ModeType_t uart_Mode;
	enuUART_NumberOfDataBits_t uart_DataBits;
	enuUART_ParityType_t uart_Parity;
	enuUART_StopBit_t uart_StopBit;
}UART_ConfigType;

/*******************************************************************************
 *                          Functions Prototypes                               *
 *******************************************************************************/

/*******************************************************************************
 * [Function Name]: uart_init
 *
 * [Description]: Function to Initialize the UART Driver
 *		   - Decide UART Mode (Normal, Double Speed)
 * 		   - Decide Baud Rate of the UART Module (100 BPS, 200 BPS, 300 BPS, ..)
 * 		   - Decide Number of Data Bits to be transmitted or Received (5,6,7,8 or 9)
 * 		   - Decide UART Parity Type (Disable, Even, Odd)
 * 		   - Decide Number of Stop Bits (One, Two)
 * 		   - Enable Transmitter & Receiver of the UART Module
 *
 * [Args]:	  Config_Ptr
 *
 * [in]		  Config_Ptr: Pointer to UART Configuration Structure
 *
 * [out]	  None
 *
 * [in/out]	  None
 *
 * [Returns]:     None
 *******************************************************************************/
void uart_init(const UART_ConfigType * Config_Ptr);

/*******************************************************************************
 * [Function Name]: uart_sendByte
 *
 * [Description]: Function responsible for sending 1 Byte through UART driver
 *
 * [Args]:	  au8_data
 *
 * [in]		  au8_data: Unsigned Character (Byte need to be sent through the UART)
 *
 * [out]	  None
 *
 * [in/out]	  None
 *
 * [Returns]:     None
 *******************************************************************************/
void uart_sendByte(const uint8_t au8_data);

/*******************************************************************************
 * [Function Name]: uart_recieveByte
 *
 * [Description]: Function responsible for receiving 1 Byte through UART driver
 *
 * [Args]:	  None
 *
 * [in]		  None
 *
 * [out]	  Unsigned Character
 *
 * [in/out]	  None
 *
 * [Returns]:     The Byte that received through the UART
 *******************************************************************************/
uint8_t uart_recieveByte(void);

/*******************************************************************************
 * [Function Name]: uart_sendString
 *
 * [Description]: Function responsible for sending a string (more than 1 character)
 * 		  through UART driver
 *
 * [Args]:	  aStr_message
 *
 * [in]		  aStr_message: Pointer to Unsigned Character (String need to be sent through the UART)
 *
 * [out]	  None
 *
 * [in/out]	  None
 *
 * [Returns]:     None
 *******************************************************************************/
void uart_sendString(const uint8_t * aStr_message);

/*******************************************************************************
 * [Function Name]: uart_receiveString
 *
 * [Description]: Function responsible for receiving a string (more than 1 character)
 * 		  until receiving a special character ('#') through UART driver
 *
 * [Args]:	  aStr_message
 *
 * [in]		  aStr_message: Pointer to Unsigned Character (String need to be received through the UART)
 *
 * [out]	  None
 *
 * [in/out]	  None
 *
 * [Returns]:     None
 *******************************************************************************/
void uart_receiveString(uint8_t * aStr_message);

/*******************************************************************************
 * [Function Name]: uart_setParityType
 *
 * [Description]: Function to set the required Parity Type
 *
 * [Args]:	  enu_parityType
 *
 * [in]		  enu_parityType: Enumerator to UART Parity Type
 *
 * [out]	  None
 *
 * [in/out]	  None
 *
 * [Returns]:     None
 *******************************************************************************/
void uart_setParityType(const enuUART_ParityType_t enu_parityType);

/*******************************************************************************
 * [Function Name]: uart_setStopBit
 *
 * [Description]: Function to set the required Stop bit(s)
 *
 * [Args]:	  enu_stopBit
 *
 * [in]		  enu_stopBit: Enumerator to UART Stop Bit
 *
 * [out]	  None
 *
 * [in/out]	  None
 *
 * [Returns]:     None
 *******************************************************************************/
void uart_setStopBit(const enuUART_StopBit_t enu_stopBit);

/*******************************************************************************
 * [Function Name]: uart_DeInit
 *
 * [Description]: Function to disable the UART Driver
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
void uart_DeInit(void);

#endif /* UART_H_ */
