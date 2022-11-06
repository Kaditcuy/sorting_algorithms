#include "sort.h"

/**
* bubble_sort - sots an array of integers using bubble
*				 sort algorithim
* @array: Array of integers to print
* @size: Size of Array
*
* Return : Nothing
*/
void bubble_sort(int *array, size_t size)
{
	size_t i, temp, j;

	if (size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
