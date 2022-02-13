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

int my_nbcmp(char *nb1, char *nb2)
{
    if (my_strlen(nb1) > my_strlen(nb2))
        return (1);
    if (my_strlen(nb2) > my_strlen(nb1))
        return (-1);
    return (my_strcmp(nb1, nb2));
}

int rank_nb(char **values, int i)
{
    int c = 0;

    for (int e = 0; values[e]; ++e) {
        if ((e != i && (my_nbcmp(values[i], values[e]) == 1)) ||
            (my_nbcmp(values[i], values[e]) == 0 && e > i))
            ++c;
    }
    return (c);
}

char *find_time(char *file, args_t *args)
{
    struct stat sb;

    if (stat(file, &sb) != -1) {
        return (return_base(sb.st_mtime, 10));
    }
    args->to_return = 84;
    return (NULL);
}

void organize_time(args_t *args, char **values, char **tmp)
{
    struct stat sb;
    int e = 0;

    for (int j = 0; args->files[j]; ++j) {
        values[j] = malloc(sizeof(char) * (my_strlen(args->files[j]) + 100));
        if (values[j] == NULL)
            exit(84);
        values[e] = find_time(args->files[j], args);
        values[e + 1] = NULL;
        tmp[e + 1] = NULL;
        if (stat(args->files[j], &sb) != -1)
            ++e;
    }
}

void sort_files_time(args_t *args)
{
    char **tmp = malloc(sizeof(char *) * (args->files_nb + 1));
    char **values = malloc(sizeof(char *) * (args->files_nb + 1));

    if (tmp == NULL || values == NULL)
        exit(84);
    for (int i = 0; args->files[i]; ++i) {
        tmp[i] = malloc(sizeof(char) * my_strlen(args->files[i]) + 100);
        if (tmp[i] == NULL)
            exit(84);
    }
    organize_time(args, values, tmp);
    for (int i = 0; values[i]; ++i)
        tmp[rank(values, i)] = args->files[i];
    file_type_sort(tmp, args);
}