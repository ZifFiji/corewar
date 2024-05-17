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
    size_t i = 0;
    size_t total = 0;
    size_t save_size = 0;

    if (corewar->input[i]->load_adress != -1)
        total = corewar->input[i]->load_adress;
    for (size_t j = total; c[i]->header.prog_size + total != j; j++)
        corewar->padding[j] = i + 1;
    i++;
    for (; corewar->nbr_champions != i; i++) {
        if (corewar->input[i]->load_adress == -1) {
            total = ((MEM_SIZE / corewar->nbr_champions) + \
            c[i]->header.prog_size + save_size) % MEM_SIZE;
        } else
            total = corewar->input[i]->load_adress % MEM_SIZE;
        for (size_t j = total; total + c[i]->header.prog_size != j; j++)
            corewar->padding[j] = i + 1;
        save_size = MEM_SIZE + total;
    }
    return 0;
}
