#include "monty.h"

/**
 * op_swap - swaps the top two elements of the stack
 * @store: head of the linked list
 * @numr: line number
 * Return: no return
 */
void op_swap(stack_t **store, unsigned int numr)
{
	stack_t *top = *store;
	stack_t *next = top->next;

	if (!store || !(*store) || !(*store)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", numr);
		free_jay();
		exit(EXIT_FAILURE);
	}

	top->next = next->next;
	top->prev = next;
	if (next->next)
		next->next->prev = top;
	next->prev = NULL;
	next->next = top;

	*store = next;
}

/**
 * op_add - adds the top two elements of the stack
 * @store: head of the linked list
 * @numr: line number
 * Return: no return
 */
void op_add(stack_t **store, unsigned int numr)
{

	if (!store || !(*store) || !(*store)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", numr);
		free_jay();
		exit(EXIT_FAILURE);
	}

	(*store)->next->n += (*store)->n;

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
	int one = (*store)->next->n;
	int two = (*store)->n;

	if (!store || !(*store) || !(*store)->next)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", numr);
		free_jay();
		exit(EXIT_FAILURE);
	}

	if ((two < 0 && one > INT_MAX + two) || (two > 0 && one < INT_MIN + two))
	{
		fprintf(stderr, "L%u: sub result out of range\n", numr);
		free_jay();
		exit(EXIT_FAILURE);
	}

	(*store)->next->n = one - two;

	op_pop(store, numr);
}
