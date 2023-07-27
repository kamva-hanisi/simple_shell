#ifndef SHELL_MAIN_H
#define SHELL_MAIN_H

/*LIBRARIES*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

int _putchar(char c);
int string_compare(char *first_str, char *second_str);
char *path_search(char *command);
char **split_args(char *str, char *separator);
char *join_strings(char *dest, char *src);
int get_str_len(char *str);
char *string_copy(char *destination, char *source);
char *get_env_variable(char *env_var);
void *memory_allocate(unsigned int nmemb, unsigned int size);
void print_env_variables(void);
int execute(char **args, char *script_file, int infinite_count);
int is_empty_line(char *buffer);
void print_string(char *str);
ssize_t read_textfile(const char *filename);
int read_arguments(char **argv);
int execute_command(char *buffer, char *script_file, int infinite_count);
int print_int(int number);
int infinite_loop(char *argv);

/* GLOBAL VAR*/
extern char **environ;

#endif

