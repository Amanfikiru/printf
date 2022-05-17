#include "main.h"
#include <stdarg.h>

/**
 * _printf - function produces output according to a format.
 * @format: is a pointer to string
 * Return: is the count of printed characters
 */
int _printf(const char *format, ...)
{
	const char *string;

	int count = 0;

	va_list args;

	if (!format)
		return (-1);

	va_start(args, format);
	string = format;

	count = loop_format(string, args);

	va_end(args);

	return (count);
}

/**
 * loop_format - function is to print format
 * @format: is a pointer to string
 * @args: is a va_list args
 * Return: is an integer.
 */
int loop_format(const char *format, va_list args)
{
	int i = 0, counter = 0, flag = 0, check_flag = 0, f_counter = 0;

	while (i < _strlen((char *)format) && *(format + i) != '\0')
	{
		char charac = format[i];

		if (charac == '%')
		{
			flag++, i++;
			charac = format[i];
			if (charac == '\0' && _strlen((char *)format) == 1)
				return (-1);
			if (charac == '\0')
				return (counter);
			if (charac == '%')
				flag++;
			else
			{
				f_counter = func_service(charac, args);
				if (f_counter >= 0 && f_counter != -1)
				{
					i++;
					charac = format[i];
					if (charac == '%')
						flag--;
					counter += f_counter;
				}
				else if (f_counter == -1 && charac != '\n' && flag == 1)
					counter += _putchar('%');
			}

		}
		check_flag = check_percent(&flag, charac);
		counter += check_flag;
		if (check_flag == 0 && charac != '%' && charac != '\0')
			counter += _putchar(charac), i++;
		check_flag = 0;
	}
	return (counter);
}


/**
 * check_percent - print a percentage
 * @flag: is address of an int
 * @charac: is a char
 * Return: is 1 if % was printed, 0 otherwise.
 */
int check_percent(int *flag, char charac)
{
	int count = 0;

	int tmp;

	tmp = *flag;

	if (tmp == 2 && charac == '%')
	{
		count = _putchar('%');
		tmp = 0;
	}
	return (count);
}


/**
 * func_service - takes arguments and prints it accordingly
 * @charac: is a char or type determinant
 * @args: is a va_list
 * Return: is the number of characters printed
 */
int func_service(char charac, va_list args)
{
	int count = 0;

	count = _switch(charac, args);

	return (count);
}


/**
 * _switch - switch character to find arg
 * @arg: is a va_list argument
 * @c: is a char
 * Return: count of printed characters
 */
int _switch(char c, va_list arg)
{
	int count = 0;

	switch (c)
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
	return (count);
}
/**
 * _putchar - writes the character c to
 * standard output
 * @c: the character to print
 *
 * Return: on success 1
 * on error, -1 is returned, and errno is set appropriately
 */

int _putchar(char c)
{
	return (write(1, &c, 1));

}

/**
 * _puts - prints a string to standard output
 * @str: pointer to address value
 *
 * Return: void
 */

void _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
}

/**
 * _strlen - returns the length of a string
 * @s: pointer with the address value
 *
 * Return: void
 */

int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		;
	}
	return (i);
}

/**
 * convert_to_format - convert from a format to another
 * @rep: is a representation format 0123456789ABCDEF or 0123456789abcdef
 * @number: unsigned int
 * @base: base representation
 * Return: is a pointer to string
 */

char *convert_to_format(char *rep, unsigned int number, int base)
{
	char *str;

	static char buffer[128];

	int mod = 0;

	str = &buffer[127];

	*str = '\0';

	do {
		mod = number % base;
		*--str = rep[mod];
		number /= base;
	} while (number != 0);
	return (str);
}
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
