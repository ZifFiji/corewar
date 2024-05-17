/*
** EPITECH PROJECT, 2024
** src
** File description:
** lfork
*/

#include "my.h"

#include <stdlib.h>

int execute_lfork(corewar_t *cw, champions_t *c, size_t nbr_player, int *args)
{
    int new_pc = 0;

    cw->champions = realloc(cw->champions, sizeof(champions_t *) * cw->\
    nbr_champions + 1);
    cw->champions[cw->nbr_champions] = malloc(sizeof(champions_t));
    cw->champions[cw->nbr_champions] = cpy_champ(cw->champions[cw->\
    nbr_champions], c);
    new_pc = ((c->program_counter + args[1]) % MEM_SIZE);
    cw->champions[cw->nbr_champions]->program_counter = new_pc;
    cw->nbr_champions++;
    cw->champions[cw->nbr_champions] = NULL;
    return SUCCESS;
}
