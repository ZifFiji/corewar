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
    #include <stdbool.h>

    #include "op.h"

typedef struct instructions_s {
    uint8_t instruction;
    int *parameters;
    int *type;
    int nbr_params;
    size_t coding_byte;
} instructions_t;

typedef struct champions_s {
    instructions_t **instruction;
    size_t nbr_instruction;
    header_t header;
    uint8_t registers[REG_NUMBER];
    int idx;
    int waittime[2];
    size_t program_counter;
    size_t carry;
} champions_t;

typedef struct input_s {
    char *file_path;
    int prog_number;
    int load_adress;
} input_t;

typedef struct corewar_s {
    uint8_t arena[MEM_SIZE];
    uint8_t padding[MEM_SIZE];
    size_t nbr_champions;
    int nbr_dump_cycles;
    champions_t **champions;
    size_t *live_call;
    bool *status_champ;
    input_t **input;
    int winner;
    size_t nbr_live;
    size_t cycle_to_die;
} corewar_t;

// COREWAR
int corewar(int ac, char **av, char **env);
int execution_corewar(corewar_t *);

// PARSER
champions_t **parser_files(corewar_t *corewar, input_t **input);
input_t **parser_input(corewar_t *c, char **raw_input);
void get_type_param(const char *size, champions_t *c);
int get_params(champions_t *c, int count_params, char const *file);
int write_param_ind(const char *file, champions_t *c, int j);
int write_param_dir(const char *file, champions_t *c, int j);

// INITIALISATION
champions_t **init_champion(size_t nbr_champions);
instructions_t *init_instruction(void);
corewar_t *init_corewar(char **raw_input);
input_t *init_input(void);
int init_params(champions_t *c, int count_params);

//ARENA
int padding(corewar_t *corewar, champions_t **c);
int arena(champions_t **c, corewar_t *corewar);
int check_mnemonique(uint8_t mnemo);
char *int_to_bin(size_t coding_byte);
int count_params(const char *size);
int *get_args_arena(champions_t *c, uint8_t *arena, size_t nbr_args, int *args);

// DISPLAY
void display_help(void);
void display_memory(uint8_t *arena);
void display_champions(champions_t *champion);
void display_instructions(champions_t *c);
void display_winner(int player, corewar_t *c);

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
int my_put_nbr_base(int nb, const char *base);
void my_putchar(char c);
char *my_revstr(char *str);
char *convert_int_to_hexa(int number, int size);
char *put_zero(char *hexa, int base);
int my_printf(const char *format, ...);

#endif /* MY_H */
