#include "lists.h"

/**
 * check_cycle - checks if a linked list has a cycle
 * @list: pointer to the head of the list
 * Return: 1 if there is a cycle, 0 if there isn't
 */
int check_cycle(listint_t *list)
{
	listint_t *low = list, *speed = list;

	while (speed != NULL && speed->next != NULL)
	{
		low = low->next;
		speed = speed->next->next;
		if (low == speed)
			return (1);
	}
	return (0);
}