/*
** EPITECH PROJECT, 2018
** my_strcapitalize
** File description:
** my_strcapitalize
*/

#include "../../include/my.h"

char *my_strcapitalize(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] > 96 && str[i] < 123)
            str[i] = str[i] - 32;
    }
    return (str);
}
