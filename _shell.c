#include "main.h"

/**
 * main - mini UNIX command line iterpreter
 *
 * Return: Always 0
 */
int main(void)
{
	pid_t child_pid;
	int status, i;
	size_t n;
	char *str;
	struct stat st;
	char *argv[BUF];

	while (1)
	{
		str = NULL;
		n = i = 0;
		printf("$ ");
		if (getline(&str, &n, stdin) == -1)
		{
			perror("Error:");
			exit(EXIT_FAILURE);
		}
		argv[i] = strtok(str, " ");
		while (argv[i] != NULL)
			argv[i++] = strtok(NULL, " ");
		i = 0;
		while (argv[i] != NULL)
		{
			if (stat(argv[i], &st) == 0)
			{
				i++;
				continue;
			}
			else
			{
				perror("Error:");
				exit(EXIT_FAILURE);
			}
		}
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			exit(EXIT_FAILURE);
		}
		if (child_pid == 0)
		{
			if (execve(argv[0], argv, environ) == -1)
			{
				perror("Error:");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(&status);
		}
	}
	return (0);
}
