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

int total(chain_t *chain)
{
    node_t *tmp = malloc(sizeof(node_t));
    long long total = 0;

    for (tmp = chain->head; tmp != NULL; tmp = tmp->next)
        total += file_type(tmp->sbl) == 'l' ? (long long)tmp->sbl.st_blocks :
            (long long)tmp->sb.st_blocks;
    total = total / 2;
    if (total <= 8)
        return (0);
    return (total - 8);
}

void reverse_display(chain_t *chain, args_t *args, int info)
{
    for (node_t *tmp = chain->tail; tmp != NULL; tmp = tmp->prev) {
        if (tmp->stat_value != -1)
            file_type(tmp->sbl) == 'l' ?
                print_flags(tmp->sbl, chain, args, tmp) :
                print_flags(tmp->sb, chain, args, tmp);
    }
    for (node_t *tmp = chain->tail; tmp != NULL; tmp = tmp->prev) {
        if (tmp->chain && tmp->chain->tail->directory &&
            args->flags[1] == 'R') {
            my_printf("\n");
            display_chain(tmp->chain, args, FOLDER);
        }
    }
}

void basic_display(chain_t *chain, args_t *args, int info)
{
    for (node_t *tmp = chain->head; tmp != NULL; tmp = tmp->next) {
        if (tmp->stat_value != -1) {
            file_type(tmp->sbl) == 'l' ?
                print_flags(tmp->sbl, chain, args, tmp) :
                print_flags(tmp->sb, chain, args, tmp);
        }
    }
    for (node_t *tmp = chain->head; tmp != NULL; tmp = tmp->next) {
        if (tmp->chain && tmp->chain->tail->directory &&
            args->flags[1] == 'R' && args->flags[2] != 'd') {
            my_putchar('\n');
            display_chain(tmp->chain, args, FOLDER);
        }
    }
}

void display_chain(chain_t *chain, args_t *args, int info)
{
    sort_list(chain, args);
    if ((args->flags[1] == 'R' || args->files_nb > 1) && info == FOLDER)
        my_printf("%s:\n", chain->head->directory);
    if (args->flags[0] == 'l' && info == FOLDER) {
        my_putstr("total ");
        my_put_basenbr(total(chain), 10);
        my_putchar('\n');
    }
    if (args->flags[3] == 'r')
        reverse_display(chain, args, info);
    else
        basic_display(chain, args, info);
}

int check_string(char *needle, char *haystack, int pos_haystack)
{
    int pos_needle = 0;

    while (needle[pos_needle] != '\0') {
        if (haystack[pos_haystack] != needle[pos_needle])
            return (0);
        ++pos_needle;
        ++pos_haystack;
    }
    return (1);
}