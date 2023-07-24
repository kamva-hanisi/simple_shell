#include "shell_main.h"

/**
 * memory_allocate - Use malloc to allocate memory for an array
 * @memory_array: array
 * @size: size
 * Return: pointer or NULL
 */
void *memory_allocate(unsigned int memory_array, unsigned int size)
{
	unsigned int index = 0;
	char *memory_pointer = NULL;

	if (memory_array == 0 || size == 0)
		return (NULL);

	memory_pointer = malloc(memory_array * size);

	if (memory_pointer == NULL)
		return (NULL);

	for (; index < (memory_array * size); index++)
		memory_pointer[index] = 0;

	return (memory_pointer);
}

