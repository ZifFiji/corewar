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
    printf("%s\n", champion->header.prog_name);
    printf("%s\n", champion->header.comment);
    printf("%d\n", champion->header.prog_size);
    printf("%d\n", champion->header.magic);
}
