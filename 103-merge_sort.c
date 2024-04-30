#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * copy_buffer - Copies data from one buffer to another.
 *
 * This function duplicates the content of the source buffer 'src' to the
 * destination buffer 'dst'. It copies 'size' number of elements.
 *
 * @src: Source buffer.
 * @dst: Destination buffer.
 * @size: Size of buffers.
 *
 * Return: No return.
 */
void copy_buffer(int *src, int *dst, int size)
{
	int i;

	for (i = 0; i < size; i++)
		dst[i] = src[i];
}

/**
 * merge_sorted_arrays - Merges two sets of data in ascending order
 * provided they are already sorted.
 *
 * @array: First set of sorted data.
 * @buffer: Second set of sorted data.
 * @minL: Lower bound of the first set.
 * @maxL: Upper bound of the first set.
 * @minR: Lower bound of the second set.
 * @maxR: Upper bound of the second set.
 *
 * Return: No Return
 */
void merge_sorted_arrays(
		int *array, int *buffer, int minL, int maxL, int minR, int maxR)
{
	int i = minL, j = minR, k = minL;

	while (i <= maxL || j <= maxR)
	{
		if (i <= maxL && j <= maxR)
		{
			if (buffer[i] <= buffer[j])
				array[k] = buffer[i], k++, i++;
			else
				array[k] = buffer[j], k++, j++;
		}
		else if (i > maxL && j <= maxR)
			array[k] = buffer[j], k++, j++;
		else
			array[k] = buffer[i], k++, i++;
	}
}

/**
 * print_array_range - Prints an array within a given range.
 *
 * @array: Array of data to be printed.
 * @start: Start index of the range.
 * @end: End index of the range.
 *
 * Return: No Return
 */
void print_array_range(int *array, int start, int end)
{
	int i;

	for (i = start; i <= end; i++)
	{
		if (i > start)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
}

/**
 * split_data_for_merge - Recursive function to split data into
 * merge tree.
 *
 * @array: Array of data to be split.
 * @buffer: Auxiliary array used for merging.
 * @min: Minimum index of data in array.
 * @max: Maximum index of data in array.
 * @size: Total size of data.
 *
 * Return: No Return
 */
void split_data_for_merge(int *array, int *buffer, int min, int max, int size)
{
	int mid, tmax, minL, maxL, minR, maxR;

	if ((max - min) <= 0)
		return;

	mid = (max + min + 1) / 2;
	tmax = max;
	max = mid - 1;

	minL = min;
	maxL = max;

	split_data_for_merge(array, buffer, min, max, size);

	min = mid;
	max = tmax;

	minR = min;
	maxR = max;

	split_data_for_merge(array, buffer, min, max, size);

	printf("Merging...\n");
	printf("[left]: ");
	print_array_range(array, minL, maxL);
	printf("[right]: ");
	print_array_range(array, minR, maxR);

	merge_sorted_arrays(array, buffer, minL, maxL, minR, maxR);
	copy_buffer(array, buffer, size);

	printf("[Done]: ");
	print_array_range(array, minL, maxR);
}

/**
 * merge_sort - Sorts an array of integers in ascending order
 * using the Merge Sort algorithm.
 *
 * @array: Array of data to be sorted.
 * @size: Size of the array.
 *
 * Return: No Return
 */
void merge_sort(int *array, size_t size)
{
	int *buffer;

	if (size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	copy_buffer(array, buffer, size);
	split_data_for_merge(array, buffer, 0, size - 1, size);
	free(buffer);
}
