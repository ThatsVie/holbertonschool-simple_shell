#include "main.h"
/**
 * handle_signal - handles the SIGINT signal ( Ctrl + C)
 * @signal: input signal number
 * Description: 
 * This function serves as a signal handler for the SIGINT signal.
 * When the user presses Ctrl+C, this signal is sent to the process.
 * The function catches this signal and prints a newline and the shell prompt.
 */
void handle_signal (int signal)
{
	if (signal == SIGINT)
	{
		printf("\n$ ");
	}
}
