/*
** EPITECH PROJECT, 2018
** my_strcmp
** File description:
** my_ctrcmp
*/

#include "../../include/my.h"

int my_strcmp(char const *str1, char const *str2)
{
    for (int i = 0; str1[i] != '\0' || str2[i] != '\0'; i++) {
        if (str1[i] > str2[i])
            return (1);
        if (str1[i] < str2[i])
            return (-1);
        if (str1[i] == 0 && str2[i] == 0)
            return (0);
    }
    return (0);
}
