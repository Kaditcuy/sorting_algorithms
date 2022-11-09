#include "sort.h"

/**
 * shell_sort - sorts an array of integers
 * in ascending order using the Shell sort algorithm,
 * using the Knuth sequence
 * @array: Array to be sorted
 * @size: Size of array to be sorted
 * Return: Void
 */
void shell_sort(int *array, size_t size)
{
	size_t h = 1, i, j, tmp;

	if (!array || size < 2 || !size)
		return;

	while (h < size / 3)
		h *= 3 + 1;

	while (h > 0)
	{
		for (i = h; i < size; i++)
		{
			tmp = array[i];

			for (j = i; j > (h - 1) && (size_t)array[j - h] >= tmp; j -= h)
			{
				array[j] = array[j - h];
			}
			array[j] = tmp;
		}
		h /= 3;
		print_array(array, size);
	}
}
