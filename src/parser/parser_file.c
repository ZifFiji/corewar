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

int write_param_reg(const char *file, champions_t *c, int j)
{
    c->instruction[c->nbr_instruction]->\
    parameters[j] = file[c->idx];
    c->idx += 1;
    return 0;
}

int write_param_dir(const char *file, champions_t *c, int j)
{
    c->instruction[c->nbr_instruction]->\
    parameters[j] += (file[c->idx] & 0x000000FF) << 24;
    c->instruction[c->nbr_instruction]->\
    parameters[j] += (file[c->idx + 1] & 0x000000FF) << 16;
    c->instruction[c->nbr_instruction]->\
    parameters[j] += (file[c->idx + 2] & 0x000000FF) << 8;
    c->instruction[c->nbr_instruction]->\
    parameters[j] += (file[c->idx + 3] & 0x000000FF) << 0;
    c->idx += 4;
    return 0;
}

int write_param_ind(const char *file, champions_t *c, int j)
{
    c->instruction[c->nbr_instruction]->\
    parameters[j] += (file[c->idx] & 0x000000FF) << 8;
    c->instruction[c->nbr_instruction]->\
    parameters[j] += (file[c->idx + 1] & 0x000000FF) << 0;
    c->idx += 2;
    return 0;
}

int get_params(champions_t *c, int count_params , char const *file)
{
    int j = 0;

    for (int i = 0; i != count_params; i++) {
        if (c->instruction[c->nbr_instruction]->type[i] == T_REG) {
            write_param_reg(file, c, j);
            j++;
        }
        if (c->instruction[c->nbr_instruction]->type[i] == T_DIR) {
            write_param_dir(file, c, j);
            j++;
        }
        if (c->instruction[c->nbr_instruction]->type[i] == T_IND) {
            write_param_ind(file, c, j);
            j++;
        }
    }
    return 0;
}

static
int get_type_ind(const char *size, champions_t *c, int j, int i)
{
    if ((size[i] == '1' && size[i + 1] == '1') || my_strcmp
    (c->instruction[c->nbr_instruction]->instruction, "sti") == 0) {
        c->instruction[c->nbr_instruction]->type[j] = T_IND;
        return 0;
    }
    return 84;
}

static
int get_type_dir(const char *size, champions_t *c, int j, int i)
{
    if (size[i] == '1' && size[i + 1] == '0') {
        c->instruction[c->nbr_instruction]->type[j] = T_DIR;
        return 0;
    }
    return 84;
}

static
int get_type_reg(const char *size, champions_t *c, int j, int i)
{
    if (size[i] == '0' && size[i + 1] == '1') {
        c->instruction[c->nbr_instruction]->type[j] = T_REG;
        return 0;
    }
    return 84;
}

static
void get_type_param(const char *size, champions_t *c)
{
    int j = 0;

    if (size == NULL || c == NULL || c->instruction == NULL)
        return;
    for (int i = 0; size[i] != '\0'; i += 2) {
        if (size[i] == 0 && size[i + 1] == 0)
            return;
        if (get_type_reg(size, c, j, i) == 0) {
            j++;
            continue;
        }
        if (get_type_ind(size, c, j, i) == 0) {
            j++;
            continue;
        }
        if (get_type_dir(size, c, j, i) == 0) {
            j++;
            continue;
        }
    }
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

static
int init_params(champions_t *c, int count_params)
{
    if (c == NULL || c->instruction == NULL ||
    c->instruction[c->nbr_instruction] == NULL)
        return 84;
    c->instruction[c->nbr_instruction]->parameters =
            malloc(sizeof(int) * (count_params + 1));
    c->instruction[c->nbr_instruction]->type =
            malloc(sizeof(int) * (count_params + 1));
    if (c->instruction[c->nbr_instruction]->parameters != NULL ||
    c->instruction[c->nbr_instruction]->type != NULL)
        return 84;
    return 0;
}

static
void get_instructions(char *file, champions_t *c)
{
    char *params = NULL;
    int count_param = 0;

    c->instruction = malloc(sizeof(instructions_t *) * 2);
    c->instruction[c->nbr_instruction] = init_instruction();
    while (file[c->idx] != '\0') {
//        printf("idx : %d, file[idx] : %d\n",c->idx, file[c->idx]);
        c->instruction = realloc_instruction_arr(c->instruction, c);
        c->instruction[c->nbr_instruction]->\
        instruction = my_strdup(op_tab[file[c->idx] - 1].mnemonique);
        c->idx++;
        if (check_mnemonique(c->instruction[c->nbr_instruction]->\
        instruction) == SUCCESS) {
            c->instruction[c->nbr_instruction]->coding_byte = file[c->idx];
            params = int_to_bin(c->instruction[c->nbr_instruction]->coding_byte);
            count_param = count_params(params);
            init_params(c, count_param);
//            printf("params : %s, count : %d\n", params, count_param);
            c->idx++;
            get_type_param(params, c);
            get_params(c, count_params(params), file);
        } else {
            count_param = 1;
            init_params(c, count_param);
            if (my_strcmp(c->instruction[c->nbr_instruction]->\
            instruction, "live") == 0)
                write_param_dir(file, c, 0);
            else
                write_param_ind(file, c, 0);
        }
//        printf("instruction : %s\n", c->instruction[c->nbr_instruction]->instruction);
//        for (int i = 0; i != count_param; i++)
//            printf("parameters : %x\n", c->instruction[c->nbr_instruction]->parameters[i]);
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
