/*
** EPITECH PROJECT, 2025
** my_putnbr
** File description:
** put nb
*/

#include <unistd.h>
#include "../../../include/my.h"

int my_putnbr(int nb)
{
    int count = 0;

    if (nb == -2147483648) {
        write(1, "-2147483648", 11);
        return 11;
    }
    if (nb < 0) {
        write(1, "-", 1);
        count = 1;
        nb = -nb;
    }
    if (nb >= 10) {
        count += my_putnbr(nb / 10);
    }
    my_putchar((nb % 10) + 48);
    count++;
    return count;
}
