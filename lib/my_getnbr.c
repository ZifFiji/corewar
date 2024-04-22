/*
** EPITECH PROJECT, 2023
** my_getnbr
** File description:
** get a nbr
*/

#include <stddef.h>

static
int my_strlen(char const *str)
{
    int len = 0;

    for (; str[len] != '\0'; len ++);
    return len;
}

static
int condition_null(char const *str)
{
    if (str == NULL) {
        return 1;
    }
    return 0;
}

static
int condition_overflow(long nb)
{
    if (nb >= 2147483647 || nb <= -2147483647)
        return 1;
    return 0;
}

static
int condition_neg(char const *str)
{
    int cpt = 0;

    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] == '-')
            cpt += 1;
    }
    if ((cpt % 2) != 0)
            return 1;
    return 0;
}

static
int condition_notdigit(char const *str)
{
    int cpt = 0;

    for (int i = 0; str[i] != '\0'; i += 1) {
        if ((str[i] < '0' || str[i] > '9') &&
            str[i] != '-' && str[i] != '+')
            return cpt;
        cpt ++;
    }
    return 0;
}

int my_getnbr(char *str)
{
    int len = my_strlen(str) + 1;
    long nb = 0;

    if (condition_null(str) == 1)
        return -1;
    if (condition_notdigit(str) != 0)
        len = condition_notdigit(str);
    for (int i = 0; i < len; i += 1) {
        if (condition_overflow(nb) == 1)
            return 0;
        if (str[i] >= '0' && str[i] <= '9') {
            nb *= 10;
            nb += str[i] - 48;
        }
    }
    if (condition_neg(str) == 1)
        nb *= -1;
    return nb;
}
