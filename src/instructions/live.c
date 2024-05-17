/*
** EPITECH PROJECT, 2024
** instructions
** File description:
** live
*/

#include "my.h"

int execute_live(corewar_t *cw, champions_t *c, size_t nbr_player, int *args)
{
    int reg = 0;

    if (!cw || !c || !args)
        return ERROR;
    reg = args[0];
    if (args[0] < 1 || args[0] > 15)
        reg = 1;
    my_printf("The player %d(%s) is alive.\n", c->registers[reg - 1], c->\
    header.prog_name);
    return SUCCESS;
}
