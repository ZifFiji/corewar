/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** xor.c
*/

#include "my.h"

/*
** It takes 3 arguments, the first two are registers or direct values, and the
** third one is a register. It applies a bitwise XOR on the first two arguments
*/
int execute_xor(corewar_t *cw, champions_t *c, size_t nbr_player, int *args)
{
    int value = 0;

    if (!c || !args)
        return ERROR;
    value = args[0] ^ args[1];
    if (args[2] >= 1 && args[2] <= 15)
        c->registers[args[2]] = value;
    if (value == 0)
        c->carry = 1;
    else
        c->carry = 0;
    return SUCCESS;
}
