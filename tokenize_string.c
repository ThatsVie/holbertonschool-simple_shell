#include "main.h"
/**
 * tokenize_string - tokenizes string using delimiters
 * @string : string to tokenize
 * @delimiters: delimiters for tokenization
 * @tokens: array to store tokens
 * Return: void
 */
void tokenize_string(char *string, char *delimiters, char **tokens)
{
	/* Use strtok to get the first token in the string*/
	char *token = strtok(string, delimiters);
	/* Initialize index to track position in the 'tokens' array */
	int i = 0;

	/* Continue tokenizing until there are no more tokens*/
	while (token != NULL)
	{
		/* Store the current token in the 'tokens' array */
		tokens[i] = token;
		/* Move to the next index in the 'tokens' array */
		i++;
		/* Use strtok with NULL to get the next token in the string */
		token = strtok(NULL, delimiters);
	}
	/*Set last element of tokens array to NULL indicate end of array */
	tokens[i] = NULL;
}
