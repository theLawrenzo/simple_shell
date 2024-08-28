#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * path_directories - Prints each directory of the PATH variable
 * on a new line
 *
 * Return: Nothing
 */
void path_directories(void)
{
	char *environ_cpy, *path_value, **each_dir;
	int i, j, colon = 1;

	path_value = getenv("PATH");
	if (path_value == NULL)
		exit(EXIT_FAILURE);

	environ_cpy = strdup(path_value);
	if (environ_cpy == NULL)
		exit(EXIT_FAILURE);

	for (i = 0; environ_cpy[i] != '\0'; i++)
	{
		if (environ_cpy[i] == ':')
		{
			colon++;
		}
	}

	each_dir = malloc(sizeof(char *) * (colon + 1));
	if (each_dir == NULL)
		exit(EXIT_FAILURE);

	for (i = 0; i < colon; i++)
	{
		each_dir[i] = environ_cpy;
		for (j = 0; environ_cpy[j] != '\0'; j++)
		{
			if (environ_cpy[j] == ':')
			{
				environ_cpy[j] = '\0';
				environ_cpy = &environ_cpy[j + 1];
				break;
			}
		}
	}

	each_dir[colon] = NULL;
	/**
	for (i = 0; environ_cpy[i] != '\0'; i++)
	{
		if (environ_cpy[i] == ':')
		{
			environ_cpy[i] = '\n';
		}
	}
	*/
	for (i = 0; each_dir[i] != NULL; i++)
	{
		printf("%s\n", each_dir[i]);
	}
}


/**
 * main - check the code
 *
 * Return: Always 0
 */
int main(void)
{
	path_directories();

	return (0);
}
