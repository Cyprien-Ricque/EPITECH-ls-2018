/*
** EPITECH PROJECT, 2018
** my_char_isnum
** File description:
** my_char_isnum
*/

int my_char_isnum(char const chr)
{
    if (chr < '0' || chr > '9')
        return (0);
    return (1);
}
