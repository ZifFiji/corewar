/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** display
*/

#include "my_constent.h"
#include <stddef.h>
#include <stdarg.h>
#include "my.h"
#include <stdio.h>

const display_t *display_flags(char c, va_list list)
{
    for (int i = 0; display_array[i].ptr != NULL; i++)
        if (c == display_array[i].flag)
            return &display_array[i];
}

int check_flags(char str, char str2)
{
    int i = 0;

    if (str != '%')
        return 1;
    while (all_flags[i] != '\0') {
        if (all_flags[i] == str2)
            return 0;
        i++;
    }
    return 2;
}

int my_printf(const char *format, ...)
{
    va_list list;

    va_start(list, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (check_flags(format[i], format[i + 1]) == 0) {
            display_flags(format[i + 1], list)->ptr(&list);
            i += 1;
        }
        if (format[i - 1] != '%') {
            my_putchar(format[i]);
        }
    }
    return 0;
}
