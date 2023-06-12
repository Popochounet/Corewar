/*
** EPITECH PROJECT, 2022
** my_nbrlen
** File description:
** count the number of digit in a number
*/

int my_nbrlen(long const nb)
{
    int count = 0;
    long temp = nb;

    if (nb < 0)
        temp = -nb;
    if (nb == 0)
        return 1;
    for (; temp != 0; count++)
        temp /= 10;
    return count;
}
