/*
** EPITECH PROJECT, 2018
** my_getstrnbr
** File description:
** my_getstrnbr
*/

#include <unistd.h>
#include <stdlib.h>
#include "../../include/my.h"

char *my_getstrnbr(char const *str, int i, int base)
{
    char *nbrstr;
    int j = 0;

    nbrstr = malloc(sizeof(char) * (my_strlen(str) + 1));
    if (str[i] == '-') {
        nbrstr[j] = '-';
        i++;
        j++;
    }
    while ((my_char_isbase(str[i], base) == 1)) {
        nbrstr[j] = str[i];
        i++;
        j++;
    }
    nbrstr[j] = '\0';
    return (nbrstr);
}
