#include "main.h"

/**
 * reverse - Reverse a string
 * @s: The string to reverse
 *
 */
void reverse(char s[])
{
	int i, j;
	char tmp;

	for (i = 0, j = _strlen(s) - 1; i < j; j--, i++)
	{
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
	}
}

/**
 * _strlen - Calculate the length of a string
 * @str: The string
 *
 * Return: The length of the string
 */
int _strlen(char *str)
{
	int len = 0;

	while (str[len])
		len++;

	return (len);
}


/**
 * _print_binary - Print a binary number to stdout
 * @n: The number to print
 *
 * Return: The number of characters printed
 */
int _print_binary(unsigned int n)
{
	int ret = 0;
	int binary[32];
	int i = 0;

	while (n > 0)
	{
		binary[i] = n % 2;
		n /= 2;
		i++;
		ret++;
	}

	for (i--; i >= 0; i--)
		_putchar('0' + binary[i]);

	return (ret);
}


