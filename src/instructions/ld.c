/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** ld.c
*/

#include "my.h"

/*
** It takes a direct or indirect value and loads it into a register
*/
int execute_ld(champions_t  *c, size_t nbr_player, uint8_t const *args)
{
    if (!c || !args)
        return ERROR;
    my_printf("ld\n");
//    c->registers[args[1]] = c->program_counter + args[0] % IDX_MOD;
    return SUCCESS;
}
