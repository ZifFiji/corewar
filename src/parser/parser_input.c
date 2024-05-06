/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** parser_input
*/

#include "my.h"

#include <stdlib.h>

static
int check_nbr_cycles(char *nbr_cycles)
{
    if (!nbr_cycles)
        return ERROR;
    for (int i = 0; nbr_cycles[i] != '\0'; i ++)
        if (my_isdigit(nbr_cycles[i]) == 0)
            return ERROR;
    return SUCCESS;
}

static
int handle_flags(char **raw_input, int *idx, input_t **input, corewar_t *c)
{
    if (my_strcmp(raw_input[(*idx)], "-dump") == 0)
        return ERROR;
    if (my_strcmp(raw_input[(*idx)], "-n") == 0) {
        if (check_nbr_cycles(raw_input[++(*idx)]) == ERROR)
            return ERROR;
        else
            input[c->nbr_champions]->prog_number = my_getnbr(raw_input[(*idx)++]); 
    }
    if (my_strcmp(raw_input[(*idx)], "-a") == 0) {
        if (check_nbr_cycles(raw_input[++(*idx)]) == ERROR)
            return ERROR;
        else
            input[c->nbr_champions - 1]->load_adress = my_getnbr(raw_input[(*idx)++]); 
    }
    return SUCCESS;
}

static
int handle_dump(corewar_t *c, char **raw_input, int *idx)
{
    if (my_strcmp(raw_input[(*idx)], "-dump") == 0) {
        if (check_nbr_cycles(raw_input[++(*idx)]) == ERROR)
            return ERROR;
        else
            c->nbr_dump_cycles = my_getnbr(raw_input[(*idx)++]);
    }
    return SUCCESS;
}

static
int handle_file(char *file_path)
{
    if (my_strcmp(&file_path[my_strlen(file_path) - 4], ".cor") == 0)
        return SUCCESS;
    return ERROR;
}

input_t **parser_input(corewar_t *c, char **raw_input)
{
    int idx = 0;
    input_t **input = malloc(sizeof(input_t *) * (c->nbr_champions + 1));

    input[c->nbr_champions - 1] = malloc(sizeof(input_t));
    if (handle_dump(c, raw_input, &idx) == ERROR)
        return NULL;
    while (raw_input[idx]) {
        if (c->nbr_champions > 1) {
            input = realloc(input, sizeof(input_t *) * (c->nbr_champions + 1));
            input[c->nbr_champions - 1] = malloc(sizeof(input_t));
            input[c->nbr_champions] = NULL;
        }
        if (handle_flags(raw_input, &idx, input, c) == ERROR)
            return NULL;
        if (handle_file(raw_input[idx]) == ERROR)
            return NULL;
        input[c->nbr_champions - 1]->file_path = my_strdup(raw_input[idx++]);
        c->nbr_champions += 1;
    }
    return input;
}
