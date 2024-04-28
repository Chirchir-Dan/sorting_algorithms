#include "sort.h"

/**
 * swap - Swaps two integers in array
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - Partitions the array and returns index of the pivot
 * @array: Array to be partitioned
 * @low: Starting index of the array
 * @high: Last index of the array
 *
 * Return: Index of the pivot.
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j;

	pivot = array[high];
	i = low - 1;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[i + 1], &array[high]);
	print_array(array, size);
	i += 1;
	return (i);
}

/**
 * quick_sort_recursive - Sorts array of integers in ascending order using
 * Quick sort algorithm recursively
 * @array: Array to be sorted
 * @low: Starting index
 * @high: Last index of array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = partition(array, low, high, size);

		quick_sort_recursive(array, low, pivot_index - 1, size);
		quick_sort_recursive(array, pivot_index + 1, high, size);
	}
}


/**
 * quick_sort - Sorts array of integers in ascending order using Quick sort
 * algorithm. It is implemented using Lomuto partition scheme
 * @array: Array to sort
 * @size: Size of the array
 *
 * Return: Nothing.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}
