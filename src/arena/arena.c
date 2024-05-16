/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** arena.c
*/

#include "my.h"
#include "op.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <stdbool.h>

static
int hexa_to_int(unsigned char hexa)
{
    if (hexa >= '0' && hexa <= '9')
        return hexa - '0';
    else
        return hexa - 'a' + 10;
}

static
int write_reg(instructions_t *ins, corewar_t *corewar, int j, int k)
{
    char *parms = NULL;

    parms = convert_int_to_hexa(ins->parameters[k], 2);
    for (int i = 0; i != 2; i++) {
        corewar->arena[j] = hexa_to_int(parms[i]);
        j++;
    }
    free(parms);
    return j;
}

static
int write_ind(instructions_t *ins, corewar_t *corewar, int j, int k)
{
    char *parms = NULL;

    parms = convert_int_to_hexa(ins->parameters[k], 4);
    for (int i = 0; i != 4; i++) {
        corewar->arena[j] = hexa_to_int(parms[i]);
        j++;
    }
    free(parms);
    return j;
}

static
int write_dir(instructions_t *ins, corewar_t *corewar, int j, int k)
{
    char *parms = NULL;

    parms = convert_int_to_hexa(ins->parameters[k], 8);
    for (int i = 0; i != 8; i++) {
        corewar->arena[j] = hexa_to_int(parms[i]);
        j++;
    }
    free(parms);
    return j;
}

int write_conditions_error(instructions_t *ins, corewar_t *corewar, int j)
{
    if (ins->instruction - 1 == 0)
        j = write_dir(ins, corewar, j, 0);
    else
        j = write_ind(ins, corewar, j, 0);
    return j;
}

int write_conditions_succes(instructions_t *ins, corewar_t *corewar, int j)
{
    corewar->arena[j] = ins->coding_byte;
    j++;
    for (int k = 0; k != ins->nbr_params; k++) {
        if (ins->type[k] == T_REG)
            j = write_reg(ins, corewar, j, k);
        if (ins->type[k] == T_IND)
            j = write_ind(ins, corewar, j, k);
        if (ins->type[k] == T_DIR)
            j = write_dir(ins, corewar, j, k);
    }
    return j;
}

static
int write_all(champions_t *c, corewar_t *corewar, int j)
{
    char *instruction = 0;

    for (size_t i = 0; c->nbr_instruction != i; i++) {
        instruction = convert_int_to_hexa(c->instruction[i]->instruction, 2);
        corewar->arena[j] = hexa_to_int(instruction[0]);
        j++;
        corewar->arena[j] = hexa_to_int(instruction[1]);
        j++;
        if (check_mnemonique(c->instruction[i]->instruction - 1) == SUCCESS)
            j = write_conditions_succes(c->instruction[i], corewar, j);
        else
            j = write_conditions_error(c->instruction[i], corewar, j);
    }
    return j;
}

int arena(champions_t **c, corewar_t *corewar)
{
    int j = 0;

    for (size_t i = 0; corewar->nbr_champions != i; i++) {
        for (; corewar->padding[j] != i + 1; j++);
        if (j % 2 != 0)
            j++;
        corewar->champions[i]->program_counter = j;
        j = write_all(c[i], corewar, j);
    }
    return 0;
}
