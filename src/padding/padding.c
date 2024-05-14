/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** padding.c
*/

#include "my.h"
#include "op.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>

int padding(corewar_t *corewar, champions_t **c)
{

    for (size_t i = 0; corewar->nbr_champions != i; i++) {
        for (int j = 0; c[i]->header.prog_size != j; j++)
            corewar->padding[j] =
    }
    return 0;
}