#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>
#include <stdarg.h>

int my_putchar(char c);
int _printf(const char *format, ...);
size_t _strlen(const char *str);
int process_format_specifier(char format, va_list args, int count);
int process_format(const char *format, va_list args);
int print_char(char c);
int print_string(const char *str);
int print_int(va_list args);
int print_unsigned(va_list args);
int print_bin(va_list args);
int print_octal(va_list args);
int print_hexa(va_list args);
int print_hex(va_list args);
int custom_string(va_list args);
int print_hex_helper(unsigned int num);

#endif
