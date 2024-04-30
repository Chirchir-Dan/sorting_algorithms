#include "sort.h"

/**
 * heapify - Maintains the max-heap property by performing heapify operation.
 *
 * This function checks if the subtree rooted at index 'root_index'
 * in the array
 * 'heap_array' satisfies the max-heap property. If not, it swaps elements to
 * restore the property and recursively applies heapify to its children.
 *
 * @heap_array: Pointer to the array representing the heap.
 * @initial_size: Initial size of the array.
 * @current_size: Current size of the heap.
 * @root_index: Index representing the root of the subtree.
 */
void heapify(
		int *heap_array, size_t initial_size, size_t current_size, size_t root_index)

{
	int temp, left_branch, right_branch;
	size_t left_index, right_index;

	left_index = root_index * 2 + 1;
	right_index = left_index + 1;
	left_branch = heap_array[left_index];
	right_branch = heap_array[right_index];

	if (((left_index < current_size) && (right_index < current_size) &&
	     (left_branch >= right_branch && left_branch > heap_array[root_index])) ||
	    ((
	      left_index == current_size - 1) && left_branch > heap_array[root_index]
	     ))
	{
		temp = heap_array[root_index];
		heap_array[root_index] = left_branch;
		heap_array[left_index] = temp;
		print_array(heap_array, initial_size); /* Print the array after swapping */
	}
	else if ((left_index < current_size) && (right_index < current_size) &&
			(right_branch > left_branch &&
		  right_branch > heap_array[root_index]))
	{
		temp = heap_array[root_index];
		heap_array[root_index] = right_branch;
		heap_array[right_index] = temp;
		print_array(heap_array, initial_size); /* Print the array after swapping */
	}

	if (left_index < current_size - 1)
		heapify(heap_array, initial_size, current_size, left_index);
	if (right_index < current_size - 1)
		heapify(heap_array, initial_size, current_size, right_index);
}

/**
 * heap_sort - Sorts an array of integers in ascending order
 * using the Heap sort algorithm.
 *
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 */
void heap_sort(int *array, size_t size)
{
	size_t i, initial_size = size;
	int temp;

	if (!array)
		return;

	/* Build max-heap from the array */
	for (i = 0; i < size / 2 ; i++)
	{
		heapify(array, initial_size, size, size / 2 - 1 - i);
	}

	/* Extract elements from the max-heap one by one */
	for (i = 0; i < initial_size - 1; i++)
	{
		/* Swap the root (maximum element) with the last element */
		temp = array[0];
		array[0] = array[size - 1 - i];
		array[size - 1 - i] = temp;
		print_array(array, initial_size); /* Print the array after swapping */
		/* Restore max-heap property on the reduced heap */
		heapify(array, initial_size, size - i - 1, 0);
	}
}
