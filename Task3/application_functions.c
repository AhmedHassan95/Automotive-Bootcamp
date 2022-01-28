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
 *                                  FUNCTION DEFINITIONS                            *
 ************************************************************************************/

sint8_t binary_Search(uint32_t * arr, uint8_t size, uint32_t number)
{
	uint8_t mid;
	uint8_t left = 0;
	uint8_t right = size-1;
	uint8_t check_sortedOrNot;

    check_sortedOrNot = array_SortedOrNot(arr, size);

	/* Check first if the array is sorted or not */
    if(check_sortedOrNot == UNSORTED)
    {
        bubble_Sort(arr);
    }

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

	return NOT_FOUND;	/* Number not found in the array */
}

void bubble_Sort(uint32_t * arr)
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

uint8_t array_SortedOrNot(uint32_t * arr, uint8_t arr_size)
{
    /* Array has one or no element or the rest are already checked and approved */
    if (arr_size == 1 || arr_size == 0)
    {
        return SORTED;
    }

    /* Unsorted pair found (Equal values allowed) */
    if (arr[arr_size - 1] < arr[arr_size - 2])
    {
        return UNSORTED;;
    }

    /* Last pair was sorted Keep on checking */
    return array_SortedOrNot(arr, arr_size - 1);
}
