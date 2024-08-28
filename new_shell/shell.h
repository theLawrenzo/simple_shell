#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>

extern char **environ;

/**
 * struct build_list - Singly linked list
 * @path: Pathname of a shell command
 * @next: Pointer to the next directory
 *
 * Description: Builds a singly linked list of an environment variable directories
 */
typedef struct list_of_dirs {
	char *path;
	struct list_of_dirs *next;
}dir_list;

/* Counts the number of times 'c' appears in s the string 'str' */
int count_tokens(char *str, char *c);
/* Returns the value of an environment variable */
char *my_getenv(char *str);
/* Reads commands typed in from stream to lineptr, and uses n to keep track of size */
ssize_t my_getline(char **lineptr, size_t *n, FILE *stream);
/* Tokenizes str using sep as the delimiter and returns the address og the first string-token */
char **my_strtok(char *str, char *sep);
/* Builds a linked list of directories from an array of strings */
dir_list *build_list(char **tokens);
/* Returns the full pathname of a file if it exists and is executable */
char *pathname(dir_list *head, char *file);
/* Prompts the users to type in commands at the CLI */
ssize_t prompt(char **lineptr, size_t *n, FILE *stream);

#endif
