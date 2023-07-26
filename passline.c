#include "main.h"

/**
 * pass_line - Gets what a user inputs in the terminal as a string.
 * Return: Returns a pointer to the line in this case string.
 */

char *pass_line(void)
{
	char *line =  NULL;
	size_t len = 0;
	ssize_t chars = 0;

	chars = getline(&line, &len, stdin);

	if (chars == EOF)
	{
		free(line);
		write(STDOUT_FILENO, "^D\n", 3);
		exit(0);
	}
	if (line == NULL)
	{
		write(STDOUT_FILENO, "\n", 1);
		free(line);
		exit(-1);
	}

	return (line);
}
