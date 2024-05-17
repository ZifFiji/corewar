/*
** EPITECH PROJECT, 2024
** src
** File description:
** zjmp
*/

#include "my.h"
#include <stdint.h>

int execute_zjmp(champions_t  *c, size_t nbr_player, int *args)
{
    if (c->carry == 0)
        return SUCCESS;
    c->program_counter -= 3;
    my_printf("b %d\n", c->program_counter);
    c->program_counter = ((c->program_counter + args[0]) % IDX_MOD) % MEM_SIZE;
    my_printf("a %d\n", c->program_counter);
    return SUCCESS;
}
