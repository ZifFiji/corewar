/*
** EPITECH PROJECT, 2023
** my_put_nbr_base
** File description:
** ez
*/

#include "my.h"
#include <stdio.h>

static char make_hexa(int nb)
{
    if (nb == 10)
        return 'a';
    if (nb == 11)
        return 'b';
    if (nb == 12)
        return 'c';
    if (nb == 13)
        return 'd';
    if (nb == 14)
        return 'e';
    if (nb == 15)
        return 'f';
}

int my_put_nbr_base(long long int nb, int base)
{
    if (nb < 0)
        return -1;
    if (nb >= base)
        my_put_nbr_base(nb / base, base);
    if (nb % base >= 10 && base == 16)
        my_putchar(make_hexa(nb % base));
    if (nb % base < 10)
        my_putchar((nb % base) + '0');
    return 0;
}
