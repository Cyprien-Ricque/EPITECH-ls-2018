/*
** EPITECH PROJECT, 2018
** dot
** File description:
** dot
*/

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../../include/my_printf.h"

void dot_plus_minus(long long nb, char *str, int val)
{
    if (nb > 0 && (str[val] == 'd' || str[val] == 'i')
        && ez_scan(str, val, '+') == 1)
        my_putchar('+');
    if (nb < 0 && (str[val] == 'd' || str[val] == 'i'))
        my_putchar('-');
    if (nb > 0 && (str[val] == 'd' || str[val] == 'i')
        && ez_scan(str, val, ' ') == 1 && ez_scan(str, val, '+') == 0)
        my_putchar(' ');
}

void dot_diez(char *str, int val)
{
    if (ez_scan(str, val, '#') == 1 && (str[val] == 'x'))
        my_putstr("0x");
    if (ez_scan(str, val, '#') == 1 && (str[val] == 'X'))
        my_putstr("0X");
    if (ez_scan(str, val, '#') == 1 && (str[val] == 'o'))
        my_putstr("0");
}

int dot_managment(long long nb, char *str, int val, int base)
{
    int zero = dot_zero(nb, str, val, base);
    int spaces = dot_spaces(nb, str, val, base);

    if (ez_scan(str, val, '-') == 0) {
        while (spaces > 0) {
            my_putchar(' ');
            spaces--;
        }
    }
    if (str[val] == 'p')
        my_putstr("0x");
    dot_diez(str, val);
    dot_plus_minus(nb, str, val);
    while (zero > 0) {
        my_putchar('0');
        zero--;
    }
    return (spaces);
}

int the_choice(long long nb, char *str, int val, int base)
{
    if (ez_scan(str, val, '.') == 1)
        return (dot_managment(nb, str, val, base));
    else
        return (space_plus(nb, str, val, base));
}
