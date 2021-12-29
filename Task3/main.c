/************************************************************************************
 *
 * [FILE NAME] : main.c
 *
 * [AUTHOR(S)] : Ahmed Hassan.
 *
 * [DATE CREATED] : DEC 22, 2021
 *
 * [DESCRIPTION] : This Project is to design a binary search algorithm
 *
 ************************************************************************************/

 #include "application_functions.h"

/************************************************************************************
 *                                  MAIN FUNCTION                                   *
 ************************************************************************************/

/* Driver code */
int main(void)
{
	uint32 arr[15] = {8, 6, 1, 7, 4, 5, 3, 2, 9, 14, 12, 13, 11, 10, 15};
	sint8 result;

	result = binarySearch(arr, ARR_SIZE, 14);

	if(result != NOT_FOUND)
	{
		printf("\nThe Number is found in the index : %d\n", result);
	}
	else
	{
		printf("\nThe Number is not found in the array \n");
	}

	return 0;
}
