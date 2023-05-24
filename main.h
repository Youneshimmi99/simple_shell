#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#ifdef __unix__
#include <sys/wait.h>
#endif

#define BUFSIZE 1024

int execute_command(char *command);

#endif
