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

void start(data *d);
void han_sig(int signal);
void _exec(data *d);
int main(int argc, char **argv);

#endif
