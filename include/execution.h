/*
** EPITECH PROJECT, 2024
** EXECUTION_H
** File description:
** execution
*/

#ifndef EXECUTION_H
    #define EXECUTION_H

    #define NBR_INSTRUCTION 15

    #include "my.h"
    #include <stdint.h>

typedef struct execution_s {
    uint8_t instructions;
    int (*fptr)(corewar_t *, champions_t *, size_t, int *);
} execution_t;

// EXECUTION FUNCTION
int execute_live(corewar_t *, champions_t *c, size_t nbr_player, int *args);
int execute_ld(corewar_t *, champions_t *c, size_t nbr_player, int *args);
int execute_st(corewar_t *, champions_t *c, size_t nbr_player, int *args);
int execute_add(corewar_t *, champions_t *c, size_t nbr_player, int *args);
int execute_sub(corewar_t *, champions_t *c, size_t nbr_player, int *args);
int execute_and(corewar_t *, champions_t *c, size_t nbr_player, int *args);
int execute_or(corewar_t *, champions_t *c, size_t nbr_player, int *args);
int execute_xor(corewar_t *, champions_t *c, size_t nbr_player, int *args);
int execute_zjmp(corewar_t *, champions_t *c, size_t nbr_player, int *args);
int execute_ldi(corewar_t *, champions_t *c, size_t nbr_player, int *args);
int execute_sti(corewar_t *, champions_t *c, size_t nbr_player, int *args);
int execute_fork(corewar_t *, champions_t *c, size_t nbr_player, int *args);
int execute_lld(corewar_t *, champions_t *c, size_t nbr_player, int *args);
int execute_lldi(corewar_t *, champions_t *c, size_t nbr_player, int *args);
int execute_lfork(corewar_t *, champions_t *c, size_t nbr_player, int *args);
int execute_aff(corewar_t *, champions_t *c, size_t nbr_player, int *args);

execution_t exec_tab[] = {
    {0, &execute_live},
    {1, &execute_ld},
    {2, &execute_st},
    {3, &execute_add},
    {4, &execute_sub},
    {5, &execute_and},
    {6, &execute_or},
    {7, &execute_xor},
    {8, &execute_zjmp},
    {9, &execute_ldi},
    {10, &execute_sti},
    {11, &execute_fork},
    {12, &execute_lld},
    {13, &execute_lldi},
    {14, &execute_lfork},
    {15, &execute_aff},
};

#endif /* EXECUTION_H */
