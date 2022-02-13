/*
** EPITECH PROJECT, 2018
** deladd_ucis
** File description:
** delete/add uchars in string
*/

#include "../../include/my.h"
#include <unistd.h>
#include <stdlib.h>

void delete_ucis(unsigned char *str, int pos, int const n)
{
    while (str[pos + n] != '\0') {
        str[pos] = str[pos + n];
        pos++;
    }
    str[pos] = '\0';
}

unsigned char *add_ucis(unsigned char *str, int pos, char *to_add)
{
    int len = my_ustrlen(str);
    int ta_len = my_strlen(to_add);
    unsigned char *dest = malloc(sizeof(unsigned char) * (len + ta_len + 1));
    int j = 0;

    for (int i = 0; i < pos; i++, j++)
        dest[j] = str[i];
    for (int i = 0; i < ta_len; i++, j++)
        dest[j] = to_add[i];
    for (int i = pos; i < len; i++, j++)
        dest[j] = str[i];
    dest[len + ta_len] = '\0';
    return (dest);
}
