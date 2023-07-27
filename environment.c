#include "main.h"

/**
 * _setenviron - updates or adds a givenenv var environment variable.
 * @var_name:varible name.
 * @var_value:varble value.
 * Return:0 success, otherwise 1.
 */

int _setenviron(char *var_name, char *var_value)
{
	int i = 0;
	size_t name_len;
	char *var_new;

	name_len = _stringlength(var_name);
	i = 0;

	while (environ[i])
	{
		if (strncmp(environ[i], var_name, name_len) == 0)
		{
			var_new = buid_var(var_name, var_value);

			environ[i] = NULL;
			environ[i] = _stringduplicate(var_new);
			free(environ[i]);
			environ[i] = _stringduplicate(var_new);
			free(var_new);
			return (0);
		}
		i++;
	}

	var_new = buid_var(var_name, var_value);
	free(environ[i]);
	environ[i] = _stringduplicate(var_new);
	i++;
	environ[i] = NULL;
	var_new = NULL;

	return (0);
}
/**
 * buid_var - Builds an env var from its name and value.
 * @var_name: given Variable name.
 * @var_value: given Variable value.
 * Return: String haviing full environment variable.
 */
char *buid_var(char *var_name, char *var_value)
{
	char *new_var;
	size_t var_len;

	var_len = _stringlength(var_name) + _stringlength(var_value) + 2;
	new_var = malloc(sizeof(char) * var_len);
	if (new_var == NULL)
	{
		perror("Error: Insufficient memory\n");
		return (NULL);
	}
	memset(new_var, 0, var_len);

	new_var = _stringcat(new_var, var_name);
	new_var = _stringcat(new_var, "=");
	new_var = _stringcat(new_var, var_value);

	return (new_var);
}
/**
 * _unsetenviron - Removes an given env environment variable.
 * @var_name: given Variable name.
 * Return: 0 if successful - 1,otherwise - -1.
 */
int _unsetenviron(char *var_name)
{
	int i = 0;
	char **env_temp;
	size_t name_len;

	name_len = _stringlength(var_name);
	while (environ[i])
	{
		if (strncmp(environ[i], var_name, name_len) == 0)
		{
			env_temp = environ;
			free(env_temp[0]);
			do {
				env_temp[0] = env_temp[1];
				env_temp++;
			} while (*env_temp);
		}
		i++;
	}
	return (0);
}
