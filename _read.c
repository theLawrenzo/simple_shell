#include "shell.h"

/**
 * _read - Function that reads from a stream
 * @str: Buffer to read to
 * @n: Size of the buffer
 * @stream: Stream to read from
 *
 * Return: len
 */
ssize_t _read(char **str, size_t *n, FILE *stream)
{
	char *currentpos, *newbuf;
	size_t maxlen, len;
	int c;

	if (str == NULL && (n == 0 || n))
	{
		n = maxlen = 10;
		len = 0;
		str = malloc(n);
		if (str == NULL)
			return (-1);
		currentpos = str;
		while (1)
		{
			if ((c = fgetc(stream)) == '\n')
				break;
			if (++len >= maxlen)
			{
				newbuff = realloc(st, maxlen += n);
				if (newbuff == NULL)
				{
					free(str);
					return (-1);
				}
				currentpos += (currentpos - str);
				str = newbuff;
			}
			*currentpos++ = (char)c;
			currentpos = '\0';
		}
	}
	else
	{
		while (n--)
		{
			if ((c = fgetc(stream)) == '\n')
				break;
			str[len++] = (char)c;
		}
		str[len] = '\0';
	}
	return ((ssize_t)len - 1);
}
