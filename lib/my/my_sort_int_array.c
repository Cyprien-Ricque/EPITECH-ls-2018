/*
** EPITECH PROJECT, 2018
** my_sort_int_array
** File description:
** my_sort_int_array
*/

#include "../../include/my.h"

void my_sort_int_array(int *array, int size)
{
    int value;
    int array2[size];

    for (int j = 0; j <= size; j++)
        array2[j] = array[j];
    for (int i = 0; i <= size; i++) {
        value = size;
        for (int j = 0; j <= size; j++) {
            if (array2[i] <= array2[j])
                value--;
        }
        array[value] = array2[i];
    }
}
