#include "monty.h"
#include <stdio.h>

/**
 * _calloc - allocate and initialize memory for an array
 * @num: number of elements
 * @size: size of each element
 * Return: pointer to the allocated memory
 */
void *_calloc(unsigned int num, unsigned int size)
{
	void *p = NULL;
	unsigned int i;
	char *char_ptr = p;

	if (num == 0 || size == 0)
		return (NULL);

	p = malloc(num * size);

	if (p == NULL)
		return (NULL);

	for (i = 0; i < num * size; i++)
		char_ptr[i] = 0;

	return (p);
}

/**
 * _realloc - resize a memory block
 * @p: pointer to the memory block
 * @old: old size of the memory block
 * @y: new size of the memory block
 * Return: pointer to the reallocated memory block
 */
void *_realloc(void *p, unsigned int old, unsigned int y)
{
	char *s = NULL;
	unsigned int i;
	char *ptr_old = p;
	char *ptr_new = s;

	if (y == old)
		return (p);

	if (p == NULL)
	{
		s = malloc(y);
		return (s);
	}

	if (y == 0)
	{
		free(p);
		return (NULL);
	}

	s = malloc(y);

	if (s == NULL)
		return (NULL);

	for (i = 0; i < old && i < y; i++)
		ptr_new[i] = ptr_old[i];

	free(p);

	return (s);
}

/**
 * add_dnodeint_end - add a node at the end of the doubly linked list
 * @head: pointer to the first node of the list
 * @n: data to store in the new node
 * Return: pointer to the new node, or NULL on failure
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *new_node, *tmp;

	if (head == NULL)
		return (NULL);

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_jay();
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->next = NULL;

	if (*head == NULL)
	{
		new_node->prev = NULL;
		*head = new_node;
		return (*head);
	}

	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;

	tmp->next = new_node;
	new_node->prev = tmp;

	return (new_node);
}

/**
 * add_dnodeint - add a node at the beginning of the doubly linked list
 * @head: pointer to the first node of the list
 * @n: data to store in the new node
 * Return: pointer to the new node, or NULL on failure
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new_node;

	if (head == NULL)
		return (NULL);

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_jay();
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;

	if (*head != NULL)
		(*head)->prev = new_node;

	*head = new_node;

	return (*head);
}

/**
 * free_dlistint - frees the doubly linked list
 * @head: pointer to the first node of the list
 * Return: no return
 */
void free_dlistint(stack_t *head)
{
	stack_t *current, *next_node;

	current = head;
	while (current != NULL)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
}

