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
int execute_add(champions_t *c, size_t nbr_player, int *args)
{
    if (!c || !args)
        return ERROR;
    my_printf("add\n");
//    c->champions[nbr_player]->registers[args[2]] = c->champions[nbr_player]->\
//            registers[args[0]] + c->champions[nbr_player]->registers[args[1]];
//    c->champions[nbr_player]->carry =
//            (c->champions[nbr_player]->registers[args[2]] == 0 ? 1 : 0);
    return SUCCESS;
}
