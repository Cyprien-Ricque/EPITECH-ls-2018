/*
** EPITECH PROJECT, 2018
** scan
** File description:
** scan
*/

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../../include/my_printf.h"

int spe_scan(char *str, int val)
{
    int i = val;

    while (str[i] != '%')
        --i;
    while (i != val && (my_char_isnum(str[i]) == 0 || str[i] == '0')) {
        if (str[i] == '0')
            return (1);
        i++;
    }
    return (0);
}

int ez_scan(char *str, int pos, char to_find)
{
    for (int i = pos; str[i] != '%'; i--) {
        if (str[i] == to_find)
            return (1);
    }
    return (0);
}

int diez_scan(char *str, int val)
{
    if (ez_scan(str, val, '#') == 1 || str[val] == 'p') {
        if (str[val] == 'x' || str[val] == 'X' || str[val] == 'p')
            return (2);
        if (str[val] == 'o')
            return (1);
    }
    return (0);
}

int initialisation(long *nb, char *str, int val)
{
    int value = -1;
    int i = val;
    int mem = 0;

    if (*nb < 0)
        *nb = *nb * -1;
    while (str[i] != '%')
        i = i - 1;
    while (i != val && mem == 0) {
        if (my_char_isnum(str[i]) == 1 && str[i] != '0') {
            value = my_getlnbr(str, i);
            mem = 1;
        }
        i++;
    }
    return (value);
}

int scan(char *str, int val, long nb, int base)
{
    int value;
    long nbbis = nb;

    value = initialisation(&nb, str, val);
    if (value == -1)
        return (0);
    value -= my_strlen(my_retbasenbr(nb, base));
    if (base == 10 &&
        (ez_scan(str, val, '+') == 1 || ez_scan(str, val, ' ') == 1 ||
            nbbis < 0) && (str[val] == 'd' || str[val] == 'i'))
        value--;
    value -= diez_scan(str, val);
    if (str[val] == 'p' &&
        (ez_scan(str, val, '+') == 1 || ez_scan(str, val, ' ') == 1))
        return (value - 1);
    return (value);
}
