/*
** EPITECH PROJECT, 2024
** B-CPE-101-BDX-1-1-myprintf-aaron.groux
** File description:
** my_putpointer.c
*/

#include "my.h"

int my_putpointer(long long int ptr)
{
    my_putstr("0x", 1);
    my_put_nbr_base(ptr, 16);
    return 0;
}
