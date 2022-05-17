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

	cnt = loopfrt(str, arg);

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
	int i = 0, count = 0, flag = 0, chkflag = 0, countf = 0;

	while (i < _stringlength((char *)format) && *(format + i) != '\0')
	{
		char chara = format[i];

		if (chara == '%')
		{
			flag++, i++;
			chara = format[i];
			if (chara == '\0' && _stringlength((char *)format) == 1)
				return (-1);
			if (chara == '\0')
				return (count);
			if (chara == '%')
				flag++;
			else
			{
				countf = fun_service(chara, arg);
				if (countf >= 0 && f_count != -1)
				{
					i++;
					chara = format[i];
					if (chara == '%')
						flag--;
					count += countf;
				}
				else if (countf == -1 && chara != '\n' && flag == 1)
					count += _putchar('%');
			}

		}
		chkflag = chkpercent(&flag, chara);
		count += chkflag;
		if (chkflag == 0 && chara != '%' && chara != '\0')
			count += _putchar(chara), i++;
		chkflag = 0;
	}
	return (count);
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

	return (count);
}


/**
 * charswitch - switch character to find arg
 * @arg: is a va_list argument
 * @a: is a char
 * Return: count of printed characters
 */
int charswitch(char a, va_list arg)
{
	int cnt = 0;

	switch (a)
	{
		case 'c':
			count += print_character(arg);
			break;
		case 'd':
		case 'i':
			count += print_signInt(arg, 10);
			break;
		case 's':
			count += print_string(arg);
			break;
		case 'x':
			count += print_base16_upper_lower(arg, "0123456789abcdef");
			break;
		case 'X':
			count += print_base16_upper_lower(arg, "0123456789ABCDEF");
			break;
		case 'p':
			count += print_addr(arg);
			break;
		case 'o':
			count += print_unsignedInt(arg, 8);
			break;
		case 'u':
			count += print_unsignedInt(arg, 10);
			break;
		default:
			count = -1;
	}
	return (cnt);
}
