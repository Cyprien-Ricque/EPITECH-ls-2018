/*
** EPITECH PROJECT, 2018
** my_swap
** File description:
** my_swap
*/

void my_swap(int *a, int *b)
{
    int stock_value;

    stock_value = *b;
    *b = *a;
    *a = stock_value;
}
