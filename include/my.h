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
    #include <stddef.h>

    #include "op.h"

typedef struct instructions_s {
    char *instruction;
    char **parameters;
} instructions_t;

typedef struct champions_s {
    instructions_t *instruction;
    header_t header;
} champions_t;

typedef struct input_s {
    char *file_path;
    size_t prog_number;
    size_t load_adress;
} input_t;

typedef struct corewar_s {
    uint8_t arena[MEM_SIZE];
    uint8_t padding[MEM_SIZE];
    size_t nbr_champions;
    size_t nbr_dump_cycles;
    champions_t **champions;
    input_t **input;
} corewar_t;

int corewar(int ac, char **av, char **env);
void display_help(void);
champions_t **parse_files(corewar_t *corewar, input_t **input);
input_t **parser_input(corewar_t *c, char **raw_input);
champions_t **init_champion(size_t nbr_champions);
corewar_t *init_corewar(char **raw_input);
void display_champions(champions_t *champion);

// LIBRARY

int my_strlen(char const *str);
int my_isdigit(char c);
int my_getnbr(char *str);
char *my_strdup(char const *src);
int my_strcmp(char const *s1, char const *s2);
int my_putstr(char const *str, int n);
char *my_getbuff(char const *file);
char *my_strncpy(char *dest, char const *src, int n);

#endif /* MY_H */
