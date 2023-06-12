/*
** EPITECH PROJECT, 2022
** B-MAT-100-LYN-1-1-101pong-adrien.audiard
** File description:
** str_to_nbr_double.c
*/

#include "my.h"

double str_to_nbr_dot(const char *str, double *res, int i)
{
    int z = 0;
    for (int nb = 0; str[i] != '\0'; i++) {
        while (str[i] == '0' && nb == 0 && str[i] != '\0') {
            i++;
            z++;
        }
        if (str[i] != '\0') {
            nb = 1;
            res[1] *= 10;
            res[1] = res[1] + str[i] - 48;
        }
    }
    while (res[1] >= 1 / (my_power_rec(10, z)))
        res[1] /= 10;
}

double str_to_nbr(const char* str)
{
    double res[2] = {0, 0};
    int neg = 1;
    int dbl = 0;
    int i = 0;
    int z = 0;
    if (str[0] == '-') {
        i++;
        neg = -1;
    }
    for (i; str[i] != '\0' && str[i] != '.'; i++) {
        res[0] *= 10;
        res[0] = res[0] + str[i] - 48;
    }
    if (str[i] == '.') {
        str_to_nbr_dot(str, res, i + 1);
    }
    return neg * (res[0] + res[1]);
}
