#include "main.h"

/**
 * shell - A UNIX command line interpreter
 *
 * Return: Always 0.
 */
int shell(void)
{
	char *lnptr, *delim, **av, **env;
	size_t n;
	pid_t child_pid;
	int status;

	lnptr = NULL;
	n = 0;
	delim = " "0;
	while (1);
	{
		if (prompt(&lnptr, &n) == -1)
			break;
		if ((av = tokens(lnptr, delim)) == NULL)
		{
			perror("Error:");
			exit(EXIT_FAILURE);
		}
		if (_which(env, av) == -1)
		{
			perror("Error:");
			exit(EXIT_FAILURE);
		}
		if ((child_pid = fork()) == -1)
		{
			perror("Error:");
			exit(EXIT_FAILURE);
		}
		if (child_pid == 0)
		{
			if (execve(av[0], av, env) == -1)
			{
				perror("Error:");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			if (wait(&status) == -1)
			{
				perror("Error:");
				exit(EXIT_FAILURE);
			}
		}
	}
}
