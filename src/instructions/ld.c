/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** ld.c
*/

#include "my.h"

/*
** It takes a direct or indirect value and loads it into a register
*/
int execute_ld(corewar_t *cw, champions_t *c, size_t nbr_player, int *args)
{
    int value = 0;
    int adress = 0;

    if (!c || !args)
        return ERROR;
    c->carry = 1;
    if (args[1] < 1 || args[1] > REG_NUMBER)
        return ERROR;
    adress = (((c->program_counter + args[0]) % IDX_MOD) % MEM_SIZE);
    for (int i = 0; i < REG_SIZE; i ++) {
        value = cw->arena[adress];
        adress++;
    }
    c->registers[args[1] - 1] = value;
    return SUCCESS;
}
