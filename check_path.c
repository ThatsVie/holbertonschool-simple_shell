#include "main.h"
/**
 * check_path - searches for and executes a command in specified directories
 * @path : PATH environment variable
 * @p_array: directories to search for command
 * @t_array: arguments of the command
 * Return: exit status of the command
 */
int check_path(char *path, char **p_array, char **t_array)
{
	int i = 0;
	char *c_path = NULL;
	struct stat file_stat;

	/* Iterate through each directory in the path array */
	while (p_array[i] != NULL)
	{
		/* Construct full path by concatenating directory and command*/
		c_path = malloc(strlen(t_array[0]) + strlen(p_array[i]) + 2);
		if (c_path == NULL)
			exit(EXIT_FAILURE);

		strcpy(c_path, p_array[i]); strlen(p_array[i] + 1);
		strcat(c_path, "/");
		strcat(c_path, t_array[0]);

		/* Check if constructed path corresponds to an existing file*/
		if (stat(c_path, &file_stat) == 0)
		{
			/*If file exists, execute the command */
			child_process(path, c_path, t_array);
			free(c_path);
			return (0);
		}
		/* Free dynamically allocated memory for constructed path */
		free(c_path);
		/* Move to the next directory in the path array */
		i++;
	}
	/*If command is not found in any directory, return exit status 127 */
	return (127); /* command not found */
}
