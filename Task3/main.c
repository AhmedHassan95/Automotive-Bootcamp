/************************************************************************************
 *
 * [FILE NAME] : main.c
 *
 * [AUTHOR(S)] : Ahmed Hassan.
 *
 * [DATE CREATED] :	DEC 22, 2021
 *
 * [DESCRIPTION] :	This Project is to design a binary search algorithm  
 *
 ************************************************************************************/

#include <stdio.h>
#include "std_types.h"
#define ARR_SIZE 15

/************************************************************************************
 *                                FUNCTION PROTOTYPES                               *
 ************************************************************************************/

uint8 binarySearch(uint32 * arr, uint8 size, uint32 number);
static void bubbleSort(uint32 * arr);


/************************************************************************************
 *                                  MAIN FUNCTION                                   *
 ************************************************************************************/

/* Driver code */
int main(void)
{
	uint32 arr[15] = {8, 6, 1, 7, 4, 5, 3, 2, 9, 14, 12, 13, 11, 10, 15}; 
	uint8 result;
	
	result = binarySearch(arr, ARR_SIZE, 14);
	
	if(result != -1)
	{
		printf("\nThe Number is found in the index : %d\n", result);
	}
	else 
	{
		printf("\nThe Number is not found in the array \n");
	}

	return 0;
}

/************************************************************************************
 *                                  FUNCTION DEFINITIONS                            *
 ************************************************************************************/

uint8 binarySearch(uint32 * arr, uint8 size, uint32 number)
{
	bubbleSort(arr);	/* Sort the array first */
	uint8 mid;
	uint8 left = 0;
	uint8 right = size-1;
	
	
	while(left <= right)
	{
		mid = left + ((right-left)/2);
		
		if(arr[mid] == number)
		{
			return mid;
		}
		else if(arr[mid] < number)
		{
			left = mid+1;
		}
		else if(arr[mid] > number)
		{
			right = mid-1;
		}
	}
	return -1;	/* Number not found in the array */
}


static void bubbleSort(uint32 * arr)
{
	int i, j, temp;
	
	for(i = 0; i < ARR_SIZE-1; i++)
	{
		for(j = 0; j < ARR_SIZE-i-1; j++)
		{
			if(arr[j] > arr[j+1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}