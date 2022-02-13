/*
** EPITECH PROJECT, 2018
** my_str_to_word_array
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>

static int *str_size_li(char const *str, int c_let, int *count_letw, int total)
{
    int a = 1;
    int i = 0;

    while (str[i] != '\0') {
        while ((str[i] > 97 && str[i] < 122) || (str[i] > 65 && str[i] < 90) ||
            (str[i] > 48 && str[i] < 57)) {
            c_let++;
            i++;
        }
        count_letw[a] = c_let;
        a++;
        i++;
    }
    count_letw[0] = total;
    return (count_letw);
}

static int *str_size(char const *str)
{
    int count_total = 0;
    int count_words = 0;
    int *count_letw;
    int c_let = 0;
    int total;
    int i = 0;

    while (str[i] != '\0') {
        while ((str[i] > 97 && str[i] < 122) || (str[i] > 65 && str[i] < 90) ||
            (str[i] > 48 && str[i] < 57)) {
            count_total++;
            i++;
        }
        i++;
        count_words++;
    }
    total = count_words + count_total;
    count_letw = malloc(sizeof(int) * count_words);
    str_size_li(str, c_let, count_letw, total);
    return count_letw;
}

static int while_info2(char const *str, int i)
{
    while (str[i] != '\0' && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A'
        || str[i] > 'Z') && (str[i] < '0' || str[i] > '9')) {
        i++;
    }
    return (i);
}

static char **while_info(char const *str, char **tab, int *count, int j)
{
    int k = 0;
    int i = 0;

    while (str[i] != '\0') {
        tab[j] = malloc(sizeof(char) * count[j] + 1);
        while ((str[i] >= 'a' && str[i] <= 'z') ||
            (str[i] >= 'A' && str[i] <= 'Z') ||
            (str[i] >= '0' && str[i] <= '9')) {
            tab[j][k] = str[i];
            i++;
            k++;
        }
        tab[j][k + 1] = '\0';
        j++;
        i++;
        k = 0;
        i = while_info2(str, i);
    }
    tab[j] = 0;
    return (tab);
}

char **my_str_to_word_array(char const *str)
{
    char **tab;
    int *count;
    int j = 0;

    count = str_size(str);
    tab = malloc(sizeof(char *) * (count[0] + 1));
    while_info(str, tab, count, j);
    return (tab);
}
