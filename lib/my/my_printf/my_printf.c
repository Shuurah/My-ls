/*
** EPITECH PROJECT, 2025
** miniprintf
** File description:
** header
*/

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "../../../include/my.h"

int loop_while_my_printf(const char *format, int *i, va_list ap)
{
    int count = 0;

    if (format[*i] == '%') {
        (*i)++;
        count += loopcheck(&format[*i], i, ap, count);
        (*i)++;
    } else if (format[0] == '\0')
        return 0;
    else {
        my_putchar(format[*i]);
        count += 1;
        (*i)++;
    }
    return count;
}

int my_printf(const char *format, ...)
{
    int i = 0;
    int count = 0;
    va_list ap;
    int err;

    va_start(ap, format);
    while (format[i] != '\0'){
        err = loop_while_my_printf(format, &i, ap);
        if (err == -1 || err == 0) {
            va_end(ap);
            return err;
        }
        count += err;
    }
    va_end(ap);
    return (count);
}
