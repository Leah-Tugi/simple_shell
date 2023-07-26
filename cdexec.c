#include "main.h"

/**
 * executeCdCommand - executes cd
 * @command: command arrays
 */

void executeCdCommand(char **command)
{
	struct passwd *pwd;
	char *path = command[1];

	if (path == NULL)
	{
		pwd = getpwuid(getuid());
		path = pwd->pw_dir;
	}
	if (path[0] == '/')
		path++;

	if (chdir(path) == -1)
	{
		perror("Error changing directory");
		DisplayPrompt();
		return;
	}

	DisplayPrompt();
}
