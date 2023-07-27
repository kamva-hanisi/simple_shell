#include "shell_main.h"

/**
 * main - simple shell
 * @argc: argument count
 * @argv: argument values
 * @env: env values
 * Return: int
 */
int main(__attribute__((unused)) int argc, char **argv, char **env)
{
	int exit_status = 0;

	if (argv[1] != NULL)
	{
		exit_status = read_arguments(argv);

		return (exit_status);
	}

	exit_status = infinite_loop(argv[0], env);

	return (exit_status);
}

