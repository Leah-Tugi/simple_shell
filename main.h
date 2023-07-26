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
void prompt(void);
char *pass_line(void);
int _stringlength(char *s);
char *_stringcat(char *dest, char *src);
char **_stringtotoken(char *str);
int _exec(char **tokens, char *args);
void printenvironment(void);
int writechar(char c);
int _stringcomp(char *s1, char *s2);
int _execmybuiltin(char **tokens);
int mybuiltin(char *str);
int _atoi(char *s);
void _kill(char *lineptr, char *tmp, char **tok);
void _exitShell(char **tokens, char *line);
void ctrlc(int signum);
int equal_delim(char c, const char *delim);
char *_stingtokarr(char *src, const char *delim);
char *_stringcopy(char *dest, char *src);
ssize_t custom_getline(char **str);
int handle_path(char **tokens);
int file_status(char *s);
char *path_constructor(char **tokens);
int path_exec(char **tokens, char *path, char *args);
char *buid_var(char *var_name, char *var_value);
int _setenviron(char *var_name, char *var_value);
int _unsetenviron(char *var_name);
char *_stringduplicate(char *str);

#endif
