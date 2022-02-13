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
#include <unistd.h>
#include <errno.h>

int search(char *str, char *to_find)
{
    for (int pos = 0; str[pos] != '\0'; ++pos) {
        if (str[pos] == to_find[0]) {
            if (check_string(to_find, str, pos) == 1)
                return (1);
        }
    }
    return (0);
}

char *my_strcat_sl(char *actual, char *to_add)
{
    char *new_str = malloc(sizeof(char) * (1000));
    int e = my_strlen(to_add);
    int k =
        to_add[e - 1] == '/' || actual[0] == '/' || actual[0] == '~' ? 0 : 1;

    if (k == 1)
        new_str[e] = '/';
    for (int i = 0; i < my_strlen(actual) || i < my_strlen(to_add); ++i) {
        new_str[i + e + k] = i < my_strlen(actual) ? actual[i] : '\0';
        new_str[i] = i < my_strlen(to_add) ? to_add[i] : new_str[i];
    }
    new_str[my_strlen(actual) + my_strlen(to_add) + k] = '\0';
    return (new_str);
}

void assignation(chain_t *chain, char *directory, char *name)
{
    chain->tail->next = NULL;
    chain->tail->chain = NULL;
    chain->tail->name = my_strdup(name);
    chain->tail->directory = directory;
    if (name[0] != '/')
        chain->tail->complete_name = my_strcat_sl(name, directory);
    else
        chain->tail->complete_name = my_strdup(name);
    chain->tail->stat_value = stat(chain->tail->complete_name,
        &chain->tail->sb);
    lstat(chain->tail->complete_name, &chain->tail->sbl);
}

int main(int ac, char *av[])
{
    args_t *args = malloc(sizeof(args_t));

    args->to_return = 0;
    find_files(av, args, ac);
    find_flags(av, args);
    if (args->flags[4] != 't')
        sort_files(args);
    else
        sort_files_time(args);
    display_files(args);
    return (args->to_return);
}