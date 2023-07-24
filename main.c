#include "shell_main.h"

/**
 * main - simple shell
 * Return: int
 */
int main(void)
{
	size_t read_size = 0;
	char *buffer = NULL, **arguments;
	int exit_status = 0, infinite_loop = 1;
	ssize_t buffer_size = 0;

	// Infinite loop
	while (infinite_loop)
	{
		if (isatty(0))
			printf("#cisfun$ ");

		buffer_size = getline(&buffer, &read_size, stdin);

		if (buffer_size == -1 || string_compare("exit\n", buffer) == 0)
		{
			free(buffer);
			break;
		}

		buffer[buffer_size - 1] = '\0';

		if (is_empty_line(buffer) == 1)
		{
			exit_status = 0;
			continue;
		}

		if (string_compare("env", buffer) == 0)
		{
			print_env_variables();
			continue;
		}

		arguments = split_args(buffer, " ");
		arguments[0] = path_search(arguments[0]);
		if (arguments[0] != NULL)
			exit_status = execute(arguments);
		else
			perror("Error");

		free(arguments);
	}
	return (exit_status);
}
