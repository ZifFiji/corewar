/*
** EPITECH PROJECT, 2024
** src
** File description:
** execution
*/

#include "my.h"
#include <stdint.h>

int execution_corewar(corewar_t *corewar)
{
    uint8_t instruction = 0;
    size_t nbr_live = 0;

    if (!corewar)
        return ERROR;
    for (size_t cycle = 0; cycle; cycle += 1) {
        if (nbr_live == 40) {
            CYCLE_TO_DIE = CYCLE_TO_DIE - 5;
            nbr_live = 0;
        }
        for (size_t i = 0; i < corewar->nbr_champions; i ++) {
            if (corewar->champions[i]->waittime[0] == corewar->champions[i]->waittime[1]) {
                instruction = corewar->arena[corewar->champions[i]->program_counter - 1];
                corewar->champions[i]->waittime[0] = 0;
                corewar->champions[i]->waittime[1] = op_tab[instruction - 1].nbr_cycles;
                if (my_strcmp(op_tab[instruction - 1].mnemonique, "live") == 0) {
                    nbr_live += 1;
                }
            }
            else {
                corewar->champions[i]->waittime[0] += 1;
            }
        }
    }
    return SUCCESS;
}
