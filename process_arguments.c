#include "shell_main.h"

/**
 * read_arguments - Reading contents of a file
 * @argv: argument values
 * Return: 0 or 1
 */
int read_arguments(char **argv)
{
	if (
		string_compare("-h", argv[1]) == 0 ||
		string_compare("--help", argv[1]) == 0)
	{
		read_textfile("help.txt");

		return (0);
	}

	print_string(argv[0]);
	print_string(": ");
	print_string(argv[1]);
	print_string(": invalid option\n");
	read_textfile("help.txt");

	return (1);
}

