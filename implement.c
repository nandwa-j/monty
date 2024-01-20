#include "monty.h"
/**
 * is_integer - checks if a string is a valid integer
 * @str: string to be checked
 * Return: 1 if valid integer, 0 otherwise
 */
int is_integer(char *str)
{
	int i = 0;

	if (str[0] == '-')
		i++;

	for (; str[i] != '\0'; i++)
	{
		if (!isdigit(str[i]))
			return (0);
	}

	return (1);
}

/**
 * op_push - pushes an element to the stack
 * @store: head of the linked list
 * @numr: line number
 * Return: no return
 */
void op_push(stack_t **store, unsigned int numr)
{
	int n;

	if (!jay.arg || !is_integer(jay.arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", numr);
		free_jay();
		exit(EXIT_FAILURE);
	}

	n = atoi(jay.arg);

	if (jay.fifo == 1)
		add_dnodeint(store, n);
	else
		add_dnodeint_end(store, n);
}

/**
 * op_pall - prints all values on the stack
 * @store: head of the linked list
 * @numr: line numbers
 * Return: no return
 */
void op_pall(stack_t **store, unsigned int numr)
{
	stack_t *new;
	(void)numr;

	if (!store || !*store)
		return;

	new = *store;

	while (new)
	{
		printf("%d\n", new->n);
		new = new->next;
	}
}

/**
 * op_pint - prints the vlue at the top of the stack
 * @store: head to the linked list
 * @numr: line number where the function is called
 * Return: no return
 */
void op_pint(stack_t **store, unsigned int numr)
{
	(void)numr;

	if (*store == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", numr);
		free_jay();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*store)->n);
}

/**
 * op_pop - removes the top element from the stack
 * @store: head of the linked list
 * @numr: line number where the pop function is called
 */
void op_pop(stack_t **store, unsigned int numr)
{
	stack_t *temp;

	if (store == NULL || *store == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", numr);
		free_jay();
		exit(EXIT_FAILURE);
	}

	temp = *store;
	*store = temp->next;

	free(temp);
}
