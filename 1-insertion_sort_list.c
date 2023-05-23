#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *
 * @list: Double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current)
	{
		listint_t *temp = current->prev;

		while (temp && temp->n > current->n)
		{
			if (temp->prev != NULL)
				temp->prev->next = current;
			if (current->next != NULL)
				current->next->prev = temp;

			temp->next = current->next;
			current->prev = temp->prev;
			temp->prev = current;
			current->next = temp;

			if (current->prev == NULL)
				*list = current;

			print_list(*list);
			temp = current->prev;
		}
		current = current->next;
	}
}
