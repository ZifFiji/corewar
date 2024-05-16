/*
** EPITECH PROJECT, 2023
** putnbrbase
** File description:
** fonctions
*/

#include "my.h"
#include <stdio.h>
#include <unistd.h>

static char make_hexa(int nb)
{
    if (nb == 10)
        return 'A';
    if (nb == 11)
        return 'B';
    if (nb == 12)
        return 'C';
    if (nb == 13)
        return 'D';
    if (nb == 14)
        return 'E';
    if (nb == 15)
        return 'F';
}

int my_put_nbr_basemaj(long long int nb, int base)
{
    if (nb < 0)
        return -1;
    if (nb >= 10)
        my_put_nbr_basemaj(nb / base, base);
    if (nb % base >= 10)
        my_putchar(make_hexa(nb % base));
    if (nb % base < 10)
        my_putchar((nb % base) + '0');
    return 0;
}
