#include "shell.h"

/**
 * main - test my shell
 *
 * Return: Always 0
 */
int main(void)
{
	int val;

	val = shell();
	if (val == 0)
		printf("success\n");
	else
		printf("try again\n");
	return (0);
}
