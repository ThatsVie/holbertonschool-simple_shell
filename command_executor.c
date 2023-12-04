#include "main.h"
/**
 * execute - executes a command by forking a child process
 * @user_input: command entered by the user
 *
 * Return: exit status -1 on error
 */
int execute(char *user_input)
{
	char **command_args = NULL; /* array to store command arguments */
	char *command_path = NULL; /* path of command to be executed */
	pid_t child_pid;
	int child_status, exit_status = 0;

	/* Validate input */
	if (user_input == NULL)
		return (-1);
	/* tokenize user's command */
	command_args = tokenize(user_input);
	if (command_args == NULL)
		return (-1); /* tokenization failed */
	/* check if command is absolute path of needs path resolution */
	if (command_args[0][0] == '/')
	{
		/* Use input as path if it starts with '/' */
		command_path = strdup(command_args[0]);
	}
	else
		command_path = get_full_path(command_args[0]);
	/* check if get_full_path failed */
	if (command_path == NULL)
	{
		free_tokens(command_args);
		return (-1);
	}
	/*check if file exists and is executible before forking */
	if (access(command_path, F_OK | X_OK) == -1)
	{
		free_tokens(command_args);
	       	free(command_path);
		return (-1);
	}
	/* fork a child process for command execution */
	child_pid = fork();
	if (child_pid < 0)
	{
		free_tokens(command_args);
		free(command_path);
		return (-1); /* fork failed*/
	}
	else if (child_pid == 0) /*child process */
	{
		exit_status = execve(command_path, command_args, environ);
		exit(EXIT_FAILURE);
	}
	else /* parent process */
	{
		wait(&child_status);
		if (WIFEXITED(child_status))
			exit_status = WEXITSTATUS(child_status);
	}
	/* free up and return exit status */
	free_tokens(command_args);
	free(command_path);
	return (exit_status);
}
