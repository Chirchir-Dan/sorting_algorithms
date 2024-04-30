#include "sort.h"

/**
 * swap_elements - Swaps two elements in an array based on the specified order.
 *
 * @arr: The array containing the elements.
 * @index1: Index of the first element to swap.
 * @index2: Index of the second element to swap.
 * @is_ascending: If 1, swaps in ascending order; otherwise, swaps in descending order.
 */
void swap_elements(int arr[], int index1, int index2, int is_ascending)
{
	int temp;

	if (is_ascending == (arr[index1] > arr[index2]))
	{
		temp = arr[index1];
		arr[index1] = arr[index2];
		arr[index2] = temp;
	}
}

/**
 * merge_bitonic_sequences - Merges bitonic sequences recursively in the specified order.
 *
 * @arr: The array to sort.
 * @low: Index of the first element.
 * @num_elements: Number of elements to merge.
 * @is_ascending: If 1, merges in ascending order; otherwise, merges in descending order.
 */
void merge_bitonic_sequences(int arr[], int low, int num_elements, int is_ascending)
{
	int mid, i;

	if (num_elements > 1)
	{
		mid = num_elements / 2;
		for (i = low; i < low + mid; i++)
			swap_elements(arr, i, i + mid, is_ascending);
		merge_bitonic_sequences(arr, low, mid, is_ascending);
		merge_bitonic_sequences(arr, low + mid, mid, is_ascending);
	}
}

/**
 * bitonic_sort_recursive - Recursively applies the bitonic sort algorithm.
 *
 * @arr: The array to sort.
 * @low: Index of the first element.
 * @num_elements: Number of elements to sort.
 * @is_ascending: If 1, sorts in ascending order; otherwise, sorts in descending order.
 * @array_size: Total size of the array.
 */
void bitonic_sort_recursive(int arr[], int low, int num_elements, int is_ascending, int array_size)
{
	int mid;

	if (num_elements > 1)
	{
		mid = num_elements / 2;
		bitonic_sort_recursive(arr, low, mid, 1, array_size);
		bitonic_sort_recursive(arr, low + mid, mid, 0, array_size);
		merge_bitonic_sequences(arr, low, num_elements, is_ascending);
	}
}

/**
 * bitonic_sort - Initiates the bitonic sort algorithm.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void bitonic_sort(int *array, size_t size)
{
	int is_ascending = 1;

	if (!array || size < 2)
		return;

	bitonic_sort_recursive(array, 0, size, is_ascending, size);
}
