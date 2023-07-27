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

	for (i = 0; environ[i] != NULL; i++)
	{

		for (j = 0; env_var[j] != '\0' && environ[i][j] != '\0'; j++)
		{
			if (env_var[j] != environ[i][j])
			{
				break;
			}
		}

		if (env_var[j] == '\0' && environ[i][j] == '=')
		{
			return (&environ[i][j + 1]);
		}
	}

	return (NULL);
}

