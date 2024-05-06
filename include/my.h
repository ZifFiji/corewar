/*
** EPITECH PROJECT, 2024
** include
** File description:
** my
*/

#ifndef MY_H
    #define MY_H

    #define SUCCESS 0
    #define ERROR 84

    #include <stdint.h>

    #include "op.h"

typedef struct corewar_s {
    uint8_t arena[MEM_SIZE];
} corewar_t;

int corewar(int ac, char **av, char **env);
void display_help(void);
int parser(char *file_path);

// LIBRARY

int my_strcmp(char const *s1, char const *s2);
int my_putstr(char const *str, int n);
char *my_getbuff(char const *file);

#endif /* MY_H */
