/*
** EPITECH PROJECT, 2023
** printint
** File description:
** my.h
*/
#include <stdarg.h>
#include "my.h"

int my_printint(va_list *list)
{
    int Hassoul = va_arg(*list, int);

    my_put_nbr(Hassoul);
    return 0;
}
