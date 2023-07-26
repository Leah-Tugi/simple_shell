#include "main.h"

/**
 * ctrlc - this is the control c handler
 * @signum: the signal num that has been received
 *
 * Return: void
 */
void ctrlc(int signum)
{
	(void)signum;

	write(STDOUT_FILENO, "\n", 1);
	exit(0);
}

/**
 * equal_delim - Check if a given char is equal to the  delim.
 * @c: char.
 * @delim: refers to " "
 * Return: 0 if no match, 1 if matched.
 */

int equal_delim(char c, const char *delim)
{
	while (delim && *delim)
	{
		if (c == *delim)
		{
			return (1);
		}
		++delim;
	}
	return (0);
}

/**
 * _stingtokarr - Mimics strtokt tokenizes a string and turns it into array
 * @src: Str from getline.
 * @delim: refers to " ";
 * Return: Individual token in a given array format.
 */

char *_stingtokarr(char *src, const char *delim)
{
	static char *s;
	static unsigned int i;
	char *result = NULL;
	int is_space = 0;

	if (src)
	{
		s = src;
		for (i = 0; s[i]; i++)
		{
			if (equal_delim(s[i], delim))
				s[i] = '\0';
		}
	}

	if (s == NULL || *s == '\0')
		return (NULL);
	result = s;
	i = _stringlength(s);
	if (s[i] == '\0' && _stringlength(s) > 0)
		is_space = 1;
	s = s + _stringlength(s) + is_space;
	return (result);
}

/**
 * _stringduplicate - duplicates a given str
 * @str: str required to be duplicated
 * Return: ptr to duplicated str in alloc memm
 */
char *_stringduplicate(char *str)
{
	char *duplicate_str;
	int i, len = 0;

	if (str == NULL)
		return (NULL);
	while (str[len])
		len++;
	len++;
	duplicate_str = malloc(sizeof(char) * len);
	if (duplicate_str == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		duplicate_str[i] = str[i];
		i++;
	}
	return (duplicate_str);
}

/**
 * custom_getline - Stores malloced buffer of command into shell.
 * @str: Buffer.
 * Return: Num of chars read.
 */
ssize_t custom_getline(char **str)
{
	ssize_t i = 0, size = 0, t = 0, t2 = 0, n = 0;
	char buff[1024];

	while (t2 == 0 && (i = read(STDIN_FILENO, buff, 1024 - 1)))
	{
		if (i == -1)
			return (-1);

		buff[i] = '\0';

		n = 0;
		while (buff[n] != '\0')
		{
			if (buff[n] == '\n')
				t2 = 1;
			n++;
		}

		if (t == 0)
		{
			i++;
			*str = malloc(sizeof(char) * i);
			*str = _stringcopy(*str, buff);
			size = i;
			t = 1;
		}
		else
		{
			size += i;
			*str = _stringcat(*str, buff);
		}
	}
	return (size);
}
