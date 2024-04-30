#include "sort.h"
#include <stdlib.h>

/**
 * counting_sort - Sorts an array of integers in ascending order
 *              using Counting Sort algorithm.
 *
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 *
 * Description: This function sorts an array by counting the occurrences
 *              of each unique element and computing their positions in the
 *              sorted output array using arithmetic operations.
 */
void counting_sort(int *array, size_t size)
{
	int max_val, j, *count_arr, *temp;
	size_t i;

	if (!array || size < 2)
		return;
	max_val = array[0];
	for (i = 0; i < size; i++)
	{
		if (array[i] > max_val)
			max_val = array[i];
	}
	count_arr = calloc((max_val + 1), sizeof(int));
	if (count_arr == NULL)
		return;

	for (i = 0; i < size; i++)
		count_arr[array[i]]++;

	for (j = 1; j < max_val; j++)
		count_arr[j + 1] += count_arr[j];

	print_array(count_arr, max_val + 1);
	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
	{
		free(count_arr);
		return;
	}

	for (i = 0; i < size; i++)
	{
		count_arr[array[i]]--;
		temp[count_arr[array[i]]] = array[i];
	}

	for (i = 0; i < size; i++)
		array[i] = temp[i];

	free(temp);
	free(count_arr);
}
