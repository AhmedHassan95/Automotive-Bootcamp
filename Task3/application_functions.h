/******************************************************************************
 *
 * [MODULE]: APPLICATION
 *
 * [FILE NAME]: application_functions.h
 *
 * [DESCRIPTION]: Header file for the Application Functions
 *
 * [AUTHOR]: Ahmed Hassan
 *
 *******************************************************************************/

#ifndef APPLICATION_FUNCTIONS_H_
#define APPLICATION_FUNCTIONS_H_

#include <stdio.h>
#include "std_types.h"
#define ARR_SIZE    15
#define SORTED      1
#define UNSORTED    0
#define NOT_FOUND   0

/************************************************************************************
 *                                FUNCTION PROTOTYPES                               *
 ************************************************************************************/

sint8 binarySearch(uint32 * arr, uint8 arr_size, uint32 number);
void bubbleSort(uint32 * arr);
uint8 arraySortedOrNot(uint32 * arr, uint8 arr_size);

#endif /* APPLICATION_FUNCTIONS_H_ */
