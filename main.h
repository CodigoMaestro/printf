#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>
#include <stdarg.h>

int my_putchar(char c);
int _printf(const char *format, ...);
size_t _strlen(const char *str);
int process_format_specifier(char format, va_list args, int count);
int process_format(const char *format, va_list args);

#endif
