/*
** EPITECH PROJECT, 2018
** my_showmem
** File description:
** my_showmem
*/

#include "../../include/my.h"
#include <unistd.h>

static int my_char_isprintable(char c)
{
    if (c < 32 || c > 126)
        return (0);
    else
        return (1);
}

static void print_string(char const *str, int i, int size)
{
    int nbinf = 16 * i;
    int nbsup = 16 * (i + 1);

    while (nbinf != nbsup && nbinf != size) {
        if (my_char_isprintable(str[nbinf]))
            my_putchar(str[nbinf]);
        else
            my_putchar('.');
        nbinf++;
    }
}

static void print_hexa(char const *str, int i, int size)
{
    int nbinf = 16 * i;
    int nbsup = 16 * (i + 1);
    int comptexa = 0;

    while (nbinf != nbsup && nbinf != size) {
        if (str[nbinf] < 16) {
            my_putchar('0');
        }
        my_put_basenbr(str[nbinf], 16);
        comptexa = comptexa + 2;
        if (nbinf % 2 != 0) {
            my_putchar(' ');
            comptexa++;
        }
        nbinf++;
    }
    while (comptexa < 40) {
        my_putchar(' ');
        comptexa++;
    }
}

static void print_address(int i)
{
    int compt = 0;
    int nb = 16 * i;
    int nb2 = nb;

    while (nb > 15) {
        nb = nb / 16;
        compt++;
    }
    for (int i = 0; (7 - compt) != i; i++)
        my_putchar('0');
    my_put_basenbr(nb2, 16);
    my_putstr(":  ");
}

int my_showmem(char const *str, int size)
{
    int i = 0;

    while (i != (size / 16 + 1)) {
        print_address(i);
        print_hexa(str, i, size);
        print_string(str, i, size);
        i++;
        my_putchar('\n');
    }
    return 0;
}
