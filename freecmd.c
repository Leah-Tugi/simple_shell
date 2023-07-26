#include "main.h"

/**
 * freeCommand - frees mem allocated
 * @command: e cmd array
 */

void freeCommand(char **command)
{
	int i;

	for (i = 0; command[i] != NULL; i++)
		free(command[i]);
	free(command);
}
