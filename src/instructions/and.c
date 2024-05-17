/*
** EPITECH PROJECT, 2024
** instructions
** File description:
** and
*/

#include "my.h"
#include <stdint.h>

/*
** It takes 3 parameters, and performs a bitwise AND on the first two.
** The result is stored in the third one. This operation modifies the carry.
*/
int execute_and(corewar_t *cw, champions_t *c, size_t nbr_player, int *args)
{
    int value = 0;

    if (!c || !args)
        return ERROR;
    value = args[0] & args[1];
    if (args[2] >= 1 && args[2] <= 15)
        c->registers[args[2]] = value;
    if (value == 0)
        c->carry = 1;
    else
        c->carry = 0;
    return SUCCESS;
}
