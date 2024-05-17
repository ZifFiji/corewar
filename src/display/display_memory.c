/*
** EPITECH PROJECT, 2024
** display
** File description:
** display_memory
*/

#include "my.h"

#include <stdint.h>

void display_memory(uint8_t *arena)
{
    int j = 0;

    for (int i = 0; i < MEM_SIZE; i ++) {
        if (arena[i] < 15) {
            my_printf("0%x ", arena[i]);
        } else {
            my_printf("%x ", arena[i]);
        }
        j += 2;
        if (j % 64 == 0) {
            my_putchar('\n');
        }
    }
    my_putchar('\n');
}
