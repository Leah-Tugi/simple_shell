#include "main.h"

/**
  *_printsenvironment - Prints variables in the working environment.
  * Return: void.
  */
void _printsenvironment(void)
{
	int i = 0;

	while (environ[i])
	{
		_printstring(environ[i]);
		i++;
	}
}

/**
 * _myBuiltIn - Checks if the token is a shell built in.
 * @str: Ptr to str to check.
 * Return: 0 if true else 1.
 */
int _myBuiltIn(char *str)
{
	if ((_stringcomp(str, "env")) == 0)
	{
		return (0);
	}
	if ((_stringcomp(str, "exit")) == 0)
		return (0);
	if ((_stringcomp(str, "setenv")) == 0)
		return (0);
	if ((_stringcomp(str, "unsetenv")) == 0)
		return (0);
	if ((_stringcomp(str, "cd")) == 0)
		return (0);
	return (1);

}

/**
 * _execBuiltIn - Executes a given builtin Function.
 * @tokens: Double ptr to tokens.
 * Return: 0 if success.
 */
int _execBuiltIn(char **tokens)
{
	if ((_stringcomp(*tokens, "env")) == 0)
	{
		_printsenvironment();
		return (0);
	}
	if ((_stringcomp(*tokens, "setenv")) == 0)
	{
		if (tokens[1] && tokens[2])
		{
			_setenviron(tokens[1], tokens[2]);
			return (0);
		}

		fprintf(stderr, "Usage: setenv var_name var_value\n");
		return (0);
	}
	if (_stringcomp(*tokens, "unsetenv") == 0)
	{
		if (tokens[1])
		{
			_unsetenviron(tokens[1]);
			return (0);
		}

		fprintf(stderr, "Usage: unsetenv VAR_NAME\n");
		return (0);
	}
	if (_stringcomp(*tokens, "cd") == 0)
	{
		if (tokens[1])
		{
			return (_cd(tokens[1]));
		}
		else
		{
			fprintf(stderr, "Usage: cd <dir>\n");
			return (-1);
		}
	}
	return (1);
}
/**
 * _exitShell - Exits from the shell and it also frees memory.
 * @tokens: Double ptr to words split from line.
 * @line: Ptr to strg got using the  getLine().
 * Return: void.
 */
void _exitShell(char **tokens, char *line)
{
	int status;

	if (tokens[1] != NULL)
	{
		status = atoi(tokens[1]);
		if (status >= 0)
		{
			free(line);
			free(tokens);
			exit(status);
		}
		write(STDERR_FILENO, "Exit: illegal exit status: ", 28);
		write(STDERR_FILENO, tokens[1], 1);
		write(STDERR_FILENO, "\n", 1);
	}
	else
	{
		free(line);
		free(tokens);
		exit(0);
	}
}
