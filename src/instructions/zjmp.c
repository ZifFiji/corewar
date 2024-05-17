/*
** EPITECH PROJECT, 2024
** src
** File description:
** zjmp
*/

#include "my.h"
#include <stdint.h>

int execute_zjmp(corewar_t *cw, champions_t *c, size_t nbr_player, int *args)
{
    int result = 0;

    if (c->carry == 0)
        return SUCCESS;
    c->program_counter -= 3;
    if ((args[0] & 1 << (16 - 1)) != 0)
        result = ((args[0] - (1 << 16) + 1) -1);
    else
        result = args[0];
    c->program_counter += ((result % IDX_MOD) % MEM_SIZE);
    return SUCCESS;
}
