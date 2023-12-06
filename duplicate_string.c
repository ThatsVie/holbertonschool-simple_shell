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
	
	if (string == NULL)
		return (NULL);
	
	while (string[i] != '\0')
	{
		i++;
		length++;
	}
	length++;

	duplicate = malloc(length * sizeof(char));
	if (duplicate == NULL)
		return (NULL);

	for (i = 0; i < length; i++)
		duplicate[i] = string[i];

	return (duplicate);
}
		
