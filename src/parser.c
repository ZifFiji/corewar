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

char *return_file(char *file_path)
{
    struct stat s;
    char *file = NULL;
    FILE *stream = fopen(file_path, "r");

    stat(file_path, &s);
    file = malloc(sizeof(char) * s.st_size);
    fread(file, 1, s.st_size, stream);
    fclose(stream);
    return file;
}

int parser(char *file_path)
{
    char *file = 0;
    char name[PROG_NAME_LENGTH + 1];
    char comment[COMMENT_LENGTH + 1];
    int prog_size = 0;

    file = return_file(file_path);
    strncpy(name, &file[4], PROG_NAME_LENGTH);
    strncpy(comment, &file[12 + PROG_NAME_LENGTH], COMMENT_LENGTH);
    prog_size = file[11 + PROG_NAME_LENGTH];
    printf("%s\n%s\n%d\n", name, comment, prog_size);
    return 0;
}
