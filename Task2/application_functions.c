/******************************************************************************
 *
 * [MODULE]: APPLICATION
 *
 * [FILE NAME]: application_functions.h
 *
 * [DESCRIPTION]: Source file for the Application Functions
 *
 * [AUTHOR]: Ahmed Hassan
 *
 *******************************************************************************/

#include "application_functions.h"

/************************************************************************************
 *                                GLOBAL VARIABLES                                  *
 ************************************************************************************/

strNode_t * gstr_Stack = NULL;

/************************************************************************************
 *                                  FUNCTION DEFINITIONS                            *
 ************************************************************************************/

void push(uint8_t data)
{
	strNode_t *link = (strNode_t *)malloc(sizeof(strNode_t));

	link->data = data;
	link->next = gstr_Stack;

	gstr_Stack = link;
}

sint8_t pull(void)
{
	uint8_t data;
	strNode_t * delete_node = gstr_Stack;

	if(gstr_Stack == NULL)
	{
		return EMPTY;
	}

	data = gstr_Stack->data;
	gstr_Stack = gstr_Stack->next;
	free(delete_node);

	return data;
}

void print_Stack(void)
{
	strNode_t * ptr = gstr_Stack;

	printf("\n[HEAD] => ");

	while(ptr != NULL)
	{
		printf("%d => ", ptr->data);
		ptr = ptr->next;
	}

	printf("[NULL]\n");
}

/* Returns Balanced if character1 and character2 are matching left and right Brackets */
bool check_Matching(uint8_t character1, uint8_t character2)
{
	if (character1 == '(' && character2 == ')')
	{
		return BALANCED;
	}
	else if (character1 == '{' && character2 == '}')
	{
		return BALANCED;
	}
	else if (character1 == '[' && character2 == ']')
	{
		return BALANCED;
	}
	else
	{
		return UNBALANCED;
	}
}

/* Return Balanced if expression has balanced Brackets */
uint8_t * balanced_Parenthses(uint8_t * expression)
{
	uint8_t index = 0;
	uint8_t result;

	uint8_t * str1 = (uint8_t *)"Balanced";
	uint8_t * str2 = (uint8_t *)"Not Balanced";

	/* Traverse the given expression to check matching brackets */
	while (expression[index])
	{
		/* If the exp[i] is a starting bracket then push it */
		if (expression[index] == '{' || expression[index] == '(' || expression[index] == '[')
		{
			push(expression[index]);
		}

		/* If exp[i] is an ending bracket then pop from stack and check
           if the popped bracket is a matching pair */
		if (expression[index] == '}' || expression[index] == ')' || expression[index] == ']')
		{

			/* If we see an ending bracket without a pair then return false */
			if (gstr_Stack == NULL)
			{
				return str2;	/* Not balanced */
			}

			result = check_Matching(pull(), expression[index]);

			/* Pop the stack element from stack, if it is not a pair bracket of
			   uint8 character then there is a mismatch. This happens for expressions like {(}) */
			if (!result)
			{
				return str2;	/* Not balanced */
			}
		}
		index++;
	}

	/* If there is something left in expression then there is a starting
	   bracket without a closing bracket */
	if (gstr_Stack == NULL)
	{
		return str1; /* Balanced */
	}
	else
	{
		return str2; /* Not balanced */
	}
}
