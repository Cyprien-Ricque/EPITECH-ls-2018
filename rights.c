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

void set_rights(unsigned long info, char *rights, int mode)
{
    if (info == 4 || info == 5 || info == 6 || info == 7)
        rights[mode * 3 + 1] = 'r';
    if (info == 2 || info == 3 || info == 6 || info == 7)
        rights[mode * 3 + 2] = 'w';
    if (info == 1 || info == 3 || info == 5 || info == 7)
        rights[mode * 3 + 3] = 'x';
}

void rights(struct stat sb)
{
    char *right = return_base(sb.st_mode, 8);
    char rights[] = "----------";
    unsigned long su = right[my_strlen(right) - 1] - 48;
    unsigned long us = right[my_strlen(right) - 2] - 48;
    unsigned long ba = right[my_strlen(right) - 3] - 48;

    rights[0] = file_type(sb);
    set_rights(su, rights, 2);
    set_rights(us, rights, 1);
    set_rights(ba, rights, 0);
    if (S_ISVTX & sb.st_mode) {
        if (rights[9] == 'x')
            rights[9] = 't';
        if (rights[9] == '-')
            rights[9] = 'T';
    }
    my_printf("%s", rights);
}