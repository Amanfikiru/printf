#include "main.h"
#include <stdlib.h>
#include <unistd.h>

/**
 * _putchar - writes the character c to
 * standard output
 * @a: the character to print
 *
 * Return: on success 1
 * on error, -1 is returned, and errno is set appropriately
 */

int _putchar(char a)
{
	return (write(1, &a, 1));

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
 * stringlength - returns the length of a string
 * @sl: pointer with the address value
 *
 * Return: void
 */

int stringlength(char *sl)
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
 * @repo: is a representation format 0123456789ABCDEF or 0123456789abcdef
 * @num: unsigned int
 * @b: base representation
 * Return: is a pointer to string
 */

char *frtconverter(char *repo, unsigned int num, int b)
{
	char *str;

	static char buf[128];

	int mode = 0;

	str = &buf[127];

	*str = '\0';

	do {
		mode = num % b;
		*--str = repo[mode];
		num /= b;
	} while (num != 0);
	return (str);
}
