/*
** EPITECH PROJECT, 2023
** constant
** File description:
** ez
*/
#include <stddef.h>
#include <stdarg.h>

#ifndef MY_CONSTENT_H_
    #define MY_CONSTENT_H_
int my_printfchar(va_list *list);
int my_printstr(va_list *list);
int my_printint(va_list *list);
int my_printx(va_list *list);
int my_printmajx(va_list *list);
int my_printu(va_list *list);
int my_printo(va_list *list);
int my_printpercent(va_list *list);
int my_printfloat(va_list *list);
int my_printpointer(va_list *list);
int my_printexposant(va_list *list);
char const all_flags[] = "idcsxXuo%fpe";

void my_putchar(char c);

typedef struct {
    char flag;
    int (*ptr) (va_list *);
} display_t;

static const display_t display_array[] = {
    {.flag = 'd', .ptr = &my_printint},
    {.flag = 'i', .ptr = &my_printint},
    {.flag = 'c', .ptr = &my_printfchar},
    {.flag = 's', .ptr = &my_printstr},
    {.flag = 'x', .ptr = &my_printx},
    {.flag = 'X', .ptr = &my_printmajx},
    {.flag = 'u', .ptr = &my_printu},
    {.flag = 'o', .ptr = &my_printo},
    {.flag = '%', .ptr = &my_printpercent},
    {.flag = 'f', .ptr = &my_printfloat},
    {.flag = 'p', .ptr = &my_printpointer},
    {.flag = 'e', .ptr = &my_printexposant},
    {.flag = '\0', .ptr = NULL}
};
#endif /*MY_CONSTENT_H_*/
