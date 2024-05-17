/*
** EPITECH PROJECT, 2024
** src
** File description:
** ldi
*/

#include "my.h"
#include <stdint.h>

int execute_ldi(corewar_t *cw, champions_t *c, size_t nbr_player, int *args)
{
    if (!c || !args)
        return ERROR;
    c->carry = 1;
    if (args[2] < 1 || args[2] > REG_NUMBER)
        return ERROR;
    return SUCCESS;
}
