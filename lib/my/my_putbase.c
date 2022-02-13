/*
** EPITECH PROJECT, 2018
** my_put_basenbr
** File description:
** my_put_basenbr
*/

#include "../../include/my.h"
#include <stdio.h>
#include <stdlib.h>

void print(char *result, int nb_bis)
{
    if (nb_bis != 0)
        my_putstr(result);
    else
        my_putstr("0");
}

void my_put_basenbr(long long nb, int base)
{
    char *result = malloc(sizeof(char) * my_strlen(my_longtostr(nb)) + 2);
    long long nb_bis = nb;
    int i = 0;

    if (nb < 0)
        nb *= -1;
    while (nb != 0) {
        result[i] = (nb % base) + 48;
        if (result[i] > '9')
            result[i] += 39;
        nb = nb / base;
        ++i;
    }
    result[i] = 0;
    result = my_revstr(result);
    if (nb_bis < 0)
        result = add_cis(result, 0, "-");
    print(result, nb_bis);
}
