#include "shell.h"


/**
 * pathname - Returns the full pathname of a file if it
 * exists and it's executable
 * @head: Pointer to the head of a linked list
 * @file: File to check
 *
 * Return: Always 0
 */
char *pathname(char **str, char *file)
{
	char *full_path, **tmp;
	int i, file_mode;

	if (str == NULL)
		return (NULL);

	tmp = str;
	i = 0;
	while (tmp[i] != NULL)
	{
		/*
		full_path = strcat(tmp->path, file);
		file_mode = access(full_path, F_OK | X_OK);
		*/
		full_path = strcat(tmp[i], "/");
		full_path = strcat(full_path, file);
		file_mode = access(full_path, F_OK | X_OK);
		if (file_mode == 0)
			break;
		i++;
	}

	return (full_path);
}
