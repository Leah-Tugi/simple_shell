#include "main.h"

/**
 * _cd - changes to current working dir
 * @path: path to change to
 * Return: 0 on success
 */
int _cd(char *path)
{
	static char last_path[1024] = {0};
	char current_path[1024];

	if (path == NULL || _stringcomp(path, "-") == 0)
	{
		if (last_path[0] != '\0')
		{
			if (chdir(last_path) == -1)
			{
				perror("cd");
				return (-1);
			}
		}
			else
			{
				fprintf(stderr, "No prev dir\n");
				return (-1);
			}
	}
		else
		{
			if (chdir(path) == -1)
			{
				perror("cd");
				return (-1);
			}
		}

		getcwd(current_path, sizeof(current_path));
		strcpy(last_path, current_path);

		return (0);
}
