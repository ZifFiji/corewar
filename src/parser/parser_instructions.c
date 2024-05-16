/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** parser_instructions.c
*/

#include "my.h"
#include "op.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>

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

int get_params(champions_t *c, int count_params, char const *file)
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
    if ((size[i] == '1' && size[i + 1] == '1') ||
    c->instruction[c->nbr_instruction]->instruction - 1 == 10) {
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

void get_type_param(const char *size, champions_t *c)
{
    int j = 0;

    c->nbr_instruction = 0;
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
