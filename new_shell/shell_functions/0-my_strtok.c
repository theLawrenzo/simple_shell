#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **my_strtok(char *str, char *sep);
int count_tokens(char *str, char c);


/**
 * main - Tests the my_strtok function
 *
 * Return: Always 0
 */
int main(void)
{
	char **tokens;
	char *str = "Hello! My name is Kome, and I'm a programmer";
	char *sep = " ";
	int i;

	printf("string contains %d tokens\n", count_tokens(str, ' '));

	tokens = my_strtok(str, sep);
	if (tokens == NULL)
	{
		printf("Something went wrong\n");
		exit(EXIT_FAILURE);
	}

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
 * spaces - Counts the number of spaces in a string
 * @str: String to count spaces in
 * @c: This is the space character
 *
 * Return: len
 */
int count_tokens(char *str, char c)
{
	int i, len;

	len = 1;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			len++;
		i++;
	}

	return (len);
}


/**
 * my_strtok - Tokenizes a string
 * @str: String to tokenize
 * @sep: Delimiter characters
 *
 * Return: tokens
 */
char **my_strtok(char *str, char *sep)
{
	char **tokens, *sep_addr, *dup_str, *dup_at_curr;
	int __attribute__((unused))i, len;

	dup_str = strdup(str);
	if (dup_str == NULL)
		return (NULL);
	len = count_tokens(dup_str, ' ');

	tokens = malloc((len + 1) * sizeof(char *));
	if (tokens == NULL)
		return (NULL);

	dup_at_curr = dup_str;

	sep_addr = strpbrk(dup_at_curr, sep);
	if (sep_addr == NULL)
		tokens[0] = dup_str;
	
	i = 0;
	while (sep_addr != NULL)
	{
		*sep_addr = '\0';
		tokens[i] = dup_at_curr;
		dup_at_curr = sep_addr + 1;
		i++;

		sep_addr = strpbrk(dup_at_curr, sep);
		if (sep_addr == NULL)
			tokens[i++] = dup_at_curr;
	}

	tokens[i] = NULL;

	printf("THE VALUE OF I IS %d\n", i);
	return (tokens);
}
