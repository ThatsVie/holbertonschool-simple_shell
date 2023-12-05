#include "main.h"
/**
 * child_process - creates child process and executes a command
 * @path: PATH environment variable
 * @c_path: full path of the command to execute
 * @c_args: arguments of the command
 * Return: Exit status of command
 */
int child_process(char *path, char *c_path, char **c_args)
{
	pid_t child_pid;
	pid_t wait_stat;
	int exit_stat = 0;

	free(path);
	child_pid = fork();

	if (child_pid == 0)
	{
		/* execute command */
		if (execve(c_path, c_args, NULL) == -1)
			exit(EXIT_FAILURE);
	}
	else if (child_pid < 0)
		exit(EXIT_FAILURE);
	else
	{
		do {
			wait_stat = waitpid(child_pid, &exit_stat, WUNTRACED);
		} while (WIFEXITED(exit_stat) && !WIFSIGNALED(exit_stat));
	}
	(void)wait_stat;
	return (exit_stat);
}
