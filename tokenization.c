#include "main.h"
/**
 * tokenize - splits the line input into tokens
 * @input_line: the line input
 *
 * Return: array of tokens
 */

char **tokenize(char *input_line)
{
	char **token_array = NULL; /* array to store tokens */
	char *current_token; /* temporary storage for each token */
	int token_index = 0; /* index for token array */

	/* allocate memory for tokens */
	token_array = (char **)malloc(sizeof(char *) * 1024);
	if (token_array == NULL)
	{
		perror("Error in memory allocation");
		exit (EXIT_FAILURE);
	}
	/* tokenize input line */
	current_token = strtok(input_line, " \n\t");
	while (current_token != NULL)
	{
		/* store each token in the array */
		token_array[token_index] = strdup(current_token);
		token_index++;
		current_token = strtok(NULL, " \n\t");
	}

	token_array[token_index] = NULL; /*mark end of array with NULL*/

	return (token_array);
}
