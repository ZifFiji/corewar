/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** st.c
*/

#include "my.h"

int execute_st(corewar_t *c, uint8_t *args, size_t nbr_player)
{
    if (!c || !args)
        return ERROR;
    my_printf("st\n");
    return SUCCESS;
    c->champions[nbr_player]->registers[args[1]] = c->champions[nbr_player]->\
    registers[args[0]];
    return SUCCESS;
}
