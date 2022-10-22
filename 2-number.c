#include "main.h"

/**
 * print_from_to - prints a range of addresses in memory
 *
 * @start: starting addres
 * @stop: address to stop at
 * @except: address to be excluded
 * Return: number of bytes printed
 */

int print_from_to(char *start, char *stop, char *except)
{
	int sum = 0;

	while (start <= stop)
	{
		if (start != except)
		{
			sum += _putchar(*start);
		}

		start++;
	}

	return (sum);
}

/**
 * print_rev - prints a string in reverse
 *
 * @ap: argument pointer (string)
 * @params: parameter struct
 * Return: number of bytes printed
 */

int print_rev(va_list ap, params_t *params)
{
	int len, sum = 0;
	char *str;
	(void)params;

	str = va_arg(ap, char *);

	if (str)
	{
		for (len = 0; *str; str++)
		{
			len++;
		}
		str--;

		for (; len > 0; len--, str--)
		{
			sum += _putchar(*str);
		}
	}

	return (sum);
}

/**
 * print_rot13 - prints string in rot13 format
 *
 * @ap: argument pointer (string)
 * @params: parameter struct
 * Return: number of bytes printed
 */

int print_rot13(va_list ap, params_t *params)
{
	int count = 0;
	int i, index;
	char arr[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(ap, char *);
	(void)params;

	index = 0;
	i = 0;

	while (a[i])
	{
		if ((a[i] >= 'A' && a[i] <= 'Z') || (a[i] >= 'a' && a[i] <= 'z'))
		{
			index = a[i] - 65;
			count += _putchar(arr[index]);
		}
		else
		{
			count += _putchar(a[i]);
		}
		i++;
	}

	return (count);
}
