#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/*
 * execute_command - Executes a command in a child process.
 * @args: An array of arguments.
 * Return: If an error occurs - a corresponding error code.
 * O/w - The exit value of the last executed command.
 */
void execute_command(char *command)
{
	if (command == NULL)
	{
		printf("invalid cmd\n");
		return;
	}

	if (strcmp(command, "exit") == 0)
	{
		printf("exiting shell..\n");
		exit(0);
	}
	printf("unknown cd: %s\n", command);
}

/*
 * main - Runs a simple UNIX command interpreter.
 * @argc: The number of arguments supplied to the program.
 * Return: always returns 0
 */
int main(void)
{
	char *prompt = " $ ";
	char *lineptr = NULL;
	size_t n = 0;
	ssize_t nchars_read;

	while (1)
	{
		printf("%s", prompt);
		nchars_read = getline(&lineptr, &n, stdin);

		if (nchars_read == -1)
		{
			printf("exiting shell..\n");
			break;
		}

		if (lineptr[nchars_read - 1] == '\n')
		{
			lineptr[nchars_read - 1] = '\0';
		}
		execute_command(lineptr);
	}

	free(lineptr);

	return (0);
}
