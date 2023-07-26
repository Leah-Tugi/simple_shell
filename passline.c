#include "main.h"


/**
 * pass_line - Gets a line typed to the command line as a str.
 * Return: Pointer to the line(string).
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
