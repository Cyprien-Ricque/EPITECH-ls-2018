/*
** EPITECH PROJECT, 2018
** my_putstr
** File description:
** my_putstr
*/

#include <unistd.h>
#include <stddef.h>
#include "../../include/my_printf.h"

int my_putstr(char const *str)
{
    int i;

    if ((str) == NULL) {
        write(1, "(null)", 6);
        return (0);
    }
    i = my_strlen(str);
    write(1, str, i);
    return (0);
}
