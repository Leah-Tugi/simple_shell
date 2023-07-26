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
#include <signal.h>

#define PROMPT "#cisfun$ "

typedef struct {
    char *shell_name;
    char *cmd;
    char **av;
    int last_exit_status;
} data;

void init_data(data *d, char *shell_name);
void free_array(char **arr);
void read_cmd(data *d);
void split(data *d, char *delimiters);
int exec_builtin(data *d);
void _which(data *d);

void start(data *d);
void han_sig(int signal);
void _exec(data *d);
int main(int argc, char **argv);

#endif
