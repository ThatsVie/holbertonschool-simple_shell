#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

extern char **environ;
int main(void);
int execute(char *user_input);
char **tokenize(char *input_line);
char **tokenize_path(char *path_string);
char *get_full_path(char *command);
void print_environment(void);
void free_tokens(char **token_array);
void handle_signal (int signal);

#endif
