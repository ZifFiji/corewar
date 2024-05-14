/*
** EPITECH PROJECT, 2024
** instructions
** File description:
** live
*/

#include "my.h"
#include <stdint.h>

int execute_live(corewar_t *c, __attribute__((unused))size_t nbr_player,
uint8_t *args)
{
    int player = args[0];

    if (player < 0 || player > 4)
        return ERROR;
    my_putstr("The player ", 1);
    my_put_nbr_base(player, "0123456789");
    my_putstr("(", 1);
    my_putstr(c->champions[player]->header.prog_name, 1);
    my_putstr(")", 1);
    my_putstr("is alive.\n", 1);
    return SUCCESS;
}
