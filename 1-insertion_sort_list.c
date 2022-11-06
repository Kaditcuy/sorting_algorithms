#include "sort.h"

/**
* insertion_sort_list - Sorts a dll of integers using
*						 insertion sort.
* @list: Pointer to pointer to the node in the dll
* Return: Null
*/
void insertion_sort_list(listint_t **list)
{

	listint_t *current, *prev;

	if (!list || (*list)->next == NULL)
		return;

	current = *list;
	while (current)
	{
		prev = current->prev;
		while (prev && (prev->n > current->n))
		{
			swap_nodes(list, prev, current);
			print_list(*list);
			prev = current->prev;
		}
		current = current->next;
	}
}

/**
* swap_nodes - swaps two nodes in a dll in ascending order
* @list: doubly linked list containing nodes to swap
* @nodeA: node to swap
* @nodeB: node to swap
*
* Return: Null
*/
void swap_nodes(listint_t **list, listint_t *nodeA, listint_t *nodeB)
{
	listint_t *prevA, *nextB;

	if (!nodeA || !nodeB)
		return;

	prevA = nodeA->prev;
	nextB = nodeB->next;

	if (prevA)
		prevA->next = nodeB;

	if (nextB)
		nextB->prev = nodeA;

	nodeA->next = nextB;
	nodeA->prev = nodeB;
	nodeB->next = nodeA;
	nodeB->prev = prevA;

	if (prevA == NULL)
		*list = nodeB;
}
