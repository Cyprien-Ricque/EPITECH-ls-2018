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

void fill_values_time(chain_t *chain, args_t *args)
{
    for (node_t *tmp = chain->head; tmp; tmp = tmp->next) {
        tmp->name_value = malloc(sizeof(char) * 40);
        tmp->name_value = return_base(tmp->sb.st_mtime, 10);
    }
}

void fill_values(chain_t *chain, args_t *args)
{
    for (node_t *tmp = chain->head; tmp; tmp = tmp->next) {
        tmp->name_value = malloc(sizeof(char) * (my_strlen(tmp->name) + 1));
        for (int i = 0; tmp->name[i]; ++i) {
            tmp->name_value[i] = find_letter(tmp->name[i]);
            tmp->name_value[i + 1] = 0;
        }
    }
}

void swap(chain_t *chain, node_t *node1, node_t *node2)
{
    if (chain->head == node1)
        chain->head = node2;
    if (chain->tail == node2)
        chain->tail = node1;
    if (node1->prev)
        node1->prev->next = node2;
    if (node2->next)
        node2->next->prev = node1;
    node1->next = node2->next;
    node2->prev = node1->prev;
    node2->next = node1;
    node1->prev = node2;
}

chain_t *sort_chain(chain_t *chain, int info)
{
    node_t *bis;

    for (node_t *tmp = chain->head; tmp->next; tmp = tmp->next) {
        if (info == BASIC &&
            my_strcmp(tmp->name_value, tmp->next->name_value) == 1) {
            swap(chain, tmp, tmp->next);
            return (chain);
        }
        if (info == TIME &&
            my_nbcmp(tmp->name_value, tmp->next->name_value) == -1) {
            swap(chain, tmp, tmp->next);
            return (chain);
        }
    }
    return (chain);
}

int list_ins(chain_t *chain, char info)
{
    for (node_t *tmp = chain->head; tmp->next != NULL; tmp = tmp->next) {
        if (info == BASIC &&
            my_strcmp(tmp->name_value, tmp->next->name_value) == 1)
            return (0);
        if (info == TIME &&
            my_nbcmp(tmp->name_value, tmp->next->name_value) == -1) {
            return (0);
        }
    }
    return (1);
}