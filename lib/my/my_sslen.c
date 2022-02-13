/*
** EPITECH PROJECT, 2018
** my_sslen
** File description:
** my_sslen
*/

#include <unistd.h>
#include <stdlib.h>
#include "../../include/my.h"

int my_sslen(char **ss)
{
    int i = 0;

    while (ss[i] != NULL) {
        i++;
    }
    return (i);
}
