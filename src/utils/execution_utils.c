/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** execution_utils.c
*/

#include "my.h"
#include <stdio.h>

#include <stdint.h>
#include <stdlib.h>

char *sti_to_bin(int coding_byte)
{
    char *params = NULL;
    char *new_params = NULL;

    params = int_to_bin(coding_byte);
    if (my_strcmp(params, "01101000") == 0)
        new_params = my_strdup("01111100");
    if (my_strcmp(params, "01011000") == 0)
        new_params = my_strdup("01011100");
    if (my_strcmp(params, "01100100") == 0)
        new_params = my_strdup("01110100");
    if (my_strcmp(params, "01010100") == 0)
        new_params = my_strdup(params);
    return new_params;
}

static
void get_register_value(uint8_t *arena, int *args, int j, size_t *pc)
{
    args[j] += (arena[(*pc)] & 0x000000FF);
    (*pc) += 1 % MEM_SIZE;
}

static
void get_direct_value(uint8_t *arena, int *args, int j, size_t *pc)
{
    args[j] += (arena[(*pc)] & 0x000000FF) << 24;
    args[j] += (arena[((*pc) + 1) % MEM_SIZE] & 0x000000FF) << 16;
    args[j] += (arena[((*pc) + 2) % MEM_SIZE] & 0x000000FF) << 8;
    args[j] += (arena[((*pc) + 3) % MEM_SIZE] & 0x000000FF) << 0;
    (*pc) += 4 % MEM_SIZE;
}

static
void get_indirect_value(uint8_t *arena, int *args, int j, size_t *pc)
{
    args[j] += (arena[(*pc)] & 0x000000FF) << 8;
    args[j] += (arena[((*pc) + 1) % MEM_SIZE] & 0x000000FF) << 0;
    (*pc) += 2 % MEM_SIZE;
}

int *get_args_arena(champions_t *c, uint8_t *arena, size_t nbr_args, int *args)
{
    int j = 0;

    for (size_t i = 0; i != nbr_args; i ++) {
        if (c->instruction[c->nbr_instruction]->type[i] == T_REG) {
            get_register_value(arena, args, j, &(c->program_counter));
            j += 1;
        }
        if (c->instruction[c->nbr_instruction]->type[i] == T_IND) {
            get_indirect_value(arena, args, j, &(c->program_counter));
            j++;
        }
        if (c->instruction[c->nbr_instruction]->type[i] == T_DIR) {
            get_direct_value(arena, args, j, &(c->program_counter));
            j++;
        }
    }
    return args;
}
