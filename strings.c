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
 * @first_str: string
 * @second_str: string
 * Return: @dest
 */
char *join_strings(char *first_str, char *second_str)
{
	size_t length_str1 = strlen(first_str), length_str2 = strlen(second_str),
		   i, j, total = length_str1 + length_str2 + 1;
	char *combined_strings = (char *)malloc((total) * sizeof(char));

	if (combined_strings == NULL)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < length_str1; i++)
	{
		combined_strings[i] = first_str[i];
	}

	for (j = 0; j < length_str2; j++, i++)
	{
		combined_strings[i] = second_str[j];
	}

	combined_strings[i] = '\0';

	return (combined_strings);
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

