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

static
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
        champ[i]->registers[0] = i + 1;
        for (int j = 1; j < REG_SIZE; j ++)
            champ[i]->registers[j] = 0;
        init_header(champ, i);
        for (int j = 0; j < 2; j ++)
            champ[i]->waittime[j] = 0;
        champ[i]->instruction = NULL;
        champ[i]->nbr_instruction = 0;
        champ[i]->program_counter = 0;
        champ[i]->carry = 1;
        champ[i]->idx = PROG_NAME_LENGTH + COMMENT_LENGTH + 16;
        champ[i]->player = 0;
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
    new->load_adress = -1;
    new->prog_number = -1;
    return new;
}

static
champions_t **buble_sort
(champions_t **c, size_t nbr_champions, input_t **input)
{
    champions_t *temp = NULL;
    input_t *input_temp = NULL;

    for (size_t i = 0; i + 1 != nbr_champions; i++) {
        if (c[i]->registers[0] > c[i + 1]->registers[0]) {
            temp = c[i];
            c[i] = c[i + 1];
            c[i + 1] = temp;
            input_temp = input[i];
            input[i] = input[i + 1];
            input[i + 1] = input_temp;
        }
    }
    return c;
}

static
void init_player(corewar_t *c)
{
    int count = 1;

    for (size_t i = 0; c->nbr_champions != i; i++) {
        if (c->input[i]->prog_number == -1 || count == c->input[i]->
        prog_number) {
            c->champions[i]->registers[0] = count;
            count++;
        } else
            c->champions[i]->registers[0] = c->input[i]->prog_number;
    }
    c->champions = buble_sort(c->champions, c->nbr_champions, c->input);
}

static
void init_execution_var(corewar_t *c)
{
    c->winner = -1;
    c->nbr_live = 0;
    c->cycle_to_die = CYCLE_TO_DIE;
}

void init_call_and_champ(corewar_t *c)
{
    c->live_call = malloc(sizeof(size_t) * c->nbr_champions);
    c->status_champ = malloc(sizeof(bool) * c->nbr_champions);
    for (size_t i = 0; i < c->nbr_champions; i ++) {
        c->live_call[i] = 0;
        c->status_champ[i] = true;
    }
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
    init_player(c);
    init_execution_var(c);
    init_call_and_champ(c);
    return c;
}
