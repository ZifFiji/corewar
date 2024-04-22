/*
** EPITECH PROJECT, 2024
** lib
** File description:
** my_is_alphanum
*/

#include "my.h"

int my_str_isaphanum(char const *str)
{
    if (!str)
        return 84;
    for (int i = 0; str[i] != '\0'; i ++) {
        if (my_char_is_alpha(str[i]) == 1 && my_isdigit(str[i]) == 0)
            return 1;
    }
    return 0;
}
