#include <stdio.h>
#include <string.h>
#include "monty.h"

/**
 * main - Entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success
 */
global_t jay;

int main(int argc, char *argv[])
{
	void (*f)(stack_t **stack, unsigned int line_number);
	FILE *fd;
	char buffer[256];
	char *lines[2] = {NULL, NULL};

	fd = c_input(argc, argv);
	start_jay(fd);

	while (fgets(buffer, sizeof(buffer), fd) != NULL)
	{
		lines[0] = custom_strtok(buffer, " \t\n");
		if (lines[0] && lines[0][0] != '#')
		{
			f = execute(lines[0]);
			if (!f)
			{
				fprintf(stderr, "L%u: unknown instruction %s\n", jay.cont, lines[0]);
				free_jay();
				exit(EXIT_FAILURE);
			}
			jay.arg = custom_strtok(NULL, " \t\n");
			f(&jay.head, jay.cont);
		}
		jay.cont++;
	}

	free_jay();

	return (0);
}

