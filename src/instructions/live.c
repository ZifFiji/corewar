/*
** EPITECH PROJECT, 2024
** instructions
** File description:
** live
*/

#include "my.h"
#include <stdint.h>

int execute_live(champions_t *c, __attribute__((unused))size_t nbr_player,
uint8_t *args)
{
    int player = args[0];

    my_printf("The player %d(%s) is alive.\n", c->registers[0], c->header.prog_name);
    return SUCCESS;
}
