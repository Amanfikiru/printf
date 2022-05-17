#include "main.h"
#include <stdarg.h>

/**
 * print_string - this function prints a string
 * @arg: is a va_list parameter
 * Return: count of printed characters
 */

int print_string(va_list arg)
{
	const char *str;

	int count = 0;

	str = (const char *)va_arg(arg, char *);
	if (!str)
	{
		str = "(null)";
		_puts((char *)str);
		return (_strlen((char *)str));
	}
	_puts((char *)str);
	count += _strlen((char *)str);
	return (count);
}

/**
 * print_base16_upper_lower - function prints base16_upper_lower
 * @arg: is a va_list parameter
 * @rep: is a pointer to base16 string
 * Description: function takes 0123456789ABCDEF or 01223456789abcdef
 * in rep parameter to print hexadecimal format
 * Return: number of characters printed
 */

int print_base16_upper_lower(va_list arg, char *rep)
{
	unsigned int i = 0;

	int count = 0;

	char *s;

	i = va_arg(arg, unsigned int);
	s = convert_to_format(rep, i, 16);
	_puts(s);
	count = _strlen(s);
	return (count);
}
