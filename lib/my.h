/*
** EPITECH PROJECT, 2024
** stumper
** File description:
** my.h
*/

#ifndef MY_H_
    #define MY_H_

void my_putchar(char c);
int my_strlen(char const *str);
int my_putstr(char const *str, int n);
char *my_strcpy(char *dest, char const *src);
char *my_strdup(char const *src);
int my_intlen(int long nb);
char *my_strcat(char *dest, char const *str);
int my_char_is_alpha(char const c);
int my_isdigit(char c);
int my_intlen_float(double nb);
int my_putpointer(long long int ptr);
int my_putexposant(double e, int precision);
int my_put_nbr(int nb);
int my_put_nbr_base(long long int nb, int base);
int my_put_nbr_basemaj(long long int nb, int base);
int my_putfloat(double nb, int flags);

#endif
