/*
** EPITECH PROJECT, 2022
** my_convert_base
** File description:
** convert a decimal nb into any form
*/

#include "my.h"
#include <stdlib.h>

char *my_convert_base(unsigned long nb, int base, bool maj)
{
    char digits[17] = "0123456789abcdef";
    if (maj)
        my_upstr(digits);
    unsigned long temp = nb;
    char *res = malloc(sizeof(char) * (my_nbrlen(nb) + 2));
    int i = 0;
    int digit;
    if (temp == 0) {
        res[0] = '0';
        res[1] = '\0';
        return res;
    }
    while (temp > 0) {
        digit = temp % base;
        res[i] = digits[digit];
        temp /= base;
        i++;
    }
    res[i] = '\0';
    return my_revstr(res);
}
