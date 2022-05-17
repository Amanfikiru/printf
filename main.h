#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>

int _printf(const char *format, ...);
int loopfrt(const char *format, va_list arg);
int chkpercent(int *flag, char chara);
int funservice(char chara, va_list arg);
int charswitch(char a, va_list arg);
int prt_character(va_list arg);
int prt_signInt(va_list arg, int b);
int prt_unsignedInt(va_list arg, int b);
int prt_base16_upper_lower(va_list arg, char *repo);
int prt_addr(va_list arg);
int prt_string(va_list arg);
int _putchar(char a);
void _puts(char *str);
int stringlength(char *sl);
char *converttoformat(char *repo, unsigned int num, int b);

#endif
