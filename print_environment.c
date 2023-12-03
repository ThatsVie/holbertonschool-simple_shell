#include "main.h"
/**
 * print_environment - prints the current environment variables
 */

void print_environment(void)
{
	char **env_variable = environ; /* pointer to environment variables */

	while (*env_variable != NULL)
	{
		printf("%s\n", *env_variable);
		env_variable++;
	}
}
