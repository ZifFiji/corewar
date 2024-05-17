/*
** EPITECH PROJECT, 2024
** instructions
** File description:
** add
*/

#include "my.h"
#include <stdint.h>

/*
** It takes 3 registers as parameters, adds the first two,
** and stores the result in the third one. This operation modifies the carry.
*/
int execute_add(corewar_t *cw, champions_t *c, int ins, int *args)
{
    int sum = 0;

    if (!c || !args)
        return ERROR;
    sum = args[0] + args[1];
    c->registers[args[2]] = sum;
    if (sum == 0)
        c->carry = 1;
    else
        c->carry = 0;
    return SUCCESS;
}
