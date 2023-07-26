#include "main.h"

/**
 * main - Entry to Simple Shell program.
 * @argc: Number of arguments.
 * @argv: Pointer to array of arguments.
 * Return: Always 0 if success else 1.
 */

int main(int argc, char *argv[])
{
	char *line;
	int Status;
	char **tokens;

	(void)argc;

	signal(SIGINT, ctrlc);
	Status = 0;
	while (Status == 0)
	{
		prompt();

		line = pass_line();
		if (_stringcomp(line, "\n") == 0)
		{
			tokens = NULL;
			free(line);
			continue;
		}
		tokens = _stringtotoken(line);
		if (tokens[0] == NULL)
		{
			free(tokens);
			free(line);
			continue;
		}

		if (_stringcomp(tokens[0], "exit") == 0)
		{
			_exitShell(tokens, line);
		}
		else
		{
			Status =  _exec(tokens, argv[0]);
		}
		free(line);
		free(tokens);
	}
	return (Status);
}
