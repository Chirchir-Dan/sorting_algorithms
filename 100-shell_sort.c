#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order
 *              using the Shell sort algorithm with Knuth sequence.
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1;
	size_t i, j;
	int temp;

	if (array == NULL || size < 2)
		return;

	/* Calculate the initial gap using Knuth sequence */
	while (gap < size / 3)
		gap = gap * 3 + 1;

	/* Iterate over each gap until gap becomes 1 */
	for (; gap > 0; gap /= 3)
	{
		/* Perform insertion sort for elements with the current gap */
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			/* Shift elements to the right that are greater than temp */
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = temp;
		}
		print_array(array, size);
	}
}
