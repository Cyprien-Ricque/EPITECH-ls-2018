/*
** EPITECH PROJECT, 2018
** my_showstr
** File description:
** my_showstr
*/

#include "../../include/my.h"

static int my_char_isprintable(char c)
{
    if (c < 32 || c > 126)
        return (0);
    else
        return (1);
}

int my_showstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (my_char_isprintable(str[i]))
            my_putchar(str[i]);
        else {
            my_putchar('\\');
            my_put_basenbr(str[i], 16);
        }
    }
    return (0);
}
