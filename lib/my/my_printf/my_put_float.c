/*
** EPITECH PROJECT, 2025
** put float
** File description:
** float
*/

#include "../../../include/my.h"

int my_put_float(double nb)
{
    int part_int = (int)nb;
    int part_float = (int)((nb - part_int) * 1000000 + 0.5);
    int count = 0;

    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
        count++;
    }
    part_int = (int)nb;
    part_float = (int)((nb - part_int) * 1000000 + 0.5);
    count += my_putnbr_unsigned(part_int);
    my_putchar('.');
    my_compute_float(part_int, part_float, count);
    count++;
    return (count);
}

int my_compute_float(int part_int, int part_float, int count)
{
    int digit;
    int buff = 100000;

    for (int i = 0; i < 6; i++) {
        digit = part_float / buff;
        my_putnbr_unsigned(digit);
        part_float = part_float % buff;
        buff = buff / 10;
        count++;
    }
    return (count);
}
