#include "sort.h"

/**
 * swap_elements - Swaps two elements in an array based on the specified order.
 *
 * @arr: The array containing the elements.
 * @index1: Index of the first element to swap.
 * @index2: Index of the second element to swap.
 */
void swap_elements(int arr[], int index1, int index2)
{
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}

/**
 * bitonic_merge - Merges two subarrays in ascending order recursively.
 *
 * @arr: The array to be sorted.
 * @low: Starting index of the first subarray.
 * @count: Size of the subarray to be merged.
 * @dir: Sorting direction (1 for ascending, 0 for descending).
 */
void bitonic_merge(int arr[], int low, int count, int dir)
{
    if (count > 1)
    {
        int i, k = count / 2;
        for (i = low; i < low + k; ++i)
        {
            if (dir == (arr[i] > arr[i + k]))
                swap_elements(arr, i, i + k);
        }
        bitonic_merge(arr, low, k, dir);
        bitonic_merge(arr, low + k, k, dir);
    }
}

/**
 * bitonic_sort_recursive - Recursively applies the Bitonic sort algorithm.
 *
 * @arr: The array to be sorted.
 * @low: Starting index of the subarray.
 * @count: Size of the subarray.
 * @dir: Sorting direction (1 for ascending, 0 for descending).
 */
void bitonic_sort_recursive(int arr[], int low, int count, int dir)
{
    if (count > 1)
    {
        int k = count / 2;
        bitonic_sort_recursive(arr, low, k, 1); /* Sort first half in ascending order */
        bitonic_sort_recursive(arr, low + k, k, 0); /* Sort second half in descending order */
        bitonic_merge(arr, low, count, dir); /* Merge the entire array in specified direction */
    }
}

/**
 * bitonic_sort - Initiates the Bitonic sort algorithm.
 *
 * @array: The array to be sorted.
 * @size: Size of the array.
 */
void bitonic_sort(int *array, size_t size)
{
    bitonic_sort_recursive(array, 0, size, 1);
    print_array(array, size); /* Print the final sorted array */
}
