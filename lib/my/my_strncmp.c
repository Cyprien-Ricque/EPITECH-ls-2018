/*
** EPITECH PROJECT, 2018
** my_strncmp
** File description:
** my_ctrncmp
*/

#include "../../include/my.h"

int my_strncmp(char const *str1, char const *str2, int n)
{
    for (int i = 0; (str1[i] != '\0' || str2[i] != '\0') && i != n; i++) {
        if (str1[i] > str2[i])
            return (1);
        if (str1[i] < str2[i])
            return (-1);
    }
    return (0);
}
