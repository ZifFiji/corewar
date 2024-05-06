/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** init_structure
*/

#include "my.h"

#include <stdlib.h>
#include <stdbool.h>

champions_t **init_champion(size_t nbr_champions)
{
    champions_t **champion = malloc(sizeof(champions_t *) * (nbr_champions + 1));

    if (!champion)
        return NULL;
    for (size_t champ = 0; champ < nbr_champions; champ ++) {
        champion[champ] = malloc(sizeof(champions_t));
        for (size_t i = 0; i < PROG_NAME_LENGTH; i ++)
            champion[champ]->header.prog_name[i] = 0;
        for (size_t i = 0; i < COMMENT_LENGTH; i ++)
            champion[champ]->header.comment[i] = 0;
        champion[champ]->header.prog_size = 0;
        champion[champ]->header.magic = 0;
        champion[champ]->instruction = NULL;
    }
    return champion;
}

corewar_t *init_corewar(char **raw_input)
{
    corewar_t *c = malloc(sizeof(corewar_t));

    for (int i = 0; i < MEM_SIZE; i ++) {
        c->arena[i] = 0;
        c->padding[i] = 0;
    }
    c->nbr_dump_cycles = 0;
    c->nbr_champions = 1;
    c->input = parser_input(c, &raw_input[1]);
    if (!c->input || c->nbr_champions == 1 || c->nbr_champions > 4)
        return NULL;
    c->champions = parse_files(c, c->input);
    return c;
}
