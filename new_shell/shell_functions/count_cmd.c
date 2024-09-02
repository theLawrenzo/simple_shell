#include "shell.h"

/**
 * count_dir - Function that returns the number of spaces in a string
 * @string
 *
 * Return: space_num
 */
size_t count_cmd(char *string)
{
	size_t i, spaces;

	if (string == NULL)
		exit (EXIT_FAILURE);

	i = 0;
	spaces = 0;
	while (string[i] != '\0')
	{
		if (string[i] != ' ')
		{
			i++;
			continue;
		}
		spaces++;
		i++;
	}
	return (++spaces);
}
