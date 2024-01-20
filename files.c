#include "monty.h"

/**
 * free_jay - frees the global variables
 * Return: no return
 */
void free_jay(void)
{
	free_dlistint(jay.head);
	free(jay.buffer);
	fclose(jay.fd);
}

/**
 * start_jay - initializes the global variables
 * @fd: file descriptor
 * Return: no return
 */
void start_jay(FILE *fd)
{
	jay.fifo = 1;
	jay.cont = 1;
	jay.arg = NULL;
	jay.head = NULL;
	jay.fd = fd;
	jay.buffer = NULL;
}

/**
 * check_input - checks if the file exists and if the file can
 * be opened
 * @argc: argument count
 * @argv: argument vector
 * Return: file struct
 */
FILE *c_input(int argc, char *argv[])
{
	FILE *fd;

	if (argc == 1 || argc > 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");

	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	return (fd);
}
