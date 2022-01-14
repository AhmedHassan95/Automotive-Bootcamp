 /******************************************************************************
 *
 * [MODULE]: Common - Platform Types Abstraction
 *
 * [FILE NAME]: std_types.h
 *
 * [DESCRIPTION]: Types for AVR
 *
 * [AUTHOR]: Ahmed Hassan
 *
 *******************************************************************************/

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

/* Boolean Data Type */
typedef unsigned char bool;

/* Boolean Values */
#ifndef FALSE
#define FALSE       (0u)
#endif
#ifndef TRUE
#define TRUE        (1u)
#endif

#define NULL_PTR    ((void*)0)

#define HIGH        (1u)						/* Standard HIGH */
#define LOW         (0u)						/* Standard LOW */

#define E_OK        (0u)						/* Function Return OK */
#define E_NOT_OK    (1u)						/* Function Return NOT OK */

typedef unsigned char         uint8_t;          /*           0 .. 255             */
typedef signed char           sint8_t;          /*        -128 .. +127            */
typedef unsigned short        uint16_;          /*           0 .. 65535           */
typedef signed short          sint16_;          /*      -32768 .. +32767          */
typedef unsigned long         uint32_t;         /*           0 .. 4294967295      */
typedef signed long           sint32_t;         /* -2147483648 .. +2147483647     */
typedef unsigned long long    uint64_t;         /*       0..18446744073709551615  */
typedef signed long long      sint64_t;
typedef float                 float32_t;
typedef double                float64_t;

#endif /* STD_TYPE_H_ */
