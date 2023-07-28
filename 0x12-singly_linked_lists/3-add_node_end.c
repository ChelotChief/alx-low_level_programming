#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node_end - adds a first node at the end of a linked list
 * @head: double pointer to the list_t list
 * @str: string to put in the first node
 *
 * Return: address of the first element, or NULL if it failed
 */

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *first;
	list_t *temp = *head;
	unsigned int len = 0;

	while (str[len])
		len++;

	first = malloc(sizeof(list_t));
	if (!first)
		return (NULL);

	first->str = strdup(str);
	first->len = len;
	first->next = NULL;

	if (*head == NULL)
	{
		*head = first;
		return (first);
	}

	while (temp->next)
		temp = temp->next;

	temp->next = first;

	return (first);
}
