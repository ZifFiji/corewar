/*
** EPITECH PROJECT, 2024
** B-CPE-101-BDX-1-1-myprintf-aaron.groux
** File description:
** printexposant.c
*/

#include "my.h"

#include <stdarg.h>

int my_printexposant(va_list *list)
{
    int sniper = 6;
    double f = va_arg(*list, double);

    my_putexposant(f, sniper);
    return 0;
}
