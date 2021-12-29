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

struct node * stack = NULL;

/************************************************************************************
 *                                  FUNCTION DEFINITIONS                            *
 ************************************************************************************/

void push(uint8 data)
{
	struct node *link = (struct node *)malloc(sizeof(struct node));

	link->data = data;
	link->next = stack;

	stack = link;
}

sint8 pull(void)
{
	uint8 data;
	struct node * delete_node = stack;

	if(stack == NULL)
	{
		return EMPTY;
	}

	data = stack->data;
	stack = stack->next;
	free(delete_node);

	return data;
}

void printStack(void)
{
	struct node * ptr = stack;

	printf("\n[HEAD] => ");

	while(ptr != NULL)
	{
		printf("%d => ", ptr->data);
		ptr = ptr->next;
	}

	printf("[NULL]\n");
}

/* Returns 1 if character1 and character2 are matching left and right Brackets */
bool check_matching(uint8 character1, uint8 character2)
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
uint8 * balancedParenthses(uint8 * expression)
{
	uint8 index = 0;
	uint8 result;

	uint8 * str1 = (uint8 *)"Balanced";
	uint8 * str2 = (uint8 *)"Not Balanced";

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
			if (stack == NULL)
			{
				return str2;	/* Not balanced */
			}

			result = check_matching(pull(), expression[index]);

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
	if (stack == NULL)
	{
		return str1; /* Balanced */
	}
	else
	{
		return str2; /* Not balanced */
	}
}
