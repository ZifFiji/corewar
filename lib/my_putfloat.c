/*
** EPITECH PROJECT, 2023
** my_putfloat
** File description:
** ez
*/

#include "my.h"

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

int my_putfloat(double f, int precision)
{
    int i = (int)f;

    my_put_nbr(i);
    f = f - i;
    my_putchar('.');
    if (f < 0)
        f = f * -1;
    while (precision > 0) {
        f = f * 10;
        i = (int)f;
        if (precision == 1 && f - i >= 0.5)
            i++;
        my_put_nbr(i);
        f = f - i;
        precision--;
    }
    return 0;
}
