#include "main.h"

/**
 * _stringcat - Concatenates given two strings.
 * @dest: Pointer to str to be conatenated upon.
 * @src: Pointer to stri to append to dest.
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
 * _stringlength - Returns given length of a string.
 * @s: Poiter to strng.
 * Return: Length of s.
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
 * _stringtotoken - splis a string into words.
 * @str: Povinter to strg.
 * Return: Pointer to array of words.
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
