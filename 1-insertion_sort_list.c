#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *		in ascending order using Insertion sort algorithm.
 * @list: Pointer to the pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	 current = (*list)->next;

	while (current != NULL)
	{
		listint_t *insertion_point = current->prev;
		listint_t *next_node = current->next;

		while (insertion_point != NULL && insertion_point->n > current->n)
		{
			/* Swap current node with its previous node */
			if (insertion_point->prev != NULL)
				insertion_point->prev->next = current;
			else
				*list = current;
			if (current->next != NULL)
				current->next->prev = insertion_point;

			insertion_point->next = current->next;
			current->prev = insertion_point->prev;
			current->next = insertion_point;
			insertion_point->prev = current;

			/* Move insertion_point backward */
			insertion_point = current->prev;
			/* Print the list after each swap */
			print_list(*list);
		}

		current = next_node;
	}
}

