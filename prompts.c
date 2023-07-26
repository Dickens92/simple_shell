#include "shell.h"

/**
 * prompt - Prompts for input
 * @str: The pointer for input storage
 * @mode: The shell mode
 *
 * Return: void
 */
size_t prompts(char **str, int *mode)
{
	size_t len = 0;
	size_t status;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
	else
		*mode = 0;

	status = getline(str, &len, stdin);
	return (status);
}
