#include "shell.h"
#define MAX 50

/**
 * _getenv - Gets an environment variable from an environment
 * @str: ENVIRONMENT VARIABLE NAME
 *
 * Return: environ[i]
 */
char *_getenv(char *str)
{
	int i, j;
	char *tmp, *var, **dup_environ, c;

	i = 0;
	while (environ[i] != NULL)
		i++;
	dup_environ = malloc(i * sizeof(char *));
	if (dup_environ == NULL)
		return (NULL);

	for (i = 0; environ[i] != NULL; i++)
	{
		dup_environ[i] = strdup(environ[i]);
		if (dup_environ[i] == NULL)
		{
			free(dup_environ);
			return (NULL);
		}
	}

	i = 0;
	/*if (dup_environ[i] == NULL)
		return (NULL);

	*/

	/* Traverse the global variable environ till the NULL character is encountered */
	while (dup_environ[i] != NULL)
	{
		j = 0;
		/* Assign each pointer that is an environment variable to the tmp variable */
		tmp = dup_environ[i];
		/**
		 * Traverse through each character of an environment variable till the
		 * equal ( = ) sign is encountered
		 */
		while (tmp[j] != '=')
		{
			/* counts the number of characters till the equal sign */
			j++;
		}
		/* Assign the value at tmp[j] that is the equal sign to the variable c */
		c = tmp[j];
		/* Then assign the NUL character to the the position of the equal sign temporarily */
		tmp[j] = '\0';
		/**
		 * Compare the string str (i.e the name of the environment variable to get)
		 * with the newly designated string created when NUL was assigned to the position
		 * of the equal sign
		 *
		 * If newly designated string is equal to the string str, then assign tmp[j] with its
		 * original character that was stored in the variable 'c' then break out of the loop
		 */
		if (strcmp(tmp, str) == 0)
		{
			tmp[j] = c;
			/**
			 * Initialize the pointer variable var with the address of the character
			 * after the equal sign in the environment variable
			 */
			var = &tmp[++j];
			break;
		}
		i++;
	}

	return (var);
}

/**
 * main - Test the _getenv function
 *
 * Return: Always 0
 */

int main(void)
{
	char *env_var;

	if ((env_var = _getenv("PATH")) == NULL)
	{
		printf("Something went wrong\n");
		printf("Usage: %s is not found...\n", "PATH");
	}
	printf("%s\n", env_var);
	return (0);
}
