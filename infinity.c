#include "shell_main.h"

/**
 * infinite_loop - infinite loop
 * @argv: argument value
 * @env: env values
 * Return: int
 */
int infinite_loop(char *argv, char **env)
{
	ssize_t buffer_size = 0;
	size_t read_size = 0;
	char *buffer = NULL;
	int infinite_count = 0, exit_status = 0, from_pipe = 0;

	while (1 && !from_pipe)
	{
		infinite_count++;
		if (isatty(STDIN_FILENO))
		{
			print_string("#cisfun$ ");
		}
		else
		{
			from_pipe = 1;
		}
		buffer_size = getline(&buffer, &read_size, stdin);
		if (buffer_size == -1 || string_compare("exit\n", buffer) == 0)
		{
			free(buffer);
			break;
		}
		if (buffer[buffer_size - 1] == '\n')
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
		exit_status = execute_command(buffer, argv, infinite_count, env);
	}
	return (exit_status);
}

