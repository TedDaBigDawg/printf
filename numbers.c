#include "main.h"

/**
 * _isdigit - checks if char is a digit
 *
 * @c: char to be checked
 * Return: 1 if its a digit, 0 if not
 */

int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - checks the length of a string
 *
 * @s: the string to be checked
 * Return: the length of the string
 */

int _strlen(char *s)
{
	int i = 0;

	while (*s++)
	{
		i++;
	}
	return (i);
}

/**
 * print_number - prints a number
 *
 * @str: the number string
 * @params: parameter struct
 * Return: something
 */

