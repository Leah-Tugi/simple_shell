#include "main.h"

/**
 * _exec - Executing a file.
 * @tokens: Spliting a str into tokens from stdin.
 * @args: Program arguments.
 * Return: 0 if success. otherwise - 1.
 */
int _exec(char **tokens, char *args)
{
	char *err1, *err2, *err3;
	pid_t child_pid;
	int status;
	char *path;

	if (_myBuiltIn(*tokens) == 0)
	{
		status = _execBuiltIn(tokens);
		return (status);
	}

	path = path_constructor(tokens);
	if (path != NULL)
	{
		status = path_execute(tokens, path, args);
		return (status);
	}

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error: ");
		return (1);
	}
	if (child_pid == 0)
	{

		if (execve(tokens[0], tokens, NULL) == -1)
		{
			err1 = _stringcat(*tokens, ": No such file or directory\n");
			err2 = _stringcat(args, ":");
			err3 = _stringcat(err2, err1);
			write(STDERR_FILENO, err3, _stringlength(err3));
			free(tokens);
			exit(EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
	}
	wait(&status);
	return (0);
}
