#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

int main(int ac, char **argv);
void execmd(char **argv);
char *get_location(char *command);
void printenv()
void execute_command(char *command)
#endif
