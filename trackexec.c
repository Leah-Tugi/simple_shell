#include "main.h"

/**
 * path_exec - Executes a file.
 * @tokens: Split string into varioouss tokens from stdin.
 * @path: Path from path_constructor function.
 * @args: Program arguments.
 * Return: 0 - on success, else - 1.
 */
int path_exec(char **tokens, char *path, char *args)
{
	char *err1, *err2, *err3;
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error: ");
		return (1);
	}

	if (child_pid == 0)
	{
		tokens[0] = path;

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
	return (EXIT_SUCCESS);
}
