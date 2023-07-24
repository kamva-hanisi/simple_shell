#ifndef SHELL_MAIN_H
#define SHELL_MAIN_H

/*LIBRARIES*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>

int string_compare(char *first_str, char *second_str);
char *path_search(char *command);
char **split_args(char *str, char *separator);
char *join_strings(char *dest, char *src);
int get_str_len(char *str);
char *string_copy(char *destination, char *source);
char *get_env_variable(char *env_var);
void *_calloc(unsigned int nmemb, unsigned int size);
void print_env_variables(void);
int execute(char **args);
int is_empty_line(char *buffer);
void print_string(char *str);

/* GLOBAL VAR*/
extern char **environ;

#endif
