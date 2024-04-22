/*
** EPITECH PROJECT, 2024
** robotfactory
** File description:
** my_strdup.c
*/

#include <stdlib.h>
#include "my.h"
#include <stddef.h>

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    if (dest == NULL || src == NULL)
        return NULL;
    for (; src[i] != '\0'; i += 1) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return (dest);
}

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    if (dest == NULL || src == NULL)
        return NULL;
    while (i != n) {
        dest[i] = src[i];
        i += 1;
    }
    dest[n] = '\0';
    return (dest);
}

char *my_strndup(char const *src, int n)
{
    char *str = NULL;

    str = malloc(sizeof(char) * n + 1);
    my_strncpy(str, src, n);
    return str;
}

char *my_strdup(char const *src)
{
    char *str = NULL;

    str = malloc(sizeof(char) * (my_strlen(src) + 1));
    my_strcpy(str, src);
    return (str);
}
