/*
** EPITECH PROJECT, 2018
** int functions
** File description:
** int functions
*/

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../../include/my_printf.h"

int in_t(va_list ap, int val, char *str)
{
    int nb = va_arg(ap, int);
    int to_add = the_choice(nb, str, val, 10);

    nb = nb < 0 ? -nb : nb;
    my_put_basenbr(nb, 10);
    while (to_add > 0) {
        my_putchar(' ');
        to_add--;
    }
    return (0);
}

int lin_t(va_list ap, int val, char *str)
{
    long int nb = va_arg(ap, long int);
    int to_add = the_choice(nb, str, val, 10);

    nb = nb < 0 ? -nb : nb;
    my_put_lbasenbr(nb, 10);
    while (to_add > 0) {
        my_putchar(' ');
        to_add--;
    }
    return (0);
}

int llin_t(va_list ap, int val, char *str)
{
    long long nb = va_arg(ap, long long);
    int to_add;

    to_add = the_choice(nb, str, val, 10);
    nb = nb < 0 ? -nb : nb;
    my_put_llbasenbr(nb, 10);
    while (to_add > 0) {
        my_putchar(' ');
        to_add--;
    }
    return (0);
}

int hin_t(va_list ap, int val, char *str)
{
    short int nb = va_arg(ap, int);
    int to_add = the_choice(nb, str, val, 10);

    nb = nb < 0 ? -nb : nb;
    my_put_hbasenbr(nb, 10);
    while (to_add > 0) {
        my_putchar(' ');
        to_add--;
    }
    return (0);
}

int hhin_t(va_list ap, int val, char *str)
{
    char nb2 = va_arg(ap, int);
    int nb = (int)nb2;
    int to_add;

    to_add = the_choice(nb, str, val, 10);
    nb = nb < 0 ? -nb : nb;
    my_put_basenbr(nb, 10);
    while (to_add > 0) {
        my_putchar(' ');
        to_add--;
    }
    return (0);
}
