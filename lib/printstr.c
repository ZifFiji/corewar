/*
** EPITECH PROJECT, 2023
** printstr
** File description:
** fonction flag str
*/
#include <stdarg.h>
#include "my.h"

int my_printstr(va_list *list)
{
    int a = 0;
    char *str = va_arg(*list, char *);

    my_putstr(str, 1);
    return 0;
}
