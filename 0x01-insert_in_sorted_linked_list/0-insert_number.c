#include <stdio.h>
#include "lists.h"
#include <stdlib.h>

/**
 * insert_node - Insert in sorted linked list
 * @head: Double pointer to head
 * @number: Integer with the number to insert
 * Return: a listint_t with the address of the new node or NULL
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new;
	listint_t *prev;
	listint_t *next;

	if (!head)
		return (NULL);
	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = number;
	if (*head == NULL)
	{
		new->next = NULL;
		*head = new;
		return (new);
	}
	prev = *head;
	next = prev->next;
	while (prev)
	{
		if (prev->n >= number)
		{
			new->next = prev;
			*head = new;
			return (new);
		}
		else if (!next && prev->n <= number)
		{
			prev->next = new;
			new->next = NULL;
			return (new);
		}
		else if (prev->n <= number && next->n >= number)
		{
			prev->next = new;
			new->next = next;
			return (new);
		}
		prev = next;
		next = prev->next;
	}
	return (NULL);
}
