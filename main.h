#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pwd.h>
#include <errno.h>
#include "main.h"

#define INPUT_SIZE 510
#define CUTTING_WORD " \n"
#define ENDING_WORD "done"
#define RESET 0

void DisplayPrompt(void);
char **parseInput(char *input, int *cmdLength);
void freeCommand(char **command);
void printEnvironment(void);
void setEnvironmentVariable(char **command);
void unsetEnvironmentVariable(char **command);
void executeCommand(char **command);
int main(void);
void executeDefaultCommand(char **command);
void executeUnsetenvCommand(char **command);
void executeSetenvCommand(char **command);
void executeEnvCommand(char **command);
void executeExitCommand(char **command, int cmdLength);
void executeCdCommand(char **command);

extern char **environ;

#endif
