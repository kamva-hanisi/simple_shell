#include "shell_main.h"

/**
 * is_empty_line - checks if there is a empty line
 * @buffer: input line
 * Return: 0 or 1 (int)
 */
int is_empty_line(char *buffer)
{
	int i;

	for (i = 0; buffer[i] != '\0'; i++)
	{
		if (buffer[i] != ' ')
			return (0);
	}
	return (1);
}

