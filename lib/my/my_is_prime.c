/*
** EPITECH PROJECT, 2018
** my_is_prime.
** File description:
** my_is_prime
*/

int my_is_prime(int nb)
{
    int nb2 = nb / 2;
    int nb3 = nb2;
    int test;
    int nb22;
    int nb33;

    if (nb <= 1){
        return (0);
    }
    for (int c = 0; c < nb2; c++){
        nb22 = nb2 - c;
        for (int d = 0; d < nb3; d++){
            nb33 = nb3 - d;
            test = nb22 * nb33;
            if (test == nb){
                return (0);
            }
        }
    }
    return (1);
}
