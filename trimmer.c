#include "shell.h"

/**
 * _trim_left - deletes whitespaces at the start
 * @str: The string
 *
 * Return: trimmed string
 */
char *_trim_left(char *str)
{
	char *trimmed = NULL;
	char c;
	int i, j, start = 0;
	int len = 0;

	if (str == NULL)
		return (NULL);

	for (i = 0, j = 0; str[i] != '\0'; i++)
	{
		c = str[i];
		if (c != ' ' && c != '\n' && start == 0)
			start = 1;

		if (start == 1)
		{
			len = _strlen(trimmed);
			trimmed = _realloc(trimmed, len, len + 2);
			if (trimmed != NULL)
			{
				trimmed[j++] = c;
				trimmed[j] = '\0';
			}
		}
	}
	return (trimmed);
}

/**
 * _trim_right - deletes whitespaces at the
 * end of a string, also new line at the end
 * @str: The string
 *
 * Return: trimmed string
 */
char *_trim_right(char *str)
{
	char *trimmed, *temp;
	char *reversed;

	reversed = _reverse_str(str);
	temp = _trim_left(reversed);
	trimmed = _reverse_str(temp);
	free(temp);
	free(reversed);
	return (trimmed);
}

/**
 * _trim - deletes whitespaces at the start and
 * end of a string, also new line at the end
 * @str: The string
 *
 * Return: trimmed string
 */
char *_trim(char *str)
{
	char *trimmed, *temp;

	temp = _trim_left(str);
	trimmed = _trim_right(temp);
	free(temp);
	return (trimmed);
}
