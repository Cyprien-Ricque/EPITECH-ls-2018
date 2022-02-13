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

void print_flags(struct stat sb, chain_t *chain, args_t *args, node_t *tmp)
{
    if (tmp->name[0] != '.' || (args->flags[2] == 'd')) {
        if (args->flags[0] == 'l')
            l_option(sb, chain);
        print_name(sb, args, tmp);
    }
}