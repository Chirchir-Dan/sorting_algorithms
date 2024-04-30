#include "deck.h"

/**
 * compare_strings - Compares two strings.
 * @str1: The first string to be compared.
 * @str2: The second string to be compared.
 *
 * Return: Positive difference if str1 > str2
 *         0 if str1 == str2
 *         Negative difference if str1 < str2
 */
int compare_strings(const char *str1, const char *str2)
{
	while (*str1 && *str2 && *str1 == *str2)
	{
		str1++;
		str2++;
	}

	if (*str1 != *str2)
		return (*str1 - *str2);
	return (0);
}

/**
 * get_card_value - Retrieves the numerical value of a card.
 * @card: Pointer to a deck_node_t representing a card.
 *
 * Return: The numerical value of the card.
 */
char get_card_value(deck_node_t *card)
{
	if (compare_strings(card->card->value, "Ace") == 0)
		return (0);
	if (compare_strings(card->card->value, "1") == 0)
		return (1);
	if (compare_strings(card->card->value, "2") == 0)
		return (2);
	if (compare_strings(card->card->value, "3") == 0)
		return (3);
	if (compare_strings(card->card->value, "4") == 0)
		return (4);
	if (compare_strings(card->card->value, "5") == 0)
		return (5);
	if (compare_strings(card->card->value, "6") == 0)
		return (6);
	if (compare_strings(card->card->value, "7") == 0)
		return (7);
	if (compare_strings(card->card->value, "8") == 0)
		return (8);
	if (compare_strings(card->card->value, "9") == 0)
		return (9);
	if (compare_strings(card->card->value, "10") == 0)
		return (10);
	if (compare_strings(card->card->value, "Jack") == 0)
		return (11);
	if (compare_strings(card->card->value, "Queen") == 0)
		return (12);
	return (13);
}

/**
 * insertion_sort_kind - Sorts a deck of cards by suit.
 * @deck: Pointer to the head of a deck_node_t doubly-linked list.
 */
void insertion_sort_kind(deck_node_t **deck)
{
	deck_node_t *current_card, *insert_position, *tmp;

	for (current_card = (*deck)->next; current_card != NULL; current_card = tmp)
	{
		tmp = current_card->next;
		insert_position = current_card->prev;
		while (
				insert_position != NULL &&
				insert_position->card->kind > current_card->card->kind)
		{
			insert_position->next = current_card->next;
			if (current_card->next != NULL)
				current_card->next->prev = insert_position;
			current_card->prev = insert_position->prev;
			current_card->next = insert_position;
			if (insert_position->prev != NULL)
				insert_position->prev->next = current_card;
			else
				*deck = current_card;
			insert_position->prev = current_card;
			insert_position = current_card->prev;
		}
	}
}

/**
 * insertion_sort_value - Sorts a deck of cards by value.
 * @deck: Pointer to the head of a deck_node_t doubly-linked list.
 */
void insertion_sort_value(deck_node_t **deck)
{
	deck_node_t *current_card, *insert_position, *tmp;

	for (current_card = (*deck)->next; current_card != NULL; current_card = tmp)
	{
		tmp = current_card->next;
		insert_position = current_card->prev;
		while (insert_position != NULL &&
			   insert_position->card->kind == current_card->card->kind &&
			   get_card_value(insert_position) > get_card_value(current_card))
		{
			insert_position->next = current_card->next;
			if (current_card->next != NULL)
				current_card->next->prev = insert_position;
			current_card->prev = insert_position->prev;
			current_card->next = insert_position;
			if (insert_position->prev != NULL)
				insert_position->prev->next = current_card;
			else
				*deck = current_card;
			insert_position->prev = current_card;
			insert_position = current_card->prev;
		}
	}
}

/**
 * deck_sort - Sorts a deck of cards.
 * @deck: Pointer to the head of a deck_node_t doubly-linked list.
 */
void deck_sort(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	insertion_sort_kind(deck);
	insertion_sort_value(deck);
}
