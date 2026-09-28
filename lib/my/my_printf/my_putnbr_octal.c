/*
** EPITECH PROJECT, 2025
** octal
** File description:
** octal
*/

#include "../../../include/my.h"

int my_putnbr_octal(unsigned int nb)
{
    int count = 0;

    if (nb >= 8)
        count += my_putnbr_octal(nb / 8);
    my_putchar((nb % 8) + '0');
    count++;
    return count;
}
