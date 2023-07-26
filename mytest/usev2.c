#include <stdlib.h>
#include <stddef.h>
#include "main.h"

/**
 * executeCommand - executeaz cmd
 * @command: cmd arraty to execute
 */

void executeCommand(char **command)
{
	char *exec_command = command[RESET];
	pid_t id = fork();

	if (id < RESET)
	{
		write(STDOUT_FILENO, "Fork fail\n", strlen("Forl fail\n"));
		freeCommand(command);
		return;
	}
	else if (id == RESET)
	{
		execve(command[RESET], command, environ);

		execvp(exec_command, command);

		perror("command not found");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
		DisplayPrompt();
	}
}
