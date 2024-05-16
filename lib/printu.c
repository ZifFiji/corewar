/*
** EPITECH PROJECT, 2023
** Printu
** File description:
** fonctions
*/

#include <stdarg.h>
#include "my.h"

int my_printu(va_list *list)
{
    unsigned int u = va_arg(*list, unsigned int);

    my_put_nbr_base(u, 10);
    return 0;
}
