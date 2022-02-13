/*
** EPITECH PROJECT, 2018
** my_compute_square_root
** File description:
** my_compute_square_root
*/

int my_compute_square_root(int nb)
{
    int nb2;
    int test1;
    int test2;

    nb2 = nb / 2;
    if (nb <= 0)
        return (0);
    if (nb == 1)
        return (1);
    for (int c = 0; c <= nb2; c++) {
        test1 = nb2 - c;
        test2 = test1 * test1;
        if (test2 == nb)
            return (test1);
    }
    return (0);
}
