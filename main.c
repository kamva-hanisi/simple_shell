#include "shell_main.h"

// TODO: Showing Error: No such file or directory instead of ./shell: No such file or directory

/**
 * main - simple shell
 * Return: int
 */
int main(__attribute__((unused)) int argc, char **argv)
{
	size_t read_size = 0;
	char *buffer = NULL;
	int exit_status = 0, infinite_loop = 1, infinite_count = 0;
	ssize_t buffer_size = 0;

	// Checking if there are arguments
	if (argv[1] != NULL)
	{
		exit_status = read_arguments(argv);

		return (exit_status);
	}

	// Infinite loop
	while (infinite_loop)
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

		exit_status = execute_command(buffer, argv[0], infinite_count);
	}
	return (exit_status);
}

