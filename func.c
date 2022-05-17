#include "main.h"
#include <stdarg.h>

/**
 * print_character - prints a character
 * @arg: is a va_list type
 * Return: 1
 */
int prtcharacter(va_list arg)
{
	unsigned char i;

	i = (unsigned char)va_arg(arg, int);
	_putchar(i);
	return (1);
}

/**
 * prtsignInt - print sign
 * @arg: is a va_list argument
 * @b: e.g., base 10
 * Return: count of digits printed
 */
int prtsignInt(va_list arg, int b)
{
	int i = 0, cnt = 0;

	char *sl;

	i = va_arg(arg, int);
	if  (i < 0)
	{
		i = -(i);
		cnt += _putchar('-');
	}
	sl = ftrconverter("0123456789ABCDEF", i, b);
	_puts(sl);
	cnt += stringlength(sl);
	return (cnt);
}


/**
 * prtunsignedInt - function prints unsigned
 * @arg: is a va_list parameter
 * @b: is an integer
 * Return: is a count of printed characters
 */
int prtunsignedInt(va_list arg, int b)
{
	unsigned int i;

	char *sl;

	int cnt = 0;

	i = va_arg(arg, unsigned int);
	sl = ftrconverter("0123456789ABCDEF", i, b);
	_puts(sl);
	cnt += stringlength(sl);
	return (cnt);
}

/**
 * prtaddr - print address of arg
 * @arg: va_list parameter
 * Return: count of printed characters
 */
int prtaddr(va_list arg)
{
	unsigned long int d, buf;

	char a[100];

	int cnt, n, i;

	d = (unsigned long int)va_arg(arg, void*);
	buf = d;
	cnt = 1;
	i = 0;
	if (!d)
	{
		_puts("(nil)");
		return (5);
	}
	while (buf)
	{
		buf /= 16;
		cnt++;
	}
	a[cnt + 1] = '\0';
	while (d > 0)
	{
		n = (d % 16);
		if (n >= 0 && n <= 9)
			a[cnt] = ((char)(n + '0'));
		else
			a[cnt] = ((char)(n + 'W'));
		cnt--;
		d /= 16;
	}
	a[0] = '0';
	a[1] = 'x';
	while (a[i] != '\0')
		i += _putchar(a[i]);
	return (i);
}
