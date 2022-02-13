/*
** EPITECH PROJECT, 2018
** my_getnbr
** File description:
** my_getnbr
*/

long my_getnbr(char const *str)
{
    long nb = 0;
    int neg = 1;
    long i = 0;

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
