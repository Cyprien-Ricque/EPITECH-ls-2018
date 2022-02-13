/*
** EPITECH PROJECT, 2018
** my_inttostr
** File description:
** my_inttostr
*/

#include "../../include/my.h"
#include <stdlib.h>

static char *longtostr(long nb, int count, char *result, int ng)
{
    long tmp = nb;
    long i;

    for (i = 0; i < count; i++) {
        tmp = nb % 10;
        result[i] = tmp + 48;
        nb = nb / 10;
    }
    result[i] = '\0';
    if (ng == 1) {
        result[i] = '-';
        result[i + 1] = '\0';
    }
    result = my_revstr(result);
    return (result);
}

char *my_longtostr(long nb)
{
    long count = 1;
    char *result;
    long nb2;
    int ng = 0;

    if (nb < 0) {
        nb = nb * -1;
        ng = 1;
    }
    nb2 = nb;
    while (nb2 >= 10) {
        nb2 = nb2 / 10;
        count++;
    }
    result = malloc(sizeof(char) * (count + 2));
    result = longtostr(nb, count, result, ng);
    return (result);
}
