#include "shell.h"

/**
 * main - checks file status
 *
 * Return: Always 0
 */
int main(void)
{
	char **files;
	struct stat statbuf;
	int status, i;

	files = calloc(6, sizeof(const char *));
	if (files == NULL)
		exit(EXIT_FAILURE);

	files[0] = "ls";
	files[1] = "/usr/bin/ls";
	files[2] = "/usr/bin/cd";
	files[3] = "cd";
	files[4] = "/usr/bin/ps";
	files[5] = NULL;

	for (i = 0; files[i] != NULL; i++)
	{
		status = stat(files[i], &statbuf);
		if (status == -1)
			printf("%s -- Not Found\n", files[i]);
		else
			printf("%s -- Found\n", files[i]);
	}

	free(files);

	return (0);
}
