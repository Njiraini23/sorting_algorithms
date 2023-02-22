#include "sort.h"

/**
 * implement_going_back - Implements going back for sorting algorythm
 * to left
 * @prev: Prev node
 * @actual: Actual node
 * @head: Head node to print list
 * Return Nothing
 */

void implement_going_back(listint_t **prev, listint_t *actual,
						  listint_t **head)
{

	while (actual->prev != NULL && actual->n < actual->prev->n)
	{
		(*prev)->next = actual->next;
		if (actual->next != NULL)
			actual->next->prev = *prev;
		actual->prev = (*prev)->prev;
		actual->next = *prev;
		if ((*prev)->prev != NULL)
			(*prev)->prev->next = actual;
		else
			*head = actual; /* prev node is NULL*/
		(*prev)->prev = actual;
		*prev = actual->prev;
		print_list((const listint_t *)*head);
	}
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 *  in ascending order using the Insertion sort algorithm
 * @list: list to look into
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *actual, *prev;

	if (list == NULL || *list == NULL)
		return;

	for (actual = (*list)->next; actual != NULL; actual = actual->next)
	{
		prev = actual->prev;
		implement_going_back(&prev, actual, list);
	}
}
