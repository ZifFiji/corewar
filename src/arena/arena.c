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

static
int hexa_to_int(char hexa)
{
    if (hexa >= 0 && hexa <= '9')
        return hexa - '0';
    else
        return hexa - 'A' + 10;
}

static
char *int_to_hex_dir(int num)
{
    char *hex = malloc(sizeof(char) * 9);
    const char *hex_chars = "0123456789ABCDEF";

    if (hex == NULL)
        return NULL;
    for (int i = 7; i >= 0; --i)
        hex[7 - i] = hex_chars[(num >> (i * 4)) & 0xF];
    hex[8] = '\0';
    return hex;
}

static
char *int_to_hex_ind(int num)
{
    char *hex = malloc(sizeof(char) * 5);
    const char *hex_chars = "0123456789ABCDEF";

    if (hex == NULL)
        return NULL;
    for (int i = 3; i >= 0; --i)
        hex[3 - i] = hex_chars[(num >> (i * 4)) & 0xF];
    hex[4] = '\0';
    return hex;
}

static
char *int_to_hex_reg(int num)
{
    char *hex = malloc(sizeof(char) * 3);
    const char *hex_chars = "0123456789ABCDEF";

    if (hex == NULL)
        return NULL;
    for (int i = 1; i >= 0; --i)
        hex[1 - i] = hex_chars[(num >> (i * 4)) & 0xF];
    hex[2] = '\0';
    return hex;
}

static
int write_reg(instructions_t *ins, corewar_t *corewar, int j, int k)
{
    char *parms = NULL;

    parms = int_to_hex_reg(ins->parameters[k]);
    corewar->arena[j] = hexa_to_int(parms[0]);
    j++;
    corewar->arena[j] = hexa_to_int(parms[1]);
    j++;
    return j;
}

static
int write_ind(instructions_t *ins, corewar_t *corewar, int j, int k)
{
    char *parms = NULL;

    parms = int_to_hex_ind(ins->parameters[k]);
    corewar->arena[j] = hexa_to_int(parms[0]);
    j++;
    corewar->arena[j] = hexa_to_int(parms[1]);
    j++;
    corewar->arena[j] = hexa_to_int(parms[2]);
    j++;
    corewar->arena[j] = hexa_to_int(parms[3]);
    j++;
    return j;
}

static
int write_dir(instructions_t *ins, corewar_t *corewar, int j, int k)
{
    char *parms = NULL;

    parms = int_to_hex_dir(ins->parameters[k]);
    corewar->arena[j] = hexa_to_int(parms[0]);
    j++;
    corewar->arena[j] = hexa_to_int(parms[1]);
    j++;
    corewar->arena[j] = hexa_to_int(parms[2]);
    j++;
    corewar->arena[j] = hexa_to_int(parms[3]);
    j++;
    corewar->arena[j] = hexa_to_int(parms[4]);
    j++;
    corewar->arena[j] = hexa_to_int(parms[5]);
    j++;
    corewar->arena[j] = hexa_to_int(parms[6]);
    j++;
    corewar->arena[j] = hexa_to_int(parms[7]);
    j++;
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

int write_all(champions_t *c, corewar_t  *corewar, int j)
{
    char *instruction = 0;

    for (size_t i = 0; c->nbr_instruction != i; i++) {
        instruction = int_to_hex_reg(c->instruction[i]->instruction);
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
