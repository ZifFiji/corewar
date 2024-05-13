/*
** EPITECH PROJECT, 2024
** lib
** File description:
** my_put_nbr_base
*/

#include "my.h"

#include <unistd.h>

int count_digit(int nb, int *count)
{
    while (nb > 0) {
        *count += 1;
        nb = nb / 10;
    }
    return *count;
}

int my_put_nbr_base(int nb, const char *base)
{
    int len = my_strlen(base);
    int count = 0;

    if (nb == 0)
        return 0;
    my_put_nbr_base((nb / len), base);
    my_putchar(base[0 + (nb % len)]);
    count = count_digit(nb , &count);
    return count;
}
