#include "main.h"
/**
 * executeExitCommand - executes cmd
 * @command: cmd array
 * @cmdLength: lgt of cmfd
 */
void executeExitCommand(char **command, int cmdLength)
{
	if (cmdLength == 1)
	{
		freeCommand(command);
		exit(EXIT_SUCCESS);
	}
	else if (cmdLength == 2)
	{
		int exitStatus = atoi(command[1]);

		freeCommand(command);
		exit(exitStatus);
	}
	else
	{
		write(STDOUT_FILENO, "Inv\n", strlen("Inv\n"));
		freeCommand(command);
		DisplayPrompt();
		return;
	}
}
/**
 * executeEnvCommand - executes env
 * @command: cmd array
 */
void executeEnvCommand(char **command)
{
	(void)command;
	printEnvironment();
	DisplayPrompt();
}
/**
 * executeSetenvCommand - execute commands
 * @command: cmd arrayy
 */
void executeSetenvCommand(char **command)
{
	setEnvironmentVariable(command);
}
/**
 * executeUnsetenvCommand - executesz unset
 * @command: cmd array
 */
void executeUnsetenvCommand(char **command)
{
	unsetEnvironmentVariable(command);
}
/**
 * executeDefaultCommand - executes default cmds
 * @command: cmd array
 */
void executeDefaultCommand(char **command)
{
	executeCommand(command);
}
