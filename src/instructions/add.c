/*
** EPITECH PROJECT, 2024
** instructions
** File description:
** add
*/

#include "my.h"
#include <stdint.h>

/*
** It takes 3 registers as parameters, adds the first two,
** and stores the result in the third one. This operation modifies the carry.
*/
int execute_add(corewar_t *c, size_t nbr_player, int *args)
{
    if (!c || !args)
        return ERROR;
    my_printf("add\n");
    return SUCCESS;
}
