#include "shell.h"

/**
 * prompt - Prompt the user
 *
 * Return: Always 0
 */
int prompt(char *str, size_t n)
{
	printf("$ ");
	if ((getline(&str, &n, stdin)) < 0)
	{
		perror("error:");
		return (-1);
	}
	if ((write(STDOUT_FILENO, str, sizeof(str))) < 0)
	{
		perror("error:");
		return (-1);
	}
	return (0);
}
