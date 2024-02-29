#include "main.h"

/**
 * main - call the shell function
 *
 * Return: Always 0.
 */
int main(void)
{
	if (shell() == -1)
		exit(EXIT_FAILURE);
	
	return (0);
}
