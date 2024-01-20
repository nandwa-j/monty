#ifndef _MONTY_H
#define _MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <limits.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct global_s - global structure to use in the functions
 * @fifo: is stack or queue
 * @cont: current line
 * @arg: second parameter inside the current line
 * @head: doubly linked list
 * @fd: file descriptor
 * @buffer: input text
 *
 * Description: doubly linked list node structure
 */
typedef struct global_s
{
	int fifo;
	unsigned int cont;
	char  *arg;
	stack_t *head;
	FILE *fd;
	char *buffer;

} global_t;

extern global_t jay;

/* implement */
int is_integer(char *str);
void op_push(stack_t **store, unsigned int numr);
void op_pall(stack_t **store, unsigned int numr);
int _sch(char *s, char c);
char *custom_strtok(char *s, char *d);
void *_calloc(unsigned int num, unsigned int size);
void *_realloc(void *p, unsigned int old, unsigned int y);
stack_t *add_dnodeint_end(stack_t **head, const int n);
stack_t *add_dnodeint(stack_t **head, const int n);
void free_dlistint(stack_t *head);
int is_integer(char *str);
void op_swap(stack_t **store, unsigned int nmr);
void op_add(stack_t **store, unsigned int nmr);
void op_nop(stack_t **store, unsigned int nmr);
void op_sub(stack_t **store, unsigned int nmr);
void op_push(stack_t **store, unsigned int numr);
void op_pall(stack_t **store, unsigned int numr);
void op_pint(stack_t **store, unsigned int numr);
void op_pop(stack_t **store, unsigned int numr);
void op_rotl(stack_t **store, unsigned int numr);
void op_rotr(stack_t **store, unsigned int numr);
void op_queue(stack_t **store, unsigned int numr);
void op_stack(stack_t **store, unsigned int numr);
void op_div(stack_t **store, unsigned int numr);
void op_mul(stack_t **store, unsigned int numr);
void op_mod(stack_t **store, unsigned int numr);
void op_pchar(stack_t **store, unsigned int numr);
void op_pstr(stack_t **store, unsigned int numr);
void (*execute(char *v))(stack_t **store, unsigned int numr);
int _strcmp(char *s1, char *s2);
void free_jay(void);
void start_jay(FILE *fd);
FILE *c_input(int argc, char *argv[]);
int _isascii(char c);
#endif /* MONTY_H */
