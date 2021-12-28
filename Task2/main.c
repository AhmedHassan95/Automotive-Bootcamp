/************************************************************************************
 *
 * [FILE NAME] : main.c
 *
 * [AUTHOR(S)] : Ahmed Hassan.
 *
 * [DATE CREATED] : DEC 22, 2021
 *
 * [DESCRIPTION] : This Project is to design a stack to check for balanced parentheses
 *
 ************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "std_types.h"

struct node
{
	uint16 data;
	struct node * next;
};

struct node * stack = NULL;

/************************************************************************************
 *                                FUNCTION PROTOTYPES                               *
 ************************************************************************************/

void push(uint16 data);
uint16 pull(void);
void printStack(void);
uint8 * balancedParenthses(uint8 * expression);
bool check_matching(uint8 character1, uint8 character2);

/************************************************************************************
 *                                  MAIN FUNCTION                                   *
 ************************************************************************************/

/* Driver code */
int main(void)
{
	uint8 exp[100] = "{1+(2+5)+2}";
	
	uint8 * ptr = balancedParenthses(exp);
	
	printf("\n%s\n", ptr);

	return 0;
}

/************************************************************************************
 *                                  FUNCTION DEFINITIONS                            *
 ************************************************************************************/

void push(uint16 data)
{
	struct node *link = (struct node *)malloc(sizeof(struct node));

	link->data = data;
	link->next = stack;

	stack = link;
}

uint16 pull(void)
{
	uint16 data;
	struct node * delete_node = stack;

	if(stack == NULL)
	{
		return -1;
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
		return 1;
	}
	else if (character1 == '{' && character2 == '}')
	{
		return 1;
	}
	else if (character1 == '[' && character2 == ']')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/* Return 1 if expression has balanced Brackets */
uint8 * balancedParenthses(uint8 * expression)
{
	uint16 i = 0;
	uint8 result;
	
	uint8 * str1 = "Balanced";
	uint8 * str2 = "Not Balanced";
	
	/* Traverse the given expression to check matching brackets */
	while (expression[i])
	{
		/* If the exp[i] is a starting bracket then push it */
		if (expression[i] == '{' || expression[i] == '(' || expression[i] == '[')
		{
			push(expression[i]);
		}

		/* If exp[i] is an ending bracket then pop from stack and check 
           if the popped bracket is a matching pair */
		if (expression[i] == '}' || expression[i] == ')' || expression[i] == ']')
		{
			
			/* If we see an ending bracket without a pair then return false */
			if (stack == NULL)
			{	
				return str2;	/* Not balanced */
			}

			result = check_matching(pull(), expression[i]);
			
			/* Pop the stack element from stack, if it is not a pair bracket of
			   uint8acter then there is a mismatch. This happens for expressions like {(}) */
			if (!result)
			{	
				return str2;	/* Not balanced */
			}
		}
		i++;
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
