#include "shell_main.h"

/**
 * path_search - search file between the path
 * @command: cmd
 * Return: cmd path
 */
char *path_search(char *command)
{
	char *path = getenv("PATH"),
		 *copy_path, **path_split, *path_concat = NULL;
	int i = 0, path_len = 0, found_command = 0;
	struct stat info;

	if (stat(command, &info) == 0)
		return (command);

	if (path == NULL)
	{
		return (NULL);
	}

	copy_path = malloc(get_str_len(path) + 1);
	copy_path = string_copy(copy_path, path);
	path_split = split_args(copy_path, ":");

	while (path_split[i])
	{
		path_len = get_str_len(path_split[i]);
		if (path_split[i][path_len - 1] != '/')
			path_concat = join_strings(path_split[i], "/");

		path_concat = join_strings(path_concat, command);
		if (stat(path_concat, &info) == 0)
		{
			found_command = 1;
			break;
		}
		i++;
	}

	free(path_split);

	if (found_command == 0)
	{
		return (NULL);
	}

	return (path_concat);
}

