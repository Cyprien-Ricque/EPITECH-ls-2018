/*
** EPITECH PROJECT, 2018
** my_strlen
** File description:
** my_strlen
*/

#include <unistd.h>

int my_ustrlen(unsigned char const *str)
{
    int count = 0;

    if (str == NULL)
        return (0);
    while (str[count] != '\0') {
        count++;
    }
    return (count);
}
