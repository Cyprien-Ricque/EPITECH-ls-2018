/*
** EPITECH PROJECT, 2018
** my_strtoarray
** File description:
** my_strtoarray
*/

#include <stdlib.h>
#include "../../include/my.h"
#include <stddef.h>

char **assignement(char **array, char *str)
{
    int y = 0;
    int x = 0;

    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == '\n') {
            array[y][x] = '\0';
            y++;
            i++;
            x = 0;
        }
        array[y][x] = str[i];
        x++;
    }
    array[y] = NULL;
    return (array);
}

char **my_str_toarray(char *str, int global_size)
{
    int line_size = 0;
    char **array = malloc(sizeof(char *) * (global_size + 2));
    int info = 0;

    for (int i = 0; info != 2; ++i) {
        if (str[i] == '\n')
            info++;
        line_size++;
    }
    for (int i = 0; i != global_size + 2; ++i)
        array[i] = malloc(sizeof(char) * line_size + 1);
    assignement(array, str);
    return (array);
}
