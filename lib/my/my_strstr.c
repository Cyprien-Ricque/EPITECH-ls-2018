/*
** EPITECH PROJECT, 2018
** my_strstr
** File description:
** my_strstr
*/

#include "../../include/my.h"
#include <unistd.h>

char *my_strstr(char *str, char const *to_find)
{
    int length = my_strlen(to_find);

    for (int j = 0; str[j] != '\0'; j++){
        for (int i = 0; str[j] == to_find[i]; i++, j++) {
            if (str[j] == to_find[i] && to_find[i + 1] == '\0') {
                j = j - length + 1;
                return (&str[j]);
            }
        }
    }
    return (NULL);
}
