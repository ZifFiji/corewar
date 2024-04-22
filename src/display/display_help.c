/*
** EPITECH PROJECT, 2024
** display
** File description:
** display_help
*/

#include "my.h"

void display_help(void)
{
    my_putstr("USAGE\n./corewar [-dump nbr_cycle] [[-n prog_number]", 1);
    my_putstr(" [-a load_address] prog_name] ...\n", 1);
    my_putstr("DESCRIPTION\n-dump nbr_cycle dumps the memory after the ", 1);
    my_putstr("nbr_cycle execution (if the round isn’t\n", 1);
    my_putstr("already over) with the following format: 32 bytes/line in ", 1);
    my_putstr("hexadecimal (A0BCDEFE1DD3...)\n-n prog_number", 1);
    my_putstr(" sets the next program’s number. By default,", 1);
    my_putstr(" the first free number in the\nparameter order\n", 1);
    my_putstr("-a load_address sets the next program’s loading address.", 1);
    my_putstr("When no address is specified,\noptimize the addresses ", 1);
    my_putstr("so that the processes are as far away from each other ", 1);
    my_putstr("as\npossible. The addresses are MEM_SIZE modulo.\n", 1);
}
