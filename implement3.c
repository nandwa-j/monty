#include "monty.h"
/**
 * op_rotl - rotates the stack to the top
 * @store: head of the linked list.
 * @numr: Line number where the rotl function is called.
 */
void op_rotl(stack_t **store, unsigned int numr)
{
	stack_t *temp;
	(void)numr;

	if (store == NULL || *store == NULL || (*store)->next == NULL)
		return;

	temp = *store;

	while (temp->next)
		temp = temp->next;

	temp->next = *store;
	(*store)->prev = temp;
	*store = (*store)->next;
	(*store)->prev->next = NULL;
	(*store)->prev = NULL;

}

/**
 * op_rotr - rotates the stack to the bottom
 * @store: Pointer to the stack.
 * @numr: Line number where the rotr function is called.
 */
void op_rotr(stack_t **store, unsigned int numr)
{
	stack_t *l;
	(void)numr;

	if (store == NULL || *store == NULL || (*store)->next == NULL)
		return;

	l = *store;

	while (l->next)
		l = l->next;

	l->prev->next = NULL;
	l->next = *store;
	l->prev = NULL;
	(*store)->prev = l;

	*store = l;
}

/**
 * op_queue - sets the format of the data to a queue (FIFO)
 * @store: head of the linked list
 * @numr: line number;
 * Return: no return
 */
void op_queue(stack_t **store, unsigned int numr)
{
	(void)store;
	(void)numr;

	jay.fifo = 0;
}

/**
 * op_stack - sets the format fo the data to a stack (LIFO)
 *
 * @store: head of the linked list
 * @numr: line number;
 * Return: no return
 */
void op_stack(stack_t **store, unsigned int numr)
{
	(void)store;
	(void)numr;

	jay.fifo = 1;
}

/**
 * _isascii - checks if a character is an ASCII character
 * @c: character to be checked
 * Return: 1 if ASCII, 0 otherwise
 */
int _isascii(char c)
{
	return ((unsigned char)c <= 127);
}
