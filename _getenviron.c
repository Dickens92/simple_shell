#include "shell.h"

/**
 * _getenv - Gets the environment key
 * @k: The key 
 *
 * Return: char*
 */
char *_getenv(char *k)
{
	char *data, *token, *env;
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		env = _strdup(environ[i]);
		token = _tokenize(env, "=");
		if (token != NULL && _strcmp(token, k) == 0)
		{
			data = _tokenize(NULL, "=");
			if (token)
				free(token);
			free(env);
			return (data);
		}
		if (token)
			free(token);
		free(env);
	}
	return (NULL);
}
