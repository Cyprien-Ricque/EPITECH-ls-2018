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

int minor_max(chain_t *chain)
{
    int size;
    int longer = 0;

    if (!chain)
        return (0);
    for (node_t *tmp = chain->head; tmp; tmp = tmp->next) {
        if (file_type(tmp->sbl) == 'l')
            size = my_strlen(return_base(minor(tmp->sb.st_rdev), 10));
        else
            size = my_strlen(return_base(minor(tmp->sbl.st_rdev), 10));
        if (my_strcmp(tmp->name, ".") != 0 && my_strcmp(tmp->name, "..") != 0)
            longer = size > longer ? size : longer;
    }
    return (longer);
}

int major_max(chain_t *chain)
{
    int size;
    int longer = 0;

    if (!chain)
        return (0);
    for (node_t *tmp = chain->head; tmp; tmp = tmp->next) {
        if (file_type(tmp->sbl) == 'l')
            size = my_strlen(return_base(major(tmp->sb.st_rdev), 10));
        else
            size = my_strlen(return_base(major(tmp->sbl.st_rdev), 10));
        if (my_strcmp(tmp->name, ".") != 0 && my_strcmp(tmp->name, "..") != 0)
            longer = size > longer ? size : longer;
    }
    return (longer);
}

int own_max(chain_t *chain)
{
    node_t *tmp = malloc(sizeof(node_t));
    int longer = 0;
    int size = 0;
    struct passwd *uid;

    if (!chain)
        return (0);
    for (tmp = chain->head; tmp != NULL; tmp = tmp->next) {
        uid = getpwuid(
            file_type(tmp->sbl) == 'l' ? tmp->sbl.st_uid : tmp->sb.st_uid);
        size = my_strlen(uid->pw_name);
        if (my_strcmp(tmp->name, ".") != 0 && my_strcmp(tmp->name, "..") != 0) {
            longer = size > longer ? size : longer;
        }
    }
    return (longer);
}

int group_max(chain_t *chain)
{
    node_t *tmp = malloc(sizeof(node_t));
    int longer = 0;
    int size = 0;
    struct group *pid;

    if (!chain)
        return (0);
    for (tmp = chain->head; tmp != NULL; tmp = tmp->next) {
        pid = getgrgid(
            file_type(tmp->sbl) == 'l' ? tmp->sbl.st_gid : tmp->sb.st_gid);
        size = my_strlen(pid->gr_name);
        if (my_strcmp(tmp->name, ".") != 0 && my_strcmp(tmp->name, "..") != 0)
            longer = size > longer ? size : longer;
    }
    return (longer);
}

int links_max(chain_t *chain)
{
    node_t *tmp = malloc(sizeof(node_t));
    int longer = 0;
    int size = 0;

    if (!chain)
        return (0);
    for (tmp = chain->head; tmp != NULL; tmp = tmp->next) {
        size = my_strlen(return_base(
            (long)file_type(tmp->sbl) == 'l' ? tmp->sbl.st_nlink :
                tmp->sb.st_nlink, 10));
        if (my_strcmp(tmp->name, ".") != 0 && my_strcmp(tmp->name, "..") != 0)
            longer = size > longer ? size : longer;
    }
    return (longer);
}