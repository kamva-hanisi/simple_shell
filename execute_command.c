#include "shell_main.h"

/**
 * execute - execute command path, child process
 * @buffer: Buffer
 * @script_file: Executing file
 * @infinite_count: Infinite counting
 * Return: exit status
 */
int execute_command(char *buffer, char *script_file, int infinite_count)
{
	char **arguments, *first_arg;
	int exit_status = 0;

	arguments = split_args(buffer, " ");
	first_arg = arguments[0];

	arguments[0] = path_search(arguments[0]);
	if (arguments[0] != NULL)
	{
		exit_status = execute(arguments, script_file, infinite_count);
	}
	else
	{
		print_string(script_file);
		print_string(": ");
		print_int(infinite_count);
		print_string(": ");
		print_string(first_arg);
		print_string(": not found\n");
		exit_status = 1;
	}

	free(arguments);

	return (exit_status);
}

