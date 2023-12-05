#include "main.h"
/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 * @env: environment variables
 * Return: exit status
 */
int main( int argc, char **argv, char **env)
{
	char *input = NULL, *path = NULL;
	size_t size = 0;
	char *t_array[33], *p_array[33];
	int exit_status = 0;
	int i;

	(void)argc;
	(void)argv;

	while (1)
	{
		i = 0;
		while (env[i] != NULL)
		{	/* 5 because number of characters in PATH= */
			if (strncmp(env[i], "PATH=", 5) == 0)
			{
				path = duplicate_string((env[i] + 5));
				break;
			}
			i++;
		}
		tokenize_string(path, ":", p_array);

		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		if (getline(&input, &size, stdin) == -1)
		{
			free(input);
			free(path);
			exit(EXIT_SUCCESS);
		}
		tokenize_string(input, " \n\t", t_array);

		if (!t_array[0])
		{
			free(path);
			continue;
		}
		if (strcmp(t_array[0], "exit") == 0)
		{
			free(input);
			free(path);
			exit(EXIT_SUCCESS);
		}
		if (strcmp(t_array[0], "env") == 0)
		{
			for (i = 0; env[i] != NULL; i++)
			{
				write(STDOUT_FILENO, env[i], strlen(env[i]));
				write(STDOUT_FILENO, "\n", 1);
			}
			free(path);
			continue;
		}
		if (access(t_array[0], X_OK) == 0)
			exit_status = child_process(path, t_array[0], t_array);
		else
			exit_status = check_path(path, p_array, t_array);
	}
	return (exit_status);
}

