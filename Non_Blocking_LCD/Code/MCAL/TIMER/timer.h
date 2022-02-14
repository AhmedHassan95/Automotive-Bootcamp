/******************************************************************************
 *
 * [MODULE]: TIMER
 *
 * [FILE NAME]: timer.h
 *
 * [DESCRIPTION]: Header file for the TIMER AVR driver
 *
 * [AUTHOR]: Ahmed Hassan
 *
 ******************************************************************************/

#ifndef TIMER_H_
#define TIMER_H_

#include "../../Library/micro_config.h"
#include "../../Library/std_types.h"
#include "../../Library/common_macros.h"
#include "../../Library/atmega32.h"

/******************************************************************************
 *                         Types Declaration                                  *
 ******************************************************************************/

typedef enum
{
	TIMER_E_PARAM_VALID, TIMER_E_PARAM_INVALID_ID,
	TIMER_E_PARAM_INVALID_MODE, TIMER_E_PARAM_POINTER
}enuTIMER_E_STATE_t;

typedef enum
{
	TIMER_0, TIMER_1, TIMER_2
}enuTIMER_ID_t;

typedef enum
{
	NORMAL, COMPARE
}enuTIMER_ModeType_t;

typedef enum
{
	T0_NO_CLOCK = 0, T0_F_CPU_CLOCK, T0_F_CPU_8, T0_F_CPU_64, T0_F_CPU_256, T0_F_CPU_1024,
	T1_NO_CLOCK = 0, T1_F_CPU_CLOCK, T1_F_CPU_8, T1_F_CPU_64, T1_F_CPU_256, T1_F_CPU_1024,
	T2_NO_CLOCK = 0, T2_F_CPU_CLOCK, T2_F_CPU_8, T2_F_CPU_32, T2_F_CPU_64 ,  T2_F_CPU_128,
	T2_F_CPU_256, T2_F_CPU_1024
}enuTIMER_Clock_t;

typedef struct
{
	uint16_t intialValue;
	uint16_t compareValue;
	enuTIMER_ID_t timer_ID;
	enuTIMER_ModeType_t timer_Mode;
}strTIMER_ConfigType_t;

/******************************************************************************
 *                          Functions Prototypes                              *
 ******************************************************************************/

/******************************************************************************
 * [Function Name]: TIMER_init
 *
 * [Description]: Function to initialize the TIMER Driver
 *		  - Decide TIMER ID (TIMER0, TIMER1, TIMER2)
 *		  - Decide TIMER Mode (NORMAL, COMPARE)
 * 		  - Insert the initial value to start counting from it
 * 		  - Insert the compare match value if use this mode (CTC Mode)
 * 		  - Enable TIMER Interrupt
 *
 * [Args]:	  Config_Ptr
 *
 * [in]		  Config_Ptr: Pointer to TIMER Configuration Structure
 *
 * [out]	  None
 *
 * [in/out]	  None
 *
 * [Returns]:     Error state
 ******************************************************************************/
enuTIMER_E_STATE_t TIMER_init(const strTIMER_ConfigType_t * Config_Ptr);

/******************************************************************************
 * [Function Name]: TIMER_setCallBack
 *
 * [Description]: Function to set the Call Back function address
 *
 * [Args]:	  a_Ptr, enu_timerID
 *
 * [in]		  a_Ptr: Pointer to function (Receive to the address of application function)
 * 		         enu_timerID: Enumerator to TIMER ID
 *
 * [out]	  None
 *
 * [in/out]	  None
 *
 * [Returns]:     Error State
 ******************************************************************************/
enuTIMER_E_STATE_t TIMER_setCallBack(void(*a_ptr)(void), const enuTIMER_ID_t enu_timerID);

/******************************************************************************
 * [Function Name]: TIMER_start
 *
 * [Description]: Function to enable the timer Driver
 *
 * [Args]:	  enu_timerID, enu_timerClock
 *
 * [in]		  enu_timerID: Enumerator to TIMER ID
 * 		  enu_timerClock: Enumerator to TIMER CLOCK
 *
 * [out]	  None
 *
 * [in/out]	  None
 *
 * [Returns]:     Error state
 ******************************************************************************/
enuTIMER_E_STATE_t TIMER_start(const enuTIMER_ID_t enu_timerID, const enuTIMER_Clock_t enu_timerClock);

/******************************************************************************
 * [Function Name]: TIMER_stop
 *
 * [Description]: Function to stop the TIMER from counting
 *
 * [Args]:	  enu_timerID
 *
 * [in]		  enu_timerID: Enumerator to TIMER ID
 *
 * [out]	  None
 *
 * [in/out]	  None
 *
 * [Returns]:     Error state
 ******************************************************************************/
enuTIMER_E_STATE_t TIMER_stop(const enuTIMER_ID_t enu_timerID);

/******************************************************************************
 * [Function Name]: TIMER_DeInit
 *
 * [Description]: Function to disable the TIMER Driver
 *
 * [Args]:	  enu_timerID
 *
 * [in]		  enu_timerID: Enumerator to TIMER ID
 *
 * [out]	  None
 *
 * [in/out]	  None
 *
 * [Returns]:     Error state
 ******************************************************************************/
enuTIMER_E_STATE_t TIMER_DeInit(const enuTIMER_ID_t enu_timerID);

#endif /* TIMER_H_ */
