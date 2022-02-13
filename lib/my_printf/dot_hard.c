/*
** EPITECH PROJECT, 2018
** dot_hard
** File description:
** dot_hard
*/

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../../include/my_printf.h"

int find_spaces_nb(char *str, int val)
{
    int i = val;
    int value = -1;

    while (str[i] != '%')
        i--;
    while (value == -1 && str[i] != '.') {
        if (my_char_isnum(str[i]) == 1 && (str[i] != '0' || str[i + 1] == '.'))
            value = my_getlnbr(str, i);
        i++;
    }
    return (value);
}

int find_zero_nb(char *str, int val)
{
    int i = val;
    int value = -1;

    while (str[i] != '.')
        i--;
    while (value == -1 && str[i] != '\0') {
        if (my_char_isnum(str[i]) == 1)
            value = my_getlnbr(str, i);
        i++;
    }
    return (value);
}

int pos_neg_scan(long long nb, char *str, int val)
{
    if (nb > 0 && (str[val] == 'd' || str[val] == 'i')
        && ez_scan(str, val, '+') == 1)
        return (1);
    if (nb < 0 && (str[val] == 'd' || str[val] == 'i'))
        return (1);
    if (nb > 0 && (str[val] == 'd' || str[val] == 'i')
        && ez_scan(str, val, ' ') == 1 && ez_scan(str, val, '+') == 0)
        return (1);
    return (0);
}

int dot_zero(long long nb, char *str, int val, int base)
{
    int value = find_zero_nb(str, val);

    value -= my_strlen(my_retbasenbr(nb, base));
    if (value < 0)
        value = 0;
    return (value);
}

int dot_spaces(long long nb, char *str, int val, int base)
{
    int value = find_spaces_nb(str, val);

    value -= diez_scan(str, val);
    value -= pos_neg_scan(nb , str, val);
    value -= dot_zero(nb, str, val, base);
    value -= my_strlen(my_retbasenbr(nb, base));
    if (value < 0)
        value = 0;
    return (value);
}
