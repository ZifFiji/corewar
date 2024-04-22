/*
** EPITECH PROJECT, 2024
** tests
** File description:
** tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my.h"

Test(unit_test, return_success)
{
    cr_assert_eq(0, corewar());
}
