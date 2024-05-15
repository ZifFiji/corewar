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
int check_mnemonique(uint8_t mnemo)
{
    if (mnemo == 8 || mnemo == 0 || mnemo == 14 || mnemo == 11)
        return ERROR;
    return SUCCESS;
}

static
uint8_t write_ind

int write_all(champions_t *c, corewar_t  *corewar, int j)
{
    for (size_t i = 0; c->nbr_instruction != i; i++) {
        corewar->arena[j] = c->instruction[i]->instruction;
        j++;
        if (check_mnemonique(56+c->instruction[i]->instruction) == SUCCESS) {
            if (c->instruction[i]->instruction == 1)
        }
    }
    return 0;
}

int arena(champions_t **c, corewar_t *corewar)
{
    int j = 0;

    for (size_t i = 0; corewar->nbr_champions != i; i++) {
        for (j; corewar->padding[j] != i + 1; j++);
        j = write_all(c[i], corewar, j);
    }
    return 0;
}
