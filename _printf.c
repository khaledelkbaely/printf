#include "main.h"

/**
 * _printf - Custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
	int ret = 0;
	va_list args;
	char *iter;

	va_start(args, format);

	if (!format || !format[0])
		return (-1);

	iter = (char *)format;
	while (*iter)
	{
		if (*iter != '%')
		{
			ret += _putchar(*iter);
			iter++;
			continue;
		}

		iter++;
		switch (*iter)
		{
		case 'c':
			ret += _putchar(va_arg(args, int));
			break;
		case 's':
			ret += _puts(va_arg(args, char *));
			break;
		case 'd':
		case 'i':
			ret += _print_decimal(va_arg(args, long));
			break;
		case '%':
			ret += _putchar('%');
			break;
		case 'b':
			ret += _print_binary(va_arg(args, unsigned int));
			break;
		default:
			break;
		}
		iter++;
	}

	va_end(args);

	return (ret);
}

/**
 * _putchar - Write a character to stdout
 * @c: The character to write
 *
 * Return: 1 on success, -1 on failure
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - Write a string to stdout
 * @str: The string to write
 *
 * Return: The number of characters written
 */
int _puts(char *str)
{
	int sum = 0;

	if (!str)
		return (0);

	while (*str)
	{
		_putchar(*str);
		sum++;
		str++;
	}

	return (sum);
}

/**
 * _print_decimal - Print a decimal number to stdout
 * @n: The number to print
 *
 * Return: The number of characters printed
 */
int _print_decimal(long int n)
{
	int ret = 0;
	int sign, remainder;
	long int tmp = n;
	char *s;

	while (tmp)
	{
		tmp /= 10;
		ret++;
	}

	if (n < 0)
		ret++;
	s = malloc((ret + 1) * sizeof(char));
	if (s == NULL)
		return (1);

	sign = n;
	ret = 0;
	do
	{
		remainder = n % 10;
		s[ret++] = ((sign < 0) ? -remainder : remainder) + '0';
	} while (n /= 10);
	if (sign < 0)
		s[ret++] = '-';
	s[ret] = '\0';
	reverse(s);
	_puts(s);
	free(s);

	return (ret);
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

/**
 * reverse - Reverse a string
 * @s: The string to reverse
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

