#include "shell_main.h"

/**
 * print_env_variables - print environment variables
 */
void print_env_variables(void)
{
	int i = 0;

	while (environ[i])
	{
		print_string(environ[i]);
		i++;
	}
}

/**
 * get_env_variable - get an env variable
 * @env_var: env variable
 * Return: env variable result, its content
 */
char *get_env_variable(char *env_var)
{
	int i = 0, j;
	int status;

	while (environ[i])
	{
		status = 1;

		for (j = 0; environ[i][j] != '='; j++)
		{
			if (environ[i][j] != env_var[j])
				status = 0;
		}
		if (status == 1)
			break;
		i++;
	}
	return (&environ[i][j + 1]);
}

