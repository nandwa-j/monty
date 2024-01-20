#include "monty.h"
/**
 * execute - selects the correct opcode to perform
 * @v: opcode passed
 *
 * Return: pointer to the function that executes the opcode
 */
void (*execute(char *v))(stack_t **store, unsigned int numr)
{
	instruction_t instruct[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{"swap", op_swap},
		{"queue", op_queue},
		{"stack", op_stack},
		{"add", op_add},
		{"nop", op_nop},
		{"sub", op_sub},
		{"mul", op_mul},
		{"div", op_div},
		{"mod", op_mod},
		{"pchar", op_pchar},
		{"pstr", op_pstr},
		{"rotl", op_rotl},
		{"rotr", op_rotr},
		{NULL, NULL}
	};
	int i;

	if (v == NULL)
	{
		return (NULL);
	}

	for (i = 0; instruct[i].opcode; i++)
	{
		if (_strcmp(instruct[i].opcode, v) == 0)
			break;
	}

	return (instruct[i].f);
}

/**
 * _strcmp - Function that compares two strings.
 * @s1: type str compared
 * @s2: type str compared
 * Return: 0 if s1 and s2 are equals.
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i] && s1[i]; i++)
		;
	if (s1[i] > s2[i])
		return (1);
	if (s1[i] < s2[i])
		return (-1);
	return (0);
}
