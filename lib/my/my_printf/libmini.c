/*
** EPITECH PROJECT, 2025
** lib
** File description:
** libmini
*/

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "../../../include/my.h"

int my_putnbr_long(long int nb)
{
    int count = 0;
    long int temp = nb;

    if (nb < 0) {
        my_putchar('-');
        count++;
        nb = -nb;
    }
    temp = nb;
    if (temp == 0){
        my_putchar('0');
        return count + 1;
    }
    if (nb >= 10)
        count += my_putnbr_long(nb / 10);
    my_putchar((nb % 10) + '0');
    count++;
    return count;
}
