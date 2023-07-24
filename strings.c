#include "shell_main.h"

/**
 * string_compare - comparing two input strings
 * @first_str: string pointer 1
 * @second_str: string pointer 2
 * Return: result
 */
int string_compare(char *first_str, char *second_str)
{
	while (*first_str && *second_str)
	{
		if (*first_str != *second_str)
			return (*first_str - *second_str);

		first_str++;
		second_str++;
	}
	return (0);
}

/**
 * split_args - split string in pieces
 * @str: string to split
 * @separator: string separator
 * Return: divided path
 */
char **split_args(char *str, char *separator)
{
	char **split, *aux;
	int i = 0;

	aux = strtok(str, separator);
	split = (char **)memory_allocate(100, sizeof(char *));

	if (!split)
	{
		free(split);
		return (NULL);
	}

	while (aux)
	{
		split[i] = aux;
		aux = strtok(NULL, separator);
		i++;
	}
	return (split);
}

/**
 * join_strings - Join two strings
 * @dest: string
 * @src: string
 * Return: @dest
 */
char *join_strings(char *dest, char *src)
{
	int a, b;

	for (a = 0; dest[a] != '\0'; a += 1)
	{
	}

	for (b = 0; src[b] != '\0'; b += 1)
	{
		dest[a] = src[b];
		a++;
	}
	dest[a] = '\0';
	return (dest);
}

/**
 * string_copy - Copies the string
 * @destination: destination
 * @source: source
 * Return: the destination
 */
char *string_copy(char *destination, char *source)
{

	size_t a;

	for (a = 0; source[a] != '\0'; a++)
	{
		destination[a] = source[a];
	}
	destination[a] = '\0';

	return (destination);
}

/**
 * get_str_len - get string length
 * @str: string
 * Return: result
 */
int get_str_len(char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;

	return (i);
}

