/*
** EPITECH PROJECT, 2023
** my_str_to_word_array
** File description:
** splits a string into words
*/

#include <stddef.h>
#include <stdlib.h>

static
int my_strlen(char const *str)
{
    int cpt = 0;

    while (str[cpt] != '\0')
        cpt += 1;
    return (cpt);
}

static
char *my_strndup(char const *src, int i)
{
    char *dup;

    dup = malloc(sizeof(char) * (i + 1));
    for (int j = 0; src[j] != '\0' && j < i; j ++) {
        dup[j] = src[j];
    }
    dup[i] = '\0';
    return dup;
}

static
int is_separator(char c, char **separator)
{
    for (int i = 0; separator[i] != NULL; i ++) {
        if (separator[i][0] == c) {
            return 1;
        }
    }
    return 0;
}

static
int remove_space(char const *str, char **separator, int i)
{
    for (; str[i] != '\0'; i ++) {
        if (is_separator(str[i], separator) == 0)
            break;
    }
    return i;
}

static
int count_word(char const *str, char **separator)
{
    int cpt = 0;

    for (int i = 0; str[i + 1] != '\0'; i ++) {
        if (is_separator(str[i], separator) == 1) {
            i = remove_space(str, separator, i);
            cpt += 1;
        }
    }
    cpt += 1;
    return cpt;
}

char **my_str_to_word_array(char const *str, char **separator)
{
    int cpt = 0;
    int j = 0;
    int i = 0;
    int idx = 0;
    char **list = malloc(sizeof(char *) * (count_word(str, separator) + 1));
    int len = my_strlen(str) + 1;

    for (i = 0; i < len; i++) {
        if (is_separator(str[i], separator) || str[i] == '\0') {
            list[j] = my_strndup(&str[idx], cpt);
            i = remove_space(str, separator, i);
            idx = i;
            j += 1;
            cpt = 0;
        }
        cpt += 1;
    }
    list[j] = NULL;
    return list;
}
