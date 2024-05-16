/*
** EPITECH PROJECT, 2023
** my_printo
** File description:
** fonctions
*/
#include <stdarg.h>
#include "my.h"

int my_printo(va_list *list)
{
    unsigned int o = va_arg(*list, unsigned int);
    int a = 0;

    my_put_nbr_base(o, 8);
    return 0;
}
