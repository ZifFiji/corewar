/*
** EPITECH PROJECT, 2024
** display
** File description:
** display_memory
*/

#include "my.h"

#include <stdint.h>
#include <stdio.h>

void display_memory(uint8_t *arena)
{
    int j = 0;

    for (int i = 0; i < MEM_SIZE; i ++) {
        if (arena[i] > 15) {
            printf("%x ", arena[i]);
        } else {
            printf("%x%x ", arena[i], arena[i + 1]);
            i += 1;
        }
        j += 2;
        if (j == 32) {
            j = 0;
            printf("\n");
        }
    }
}
