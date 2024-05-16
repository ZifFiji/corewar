/*
** EPITECH PROJECT, 2024
** B-CPE-101-BDX-1-1-myprintf-aaron.groux
** File description:
** printpointer.c
*/

#include "my.h"

#include <stdarg.h>
#include <stdio.h>

int my_printpointer(va_list *list)
{
    long long int ptr = va_arg(*list, long long int);

    my_putpointer(ptr);
    return 0;
}
