/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** lldi.c
*/

#include "my.h"

int execute_lldi(champions_t  *c, uint8_t *args)
{
    if (!c || !args)
        return ERROR;
    my_printf("lldi\n");
    return SUCCESS;
}
