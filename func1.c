#include "main.h"

/**
 * _printstring - prints a str followed by newline to stdout
 * @str: string to print
 */

void _printstring(char *str)
{
	unsigned long i = 0;

	while (str[i] != '\0')
	{
		writechar(str[i]);
		i++;
	}

	writechar('\n');
}

/**
 * _stringcat - Concatenates two strings.
 * @dest: Pointer to string to be conatenated upon.
 * @src: Pointer to string to append to dest.
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
 * _white_space_check - checks for white space.
 * @s: Pointer to string to check.
 * Return: integer.
 */
unsigned int _white_space_check(char *s)
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
 * _stringlength - Returns the length of a given str
 * @s: ptr to a given str
 * Return: leth of s
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
 * _stringtotoken - splits a given string into maany words.
 * @str: Pointer to a given string.
 * Return: refers to a Pointer to array of words.
 */
char **_stringtotoken(char *str)
{
	int i = 0;
	const char delimeter[] = " \t\n";
	int space = _white_space_check(str);
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
