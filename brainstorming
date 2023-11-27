#include <stdio.h>
#include <unistd.h>

/**
* main - getppid
* Description
* this program retrieves and prints the PID of the parent process
* using the getppid sustem call
* Return: 0
*/

int main(void)
{
	pid_t parent_pid;

	parent_pid = getppid();
	printf("Parent PID: %u\n", parent_pid);
 return (0);
}

#!/bin/sh
# Script to print the maximum value a process ID can be
# This script reads the maximum process ID value from /proc/sys/kernel/pid_max
# and prints i to the console

pid_max=$(cat /proc/sys/kernel/pid_max)
echo "Maximum PID: $pid_max"

0.av
#include <stdio.h>
/**
* main - print all command line arguments without using ac
* relies on NULL termination of av array
* Return: 0

int main(char **av)

{
	int i = 0;
	/* loop through the av array until NULL pointer is encountered*/
	while (av[i] != NULL)
	{
		/* print each argument on a new line */
		printf("%s\n", av[i]);
		i++;
	}

	return (0);
}

#include <stdio.h>
#include <stdlib.h>

/**
* main - read a line from the user using getline and print it
* this program prints "$", waits for the user to enter a command using getline
* and prints the entered command on next line.
* it handles EOF condition
* Return: always 0
*/
int main(void)
{
	char *input = NULL;
	size_t len = 0;
	ssize_t read;

	/* prompt user with "$" */
	printf("$ ");
	
	/* read a line of input from user using getline */
	read = getline(&input, &len, stdin);
	
	/* check for end of file or error */
	if (read == -1)
	{
		if (feof(stdin))
		{
		/* handle end of file */
		printf("\nEnd of input. exiting ...\n");
		}
		else
		{
		/* handle error */
		perror("getline");
		}
	}
	else
	{
		/*print entered command */
		printf("you entered: %s", input);
	}

	/* free allocated memory
	free(input);
	return 0;
}

