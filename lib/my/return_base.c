/*
** EPITECH PROJECT, 2018
** my_put_basenbr
** File description:
** my_put_basenbr
*/

#include "../../include/my.h"
#include <stdio.h>
#include <stdlib.h>

char *rev_str(char *str)
{
    char str_bis[my_strlen(str)];
    int i = 0;

    while (str[i] >= '0' && str[i] <= '9') {
        str_bis[i] = str[i];
        ++i;
    }
    str_bis[i] = 0;
    for (int j = 0; j < i; ++j)
        str[j] = str_bis[i - j - 1];
    str[i] = 0;
    return (str);
}

char *return_base(long long nb, int base)
{
    char *result = malloc(sizeof(char) * 50);
    long long nb_bis = nb;
    int i;

    if (nb < 0)
        nb *= -1;
    for (i = 0; nb > 0; i++) {
        result[i] = (nb % base) + 48;
        if (result[i] > '9')
            result[i] += 39;
        nb = nb / base;
    }
    result[i] = 0;
    result = rev_str(result);
    if (nb_bis < 0)
        result = add_cis(result, 0, "-");
    if (nb_bis == 0)
        return ("0");
    return (result);
}
