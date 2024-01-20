#include "monty.h"

int char_search(char *str, char c)
{
	int index = 0;

	while (str[index] != '\0')
	{
		if (str[index] == c)
		{
			return (1);
		}
		index++;
	}

	return (0);
}

char *custom_strtok(char *str, char *delimiters)
{
	static char *lastToken;
	char *currentTokenStart = NULL;

	if (!str)
	{
		str = lastToken;
	}

	while (*str != '\0' && char_search(delimiters, *str))
	{
		str++;
	}

	if (*str == '\0')
	{
		lastToken = NULL;
		return (NULL);
	}

	currentTokenStart = str;

	while (*str != '\0' && !char_search(delimiters, *str))
	{
		str++;
	}

	if (*str != '\0')
	{
		*str = '\0';
		lastToken = str + 1;
	}
	else
	{
		lastToken = NULL;
	}
	return (currentTokenStart);
}

