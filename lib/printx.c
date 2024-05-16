/*
** EPITECH PROJECT, 2023
** printx
** File description:
** fonctions
*/

#include <stdarg.h>

#include "my.h"

int my_printx(va_list *list)
{
    unsigned int x = va_arg(*list, unsigned int);

    my_put_nbr_base(x, 16);
    return 0;
}
