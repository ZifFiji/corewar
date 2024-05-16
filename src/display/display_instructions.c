/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** display_instructions.c
*/

#include "my.h"

void display_instructions(champions_t *c)
{
    for (int i = 0; i != (int)c->nbr_instruction; i++) {
        my_printf("instructions : %s", op_tab[c->instruction[i]
        ->instruction - 1].mnemonique);
        for (int j = 0; j != c->instruction[i]->nbr_params; j++)
            my_printf("params[%d] : %x", j + 1, c->instruction[i]
            ->parameters[j]);
        my_printf("\n");
    }
}
