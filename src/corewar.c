/*
** EPITECH PROJECT, 2024
** src
** File description:
** corewar
*/

#include "my.h"

int error_handling(int ac, char **av, char **env)
{
    if (ac < 2 || !av || !av[1] || !env)
        return ERROR;
    if (my_strcmp(av[1], "-h") == 0) {
        display_help();
        return SUCCESS;
    }
    if (ac == 2 || ac > 4)
        return ERROR;
    return SUCCESS;
}

int corewar(int ac, char **av, char **env)
{
    if (error_handling(ac, av, env) == ERROR)
        return ERROR;
    return SUCCESS;
}
