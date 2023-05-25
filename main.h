#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

ssize_t read_input(char **lineptr, size_t *n);
char **tokenize_input(char *line, const char *delim, int *num_tokens);
void free_arguments(char **args, int num_tokens);
int main(int ac, char **argv);
void execmd(char **argv);
char *get_location(char *command);
<<<<<<< HEAD
void printenv(void);
void execute_command(char *command);

=======
void printenv()
void execute_command(char *command, char **args)
void execute_command(char *command)
>>>>>>> bb66347c927ad29813c4db7919513d653cea6cb4

#endif
