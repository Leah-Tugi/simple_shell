#include "main.h"

/**
 * _printstring - prints a stg, followed by a new line, to stdout.
 * @str: string to print.
 */

void _printstring(char *str)
{
	unsigned long i = 0;

	while (str[i] != '\0')
	{
		writechar(str[i]);
		i++;
	}

	writechar('\n');
}
