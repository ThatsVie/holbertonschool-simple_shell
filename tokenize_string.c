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
	char *token = strtok(string, delimiters);
	int i = 0;

	while (token != NULL)
	{
		tokens[i] = token;
		i++;
		token = strtok(NULL, delimiters);
	}
	tokens[i] = NULL;
}
