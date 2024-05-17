/*
** EPITECH PROJECT, 2024
** display
** File description:
** display_champions
*/

#include "my.h"

#include <stdio.h>

void display_champions(champions_t *champion)
{
    my_printf("%s\n", champion->header.prog_name);
    my_printf("%s\n", champion->header.comment);
    my_printf("%d\n", champion->header.prog_size);
    my_printf("%d\n", champion->header.magic);
}
