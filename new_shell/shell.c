#include "shell.h"

/**
 * main - Program that mimics the bash shell
 *
 * Return: Always 0
 */
int main(void)
{
	char **argv, **envp, *lineptr = NULL;
	pid_t child_pid;
	int wstatus, i;
	size_t n = 0;
	ssize_t __attribute__((unused))rd_line;

	envp = malloc(2 * sizeof(char *));
	if (envp == NULL)
		return (-1);
	envp[0] = _getenv("PATH");
	if (envp[0] == NULL)
	{
		perror("getenv");
		return (96);
	}
	envp[1] = NULL;
	i = 0;
	while (1)
	{
		rd_line = prompt(&lineptr, &n, stdin);
		if (rd_line == -1)
			continue;
		argv = my_strtok(lineptr, " ");
		if (argv == NULL)
			return (-1);
		while (argv[i] != NULL)
		{
			if (*argv[0] == '-')
				continue;

			child_pid = fork();
			if (child_pid == -1)
			{
				perror("Error");
				exit(EXIT_FAILURE);
			}

			if (child_pid == 0)
			{
				if (execve(argv[0], argv, envp) == -1)
				{
					perror("Error");
					exit(EXIT_FAILURE);
				}
			}
			else
			{
				if (wait(&wstatus) == -1)
				{
					perror("Wait");
					exit(EXIT_FAILURE);
				}
			}
			i++;
		}
	}

	return (0);
}
