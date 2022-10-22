#include "main.h"

/**
 * _puts - prints a string with a newline
 *
 * @str: string to be printed
 * Return: string
 */

int _puts(char *str)
{
	char *a = str;

	while (*str)
	{
		_putchar(*str++);
	}

	return (str - a);
}

/**
 * _putchar - prints a character to standard output
 *
 * @c: character to be printed
 * Return: 1 if success, and -1 if failed
 */

int _putchar(char c)
{
	static int i;
	static char buf[OUTPUT_BUF_SIZE];

	if (c == BUF_FLUSH || i >= OUTPUT_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}

	if (c != BUF_FLUSH)
	{
		buf[i++] = c;
	}

	return (1);
}
