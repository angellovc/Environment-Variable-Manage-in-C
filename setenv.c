#include "variable_manage.h"
/**
 *_setenv - set or change an environment varialbe
 *@name: variable name
 *@value: variable value
 *@overwrite: 1 to overwrite, 0 to dont
 *Return: 0 success, -1 error
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	size_t i = 0;

	while (environ[i] != NULL)
	{
		if (comp_string(environ[i], name) && overwrite)
		{
			overwrite_after("=", (char *)value, environ[i]);
			return (0);
		}
		else if (comp_string(environ[i], name) && !overwrite)
			return (0);
		i++;
	}
	environ = realloc_environ(environ, sizeof(char *) * (i + 1));
	if (environ == '\0')
		return (-1);
	environ[i] = write_variable(name, value, environ[i]);
	if (environ[i] == '\0')
		return (-1);
	return (0);
}
