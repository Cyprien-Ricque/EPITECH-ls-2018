/*
** EPITECH PROJECT, 2018
** deladd_cis
** File description:
** delete/add chars in string
*/

#include "../../include/my.h"
#include <unistd.h>
#include <stdlib.h>

void delete_cis(char *str, int pos, int const n)
{
    while (str[pos + n] != '\0') {
        str[pos] = str[pos + n];
        pos++;
    }
    str[pos] = '\0';
}

char *add_cis(char *str, int pos, char *to_add)
{
    int len = my_strlen(str);
    int ta_len = my_strlen(to_add);
    char *dest = malloc(sizeof(char) * (len + ta_len + 1));

    int j = 0;
    for (int i = 0; i < pos; i++, j++)
        dest[j] = str[i];
    for (int i = 0; i < ta_len; i++, j++)
        dest[j] = to_add[i];
    for (int i = pos; i < len; i++, j++)
        dest[j] = str[i];
    dest[len + ta_len] = '\0';
    free(str);
    return (dest);
}
