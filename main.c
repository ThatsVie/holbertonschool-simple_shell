#include "main.h"
/**
 * main - entry point
 * Return: When success 0, when error -1
 */
int main(void)
{
	char *user_input = NULL; /*variable to store user input */
	int exit_status = 0, getline_result;
	size_t buffer_size = 0; /* size of buffer for getline */

	while (1)/* creates infinite loop - main execution loop of shell*/
	{ /* check if connected to a terminal and print shell prompt*/
		if (isatty(STDIN_FILENO))
			printf("$ ");
		/* read a line of input from user */
		getline_result = getline(&user_input, &buffer_size, stdin);
		/* check for errors or EOF */
		if (getline_result == -1)
		{
			if (feof(stdin))
			{
				printf("\n");
				free(user_input);
				exit(EXIT_SUCCESS);
			}
			break;
		}
		if (strcmp(user_input, "exit\n") == 0)
		{
			free(user_input);
			exit(EXIT_SUCCESS);
		}
		/* check for env command */
		if (strcmp(user_input, "env\n") == 0)
		{
			print_environment(); /*print environment variable*/
			free(user_input);
			continue;
		}
		exit_status = execute(user_input);

		if (exit_status == -1)
			perror("Execution Error");
		free(user_input);
	}
	return (exit_status);
}
