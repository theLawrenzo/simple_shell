#include "shell.h"

/**
 * pathname - Returns the full pathname of a file if it
 * exists and it's executable
 * @head: Pointer to the head of a linked list
 * @file: File to check
 *
 * Return: Always 0
 */
char *pathname(dir_list *head, char *file)
{
	dir_list *tmp;
	char *full_path;
	int file_mode;

	if (head == NULL)
		return (NULL);

	tmp = head;
	while (tmp != NULL)
	{
		full_path = strcat(tmp->path, "/");
		full_path = strcat(full_path, file);
		file_mode = access(full_path, F_OK | X_OK);

		if (file_mode == 0)
			break;
		tmp = tmp->next;
	}

	return (full_path);
}
