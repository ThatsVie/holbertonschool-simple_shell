#include "main.h"
/**
 * child_process - creates child process and executes a command
 * @path: PATH environment variable (freed in function)
 * @c_path: full path of the command to execute
 * @c_args: arguments of the command
 * Return: Exit status of command
 */
int child_process(char *path, char *c_path, char **c_args)
{
	pid_t child_pid;
	pid_t wait_stat;
	int exit_stat = 0;

	/* Free the dynamically allocated memory for the PATH variable */
	free(path);
	/* Create a child process using fork() */
	child_pid = fork();

	if (child_pid == 0)
	{
		/* In the child process, execute the specified command */
		if (execve(c_path, c_args, NULL) == -1)
			exit(EXIT_FAILURE);/*Exit if execution fails */
	}
	else if (child_pid < 0)
		exit(EXIT_FAILURE);/*Exit the parent process if fork fails */
	else
	{
		/*In parent process, wait fo child process to complete*/
		do {
			wait_stat = waitpid(child_pid, &exit_stat, WUNTRACED);
		} while (WIFEXITED(exit_stat) && !WIFSIGNALED(exit_stat));
	}
	/*Ignore the wait_stat variable to prevent compiler warnings*/
	(void) wait_stat;
	/*Return the exit status of the executed command */
	return (exit_stat);
}
