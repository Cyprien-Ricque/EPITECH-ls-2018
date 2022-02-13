/*
** EPITECH PROJECT, 2018
** hexm_a
** File description:
** hexm_a
*/

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../../include/my_printf.h"

int hexam(va_list ap, int val, char *str)
{
    unsigned int nb = va_arg(ap, unsigned int);
    int to_add = the_choice(nb, str, val, 16);

    my_put_ubasemnbr(nb, 16);
    while (to_add > 0) {
        my_putchar(' ');
        to_add--;
    }
    return (0);
}

int lhexam(va_list ap, int val, char *str)
{
    unsigned long int nb = va_arg(ap, long unsigned int);
    int to_add = the_choice(nb, str, val, 16);

    my_put_lubasemnbr(nb, 16);
    while (to_add > 0) {
        my_putchar(' ');
        to_add--;
    }
    return (0);
}

int llhexam(va_list ap, int val, char *str)
{
    unsigned long long nb = va_arg(ap, unsigned long long int);
    int to_add = the_choice(nb, str, val, 16);

    my_put_llubasemnbr(nb, 16);
    while (to_add > 0) {
        my_putchar(' ');
        to_add--;
    }
    return (0);
}

int hhexam(va_list ap, int val, char *str)
{
    unsigned short int nb = va_arg(ap, unsigned int);
    int to_add = the_choice(nb, str, val, 16);

    my_put_hubasemnbr(nb, 16);
    while (to_add > 0) {
        my_putchar(' ');
        to_add--;
    }
    return (0);
}

int hhhexam(va_list ap, int val, char *str)
{
    unsigned char nb2 = va_arg(ap, unsigned int);
    int nb = (int)nb2;
    int to_add = the_choice(nb, str, val, 16);

    my_put_ubasemnbr(nb, 16);
    while (to_add > 0) {
        my_putchar(' ');
        to_add--;
    }
    return (0);
}
