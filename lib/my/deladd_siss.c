/*
** EPITECH PROJECT, 2018
** deladd_ciss
** File description:
** delete/add string in array
*/

#include "../../include/my.h"
#include <unistd.h>
#include <stdlib.h>

void delete_siss(char **ss, int pos, int const n)
{
    while (ss[pos + n] != NULL) {
        ss[pos] = ss[pos + n];
        pos++;
    }
    ss[pos] = NULL;
}

char **add_siss(char **ss, int pos, char *to_add)
{
    int len = my_sslen(ss);
    int ta_len = my_strlen(to_add);
    int j = 0;
    char **dest = malloc(sizeof(char *) * (len + ta_len + 1));

    for (int m = 0; m < (len + ta_len); m++)
        dest[m] = malloc(sizeof(char) * (len + ta_len + 1));
    for (int i = 0; i < pos; i++, j++)
        dest[j] = ss[i];
    for (int i = 0; i < ta_len; i++, j++)
        dest[pos][i] = to_add[i];
    dest[pos][ta_len] = '\0';
    for (int i = pos; i < len; i++, j++)
        dest[j] = ss[i];
    dest[len + ta_len] = NULL;
    return (dest);
}
