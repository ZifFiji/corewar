/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** init_structure
*/

#include "my.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void init_header(champions_t **champ, size_t i)
{
    for (size_t j = 0; j < PROG_NAME_LENGTH; j ++)
        champ[i]->header.prog_name[j] = 0;
    for (size_t j = 0; j < COMMENT_LENGTH; j ++)
        champ[i]->header.comment[j] = 0;
    champ[i]->header.prog_size = 0;
    champ[i]->header.magic = 0;
}

champions_t **init_champion(size_t nbr_champions)
{
    champions_t **champ = malloc(sizeof(champions_t *) * (nbr_champions + 1));

    if (!champ)
        return NULL;
    for (size_t i = 0; i < nbr_champions; i ++) {
        champ[i] = malloc(sizeof(champions_t));
        for (int j = 0; j < REG_SIZE; j ++)
            champ[i]->registers[j] = 0;
        init_header(champ, i);
        champ[i]->instruction = NULL;
        champ[i]->nbr_instruction = 0;
        champ[i]->program_counter = 0;
        champ[i]->carry = 1;
        champ[i]->idx = PROG_NAME_LENGTH + COMMENT_LENGTH + 16;
    }
    return champ;
}

instructions_t *init_instruction(void)
{
    instructions_t *new = malloc(sizeof(instructions_t));

    new->instruction = 0;
    new->coding_byte = 0;
    new->parameters = NULL;
    new->type = NULL;
    return new;
}

input_t *init_input(void)
{
    input_t *new = malloc(sizeof(input_t));

    new->file_path = NULL;
    new->load_adress = 0;
    new->prog_number = 0;
    return new;
}

corewar_t *init_corewar(char **raw_input)
{
    corewar_t *c = malloc(sizeof(corewar_t));

    for (int i = 0; i < MEM_SIZE; i ++) {
        c->arena[i] = 0;
        c->padding[i] = 0;
    }
    c->nbr_dump_cycles = -1;
    c->nbr_champions = 0;
    c->input = parser_input(c, &raw_input[1]);
    if (!c->input || c->nbr_champions == 1 || c->nbr_champions > 4)
        return NULL;
    c->champions = parser_files(c, c->input);
    if (!c->champions)
        return NULL;
    return c;
}
