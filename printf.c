#include "main.h"
#include <stdarg.h>

/**
 * _printf - function produces output according to a format.
 * @format: is a pointer to string
 * Return: is the count of printed characters
 */
int _printf(const char *format, ...)
{
	const char *str;

	int cnt = 0;

	va_list arg;

	if (!format)
		return (-1);

	va_start(arg, format);
	str = format;

	count = loopfrt(string, args);

	va_end(arg);

	return (cnt);
}

/**
 * loopfrt - function is to print format
 * @format: is a pointer to string
 * @arg: is a va_list args
 * Return: is an integer.
 */
int loopfrt(const char *format, va_list arg)
{
	int i = 0, cntr = 0, flag = 0, chkflag = 0, fcntr = 0;

	while (i < stringlength((char *)format) && *(format + i) != '\0')
	{
		char chara = format[i];

		if (chara == '%')
		{
			flag++, i++;
			chara = format[i];
			if (chara == '\0' && stringlength((char *)format) == 1)
				return (-1);
			if (chara == '\0')
				return (cntr);
			if (chara == '%')
				flag++;
			else
			{
				fcntr = funservice(chara, arg);
				if (fcntr >= 0 && fcntr != -1)
				{
					i++;
					chara = format[i];
					if (chara == '%')
						flag--;
					cntr += fcntr;
				}
				else if (fcntr == -1 && chara != '\n' && flag == 1)
					cntr += _putchar('%');
			}

		}
		chkflag = chkpercent(&flag, chara);
		cntr += chkflag;
		if (chkflag == 0 && chara != '%' && chara != '\0')
			cntr += _putchar(chara), i++;
		chkflag = 0;
	}
	return (cntr);
}


/**
 * chkpercent - print a percentage
 * @flag: is address of an int
 * @chara: is a char
 * Return: is 1 if % was printed, 0 otherwise.
 */
int chkpercent(int *flag, char chara)
{
	int cnt = 0;

	int tmp;

	tmp = *flag;

	if (tmp == 2 && chara == '%')
	{
		cnt = _putchar('%');
		tmp = 0;
	}
	return (cnt);
}


/**
 * funservice - takes arguments and prints it accordingly
 * @chara: is a char or type determinant
 * @arg: is a va_list
 * Return: is the number of characters printed
 */
int funservice(char chara, va_list arg)
{
	int cnt = 0;

	cnt = charswitch(chara, arg);

	return (cnt);
}


/**
 * charswitch - switch character to find arg
 * @arg: is a va_list argument
 * @c: is a char
 * Return: count of printed characters
 */
int charswitch(char a, va_list arg)
{
	int cnt = 0;

	switch (a)
	{
		case 'c':
			cnt += prtcharacter(arg);
			break;
		case 'd':
		case 'i':
			cnt += prtsignInt(arg, 10);
			break;
		case 's':
			cnt += prtstring(arg);
			break;
		case 'x':
			cnt += prtbase16_upper_lower(arg, "0123456789abcdef");
			break;
		case 'X':
			cnt += prtbase16_upper_lower(arg, "0123456789ABCDEF");
			break;
		case 'p':
			cnt += prtaddr(arg);
			break;
		case 'o':
			cnt += prtunsignedInt(arg, 8);
			break;
		case 'u':
			cnt += prtunsignedInt(arg, 10);
			break;
		default:
			cnt = -1;
	}
	return (cnt);
}
