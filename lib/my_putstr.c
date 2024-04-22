/*
** EPITECH PROJECT, 2024
** template
** File description:
** my_putstr.c
*/

#include "my.h"
#include <unistd.h>

int my_putstr(char const *str, int n)
{
    if (!str || n > 2 || n < 0)
        return 84;
    if (write(n, str, my_strlen(str)) == -1)
        return 84;
    return 0;
}
