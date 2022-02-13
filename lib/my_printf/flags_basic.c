/*
** EPITECH PROJECT, 2018
** print_flages_one
** File description:
** print_flags_one
*/

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../../include/my_printf.h"

int strin_g(va_list ap, int val, char *str)
{
    char *strtp = va_arg(ap, char *);
    int to_add = st_flags(val, str, strtp);

    my_putstr(strtp);
    while (to_add > 0) {
        my_putchar(' ');
        to_add--;
    }
    return (0);
}

int cha_r(va_list ap, int val, char *str)
{
    unsigned char strtp[2];
    int to_add;

    strtp[0] = va_arg(ap, int);
    strtp[1] = '\0';
    to_add = st_flags(val, str, strtp);
    my_putchar(strtp[0]);
    return (0);
}

int pointe_r(va_list ap, int val, char *str)
{
    unsigned long nb = va_arg(ap, unsigned long);
    int to_add = the_choice(nb, str, val, 16);

    my_put_llubasenbr(nb, 16);
    while (to_add > 0) {
        my_putchar(' ');
        to_add--;
    }
    return (0);
}

int nothin_g(va_list ap, int val, char *str)
{
    my_putchar('%');
    return (0);
}
