#ifndef SORT_H
#define SORT_H
#include <stddef.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;


/*Function prototypes*/

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void swap(int *a, int *b);
void lomuto_partition(int *array, int low, int high, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void _swap(listint_t **node, listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void split_data_for_merge(int *array, int *buffer, int min, int max, int size);
void print_array_range(int *array, int start, int end);
void merge_sorted_arrays(int *array, int *buffer, int minL, int maxL, int minR, int maxR);
void copy_buffer(int *src, int *dst, int size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void bitonic_sort(int *array, size_t size);

#endif /* SORT_H */
