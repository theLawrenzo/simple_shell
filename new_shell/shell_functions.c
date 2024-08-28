#include "shell.h"

/**
 * prompt - Prints '$' to stdout and gets commands from user
 * @lineptr: Pointer to the string read from stdin
 * @n: Length of the string read from stdin
 * @stream: Stream to read commands from
 *
 * Return: On success number of characters read,
 * -1 On failure
 */
ssize_t prompt(char **lineptr, size_t *n, FILE *stream)
{
	ssize_t ret_val;

	printf("$ ");
	ret_val = my_getline(lineptr, n, stream);
	if (ret_val == -1)
		return (-1);

	return (ret_val);
}


/**
 * count_tokens - Counts the number of spaces in a string
 * @str: String to count spaces in
 * @c: This is the space character
 *
 * Return: len
 */
int count_tokens(char *str, char *c)
{
	int i, len;

	len = 1;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == *c)
			len++;
		i++;
	}

	return (len);
}


/**
 * my_getenv - Gets an environment variable list of directories
 * @var: Environment variable
 *
 * Return: environ[i]
 */
char *my_getenv(char *str)
{
	int i, j;
	char *tmp, *var, c;

	for (i = 0; environ[i] != NULL; i++)
	{
		tmp = environ[i];
		j = 0;
		while (tmp[j] != '=')
			j++;

		c = tmp[j];
		tmp[j] = '\0';

		if (strcmp(tmp, str) == 0)
		{
			tmp[j] = c;
			var = &tmp[++j];
			break;
		}
	}

	return (var);
}


/**
 * _getline - Reads the commands typed at the command line
 * @lineptr: Pointer to the commands
 * @n: number of characters entered
 * @stream: Pointer to the stream to read commands from
 *
 * Return: size of commands entered
 */
ssize_t my_getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t initial_size, growth_size, new_size;
	char *new_buffer, *current_position, c;
	ssize_t total_len = 0;

	initial_size = new_size = 5;
	growth_size = 5;

	*lineptr = malloc(initial_size * sizeof(char));
	if (*lineptr == NULL)
		return (-1);
	current_position = *lineptr;
	while (1)
	{
		c = (char)fgetc(stream);
		if (c == '\n' || c == EOF)
			break;

		if (*n >= initial_size)
		{
			new_buffer = realloc(*lineptr, growth_size);
			if (new_buffer == NULL)
				return (-1);
			
			current_position = new_buffer + (current_position - *lineptr);
			*lineptr = new_buffer;
			new_size += growth_size;
		}
		*current_position++ = c;
		total_len++;
		(*n)++;
	}
	*current_position = '\0';
	return (total_len);
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
	len = count_tokens(dup_str, sep);

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
	return (tokens);
}
