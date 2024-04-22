/*
** EPITECH PROJECT, 2024
** my_strcat.c
** File description:
** concat two strings
*/

#include <stdlib.h>
#include "my.h"

char *my_strcat(char *dest, char const *str)
{
    int j = 0;
    char *new = NULL;

    if (!dest || !str)
        return NULL;
    new = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(str) + 1));
    for (int i = 0; dest[i] != '\0'; i ++) {
        new[j] = dest[i];
        j ++;
    }
    free(dest);
    for (int i = 0; str[i] != '\0'; i ++) {
        new[j] = str[i];
        j ++;
    }
    new[j] = '\0';
    return new;
}
