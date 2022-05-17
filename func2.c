#include "main.h"
#include <stdarg.h>

/**
 * print_character - prints a character
 * @arg: is a va_list type
 * Return: 1
 */
int print_character(va_list arg)
{
	unsigned char i;

	i = (unsigned char)va_arg(arg, int);
	_putchar(i);
	return (1);
}

/**
 * print_signInt - print sign
 * @arg: is a va_list argument
 * @base: e.g., base 10
 * Return: count of digits printed
 */
int print_signInt(va_list arg, int base)
{
	int i = 0, count = 0;

	char *s;

	i = va_arg(arg, int);
	if  (i < 0)
	{
		i = -(i);
		count += _putchar('-');
	}
	s = convert_to_format("0123456789ABCDEF", i, base);
	_puts(s);
	count += _strlen(s);
	return (count);
}


/**
 * print_unsignedInt - function prints unsigned
 * @arg: is a va_list parameter
 * @base: is an integer
 * Return: is a count of printed characters
 */
int print_unsignedInt(va_list arg, int base)
{
	unsigned int i;

	char *s;

	int count = 0;

	i = va_arg(arg, unsigned int);
	s = convert_to_format("0123456789ABCDEF", i, base);
	_puts(s);
	count += _strlen(s);
	return (count);
}

/**
 * print_addr - print address of arg
 * @arg: va_list parameter
 * Return: count of printed characters
 */
int print_addr(va_list arg)
{
	unsigned long int dec, buffer;

	char c[100];

	int count, n, i;

	dec = (unsigned long int)va_arg(arg, void*);
	buffer = dec;
	count = 1;
	i = 0;
	if (!dec)
	{
		_puts("(nil)");
		return (5);
	}
	while (buffer)
	{
		buffer /= 16;
		count++;
	}
	c[count + 1] = '\0';
	while (dec > 0)
	{
		n = (dec % 16);
		if (n >= 0 && n <= 9)
			c[count] = ((char)(n + '0'));
		else
			c[count] = ((char)(n + 'W'));
		count--;
		dec /= 16;
	}
	c[0] = '0';
	c[1] = 'x';
	while (c[i] != '\0')
		i += _putchar(c[i]);
	return (i);
}
