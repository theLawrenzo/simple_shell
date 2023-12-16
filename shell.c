#include "shell.c"

/**
 * shell - A simple command line interpreter
 *
 * Return: On success 0
 * On error or failure -1
 */
int shell(void)
{
	char *str, **av, **envp;
	size_t n;
	ssize_t line;
	pid_t pid;

	printf("$ ");
	while (1)
	{
		str = NULL;
		n = 0;
		line = _read(&str, &n, stdin);
		if (line < 0)
			fprintf(stderr, "Error:\n");
		av = split_str(str);
		/**
		 * Inside here create a function that checks
		 * for the path and call the function
		 */
		envp = getcwd();
		if (*av[i] == exit)
		{
			break;
		}
		/**
		 * check if the command exist in that path
		 * if it exits then create a new process
		 */
		pid = fork();
		if ((pid = fork()) < 0)
		{
			perror("Error:");
			exit(EXIT_FAILURE);
		}
		if (pid == 0)
		{
			if ((execve(av[0], av, envp)) < 0)
			{
				perror("Error:");
				exit(EXIT_FAILURE);
			}
		}
	}

	return (0);
}
