/*
** EPITECH PROJECT, 2024
** template
** File description:
** my_strlen.c
*/

#include <stddef.h>

int my_strlen(char const *str)
{
    int len = 0;

    if (!str)
        return -1;
    for (; str[len] != '\0'; len ++);
    return len;
}

int len_tab(char **tab)
{
    int len = 0;

    if (!tab)
        return -1;
    for (int i = 0; tab[i] != NULL; i++)
        len++;
    return len;
}

int my_intlen(long int nb)
{
    int len = 0;

    while (nb > 0) {
        nb = nb / 10;
        len++;
    }
    return len;
}

int my_intlen_float(double nb)
{
    int count = 0;

    while (nb < 1.0) {
        nb = nb * 10.0;
        count++;
    }
    return count;
}