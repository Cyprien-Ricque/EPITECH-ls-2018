/*
** EPITECH PROJECT, 2018
** my_strtoss
** File description:
** my_strtoss
*/

#include <unistd.h>
#include <stdlib.h>
#include "../../include/my_printf.h"

int sharing(char **ss, int i, int pos, int base)
{
    if ((my_char_isbase(ss[0][pos], base) == 1) ||
        (ss[0][pos] == '-' && my_char_isbase(ss[0][pos + 1], base) == 1
        && (i == 0 || my_char_isbase(ss[0][pos - 1], base) != 1))) {
        ss[i] = my_getstrnbr(ss[0], pos, base);
        pos = pos + (my_strlen(ss[i]));
    } else {
        ss[i][0] = ss[0][pos];
        ss[i][1] = '\0';
        pos += 1;
    }
    return (pos);
}

char **my_strtoss(char *str, int base)
{
    char **ss;
    int pos = 0;
    int i;

    ss = malloc(sizeof(char *) * (my_strlen(str) + 4));
    ss[0] = malloc(sizeof(char) * 11);
    ss[0] = str;
    if (ss == NULL)
        return (NULL);
    for (i = 1; ss[0][pos] != '\0'; i++) {
        ss[i] = malloc(sizeof(char) * (my_strlen(ss[0])));
        if (ss[i] == NULL)
            return (NULL);
        pos = sharing(ss, i, pos, base);
    }
    ss[i] = NULL;
    delete_siss(ss, 0, 1);
    return (ss);
}
