/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** hexa.c
*/

#include "../include/my.h"

#include <stdlib.h>
#include <stdio.h>

char *convert_int_to_hexa(int number, int size)
{
    char *hexa = NULL;
    int i = 0;
    int letter = 0;

    hexa = malloc(sizeof(char) * (size + 1));
    for (int j = 0; j != size; j++)
        hexa[j] = '0';
    hexa[size] = '\0';
    while (number != 0) {
        letter = number % 16;
        if (letter < 10) {
            hexa[i] = letter + '0';
        } else {
            hexa[i] = letter + 'a' - 10;
        }
        number /= 16;
        i++;
    }
    my_revstr(hexa);
    return hexa;
}
