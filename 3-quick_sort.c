#include "sort.h"

/**
* quick_sort - Sorts using quicksort algorithim
* @array: Array of elements to sort
* @size: size of array
*
* Return: NULL
*/
void quick_sort(int *array, size_t size)
{
	lomuto_qsort(array, 0, size - 1, size);
}

/**
* lomuto_qsort - sorts using lomuto quick sort
* @array: Array of elements to sort
* @start: first index of array
* @end: Last index of array
* @size: size of array
*
* Return: NULL
*/
void lomuto_qsort(int *array, int start, int end, size_t size)
{
	int pIndex = 0;

	if (start < end)
	{
		pIndex = partition(array, start, end, size);
		lomuto_qsort(array, start, pIndex - 1, size);
		lomuto_qsort(array, pIndex + 1, end, size);
	}
}
/**
* partition - Divides an array of elements to sort
* @array: Array of elements to sort
* @start: First index of array
* @end: last index of array
* @size: size of array
*
* Return: partition index
*/
int partition(int *array, int start, int end, size_t size)
{
	int pivot = array[end];
	int pIndex = start - 1;
	int i;
	int tmp;

	for (i = start; i <= end; i++)
	{
		if (array[i] <= pivot)
		{
			pIndex++;
			if (pIndex != i)
			{
				tmp = array[pIndex];
				array[pIndex] = array[i];
				array[i] = tmp;
				print_array(array, size);
			}
		}
	}
	return (pIndex);
}
