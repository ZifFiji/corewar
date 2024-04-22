/*
** EPITECH PROJECT, 2024
** lib
** File description:
** my_isdigit
*/

int my_isdigit(char c)
{
    if ((c >= '0' && c <= '9'))
        return 1;
    return 0;
}
