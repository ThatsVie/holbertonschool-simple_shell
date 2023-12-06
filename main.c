#include "main.h"
/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 * @env: environment variables
 * Return: exit status
 */
int main(int argc, char **argv, char **env)
{
	char *input = NULL, *path = NULL;
	size_t size = 0;
	char *t_array[20], *p_array[20];
	int exit_status = 0, i;
	
	/* unsused parameters to avoid compiler warning */
	(void)argc;
	(void)argv;

	/*main shell execution loop*/
	while (1)
	{
		i = 0;
		/* find PATH environment variable*/
		while (env[i] != NULL)
		{
			if (strncmp(env[i], "PATH=", 5) == 0)
			{	/* extract PATH value and duplicate it */
				path = duplicate_string((env[i] + 5));
				break;
			}
			i++;
		}
		/* tokenize PATH into array of directories */
		tokenize_string(path, ":", p_array);

		/* print shell prompt if connected to terminal */
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "MARCEL $ ", 9);
		/* read a line of input from user */
		if (getline(&input, &size, stdin) == -1)
		{
			free(input);
			free(path);
			exit(EXIT_SUCCESS);
		}
		/* tokenize the user input into array of tokens */
		tokenize_string(input, " \n\t\r", t_array);

		/*handle empty input */
		if (!t_array[0])
		{
			free(path);
			continue;
		}
		/*handle exit command*/
		if (strcmp(t_array[0], "exit") == 0)
		{
			free(input);
			free(path);
			exit(EXIT_SUCCESS);
		}
		/*handle env command */
		if (strcmp(t_array[0], "env") == 0)
		{
			for (i = 0; env[i] != NULL; i++)
			{
				/* print each environment variable */
				write(STDOUT_FILENO, env[i], strlen(env[i]));
				write(STDOUT_FILENO, "\n", 1);
			}
			free(path);
			continue;
		}
		/* check if the command is executable */
		if (access(t_array[0], X_OK) == 0)
			child_process(path, t_array[0], t_array);
		else
			exit_status = check_path(path, p_array, t_array);
	}
	/* return final exit status of shell*/
	return (exit_status);
}

