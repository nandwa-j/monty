#include "monty.h"

/**
 * op_swap - swaps the top two elements of the stack
 * @store: head of the linked list
 * @numr: line number
 * Return: no return
 */
void op_swap(stack_t **store, unsigned int numr)
{
	int count = 0;
	stack_t *one = *store;
	stack_t *two = NULL;

	while (one && count < 2)
	{
		two = one;
		one = one->next;
		count++;
	}

	if (count < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", numr);
		free_jay();
		exit(EXIT_FAILURE);
	}

	two->prev->next = two->next;
	if (two->next)
		two->next->prev = two->prev;

	two->next = one;
	two->prev = one->prev;
	if (one->prev)
		one->prev->next = two;
	one->prev = two;

	*store = two;
}

/**
 * op_add - adds the top two elements of the stack
 * @store: head of the linked list
 * @numr: line number
 * Return: no return
 */
void op_add(stack_t **store, unsigned int numr)
{
	int count = 0;
	stack_t *one = *store;
	stack_t *two = NULL;

	while (one && count < 2)
	{
		two = one;
		one = one->next;
		count++;
	}

	if (count < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", numr);
		free_jay();
		exit(EXIT_FAILURE);
	}

	two->n += one->n;

	op_pop(store, numr);
}

/**
 * op_nop - doesn't do anything
 * @store: head of a linked list
 * @numr: line number where the op_nop function is called
 * Return: no retrun
 */
void op_nop(stack_t **store, unsigned int numr)
{
	(void)store;
	(void)numr;
}

/**
 * op_sub - subtracts the top element from the second top element of the stack
 * @store: head of the linked list
 * @numr: line number
 * Return: no return
 */
void op_sub(stack_t **store, unsigned int numr)
{
	int count = 0;
	stack_t *one = *store;
	stack_t *two = NULL;

	while (one && count < 2)
	{
		two = one;
		one = one->next;
		count++;
	}

	if (count < 2)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", numr);
		free_jay();
		exit(EXIT_FAILURE);
	}

	two->n -= one->n;

	op_pop(store, numr);
}
