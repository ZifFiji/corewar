/*
** EPITECH PROJECT, 2023
** printx
** File description:
** fonctions
*/

#include "my.h"
#include <stdarg.h>

int my_printmajx(va_list *list)
{
    unsigned int X = va_arg(*list, unsigned int);

    my_put_nbr_basemaj(X, 16);
    return 0;
}
