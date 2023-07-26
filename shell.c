#include "shell.h"

/**
 * main - a shell program
 * @argc: arguments counts
 * @argv: List of arguments passed
 *
 * Return: 0
 */
int main(int argc, char **argv)
{
	char *str, *nocomments, *trimmed;
	int mode = 1;
	shell_var_t var = {0, 0, 0};

	var.pid = getpid();
	/*signal(SIGINT, sigintHandler);*/
	while (mode)
	{
		str = NULL;
		if (argc > 1)
		{
			if (fileProcessor(argv[1], &str) == 0)
				exit(var.code);
		}
		else
		{
			if ((int)prompt(&str, &mode) == -1)
			{
				free(str);
				exit(var.code);
			}
		}

		trimmed = _trim(str);
		nocomments = removeComment(trimmed);
		free(str);
		free(trimmed);
		str = nocomments;
		if (processLogical(argv[0], str, &var) == 1)
			continue;
		else if (processCmdSp(argv[0], str, &var) == 1)
			continue;
		else
			processcmd(argv[0], str, &var);
	}
	return (var.code);
}
