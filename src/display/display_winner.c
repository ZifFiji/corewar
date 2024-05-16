/*
** EPITECH PROJECT, 2024
** display
** File description:
** display_winner
*/

#include "my.h"

void display_winner(int player, corewar_t *c)
{
    printf("%d\n", player);
    my_putstr("The player ", 1);
    my_put_nbr_base(player, "0123456789");
    my_putstr("(", 1);
    my_putstr(c->champions[player]->header.prog_name, 1);
    my_putstr(")", 1);
    my_putstr("has won.\n", 1);
}
