#include "main.h"

/**
 * file_status - Checks i on the exact file status
 * @s: Ptr to file name.
 * Return: 0 if success, else non zero.
 */
int file_status(char *s)
{
	struct stat st;

	return (stat(s, &st));
}

/**
 * path_constructor - Construc path to binaries.
 * @tokens: Double pointer to tokens.
 * Return: Return - path, else - NULL.
 */
char *path_constructor(char **tokens)
{
	char path1[100] = "/bin/";
	char path2[100] = "/usr/bin/";

	char *finalPath1;
	char *finalPath2;

	finalPath1 = _stringcat(path1, tokens[0]);

	if ((file_status(finalPath1) == 0))
		return (finalPath1);

	finalPath2 = _stringcat(path2, tokens[0]);
	if ((file_status(finalPath2) == 0))
		return (finalPath2);

	return (NULL);
}
