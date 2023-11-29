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
	int array_size = 8; /* inital size of token array */
	size_t length;
	/* allocate memory for tokens */
	token_array = (char **)malloc(sizeof(char *) * array_size);
	if (token_array == NULL)
	{
		fprintf(stderr, "Error in memory allocation\n");
		exit (EXIT_FAILURE);
	}
	/* tokenize input line */
	current_token = strtok(input_line, "\n\t");
	while (current_token != NULL)
	{
		/* store each token in the array */
		token_array[token_index] = strdup(current_token);
		if (token_array[token_index] == NULL)
		{
			fprintf(stderr, "Error: Failed to allocate memory for token\n");
			exit(EXIT_FAILURE);
		}
		token_index++;

		/*resize array if necessary */
		if (token_index == array_size)
		{
			array_size *=2;
			token_array = realloc(token_array, sizeof(char *) * array_size);
			if (token_array == NULL)
			{
				fprintf(stderr, "Error in memory reallocation\n");
				exit(EXIT_FAILURE);
			}
		}
		current_token = strtok(NULL, "\n\t"); /* move to next token */
	}
	/* remove trailing newline character from each token */
	for (token_index = 0; token_index < array_size; token_index++)
	{
		length = strlen(token_array[token_index]);
		if (length > 0 && token_array[token_index][length - 1] == '\n')
		{
			token_array[token_index][length - 1] = '\0';
		}
	}
	
	token_array[token_index] = NULL; /*mark end of array with NULL*/

	return (token_array);
}
