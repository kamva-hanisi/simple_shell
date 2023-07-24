#include "shell_main.h"

/**
 * execute - execute command path, child process
 * @args: arguments
 * Return: exit status
 */
int execute(char **args)
{
	int id = fork(), status = 0;

	if (id == 0)
	{
		if (execve(args[0], args, environ) == -1)
			perror("Test");
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			status = WEXITSTATUS(status);
	}

	return (status);
}

/**
 * read_textfile - Read file and write to stdout
 * @filename: file to read
 * Return: status
 */
ssize_t read_textfile(const char *filename)
{
	ssize_t file_open, reader;
	char buffer[BUFFER_SIZE];

	if (filename == NULL)
	{
		perror("Error no filename");
		return (1);
	}

	file_open = open(filename, O_RDONLY);
	if (file_open == -1)
	{
		perror("Error opening the file");
		return (1);
	}

	while ((reader = read(file_open, buffer, BUFFER_SIZE)) > 0)
	{
		write(STDOUT_FILENO, buffer, reader);
	}

	if (reader == -1)
	{
		perror("Error reading the file");
		close(file_open);
		return (1);
	}

	if (close(file_open) == -1)
	{
		perror("Error closing the file");
		return (1);
	}

	write(1, "\n", 1);

	return (0);
}

