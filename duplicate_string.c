#include "main.h"
/**
 * duplicate_string - duplicates a string and returns copy
 * @string: string to duplicate
 * Return: pointer to the duplicated string
 * NULL if memory allocation fails
 */
char *duplicate_string(char *string)
{
	int i = 0;
	int length = 0;
	char *duplicate;

	/* Check if the input string is NULL */
	if (string == NULL)
		return (NULL);
	/* Calculate the length of the input string */
	while (string[i] != '\0')
	{
		i++;
		length++; /* Include the null terminator */
	}
	length++;

	/* Allocate memory for the duplicated string */
	duplicate = malloc(length * sizeof(char));
	if (duplicate == NULL)
		return (NULL);/*Return NULL if memory allocation fails */

	/* Copy characters from input string to duplicated string */
	for (i = 0; i < length; i++)
		duplicate[i] = string[i];

	/*Return a pointer to the duplicated string*/
	return (duplicate);
}
