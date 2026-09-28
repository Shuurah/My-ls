/*
** EPITECH PROJECT, 2025
** my_putstr
** File description:
** put str
*/

#include <unistd.h>
#include "../../../include/my.h"

int my_putstr(char const *str)
{
    int count = 0;

    if (str == NULL) {
        write(1, "(null)", 6);
        return (6);
    }
    while (*str != '\0'){
        my_putchar(*str);
        str++;
        count++;
    }
    return (count);
}
