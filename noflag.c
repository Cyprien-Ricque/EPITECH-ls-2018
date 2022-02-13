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

void print_name(struct stat sb, args_t *args, node_t *tmp)
{
    char *buf;
    int size;

    if (file_type(sb) == 'l' && args->flags[0] == 'l') {
        buf = malloc(sizeof(char) * 302);
        size = readlink(tmp->complete_name, buf, 300);
        if (size > 0)
            buf[size] = 0;
        my_printf("%s -> %s\n", tmp->name, buf);
    } else {
        my_printf("%s\n", tmp->name);
    }
}