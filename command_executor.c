include "main.h"
/**
 * execute - executes a command by forking a child process
 * @user_command: command entered by the user
 *
 * Return: exit status 0 on success, -1 on error
 */
 
int execute(char *user_command)
{
	char **command_arguments = NULL; /* array to store command arguments*/
	char *command_path = NULL; /* path o the comand to be executed */
	pid_t child_pid;
	int child_status, exit_status = 0;



