/*
** EPITECH PROJECT, 2018
** my_ls
** File description:
** my_ls
*/

#include "include/my_printf.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include "include/my.h"
#include <pwd.h>
#include <grp.h>
#include "include/my_ls.h"

void fill_flags(char *flags, args_t *args)
{
    for (int i = 0; flags[i] != '\0'; ++i) {
        if (flags[i] == 'l')
            args->flags[0] = 'l';
        if (flags[i] == 'R')
            args->flags[1] = 'R';
        if (flags[i] == 'd')
            args->flags[2] = 'd';
        if (flags[i] == 'r')
            args->flags[3] = 'r';
        if (flags[i] == 't')
            args->flags[4] = 't';
    }
}

void find_flags(char **av, args_t *args)
{
    args->flags = malloc(sizeof(char) * 6);

    args->flags[0] = '-';
    args->flags[1] = '-';
    args->flags[2] = '-';
    args->flags[3] = '-';
    args->flags[4] = '-';
    args->flags[5] = '\0';
    for (int i = 0; av[i]; ++i) {
        if (av[i][0] == '-')
            fill_flags(av[i], args);
    }
}