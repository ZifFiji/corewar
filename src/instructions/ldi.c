/*
** EPITECH PROJECT, 2024
** src
** File description:
** ldi
*/

#include "my.h"
#include <stdint.h>

static
void add_value(corewar_t *cw, champions_t *c, int *args)
{
    int adress = 0;
    int sum = 0;
    int value = 0;

    adress = ((c->program_counter + args[0]) % IDX_MOD) % MEM_SIZE;
    for (int i = 0; i < IND_SIZE + adress; i++) {
        sum += cw->arena[adress];
        adress++;
    }
    adress = ((c->program_counter + sum) % IDX_MOD) % MEM_SIZE;
    for (int i = 0; i < REG_SIZE; i++) {
        value += cw->arena[adress];
        adress++;
    }
    c->registers[args[2] - 1] = value;
}

int execute_ldi(corewar_t *cw, champions_t *c, int ins, int *args)
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
