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
    file = malloc(sizeof(char) * s.st_size + 1);
    fread(file, 1, s.st_size, stream);
    file[s.st_size] = '\0';
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

int check_mnemonique(uint8_t mnemo)
{
    if (mnemo == 8 || mnemo == 0 || mnemo == 14 || mnemo == 11)
        return ERROR;
    return SUCCESS;
}

char *int_to_bin(size_t num)
{
    char *binary = malloc(sizeof(char) * 9);

    if (binary == NULL)
        return NULL;
    for (int i = 7; i >= 0; --i)
        binary[7 - i] = (num & (1 << i)) ? '1' : '0';
    binary[8] = '\0';
    return binary;
}

int count_params(const char *size)
{
    int j = 0;

    if (size == NULL)
        return 84;
    for (int i = 0; size[i] != '\0'; i += 2) {
        if (size[i] == 0 && size[i + 1] == 0)
            return j;
        if (size[i] == '0' && size[i + 1] == '1')
            j++;
        if (size[i] == '1' && size[i + 1] == '1')
            j++;
        if (size[i] == '1' && size[i + 1] == '0')
            j++;
    }
    return j;
}

int init_params(champions_t *c, int count_params)
{
    if (c == NULL || c->instruction == NULL ||
        c->instruction[c->nbr_instruction] == NULL)
        return 84;
    if (c->instruction[c->nbr_instruction]->parameters)
        free(c->instruction[c->nbr_instruction]->parameters);
    if (c->instruction[c->nbr_instruction]->type)
        free(c->instruction[c->nbr_instruction]->type);
    c->instruction[c->nbr_instruction]->parameters =
            malloc(sizeof(int) * (count_params + 1));
    c->instruction[c->nbr_instruction]->type =
            malloc(sizeof(int) * (count_params + 1));
    for (int i = 0; i != count_params; i++)
        c->instruction[c->nbr_instruction]->parameters[i] = 0;
    return 0;
}

static
void get_instructions_conditions(char *file, champions_t *c, char *params)
{
    if (check_mnemonique(c->instruction[c->nbr_instruction]->\
        instruction - 1) == SUCCESS) {
        c->instruction[c->nbr_instruction]->coding_byte = file[c->idx] & 0xFF;
        params = int_to_bin(c->instruction[c->nbr_instruction]->coding_byte);
        c->instruction[c->nbr_instruction]->nbr_params = count_params(params);
        init_params(c, c->instruction[c->nbr_instruction]->nbr_params);
        c->idx++;
        get_type_param(params, c);
        get_params(c, count_params(params), file);
    } else {
        c->instruction[c->nbr_instruction]->nbr_params = 1;
        init_params(c, c->instruction[c->nbr_instruction]->nbr_params);
        if (c->instruction[c->nbr_instruction]->\
        instruction - 1 == 0)
            write_param_dir(file, c, 0);
        else
            write_param_ind(file, c, 0);
    }
}

static
void get_instructions(char *file, champions_t *c)
{
    char *params = NULL;

    c->instruction = malloc(sizeof(instructions_t *) * 2);
    c->instruction[c->nbr_instruction] = init_instruction();
    while (file[c->idx] != '\0') {
        c->instruction = realloc_instruction_arr(c->instruction, c);
        c->instruction[c->nbr_instruction]->\
        instruction = file[c->idx];
        c->idx++;
        get_instructions_conditions(file, c, params);
        c->nbr_instruction++;
    }
}

static
void get_header(char *file, champions_t *c)
{
    my_strncpy(c->header.prog_name, &file[4], PROG_NAME_LENGTH);
    my_strncpy(c->header.comment,
        &file[12 + PROG_NAME_LENGTH], COMMENT_LENGTH);
    c->header.prog_size = file[11 + PROG_NAME_LENGTH];
}

champions_t **parser_files(corewar_t *corewar, input_t **input)
{
    char *file = NULL;
    champions_t **c = NULL;

    if (!corewar || !input)
        return NULL;
    c = init_champion(corewar->nbr_champions);
    for (int i = 0; input[i] != NULL; i++) {
        file = get_file(input[i]->file_path);
        if (!file)
            return NULL;
        get_header(file, c[i]);
        get_instructions(file, c[i]);
        free(file);
    }
    return c;
}
