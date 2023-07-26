#include "main.h"
/**
 * main - entry point
 * Return: exit statusss
 */
int main(void)
{
	int cmdLength = RESET;
	char input[INPUT_SIZE] = "";
	char **command;

	DisplayPrompt();
	while (strcmp(input, ENDING_WORD) != RESET)
{
	if (fgets(input, INPUT_SIZE, stdin) == NULL)
	{
		write(STDOUT_FILENO, "Exit..\n", strlen("Exit..\n"));
		break;
	}
	command = parseInput(input, &cmdLength);
	if (strcmp("cd", command[RESET]) == RESET)
	{
		executeCdCommand(command);
	}
	else if (strcmp("exit", command[RESET]) == RESET)
	{
		executeExitCommand(command, cmdLength);
	}
	else if (strcmp("env", command[RESET]) == RESET)
	{
		executeEnvCommand(command);
	}
	else if (strcmp("setenv", command[RESET]) == RESET)
	{
		executeSetenvCommand(command);
	}
	else if (strcmp("unsetenv", command[RESET]) == RESET)
	{
		executeUnsetenvCommand(command);
	}
	else
	{
		executeDefaultCommand(command);
	}
	freeCommand(command);
}
return (EXIT_SUCCESS);
}
