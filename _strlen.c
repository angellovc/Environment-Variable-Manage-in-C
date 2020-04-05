#include "variable_manage.h"
/**
 *_strlen - get size of the string
 *@str: string
 *Return: size
 */
size_t _strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
		return (i);
}
