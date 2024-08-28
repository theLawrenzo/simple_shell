#include "shell.h"

/**
 * main - Test the build_list function
 *
 * Return: Always 0
 */
/*
int main(void)
{
	dir_list *head, *tmp;
	char *env_var, **tokens, *full_path;

	env_var = my_getenv("PATH");
	if (env_var == NULL)
	{
		printf("my_getenv function failed\n");
		exit(EXIT_FAILURE);
	}

	tokens = my_strtok(env_var, ":");
	if (tokens == NULL)
	{
		printf("my_strtok function failed\n");
		exit(EXIT_FAILURE);
	}

	head = build_list(tokens);
	if (head == NULL)
	{
		printf("build_list function failed\n");
		exit(EXIT_FAILURE);
	}

	tmp = head;
	while (tmp != NULL)
	{
		printf("%s\n", tmp->path);
		tmp = tmp->next;
	}

	full_path = pathname(head, "ls");
	if (full_path == NULL)
	{
		printf("pathname function failed\n");
		exit(EXIT_FAILURE);
	}
	else
		printf("The full path of \'ls\' is %s\n", full_path);

	printf("Success\n");
	return (0);
}
*/

/**
 * build_list - Builds a linked list from an array of strings
 * @tokens: Pointer to strings to build list from
 *
 * Return: head
 */
dir_list *build_list(char **tokens)
{
	dir_list *head, *tmp, *new;
	int i;

	head = NULL;
	i = 0;
	while (tokens[i] != NULL)
	{
		new = malloc(sizeof(dir_list));
		if (new == NULL)
			return (NULL);

		new->path = tokens[i];
		new->next = NULL;

		if (head == NULL)
			head = new;
		else
		{
			tmp = head;
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = new;
		}
		i++;
	}

	return (head);
}
