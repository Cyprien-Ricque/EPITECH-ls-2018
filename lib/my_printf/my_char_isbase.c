/*
** EPITECH PROJECT, 2018
** my_char_isbase
** File description:
** my_char_isbase
*/

int my_char_isbase(char const chr, int base)
{
    if (chr < '0' || chr > (48 + base - 1))
        return (0);
    return (1);
}

int my_char_iscbase(char const chr, char base)
{
    if (chr < '0' || chr > base - 1)
        return (0);
    return (1);
}
