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
