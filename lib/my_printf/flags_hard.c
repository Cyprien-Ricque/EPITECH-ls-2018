/*
** EPITECH PROJECT, 2018
** print_flag_four
** File description:
** print_flag_four
*/

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../../include/my_printf.h"

int zero(long long nb, char *str, int val, int to_add)
{
    if (spe_scan(str, val) == 1 && ez_scan(str, val, '-') == 0) {
        while (to_add > 0) {
            to_add--;
            my_putchar('0');
        }
    }
    return (to_add);
}

int die_z(long long nb, char *str, int val, int to_add)
{
    if (ez_scan(str, val, '#') == 1 && (str[val] == 'x'))
        my_putstr("0x");
    if (ez_scan(str, val, '#') == 1 && (str[val] == 'X'))
        my_putstr("0X");
    if (ez_scan(str, val, '#') == 1 && (str[val] == 'o'))
        my_putstr("0");
    return (0);
}

int space_minus(char *str, int val, long long nb, int base)
{
    if (nb >= 0 && ez_scan(str, val, '+') == 0 && ez_scan(str, val, ' ') == 1
        && base == 10 && (str[val] == 'd' || str[val] == 'i'))
        my_putchar(' ');
    if (nb < 0) {
        nb = nb * 1;
        my_putchar('-');
    }
    return (nb);
}

int space_plus(long long nb, char *str, int val, int base)
{
    int to_add = scan(str, val, nb, base);

    if (nb < 0 && str[val] != 'd' && str[val] != 'i')
        nb = -nb;
    if (to_add > 0 && ez_scan(str, val, '-') == 0 && spe_scan(str, val) == 0) {
        while (to_add != 0) {
            to_add--;
            my_putchar(' ');
        }
    }
    pointeur(str, val);
    die_z(nb, str, val, to_add);
    if (str[val] == 'p')
        my_putstr("0x");
    if (nb >= 0 && ez_scan(str, val, '+') == 1 && base == 10
        && (str[val] == 'd' || str[val] == 'i'))
        my_putchar('+');
    nb = space_minus(str, val, nb, base);
    zero(nb, str, val, to_add);
    return (to_add);
}

int spestrin_g(va_list ap, int val, char *str)
{
    char *str_b = va_arg(ap, char *);

    for (int i = 0; str_b[i] != '\0'; i++) {
        if (str_b[i] < 8) {
            my_putstr("\\00");
            my_put_basenbr(str_b[i], 8);
        }
        if (str_b[i] >= 8 && str_b[i] < 33) {
            my_putstr("\\0");
            my_put_basenbr(str_b[i], 8);
        }
        if (str_b[i] > 126) {
            my_putchar('\\');
            my_put_basenbr(str_b[i], 8);
        }
        if (str_b[i] > 32 && str_b[i] < 127)
            my_putchar(str_b[i]);
    }
    return (0);
}
