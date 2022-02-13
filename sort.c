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

int rank(char **values, int i)
{
    int c = 0;

    for (int e = 0; values[e]; ++e) {
        if ((e != i && (my_strcmp(values[i], values[e]) == -1)) ||
            (my_strcmp(values[i], values[e]) == 0 && e > i))
            ++c;
    }
    return (c);
}

void file_type_sort(char **tmp, args_t *args)
{
    struct stat sb;
    int basic = 0;
    int stat_value;

    for (int i = 0; tmp[i]; ++i) {
        stat_value = stat(tmp[i], &sb);
        if (stat_value != -1 && file_type(sb) != 'd') {
            args->files[basic] = tmp[i];
            ++basic;
        }
    }
    for (int i = 0; tmp[i]; ++i) {
        stat_value = stat(tmp[i], &sb);
        if (stat_value != -1 && file_type(sb) == 'd') {
            args->files[basic] = tmp[i];
            ++basic;
        }
    }
    args->files[basic] = NULL;
}

void sort_list(chain_t *chain, args_t *args)
{
    if (args->flags[4] != 't')
        fill_values(chain, args);
    else
        fill_values_time(chain, args);
    while (list_ins(chain, args->flags[4] != 't' ? BASIC : TIME) == 0)
        chain = sort_chain(chain, args->flags[4] != 't' ? BASIC : TIME);
}