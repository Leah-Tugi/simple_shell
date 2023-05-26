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
