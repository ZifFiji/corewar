/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** char
*/

#include <stdarg.h>
#include "my.h"

int my_printfchar(va_list *list)
{
    char c = va_arg(*list, int);

    my_putchar(c);
    return 0;
}
