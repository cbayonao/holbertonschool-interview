#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * list_length - Get the length of a linked list
 * @head: linked list head
 * Return: lenght
 */

int list_length(listint_t **head)
{
	int i;
	listint_t *current = *head;

	for (i = 0; current != NULL; i++)
		current = current->next;
	return (i);
}

/**
 * reversed - function that reversed a linked list
 * @head: double pointer
 * Return: Address of the new element
 */

listint_t *reversed(listint_t **head)
{
	listint_t *prev = NULL, *current = *head, *next = NULL;

	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head = prev;
	return (*head);
}

/**
 * is_palindrome - checks if a singly linked list is a palindrome.
 * @head: linked list head
 * Return: 1 if is palindrome or 0 if not
 */

int is_palindrome(listint_t **head)
{
	int length = list_length(head);
	int i, if_palindrome = 1;
	listint_t *reversed_head;
	listint_t *current = *head;
	listint_t *c_reversed;

	reversed_head = *head;
	for (i = 0; i < (length / 2); i++)
		reversed_head = reversed_head->next;
	if (length % 2 != 0)
		reversed_head = reversed_head->next;
	reversed_head = reversed(&reversed_head);
	c_reversed = reversed_head;
	current = *head;
	while (c_reversed != NULL)
	{
		if (c_reversed->n != current->n)
			if_palindrome = 0;
		c_reversed = c_reversed->next;
		current = current->next;
	}
	return (if_palindrome);
}
