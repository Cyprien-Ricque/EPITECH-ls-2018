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

chain_t *new_node(char *name, chain_t *chain, char *directory)
{
    node_t *new_node = malloc(sizeof(node_t));

    new_node->chain = malloc(sizeof(chain_t));
    if (new_node == NULL || new_node->chain == NULL)
        exit(84);
    if (chain->tail == NULL) {
        chain->head = new_node;
        chain->tail = new_node;
        chain->tail->prev = NULL;
    } else {
        chain->tail->next = new_node;
        chain->tail->next->prev = chain->tail;
        chain->tail = chain->tail->next;
    }
    assignation(chain, directory, name);
    return (chain);
}

void organize_chains(chain_t *chain, struct dirent *result, char *directory,
    args_t *args)
{
    struct stat sb;
    int val;

    val = stat(my_strcat_sl(result->d_name, directory), &sb);
    if (val != -1)
        chain = new_node(result->d_name, chain, directory);
    else
        args->to_return = 84;
    if (val != -1 && search(chain->tail->complete_name, "/.") == 0 &&
        search(chain->tail->complete_name, "/..") == 0 &&
        file_type(chain->tail->sb) == 'd' &&
        file_type(chain->tail->sbl) != 'l' && args->flags[1] == 'R') {
        chain->tail->chain = create_chain(chain->tail->chain,
            chain->tail->complete_name, args);
    }
}

chain_t *create_chain(chain_t *chain, char *directory, args_t *args)
{
    DIR *dir = opendir(directory);
    struct dirent *result;

    chain = malloc(sizeof(chain_t));
    if (dir == NULL || chain == NULL)
        return (NULL);
    chain->tail = NULL;
    while (result = readdir(dir)) {
        organize_chains(chain, result, directory, args);
    }
    closedir(dir);
    return (chain);
}