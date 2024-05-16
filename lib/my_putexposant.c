/*
** EPITECH PROJECT, 2024
** B-CPE-101-BDX-1-1-myprintf-aaron.groux
** File description:
** my_putexposant.c
*/

#include "my.h"
#include <stdio.h>

int put_negative_exposant(double e)
{
    int len = 0;

    my_putchar('-');
    len = my_intlen_float(e);
    if (len < 10)
        my_put_nbr(0);
    my_put_nbr(len);
    return 0;
}

int put_postive_exposant(double e)
{
    int len = 0;

    my_putchar('+');
    len = my_intlen((long)e) - 1;
    if (len < 10)
        my_put_nbr(0);
    my_put_nbr(len);
    return 0;
}

int my_putexposant(double e, int precision)
{
    double tmp = e;

    if (e < 0)
        e *= -1;
    if (e < 1) {
        while (e < 1)
            e *= 10;
    } else {
        while (e > 10)
            e /= 10;
    }
    my_putfloat(e, precision);
    my_putstr("e", 1);
    if (tmp < 1) {
        put_negative_exposant(tmp);
    } else {
        put_postive_exposant(tmp);
    }
    return 0;
}
