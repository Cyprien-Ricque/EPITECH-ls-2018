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

char file_type(struct stat sb)
{
    switch (sb.st_mode & S_IFMT) {
    case S_IFBLK:
        return ('b');
    case S_IFCHR:
        return ('c');
    case S_IFDIR:
        return ('d');
    case S_IFIFO:
        return ('p');
    case S_IFLNK:
        return ('l');
    case S_IFREG:
        return ('-');
    case S_IFSOCK:
        return ('s');
    default:
        return ('u');
    }
}

void print_spaces(int nb)
{
    for (int i = 0; i < nb; ++i)
        my_putchar(' ');
}

void char_print(struct stat sb, int diff_size_ct, int size_actual_ct)
{
    my_put_basenbr(major(sb.st_rdev), 10);
    my_printf(", ");
    print_spaces(diff_size_ct - size_actual_ct);
    my_put_basenbr(minor(sb.st_rdev), 10);
}

void print_size(struct stat sb, chain_t *chain)
{
    int size_actual = my_strlen(return_base(sb.st_size, 10));
    int size_actual_co;
    int size_actual_ct;
    int diff_size = size_max(chain);
    int diff_size_co;
    int diff_size_ct;

    if (file_type(sb) == 'c') {
        diff_size_co = major_max(chain) + 2;
        diff_size_ct = minor_max(chain);
        size_actual_co = my_strlen(return_base(major(sb.st_rdev), 10)) + 2;
        size_actual_ct = my_strlen(return_base(minor(sb.st_rdev), 10));
        print_spaces(diff_size_co - size_actual_co);
        char_print(sb, diff_size_ct, size_actual_ct);
    } else {
        print_spaces(diff_size - size_actual);
        my_put_basenbr(sb.st_size, 10);
    }
}

void l_option(struct stat sb, chain_t *chain)
{
    char *time_e = malloc(sizeof(char) * 20);
    int diff_link = links_max(chain) - my_strlen(return_base(sb.st_nlink, 10));
    int diff_own = own_max(chain);
    int diff_group = group_max(chain);
    struct passwd *uid = getpwuid(sb.st_uid);
    struct group *pid = getgrgid(sb.st_gid);

    rights(sb);
    print_spaces(diff_link + 1);
    my_put_basenbr(sb.st_nlink, 10);
    my_printf(" %s", uid->pw_name);
    print_spaces(diff_own - my_strlen(uid->pw_name));
    my_printf(" %s", pid->gr_name);
    print_spaces(diff_group - my_strlen(pid->gr_name) + 1);
    print_size(sb, chain);
    time_e = ctime(&sb.st_mtime);
    time_e[my_strlen(time_e) - 1] = 0;
    my_printf(" %s ", time_e);
}