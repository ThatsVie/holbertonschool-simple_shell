#ifndef MAIN_H
#define MAIN_H

#include <stdio.h> /*for standard input/output functions*/
#include <stdlib.h> /*For memory allocation and EXIT_SUCCESS/EXIT_FAILURE*/
#include <string.h> /*For string manipulation functions*/
#include <unistd.h> /* For access(), fork(), execve(), getpid() */
#include <sys/wait.h> /* For waitpid() */
#include <sys/types.h> /* For pid_t */
#include <sys/stat.h> /* For stat() */
#include <fcntl.h> /* For file control options (access mode) */

void tokenize_string(char *string, char *delimiters, char **tokens);
int check_path(char *path, char **p_array, char **t_array);
int child_process(char *path, char *c_path, char **c_args);
char *duplicate_string(char *string);

#endif
