#include "main.h"

#define BUFFER_SIZE 1024

/**
 * main - entry point
 *
 * Return: 0 always
 */

int main(void)
{
	char buffer[BUFFER_SIZE];
	ssize_t chars;
	int status = 0;
	
	while (1)
	{
		printf("$ ");  /* Display prompt */
		chars = read(STDIN_FILENO, buffer, BUFFER_SIZE);  /* Read command line */
		if (chars == EOF)
		{
			printf("\n");
			break;  /* End of file, exit the shell */
		}
		if (chars > 0 && buffer[chars - 1] == '\n')
			buffer[chars - 1] = '\0';  /* Remove the newline character */

		if (access(buffer, X_OK) == 0)  /* Check if executable file exists */
		{	
			pid_t child_pid = fork();
			if (child_pid == -1)
			{
				perror("Fork error");
				exit(EXIT_FAILURE);
			}
			
			if (child_pid == 0)  /* Child process */
			{
				if (execve(buffer, NULL, NULL) == -1)
				{
					perror("Execve error");
					exit(EXIT_FAILURE);
				}
			}
			else  /* Parent process */
			{
				wait(&status);
			}
		}
		else
		{
			fprintf(stderr, "Command not found: %s\n", buffer);
		}
	}
	
	return (0);

}
