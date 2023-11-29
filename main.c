#include "main.h"
/**
 * main - entry point
 * Return: When success 0, when error -1
 */
int main(void)
{
	char *user_input = NULL; /* pointer to string to store user input */
	size_t buffer_size = 0; /* variable to store the size of buffer for getline*/
	int exit_status = 0; /* integer to store the exit status of shell */
	int i; /* integer variable to store result of getline function */

	while (1) /* creates infinite loop - main execution loop of shell*/
	{
		if(isatty(STDIN_FILENO)) /*checks if connected to terminal */
		{
			printf("$ "); /* if so, prints shell prompt */

			signal(SIGINT, handle_signal); /* for Ctrl+C */
		}

/* read line of input from user,store line in user_input then result in i */
		i = getline(&user_input, &buffer_size, stdin);

/* check if error or EOF. print new line if EOF, free memory, exit program */
		if (i == -1)
		{
			if (feof(stdin))
			{
				printf("\n");
				free(user_input);
				exit(EXIT_SUCCESS);
			}
			break;
		}
	/* check if entered exit or env command */
		if (strcmp(user_input, "exit\n") == 0)
		{
			free(user_input);
			exit(exit_status);
		}

		if (strcmp(user_input, "env\n") == 0)
		{
			print_environment();
			free(user_input);
			continue;
		}
	/* execute user input. if execution fails print error, free memory */
		exit_status =  execute(user_input);
		if (exit_status == -1)/* execution fails*/
		perror( "Error");
		
	/* free memory allocated by getline */
		free(user_input);
		
	/*reset buffer_size to 0 */
		buffer_size = 0;
		
		user_input = NULL; /* set pointer to NULL after freeing */
	}

	return (exit_status);
}
