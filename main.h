#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <wait.h>
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>

<<<<<<< HEAD
=======
extern char **environ;

ssize_t read_input(char **lineptr, size_t *n);
char **tokenize_input(char *line, const char *delim, int *num_tokens);
void free_arguments(char **args, int num_tokens);
int main(int ac, char **argv);
void execmd(char **argv);
char *get_location(char *command);
void printenv(void);
>>>>>>> 8636ca36835ee4c5428b1b18f2eafe69a528d65c

extern char **environ;
void _puts(char *str);
void prompt(void);
char *read_line(void);
void _printenv(void);
int _putchar(char h);
int _strcmp(char *stringA, char *stringB);
int c_atoi(char *l);
void _kill(char *lineptr, char *tmp, char **tok);
void ctrlc(int signum);
int is_equal_delim(char b, const char *delim);
char *_str_tokenization(char *sourc, const char *delim);
char *_strcpy(char *dest, char *src);
ssize_t get_line(char **str);
char *_strdup(char *str);

#endif
