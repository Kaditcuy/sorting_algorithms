#include "sort.h"

/**
*
*/
void quick_sort(int *array, size_t size)
{
	lomuto_qsort(array, 0, size-1, size);
}

/**
*
*/
void lomuto_qsort(int *array, int start, int end, size_t size)
{
	int pIndex;

	if (start < end)
	{
		pIndex = partition(array, start, end, size);
		lomuto_qsort(array, start, pIndex-1, size);
		lomuto_qsort(array, pIndex+1, end, size);
	}
}

int partition(int *array, int start, int end, size_t size)
{
	int pivot = array[end];
	int pIndex = start;
	int i;

	for (i = start; i < end; i++)
	{
		if (array[i] <= pivot)
		{
			swap(&array[i], &array[pIndex]);
			pIndex++;
			/*if (pIndex != i)
			{
				tmp = array[pIndex];
				array[pIndex] = array[i];
				array[i] = tmp;
				print_array(array, size);
			}*/
		}
	}
	swap(&array[pIndex], &array[end]);
	print_array(array, size);
	return (pIndex);
}

void swap(int *a, int *b)
{
	int temp;

	temp = *b;
	*b = *a;
	*a = temp;
}
