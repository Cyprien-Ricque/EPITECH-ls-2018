/*
** EPITECH PROJECT, 2018
** my_str_isbase
** File description:
** my_str_is_base
*/

int my_str_isbase(char const *str, int base)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] < '0' || str[i] > (48 + base - 1)) && str[i] != '-')
            return (0);
    }
    return (1);
}
