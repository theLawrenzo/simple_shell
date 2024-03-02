#include "shell.h"

/**
 * prompt - Prompt
 * @str: Pointer to string
 * @n: sizeof string
 *
 * Return: Always 0
 */
int prompt(char *str, size_t n)
{
	printf("$ ");
	if (getline(&str, &n, stdin) == -1)
		return (1);

	return (0);
}


/**
 * _getenv - Gets an environment variable
 * @str: Variable NAME
 *
 * Return: var
 */
char *_getenv(char *str)
{
	int i, j;
	char *tmp, c;

	i = 0;
	while (environ[i] != NULL)
	{
		j = 0;
		tmp = environ[i];
		while (tmp[j] != '=')
			j++;
		c = tmp[j];
		tmp[j] = '\0';
		if (strcmp(tmp, str) == 0)
		{
			tmp[j] = c;
			break;
		}
		i++;
	}
	if (environ[i] == NULL)
		return (NULL);

	return (environ[i]);
}

/**
 * split - Function that splits strings
 * @str: string to split
 * @delim: deliminter
 *
 * Return: Always 0.
 */
char **split(char *str, const char *delim)
{
	int i;
	char **av;

	if (str == NULL)
		return (NULL);
	av = malloc(sizeof(char *) * BUF);
	if (av == NULL)
		return (NULL);
	i = 0;
	*(av + i) = strtok(str, delim);
	while (*(av + i) != NULL)
	{
		i++;
		*(av + i) = strtok(NULL, delim);
	}
	return (av);
}

/**
 * find_cmd - Find file/cmd in the PATH variable
 * @cmd: Name of file
 *
 * Return: NULL
 */
char *find_cmd(const char *cmd)
{
	char *env_var;
	char *tmp_env;
	char *direct;
	char *nxt_dir;
	char *abs_path;
	int len;

	env_var = _getenv("PATH");
	if (env_var == NULL)
		return (NULL);
	tmp_env =strdup(env_var);
	if (tmp_env == NULL)
		return (NULL);
	direct = tmp_env;
	while (direct != NULL)
	{
		nxt_dir = strchr(direct, ':');
		if (nxt_dir)
			len = nxt_dir - direct + 1 + strlen(cmd) + 1;
		else
			len = strlen(direct) + 1 + strlen(cmd) + 1;
		abs_path = malloc(len);
		if (abs_path == NULL)
		{
			free(tmp_env);
			return (NULL);
		}
		if (nxt_dir)
			strncpy(abs_path, direct, nxt_dir - direct);
		else
			strcpy(abs_path, direct);
		strcat(abs_path, "/");
		strcat(abs_path, cmd);
		if (access(abs_path, X_OK) == 0)
		{
			free(tmp_env);
			return (abs_path);
		}
		free(abs_path);
		direct = nxt_dir ? nxt_dir + 1 : NULL;
	}
	free(tmp_env);
	return (NULL);
}

/**
 * execute - Function that executes commands
 * @args: Command to execute
 *
 * Return: 0 on success
 */
int execute(char **args)
{
	int status;
	pid_t my_pid;

	my_pid = fork();
	if (my_pid == -1)
	{
		perror("Error:");
		return (1);
	}
	else if (my_pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			perror("Error:");
			return (1);
		}
	}
	else
		wait(&status);

	return (0);
}
