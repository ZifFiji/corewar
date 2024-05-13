/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** aff.c
*/

#include "my.h"

#include <unistd.h>

/*
** It takes a register and displays the character in the ASCII table
*/
int execute_aff(corewar_t *c, uint8_t const *args)
{
    int to_display = args[0] % 256;

    if (!c || !args)
        return ERROR;
    write(1, &to_display, 1);
    return SUCCESS;
}