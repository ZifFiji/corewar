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

char *int_to_bin(int num)
{
    char *binary = malloc(sizeof(char) * 9);

    if (binary == NULL)
        return NULL;
    for (int i = 7; i >= 0; --i)
        binary[7 - i] = (num & (1 << i)) ? '1' : '0';
    binary[8] = '\0';
    return binary;
}

int write_param_reg(char *file, champions_t *c, int j)
{
    c->instruction[c->nbr_instruction]->\
    parameters[j] = my_strndup(file, T_REG);
    c->idx += T_REG;
    return 0;
}

int write_param_dir(char *file, champions_t *c, int j)
{
    c->instruction[c->nbr_instruction]->\
    parameters[j] = my_strndup(file, T_DIR);
    c->idx += T_DIR;
    return 0;
}

int write_param_ind(char *file, champions_t *c, int j)
{
    c->instruction[c->nbr_instruction]->\
    parameters[j] = my_strndup(file, T_IND);
    c->idx += T_IND;
    return 0;
}

static
int get_param(char *file, const char *size, champions_t *c)
{
    int j = 0;

    if (size == NULL || c == NULL || c->instruction == NULL)
        return 84;
    for (int i = 0; size[i] != '\0'; i += 2) {
        if (size[i] == 0 && size[i + 1] == 0)
            return 0;
        if (size[i] == '0' && size[i + 1] == '1') {
            write_param_reg(file, c, j);
            j++;
        }
        if (size[i] == '1' && size[i + 1] == '1') {
            write_param_ind(file, c, j);
            j++;
        }
        if (size[i] == '1' && size[i + 1] == '0') {
            write_param_dir(file, c, j);
            j++;
        }
    }
    return 0;
}

static
int get_instructions(char *file, champions_t *c)
{
    char *params = NULL;

    c->instruction = malloc(sizeof(instructions_t *) * 2);
    c->instruction[c->nbr_instruction] = init_instruction();
    while (file[c->idx]) {
        c->instruction = realloc_instruction_arr(c->instruction, c);
        if (check_mnemonique(c->instruction[c->nbr_instruction]->\
        instruction) == SUCCESS) {
            c->instruction[c->nbr_instruction]->coding_byte = file[c->idx];
            c->idx++;
        }
        params = int_to_bin(file[c->idx]);
        printf("params : %s\n", params);
        if (get_param(file, params, c) == 84)
            return 84;
        c->nbr_instruction++;
        printf("instruction : %s, size : %s\n", c->instruction[c->nbr_instruction - 1]->instruction, params);
    }
    return coding_byte;
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
