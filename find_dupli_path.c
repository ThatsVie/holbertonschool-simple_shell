#include "main.h"
/**
 * find_and_duplicate_path - Finds the PATH environment variable
 * and duplicates its value.
 * @env: array of environment variables
 * return: duplicated path value
 */
char *find_and_duplicate_path(char **env)
{
	int i = 0;
	char *path = NULL;

	while (env[i] != NULL)
	{
		if (strncmp(env[i], "PATH=", 5) == 0)
		{
			path = duplicate_string((env[i] + 5));
			break;
		}
		i++;
	}
	return (path);
}
