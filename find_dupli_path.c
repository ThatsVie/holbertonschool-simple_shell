#include "main.h"
/**
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
