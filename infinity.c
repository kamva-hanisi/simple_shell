#include "shell_main.h"

/**
 * infinite_loop - infinite loop
 * @argv: argument value
 * Return: int
 */
int infinite_loop(char *argv)
{
	ssize_t buffer_size = 0;
	size_t read_size = 0;
	char *buffer = NULL;
	int infinite_count = 0, exit_status = 0;

	while (1)
	{
		infinite_count++;
		if (isatty(0))
			print_string("#cisfun$ ");
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
		exit_status = execute_command(buffer, argv, infinite_count);
	}
	return (exit_status);
}

