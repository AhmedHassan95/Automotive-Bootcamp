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

struct node
{
	uint8 data;
	struct node * next;
};

/************************************************************************************
 *                                FUNCTION PROTOTYPES                               *
 ************************************************************************************/

void push(uint8 data);
sint8 pull(void);
void printStack(void);
uint8 * balancedParenthses(uint8 * expression);
bool check_matching(uint8 character1, uint8 character2);

#endif /* APPLICATION_FUNCTIONS_H_ */
