/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** my_printf
*/

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../../include/my_printf.h"

static const char flag_base[44] = "dddddiiiiiooooouuuuuxxxxxXXXXXbbbbbcsp%Slhq";

static const char flag_ebase[32] = "diouxXbbcsp%Slhq+-#. 0123456789";

int (*function_base[40])(va_list ap, int val, char *str) = {in_t, lin_t, llin_t,
    hin_t, hhin_t, in_t, lin_t, llin_t, hin_t, hhin_t, octa, locta, llocta,
    hocta, hhocta, usd, lusd, llusd, husd, hhusd, hexa, lhexa, llhexa, hhexa,
    hhhexa, hexam, lhexam, llhexam, hhexam, hhhexam, bin, lbin, llbin, hbin,
    hhbin, cha_r, strin_g, pointe_r, nothin_g, spestrin_g};

int unknown_flag(char *str, int *i)
{
    int c = 0;
    int icpy = *i;

    while (str[icpy] != flag_ebase[c]) {
        if (c == my_strlen(flag_ebase))
            return (84);
        c++;
        if ((str[icpy] == 'h' || str[icpy] == 'l' || str[icpy] == 'q') &&
            str[icpy + 1] != '\0') {
            icpy++;
            c = 0;
        }
        if ((str[icpy] == 'h' || str[icpy] == 'l' || str[icpy] == 'q') &&
            str[icpy + 1] == '\0') {
            return (84);
        }
    }
    return (0);
}

int hredirection(char *str, int *i)
{
    int a = 0;

    *i += 1;
    while (str[*i] != flag_base[a] && a <= my_strlen(flag_base)) {
        a++;
    }
    if (flag_base[a] == 'h') {
        *i += 1;
        a = 0;
        while (str[*i] != flag_base[a] && a <= my_strlen(flag_base)) {
            a++;
        }
        return (a + 4);
    }
    return (a + 3);
}

int lredirection(char *str, int *i)
{
    int a = 0;

    *i += 1;
    while (str[*i] != flag_base[a] && a <= my_strlen(flag_base)) {
        a++;
    }
    if (flag_base[a] == 'q')
        return (a + 1);
    if (flag_base[a] == 'l') {
        a = 0;
        *i += 1;
        while (str[*i] != flag_base[a] && a <= my_strlen(flag_base)) {
            a++;
        }
        return (a + 2);
    }
    return (a + 1);
}

int redirection(char *str, int *i, va_list *ap)
{
    int a = 0;
    int icpy = *i;

    while (str[*i] != flag_base[a]) {
        *i = *i + 1;
        if (unknown_flag(str, i) == 84) {
            *i = icpy;
            return (84);
        }
        a = 0;
        while (str[*i] != flag_base[a] && a != my_strlen(flag_base))
            a++;
    }
    if (flag_base[a] == 'l' || flag_base[a] == 'q')
        a = lredirection(str, i);
    if (flag_base[a] == 'h')
        a = hredirection(str, i);
    return (function_base[a](*ap, *i, str));
}

int my_printf(char *str, ...)
{
    va_list ap;
    int tmp;

    va_start(ap, str);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '%') {
            tmp = redirection(str, &i, &ap);
            if (tmp == 84)
                my_putchar('%');
        } else
            my_putchar(str[i]);
    }
    va_end(ap);
    return (0);
}
