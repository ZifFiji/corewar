/*
** EPITECH PROJECT, 2024
** robotfactory
** File description:
** my_show_array.c
*/

#include "my.h"
#include <stddef.h>

int my_show_word_array(char **tab)
{
    if (!tab)
        return 84;
    for (int i = 0; tab[i] != NULL; i++) {
        if (my_putstr(tab[i], 1) == 84)
            return 84;
        my_putstr("\n", 1);
    }
    return 0;
}
