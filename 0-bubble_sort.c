#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order
 * using Bubble sort
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;
	int swapped;

	if (size < 2 || array == NULL)
		return;

	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				/* Swap array[j] and array[j + 1] */
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swapped = 1;

				/* Print the array after each swap */
				print_array(array, size);
			}
		}
		/* If no two elements were swapped in the inner */
		/* loop, then the array is already sorted */
		if (swapped == 0)
			break;
	}
}
