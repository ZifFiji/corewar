/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** st.c
*/

#include "my.h"

int execute_st(corewar_t *cw, corewar_t *c, size_t nbr_player, int *args)
{
    if (!c || !args)
        return ERROR;
    my_printf("st\n");
    return SUCCESS;
    c->champions[nbr_player]->registers[args[1]] = c->champions[nbr_player]->\
    registers[args[0]];
    return SUCCESS;
}
