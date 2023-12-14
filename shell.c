#include "shell.h"

/**
 * shell - my shell
 *
 * Return: Always 0
 */
int shell(void)
{
	char *args[MAX_ARG];
	char cmd[MAX_LEN];
	char *tkn;
	int i;
	pid_t pid;

	while (1)
	{
		fprintf(stdout, "$ ");
		fgets(cmd, sizeof(cmd), stdin);
		cmd[strcspn(cmd, "\n")] = '\0';

		if ((strcmp(cmd, "exit")) == 0)
		{
			break;
		}
	}

	tkn = strtok(cmd, " ");
	i = 0;

	while (tkn != NULL && i < MAX_ARG - 1)
	{
		args[i] = tkn;
		tkn = strtok(NULL, " ");
		i++;
	}
	args[i] = NULL;

	pid = fork();
	if (pid < 0)
	{
		perror("Error");
	}
	if (pid == 0)
	{
		if ((execve(args[0], args, NULL)) < 0)
		{
			perror("Error");
		}
	}
	else
	{
		wait(NULL);
	}

	return (0);
}
