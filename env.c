#include "main.h"

/**
 * printEnvironment - prints env var
 */
void printEnvironment(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}

/**
 * setEnvironmentVariable - sets env var
 * @command: cmd arrays
 */
void setEnvironmentVariable(char **command)
{
	if (command[1] == NULL || command[2] == NULL)
	{
		fprintf(stderr, "Usage: setenv VARIABLE VQALUE\n");
		return;
	}
	if (setenv(command[1], command[2], 1) != 0)
	{
		perror("failed to set environment variable");
	}
}

/**
 * unsetEnvironmentVariable - unsets env var
 * @command: the cmd array
 */
void unsetEnvironmentVariable(char **command)
{
	if (command[1] == NULL)
	{
		fprintf(stderr, "usage: unset variable\n");
		return;
	}
	if (unsetenv(command[1]) != 0)
	{
		perror("failed to unset environment variable");
	}
}
