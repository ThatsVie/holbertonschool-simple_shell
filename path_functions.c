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
	char *path_env, *copied_path;
	char full_path[1024];
	char *path_token;
	struct stat file_info;

	/* get the value of the PATH environment variable */
	path_env = getenv("PATH");
	if (path_env == NULL)
		return (NULL);
	/* duplicate the environment variable for tokenization */
	copied_path = strdup(path_env);
	/* tokenize the PATH variable to search for the command */
	path_token = strtok(copied_path, ":");
	printf("path_token-> %s \n", path_token);
	while (path_token)
	{
		/* construct full path */
		sprintf(full_path, "%s/%s", path_token, command);
			printf("full_path-> %s \n", full_path);
		/* check if path is valid */
		if (stat(full_path, &file_info) == 0)
		{
			printf("File info is valid! \n");
			free(copied_path);
			return (strdup(full_path));
		}
			path_token = strtok(NULL, ":"); /* get next token */
		}
	free(copied_path);
	return (NULL); /* command not found in directory*/
}
