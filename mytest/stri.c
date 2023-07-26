#include "main.h"

/**
 * _stringlength - Returns len of a string.
 * @s: Pointers to the exact string.
 * Return: Len of s.
 */
int _stringlength(char *s)
{
	int index;

	index = 0;
	while (s[index] != '\0')
	{
		index++;
	}
	return (index);
}
/**
 * _stringcat - Concatenates the two strings.
 * @dest: Pointer to string to be concatenated.
 * @src: Pointer to str to append to dest.
 * Return: Pointer to dest.
 */
char *_stringcat(char *dest, char *src)
{
	char *destAddress;
	int destLen;

	destAddress = dest;
	destLen = _stringlength(dest);
	destAddress = destAddress + destLen;
	while (*src != '\0')
	{
		*destAddress = *src;
		src++;
		destAddress++;
	}
	*destAddress = '\0';

	return (dest);
}

/**
 * _white_space_checker - checking the white space.
 * @s: Pointer to str to check.
 * Return: integer.
 */
unsigned int _white_space_checker(char *s)
{
	int i, count = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i]  == ' ' || s[i] == '\t' || s[i] == '\n')
			count++;
	}
	return (count);
}

/**
 * _stringtotokens - splits a given string into words.
 * @str: Pointer to string.
 * Return: Pointer to array of words.
 */
char **_stringtotokens(char *str)
{
	int i = 0;
	const char delimeter[] = " \t\n";
	int space = _white_space_checker(str);
	char **tokens = malloc(sizeof(char *) * (space + 1));
	char *token;

	if (!tokens)
	{
		free(tokens);
		fprintf(stderr, "sh: allocation error\n");
		exit(1);
	}

	token = strtok(str, delimeter);

	while (token != NULL)
	{
		tokens[i] = token;
		token = strtok(NULL, delimeter);
		i++;
	}
	tokens[i] =  NULL;

	return (tokens);
}



/**
 * _printstring - prints a str, followed by new line, to stdout.
 * @str: string to print.
 */

void _printstring(char *str)
{
	unsigned long i = 0;

	while (str[i] != '\0')
	{
		_writechar(str[i]);
		i++;
	}

	_writechar('\n');
}
