/*
** EPITECH PROJECT, 2023
** float
** File description:
** fonction for float
*/

#include <stdarg.h>
#include "my.h"

int my_printfloat(va_list *list)
{
    int sniper = 6;
    double f = va_arg(*list, double);

    my_putfloat(f, sniper);
    return 0;
}
