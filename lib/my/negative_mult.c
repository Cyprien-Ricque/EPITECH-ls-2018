/*
** EPITECH PROJECT, 2018
** infin_mult
** File description:
** negative number managment
*/

#include "../../include/my.h"
#include "../../include/bistromatic.h"

int neg(char *nb1, char *nb2)
{
    int ng = 0;

    if (nb1[0] == '-' && nb2[0] != '-')
        ng = 1;
    if (nb1[0] != '-' && nb2[0] == '-')
        ng = 1;
    return (ng);
}

void delete_neg(char *nb1, char *nb2)
{
    if (nb1[0] == '-')
        delete_cis(nb1, 0, 1);
    if (nb2[0] == '-')
        delete_cis(nb2, 0, 1);
}
