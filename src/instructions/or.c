/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** or.c
*/

#include "my.h"

/*
** It takes 3 arguments, the first two are registers or direct values, and the
** third one is a register. It applies a bitwise OR on the first two arguments
*/
int execute_or(corewar_t *c, uint8_t *args, int nbr_player)
{
    if (!c || !args)
        return ERROR;
    c->champions[nbr_player]->registers[args[2]] = c->champions[nbr_player]->\
    registers[args[0]] | c->champions[nbr_player]->registers[args[1]];
    return SUCCESS;
}
