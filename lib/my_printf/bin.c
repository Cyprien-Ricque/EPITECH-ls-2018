/*
** EPITECH PROJECT, 2018
** binary
** File description:
** binary
*/

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../../include/my_printf.h"

int bin(va_list ap, int val, char *str)
{
    unsigned int nb = va_arg(ap, unsigned int);
    int to_add = the_choice(nb, str, val, 2);

    my_put_ubasenbr(nb, 2);
    while (to_add > 0) {
        my_putchar(' ');
        to_add--;
    }
    return (0);
}

int lbin(va_list ap, int val, char *str)
{
    unsigned long int nb = va_arg(ap, long unsigned int);
    int to_add = the_choice(nb, str, val, 2);

    my_put_lubasenbr(nb, 2);
    while (to_add > 0) {
        my_putchar(' ');
        to_add--;
    }
    return (0);
}

int llbin(va_list ap, int val, char *str)
{
    unsigned long long nb = va_arg(ap, unsigned long long);
    int to_add = the_choice(nb, str, val, 2);

    my_put_llubasenbr(nb, 2);
    while (to_add > 0) {
        my_putchar(' ');
        to_add--;
    }
    return (0);
}

int hbin(va_list ap, int val, char *str)
{
    unsigned short int nb = va_arg(ap, int);
    int to_add = the_choice(nb, str, val, 2);

    my_put_hubasenbr(nb, 2);
    while (to_add > 0) {
        my_putchar(' ');
        to_add--;
    }
    return (0);
}

int hhbin(va_list ap, int val, char *str)
{
    unsigned char nb2 = va_arg(ap, unsigned int);
    int nb = (int)nb2;
    int to_add = the_choice(nb, str, val, 2);

    my_put_ubasenbr(nb, 2);
    while (to_add > 0) {
        my_putchar(' ');
        to_add--;
    }
    return (0);
}
