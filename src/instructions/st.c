/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** st.c
*/

#include "my.h"

int execute_st(corewar_t *cw, champions_t *c, int ins, int *args)
{
    size_t adress = 0;

    if (!c || !args)
        return ERROR;
    if (c->instruction[0]->type[1] == T_REG)
        c->registers[args[1] - 1] = c->registers[args[0] - 1];
    if (c->instruction[0]->type[1] == T_IND) {
        adress = ((c->program_counter + args[1]) % IDX_MOD) % MEM_SIZE;
        cw->arena[adress] = c->registers[args[0] - 1];
    }
    return SUCCESS;
}
