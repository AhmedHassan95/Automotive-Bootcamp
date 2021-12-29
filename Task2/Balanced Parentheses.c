/************************************************************************************
 *
 * [FILE NAME] : Balanced_Parentheses.c
 *
 * [AUTHOR(S)] : Ahmed Hassan.
 *
 * [DATE CREATED] : DEC 22, 2021
 *
 * [DESCRIPTION] : This Project is to design a stack to check for balanced parentheses
 *
 ************************************************************************************/

#include "application_functions.h"

/************************************************************************************
 *                                  MAIN FUNCTION                                   *
 ************************************************************************************/

/* Driver code */
int main(void)
{
	uint8_t exp[100] = "{({2+10}}*11}"; //"(2*3+(5/2+(4*3)))";

	uint8_t * ptr = balanced_Parenthses(exp);

	printf("\n%s\n", ptr);

	return 0;
}
