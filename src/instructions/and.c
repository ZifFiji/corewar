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
int execute_and(champions_t  *c, int nbr_player, uint8_t *args)
{
    if (!c || !args)
        return ERROR;
    my_printf("and\n");
    args[2] = args[0] & args[1];
    return SUCCESS;
}
