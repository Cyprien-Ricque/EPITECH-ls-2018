/*
** EPITECH PROJECT, 2018
** pointer
** File description:
** pointer
*/

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../../include/my_printf.h"

void pointeur(char *str, int val)
{
    if (ez_scan(str, val, '+') == 1 && str[val] == 'p')
        my_putchar('+');
    if (ez_scan(str, val, '+') == 0 && str[val] == 'p' &&
        ez_scan(str, val, ' ') == 1)
        my_putchar(' ');
}