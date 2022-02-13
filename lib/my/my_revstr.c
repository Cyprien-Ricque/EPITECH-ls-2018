/*
** EPITECH PROJECT, 2018
** my_revstr
** File description:
** my_revstr
*/

#include "../../include/my.h"

char *my_revstr(char *str)
{
    int c = my_strlen(str);
    int i = 0;
    char str2[c + 1];

    for (int j = (c - 1); i <= (c - 1); i++, j--) {
        str2[i] = str[j];
    }
    str2[i] = '\0';
    str = my_strdup(str2);
    return (str);
}
