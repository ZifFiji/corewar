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

int corewar(int ac, char **av, char **env);
void display_help(void);

// LIBRARY

int my_strcmp(char const *s1, char const *s2);
int my_putstr(char const *str, int n);

#endif /* MY_H */
