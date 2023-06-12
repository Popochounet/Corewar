/*
** EPITECH PROJECT, 2022
** my_putnbr
** File description:
** display all the digits of a given number
*/

#include "my.h"

int my_putnbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb / 10)
        my_putnbr(nb / 10);
    my_putchar(nb % 10 + '0');
    return my_nbrlen(nb);
}
