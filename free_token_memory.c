#include "main.h"
/**
 * free_tokens - frees the array of tokens
 * @token_array: tokens array to be freed
 */
void free_tokens(char **token_array)
{
	int token_index;
	
	if (token_array == NULL)
		return;

	for (token_index = 0; token_array[token_index] != NULL; token_index++)
	{
		free(token_array[token_index]);
	}
	free(token_array);
}
