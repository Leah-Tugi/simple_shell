#include "main.h"

/**
 * _writechar - Writes the char c to stdout.
 * @c: The char inteded for printing
 * Return: On success - 1.
 */
int _writechar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _stringcomp - Comparesthe given two strings.
 * @s1: Pointer to the first string.
 * @s2: Pointer to the second string.
 * Return: 0 if they are equal, Otherwise of positive value.
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
 * _atoi - it changes a string to int.
 * @s: string.
 * Return: Number if success, -1 if string contains non-numbers.
 */
int _atoi(char *s)
{
	int i = 0;
	unsigned int num = 0;

	while (s[i] != '\0')
	{
		if (s[i] >= '0' && s[i] <= '9')
			num = num * 10 + (s[i] - '0');
		if (s[i] > '9' || s[i] < '0')
			return (-1);
		i++;
	}
	return (num);
}


/**
 * _stringcopy - Copies the str pointed pointed to by dest.
 * @dest: Copy source to this buffer.
 * @src: This is the source to copy.
 * Return: Copy of og source.
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
