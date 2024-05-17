/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** lldi.c
*/

#include "my.h"

static
void add_value(corewar_t *cw, champions_t *c, int *args)
{
    size_t adress = 0;
    size_t sum = 0;
    int value = 0;

    adress = (c->program_counter + args[0]) % MEM_SIZE;
    for (size_t i = 0; i < IND_SIZE + adress; i++) {
        sum += cw->arena[adress];
        adress++;
    }
    adress = (c->program_counter + sum) % MEM_SIZE;
    for (int i = 0; i < REG_SIZE; i++) {
        value += cw->arena[adress];
        adress++;
    }
    c->registers[args[2] - 1] = value;
}

int execute_lldi(corewar_t *cw, champions_t *c, int ins, int *args)
{
    if (!c || !args)
        return ERROR;
    if (args[2] < 1 || args[2] > REG_NUMBER)
        return ERROR;
    add_value(cw, c, args);
    if (c->carry == 1)
        c->carry = 0;
    else
        c->carry = 1;
    return SUCCESS;
}
