#include "main.h"

/**
 * prompt - Print p specific prompt to the terminal.
 * Return: Void.
 */
void prompt(void)
{
	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "$ ", 2);
	}
}
