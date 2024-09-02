#include "shell.h"

char **new_strtok(char *string, char *delim);
int count(char *cmd, char c);

/**
 * main - Test the new_strtok function
 *
 * Return: Always 0
 */
int main(void)
{
	char *about = "My name is Kome, and I love coding";
	char *delim = ", ";
	char **tkns;
	int i;

	tkns = new_strtok(about, delim);
	if (tkns == NULL)
		exit(EXIT_FAILURE);

	for (i = 0; tkns[i] != NULL; i++)
		printf("%s\n", tkns[i]);

	free(tkns);
	return (0);
}


/**
 * count - counts the number of delimiters in a string
 * @cmd: Strings
 * @sep: Delimiter to count
 *
 * Return: len
 */
int count(char *cmd, char c)
{
	int i, len, n;

	len = 0;
	for (n = strlen(cmd), i = 0; i < n; i++)
		if (cmd[i] == c)
			len++;

	return (len + 1);
}


/**
 * new_strtok - Tokenizes a string
 * @string: String to tokenize
 * @delim: Delimiter
 *
 * Return: tkns
 */
char **new_strtok(char *string, char *delim)
{
	char **tkns;
	int i, len;

	len = count(string, ' ');
	tkns = calloc(len + 1, sizeof(char *));
	if (tkns == NULL)
		return (NULL);

	i = 0;
	tkns[i] = strtok(string, delim);
	for (i = 1; ; i++)
	{
		tkns[i] = strtok(NULL, delim);
		if (tkns[i] == NULL)
			break;
	}
	return (tkns);
}
