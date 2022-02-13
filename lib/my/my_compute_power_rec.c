/*
** EPITECH PROJECT, 2018
** my_compute_power_rec
** File description:
** my_compute_power_rec
*/

static int my_compute_power_rec2(int nb, int p, int nb2)
{
    if (p == 1)
        return nb;
    if (p == 0) {
        return (1);
    } else if (p < 0) {
        return (0);
    } else {
        p--;
        nb2 = nb2 * nb;
        if (nb2 > 2147483647 || nb2 < -2147482147)
            return (0);
    }
    if (p != 1)
        return (my_compute_power_rec2(nb, p, nb2));
    else
        return (nb2);
    return (0);
}

int my_compute_power_rec(int nb, int p)
{
    long nb2 = nb;
    int return1;

    return1 = my_compute_power_rec2(nb, p, nb2);
    return (return1);
}
