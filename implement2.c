#include "monty.h"
/**
 * op_div - divides the second element by the top element of the stack
 * @store: head of the linked list
 * @numr: line number
 * Return: no return
 */
void op_div(stack_t **store, unsigned int numr)
{
	stack_t *one = *store;
	stack_t *two = NULL;

	if (!one || !(one->next))
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", numr);
		free_jay();
		exit(EXIT_FAILURE);
	}

	two = one->next;

	if (one->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", numr);
		free_jay();
		exit(EXIT_FAILURE);
	}

	two->n /= one->n;
	op_pop(store, numr);
}

/**
 * op_mul - multiplies the top element by the second top element of the stack
 * @store: head of the linked list
 * @numr: line number
 * Return: no return
 */
void op_mul(stack_t **store, unsigned int numr)
{
	stack_t *one = *store;
	stack_t *two = NULL;

	if (!one || !(one->next))
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", numr);
		free_jay();
		exit(EXIT_FAILURE);
	}

	two = one->next;

	two->n *= one->n;
	op_pop(store, numr);
}

/**
 * op_mod - computes the remainder of the division of the second element
 * by the top element of the stack
 * @store: head of the linked list
 * @numr: line number
 * Return: no return
 */
void op_mod(stack_t **store, unsigned int numr)
{
	stack_t *one = *store;
	stack_t *two = NULL;

	if (!one || !(one->next))
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", numr);
		free_jay();
		exit(EXIT_FAILURE);
	}

	two = one->next;

	if (one->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", numr);
		free_jay();
		exit(EXIT_FAILURE);
	}

	two->n %= one->n;
	op_pop(store, numr);
}

/**
 * op_pchar - print the char value of the first element
 * @store: head of the linked list
 * @numr: line number
 * Return: no return
 */
void op_pchar(stack_t **store, unsigned int numr)
{
	int value = (*store)->n;

	if (!store || !(*store))
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", numr);
		free_jay();
		exit(EXIT_FAILURE);
	}

	if (!_isascii(value))
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", numr);
		free_jay();
		exit(EXIT_FAILURE);
	}

	printf("%c\n", value);
}

/**
 * op_pstr - prints the string of the stack
 * @store: head of the linked list
 * @numr: line number
 * Return: no return
 */
void op_pstr(stack_t **store, unsigned int numr)
{
	stack_t *temp;
	(void)numr;

	temp = *store;

	while (temp && _isascii(temp->n) && temp->n != 0)
	{
		printf("%c", temp->n);
		temp = temp->next;
	}

	printf("\n");
}
