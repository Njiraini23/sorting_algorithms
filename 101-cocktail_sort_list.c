#include "sort.h"

/**
 * swap_node_from_letf_to_right - swap node from rigth to left
 * @actual_node: pointer to the actual node
 * @tail_node: pointer to the last elemetn of the list
 * @list: pointer to the first element of the list
 */
void swap_node_from_letf_to_right(listint_t **actual_node,
								  listint_t **tail_node,
								  listint_t **list)
{
	listint_t *next_node = (*actual_node)->next;

	if ((*actual_node)->prev != NULL)
		(*actual_node)->prev->next = next_node;
	else
		*list = next_node;
	next_node->prev = (*actual_node)->prev;
	(*actual_node)->next = next_node->next;
	if (next_node->next != NULL)
		next_node->next->prev = *actual_node;
	else
		*tail_node = *actual_node;
	(*actual_node)->prev = next_node;
	next_node->next = *actual_node;
	*actual_node = next_node;
}
/**
 * swap_node_from_rigth_to_left - swap node from left to rigth
 * @actual_node: pointer to the actual node
 * @tail_node: pointer to the last elemetn of the list
 * @list: pointer to the first element of the list
 */

void swap_node_from_rigth_to_left(listint_t **actual_node,
								  listint_t **tail_node,
								  listint_t **list)
{
	listint_t *prev_node = (*actual_node)->prev;

	if ((*actual_node)->next != NULL)
		(*actual_node)->next->prev = prev_node;
	else
		*tail_node = prev_node;
	prev_node->next = (*actual_node)->next;
	(*actual_node)->prev = prev_node->prev;
	if (prev_node->prev != NULL)
		prev_node->prev->next = *actual_node;
	else
		*list = *actual_node;
	(*actual_node)->next = prev_node;
	prev_node->prev = *actual_node;
	*actual_node = prev_node;
}

/**
 * going_forward - Moving form right to left to check nodes of the list
 * @list: List to sort
 * @tail_node: Node of the last element of the list
 * @control: stands in 1 - if Not swap neededs otherwhise change to 0
 * Return: Nothing
 */
void going_forward(listint_t **list, listint_t **tail_node, int *control)
{
	listint_t *actual = NULL;

	for (actual = *list; actual != *tail_node; actual = actual->next)
	{
		if (actual->n > actual->next->n)
		{
			swap_node_from_letf_to_right(&actual, tail_node, list);
			print_list((const listint_t *)*list);
			control[0] = 0;
		}
	}
}

/**
 * going_backward - Moving form left to right to check nodes of the list
 * @list: List to sort
 * @tail_node: Node of the last element of the list
 * @control: stands in 1 - if Not swap neededs otherwhise change to 0
 * Return: Nothing
 */
void going_backward(listint_t **list, listint_t **tail_node, int *control)
{
	listint_t *actual;

	for (actual = *tail_node; actual != *list; actual = actual->prev)
	{
		if (actual->n < actual->prev->n)
		{
			swap_node_from_rigth_to_left(&actual, tail_node, list);
			print_list((const listint_t *)*list);
			control[0] = 0;
		}
	}
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers
 *  in ascending order using the Cocktail shaker sort algorithm
 * @list: list to sort
 * Return: Nothing
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail = NULL;
	int control = 0;

	if (list == NULL || *list == NULL)
		return;

	for (tail = *list; tail->next != NULL; tail = tail->next)
		;
	while (!control)
	{
		control = 1;
		going_forward(list, &tail, &control);
		going_backward(list, &tail, &control);
	}
}
