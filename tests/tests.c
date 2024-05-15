/*
** EPITECH PROJECT, 2024
** tests
** File description:
** tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my.h"

Test(unit_test, return_success)
{
    int ac = 0;
    char **av = NULL;
    char **env = NULL;

    cr_assert_eq(0, corewar(ac, av, env));
}

// Test(unit_test, display_winner_player_1, .init=cr_redirect_stdout)
// {
//     corewar_t *c = malloc(sizeof(corewar_t));
//
//     c->champions = malloc(sizeof(champions_t *) * 2);
//     c->champions[0] = malloc(sizeof(champions_t));
//     c->champions[0]->header.prog_name[0] = 'y';
//     c->champions[0]->header.prog_name[1] = 'e';
//     c->champions[0]->header.prog_name[2] = 's';
//     c->champions[0]->header.prog_name[3] = '\0';
//     display_winner(0, c);
//     cr_assert_stdout_eq_str("The player1(yes)has won.\n");
// }
