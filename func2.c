#include "main.h"

/**
 * _stringcomp - Compares a given two strings.
 * @s1: Pointer to given First string.
 * @s2: Pointer to given Second string.
 * Return: 0 if they are equal, Otherwise - value.
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
 * _atoi - Custom _atoi that converts thestring to int.
 * @s: string.
 * Return: Number if success, -1 if stringn-numbers.
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
 * writechar - writes th char c to stdout
 * @c: char to print
 * Return: on succes give -1
 */
int writechar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _stringcopy - Copies str pointed to by src to the buffer pointe dest.
 * @dest: Copy source to this given buffer.
 * @src: This is the source given to copy.
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
