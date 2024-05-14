/*
** EPITECH PROJECT, 2024
** src
** File description:
** execution
*/

#include "my.h"
#include "execution.h"

#include <stdint.h>

static
void check_live_instruction(size_t *nbr_live, size_t *cycle_to_die)
{
    if ((*nbr_live) == NBR_LIVE) {
        (*cycle_to_die) -= CYCLE_DELTA;
        (*nbr_live) = 0;
    }
}

int execution_corewar(corewar_t *corewar)
{
    uint8_t instruction = 0;
    size_t nbr_live = 0;
    size_t cycle_to_die = CYCLE_TO_DIE;
    int winner = -1;

    if (!corewar)
        return ERROR;
    for (size_t cycle = 0; cycle; cycle += 1) {
        check_live_instruction(&nbr_live, &cycle_to_die); // CHECK IF THERE IS 40 CALLS OF LIVE AND REDUCE CYCLE_TO_DIE
        for (size_t i = 0; i < corewar->nbr_champions; i ++) { // LOOP ON ALL CHAMPS
            corewar->champions[i]->program_counter %= IDX_MOD;
            if (corewar->champions[i]->waittime[0] == corewar->champions[i]->waittime[1]) { // IF THE CHAMPION IS NOT IN A WAIT TIME
                instruction = corewar->arena[corewar->champions[i]->program_counter]; // WE GET THE INSTRUCTION
                if (instruction >= 0 && instruction <= NBR_INSTRUCTION) { // IF THE INSTRUCTION EXISTS
                    corewar->champions[i]->waittime[0] = 0; // SET THE COUNTER OF TIME TO WAIT
                    corewar->champions[i]->waittime[1] = op_tab[instruction - 1].nbr_cycles; // SET THE TIME TO WAIT
                    if (my_strcmp(op_tab[instruction - 1].mnemonique, "live") == 0) {
                        winner = i;
                        nbr_live += 1;
                    }
                }
            }
            else { // ELSE WE ADD 1 TO THE COUNTER OF CYCLE TO WAIT
                corewar->champions[i]->waittime[0] += 1;
            }
        }
    }
    return SUCCESS;
}
