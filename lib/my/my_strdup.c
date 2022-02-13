/*
** EPITECH PROJECT, 2018
** my_strdup
** File description:
** my_strdup
*/

#include <stdlib.h>
#include "../../include/my.h"

char *my_strdup(char const *src)
{
    char *str;
    int i;
    int c = 0;

    i = my_strlen(src);
    str = malloc(sizeof(char) * (i + 2));
    while (c < i) {
        str[c] = src[c];
        c++;
    }
    str[i] = '\0';
    return (str);
}
