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

static
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

static
instructions_t **realloc_instruction_arr(instructions_t **i, champions_t *c)
{
    if (c->nbr_instruction > 0) {
        i = realloc(i, sizeof(instructions_t *) * (c->nbr_instruction + 2));
        if (!i)
            return NULL;
        i[c->nbr_instruction] = init_instruction();
        i[c->nbr_instruction + 1] = NULL;
    }
    return i;
}

static
int check_mnemonique(char *mnemo)
{
    if (my_strcmp(mnemo, "zjmp") == 0 ||
        my_strcmp(mnemo, "live") == 0 ||
        my_strcmp(mnemo, "lfork") == 0 ||
        my_strcmp(mnemo, "fork") == 0)
        return ERROR;
    return SUCCESS;
}

static
void get_instructions(char *file, champions_t *c)
{
    int idx = PROG_NAME_LENGTH + COMMENT_LENGTH + 16;

    c->instruction = malloc(sizeof(instructions_t *) * 2);
    c->instruction[c->nbr_instruction] = init_instruction();
    // while (file[idx]) {
        c->instruction = realloc_instruction_arr(c->instruction, c);
        c->instruction[c->nbr_instruction]->\
        instruction = my_strdup(op_tab[file[idx] - 1].mnemonique);
        idx++;
        if (check_mnemonique(c->instruction[c->nbr_instruction]->\
        instruction) == SUCCESS) {
            c->instruction[c->nbr_instruction]->coding_byte = file[idx];
            idx++;
        }
        c->nbr_instruction++;
    // }
    printf("%s\n", c->instruction[c->nbr_instruction - 1]->instruction);
    printf("%x\n", c->instruction[c->nbr_instruction - 1]->coding_byte);
}

static
void get_header(char *file, champions_t *c)
{
    my_strncpy(c->header.prog_name, &file[4], PROG_NAME_LENGTH);
    my_strncpy(c->header.comment,
        &file[12 + PROG_NAME_LENGTH], COMMENT_LENGTH);
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
        get_instructions(file, c[i]);
        free(file);
    }
    return c;
}
