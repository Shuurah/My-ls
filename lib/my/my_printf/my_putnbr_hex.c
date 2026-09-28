/*
** EPITECH PROJECT, 2025
** hexa
** File description:
** hexadecimal
*/

#include "../../../include/my.h"

int my_putnbr_hex_lower(unsigned long nb)
{
    int count = 0;
    char *base = "0123456789abcdef";

    if (nb >= 16)
        count += my_putnbr_hex_lower(nb / 16);
    my_putchar(base[nb % 16]);
    count++;
    return count;
}

int my_putnbr_hex_upper(unsigned long nb)
{
    int count = 0;
    char *base = "0123456789ABCDEF";

    if (nb >= 16)
        count += my_putnbr_hex_upper(nb / 16);
    my_putchar(base[nb % 16]);
    count++;
    return count;
}
