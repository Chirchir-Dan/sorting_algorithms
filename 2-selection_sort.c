#include "sort.h"

/**
* selection_sort - sorts array of integers in ascending order
* using Selection sort algorithm
* @array: The array to sort
* @size: Size of array
*/
void selection_sort(int *array, size_t size)
{
	int temp;
	size_t i, j, min_elem;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_elem = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_elem])
			{
				min_elem = j;
			}
		}

		if (min_elem != i)
		{
			temp = array[i];
			array[i] = array[min_elem];
			array[min_elem] = temp;
		}
		print_array(array, size);
	}
}
