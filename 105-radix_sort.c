#include <stdlib.h>
#include "sort.h"

/**
 * radix_counting_sort - Sorts an array of integers based on the value of
 * the least significant digit (LSD) using the Counting Sort algorithm.
 *
 * This function sorts the array based on the LSD, iterating through
 * each digit position and counting occurrences of each digit.
 * It then rearranges the elements in the array according to the counts.
 *
 * @array: The array of integers to be sorted.
 * @digit_buckets: A dynamically allocated buffer for temporary storage.
 * @size: The size of the array.
 * @digit_position: The position of the least significant digit
 * being considered.
 */
void radix_counting_sort(
		int *array, int **digit_buckets, int size, int digit_position)
{
	int i, j, digit;
	int digit_counts[10] = {0};

	/* Count occurrences of each digit at the specified position */
	for (i = 0; i < size; i++)
	{
		digit = array[i];
		for (j = 0; j < digit_position; j++)
			if (j > 0)
				digit = digit / 10;
		digit = digit % 10;
		digit_buckets[digit][digit_counts[digit]++] = array[i];
	}

	/* Rearrange elements in the array based on the counts */
	for (i = 0, j = 0; i < 10; i++)
	{
		while (digit_counts[i] > 0)
		{
			array[j] = digit_buckets[i][--digit_counts[i]];
			j++;
		}
	}

	print_array(array, size);
}

/**
 * counting_sort_recursive - Recursively sorts an array of integers
 * using the Counting Sort algorithm based on different least
 * significant digits.
 *
 * This function recursively applies counting_sort with increasing least
 * significant digit positions until the entire array is sorted.
 *
 * @array: The array of integers to be sorted.
 * @size: The size of the array.
 * @digit_position: The position of the least significant digit
 * being considered.
 */
void radix_counting_sort_recursive(int *array, int size, int digit_position)
{
	int digit_counts[10] = {0};
	int **digit_buckets = malloc(sizeof(int *) * 10);
	int i, j, digit;

	if (!digit_buckets)
		return;
	/* Count occurrences of each digit at the specified position */
	for (i = 0; i < size; i++)
	{
		digit = array[i];

		for (j = 0; j < digit_position; j++)
			if (j > 0)
				digit = digit / 10;
		digit = digit % 10;
		digit_counts[digit]++;
	}

	/* If all elements have the same digit at the specified */
	/* position, no sorting is required */
	if (digit_counts[0] == size)
	{
		free(digit_buckets);
		return;
	}
	/* Allocate memory for the buffer based on counts */
	for (i = 0; i < 10; i++)
		if (digit_counts[i] != 0)
			digit_buckets[i] = malloc(sizeof(int) * digit_counts[i]);

	/* Sort the array based on the current least significant digit */
	radix_counting_sort(array, digit_buckets, size, digit_position);

	/* Recursively sort the array based on the next least significant digit */
	radix_counting_sort_recursive(array, size, digit_position + 1);
	/* Free memory allocated for the buffer */
	for (i = 0; i < 10; i++)
		if (digit_counts[i] > 0)
			free(digit_buckets[i]);
	free(digit_buckets);
}

/**
 * radix_sort - Sorts an array of integers in ascending order
 * using the Radix sort algorithm.
 *
 * @array: The array of integers to be sorted.
 * @size: The size of the array.
 */
void radix_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	/* Start the radix sort with least significant digit position 1 */
	radix_counting_sort_recursive(array, size, 1);
}
