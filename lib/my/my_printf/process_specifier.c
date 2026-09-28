/*
** EPITECH PROJECT, 2025
** process file
** File description:
** proceed
*/

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "../../../include/my.h"

int process_specifier_simple(char specifier, va_list ap, int count)
{
    if (specifier == 'c'){
        my_putchar((char)va_arg(ap, int));
        count += 1;
    }
    if (specifier == 'i' || specifier == 'd')
        count += my_putnbr(va_arg(ap, int));
    if (specifier == 'u')
        count += my_putnbr_unsigned(va_arg(ap, unsigned int));
    if (specifier == 's')
        count += my_putstr(va_arg(ap, char *));
    if (specifier == '%'){
        my_putchar('%');
        count += 1;
    }
    if (specifier == 'n')
        my_putnbr(count);
    count += process_specifier_complex(specifier, ap, count);
    return count;
}

int process_specifier_complex(char specifier, va_list ap, int count)
{
    if (specifier == 'o')
        count += my_putnbr_octal(va_arg(ap, unsigned int));
    if (specifier == 'p')
        count += my_put_pointer(va_arg(ap, char*));
    if (specifier == 'x')
        count += my_putnbr_hex_lower(va_arg(ap, unsigned int));
    if (specifier == 'X')
        count += my_putnbr_hex_upper(va_arg(ap, unsigned int));
    if (specifier == 'f' || specifier == 'F')
        count += my_put_float(va_arg(ap, double));
    return count;
}
