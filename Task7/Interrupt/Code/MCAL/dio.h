/******************************************************************************
 *
 * [MODULE]: DIO
 *
 * [FILE NAME]: dio.h
 *
 * [DESCRIPTION]: Header file for the DIO AVR driver
 *
 * [AUTHOR]: Ahmed Hassan
 *
 ******************************************************************************/

#ifndef DIO_H_
#define DIO_H_

#include "../Includes/micro_config.h"
#include "../Includes/std_types.h"
#include "../Includes/common_macros.h"

#define INPUT_PORT  0x00
#define OUTPUT_PORT 0xFF

/******************************************************************************
 *                         Types Declaration                                  *
 ******************************************************************************/

typedef enum
{
	DIO_E_PARAM_VALID, DIO_E_PARAM_INVALID_PORT_ID, DIO_E_PARAM_INVALID_PIN_ID,
	DIO_E_PARAM_INVALID_PIN_DIR, DIO_E_PARAM_INVALID_PORT_DIR, DIO_E_PARAM_POINTER
}enuDIO_E_STATE_t;

typedef enum
{
	DIO_PORTA, DIO_PORTB, DIO_PORTC, DIO_PORTD
}enuDIO_PortId_t;

typedef enum
{
	PIN_0, PIN_1, PIN_2, PIN_3, PIN_4, PIN_5, PIN_6, PIN_7
}enuDIO_PinId_t;

typedef enum
{
	INPUT, OUTPUT
}enuDIO_DirectionType_t;

/******************************************************************************
 *                          Functions Prototypes                              *
 ******************************************************************************/

/******************************************************************************
 * [Function Name]: DIO_setPortDirection
 *
 * [Description]: Function to set the direction of all pins in the port (INPUT, OUTPUT)
 *
 * [Args]:	  enu_portID, enu_portDirection
 *
 * [in]		  enu_portID: Enumerator to DIO port ID
 * 		  enu_portDirection: Enumerator to DIO port direction
 *
 * [out]	  None
 *
 * [in/out]	  None
 *
 * [Returns]:     Error state
 ******************************************************************************/
enuDIO_E_STATE_t DIO_setPortDirection(enuDIO_PortId_t enu_portID, enuDIO_DirectionType_t enu_portDirection);

/******************************************************************************
 * [Function Name]: DIO_setPinDirection
 *
 * [Description]: Function to set the direction of a certain pin in a certain port
 *
 * [Args]:	  enu_portID, enu_pinID, enu_pinDirection
 *
 * [in]		  enu_portID: Enumerator to DIO port ID
 * 		  enu_pinID: Enumerator to DIO pin ID
 * 		  enu_portDirection: Enumerator to DIO pin direction
 *
 * [out]	  None
 *
 * [in/out]	  None
 *
 * [Returns]:     Error State
 ******************************************************************************/
enuDIO_E_STATE_t DIO_setPinDirection(enuDIO_PortId_t enu_portID , enuDIO_PinId_t enu_pinID,
				     enuDIO_DirectionType_t enu_pinDirection);

/******************************************************************************
 * [Function Name]: DIO_writePort
 *
 * [Description]: Function to write (HIGH, LOW) in a certain port
 *
 * [Args]:	  enu_portID, au8_portValue
 *
 * [in]		  enu_portID: Enumerator to DIO port ID
 *	          au8_portValue: Unsigned character value to be written in the port
 *
 * [out]	  None
 *
 * [in/out]	  None
 *
 * [Returns]:     Error State
 ******************************************************************************/
enuDIO_E_STATE_t DIO_writePort(enuDIO_PortId_t enu_portID, uint8_t au8_portValue);

/******************************************************************************
 * [Function Name]: DIO_writePin
 *
 * [Description]: Function to write (HIGH, LOW) in a certain pin in a certain port
 *
 * [Args]:	  enu_portID, pinID, au8_pinValue
 *
 * [in]		  enu_portID: Enumerator to DIO port ID
 *		  enu_pinID: Enumerator to DIO pin ID
 *		  au8_pinValue: Unsigned character value to be written in the pin
 *
 * [out]	  None
 *
 * [in/out]	  None
 *
 * [Returns]:     Error State
 ******************************************************************************/
enuDIO_E_STATE_t DIO_writePin(enuDIO_PortId_t enu_portID, enuDIO_PinId_t enu_pinID, uint8_t au8_pinValue);

/******************************************************************************
 * [Function Name]: DIO_readPort
 *
 * [Description]: Function to read the value of the certain port
 *
 * [Args]:	  enu_portID, ptr_portState
 *
 * [in]		  enu_portID: Enumerator to DIO port ID
 *		  enu_portState: Pointer to Unsigned character value to return the
 *				 state of the port in it
 *
 * [out]	  None
 *
 * [in/out]	  None
 *
 * [Returns]:     Error State
 ******************************************************************************/
enuDIO_E_STATE_t DIO_readPort(enuDIO_PortId_t enu_portID, uint8_t * ptr_portState);

/******************************************************************************
 * [Function Name]: DIO_readPin
 *
 * [Description]: Function to read the value of the certain pin
 *
 * [Args]:	  enu_portID, enu_pinID, ptr_pinState
 *
 * [in]		  enu_portID: Enumerator to DIO port ID
 *		  enu_pinID: Enumerator to DIO pin ID
 *		  ptr_pinState: Pointer to Unsigned character value to return the
 *				state of the pin in it
 *
 * [out]	  None
 *
 * [in/out]	  None
 *
 * [Returns]:     Error State
 ******************************************************************************/
enuDIO_E_STATE_t DIO_readPin(enuDIO_PortId_t enu_portID, enuDIO_PinId_t enu_pinID, uint8_t * ptr_pinState);

/******************************************************************************
 * [Function Name]: DIO_TogglePin
 *
 * [Description]: Function to toggle a pin
 *
 * [Args]:	  enu_portID, enu_pinID
 *
 * [in]		  enu_portID: Enumerator to DIO port ID
 *		  enu_pinID: Enumerator to DIO pin ID
 *
 * [out]	  None
 *
 * [in/out]	  None
 *
 * [Returns]:     Error State
 ******************************************************************************/
enuDIO_E_STATE_t DIO_TogglePin(enuDIO_PortId_t enu_portID, enuDIO_PinId_t enu_pinID);

#endif /* DIO_H_ */
