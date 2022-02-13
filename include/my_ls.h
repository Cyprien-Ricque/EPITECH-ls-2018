/*
** EPITECH PROJECT, 2018
** bsq
** File description:
** bsq
*/

#ifndef MY_LS_H_
#define MY_LS_H_

#define PRESENT 1
#define ABSENT 0
#define FILE 0
#define FOLDER 1
#define BASIC 0
#define TIME 1

#include "my_printf.h"

struct args {
    char *flags;
    char **files;
    int files_nb;
    int to_return;
};
typedef struct args args_t;

struct chain {
    struct node *tail;
    struct node *head;
};
typedef struct chain chain_t;

struct node {
    struct stat sb;
    struct stat sbl;
    char *name;
    char *name_value;
    char *complete_name;
    char *directory;
    struct node *next;
    struct node *prev;
    chain_t *chain;
    char *buf;
    int stat_value;
};
typedef struct node node_t;

void sort_files(args_t *args);
char file_type(struct stat sb);
void l_option(struct stat sb, chain_t *chain);
void print_name(struct stat sb, args_t *args, node_t *tmp);
void find_files(char **av, args_t *args, int ac);
void find_flags(char **av, args_t *args);
void print_flags(struct stat sb, chain_t *chain, args_t *args, node_t *tmp);
int search(char *str, char *to_find);
void sort_list(chain_t *chain, args_t *args);
char find_letter(char c);
void display_chain(chain_t *chain, args_t *args, int info);
int my_printf(char *str, ...);
void sort_files_time(args_t *args);
int my_nbcmp(char *nb1, char *nb2);
int rank(char **values, int i);
void file_type_sort(char **tmp, args_t *args);
void fill_values_time(chain_t *chain, args_t *args);
void fill_values(chain_t *chain, args_t *args);
void swap(chain_t *chain, node_t *node1, node_t *node2);
chain_t *sort_chain(chain_t *chain, int info);
int list_ins(chain_t *chain, char info);
int minor_max(chain_t *chain);
int major_max(chain_t *chain);
int own_max(chain_t *chain);
int group_max(chain_t *chain);
int links_max(chain_t *chain);
int size_max(chain_t *chain);
void set_rights(unsigned long info, char *rights, int mode);
void rights(struct stat sb);
int total(chain_t *chain);
void reverse_display(chain_t *chain, args_t *args, int info);
void basic_display(chain_t *chain, args_t *args, int info);
void display_chain(chain_t *chain, args_t *args, int info);
int check_string(char *needle, char *haystack, int pos_haystack);
int total(chain_t *chain);
void display_folders(args_t *args, struct stat sb, int i);
void display_files(args_t *args);
int search(char *str, char *to_find);
char *my_strcat_sl(char *actual, char *to_add);
void assignation(chain_t *chain, char *directory, char *name);
chain_t *new_node(char *name, chain_t *chain, char *directory);
chain_t *create_chain(chain_t *chain, char *directory, args_t *args);
chain_t *new_node(char *name, chain_t *chain, char *directory);
chain_t *create_chain(chain_t *chain, char *directory, args_t *args);

#endif
