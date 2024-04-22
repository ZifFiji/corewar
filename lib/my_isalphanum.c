/*
** EPITECH PROJECT, 2024
** lib
** File description:
** my_isalphanum
*/

#include "my.h"

int my_isalphanum(char c)
{
    if (!c)
        return 1;
    if (my_char_is_alpha(c) == 0 && my_isdigit(c) == 0)
        return 0;
    return 1;
}
