#include "shell.h"

/**
 * get_builtins - Gets built command
 * @name: The name
 *
 * Return: Built-in command or NULL
 */
int (*get_builtins(char *name))(char **)
{
	builtins_t cmds[] = {
			{"env", _env},
			{"cd", cd},
			{"exit", __exit},
			{NULL, NULL},
	};
	int i;

	for (i = 0; cmds[i].cmd != NULL; i++)
	{
		if (_strcmp(name, cmds[i].name) == 0)
			return (cmds[i].cmd);
	}

	return (NULL);
}
