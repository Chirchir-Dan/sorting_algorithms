#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 *                   using the Selection sort algorithm.
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index;


	if (array == NULL || size < 2)
		return;


	for (i = 0; i < size - 1; i++)
	{
		min_index = i;

		/* Find the index of the smallest element */
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_index])
				min_index = j;
		}

		/* Swap the current element with the smallest element */
		if (min_index != i)
		{
			int temp = array[i];

			array[i] = array[min_index];
			array[min_index] = temp;

			/* Print the array after each swap */
			print_array(array, size);
		}
	}
}
