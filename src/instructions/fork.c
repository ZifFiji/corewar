/*
** EPITECH PROJECT, 2024
** src
** File description:
** fork
*/

#include "my.h"

#include <stdlib.h>

champions_t *cpy_champ(champions_t *dest, const champions_t *src)
{
    dest->idx = src->idx;
    dest->carry = src->carry;
    dest->header = src->header;
    for (int i = 0; i < 2; i ++)
        dest->waittime[i] = src->waittime[i];
    for (int i = 0; i < REG_NUMBER; i ++)
        dest->registers[i] = src->registers[i];
    dest->instruction = src->instruction;
    dest->nbr_instruction = src->nbr_instruction;
    dest->program_counter = 0;
    return dest;
}

int execute_fork(corewar_t *cw, champions_t *c, int ins, int *args)
{
    size_t new_pc = 0;

    cw->champions = realloc(cw->champions, sizeof(champions_t *) * (cw->\
    nbr_champions + 2));
    cw->status_champ = realloc(cw->status_champ, sizeof(bool) * (cw->\
    nbr_champions + 1));
    cw->status_champ[cw->nbr_champions - 1] = true;
    cw->live_call = realloc(cw->live_call, sizeof(size_t) * (cw->\
    nbr_champions + 2));
    cw->live_call[cw->nbr_champions - 1] = cw->live_call[cw->nbr_champions - 2];
    cw->champions[cw->nbr_champions] = malloc(sizeof(champions_t));
    cw->champions[cw->nbr_champions] = cpy_champ(cw->champions[cw->\
    nbr_champions], c);
    new_pc = (((c->program_counter + args[0]) % IDX_MOD) % MEM_SIZE);
    cw->champions[cw->nbr_champions]->program_counter = new_pc;
    cw->nbr_champions++;
    cw->champions[cw->nbr_champions] = NULL;
    return SUCCESS;
}
