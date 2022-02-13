/*
** EPITECH PROJECT, 2018
** st_flags
** File description:
** st_flags
*/

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../../include/my_printf.h"

int st_scan(int val, char *str, char *strtp)
{
    int i = val;
    int value = -1;

    while (str[i] != '%')
        i = i - 1;
    while (i != val) {
        if (my_char_isnum(str[i]) == 1 && str[i] != '0')
            value = my_getlnbr(str, i);
        i++;
    }
    if (value == -1)
        return (0);
    value -= my_strlen(strtp);
    return (value);
}

int st_flags(int val, char *str, char *strtp)
{
    int to_add = st_scan(val, str, strtp);

    if (ez_scan(str, val, '-') == 0 && to_add > 0) {
        while (to_add > 0) {
            my_putchar(' ');
            to_add--;
        }
    }
    return (to_add);
}
