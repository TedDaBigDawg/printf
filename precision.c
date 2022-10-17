#include "main.h"

/**
 * get_precision - gets the precision from the format string provided
 *
 * @s: the format string
 * @params: parameter struct
 * @ap: argument pointer
 * Return: a pointer
 */

char *get_precision(char *s, params_t *params, va_list ap)
{
	int i = 0;

	if (*s != '.')
	{
		return (s);
		s++;
	}

	if (*s == '*')
	{
		i = va_arg(ap, int);
		s++;
	}
	else
	{
		while (is_digit(*s))
		{
			i = i * 10 + (*s++ - '0');
		}
	}
	params->precision = i;

	return (s);
}
