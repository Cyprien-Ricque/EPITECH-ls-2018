/*
** EPITECH PROJECT, 2018
** in_tb
** File description:
** in_tb
*/

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../../include/my_printf.h"

int usd(va_list ap, int val, char *str)
{
    unsigned int nb = va_arg(ap, unsigned int);
    int to_add = the_choice(nb, str, val, 10);

    my_put_ubasenbr(nb, 10);
    while (to_add > 0) {
        my_putchar(' ');
        to_add--;
    }
    return (0);
}

int lusd(va_list ap, int val, char *str)
{
    unsigned long int nb = va_arg(ap, unsigned long int);
    int to_add = the_choice(nb, str, val, 10);

    nb = nb < 0 ? -nb : nb;
    my_put_lubasenbr(nb, 10);
    while (to_add > 0) {
        my_putchar(' ');
        to_add--;
    }
    return (0);
}

int llusd(va_list ap, int val, char *str)
{
    unsigned long long nb = va_arg(ap, unsigned long long);
    int to_add = the_choice(nb, str, val, 10);

    nb = nb < 0 ? -nb : nb;
    my_put_llubasenbr(nb, 10);
    while (to_add > 0) {
        my_putchar(' ');
        to_add--;
    }
    return (0);
}

int husd(va_list ap, int val, char *str)
{
    short unsigned int nb = va_arg(ap, unsigned int);
    int to_add = the_choice(nb, str, val, 10);

    my_put_hubasenbr(nb, 10);
    while (to_add > 0) {
        my_putchar(' ');
        to_add--;
    }
    return (0);
}

int hhusd(va_list ap, int val, char *str)
{
    unsigned char nb2 = va_arg(ap, unsigned int);
    unsigned int nb = (int)nb2;
    int to_add = the_choice(nb, str, val, 10);

    my_put_ubasenbr(nb, 10);
    while (to_add > 0) {
        my_putchar(' ');
        to_add--;
    }
    return (0);
}
