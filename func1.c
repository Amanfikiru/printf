#include "main.h"
#include <stdarg.h>

/**
 * print_string - this function prints a string
 * @arg: is a va_list parameter
 * Return: count of printed characters
 */

int prtstring(va_list arg)
{
	const char *str;

	int cnt = 0;

	str = (const char *)va_arg(arg, char *);
	if (!str)
	{
		str = "(null)";
		_puts((char *)str);
		return (stringlength((char *)str));
	}
	_puts((char *)str);
	cnt += stringlength((char *)str);
	return (cnt);
}

/**
 * print_base16_upper_lower - function prints base16_upper_lower
 * @arg: is a va_list parameter
 * @rep: is a pointer to base16 string
 * Description: function takes 0123456789ABCDEF or 01223456789abcdef
 * in rep parameter to print hexadecimal format
 * Return: number of characters printed
 */

int prtbase16_upper_lower(va_list arg, char *repo)
{
	unsigned int i = 0;

	int cnt = 0;

	char *sl;

	i = va_arg(arg, unsigned int);
	sl = frtconverter(rep, i, 16);
	_puts(sl);
	cnt = stringlength(sl);
	return (cnt);
}
