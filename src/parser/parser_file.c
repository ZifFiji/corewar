/*
** EPITECH PROJECT, 2024
** src
** File description:
** parser
*/

#include "my.h"
#include "op.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>

char *get_file(char *file_path)
{
    struct stat s;
    char *file = NULL;
    FILE *stream = fopen(file_path, "r");

    stat(file_path, &s);
    if (s.st_size == 0)
        return NULL;
    file = malloc(sizeof(char) * s.st_size);
    fread(file, 1, s.st_size, stream);
    fclose(stream);
    return file;
}

void get_header(char *file, champions_t *c)
{
    my_strncpy(c->header.prog_name, &file[4], PROG_NAME_LENGTH);
    my_strncpy(c->header.comment, &file[12 + PROG_NAME_LENGTH], COMMENT_LENGTH);
    c->header.prog_size = file[11 + PROG_NAME_LENGTH];
    printf("%s\n", c->header.prog_name);
    printf("%s\n", c->header.comment);
    printf("%d\n", c->header.prog_size);
}

champions_t **parse_files(corewar_t *corewar, input_t **input)
{
    char *file = NULL;
    champions_t **c = NULL;

    if (!corewar || !input)
        return NULL;
    c = init_champion(corewar->nbr_champions);
    for (int i = 0; input[i] != NULL; i ++) {
        file = get_file(input[i]->file_path);
        if (!file)
            return NULL;
        get_header(file, c[i]);
        free(file);
    }
    return 0;
}
