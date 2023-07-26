#include "main.h"
/**
 * parseInput - parses user inputs into cmd
 * @input: user input into string
 * @cmdLength: pointer to the var
 * Return: ana array of string
 */
char **parseInput(char *input, int *cmdLength)
{
	int i = 0;
	int counter = 0;
	char *ptr;
	char *ptrCopy;
	char **command;
	char inputCopy[INPUT_SIZE];

	strcpy(inputCopy, input);
	ptr = strtok(input, CUTTING_WORD);
	while (ptr != NULL)
	{
		counter++;
		ptr = strtok(NULL, CUTTING_WORD);
	}
	command = malloc((counter + 1) * sizeof(char *));
	if (command == NULL)
	{
		write(STDOUT_FILENO, "Error mem.\n", strlen("Error mem.\n"));
		exit(EXIT_FAILURE);
	}
	ptrCopy = strtok(inputCopy, CUTTING_WORD);
	while (ptrCopy != NULL)
	{
		command[i] = malloc((strlen(ptrCopy) + 1) * sizeof(char));
		if (command[i] == NULL)
		{
			write(STDOUT_FILENO, "Err mem\n", strlen("Err mem\n"));
			freeCommand(command);
			exit(EXIT_FAILURE);
		}

		strcpy(command[i], ptrCopy);
		command[i][strlen(ptrCopy)] = '\0';
		ptrCopy = strtok(NULL, CUTTING_WORD);
		i++;
	}

	command[counter] = NULL;
	*cmdLength = counter;
	return (command);
}
