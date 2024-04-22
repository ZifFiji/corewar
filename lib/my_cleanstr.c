/*
** EPITECH PROJECT, 2024
** robotfactory
** File description:
** my_cleanstr.c
*/

#include "my.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char *clean_str(char *str)
{
    char *new_str = NULL;
    int len = 0;

    if (!str)
        return NULL;
    while (*str == ' ' || *str == '\t')
        str += 1;
    len = my_strlen(str);
    if (len == -1)
        return NULL;
    new_str = my_strdup(str);
    return new_str;
}

static
int len_tab(char **tab)
{
    int size = 0;

    for (int i = 0; tab[i] != NULL; i++) {
        if (my_strlen(tab[i]) != 0)
            size++;
    }
    return size;
}

char **clean_tab(char **tab)
{
    char **new_tab = malloc(sizeof(char *) * (len_tab(tab) + 1));
    int i = 0;
    int j = 0;

    new_tab[len_tab(tab)] = NULL;
    while (tab[i] != NULL) {
        if (my_strlen(tab[i]) != 0) {
            new_tab[j] = my_strdup(tab[i]);
            j++;
        }
        i++;
    }
    return new_tab;
}
