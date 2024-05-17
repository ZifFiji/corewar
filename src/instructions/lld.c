/*
** EPITECH PROJECT, 2024
** src
** File description:
** lld
*/

#include "my.h"

int execute_lld(corewar_t *cw, champions_t *c, int ins, int *args)
{
    int value = 0;
    int adress = 0;

    if (!c || !args)
        return ERROR;
    if (args[1] < 1 || args[1] > REG_NUMBER)
        return ERROR;
    adress = ((c->program_counter + args[0]) % MEM_SIZE);
    for (int i = 0; i < REG_SIZE; i ++) {
        value = cw->arena[adress];
        adress++;
    }
    c->registers[args[1] - 1] = value;
    if (c->carry == 1)
        c->carry = 0;
    else
        c->carry = 1;
    return SUCCESS;
}
