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

static const char list[] = " !\"#%&()*+,./:;<=>?@[\\]^_`{}~§°$£€²0123456789aAàâ"
                           "ÂäÄbBcCçdDeEéèêÊëËfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUv"
                           "VwWxXyYzZøµ";

char find_letter(char c)
{
    char value_nb;

    for (int i = 0; list[i]; ++i) {
        if (list[i] == c)
            return (i);
    }
    return (my_strlen(list));
}

void check_return(char **tmp, args_t *args)
{
    struct stat sb;

    for (int j = 0; tmp[j]; ++j) {
        if (stat(tmp[j], &sb) == -1) {
            args->to_return = 84;
        }
    }
}

void organize_files(args_t *args, char **values, char **tmp)
{
    for (int j = 0; args->files[j]; ++j) {
        values[j] = malloc(sizeof(char) * (my_strlen(args->files[j]) + 1000));
        if (values[j] == NULL)
            exit(84);
        for (int i = 0; args->files[j][i]; ++i) {
            values[j][i] = find_letter(args->files[j][i]);
            values[j][i + 1] = 0;
        }
        values[j + 1] = NULL;
        tmp[j + 1] = NULL;
    }
}

void sort_files(args_t *args)
{
    char **tmp = malloc(sizeof(char *) * (args->files_nb + 1));
    char **values = malloc(sizeof(char *) * (args->files_nb + 1));

    if (tmp == NULL || values == NULL)
        exit(84);
    for (int i = 0; args->files[i]; ++i) {
        tmp[i] = malloc(sizeof(char) * my_strlen(args->files[i]) + 1);
        if (tmp[i] == NULL)
            exit(84);
    }
    organize_files(args, values, tmp);
    for (int i = 0; i < args->files_nb; ++i)
        tmp[rank(values, i)] = args->files[i];
    check_return(tmp, args);
    file_type_sort(tmp, args);
}