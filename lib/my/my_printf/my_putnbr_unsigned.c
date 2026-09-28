/*
** EPITECH PROJECT, 2025
** my_putnbr_unsigned
** File description:
** put nb
*/

#include "../../../include/my.h"

int my_putnbr_unsigned(unsigned int nb)
{
    int count = 0;

    if (nb >= 10) {
        count += my_putnbr_unsigned(nb / 10);
    }
    my_putchar((nb % 10) + 48);
    count++;
    return count;
}
