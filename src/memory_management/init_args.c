/*
** EPITECH PROJECT, 2024
** memory_management
** File description:
** init_args
*/

#include "../../include/my.h"

#include <stdlib.h>

int check_mnemonique(uint8_t mnemo)
{
    if (mnemo == 8 || mnemo == 0 || mnemo == 14 || mnemo == 11)
        return ERROR;
    return SUCCESS;
}

int *init_args(size_t nbr_args, int *args)
{
    if (!nbr_args)
        return NULL;
    args = malloc(sizeof(int) * nbr_args);
    for (size_t i = 0; i < nbr_args; i ++)
        args[i] = 0;
    if (!args)
        return NULL;
    return args;
}
