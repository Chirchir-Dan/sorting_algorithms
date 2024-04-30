#include "sort.h"

/**
 * swap_elements - Changes the positions of two elements in an array.
 *
 * @array: The array containing the elements.
 * @item1: Index of the first element to swap.
 * @item2: Index of the second element to swap.
 */
void swap_elements(int *array, ssize_t item1, ssize_t item2)
{
	int tmp;

	tmp = array[item1];
	array[item1] = array[item2];
	array[item2] = tmp;
}

/**
 * hoare_partition - Implements the Hoare partition sorting scheme.
 *
 * @array: The array to be partitioned.
 * @first: Index of the first element of the array to partition.
 * @last: Index of the last element of the array to partition.
 * @size: Size of the array.
 *
 * Return: The position of the last sorted element.
 */
int hoare_partition(int *array, int first, int last, int size)
{
	int current = first - 1, finder = last + 1;
	int pivot = array[last];

	while (1)
	{
		do {
			current++;
		} while (array[current] < pivot);

		do {
			finder--;
		} while (array[finder] > pivot);

		if (current >= finder)
			return (current);

		swap_elements(array, current, finder);
		print_array(array, size);
	}
}

/**
 * quick_sort_recursive - Recursively applies the Quicksort algorithm.
 *
 * @array: The array to be sorted.
 * @first: Index of the first element of the subarray.
 * @last: Index of the last element of the subarray.
 * @size: Size of the array.
 */
void quick_sort_recursive(int *array, ssize_t first, ssize_t last, int size)
{
	ssize_t position = 0;

	if (first < last)
	{
		position = hoare_partition(array, first, last, size);
		quick_sort_recursive(array, first, position - 1, size);
		quick_sort_recursive(array, position, last, size);
	}
}

/**
 * quick_sort_hoare - Initiates the Quick Sort algorithm using the Hoare scheme.
 *
 * @array: The array to be sorted.
 * @size: Size of the array.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}
