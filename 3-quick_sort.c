#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order
 *              using the Quick sort algorithm with Lomuto partition scheme.
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_partition(array, 0, size - 1, size);
}

/**
 * lomuto_partition - Partitions the array using the Lomuto partition scheme
 * @array: The array to be partitioned
 * @low: The lower index of the partition
 * @high: The higher index of the partition
 * @size: Number of elements in the array
 */
void lomuto_partition(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot = array[high];
		int i = low - 1;
		int j;

		for (j = low; j <= high - 1; j++)
		{
			if (array[j] < pivot)
			{
				i++;
				if (i != j)
				{
					swap(&array[i], &array[j]);
					print_array(array, size);
				}
			}
		}
		if (array[i + 1] != array[high])
		{
			swap(&array[i + 1], &array[high]);
			print_array(array, size);
		}

		lomuto_partition(array, low, i, size);
		lomuto_partition(array, i + 2, high, size);
	}
}

/**
 * swap - Swaps two elements in an array
 * @a: Pointer to the first element
 * @b: Pointer to the second element
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
