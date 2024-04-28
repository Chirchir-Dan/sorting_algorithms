#include "sort.h"

/**
* bubble_sort - sorts array of integers using Bubble sort
*
* @array: Pointer to the array to be sorted
* @size: Number of elements in array
* Return: Nothing.
*/
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp, sorted;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		sorted = 1;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				sorted = 0;
				print_array(array, size);
			}
		}
		if (sorted)
			break;
	}
}
