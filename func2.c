#include "main.h"

/**
 * _stringcomp - Comparesi given two strings.
 * @s1: Pointer to give First string.
 * @s2: Pointer to  given Second string.
 * Return: 0 ifqual, Otherwise - positive value.
 */

int _stringcomp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

/**
 * writechar - Writes the cha c to stdout.
 * @c: The charto print.
 * Return: On success - 1.
 */
int writechar(char c)
{
	return (write(1, &c, 1));
}


/**
 * _stringcopy - Copies the string pointed to by dest.
 * @dest: Copy source to this buffer.
 * @src: This is the given srce to copy.
 * Return: Copy of original source.
 */

char *_stringcopy(char *dest, char *src)
{
	int i, len;

	for (len = 0; src[len] != '\0'; len++)
		;

	for (i = 0; i <= len; i++)
		dest[i] = src[i];

	return (dest);
}
