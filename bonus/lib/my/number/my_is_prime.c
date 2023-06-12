/*
** EPITECH PROJECT, 2022
** my_is_prime
** File description:
** tells if a number is prime or not
*/

#include <stdbool.h>

bool my_is_prime(int nb)
{
    int i;

    if (nb <= 1)
        return false;
    if (nb == 2)
        return true;
    for (i = 2; i <= nb / 2; i++) {
    if (nb % i == 0)
        return false;
    }
    return true;
}
