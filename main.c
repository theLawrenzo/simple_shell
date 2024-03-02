#include "shell.h"

/**
 * main - A simple UNIX command line interpreter
 *
 * Return: Always 0.
 */
int main(void)
{
	char *env_var, **args, *path;
	char *str = NULL;
	char *exit_cmd = "exit";
	size_t n = 0;
	int i;

	while (1)
	{
		if (prompt(str, n) == 1)
		{
			perror("Error:");
			exit(EXIT_FAILURE);
		}
		env_var = _getenv("PATH");
		if (env_var == NULL)
		{
			perror("Error:");
			exit(EXIT_FAILURE);
		}
		args = split(env_var, " ");
		if (args == NULL)
		{
			perror("Error:");
			exit(EXIT_FAILURE);
		}
		if (args[0] == exit_cmd)
			break;
		i = 0;
		while (args[i] != NULL)
		{
			path = find_cmd(args[i]);
			if (path == NULL)
			{
				perror("Error:");
				exit(EXIT_FAILURE);
			}
			if (execute(args) == 1)
			{
				perror("Error:");
				exit(EXIT_FAILURE);
			}
			i++;
		}
	}

	return (0);
}
