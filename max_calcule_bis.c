/*
** EPITECH PROJECT, 2018
** my_ls
** File description:
** my_ls
*/

#include <sys/types.h>
#include <sys/sysmacros.h>
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
#include <time.h>

int def_size(int size, node_t *tmp)
{
    if (file_type(tmp->sb) == 'c') {
        size = my_strlen(return_base(major(tmp->sb.st_rdev), 10));
        size += my_strlen(return_base(minor(tmp->sb.st_rdev), 10));
        size += 2;
    } else {
        size = my_strlen(return_base(
            (long long)file_type(tmp->sbl) == 'l' ? tmp->sbl.st_size :
                tmp->sb.st_size, 10));
    }
    return (size);
}

int size_max(chain_t *chain)
{
    node_t *tmp = malloc(sizeof(node_t));
    int longer = 0;
    int size = 0;
    struct stat sb;
    int val;

    if (!chain)
        return (0);
    for (tmp = chain->head; tmp != NULL; tmp = tmp->next) {
        size = def_size(size, tmp);
        if (my_strcmp(tmp->name, ".") != 0 && my_strcmp(tmp->name, "..") != 0)
            longer = size > longer ? size : longer;
    }
    return (longer);
}