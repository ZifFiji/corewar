/*
** EPITECH PROJECT, 2024
** lib
** File description:
** my_char_is_alpha
*/

int my_char_is_alpha(char const c)
{
    if ((c < 'A' || c > 'Z') && (c < 'a' || c > 'z') && c != '_')
        return 1;
    return 0;
}
