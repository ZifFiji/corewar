/*
** EPITECH PROJECT, 2024
** src
** File description:
** corewar
*/

#include "my.h"

#include <stdlib.h>

int error_handling(int ac, char **av, char **env)
{
    if (ac <= 2 || !av || !av[1] || !env)
        return ERROR;
    if (my_strcmp(av[1], "-h") == 0) {
        display_help();
        return SUCCESS;
    }
    return SUCCESS;
}

int corewar(int ac, char **av, char **env)
{
    corewar_t *corewar = NULL;

    if (error_handling(ac, av, env) == ERROR)
        return ERROR;
    corewar = init_corewar(av);
    if (!corewar)
        return ERROR;
    return SUCCESS;
}
