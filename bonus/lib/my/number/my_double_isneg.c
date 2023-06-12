/*
** EPITECH PROJECT, 2022
** my_double_isneg
** File description:
** verif if a double is neg
*/

#include "my.h"
#include <stdlib.h>

bool my_double_isneg(double const nb)
{
    nb_binary_t *temp = malloc(sizeof(nb_binary_t));

    temp->nb = nb;
    temp->binary >>= 63;
    if (temp->binary == 1)
        return true;
    return false;
}
