/*
** EPITECH PROJECT, 2018
** my_strlen
** File description:
** my_strlen
*/

#include <unistd.h>

int my_strlen(char const *str)
{
    int count = 0;

    if (str == NULL)
        return (6);
    while (str[count] != '\0')
        count++;
    return (count);
}
