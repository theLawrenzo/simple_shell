#include "shell.h"

char **my_strtok(char *command, char *sep);
int count(char *command, char c);

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	char *commands = "I love programming";
	char *sep = " ,";
	char **tokens;
	int i;

	tokens = my_strtok(commands, sep);
	if (tokens == NULL)
		exit(EXIT_FAILURE);

	i = 0;
	while (tokens[i] != NULL)
	{
		printf("%s\n", tokens[i]);
		i++;
	}

	free(tokens);

	return (0);
}


/**
 * my_strok - Tokenize a string
 * @command: String to split into tokens
 * @sep: Separators of the string
 *
 * Return: tokens
 */
char **my_strtok(char *command, char *sep)
{
	char **tkns, **dup_tkns, *sep_addr;
	int i, c/*len*/, cmd_counts;

	cmd_counts = count(command, ' ');
	tkns = calloc(cmd_counts + 1, sizeof(char *));
	if (tkns == NULL)
		return (NULL);
	dup_tkns = tkns;
	/*len = strlen(command);*/
	i = 0;
	while (command[i] != '\0')
	{
		c = (int)command[i];
		sep_addr = strchr(sep, c);
		if (sep_addr == NULL)
		{
			i++;
			continue;
		}
		else
		{
			command[i] = '\0';
			/*
			*dup_tkns = command;
			dup_tkns++;
			*/
			*dup_tkns = strdup(command);
			if (*dup_tkns == NULL)
			{
				free(tkns);
				return (NULL);
			}
			command[i] = (char)c;
			command = &command[i + 1];
			dup_tkns++;
		}
		i++;
	}
	dup_tkns = NULL;
	return (tkns);
}


/**
 * count - Counts number of spaces in a string
 * @command: String  to check
 * @delim: Character to find in the command string
 *
 * Return: size
 */
int count(char *command, char c)
{
	int i, size;

	if (command == NULL)
		return (-1);

	size = 0;
	i = 0;
	while (command[i] != '\0')
	{
		if (command[i] == c)
			size++;
		i++;
	}

	return (++size);
}
