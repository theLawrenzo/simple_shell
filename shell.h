#ifndef SHELL_H
#define SHELL_H

#define MAX 100
#define BUF 50
#define ROW 50
#define COL 50

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

extern char **environ;

int prompt(char *str, size_t n);
char *_getenv(char *str);
char **split(char *str, const char *delim);
char *find_cmd(const char *cmd);
int execute(char **args);

#endif
