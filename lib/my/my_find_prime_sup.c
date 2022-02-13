/*
** EPITECH PROJECT, 2018
** my_find_prime_sup
** File description:
** find prime sup
*/

static int my_is_prime2(int nb)
{
    int count1;
    int count2;
    int nb2 = nb / 2;
    int nb3 = nb2;
    int test;
    int nb22;
    int nb33;

    for (count1 = 0; count1 < nb2; count1++) {
        nb22 = nb2 - count1;
        for (count2 = 0; count2 < nb3; count2++) {
            nb33 = nb3 - count2;
            test = nb22 * nb33;
            if (test == nb){
                return (0);
            }
        }
    }
    return (nb);
}

int my_find_prime_sup(int nb)
{
    int test2 = 0;

    if (nb <= 1){
        return (2);
    }
    while (test2 == 0) {
        test2 = my_is_prime2(nb);
        nb++;
    }
    return (test2);
}
