#include "shell.h"

/**
 * main - Test functions: pathname, build_list, my_getline,
 * strtok, count_tokens, my_getenv
 *
 * Return: Always 0
 */
int main(void)
{
	dir_list *head;
	char **env_tokens, *full_path;
	char *env_var, *lineptr = NULL;
	size_t i, n = 0;
	ssize_t line_read;

	env_var = my_getenv("PATH");
	if (env_var == NULL)
	{
		printf("my_getenv function failed\n");
		exit(EXIT_FAILURE);
	}

	printf("%s\n", env_var);

	env_tokens = my_strtok(env_var, ":");
	if (env_tokens == NULL)
	{
		printf("my_strtok function failed\n");
		exit(EXIT_FAILURE);
	}

	for (i = 0; env_tokens[i] != NULL; i++)
		printf("%s\n", env_tokens[i]);

	line_read = my_getline(&lineptr, &n, stdin);
	if (line_read == -1)
	{
		printf("my_getline function failed\n");
		exit(EXIT_FAILURE);
	}

	head = build_list(env_tokens);
	if (head == NULL)
	{
		printf("build_list function failed\n");
		exit(EXIT_FAILURE);
	}

	full_path = pathname(head, lineptr);
	if (full_path == NULL)
	{
		printf("pathname function failed\n");
		exit(EXIT_FAILURE);
	}

	printf("\nThe full path of %s is %s\n", lineptr, full_path);

	return (0);
}
