#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_LEN 120
#define MAX_ARG 20

int _putchar(char c);
int prompt(char *str, size_t n);
ssize_t _read(char **str, size_t *n, FILE *stream);
char **split_str(char *str, char *sep);
int shell(void);

#endif
