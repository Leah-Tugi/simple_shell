#include "main.h"

/**
 * prompt - Printing our chosen prompt.
 * Return: Void.
 */
void prompt(void)
{
	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "$ ", 2);
	}
}
