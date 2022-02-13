/*
** EPITECH PROJECT, 2018
** my_putss
** File description:
** my_putss
*/

#include "../../include/my.h"

void my_putss(char **ss)
{
    for (int i = 0; i < my_sslen(ss); i++) {
        my_putstr(ss[i]);
        my_putchar('\n');
    }
}
