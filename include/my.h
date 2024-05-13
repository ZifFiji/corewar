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
    size_t coding_byte;
    char **parameters;
} instructions_t;

typedef struct champions_s {
    instructions_t **instruction;
    size_t nbr_instruction;
    header_t header;
    int idx;
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
    int nbr_dump_cycles;
    champions_t **champions;
    input_t **input;
} corewar_t;

int corewar(int ac, char **av, char **env);

// PARSER
champions_t **parse_files(corewar_t *corewar, input_t **input);
input_t **parser_input(corewar_t *c, char **raw_input);

// INITIALISATION
champions_t **init_champion(size_t nbr_champions);
instructions_t *init_instruction(void);
corewar_t *init_corewar(char **raw_input);
input_t *init_input(void);

// DISPLAY
void display_help(void);
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
char *my_strndup(char const *src, int n);

#endif /* MY_H */
