/*
** EPITECH PROJECT, 2018
** my_getlnbr
** File description:
** my_getlnbr
*/

long my_getlnbr(char const *str, int pos)
{
    long nb = 0;
    int neg = 1;
    long i = pos;

    while (str[i] != '\0'
            && ((str[i] <= '9' && str[i] >= '0') ||
            (str[i] == '-' || str[i] == '+'))) {
        if (str[i] == '-')
            neg = neg * (-1);
        if (str[i] >= '0' && str[i] <= '9') {
            nb = nb * 10;
            nb = nb + (str[i] - 48);
        }
        i++;
    }
    nb = nb * neg;
    return (nb);
}
