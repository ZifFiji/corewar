/*
** EPITECH PROJECT, 2024
** instructions
** File description:
** sub
*/

#include "my.h"
#include <stdint.h>

/*
** It takes 3 registers as parameters, subtracts the first two, and stores the
** result in the third one. This operation modifies the carry.
*/
int execute_sub(corewar_t *cw, champions_t *c, size_t nbr_player, int *args)
{
    int sub = 0;

    if (!c || !args)
        return ERROR;
    sub = args[0] + args[1];
    c->registers[args[2]] = sub;
    if (sub == 0)
        c->carry = 1;
    else
        c->carry = 0;
    return SUCCESS;
}
