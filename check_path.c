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

	while (p_array[i] != NULL)
	{
		/* construct full path*/
		c_path = malloc(strlen(t_array[0]) + strlen(p_array[i]) + 2);
		strcpy(c_path, p_array[i]);
		strcat(c_path, "/");
		strcat(c_path, t_array[0]);
		if (stat(c_path, &file_stat) == 0)
		{
			child_process(path, c_path, t_array);
			free(c_path);
			return (0);
		}
		free(c_path);
		i++;
	}
	return (1); /* command not found */
}
