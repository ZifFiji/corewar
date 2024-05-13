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
int execute_ld(corewar_t *c, uint8_t const *args, int nbr_player)
{
    if (!c || !args)
        return ERROR;
    c->champions[nbr_player]->registers[args[1]] = c->champions[nbr_player]->\
    program_counter + args[0] % IDX_MOD;
    return SUCCESS;
}
