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
		_putchar('\n');
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
	int i = 0, j = 0;
	const char *env_variable;

	for (i = 0; environ[i] != NULL; i++)
	{
		env_variable = environ[i];

		while (env_variable[j] != '=' && env_variable[j] != '\0')
		{
			if (env_variable[j] != env_var[j])
			{
				break;
			}
			j++;
		}

		if (env_variable[j] == '=' && env_var[j] == '\0')
		{
			return ((char *)&env_variable[j + 1]);
		}
	}

	return (NULL);
}

