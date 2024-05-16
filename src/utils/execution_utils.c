/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** execution_utils.c
*/

#include "my.h"

#include <stdint.h>
#include <stdlib.h>

static
void get_register_value(uint8_t *arena, int *args, int j, size_t *pc)
{
    args[j] = (arena[(*pc)] & 0x000000FF);
    args[j] = (arena[(*pc + 1)] & 0x000000FF);
    (*pc) += 2;
}

static
void get_direct_value(uint8_t *arena, int *args, int j, size_t *pc)
{
    args[j] = (arena[(*pc)] & 0x000000FF);
    args[j] = (arena[(*pc) + 1] & 0x000000FF);
    args[j] = (arena[(*pc) + 2] & 0x000000FF);
    args[j] = (arena[(*pc) + 3] & 0x000000FF);
    args[j] = (arena[(*pc) + 4] & 0x000000FF);
    args[j] = (arena[(*pc) + 5] & 0x000000FF);
    args[j] = (arena[(*pc) + 6] & 0x000000FF);
    args[j] = (arena[(*pc) + 7] & 0x000000FF);
    (*pc) += 8;
}

static
void get_indirect_value(uint8_t *arena, int *args, int j, size_t *pc)
{
    args[j] = (arena[(*pc)] & 0x000000FF);
    args[j] = (arena[(*pc) + 1] & 0x000000FF);
    args[j] = (arena[(*pc) + 2] & 0x000000FF);
    args[j] = (arena[(*pc) + 3] & 0x000000FF);
    (*pc) += 4;
}

int *get_args_arena(champions_t *c, uint8_t *arena, size_t nbr_args, int *args)
{
    int j = 0;

    for (size_t i = 0; i != nbr_args; i ++) {
        my_printf("%d\n", c->instruction[c->nbr_instruction]->type[i]);
        if (c->instruction[c->nbr_instruction]->type[i] == T_REG) {
            get_register_value(arena, args, j, &(c->program_counter));
            j += 1;
        }
        if (c->instruction[c->nbr_instruction]->type[i] == T_DIR) {
            get_direct_value(arena, args, j, &(c->program_counter));
            j++;
        }
        if (c->instruction[c->nbr_instruction]->type[i] == T_IND) {
            get_indirect_value(arena, args, j, &(c->program_counter));
            j++;
        }
    }
    return args;
}
