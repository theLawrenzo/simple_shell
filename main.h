#ifndef MANI_H
#define MAIN_H

#define ROW 30
#define COL 30

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wai.h>

typedef struct _path_to_dir {
	struct _path_to_dir *prev;
	struct _path_to_dir *next;
}_dir_link;


int prompt(char **ptr, size_t *n);
char **alloc_2darr(void);
char **tokens(char *str, char *delims);
int _which(char **av, char **env);
int shell(void);

#endif
