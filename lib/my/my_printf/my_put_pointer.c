/*
** EPITECH PROJECT, 2025
** pointer
** File description:
** pointer
*/

#include "../../../include/my.h"

int my_put_pointer(char *ptr)
{
    char *addr = ptr;
    int count = 0;

    my_putchar('0');
    my_putchar('x');
    count += 2;
    if (addr == 0) {
        my_putchar('0');
        return count + 1;
    }
    count += my_putnbr_hex_lower((unsigned long)addr);
    return count;
}
