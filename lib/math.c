/*
** EPITECH PROJECT, 2024
** robotfactory
** File description:
** math.c
*/

int my_compute_power_rec(int nb, int p)
{
    int result = nb;

    if (p == 0)
        return (1);
    if (p < 0 || result < 0)
        return (0);
    result = nb * my_compute_power_rec(nb, p - 1);
    return (result);
}
