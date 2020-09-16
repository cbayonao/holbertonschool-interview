#include "lists.h"
#include <stdlib.h>

/**
 * check_cycle - Function that check if a single linked list is a cycle
 * @list: list to check
 * Return: 0
 */

int check_cycle(listint_t *list)
{
	listint_t *oneStep = list, *twoStep = list;

	while (oneStep && twoStep && twoStep->next)
	{
		oneStep = oneStep->next;
		twoStep = twoStep->next->next;
		if (oneStep == twoStep)
			return (1);
	}
	return (0);
}
