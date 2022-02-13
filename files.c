/*
** EPITECH PROJECT, 2018
** my_ls
** File description:
** my_ls
*/

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

void find_files(char **av, args_t *args, int ac)
{
    args->files = malloc(sizeof(char *) * (ac + 1));
    int c = 0;

    for (int i = 1; av[i]; ++i) {
        if (av[i][0] != '-') {
            args->files[c] = malloc(sizeof(char) * (my_strlen(av[i]) + 1));
            args->files[c] = av[i];
            ++c;
        }
    }
    if (c == 0) {
        args->files[c] = ".";
        ++c;
    }
    args->files[c] = NULL;
    args->files_nb = c;
}