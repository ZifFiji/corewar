/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** aff.c
*/

#include "my.h"

#include <unistd.h>

/*
** It takes a register and displays the character in the ASCII table
*/
int execute_aff(corewar_t *cw, champions_t *c, int ins, int *args)
{
    if (!c || !args)
        return ERROR;
    if (args[0] < 1 || args[0] > REG_NUMBER)
        return ERROR;
    my_printf("%c\n", c->registers[args[0] - 1] % 256);
    return SUCCESS;
}
