#include "main.h"
#include <string.h>

/**
 * _printf - entry point
 * @format: char
 * Return: 0
 */

int _printf(const char *format, ...)
{
        va_list args;
        int count;

        va_start(args, format);

        if (format == NULL || (format[0] == '%' && format[1] == '\0'))
                return (-1);

        if (strcmp(format, "% ") == 0 || strcmp(format, "%") == 0)
                return (-1);

        count = process_format(format, args);

        va_end(args);
        return (count);
}

