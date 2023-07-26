#include "main.h"

/**
 * mybuiltin - This function checks whether a token is built in.
 * @str: Pointer to point to the string to be checked..
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
	return (1);
}

/**
  *printenvironment - Prints variables that are in the current
  * working environment.
  * Return: Returns a void.
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
 * _execmybuiltin - This function executes a builtin Function.
 * @tokens: Doubles the pointer to tokens.
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


	return (1);
}
/**
 * _exitShell - Exits the Simple shell
 * and frees memory.
 * @tokens: Double pointer to words split from line.
 * @line: Pointer to string got using getLine().
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
