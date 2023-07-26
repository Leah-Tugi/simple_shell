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

void _printstring(char *str);
char *pass_line(void);
char *var_build(char *var_name, char *var_value);
int _setenviron(char *var_name, char *var_value);
int _unsetenviron(char *var_name);
int _exec(char **tokens, char *args);
int _stringlength(char *s);
char *_stringcat(char *dest, char *src);
unsigned int _white_space_checker(char *s);
char **_stringtotokens(char *str);
int _writechar(char c);
int _stringcomp(char *s1, char *s2);
int _atoi(char *s);
char *_stringcpy(char *dest, char *src);
int equal_delim(char c, const char *delim);
char *_stringtokarr(char *src, const char *delim);
void ctrlc(int signum);
ssize_t custom_getline(char **str);
char *_stringduplicate(char *str);
void _exitShell(char **tokens, char *line);
int _execBuiltIn(char **tokens);
int _myBuiltIn(char *str);
void _printsenvironment(void);
int file_status(char *s);
char *path_constructor(char **tokens);
int path_execute(char **tokens, char *path, char *args);
int main(int argc, char *argv[]);
void prompt(void);
int _cd(char *path);

/*void _kill(char *lineptr, char *tmp, char **tok);*/


#endif
