#include "main.h"

/**
 * pass_line - Gets a typed line from the command line as a string.
 * Return: Pointer to the line(string).
 */

char *pass_line(void)
{
	char *line =  NULL;
	size_t len = 0;
	/*int chars = 0;*/
	ssize_t chars = 0;

	/* inbuilt getline */
	chars = getline(&line, &len, stdin);

	/* custom get line */
	/*chars = custom_getline(&line);*/
	if (chars == EOF)
	{
		free(line);
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