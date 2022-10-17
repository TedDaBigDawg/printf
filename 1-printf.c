#include "main.h"

/**
 * _printf - prints to the standard output
 *
 * @format: the format string
 * Return: number of bytes printed
 */
int _printf(const char *format, ...)
{
	int sum = 0;
	char *p, *start;
	va_list ap;

	params_t params = PARAMS_INIT;

	va_start(ap, format);

	if (!format || (format[0] == '%' && !format[1]))
	{
		return (-1);
	}
	if (format[0] == '%' && format[1] == ' ' && !format[2])
	{
		return (-1);
	}
	for (p = (char *)format; *p; p++)
	{
		init_params(&params, ap);

		if (*p != '%')
		{
			sum += _putchar(*p);
			continue;
		}
		start = p;
		p++;

		if (!get_specifier(p))
		{
			sum += print_from_to(start, p, params.l_modifier || params.h_modifier ? p - 1 : 0);
		}
		else
		{
			sum += get_print_func(p, ap, &params);
		}
	}
	va_end(ap);
	return (sum);
}
