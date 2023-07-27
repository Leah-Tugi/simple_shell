#include "main.h"

/**
 * mybuiltin - Checks if  given token is a built in.
 * @str: Pointer to string to check.
 * Return: 0 if true else 1.
 */
int mybuiltin(char *str)
{
	if ((_stringcomp(str, "env")) == 0)
	{
		return (0);
	}
	if ((_stringcomp(str, "setenv")) == 0)
	{
		return (0);
	}
	if ((_stringcomp(str, "unsetenv")) == 0)
	{
		return (0);
	}
	if ((_stringcomp(str, "exit")) == 0)
	{
		return (0);
	}
	if ((_stringcomp(str, "cd")) == 0)
	{
		return (0);
	}
	return (1);
}

/**
  *printenvironment - Prints var working environment.
  * Return: void.
  */
void printenvironment(void)
{
	int i = 0;

	while (environ[i])
	{
		_printstring(environ[i]);
		i++;
	}
}

/**
 * _execmybuiltin - Executes a given builtin Function.
 * @tokens: Double ptr to given tokens.
 * Return: 0 if success.
 */
int _execmybuiltin(char **tokens)
{
	if ((_stringcomp(*tokens, "env")) == 0)
	{
		printenvironment();
		return (0);
	}
	if ((_stringcomp(*tokens, "setenv")) == 0)
	{

		if (tokens[1] && tokens[2])
		{
			_setenviron(tokens[1], tokens[2]);
			return (0);
		}
		printf("Usage: setenv var_name var_value\n");
		return (0);
	}
	if (_stringcomp(*tokens, "unsetenv") == 0)
	{

		if (tokens[1])
		{
			_unsetenviron(tokens[1]);
			return (0);
		}
		printf("Usage: unsetenv VAR_NAME\n");
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
			fprintf(stderr, "usage: cd <dir>\n");
			return (-1);
		}
	}
	return (1);
}
/**
 * _exitShell - Exits the given shell nd frees memory.
 * @tokens: Double ptr to words split from line.
 * @line: Pointer to str got using getLine functio().
 * Return: void.
 */
void _exitShell(char **tokens, char *line)
{
	int status;

	if (tokens[1] != NULL)
	{
		status = _atoi(tokens[1]);
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
