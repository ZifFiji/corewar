/*
** EPITECH PROJECT, 2023
** my_getbuf.c
** File description:
** my_getbuf.c
*/

#include <stdio.h>
#include <stdlib.h>

static int copy_string(char *str, char const *to_copy, int i)
{
    if (!str || !to_copy)
        return -1;
    for (int j = 0; to_copy[j] != '\0'; j ++) {
        str[i] = to_copy[j];
        i ++;
    }
    return i;
}

static int get_len(char const *file)
{
    FILE *stream = NULL;
    char *buffer = NULL;
    size_t size = 0;
    ssize_t read = 0;
    size_t len = 0;

    if (!file)
        return -1;
    stream = fopen(file, "r");
    read = getline(&buffer, &size, stream);
    while (read != -1) {
        len += read;
        read = getline(&buffer, &size, stream);
    }
    fclose(stream);
    return (int) len;
}

char *my_getbuff(char const *file)
{
    FILE *stream = NULL;
    char *temp = NULL;
    char *buffer = NULL;
    size_t size = 0;
    ssize_t read = 0;

    if (!file)
        return NULL;
    stream = fopen(file, "r");
    if (stream == NULL || get_len(file) == 0)
        return NULL;
    buffer = malloc(sizeof(char) * (get_len(file) + 1));
    read = getline(&temp, &size, stream);
    for (int i = 0; read != -1;) {
        i = copy_string(buffer, temp, i);
        read = getline(&temp, &size, stream);
        buffer[i] = '\0';
    }
    fclose(stream);
    return buffer;
}
