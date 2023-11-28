#include "main.h"
/**
 * execute - executes a command by forking a child process
 * @user_command: command entered by the user
 *
 * Return: exit status 0 on success, -1 on error
 */
 
int execute(char *user_command)
{
	char **command_arguments = NULL; /* array to store command arguments*/
	char *command_path = NULL; /* path of the comand to be executed */
	pid_t child_pid;
	int child_status, exit_status = 0;

	/* tokenize the user's command */
	command_arguments = tokenize(user_command);
	if (command_arguments == NULL)
	{
		fprintf(stderr, "Error: Failed to tokenize the command.\n");
		return (-1);
	}

	/* Is command an absolute path or needs path resolution */
	if (user_command[0] == '/')
	{
		command_path = strdup(user_command);
	}
	else
	{
		command_path = get_path(command_arguments[0]);
	}
	
	if (command_path == NULL)
	{
		fprintf(stderr, "Error: Failed to retrieve full path.\n");
		free_tokens(command_arguments);
		return (-1);
	}

	/* Fork a child process for command execution */

	child_pid = fork();
	if (child_pid < 0)
	{
		fprintf(stderr, "Error: Failed to fork a child process.\n");
		free_tokens(command_arguments);
		free(command_path);
		return (-1);
	}
	else if (child_pid == 0)
	{ 
		/* child process */
		exit_status = execve(command_path, command_arguments, environ);
	}
	else
	{
		/*parent process */
		wait(&child_status);
		if (WIFEXITED(child_status))
		{
			exit_status = WEXITSTATUS(child_status);
		}
	}

	/* free up and return exit status */
	free_tokens(command_arguments);
	free(command_path);
	return (exit_status);
}



