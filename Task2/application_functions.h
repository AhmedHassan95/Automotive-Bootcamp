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
#include <stdlib.h>
#include "std_types.h"

#define UNBALANCED 0
#define BALANCED   1
#define EMPTY     -1

/******************************************************************************
 *                         Types DECLARATION                                  *
 ******************************************************************************/

typedef struct strNode_t
{
	uint8_t data;
	struct strNode_t * next;
}strNode_t;

/************************************************************************************
 *                                FUNCTION PROTOTYPES                               *
 ************************************************************************************/

void push(uint8_t data);
sint8_t pull(void);
void print_Stack(void);
uint8_t * balanced_Parenthses(uint8_t * expression);
bool check_Matching(uint8_t character1, uint8_t character2);

#endif /* APPLICATION_FUNCTIONS_H_ */
