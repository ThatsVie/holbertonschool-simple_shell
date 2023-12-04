#include "main.h"
/**
 * tokenize_path - tokenizes PATH variable into an array of tokens
 * @path_string: the full path string
 *
 * Return: array of pointers to path tokens
 */

char **tokenize_path(char *path_string)
{
	char **path_tokens;
	int token_index = 0;
	char *token;

	/* allocate memory for the buffer */
	path_tokens = (char **)malloc(sizeof(char *) * 1024);
	if (path_tokens == NULL)
	{
		perror("Error in memory allocation");
		exit(EXIT_FAILURE);
	}

	/* tokenize path string */
	token = strtok(path_string, ":");
	while (token != NULL)
	{
		path_tokens[token_index] = token;
		token = strtok(NULL, ":");
		token_index++;
	}
	path_tokens[token_index] = NULL; /* marking end of buffer */

	return (path_tokens);
}

/**
 * get_full_path - gets the  full path fo a given command
 * @command: the command for which the full path is needed
 *
 * Return: full path or NULL on error
 */
char *get_full_path(char *command)
{
	char *path_env;
	char full_path[1024];
	struct stat file_info;
	char **path_tokens;
	int i;
	/*if command already has a path use it directly */
	if (strchr(command, '/') != NULL)
	{
		if (stat(command, &file_info) == 0)
		return (strdup(command));
		return (NULL); /* if condition is false */
	}
	/* get the value of the PATH environment variable */
	path_env = getenv("PATH");
	if (path_env == NULL)
		return (NULL);

	/* tokenize PATH variable */
	path_tokens = tokenize_path(path_env);
	if (path_tokens == NULL)
		return (NULL);
	/* iterate through each directory in PATH */
	for (i = 0; path_tokens[i] != NULL; i++)
	{
		/* construct full path */
		snprintf(full_path, sizeof(full_path), "%s/%s", path_tokens[i], command);

		/* check if path is valid */
		if (stat(full_path, &file_info) == 0)
		{
			free(path_tokens);
			return (strdup(full_path));
		}
	}
	free(path_tokens);
	return (NULL);
}
