#include "shell.h"

/**
 * argsize - Arguments count parsed
 * @args: Args List
 *
 * Return: int
 */
int argsize(char **args)
{
	int size, i;

	if (args == NULL)
		return (0);

	for (i = 0, size = 0; args[i] != NULL; i++)
		++size;
	return (size);
}
