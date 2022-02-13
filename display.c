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

void display_folders(args_t *args, struct stat sb, int i)
{
    chain_t *chain;

    while (args->files[i]) {
        i > 0 ? my_printf("\n") : my_printf("");
        chain = create_chain(chain, args->files[i], args);
        if (chain)
            display_chain(chain, args, FOLDER);
        ++i;
        if (args->files[i])
            stat(args->files[i], &sb);
    }
}

void display_files(args_t *args)
{
    struct stat sb;
    int i = 0;
    chain_t *chain = malloc(sizeof(chain_t));

    if (args->files[0])
        stat(args->files[i], &sb);
    chain->tail = NULL;
    if (chain == NULL)
        exit(84);
    while (args->files[i] && (file_type(sb) != 'd' || args->flags[2] == 'd')) {
        chain = new_node(args->files[i], chain, ".");
        ++i;
        if (args->files[i])
            stat(args->files[i], &sb);
    }
    if (i > 0 && chain)
        display_chain(chain, args, FILE);
    free(chain);
    display_folders(args, sb, i);
}