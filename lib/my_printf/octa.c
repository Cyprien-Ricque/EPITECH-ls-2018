/*
** EPITECH PROJECT, 2018
** octa
** File description:
** octa
*/

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../../include/my_printf.h"

int octa(va_list ap, int val, char *str)
{
    unsigned int nb = va_arg(ap, unsigned int);
    int to_add = the_choice(nb, str, val, 8);

    my_put_ubasenbr(nb, 8);
    while (to_add > 0) {
        my_putchar(' ');
        to_add--;
    }
    return (0);
}

int locta(va_list ap, int val, char *str)
{
    unsigned long int nb = va_arg(ap, unsigned long int);
    int to_add = the_choice(nb, str, val, 8);

    my_put_lubasenbr(nb, 8);
    while (to_add > 0) {
        my_putchar(' ');
        to_add--;
    }
    return (0);
}

int llocta(va_list ap, int val, char *str)
{
    unsigned long long nb = va_arg(ap, unsigned long long);
    int to_add = the_choice(nb, str, val, 8);

    my_put_llubasenbr(nb, 8);
    while (to_add > 0) {
        my_putchar(' ');
        to_add--;
    }
    return (0);
}

int hocta(va_list ap, int val, char *str)
{
    unsigned short int nb = va_arg(ap, unsigned int);
    int to_add = the_choice(nb, str, val, 8);

    my_put_hubasenbr(nb, 8);
    while (to_add > 0) {
        my_putchar(' ');
        to_add--;
    }
    return (0);
}

int hhocta(va_list ap, int val, char *str)
{
    unsigned char nb2 = va_arg(ap, unsigned int);
    unsigned int nb = (int)nb2;
    int to_add = the_choice(nb, str, val, 8);

    my_put_ubasenbr(nb, 8);
    while (to_add > 0) {
        my_putchar(' ');
        to_add--;
    }
    return (0);
}
