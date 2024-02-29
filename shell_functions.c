#include "main.h"

/**
 * prompt - Prompt for the user
 *
 * Return: Always 0
 */
int prompt(char *ptr, size_t n)
{
	printf("$ ");
	if (getline(&ptr, &n) == -1)
	{
		perror("Error:");
		return (-1);
	}
	return (0);
}

/**
 * alloc_2darr - Allocate a two dimensional array of pointers
 *
 * Return: av on success
 * Otherwise NULL
 */
char **alloc_2darr(void)
{
	char **av;
	int i, j;

	av = malloc(sizeof(char *) * ROW);
	if (av == NULL)
		return (NULL);
	for (i = 0; i < ROW; i++)
	{
		av[i] = malloc(sizeof(char) * COL);
		if (av[i] == NULL)
		{
			free(av[i -1]);
			free(av);
			return (NULL);
		}
	}

	return (av);
}

/**
 * tokens - Splits a string to sub_strings
 * @str: String to split
 *
 * Return: av
 */
char **tokens(char *str, char *delim)
{
	char **av;
	int i, j, k;

	av = alloc_2darr();
	if (av == NULL)
		return (NULL);
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; str[j] != '\n'; j++)
		{
			for (k = 0; k < (int)strlen(delim); k++)
			{
				if (str[j] == delim[k])
				{
					av[i][j] = '\0';
					str = &str[j + 1];
				}
				if (str[j] == '\0')
				{
					av[i][j] = '\0';
					av[i + 1] = NULL;
					return (av);
				}
			}
			av[i][j] = str[j];
		}
	}
	return (av);
}

/**
 * _which - Finds a file in an environment variable
 *
 * Return: Always 0.
 */
int _which(char **av, char **env)
{
	unsigned int i;
	struct stat st;

	env[0] = getenv("PATH");
	env[1] = NULL;
	i = 0;
	while (av[i])
	{
		if (stat(av[i], &st) == 0)
			return (0);
		else
			return (-1);
		i++;
	}
	return (0);
}
