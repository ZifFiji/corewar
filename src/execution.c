/*
** EPITECH PROJECT, 2024
** src
** File description:
** execution
*/

#include "my.h"
#include "execution.h"

#include <stdint.h>
#include <stdlib.h>

static
void check_live_instruction(size_t *nbr_live, size_t *cycle_to_die)
{
    if ((*nbr_live) == NBR_LIVE) {
        (*cycle_to_die) -= CYCLE_DELTA;
        (*nbr_live) = 0;
    }
}

static
int check_alive_champ(corewar_t *corewar)
{
    size_t alive_champ = 0;

    printf("nbr_champ = %d\n", corewar->nbr_champions);
    for (size_t i = 0; i < corewar->nbr_champions; i ++) {
        if (corewar->status_champ[i] == true)
            alive_champ += 1;
    }
    printf("alive champ = %d\n", alive_champ);
    if (alive_champ > 1)
        return SUCCESS;
    return ERROR;
}

/*
** Set the wait time to the number of cycle to wait associated to
** the instruction
*/
static
void set_cycle_to_wait(champions_t *champion, uint8_t instruction)
{
    champion->waittime[0] = 0;
    champion->waittime[1] = op_tab[instruction - 1].nbr_cycles;
}

/*
** This function is use to handle the live counter of every champ and to know
** if the champion is dead
*/
static
void handle_live_counter(corewar_t *corewar, size_t i, uint8_t instruction)
{
    if (instruction == 1) {
        corewar->winner = i;
        corewar->nbr_live += 1;
        corewar->live_call[i] = 0;
    } else {
        corewar->live_call[i] += 1;
    }
}

static
void get_type_no_coding_byte(champions_t *c, uint8_t ins)
{
    if (ins == 0)
        c->instruction[c->nbr_instruction]->type[0] = T_DIR;
    if (ins == 8 || ins == 14 || ins == 11)
        c->instruction[c->nbr_instruction]->type[0] = T_IND;
}

static
void execute_instruction(corewar_t *corewar, uint8_t instruction, size_t i)
{
    int *args = NULL;
    char *coding_byte = NULL;

    set_cycle_to_wait(corewar->champions[i], instruction);
    args = malloc(sizeof(int) * op_tab[instruction - 1].nbr_args);
    if (instruction == 1 || instruction == 9 || instruction == 15 || instruction == 12) {
        handle_live_counter(corewar, i, instruction);
        init_params(corewar->champions[i], op_tab[instruction - 1].nbr_args);
        get_type_no_coding_byte(corewar->champions[i], instruction - 1);
        args = get_args_arena(corewar->champions[i], corewar->arena, op_tab[instruction - 1].nbr_args, args);
    } else {
        handle_live_counter(corewar, i, instruction);
        coding_byte = int_to_bin(corewar->arena[corewar->\
        champions[i]->program_counter]);
        init_params(corewar->champions[i], op_tab[instruction - 1].nbr_args);
        get_type_param(coding_byte, corewar->champions[i]);
        args = get_args_arena(corewar->champions[i], corewar->arena, op_tab[instruction - 1].nbr_args, args);
    }
    corewar->champions[i]->program_counter += op_tab[instruction - 1].nbr_args - 1;
    exec_tab[instruction - 1].fptr(corewar, i, args);
}

/*
** This function is used to compute the champion
*/
static
int compute_champions(corewar_t *corewar, size_t i, size_t *pc)
{
    uint8_t instruction = 0;

    if (corewar->status_champ[i] == false)
        return SUCCESS;
    if (corewar->champions[i]->waittime[0] == corewar->champions[i]->waittime[1]) {
        instruction = corewar->arena[(*pc) + 1];
        (*pc) = ((*pc) + 1) % MEM_SIZE;
        if (instruction >= 1 && instruction <= NBR_INSTRUCTION)
            execute_instruction(corewar, instruction, i);
    }
    else {
        corewar->champions[i]->waittime[0] += 1;
        corewar->live_call[i] += 1;
    }
    if (corewar->live_call[i] >= corewar->cycle_to_die)
        corewar->status_champ[i] = false;
    check_live_instruction(&(corewar->nbr_live), &(corewar->cycle_to_die));
    return SUCCESS;
}

/*
** This function is used execute the corewar game
*/
int execution_corewar(corewar_t *corewar)
{
    int cycle = 0;

    if (!corewar)
        return ERROR;
    while (cycle != corewar->nbr_dump_cycles) {
        if (check_alive_champ(corewar) == ERROR) {
            display_winner(corewar->winner, corewar);
        }
        for (size_t i = 0; i < corewar->nbr_champions; i ++) {
            compute_champions(corewar, i, &(corewar->champions[i]->\
            program_counter));
        }
        cycle += 1;
    }
    if (corewar->nbr_dump_cycles != -1)
        display_memory(corewar->arena);
    my_putstr("Everybody won.\n", 1);
    return SUCCESS;
}
