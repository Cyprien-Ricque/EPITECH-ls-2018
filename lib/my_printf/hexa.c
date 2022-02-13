/*
** EPITECH PROJECT, 2018
** hex_a
** File description:
** hex_a
*/

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../../include/my_printf.h"

int hexa(va_list ap, int val, char *str)
{
    unsigned int nb = va_arg(ap, unsigned int);
    int to_add = the_choice(nb, str, val, 16);

    my_put_ubasenbr(nb, 16);
    while (to_add > 0) {
        my_putchar(' ');
        to_add--;
    }
    return (0);
}

int lhexa(va_list ap, int val, char *str)
{
    unsigned long nb = va_arg(ap, unsigned long int);
    int to_add = the_choice(nb, str, val, 16);

    my_put_lubasenbr(nb, 16);
    while (to_add > 0) {
        my_putchar(' ');
        to_add--;
    }
    return (0);
}

int llhexa(va_list ap, int val, char *str)
{
    unsigned long long nb = va_arg(ap, unsigned long long);
    int to_add = the_choice(nb, str, val, 16);

    my_put_llubasenbr(nb, 16);
    while (to_add > 0) {
        my_putchar(' ');
        to_add--;
    }
    return (0);
}

int hhexa(va_list ap, int val, char *str)
{
    unsigned short int nb = va_arg(ap, int);
    int to_add = the_choice(nb, str, val, 16);
    my_put_hubasenbr(nb, 16);
    while (to_add > 0) {
        my_putchar(' ');
        to_add--;
    }
    return (0);
}

int hhhexa(va_list ap, int val, char *str)
{
    unsigned char nb2 = va_arg(ap, unsigned int);
    int nb = (int)nb2;
    int to_add = the_choice(nb, str, val, 16);

    my_put_ubasenbr(nb, 16);
    while (to_add > 0) {
        my_putchar(' ');
        to_add--;
    }
    return (0);
}
