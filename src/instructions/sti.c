/*
** EPITECH PROJECT, 2024
** src
** File description:
** sti
*/

#include "my.h"
#include "op.h"

int execute_sti(corewar_t *cw, champions_t *c, int ins, int *args)
{
    int value = 0;
    int adress = 0;

    if (!c || !args)
        return ERROR;
    if (args[0] < 1 || args[0] > REG_NUMBER)
        return ERROR;
    value = args[0];
    adress = c->program_counter + (((args[1] + args[2]) % IDX_MOD) % MEM_SIZE);
    cw->arena[adress] = (value & 0xFF000000) << 24;
    cw->arena[adress + 1] = (value & 0x00FF0000) << 16;
    cw->arena[adress + 2] = (value & 0x0000FF00) << 8;
    cw->arena[adress + 3] = (value & 0x000000FF) << 0;
    return SUCCESS;
}
